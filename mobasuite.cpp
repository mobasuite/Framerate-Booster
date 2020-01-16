#define WIN32_LEAN_AND_MEAN
#include <Shlobj_core.h>
#include <Tlhelp32.h>
#include <Windows.h>
#include <filesystem>
#include <shellapi.h>

int c;
const wchar_t* cb[13] = {
	L"League of Legends", L"SMITE", L"Dota2", L"Unreal Tournament", L"Minecraft", L"Black Desert Online", L"Paladins",
	L"World of Tanks", L"World of Warships", L"Lineage II", L"The Elder Scrolls Online", L"Tencent Gaming-Buddy", L"DirectX"
};

const wchar_t* dx[] = {
	L"Apr2005_d3dx9_25_x86.cab",
	L"Apr2006_d3dx9_30_x86.cab",
	L"Apr2006_MDX1_x86.cab",
	L"Apr2006_MDX1_x86_Archive.cab",
	L"Apr2006_XACT_x86.cab",
	L"Apr2006_xinput_x86.cab",
	L"APR2007_d3dx9_33_x86.cab",
	L"APR2007_d3dx10_33_x86.cab",
	L"APR2007_XACT_x86.cab",
	L"APR2007_xinput_x86.cab",
	L"Aug2005_d3dx9_27_x86.cab",
	L"AUG2006_XACT_x86.cab",
	L"AUG2006_xinput_x86.cab",
	L"AUG2007_d3dx9_35_x86.cab",
	L"AUG2007_d3dx10_35_x86.cab",
	L"AUG2007_XACT_x86.cab",
	L"Aug2008_d3dx9_39_x86.cab",
	L"Aug2008_d3dx10_39_x86.cab",
	L"Aug2008_XACT_x86.cab",
	L"Aug2008_XAudio_x86.cab",
	L"Aug2009_D3DCompiler_42_x86.cab",
	L"Aug2009_d3dcsx_42_x86.cab",
	L"Aug2009_d3dx9_42_x86.cab",
	L"Aug2009_d3dx10_42_x86.cab",
	L"Aug2009_d3dx11_42_x86.cab",
	L"Aug2009_XACT_x86.cab",
	L"Aug2009_XAudio_x86.cab",
	L"Dec2005_d3dx9_28_x86.cab",
	L"DEC2006_d3dx9_32_x86.cab",
	L"DEC2006_d3dx10_00_x86.cab",
	L"DEC2006_XACT_x86.cab",
	L"Feb2005_d3dx9_24_x86.cab",
	L"Feb2006_d3dx9_29_x86.cab",
	L"Feb2006_XACT_x86.cab",
	L"FEB2007_XACT_x86.cab",
	L"Feb2010_X3DAudio_x86.cab",
	L"Feb2010_XACT_x86.cab",
	L"Feb2010_XAudio_x86.cab",
	L"Jun2005_d3dx9_26_x86.cab",
	L"JUN2006_XACT_x86.cab",
	L"JUN2007_d3dx9_34_x86.cab",
	L"JUN2007_d3dx10_34_x86.cab",
	L"JUN2007_XACT_x86.cab",
	L"JUN2008_d3dx9_38_x86.cab",
	L"JUN2008_d3dx10_38_x86.cab",
	L"JUN2008_X3DAudio_x86.cab",
	L"JUN2008_XACT_x86.cab",
	L"JUN2008_XAudio_x86.cab",
	L"Jun2010_D3DCompiler_43_x86.cab",
	L"Jun2010_d3dcsx_43_x86.cab",
	L"Jun2010_d3dx9_43_x86.cab",
	L"Jun2010_d3dx10_43_x86.cab",
	L"Jun2010_d3dx11_43_x86.cab",
	L"Jun2010_XACT_x86.cab",
	L"Jun2010_XAudio_x86.cab",
	L"Mar2008_d3dx9_37_x86.cab",
	L"Mar2008_d3dx10_37_x86.cab",
	L"Mar2008_X3DAudio_x86.cab",
	L"Mar2008_XACT_x86.cab",
	L"Mar2008_XAudio_x86.cab",
	L"Mar2009_d3dx9_41_x86.cab",
	L"Mar2009_d3dx10_41_x86.cab",
	L"Mar2009_X3DAudio_x86.cab",
	L"Mar2009_XACT_x86.cab",
	L"Mar2009_XAudio_x86.cab",
	L"Nov2007_d3dx9_36_x86.cab",
	L"Nov2007_d3dx10_36_x86.cab",
	L"NOV2007_X3DAudio_x86.cab",
	L"NOV2007_XACT_x86.cab",
	L"Nov2008_d3dx9_40_x86.cab",
	L"Nov2008_d3dx10_40_x86.cab",
	L"Nov2008_X3DAudio_x86.cab",
	L"Nov2008_XACT_x86.cab",
	L"Nov2008_XAudio_x86.cab",
	L"Oct2005_xinput_x86.cab",
	L"OCT2006_d3dx9_31_x86.cab",
	L"OCT2006_XACT_x86.cab"
};

