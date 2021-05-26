// mobasuite.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "mobasuite.h"
using namespace std::filesystem;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst; // current instance
WCHAR szTitle[MAX_LOADSTRING]; // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING]; // the main window class name

// Forward declarations of functions included in this code module:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);


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

const wchar_t* dx_64[] = {
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

const wchar_t* apimswincore[] = {
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

// Variables
wchar_t n[83][MAX_PATH + 1];
std::wstring cp = current_path();
SHELLEXECUTEINFO pi;
int c;
const wchar_t* cmbbox[13] = {
	L"League of Legends", L"SMITE", L"DOTA2", L"Unreal Tournament (Pre-Alpha)", L"Minecraft (Java Edition)",
	L"Black Desert Online Remastered", L"Paladins", L"World of Tanks", L"World of Warships", L"Lineage II",
	L"The Elder Scrolls Online", L"Tencent Gaming-Buddy", L"DirectX Unblocked"
};

void unblockfile(std::wstring file)
{
	DeleteFile(file.append(L":Zone.Identifier").c_str());
}

std::wstring j(const int j, const std::wstring& add)
{
	path p = n[j];
	path f = p / add;
	return f.c_str();
}

void p(const int j, const std::wstring& add)
{
	path p = n[j];
	path f = p / add;
	wcsncpy_s(n[j], f.c_str(), _TRUNCATE);
}

void _(const int j, const int k, const std::wstring& add)
{
	path p = n[k];
	path f = p / add;
	wcsncpy_s(n[j], f.c_str(), _TRUNCATE);
}

void cf(const int i, const int k, const std::wstring& add)
{
	copy_file(n[i], j(k, add), copy_options::overwrite_existing);
}

void process_end(const std::wstring& name)
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

void download_file(const std::wstring& url, const int j)
{
	URLDownloadToFile(nullptr, std::wstring(L"https://mobasuite.com/" + url).c_str(), n[j], NULL, nullptr);
	unblockfile(n[j]);
}

void apimswincore_bulkdownload(const wchar_t* url)
{
	for (int i = 0; i < 40; i++)
	{
		_(i + 1, 0, apimswincore[i]);
		download_file(&std::wstring(url + std::wstring(apimswincore[i]))[0], i + 1);
	}
}

bool determine_archx64()
{
	BOOL bIsWow64 = FALSE;

	typedef BOOL(APIENTRY* LPFN_ISWOW64PROCESS)
		(HANDLE, PBOOL);

	LPFN_ISWOW64PROCESS fnIsWow64Process;

	HMODULE module = GetModuleHandle(_T("kernel32"));
	const char funcName[] = "IsWow64Process";
	fnIsWow64Process = (LPFN_ISWOW64PROCESS)
		GetProcAddress(module, funcName);

	if (NULL != fnIsWow64Process)
	{
		if (!fnIsWow64Process(GetCurrentProcess(),
			&bIsWow64))
			throw std::exception("Unknown error");
	}
	return bIsWow64 != FALSE;
}

void ini_cfg(const std::wstring& key)
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
			i.lpszTitle = L"<drive>\\Riot Games\\ , <program files>\\TencentGame\\LOL , Garena\\Games\\<lolgame>";
		}
		if (key == L"dota2" || key == L"sm" || key == L"pl")
		{
			i.lpszTitle = L"<program files>\\Steam";
		}
		if (key == L"tgb")
		{
			i.lpszTitle = L"<program files>\\TxGameAssistant\\AppMarket";
		}
		if (key == L"es")
		{
			i.lpszTitle = L"Zenimax Online\\The Elder Scrolls Online";
		}
		if (key == L"ut")
		{
			i.lpszTitle = L"<program files>\\Epic Games";
		}
		if (key == L"l2")
		{
			i.lpszTitle = L"<program files>\\NCSOFT";
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
			i.lpszTitle = L"<program files>\\Black Desert Online";
		}
		if (key == L"dota2")
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
		const auto dl = SHBrowseForFolderW(&i);
		if (dl == nullptr)
		{
			_exit(0);
		}
		SHGetPathFromIDListW(dl, n[0]);
		WritePrivateProfileString(L"Path", key.c_str(), n[0], n[82]);
	}
}

void elevate_process()
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
		pi = {};
		pi.cbSize = sizeof pi;
		pi.fMask = 64;
		pi.lpVerb = L"runas";
		pi.lpFile = my;
		pi.lpDirectory = cp.c_str();
		pi.nShow = SW_SHOW;
		ShellExecuteEx(&pi);
		_exit(0);
	}
}

