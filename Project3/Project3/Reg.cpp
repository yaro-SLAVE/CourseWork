#include "Reg.h"

System::Void Project3::Reg::back_but_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

System::Void Project3::Reg::reg_but_Click(System::Object^ sender, System::EventArgs^ e)
{
    enter();
}

System::Void Project3::Reg::log_box_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e)
{
    if (e->KeyCode == Keys::Enter)
        pass_box->Focus();
}

System::Void Project3::Reg::pass_box_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e)
{
    if (e->KeyCode == Keys::Enter)
        enter();
}

void Project3::Reg::enter()
{
	if (String::Compare(log_box->Text, "") == 0 || String::Compare(log_box->Text, "") == 0)
		MessageBox::Show("����� �/��� ������ �� �������!", "������");
	else
	{
		bool flag = true;

		FileStream^ fs = gcnew FileStream("Logins.bin", FileMode::Open);
		BinaryReader^ br = gcnew BinaryReader(fs);

		while (br->BaseStream->Position < br->BaseStream->Length)
		{
			if (log_box->Text == br->ReadString() || log_box->Text == "Guest")
			{
				flag = false;
				MessageBox::Show("������� ������ � ������ ������� ��� ����������. �������� �����", "������");
				break;
			}
		}

		fs->Close();

		if (flag)
		{
			fs = gcnew FileStream("Logins.bin", FileMode::Append);
			BinaryWriter^ w = gcnew BinaryWriter(fs);
			w->Write(log_box->Text);
			w->Write(pass_box->Text);
			fs->Close();

			StreamWriter^ sw = gcnew StreamWriter("Players\\" + log_box->Text + ".txt");
			sw->WriteLine("0_0_0"); //����_������_���������
			sw->WriteLine("true"); //������� ��������� �������
			sw->WriteLine("false"); //������� ��������� �������
			sw->WriteLine("false"); //������� ��������� ������������
			sw->WriteLine("true"); //�������������� ����������
			sw->WriteLine("true"); //�������� �������������
			sw->WriteLine("false"); //���� �� ������������� ����
			sw->Close();


			MessageBox::Show("������� ������ �������!", "������");

			this->Close();
		}
	}
}
