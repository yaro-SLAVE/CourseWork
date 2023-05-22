#include "Main.h"

System::Void Project3::Main::Main_Load(System::Object^ sender, System::EventArgs^ e)
{
	StreamReader^ din = File::OpenText("Players\\" + Login + ".txt");

	for (int i = 0; i < 7; ++i)
		data[i] = din->ReadLine();
	din->Close();
	continue_but->Visible = bool::Parse(data[6]);
}

System::Void Project3::Main::Main_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	if (Login == "Guest")
	{
		StreamWriter^ sw = gcnew StreamWriter("Players\\Guest.txt");
		sw->WriteLine(0); //очки
		sw->WriteLine("true"); //уровень сложности новичок
		sw->WriteLine("false"); //уровень сложности опытный
		sw->WriteLine("false"); //уровень сложности профессионал
		sw->WriteLine("true"); //автоматическое сохранение
		sw->WriteLine("true"); //звуковое сопровождение
		sw->WriteLine("false"); //есть ли незаконченна€ игра
		sw->Close();
	}
}

System::Void Project3::Main::sett_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	sett = gcnew Settings(Login);
	sett->Owner = this;
	this->sett->Closed += gcnew EventHandler(this, &Main::forms_Closed);
	this->Hide();
	sett->ShowDialog();
}

System::Void Project3::Main::exit_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("¬ы действительно хотите выйти?", "¬ыход",
		MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		this->Close();
}

System::Void Project3::Main::newGame_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (bool::Parse(data[6]))
	{
		if (MessageBox::Show("¬ы действительно хотите начать новую игру? —охранЄнна€ игра будет потер€на", "Ќова€ игра",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			pl_gr = gcnew Playground(Login);
			pl_gr->Owner = this;
			this->pl_gr->Closed += gcnew EventHandler(this, &Main::forms_Closed);
			this->Hide();
			pl_gr->ShowDialog();
		}
	}

	else
	{
		pl_gr = gcnew Playground(Login);
		pl_gr->Owner = this;
		this->pl_gr->Closed += gcnew EventHandler(this, &Main::forms_Closed);
		this->Hide();
		pl_gr->ShowDialog();
	}
}

System::Void Project3::Main::rules_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	Process::Start("notepad.exe", "Additional Information\\Rules.txt");
}

System::Void Project3::Main::continue_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	cont_game = gcnew Continue_Game(Login);
	cont_game->Owner = this;
	this->cont_game->Closed += gcnew EventHandler(this, &Main::forms_Closed);
	this->Hide();
	cont_game->ShowDialog();
}

void Project3::Main::forms_Closed(System::Object^ sender, System::EventArgs^ e)
{
	StreamReader^ din = File::OpenText("Players\\" + Login + ".txt");

	for (int i = 0; i < 7; ++i)
		data[i] = din->ReadLine();
	din->Close();
	continue_but->Visible = bool::Parse(data[6]);

	this->Show();
}

System::Void Project3::Main::lead_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	lead = gcnew Leaders_Table(Login);
	lead->Owner = this;
	this->lead->Closed += gcnew EventHandler(this, &Main::forms_Closed);
	this->Hide();
	lead->ShowDialog();
}

System::Void Project3::Main::about_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	Process::Start("notepad.exe", "Additional Information\\About.txt");
}