void game(const std::wstring& dir, const std::wstring& key)
{
	for (int i = 0; i < 57; i++)
	{
		*n[i] = '\0';
	}
	ini_cfg(key);
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
	_(57, 0, L"d3dcompiler_46.dll");
}

void dota2(bool restore)
{
	process_end(L"dota2.exe");
	if (determine_archx64())
	{
		*n[1] = '\0';
		*n[2] = '\0';
		ini_cfg(L"dota2");
		p(0, L"win64");
		_(1, 0, L"d3dcompiler_43.dll");
		_(2, 0, L"embree.dll");
		unblockfile(j(0, L"dota2.exe"));
		if (restore)
		{
			download_file(L"r/dota/x64/d3dcompiler_43.dll", 1);
			download_file(L"r/dota/x64/embree.dll", 2);
		}
		else
		{
			download_file(L"6/D3DCompiler_47.dll", 1);
			download_file(L"6/embree.dll", 2);
		}
	}
	*n[1] = '\0';
	ini_cfg(L"dota2");
	p(0, L"win32");
	_(1, 0, L"d3dcompiler_43.dll");
	unblockfile(j(0, L"dota2.exe"));
	if (restore)
	{
		download_file(L"r/dota/d3dcompiler_43.dll", 1);
	}
	else
	{
		download_file(L"D3DCompiler_47.dll", 1);
	}
	ini_cfg(L"dota2");
	pi = {};
	pi.cbSize = sizeof(SHELLEXECUTEINFO);
	pi.fMask = 64;
	pi.nShow = 5;
	if (determine_archx64())
	{
		p(0, L"win64");
	}
	else
	{
		p(0, L"win32");
	}
	pi.lpFile = j(0, L"dota2.exe").c_str();
	ShellExecuteEx(&pi);
	_exit(0);
}

void lineage(bool restore)
{
	for (auto i = 0; i < 8; i++)
	{
		*n[i] = '\0';
	}
	process_end(L"NCLauncherR.exe");
	process_end(L"NCLauncher.exe");
	process_end(L"L2.bin");
	ini_cfg(L"l2");
	p(0, L"System");
	unblockfile(j(0, L"L2.bin"));
	_(1, 0, L"d3dcompiler_43.dll");
	_(2, 0, L"d3dcompiler_47.dll");
	_(3, 0, L"D3DX9_40.dll");
	_(4, 0, L"vcomp120.dll");
	_(6, 0, L"plugins");
	if (restore)
	{
		download_file(L"r/l2/d3dcompiler_43.dll", 1);
		download_file(L"r/l2/d3dcompiler_47.dll", 2);
		download_file(L"r/l2/D3DX9_40.dll", 3);
		download_file(L"r/l2/vcomp120.dll", 4);
	}
	else
	{
		download_file(L"D3DCompiler_47.dll", 1);
		download_file(L"D3DCompiler_47.dll", 2);
		download_file(L"D3DX9_43.dll", 3);
		download_file(L"vcomp120.dll", 4);
	}
	pi = {};
	pi.cbSize = sizeof(SHELLEXECUTEINFO);
	pi.fMask = 64;
	pi.nShow = 5;
	*n[0] = '\0';
	SHGetSpecialFolderPathW(nullptr, n[0], 42, 0);
	pi.lpVerb = L"runas";
	pi.lpParameters = L"/LauncherID:\"NCWest\" /CompanyID:\"12\" /GameID:\"LINEAGE2\" /LUpdateAddr:\"updater.nclauncher.ncsoft.com\"";
	pi.lpFile = j(0, L"NCWest\\NCLauncher\\NCLauncher.exe").c_str();
	ShellExecuteEx(&pi);
	_exit(0);
}

