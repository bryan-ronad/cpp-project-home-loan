#include "Landing.h"
#include "Windows.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace HLoanApplication;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)

{
	srand((unsigned)time(NULL));
	AllocConsole();
	freopen("CONOUT$", "w", stdout);


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew Landing());
	return 0;
}