const wchar_t* dx64[] = {
	L"Apr2005_d3dx9_25_x64.cab",
	L"Apr2006_d3dx9_30_x64.cab",
	L"Apr2006_XACT_x64.cab",
	L"Apr2006_xinput_x64.cab",
	L"APR2007_d3dx9_33_x64.cab",
	L"APR2007_d3dx10_33_x64.cab",
	L"APR2007_XACT_x64.cab",
	L"APR2007_xinput_x64.cab",
	L"Aug2005_d3dx9_27_x64.cab",
	L"AUG2006_XACT_x64.cab",
	L"AUG2006_xinput_x64.cab",
	L"AUG2007_d3dx9_35_x64.cab",
	L"AUG2007_d3dx10_35_x64.cab",
	L"AUG2007_XACT_x64.cab",
	L"Aug2008_d3dx9_39_x64.cab",
	L"Aug2008_d3dx10_39_x64.cab",
	L"Aug2008_XACT_x64.cab",
	L"Aug2008_XAudio_x64.cab",
	L"Aug2009_D3DCompiler_42_x64.cab",
	L"Aug2009_d3dcsx_42_x64.cab",
	L"Aug2009_d3dx9_42_x64.cab",
	L"Aug2009_d3dx10_42_x64.cab",
	L"Aug2009_d3dx11_42_x64.cab",
	L"Aug2009_XACT_x64.cab",
	L"Aug2009_XAudio_x64.cab",
	L"Dec2005_d3dx9_28_x64.cab",
	L"DEC2006_d3dx9_32_x64.cab",
	L"DEC2006_d3dx10_00_x64.cab",
	L"DEC2006_XACT_x64.cab",
	L"Feb2005_d3dx9_24_x64.cab",
	L"Feb2006_d3dx9_29_x64.cab",
	L"Feb2006_XACT_x64.cab",
	L"FEB2007_XACT_x64.cab",
	L"Feb2010_X3DAudio_x64.cab",
	L"Feb2010_XACT_x64.cab",
	L"Feb2010_XAudio_x64.cab",
	L"Jun2005_d3dx9_26_x64.cab",
	L"JUN2006_XACT_x64.cab",
	L"JUN2007_d3dx9_34_x64.cab",
	L"JUN2007_d3dx10_34_x64.cab",
	L"JUN2007_XACT_x64.cab",
	L"JUN2008_d3dx9_38_x64.cab",
	L"JUN2008_d3dx10_38_x64.cab",
	L"JUN2008_X3DAudio_x64.cab",
	L"JUN2008_XACT_x64.cab",
	L"JUN2008_XAudio_x64.cab",
	L"Jun2010_D3DCompiler_43_x64.cab",
	L"Jun2010_d3dcsx_43_x64.cab",
	L"Jun2010_d3dx9_43_x64.cab",
	L"Jun2010_d3dx10_43_x64.cab",
	L"Jun2010_d3dx11_43_x64.cab",
	L"Jun2010_XACT_x64.cab",
	L"Jun2010_XAudio_x64.cab",
	L"Mar2008_d3dx9_37_x64.cab",
	L"Mar2008_d3dx10_37_x64.cab",
	L"Mar2008_X3DAudio_x64.cab",
	L"Mar2008_XACT_x64.cab",
	L"Mar2008_XAudio_x64.cab",
	L"Mar2009_d3dx9_41_x64.cab",
	L"Mar2009_d3dx10_41_x64.cab",
	L"Mar2009_X3DAudio_x64.cab",
	L"Mar2009_XACT_x64.cab",
	L"Mar2009_XAudio_x64.cab",
	L"Nov2007_d3dx9_36_x64.cab",
	L"Nov2007_d3dx10_36_x64.cab",
	L"NOV2007_X3DAudio_x64.cab",
	L"NOV2007_XACT_x64.cab",
	L"Nov2008_d3dx9_40_x64.cab",
	L"Nov2008_d3dx10_40_x64.cab",
	L"Nov2008_X3DAudio_x64.cab",
	L"Nov2008_XACT_x64.cab",
	L"Nov2008_XAudio_x64.cab",
	L"Oct2005_xinput_x64.cab",
	L"OCT2006_d3dx9_31_x64.cab",
	L"OCT2006_XACT_x64.cab"
};

const wchar_t* _a[] = {
	L"api-ms-win-core-console-l1-1-0.dll",
	L"api-ms-win-core-datetime-l1-1-0.dll",
	L"api-ms-win-core-debug-l1-1-0.dll",
	L"api-ms-win-core-errorhandling-l1-1-0.dll",
	L"api-ms-win-core-file-l1-1-0.dll",
	L"api-ms-win-core-file-l1-2-0.dll",
	L"api-ms-win-core-file-l2-1-0.dll",
	L"api-ms-win-core-handle-l1-1-0.dll",
	L"api-ms-win-core-heap-l1-1-0.dll",
	L"api-ms-win-core-interlocked-l1-1-0.dll",
	L"api-ms-win-core-libraryloader-l1-1-0.dll",
	L"api-ms-win-core-localization-l1-2-0.dll",
	L"api-ms-win-core-memory-l1-1-0.dll",
	L"api-ms-win-core-namedpipe-l1-1-0.dll",
	L"api-ms-win-core-processenvironment-l1-1-0.dll",
	L"api-ms-win-core-processthreads-l1-1-0.dll",
	L"api-ms-win-core-processthreads-l1-1-1.dll",
	L"api-ms-win-core-profile-l1-1-0.dll",
	L"api-ms-win-core-rtlsupport-l1-1-0.dll",
	L"api-ms-win-core-string-l1-1-0.dll",
	L"api-ms-win-core-synch-l1-1-0.dll",
	L"api-ms-win-core-synch-l1-2-0.dll",
	L"api-ms-win-core-sysinfo-l1-1-0.dll",
	L"api-ms-win-core-timezone-l1-1-0.dll",
	L"api-ms-win-core-util-l1-1-0.dll",
	L"api-ms-win-crt-conio-l1-1-0.dll",
	L"api-ms-win-crt-convert-l1-1-0.dll",
	L"api-ms-win-crt-environment-l1-1-0.dll",
	L"api-ms-win-crt-filesystem-l1-1-0.dll",
	L"api-ms-win-crt-heap-l1-1-0.dll",
	L"api-ms-win-crt-locale-l1-1-0.dll",
	L"api-ms-win-crt-math-l1-1-0.dll",
	L"api-ms-win-crt-multibyte-l1-1-0.dll",
	L"api-ms-win-crt-private-l1-1-0.dll",
	L"api-ms-win-crt-process-l1-1-0.dll",
	L"api-ms-win-crt-runtime-l1-1-0.dll",
	L"api-ms-win-crt-stdio-l1-1-0.dll",
	L"api-ms-win-crt-string-l1-1-0.dll",
	L"api-ms-win-crt-time-l1-1-0.dll",
	L"api-ms-win-crt-utility-l1-1-0.dll"
};