void blackdesertonline_remastered(bool restore)
{
	process_end(L"BlackDesert32.exe");
	process_end(L"BlackDesert64.exe");
	ini_cfg(L"bdo");
	game(L"bin", L"bdo");
	if (restore)
	{
		apimswincore_bulkdownload(L"r/bdo/");
		download_file(L"r/bdo/msvcp140.dll", 44);
		download_file(L"r/bdo/ucrtbase.dll", 45);
		download_file(L"r/bdo/vcruntime140.dll", 46);
		download_file(L"r/bdo/D3DCompiler_43.dll", 47);
		download_file(L"r/bdo/concrt140.dll", 49);
		download_file(L"r/bdo/mfc140u.dll", 53);
		download_file(L"r/bdo/mfcm140u.dll", 54);
		download_file(L"r/bdo/vcomp140.dll", 55);
		download_file(L"r/bdo/vccorlib140.dll", 56);
	}
	else
	{
		apimswincore_bulkdownload(L"");
		download_file(L"msvcp140.dll", 44);
		download_file(L"ucrtbase.dll", 45);
		download_file(L"vcruntime140.dll", 46);
		download_file(L"D3DCompiler_47.dll", 47);
		download_file(L"concrt140.dll", 49);
		download_file(L"mfc140u.dll", 53);
		download_file(L"mfcm140u.dll", 54);
		download_file(L"vcomp140.dll", 55);
		download_file(L"vccorlib140.dll", 56);
	}
	game(L"bin64", L"bdo");
	if (restore)
	{
		download_file(L"r/bdo/x64/msvcp140.dll", 44);
		download_file(L"r/bdo/x64/ucrtbase.dll", 45);
		download_file(L"r/bdo/x64/vcruntime140.dll", 46);
		download_file(L"r/bdo/x64/D3DCompiler_43.dll", 47);
		download_file(L"r/bdo/x64/concrt140.dll", 49);
		download_file(L"r/bdo/x64/mfc140u.dll", 53);
		download_file(L"r/bdo/x64/mfcm140u.dll", 54);
		download_file(L"r/bdo/x64/vcomp140.dll", 55);
		download_file(L"r/bdo/x64/vccorlib140.dll", 56);
		apimswincore_bulkdownload(L"r/bdo/x64/");
	}
	else
	{
		download_file(L"6/msvcp140.dll", 44);
		download_file(L"6/ucrtbase.dll", 45);
		download_file(L"6/vcruntime140.dll", 46);
		download_file(L"6/D3DCompiler_47.dll", 47);
		download_file(L"6/concrt140.dll", 49);
		download_file(L"6/mfc140u.dll", 53);
		download_file(L"6/mfcm140u.dll", 54);
		download_file(L"6/vcomp140.dll", 55);
		download_file(L"6/vccorlib140.dll", 56);
		apimswincore_bulkdownload(L"6/");
	}
	if (restore)
	{
		download_file(L"r/bdo/main/d3dcompiler_43.dll", 47);
		download_file(L"r/bdo/main/d3dcompiler_46.dll", 57);
	}
	else
	{
		download_file(L"D3DCompiler_47.dll", 47);
		download_file(L"D3DCompiler_47.dll", 57);
	}

	game(L"", L"bdo");
	pi = {};
	pi.cbSize = sizeof(SHELLEXECUTEINFO);
	pi.fMask = 64;
	pi.nShow = 5;
	pi.lpFile = L"Black Desert Online Launcher.exe";
	ShellExecuteEx(&pi);
	_exit(0);
}

void elderscrollsonline(bool restore)
{
	for (int i = 0; i < 7; i++)
	{
		*n[i] = '\0';
	}
	process_end(L"eso.exe");
	process_end(L"eso64.exe");
	ini_cfg(L"es");
	p(0, L"game\\client");
	_(1, 0, L"tbb.dll");
	_(2, 0, L"tbbmalloc.dll");
	_(3, 0, L"x64");
	_(4, 0, L"x86");
	p(3, L"D3DCompiler_47.dll");
	p(4, L"D3DCompiler_47.dll");
	_(5, 0, L"eso.exe");
	_(6, 0, L"eso64.exe");
	if (restore)
	{
		download_file(L"r/teso/tbb.dll", 1);
		download_file(L"r/teso/tbbmalloc.dll", 2);
		download_file(L"r/teso/x64/D3DCompiler_47.dll", 3);
		download_file(L"r/teso/D3DCompiler_47.dll", 4);
	}
	else
	{
		download_file(L"tbb12.dll", 1);
		download_file(L"tbbmalloc.dll", 2);
		download_file(L"6/D3DCompiler_47.dll", 3);
		download_file(L"D3DCompiler_47.dll", 4);
	}
	unblockfile(n[5]);
	unblockfile(n[6]);
	pi = {};
	pi.cbSize = sizeof(SHELLEXECUTEINFO);
	pi.fMask = 64;
	pi.nShow = 5;
	if (determine_archx64())
	{
		pi.lpFile = n[6];
	}
	else
	{
		pi.lpFile = n[5];
	}
	ShellExecuteEx(&pi);
	_exit(0);
}

