#include "Log.h"

System::Void Project3::Log::reg_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	reg = gcnew Reg();
	reg->Owner = this;
	this->reg->Closed += gcnew EventHandler(this, &Log::forms_Closed);
	this->Hide();
	reg->ShowDialog();
}

System::Void Project3::Log::guest_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Вы действительно хотите продолжить как Гость? Ваш прогресс не будет сохранён", "Guest",
		MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
	{
		log_box->Clear();
		pass_box->Clear();
		main = gcnew Main("Guest");
		this->main->Closed += gcnew EventHandler(this, &Log::forms_Closed);
		main->Owner = this;
		this->Hide();
		main->ShowDialog();
	}
}

System::Void Project3::Log::enter_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	enter();
}

System::Void Project3::Log::exit_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Вы действительно хотите выйти?", "Выход",
		MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
	{
		this->Close();
	}
}

System::Void Project3::Log::log_box_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e)
{
	if (e->KeyCode == Keys::Enter)
		pass_box->Focus();		
}

System::Void Project3::Log::pass_box_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e)
{
	if (e->KeyCode == Keys::Enter)
	{
		enter();
	}
}

void Project3::Log::forms_Closed(System::Object^ sender, System::EventArgs^ e)
{
	this->Show();
}

void Project3::Log::enter()
{
	if (String::Compare(log_box->Text, "") == 0 || String::Compare(log_box->Text, "") == 0)
		MessageBox::Show("Логин и/или пароль не введены!", "Ошибка");
	else
	{
		FileStream^ fs = gcnew FileStream("Logins.bin", FileMode::Open);
		BinaryReader^ br = gcnew BinaryReader(fs);

		bool flag = false;
		while (br->BaseStream->Position < br->BaseStream->Length)
		{
			if (br->ReadString() == log_box->Text)
			{
				if (br->ReadString() == pass_box->Text)
					flag = true;
				break;
			}
		}

		fs->Close();

		if (flag)
		{
			Login = log_box->Text;
			log_box->Clear();
			pass_box->Clear();
			main = gcnew Main(Login);
			this->main->Closed += gcnew EventHandler(this, &Log::forms_Closed);
			main->Owner = this;
			this->Hide();
			main->ShowDialog();
		}

		else
			MessageBox::Show("Неправильный логин или пароль", "Ошибка!");
	}
}

System::Void Project3::Log::Log_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	Application::Exit();
}