wchar_t n[83][MAX_PATH + 1];

std::wstring cp = std::filesystem::current_path();
SHELLEXECUTEINFO f;

LRESULT CALLBACK WndProc(HWND /*hwnd*/, UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/);

void u(std::wstring file)
{
	DeleteFile(file.append(L":Zone.Identifier").c_str());
}

auto j(const int j, std::wstring const& add) -> std::wstring
{
	std::filesystem::path p = n[j];
	std::filesystem::path f = p / add;
	return f.c_str();
}

void p(const int j, std::wstring const& add)
{
	std::filesystem::path p = n[j];
	std::filesystem::path f = p / add;
	wcsncpy_s(n[j], f.c_str(), _TRUNCATE);
}

void _(const int j, const int k, std::wstring const& add)
{
	std::filesystem::path p = n[k];
	std::filesystem::path f = p / add;
	wcsncpy_s(n[j], f.c_str(), _TRUNCATE);
}

void cf(const int i, const int k, std::wstring const& add)
{
	copy_file(n[i], j(k, add), std::filesystem::copy_options::overwrite_existing);
}

void v(const int j)
{
	WIN32_FIND_DATA fd;
	const auto find = FindFirstFile(std::wstring(n[j] + std::wstring(L"\\*.*")).c_str(), &fd);
	if (find != INVALID_HANDLE_VALUE)
	{
		while (FindNextFile(find, &fd))
		{
		}
		p(j, fd.cFileName);
		FindClose(find);
	}
}

void pc_end(std::wstring const& name)
{
	HANDLE snapshot = CreateToolhelp32Snapshot(2, 0);
	PROCESSENTRY32 process;
	ZeroMemory(&process, sizeof(process));
	process.dwSize = sizeof(process);
	if (Process32First(snapshot, &process))
	{
		while (Process32Next(snapshot, &process))
		{
			if (process.szExeFile == name)
			{
				snapshot = OpenProcess(SYNCHRONIZE | PROCESS_TERMINATE, 1,
				                       process.th32ProcessID);
				TerminateProcess(snapshot, 0);
				break;
			}
		}
	}
	CloseHandle(snapshot);
}

void d(std::wstring const& url, const int j)
{
	URLDownloadToFile(nullptr, std::wstring(L"https://mobasuite.com/" + url).c_str(), n[j], NULL, nullptr);
	u(n[j]);
}

void a(const wchar_t* url)
{
	for (int i = 0; i < 40; i++)
	{
		_(i + 1, 0, _a[i]);
		d(&std::wstring(url + std::wstring(_a[i]))[0], i + 1);
	}
}

auto x64() -> bool
{
	USHORT pProcessMachine;
	USHORT pNativeMachine;
	return IsWow64Process2(
		GetCurrentProcess(),
		&pProcessMachine,
		&pNativeMachine
	) != 0;
}

void cfg(const std::wstring& key)
{
	*n[0] = '\0';
	*n[82] = '\0';
	p(82, &cp[0]);
	p(82, L"msuite.ini");
	GetPrivateProfileString(L"Path", key.c_str(), nullptr, n[0], 261, n[82]);
	if (std::wstring(n[0]).empty())
	{
		BROWSEINFOW i{};
		i.ulFlags = 64 | 256 | 512 | 32768;
		if (key == L"ll")
		{
			i.lpszTitle = L"<drive>\\Riot Games\\ , Program Files\\TencentGame\\LOL , Garena\\Games\\<lolgame>";
		}
		if (key == L"d2" || key == L"sm" || key == L"pl")
		{
			i.lpszTitle = L"Program Files (x86)\\Steam";
		}
		if (key == L"tgb")
		{
			i.lpszTitle = L"Program Files\\TxGameAssistant\\AppMarket";
		}
		if (key == L"es")
		{
			i.lpszTitle = L"Zenimax Online\\The Elder Scrolls Online";
		}
		if (key == L"ut")
		{
			i.lpszTitle = L"Program\\Epic Games";
		}
		if (key == L"l2")
		{
			i.lpszTitle = L"Program Files (x86)\\NCSOFT";
		}
		if (key == L"wt")
		{
			i.lpszTitle = L"Games\\World_of_Tanks";
		}
		if (key == L"ww")
		{
			i.lpszTitle = L"Games\\World_of_Warships";
		}
		if (key == L"bd")
		{
			i.lpszTitle = L"Program files(x86)\\Black Desert Online";
		}
		const auto dl = SHBrowseForFolderW(&i);
		if (dl == nullptr)
		{
			_exit(0);
		}
		SHGetPathFromIDListW(dl, n[0]);
		if (key == L"d2")
		{
			p(0, L"steamapps\\common\\dota 2 beta\\game\\bin");
		}
		if (key == L"sm")
		{
			p(0, L"steamapps\\common\\SMITE\\Binaries");
		}
		if (key == L"pl")
		{
			p(0, L"steamapps\\common\\Paladins\\Binaries");
		}
		if (key == L"ut")
		{
			p(0, L"UnrealTournament");
		}
		if (key == L"l2")
		{
			p(0, L"Lineage II");
		}
		WritePrivateProfileString(L"Path", key.c_str(), n[0], n[82]);
	}
}

void e()
{
	BOOL admin = FALSE;
	PSID group = nullptr;
	SID_IDENTIFIER_AUTHORITY auth = SECURITY_NT_AUTHORITY;
	if (AllocateAndInitializeSid(&auth, 2, SECURITY_BUILTIN_DOMAIN_RID,
	                             DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0,
	                             &group) == 0)
	{
		if (group != nullptr)
		{
			FreeSid(group);
			group = nullptr;
		}
	}
	CheckTokenMembership(nullptr, group, &admin);
	if (admin == 0)
	{
		wchar_t my[261];
		GetModuleFileName(nullptr, my, _countof(my) - 1);
		f = {};
		f.cbSize = sizeof f;
		f.fMask = 64;
		f.lpVerb = L"runas";
		f.lpFile = my;
		f.lpDirectory = cp.c_str();
		f.nShow = 1;
		ShellExecuteEx(&f);
		_exit(0);
	}
}