void worldoftanks(bool restore)
{
	for (int i = 0; i < 46; i++)
	{
		*n[i] = '\0';
	}
	ini_cfg(L"wt");
	wchar_t wt[261] = L"WorldOfTanks.exe";
	process_end(L"WorldOfTanks.exe");
	unblockfile(j(0, wt));
	_(41, 0, L"concrt140.dll");
	_(42, 0, L"msvcp140.dll");
	_(43, 0, L"tbb.dll");
	_(44, 0, L"vcruntime140.dll");
	_(45, 0, L"system");
	_(46, 45, L"ucrtbase.dll");
	if (restore)
	{
		download_file(L"r/wt/concrt140.dll", 41);
		download_file(L"r/wt/msvcp140.dll", 42);
		download_file(L"r/wt/tbb.dll", 43);
		download_file(L"r/wt/vcruntime140.dll", 44);
		download_file(L"r/wt/ucrtbase.dll", 46);
		p(0, L"system");
		apimswincore_bulkdownload(L"r/wt/");
	}
	else
	{
		download_file(L"concrt140.dll", 41);
		download_file(L"msvcp140.dll", 42);
		download_file(L"tbb12.dll", 43);
		download_file(L"vcruntime140.dll", 44);
		download_file(L"ucrtbase.dll", 46);
		p(0, L"system");
		apimswincore_bulkdownload(L"");
	}
	ini_cfg(L"wt");
	pi = {};
	pi.cbSize = sizeof(SHELLEXECUTEINFO);
	pi.fMask = 64;
	pi.nShow = 5;
	pi.lpFile = j(0, wt).c_str();
	ShellExecuteEx(&pi);
	_exit(0);
}

void worldofwarships(bool restore)
{
	for (int i = 0; i < 46; i++)
	{
		*n[i] = '\0';
	}
	ini_cfg(L"ww");
	wchar_t www[261] = L"WorldOfWarships.exe";
	process_end(L"WorldOfWarships.exe");
	unblockfile(j(0, www));
	_(41, 0, L"msvcp140.dll");
	_(42, 0, L"ucrtbase.dll");
	_(43, 0, L"vcruntime140.dll");
	_(44, 0, L"cef");
	_(45, 44, L"d3dcompiler_43.dll");
	_(46, 44, L"d3dcompiler_47.dll");
	if (restore)
	{
		apimswincore_bulkdownload(L"r/wws/");
		download_file(L"r/wws/msvcp140.dll", 41);
		download_file(L"r/wws/ucrtbase.dll", 42);
		download_file(L"r/wws/vcruntime140.dll", 43);
		p(0, L"cef");
		download_file(L"r/wws/d3dcompiler_43.dll", 45);
		download_file(L"r/wws/d3dcompiler_47.dll", 46);
	}
	else
	{
		apimswincore_bulkdownload(L"");
		download_file(L"msvcp140.dll", 41);
		download_file(L"ucrtbase.dll", 42);
		download_file(L"vcruntime140.dll", 43);
		p(0, L"cef");
		download_file(L"D3DCompiler_47.dll", 45);
		download_file(L"D3DCompiler_47.dll", 46);
	}
	ini_cfg(L"ww");
	pi = {};
	pi.cbSize = sizeof(SHELLEXECUTEINFO);
	pi.fMask = 64;
	pi.nShow = 5;
	pi.lpFile = j(0, www).c_str();
	ShellExecuteEx(&pi);
	_exit(0);
}

void _epic(bool restore, bool last)
{
	if (last)
	{
		if (restore)
		{
			download_file(L"r/epic/d3dcompiler_43.dll", 47);
			download_file(L"r/epic/d3dcompiler_47.dll", 48);
		}
		else
		{
			download_file(L"6/D3DCompiler_47.dll", 47);
			download_file(L"6/D3DCompiler_47.dll", 48);
		}
		pi = {};
		pi.cbSize = sizeof(SHELLEXECUTEINFO);
		pi.fMask = 64;
		pi.nShow = 5;
		*n[0] = '\0';
		SHGetSpecialFolderPathW(nullptr, n[0], 42, 0);
		pi.lpFile = j(0, L"Epic Games\\Launcher\\Portal\\Binaries\\Win32\\EpicGamesLauncher.exe").c_str();
		ShellExecuteEx(&pi);
	}
	else
	{
		if (restore)
		{
			apimswincore_bulkdownload(L"r/epic/");
			download_file(L"r/epic/concrt140.dll", 49);
			download_file(L"r/epic/ucrtbase.dll", 45);
			download_file(L"r/epic/vccorlib140.dll", 52);
			download_file(L"r/epic/msvcp140.dll", 44);
			download_file(L"r/epic/vcruntime140.dll", 46);
		}
		else
		{
			download_file(L"6/concrt140.dll", 49);
			apimswincore_bulkdownload(L"6/");
			download_file(L"6/ucrtbase.dll", 45);
			download_file(L"6/vccorlib140.dll", 52);
			download_file(L"6/msvcp140.dll", 44);
			download_file(L"6/vcruntime140.dll", 46);
		}
	}
	_exit(0);
}

