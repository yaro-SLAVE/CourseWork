#include "Splash_Screen.h"

System::Void Project3::Splash_Screen::Splash_Screen_Load(System::Object^ sender, System::EventArgs^ e)
{
	timer->Enabled = true;
	timer->Interval = 1500;
}

System::Void Project3::Splash_Screen::timer_Tick(System::Object^ sender, System::EventArgs^ e)
{
	++i;
	pr_bar->PerformStep();
	label->Text = comments[i];
	if (i == 10)
	{
		timer->Enabled = false;

		log = gcnew Log();
		log->Owner = this;
		this->Hide();
		log->ShowDialog();
	}
}