void g(std::wstring const& dir, std::wstring const& key)
{
	for (int i = 0; i < 57; i++)
	{
		*n[i] = '\0';
	}
	cfg(key);
	p(0, dir);
	_(41, 0, L"D3DCompiler_42.dll");
	_(42, 0, L"d3dx9_42.dll");
	_(43, 0, L"d3dx11_42.dll");
	_(44, 0, L"msvcp140.dll");
	_(45, 0, L"ucrtbase.dll");
	_(46, 0, L"vcruntime140.dll");
	_(47, 0, L"d3dcompiler_43.dll");
	_(48, 0, L"d3dcompiler_47.dll");
	_(49, 0, L"concrt140.dll");
	_(52, 0, L"vccorlib140.dll");
	_(53, 0, L"mfc140u.dll");
	_(54, 0, L"mfcm140u.dll");
	_(55, 0, L"vcomp140.dll");
	_(56, 0, L"vccorlib140.dll");
}

void dota2(bool r)
{
	pc_end(L"dota2.exe");
	if (x64())
	{
		*n[1] = '\0';
		*n[2] = '\0';
		cfg(L"d2");
		p(0, L"win64");
		_(1, 0, L"d3dcompiler_43.dll");
		_(2, 0, L"embree.dll");
		u(j(0, L"dota2.exe"));
		if (r)
		{
			d(L"r/dota/x64/d3dcompiler_43.dll", 1);
			d(L"r/dota/x64/embree.dll", 2);
		}
		else
		{
			d(L"6/D3DCompiler_47.dll", 1);
			d(L"6/embree.dll", 2);
		}
	}
	*n[1] = '\0';
	cfg(L"d2");
	p(0, L"win32");
	_(1, 0, L"d3dcompiler_43.dll");
	u(j(0, L"dota2.exe"));
	if (r)
	{
		d(L"r/dota/d3dcompiler_43.dll", 1);
	}
	else
	{
		d(L"D3DCompiler_47.dll", 1);
	}
	cfg(L"d2");
	f = {};
	f.cbSize = sizeof(SHELLEXECUTEINFO);
	f.fMask = 64;
	f.nShow = 5;
	if (x64())
	{
		p(0, L"win64");
	}
	else
	{
		p(0, L"win32");
	}
	f.lpFile = j(0, L"dota2.exe").c_str();
	ShellExecuteEx(&f);
}

void lineage(bool r)
{
	for (auto i = 0; i < 8; i++)
	{
		*n[i] = '\0';
	}
	pc_end(L"NCLauncherR.exe");
	pc_end(L"NCLauncher.exe");
	pc_end(L"L2.bin");
	cfg(L"l2");
	p(0, L"System");
	u(j(0, L"L2.bin"));
	_(1, 0, L"d3dcompiler_43.dll");
	_(2, 0, L"d3dcompiler_47.dll");
	_(3, 0, L"D3DX9_40.dll");
	_(4, 0, L"vcomp120.dll");
	_(6, 0, L"plugins");
	if (r)
	{
		d(L"r/l2/d3dcompiler_43.dll", 1);
		d(L"r/l2/d3dcompiler_47.dll", 2);
		d(L"r/l2/D3DX9_40.dll", 3);
		d(L"r/l2/vcomp120.dll", 4);
	}
	else
	{
		d(L"D3DCompiler_47.dll", 1);
		d(L"D3DCompiler_47.dll", 2);
		d(L"D3DX9_43.dll", 3);
		d(L"vcomp120.dll", 4);
	}
	f = {};
	f.cbSize = sizeof(SHELLEXECUTEINFO);
	f.fMask = 64;
	f.nShow = 5;
	*n[0] = '\0';
	SHGetSpecialFolderPathW(nullptr, n[0], 42, 0);
	f.lpVerb = L"runas";
	f.lpParameters =
		L"/LauncherID:\"NCWest\" /CompanyID:\"12\" /GameID:\"LINEAGE2\" /LUpdateAddr:\"updater.nclauncher.ncsoft.com\"";
	f.lpFile = j(0, L"NCWest\\NCLauncher\\NCLauncher.exe").c_str();
	ShellExecuteEx(&f);
}

void bdo(bool r)
{
	pc_end(L"BlackDesert32.exe");
	pc_end(L"BlackDesert64.exe");
	cfg(L"bd");
	g(L"bin", L"bdo");
	if (r)
	{
		d(L"r/bdo/msvcp140.dll", 44);
		d(L"r/bdo/ucrtbase.dll", 45);
		d(L"r/bdo/vcruntime140.dll", 46);
		d(L"r/bdo/D3DCompiler_43.dll", 47);
		d(L"r/bdo/concrt140.dll", 49);
		d(L"r/bdo/mfc140u.dll", 53);
		d(L"r/bdo/mfcm140u.dll", 54);
		d(L"r/bdo/vcomp140.dll", 55);
		d(L"r/bdo/vccorlib140.dll", 56);
		a(L"r/bdo/");
	}
	else
	{
		d(L"msvcp140.dll", 44);
		d(L"ucrtbase.dll", 45);
		d(L"vcruntime140.dll", 46);
		d(L"D3DCompiler_47.dll", 47);
		d(L"concrt140.dll", 49);
		d(L"mfc140u.dll", 53);
		d(L"mfcm140u.dll", 54);
		d(L"vcomp140.dll", 55);
		d(L"vccorlib140.dll", 56);
		a(L"");
	}
	g(L"bin64", L"bdo");
	if (r)
	{
		d(L"r/bdo/x64/msvcp140.dll", 44);
		d(L"r/bdo/x64/ucrtbase.dll", 45);
		d(L"r/bdo/x64/vcruntime140.dll", 46);
		d(L"r/bdo/x64/D3DCompiler_43.dll", 47);
		d(L"r/bdo/x64/concrt140.dll", 49);
		d(L"r/bdo/x64/mfc140u.dll", 53);
		d(L"r/bdo/x64/mfcm140u.dll", 54);
		d(L"r/bdo/x64/vcomp140.dll", 55);
		d(L"r/bdo/x64/vccorlib140.dll", 56);
		a(L"r/bdo/x64/");
	}
	else
	{
		d(L"6/msvcp140.dll", 44);
		d(L"6/ucrtbase.dll", 45);
		d(L"6/vcruntime140.dll", 46);
		d(L"6/D3DCompiler_47.dll", 47);
		d(L"6/concrt140.dll", 49);
		d(L"6/mfc140u.dll", 53);
		d(L"6/mfcm140u.dll", 54);
		d(L"6/vcomp140.dll", 55);
		d(L"6/vccorlib140.dll", 56);
		a(L"6/");
	}
	g(L"", L"bdo");
	f = {};
	f.cbSize = sizeof(SHELLEXECUTEINFO);
	f.fMask = 64;
	f.nShow = 5;
	f.lpFile = L"Black Desert Online Launcher.exe";
	ShellExecuteEx(&f);
}