void unrealtournament_alpha(bool restore)
{
	ini_cfg(L"ut");
	wchar_t ut[261] = L"UE4-Win64-Shipping.exe";
	process_end(ut);
	process_end(L"EpicGamesLauncher.exe");
	game(L"UnrealTournament\\Binaries\\Win64", L"ut");
	_epic(restore, false);
	game(L"Engine\\Binaries\\Win64", L"ut");
	unblockfile(j(0, ut));
	_epic(restore, false);
	game(L"Engine\\Binaries\\ThirdParty\\CEF3\\Win64", L"ut");
	_epic(restore, true);
	_exit(0);
}

void tencent_gamingbuddy(bool restore)
{
	elevate_process();
	process_end(L"AppMarket.exe");
	process_end(L"QQExternal.exe");
	for (auto i = 0; i < 44; i++)
	{
		*n[i] = '\0';
	}
	ini_cfg(L"tgb");
	_(40, 0, L"msvcp140.dll");
	_(41, 0, L"ucrtbase.dll");
	_(42, 0, L"vcomp140.dll");
	_(43, 0, L"vcruntime140.dll");
	if (restore)
	{
		apimswincore_bulkdownload(L"r/tencentgb");
		download_file(L"r/tencentgb/msvcp140.dll", 40);
		download_file(L"r/tencentgb/ucrtbase.dll", 41);
		download_file(L"r/tencentgb/vcomp140.dll", 42);
		download_file(L"r/tencentgb/vcruntime140.dll", 43);
	}
	else
	{
		apimswincore_bulkdownload(L"");
		download_file(L"msvcp140.dll", 40);
		download_file(L"ucrtbase.dll", 41);
		download_file(L"vcomp140.dll", 42);
		download_file(L"vcruntime140.dll", 43);
	}
	pi = {};
	pi.cbSize = sizeof(SHELLEXECUTEINFO);
	pi.fMask = 64;
	pi.nShow = 5;
	pi.lpVerb = L"runas";
	pi.lpFile = j(0, L"AppMarket.exe").c_str();
	ShellExecuteEx(&pi);
	unblockfile(j(0, L"AppMarket.exe"));
	_exit(0);
}

void leagueoflegends(bool restore)
{
	elevate_process();
	for (auto i = 0; i < 55; i++)
	{
		*n[i] = '\0';
	}
	ini_cfg(L"ll");
	std::wstring dir = n[0];

	process_end(L"League of Legends.exe");
	process_end(L"RiotClientUx.exe");
	process_end(L"RiotClientUxRender.exe");
	process_end(L"LeagueClient.exe");
	p(0, L"Riot Client");
	_(44, 0, L"concrt140.dll");
	_(45, 0, L"vcruntime140.dll");
	_(46, 0, L"ucrtbase.dll");
	_(47, 0, L"msvcp140.dll");


	if (restore)
	{
		apimswincore_bulkdownload(L"r/lol");
		download_file(L"r/lol/concrt140.dll", 44);
		download_file(L"r/lol/vcruntime140.dll", 45);
		download_file(L"r/lol/ucrtbase.dll", 46);
		download_file(L"r/lol/msvcp140.dll", 47);
	}
	else
	{
		apimswincore_bulkdownload(L"");
		download_file(L"concrt140.dll", 44);
		download_file(L"vcruntime140.dll", 45);
		download_file(L"ucrtbase.dll", 46);
		download_file(L"msvcp140.dll", 47);
	}

	p(0, L"UX");
	_(44, 0, L"concrt140.dll");
	_(45, 0, L"vcruntime140.dll");
	_(46, 0, L"ucrtbase.dll");
	_(47, 0, L"msvcp140.dll");
	_(50, 0, L"d3dcompiler_47.dll");
	if (restore)
	{
		apimswincore_bulkdownload(L"r/lol");
		download_file(L"r/lol/concrt140.dll", 44);
		download_file(L"r/lol/vcruntime140.dll", 45);
		download_file(L"r/lol/ucrtbase.dll", 46);
		download_file(L"r/lol/msvcp140.dll", 47);
		download_file(L"r/lol/d3dcompiler_47.dll", 50);
	}
	else
	{
		apimswincore_bulkdownload(L"");
		download_file(L"concrt140.dll", 44);
		download_file(L"vcruntime140.dll", 45);
		download_file(L"ucrtbase.dll", 46);
		download_file(L"msvcp140.dll", 47);
		download_file(L"D3DCompiler_47.dll", 50);
	}
	wcsncpy_s(n[0], dir.c_str(), _TRUNCATE);
	p(0, L"League of Legends");
	_(42, 0, L"Game");
	unblockfile(j(42, L"League of Legends.exe"));
	unblockfile(j(0, L"LeagueClient.exe"));
	_(49, 42, L"D3DCompiler_43.dll");
	_(44, 0, L"concrt140.dll");
	_(45, 0, L"vcruntime140.dll");
	_(46, 0, L"ucrtbase.dll");
	_(47, 0, L"msvcp140.dll");
	_(48, 42, L"tbb.dll");
	_(50, 42, L"D3DCompiler_47.dll");
	_(51, 0, L"D3DCompiler_47.dll");
	if (restore)
	{
		remove(n[48]);
		download_file(L"r/lol/D3DCompiler_43.dll", 42);
		apimswincore_bulkdownload(L"r/lol/");
		download_file(L"r/lol/concrt140.dll", 44);
		download_file(L"r/lol/vcruntime140.dll", 45);
		download_file(L"r/lol/ucrtbase.dll", 46);
		download_file(L"r/lol/msvcp140.dll", 47);
		download_file(L"r/lol/D3DCompiler_43.dll", 49);
		download_file(L"r/lol/d3dcompiler_47.dll", 50);
		download_file(L"r/lol/d3dcompiler_47.dll", 51);
	}
	else
	{
		apimswincore_bulkdownload(L"");
		download_file(L"concrt140.dll", 44);
		download_file(L"vcruntime140.dll", 45);
		download_file(L"ucrtbase.dll", 46);
		download_file(L"msvcp140.dll", 47);
		download_file(L"D3DCompiler_47.dll", 50);
		download_file(L"D3DCompiler_47.dll", 51);
		if (determine_archx64())
		{
			download_file(L"6/tbb12.dll", 48);
			download_file(L"6/D3DCompiler_47.dll", 49);
		}
		else
		{
			download_file(L"tbb12.dll", 48);
			download_file(L"D3DCompiler_47.dll", 49);
		}
	}
	pi = {};
	pi.cbSize = sizeof(SHELLEXECUTEINFO);
	pi.fMask = 64;
	pi.nShow = 5;
	pi.lpFile = j(0, L"LeagueClient.exe").c_str();
	ShellExecuteEx(&pi);
	_exit(0);
}

