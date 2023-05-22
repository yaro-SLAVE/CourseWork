#include "Settings.h"

System::Void Project3::Settings::Settings_Load(System::Object^ sender, System::EventArgs^ e)
{
	StreamReader^ din = File::OpenText("Players\\" + Login + ".txt");

	int i = 0;
	while ((data[i] = din->ReadLine()) != nullptr)
		++i;
	din->Close();

	jun_flag->Checked = bool::Parse(data[1]);
	mid_flag->Checked = bool::Parse(data[2]);
	prof_flag->Checked = bool::Parse(data[3]);
	save_box->Checked = bool::Parse(data[4]);
	sound_box->Checked = bool::Parse(data[5]);
}

System::Void Project3::Settings::Settings_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	data_write();
}

System::Void Project3::Settings::back_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

void Project3::Settings::data_write()
{
	if (jun_flag->Checked)
	{
		data[1] = "true";
		data[2] = "false";
		data[3] = "false";
	}

	else if (mid_flag->Checked)
	{
		data[1] = "false";
		data[2] = "true";
		data[3] = "false";
	}

	else if (prof_flag->Checked)
	{
		data[1] = "false";
		data[2] = "false";
		data[3] = "true";
	}

	if (save_box->Checked)
		data[4] = "true";
	else
		data[4] = "false";

	if (sound_box->Checked)
		data[5] = "true";
	else
		data[5] = "false";

	if (!(bool::Parse(data[6])))
	{
		StreamWriter^ sw = gcnew StreamWriter("Players\\" + Login + ".txt");
		for (int i = 0; i < 7; ++i)
			sw->WriteLine(data[i]);
		sw->Close();
	}

	else if (bool::Parse(data[6]))
	{
		StreamWriter^ sw = gcnew StreamWriter("Players\\" + Login + ".txt");
		for (int i = 0; i < 32 * 16 + 10; ++i)
			sw->WriteLine(data[i]);
		sw->Close();
	}

}