void eso(bool r)
{
	for (int i = 0; i < 7; i++)
	{
		*n[i] = '\0';
	}
	pc_end(L"eso.exe");
	pc_end(L"eso64.exe");
	cfg(L"es");
	p(0, L"game\\client");
	_(1, 0, L"tbb.dll");
	_(2, 0, L"tbbmalloc.dll");
	_(3, 0, L"x64");
	_(4, 0, L"x86");
	p(3, L"D3DCompiler_47.dll");
	p(4, L"D3DCompiler_47.dll");
	_(5, 0, L"eso.exe");
	_(6, 0, L"eso64.exe");
	if (r)
	{
		d(L"r/teso/tbb.dll", 1);
		d(L"r/teso/tbbmalloc.dll", 2);
		d(L"r/teso/x64/D3DCompiler_47.dll", 3);
		d(L"r/teso/D3DCompiler_47.dll", 4);
	}
	else
	{
		d(L"tbb.dll", 1);
		d(L"tbbmalloc.dll", 2);
		d(L"6/D3DCompiler_47.dll", 3);
		d(L"D3DCompiler_47.dll", 4);
	}
	u(n[5]);
	u(n[6]);
	f = {};
	f.cbSize = sizeof(SHELLEXECUTEINFO);
	f.fMask = 64;
	f.nShow = 5;
	if (x64())
	{
		f.lpFile = n[6];
	}
	else
	{
		f.lpFile = n[5];
	}
	ShellExecuteEx(&f);
}

void wt(bool r)
{
	for (int i = 0; i < 46; i++)
	{
		*n[i] = '\0';
	}
	cfg(L"wt");
	wchar_t wt[261] = L"WorldOfTanks.exe";
	pc_end(L"WorldOfTanks.exe");
	u(j(0, wt));
	_(41, 0, L"concrt140.dll");
	_(42, 0, L"msvcp140.dll");
	_(43, 0, L"tbb.dll");
	_(44, 0, L"vcruntime140.dll");
	_(45, 0, L"system");
	_(46, 45, L"ucrtbase.dll");
	if (r)
	{
		d(L"r/wt/concrt140.dll", 41);
		d(L"r/wt/msvcp140.dll", 42);
		d(L"r/wt/tbb.dll", 43);
		d(L"r/wt/vcruntime140.dll", 44);
		d(L"r/wt/ucrtbase.dll", 46);
		p(0, L"system");
		a(L"r/wt/");
	}
	else
	{
		d(L"concrt140.dll", 41);
		d(L"msvcp140.dll", 42);
		d(L"tbb.dll", 43);
		d(L"vcruntime140.dll", 44);
		d(L"ucrtbase.dll", 46);
		p(0, L"system");
		a(L"");
	}
	cfg(L"wt");
	f = {};
	f.cbSize = sizeof(SHELLEXECUTEINFO);
	f.fMask = 64;
	f.nShow = 5;
	f.lpFile = j(0, wt).c_str();
	ShellExecuteEx(&f);
}

void wws(bool r)
{
	for (int i = 0; i < 46; i++)
	{
		*n[i] = '\0';
	}
	cfg(L"ww");
	wchar_t www[261] = L"WorldOfWarships.exe";
	pc_end(L"WorldOfWarships.exe");
	u(j(0, www));
	_(41, 0, L"msvcp140.dll");
	_(42, 0, L"ucrtbase.dll");
	_(43, 0, L"vcruntime140.dll");
	_(44, 0, L"cef");
	_(45, 44, L"d3dcompiler_43.dll");
	_(46, 44, L"d3dcompiler_47.dll");
	if (r)
	{
		a(L"r/wws/");
		d(L"r/wws/msvcp140.dll", 41);
		d(L"r/wws/ucrtbase.dll", 42);
		d(L"r/wws/vcruntime140.dll", 43);
		p(0, L"cef");
		d(L"r/wws/d3dcompiler_43.dll", 45);
		d(L"r/wws/d3dcompiler_47.dll", 46);
	}
	else
	{
		a(L"");
		d(L"msvcp140.dll", 41);
		d(L"ucrtbase.dll", 42);
		d(L"vcruntime140.dll", 43);
		p(0, L"cef");
		d(L"D3DCompiler_47.dll", 45);
		d(L"D3DCompiler_47.dll", 46);
	}
	cfg(L"ww");
	f = {};
	f.cbSize = sizeof(SHELLEXECUTEINFO);
	f.fMask = 64;
	f.nShow = 5;
	f.lpFile = j(0, www).c_str();
	ShellExecuteEx(&f);
}