void smite(bool restore)
{
	elevate_process();
	process_end(L"HirezLauncherUI.exe");
	process_end(L"Smite.exe");
	process_end(L"SteamLauncherUI.exe");
	if (determine_archx64())
	{
		for (auto i = 0; i < 7; i++)
		{
			*n[i] = '\0';
		}
		ini_cfg(L"sm");
		p(0, L"Win64");
		_(1, 0, L"tbbmalloc.dll");
		_(2, 0, L"concrt140.dll");
		_(3, 0, L"vccorlib140.dll");
		_(4, 0, L"vcruntime140.dll");
		_(5, 0, L"d3dcompiler_46.dll");
		unblockfile(j(0, L"Smite.exe"));
		if (restore)
		{
			download_file(L"r/hirez/s/x64/tbbmalloc.dll", 1);
			download_file(L"r/hirez/s/x64/concrt140.dll", 2);
			download_file(L"r/hirez/s/x64/vccorlib140.dll", 3);
			download_file(L"r/hirez/s/x64/vcruntime140.dll", 4);
			download_file(L"r/hirez/s/x64/d3dcompiler_46.dll", 5);
		}
		else
		{
			download_file(L"6/tbbmalloc.dll", 1);
			download_file(L"6/concrt140.dll", 2);
			download_file(L"6/vccorlib140.dll", 3);
			download_file(L"6/vcruntime140.dll", 4);
			download_file(L"6/D3DCompiler_47.dll", 5);
		}
	}
	for (auto i = 0; i < 7; i++)
	{
		*n[i] = '\0';
	}
	ini_cfg(L"sm");
	p(0, L"Win32");
	_(1, 0, L"tbbmalloc.dll");
	_(2, 0, L"concrt140.dll");
	_(3, 0, L"vccorlib140.dll");
	_(4, 0, L"vcruntime140.dll");
	_(5, 0, L"d3dcompiler_46.dll");
	unblockfile(j(0, L"Smite.exe"));
	if (restore)
	{
		download_file(L"r/hirez/s/tbbmalloc.dll", 1);
		download_file(L"r/hirez/s/concrt140.dll", 2);
		download_file(L"r/hirez/s/vccorlib140.dll", 3);
		download_file(L"r/hirez/s/vcruntime140.dll", 4);
		download_file(L"r/hirez/s/d3dcompiler_46.dll", 5);
	}
	else
	{
		download_file(L"tbbmalloc.dll", 1);
		download_file(L"concrt140.dll", 2);
		download_file(L"vccorlib140.dll", 3);
		download_file(L"vcruntime140.dll", 4);
		download_file(L"D3DCompiler_47.dll", 5);
	}
	ini_cfg(L"sm");
	pi = {};
	pi.cbSize = sizeof(SHELLEXECUTEINFO);
	pi.fMask = 64;
	pi.nShow = 5;
	pi.lpParameters = L"game=300 product=17";
	pi.lpFile = j(0, L"SteamLauncherUI.exe").c_str();
	ShellExecuteEx(&pi);
	_exit(0);
}

