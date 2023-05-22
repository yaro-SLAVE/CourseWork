#include "Log.h"
#include "Reg.h"
#include "Main.h"
#include "Settings.h"
#include "Playground.h"
#include "Continue_Game.h"
#include "Leaders_Table.h"
#include "Splash_Screen.h"
#include "Cons_Devel.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace Project3;

int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Splash_Screen);

	return 0;
}