void _epic(bool r, bool last)
{
	if (last)
	{
		if (r)
		{
			d(L"r/epic/d3dcompiler_43.dll", 47);
			d(L"r/epic/d3dcompiler_47.dll", 48);
		}
		else
		{
			d(L"6/D3DCompiler_47.dll", 47);
			d(L"6/D3DCompiler_47.dll", 48);
		}
		f = {};
		f.cbSize = sizeof(SHELLEXECUTEINFO);
		f.fMask = 64;
		f.nShow = 5;
		*n[0] = '\0';
		SHGetSpecialFolderPathW(nullptr, n[0], 42, 0);
		f.lpFile = j(0, L"Epic Games\\Launcher\\Portal\\Binaries\\Win32\\EpicGamesLauncher.exe").c_str();
		ShellExecuteEx(&f);
	}
	else
	{
		if (r)
		{
			a(L"r/epic/");
			d(L"r/epic/concrt140.dll", 49);
			d(L"r/epic/ucrtbase.dll", 45);
			d(L"r/epic/vccorlib140.dll", 52);
			d(L"r/epic/msvcp140.dll", 44);
			d(L"r/epic/vcruntime140.dll", 46);
		}
		else
		{
			d(L"6/concrt140.dll", 49);
			a(L"6/");
			d(L"6/ucrtbase.dll", 45);
			d(L"6/vccorlib140.dll", 52);
			d(L"6/msvcp140.dll", 44);
			d(L"6/vcruntime140.dll", 46);
		}
	}
}

void ut(bool r)
{
	cfg(L"ut");
	wchar_t ut[261] = L"UE4-Win64-Shipping.exe";
	pc_end(ut);
	pc_end(L"EpicGamesLauncher.exe");
	g(L"UnrealTournament\\Binaries\\Win64", L"ut");
	_epic(r, false);
	g(L"Engine\\Binaries\\Win64", L"ut");
	u(j(0, ut));
	_epic(r, false);
	g(L"Engine\\Binaries\\ThirdParty\\CEF3\\Win64", L"ut");
	_epic(r, true);
}

void tencentgb(bool r)
{
	e();
	pc_end(L"AppMarket.exe");
	pc_end(L"QQExternal.exe");
	for (auto i = 0; i < 44; i++)
	{
		*n[i] = '\0';
	}
	cfg(L"tgb");
	_(40, 0, L"msvcp140.dll");
	_(41, 0, L"ucrtbase.dll");
	_(42, 0, L"vcomp140.dll");
	_(43, 0, L"vcruntime140.dll");
	if (r)
	{
		a(L"r/tencentgb");
		d(L"r/tencentgb/msvcp140.dll", 40);
		d(L"r/tencentgb/ucrtbase.dll", 41);
		d(L"r/tencentgb/vcomp140.dll", 42);
		d(L"r/tencentgb/vcruntime140.dll", 43);
	}
	else
	{
		a(L"");
		d(L"msvcp140.dll", 40);
		d(L"ucrtbase.dll", 41);
		d(L"vcomp140.dll", 42);
		d(L"vcruntime140.dll", 43);
	}
	f = {};
	f.cbSize = sizeof(SHELLEXECUTEINFO);
	f.fMask = 64;
	f.nShow = 5;
	f.lpVerb = L"runas";
	f.lpFile = j(0, L"AppMarket.exe").c_str();
	ShellExecuteEx(&f);
	u(j(0, L"AppMarket.exe"));
}

void LoL(bool r)
{
	e();
	for (auto i = 0; i < 55; i++)
	{
		*n[i] = '\0';
	}
	cfg(L"ll");
	std::wstring dir = n[0];

	pc_end(L"League of Legends.exe");
	pc_end(L"RiotClientUx.exe");
	pc_end(L"RiotClientUxRender.exe");
	pc_end(L"LeagueClient.exe");
	p(0, L"Riot Client");
	_(44, 0, L"concrt140.dll");
	_(45, 0, L"vcruntime140.dll");
	_(46, 0, L"ucrtbase.dll");
	_(47, 0, L"msvcp140.dll");


	if (r)
	{
		a(L"r/lol");
		d(L"r/lol/concrt140.dll", 44);
		d(L"r/lol/vcruntime140.dll", 45);
		d(L"r/lol/ucrtbase.dll", 46);
		d(L"r/lol/msvcp140.dll", 47);
	}
	else
	{
		a(L"");
		d(L"concrt140.dll", 44);
		d(L"vcruntime140.dll", 45);
		d(L"ucrtbase.dll", 46);
		d(L"msvcp140.dll", 47);
	}

	p(0, L"UX");
	_(44, 0, L"concrt140.dll");
	_(45, 0, L"vcruntime140.dll");
	_(46, 0, L"ucrtbase.dll");
	_(47, 0, L"msvcp140.dll");
	_(50, 0, L"d3dcompiler_47.dll");
	if (r)
	{
		a(L"r/lol");
		d(L"r/lol/concrt140.dll", 44);
		d(L"r/lol/vcruntime140.dll", 45);
		d(L"r/lol/ucrtbase.dll", 46);
		d(L"r/lol/msvcp140.dll", 47);
		d(L"r/lol/d3dcompiler_47.dll", 50);
	}
	else
	{
		a(L"");
		d(L"concrt140.dll", 44);
		d(L"vcruntime140.dll", 45);
		d(L"ucrtbase.dll", 46);
		d(L"msvcp140.dll", 47);
		d(L"D3DCompiler_47.dll", 50);
	}
	wcsncpy_s(n[0], dir.c_str(), _TRUNCATE);
	p(0, L"League of Legends");
	_(42, 0, L"Game");
	u(j(42, L"League of Legends.exe"));
	u(j(0, L"LeagueClient.exe"));
	_(49, 42, L"D3DCompiler_43.dll");
	_(44, 0, L"concrt140.dll");
	_(45, 0, L"vcruntime140.dll");
	_(46, 0, L"ucrtbase.dll");
	_(47, 0, L"msvcp140.dll");
	_(48, 42, L"tbb.dll");
	_(49, 42, L"D3DCompiler_43.dll");
	_(50, 0, L"d3dcompiler_47.dll");

	if (r)
	{
		std::filesystem::remove(n[48]);
		d(L"r/lol/D3DCompiler_43.dll", 42);
		a(L"r/lol/");
		d(L"r/lol/concrt140.dll", 44);
		d(L"r/lol/vcruntime140.dll", 45);
		d(L"r/lol/ucrtbase.dll", 46);
		d(L"r/lol/msvcp140.dll", 47);
		d(L"r/lol/D3DCompiler_43.dll", 49);
		d(L"r/lol/d3dcompiler_47.dll", 50);
	}
	else
	{
		a(L"");
		d(L"concrt140.dll", 44);
		d(L"vcruntime140.dll", 45);
		d(L"ucrtbase.dll", 46);
		d(L"msvcp140.dll", 47);
		d(L"D3DCompiler_47.dll", 50);
		if (x64())
		{
			d(L"6/tbb.dll", 48);
			d(L"6/D3DCompiler_47.dll", 49);
		}
		else
		{
			d(L"tbb.dll", 48);
			d(L"D3DCompiler_47.dll", 49);
		}
	}
	f = {};
	f.cbSize = sizeof(SHELLEXECUTEINFO);
	f.fMask = 64;
	f.nShow = 5;
	f.lpFile = j(0, L"LeagueClient.exe").c_str();
	ShellExecuteEx(&f);
}