void paladins(bool restore)
{
	elevate_process();
	process_end(L"HirezLauncherUI.exe");
	process_end(L"Paladins.exe");
	process_end(L"SteamLauncherUI.exe");
	if (determine_archx64())
	{
		*n[0] = '\0';
		*n[1] = '\0';
		ini_cfg(L"pl");
		p(0, L"Win64");
		_(1, 0, L"tbbmalloc.dll");
		unblockfile(j(0, L"Paladins.exe"));
		if (restore)
		{
			download_file(L"r/hirez/p/x64/tbbmalloc.dll", 1);
		}
		else
		{
			download_file(L"6/tbbmalloc.dll", 1);
		}
	}
	*n[0] = '\0';
	*n[1] = '\0';
	ini_cfg(L"pl");
	p(0, L"Win32");
	_(1, 0, L"tbbmalloc.dll");
	unblockfile(j(0, L"Paladins.exe"));
	if (restore)
	{
		download_file(L"r/hirez/p/tbbmalloc.dll", 1);
	}
	else
	{
		download_file(L"tbbmalloc.dll", 1);
	}
	ini_cfg(L"pl");
	pi = {};
	pi.cbSize = sizeof(SHELLEXECUTEINFO);
	pi.fMask = 64;
	pi.nShow = 5;
	pi.lpParameters = L"game=400 product=402";
	pi.lpFile = j(0, L"SteamLauncherUI.exe").c_str();
	ShellExecuteEx(&pi);
	_exit(0);
}

void java_minecraft()
{
	elevate_process();
	*n[0] = '\0';
	p(0, cp);
	if (determine_archx64())
	{
		p(0, L"java15.exe");
		download_file(L"jdk-16_windows-x64_bin.exe", 0);
	}
	else
	{
		p(0, L"java8.exe");
		download_file(L"jre-8u281.exe", 0);
	}
	pi = {};
	pi.cbSize = sizeof(SHELLEXECUTEINFO);
	pi.fMask = 64;
	pi.nShow = 5;
	pi.lpVerb = L"runas";
	pi.lpFile = n[0];
	ShellExecuteEx(&pi);
	if (pi.hProcess != nullptr)
	{
		WaitForSingleObject(pi.hProcess, INFINITE);
	}
	remove(n[0]);
	if (determine_archx64())
	{
		MessageBox(nullptr,
		           L"Minecraft > Launch Options > Advanced > Java Executable Path > Program Files\\Java\\jdk-16\\bin\\javaw.exe",
		           L"Instructions", MB_OK);
	}
	else
	{
		MessageBox(nullptr,
		           L"Minecraft > Launch Options > Advanced > Java Executable Path > Program Files\\Java\\jre-8u281\\bin\\javaw.exe",
		           L"Instructions", MB_OK);
	}
	_exit(0);
}