void smite(bool r)
{
	e();
	pc_end(L"HirezLauncherUI.exe");
	pc_end(L"Smite.exe");
	pc_end(L"SteamLauncherUI.exe");
	if (x64())
	{
		for (auto i = 0; i < 7; i++)
		{
			*n[i] = '\0';
		}
		cfg(L"sm");
		p(0, L"Win64");
		_(1, 0, L"tbbmalloc.dll");
		_(2, 0, L"concrt140.dll");
		_(3, 0, L"vccorlib140.dll");
		_(4, 0, L"vcruntime140.dll");
		_(5, 0, L"d3dcompiler_46.dll");
		u(j(0, L"Smite.exe"));
		if (r)
		{
			d(L"r/hirez/s/x64/tbbmalloc.dll", 1);
			d(L"r/hirez/s/x64/concrt140.dll", 2);
			d(L"r/hirez/s/x64/vccorlib140.dll", 3);
			d(L"r/hirez/s/x64/vcruntime140.dll", 4);
			d(L"r/hirez/s/x64/d3dcompiler_46.dll", 5);
		}
		else
		{
			d(L"6/tbbmalloc.dll", 1);
			d(L"6/concrt140.dll", 2);
			d(L"6/vccorlib140.dll", 3);
			d(L"6/vcruntime140.dll", 4);
			d(L"6/D3DCompiler_47.dll", 5);
		}
	}
	for (auto i = 0; i < 7; i++)
	{
		*n[i] = '\0';
	}
	cfg(L"sm");
	p(0, L"Win32");
	_(1, 0, L"tbbmalloc.dll");
	_(2, 0, L"concrt140.dll");
	_(3, 0, L"vccorlib140.dll");
	_(4, 0, L"vcruntime140.dll");
	_(5, 0, L"d3dcompiler_46.dll");
	u(j(0, L"Smite.exe"));
	if (r)
	{
		d(L"r/hirez/s/tbbmalloc.dll", 1);
		d(L"r/hirez/s/concrt140.dll", 2);
		d(L"r/hirez/s/vccorlib140.dll", 3);
		d(L"r/hirez/s/vcruntime140.dll", 4);
		d(L"r/hirez/s/d3dcompiler_46.dll", 5);
	}
	else
	{
		d(L"tbbmalloc.dll", 1);
		d(L"concrt140.dll", 2);
		d(L"vccorlib140.dll", 3);
		d(L"vcruntime140.dll", 4);
		d(L"D3DCompiler_47.dll", 5);
	}
	cfg(L"sm");
	f = {};
	f.cbSize = sizeof(SHELLEXECUTEINFO);
	f.fMask = 64;
	f.nShow = 5;
	f.lpParameters = L"game=300 product=17";
	f.lpFile = j(0, L"SteamLauncherUI.exe").c_str();
	ShellExecuteEx(&f);
}

void pala(bool r)
{
	e();
	pc_end(L"HirezLauncherUI.exe");
	pc_end(L"Paladins.exe");
	pc_end(L"SteamLauncherUI.exe");
	if (x64())
	{
		*n[0] = '\0';
		*n[1] = '\0';
		cfg(L"pl");
		p(0, L"Win64");
		_(1, 0, L"tbbmalloc.dll");
		u(j(0, L"Paladins.exe"));
		if (r)
		{
			d(L"r/hirez/p/x64/tbbmalloc.dll", 1);
		}
		else
		{
			d(L"6/tbbmalloc.dll", 1);
		}
	}
	*n[0] = '\0';
	*n[1] = '\0';
	cfg(L"pl");
	p(0, L"Win32");
	_(1, 0, L"tbbmalloc.dll");
	u(j(0, L"Paladins.exe"));
	if (r)
	{
		d(L"r/hirez/p/tbbmalloc.dll", 1);
	}
	else
	{
		d(L"tbbmalloc.dll", 1);
	}
	cfg(L"pl");
	f = {};
	f.cbSize = sizeof(SHELLEXECUTEINFO);
	f.fMask = 64;
	f.nShow = 5;
	f.lpParameters = L"game=400 product=402";
	f.lpFile = j(0, L"SteamLauncherUI.exe").c_str();
	ShellExecuteEx(&f);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
		if (HIWORD(wParam) == CBN_SELCHANGE)
		{
			c = SendMessage(reinterpret_cast<HWND>(lParam), static_cast<UINT>(CB_GETCURSEL), static_cast<WPARAM>(0),
			                static_cast<LPARAM>(0));
		}
		if (LOWORD(wParam) == 1)
		{
			switch (c)
			{
			case 0:
				LoL(false);
				break;
			case 1:
				smite(false);
				break;
			case 2:
				dota2(false);
				break;
			case 3:
				ut(false);
				break;
			case 4:
				e();
				*n[0] = '\0';
				p(0, cp);
				if (x64())
				{
					p(0, L"java13.exe");
					d(L"jdk13.0.2.exe", 0);
				}
				else
				{
					p(0, L"java8.exe");
					d(L"jre8u241.exe", 0);
				}
				f = {};
				f.cbSize = sizeof(SHELLEXECUTEINFO);
				f.fMask = 64;
				f.nShow = 5;
				f.lpVerb = L"runas";
				f.lpFile = n[0];
				ShellExecuteEx(&f);
				if (f.hProcess != nullptr)
				{
					WaitForSingleObject(f.hProcess, INFINITE);
				}
				std::filesystem::remove(n[0]);
				if (x64())
				{
					MessageBox(nullptr,
					           L"Minecraft > Launch Options > Advanced > Java Executable Path > Program Files\\Java\\jdk-13.0.1\\bin\\javaw.exe",
					           L"Instructions", MB_OK);
				}
				else
				{
					MessageBox(nullptr,
					           L"Minecraft > Launch Options > Advanced > Java Executable Path > Program Files\\Java\\jre-8u231\\bin\\javaw.exe",
					           L"Instructions", MB_OK);
				}
				break;
			case 5:
				bdo(false);
				break;
			case 6:
				pala(false);
				break;
			case 7:
				wt(false);
				break;
			case 8:
				wws(false);
				break;
			case 9:
				lineage(false);
				break;
			case 10:
				eso(false);
				break;
			case 11:
				tencentgb(false);
				break;
			case 12:
				e();
				*n[82] = '\0';
				p(82, cp);
				p(82, L"t_");
				std::filesystem::create_directory(n[82]);
				for (auto i = 0; i < 77; i++)
				{
					*n[i] = '\0';
					_(i, 82, dx[i]);
					d(&std::wstring(L"9/" + std::wstring(dx[i]))[0], i);
				}
				if (x64())
				{
					for (auto i = 0; i < 75; i++)
					{
						*n[i] = '\0';
						_(i, 82, dx64[i]);
						d(&std::wstring(L"9/" + std::wstring(dx64[i]))[0], i);
					}
				}

				for (auto i = 0; i < 5; i++)
				{
					const wchar_t* dx_install[] = {
						L"dsetup.dll", L"dsetup32.dll", L"dxdllreg_x86.cab", L"DXSETUP.exe", L"dxupdate.cab"
					};
					*n[i] = '\0';
					_(i, 82, dx_install[i]);
					d(&std::wstring(L"9/" + std::wstring(dx_install[i]))[0], i);
				}
				pc_end(L"DXSETUP.exe");
				f = {};
				f.cbSize = sizeof(SHELLEXECUTEINFO);
				f.fMask = 64;
				f.nShow = 5;
				f.lpVerb = L"runas";
				f.lpParameters = L"/silent";
				f.lpFile = j(82, L"DXSETUP.exe").c_str();
				ShellExecuteEx(&f);
				if (f.hProcess != nullptr)
				{
					WaitForSingleObject(f.hProcess, INFINITE);
				}
				std::filesystem::remove_all(n[82]);
				break;
			default: ;
			}
		}
		if (LOWORD(wParam) == 2)
		{
			switch (c)
			{
			case 0:
				LoL(true);
				break;
			case 1:
				smite(true);
				break;
			case 2:
				dota2(true);
				break;
			case 3:
				ut(true);
				break;
			case 5:
				bdo(true);
				break;
			case 6:
				pala(true);
				break;
			case 7:
				wt(true);
				break;
			case 8:
				wws(true);
				break;
			case 9:
				lineage(true);
				break;
			case 10:
				eso(true);
				break;
			case 11:
				tencentgb(true);
				break;
			default: ;
			}
		}
	default: ;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPWSTR /*lpCmdLine*/, int nShowCmd)
{
	MSG msg;
	const wchar_t* szWindowClass = L"x86_win";
	WNDCLASSEX wcex{
		sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0, hInstance, LoadIcon(hInstance, IDI_APPLICATION),
		LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr, szWindowClass,
		LoadIcon(hInstance, IDI_APPLICATION)
	};
	RegisterClassEx(&wcex);
	HWND hwnd = CreateWindow(szWindowClass, L"MOBASuite", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 420, 160,
	                         nullptr, nullptr, hInstance, nullptr);
	CreateWindow(L"BUTTON", L"Patch", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 10, 100,
	             100, hwnd, reinterpret_cast<HMENU>(1), hInstance, nullptr);
	CreateWindow(L"BUTTON", L"Restore", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 300, 10, 100,
	             100, hwnd, reinterpret_cast<HMENU>(2), hInstance, nullptr);
	HWND cmb = CreateWindow(WC_COMBOBOX, L"COMBOBOX", CBS_DROPDOWN | LBS_SORT | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
	                        120, 10, 170, 340, hwnd, nullptr, hInstance, nullptr);
	for (auto& i : cb)
	{
		SendMessage(cmb, CB_ADDSTRING, static_cast<WPARAM>(0), reinterpret_cast<LPARAM>(i));
	}
	SendMessage(cmb, CB_SETCURSEL, static_cast<WPARAM>(0), static_cast<LPARAM>(0));
	if (x64())
	{
		*n[0] = '\0';
		p(0, &cp[0]);
		p(0, L"vcredist_x64.exe");
		d(L"vcredist_x64.exe", 0);
		f = {};
		f.cbSize = sizeof(SHELLEXECUTEINFO);
		f.fMask = 64;
		f.nShow = 5;
		f.lpVerb = L"runas";
		f.lpFile = n[0];
		f.lpParameters = L"/q";
		ShellExecuteEx(&f);
		if (f.hProcess != nullptr)
		{
			WaitForSingleObject(f.hProcess, INFINITE);
		}
		DeleteFile(n[0]);
		*n[0] = '\0';
	}
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return static_cast<int>(msg.wParam);
}