void deblock_directx9()
{
	elevate_process();
	*n[82] = '\0';
	p(82, cp);
	p(82, L"temp_dx");
	create_directory(n[82]);
	for (auto i = 0; i < 77; i++)
	{
		*n[i] = '\0';
		_(i, 82, dx[i]);
		download_file(&std::wstring(L"9/" + std::wstring(dx[i]))[0], i);
	}
	if (determine_archx64())
	{
		for (auto i = 0; i < 75; i++)
		{
			*n[i] = '\0';
			_(i, 82, dx_64[i]);
			download_file(&std::wstring(L"9/" + std::wstring(dx_64[i]))[0], i);
		}
	}

	for (auto i = 0; i < 5; i++)
	{
		const wchar_t* dx_install[] = {
			L"dsetup.dll", L"dsetup32.dll", L"dxdllreg_x86.cab", L"DXSETUP.exe", L"dxupdate.cab"
		};
		*n[i] = '\0';
		_(i, 82, dx_install[i]);
		download_file(&std::wstring(L"9/" + std::wstring(dx_install[i]))[0], i);
	}
	process_end(L"DXSETUP.exe");
	pi = {};
	pi.cbSize = sizeof(SHELLEXECUTEINFO);
	pi.fMask = 64;
	pi.nShow = 5;
	pi.lpVerb = L"runas";
	pi.lpParameters = L"/silent";
	pi.lpFile = j(82, L"DXSETUP.exe").c_str();
	ShellExecuteEx(&pi);
	if (pi.hProcess != nullptr)
	{
		WaitForSingleObject(pi.hProcess, INFINITE);
	}
	remove_all(n[82]);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPWSTR lpCmdLine,
                      _In_ int nCmdShow)
{
	if (determine_archx64())
	{
		*n[0] = '\0';
		p(0, &cp[0]);
		p(0, L"vcredist_x64.exe");
		download_file(L"vcredist_x64.exe", 0);
		pi = {};
		pi.cbSize = sizeof(SHELLEXECUTEINFO);
		pi.fMask = 64;
		pi.nShow = 5;
		pi.lpVerb = L"runas";
		pi.lpFile = n[0];
		pi.lpParameters = L"/q";
		ShellExecuteEx(&pi);
		if (pi.hProcess != nullptr)
		{
			WaitForSingleObject(pi.hProcess, INFINITE);
		}
		DeleteFile(n[0]);
		*n[0] = '\0';
	}
	else
	{
		*n[0] = '\0';
		p(0, &cp[0]);
		p(0, L"vcredist_x86.exe");
		download_file(L"vcredist_x86.exe", 0);
		pi = {};
		pi.cbSize = sizeof(SHELLEXECUTEINFO);
		pi.fMask = 64;
		pi.nShow = 5;
		pi.lpVerb = L"runas";
		pi.lpFile = n[0];
		pi.lpParameters = L"/q";
		ShellExecuteEx(&pi);
		if (pi.hProcess != nullptr)
		{
			WaitForSingleObject(pi.hProcess, INFINITE);
		}
		DeleteFile(n[0]);
		*n[0] = '\0';
	}

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_MOBASUITE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MOBASUITE));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return static_cast<int>(msg.wParam);
}


//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MOBASUITE));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MOBASUITE);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindow(szWindowClass, L"MOBASuite", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
	                         CW_USEDEFAULT, 470, 180,
	                         nullptr, nullptr, hInstance, nullptr);

	CreateWindow(L"BUTTON", L"Patch", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 10, 100,
	             100, hWnd, reinterpret_cast<HMENU>(1), hInstance, nullptr);
	CreateWindow(L"BUTTON", L"Restore", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 350, 10, 100,
	             100, hWnd, reinterpret_cast<HMENU>(2), hInstance, nullptr);
	HWND hWndComboBox = CreateWindow(WC_COMBOBOX, L"",
	                                 CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
	                                 120, 10, 220, 360, hWnd, NULL, hInstance,
	                                 NULL);
	for (auto& i : cmbbox)
	{
		SendMessage(hWndComboBox, CB_ADDSTRING, static_cast<WPARAM>(0), reinterpret_cast<LPARAM>(i));
	}
	SendMessage(hWndComboBox, CB_SETCURSEL, static_cast<WPARAM>(0), static_cast<LPARAM>(0));

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
		{
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
					leagueoflegends(false);
					break;
				case 1:
					smite(false);
					break;
				case 2:
					dota2(false);
					break;
				case 3:
					unrealtournament_alpha(false);
					break;
				case 4:
					java_minecraft();
					break;
				case 5:
					blackdesertonline_remastered(false);
					break;
				case 6:
					paladins(false);
					break;
				case 7:
					worldoftanks(false);
					break;
				case 8:
					worldofwarships(false);
					break;
				case 9:
					lineage(false);
					break;
				case 10:
					elderscrollsonline(false);
					break;
				case 11:
					tencent_gamingbuddy(false);
					break;
				case 12:
					deblock_directx9();
					break;
				default: ;
				}
			}
			if (LOWORD(wParam) == 2)
			{
				switch (c)
				{
				case 0:
					leagueoflegends(true);
					break;
				case 1:
					smite(true);
					break;
				case 2:
					dota2(true);
					break;
				case 3:
					unrealtournament_alpha(true);
					break;
				case 5:
					blackdesertonline_remastered(true);
					break;
				case 6:
					paladins(true);
					break;
				case 7:
					worldoftanks(true);
					break;
				case 8:
					worldofwarships(true);
					break;
				case 9:
					lineage(true);
					break;
				case 10:
					elderscrollsonline(true);
					break;
				case 11:
					tencent_gamingbuddy(true);
					break;
				}
			}

			int wmId = LOWORD(wParam);
			// Parse the menu selections:
			switch (wmId)
			{
			case IDM_ABOUT:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
				break;
			case IDM_EXIT:
				DestroyWindow(hWnd);
				break;
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
		}
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code that uses hdc here...
			EndPaint(hWnd, &ps);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}
