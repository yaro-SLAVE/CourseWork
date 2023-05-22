#include "Leaders_Table.h"

System::Void Project3::Leaders_Table::Leaders_Table_Load(System::Object^ sender, System::EventArgs^ e)
{
	array<String^>^ data = System::IO::Directory::GetFiles("Players\\");

	int num_of_rows = 0;
	String^ str = "";
	int points = 0;
	int num_of_wins = 0;
	int num_of_losses = 0;
	for (int p = 0; p < data->Length; ++p)
	{
		if (data[p] != "Players\\Guest.txt")
		{
			StreamReader^ din = File::OpenText(data[p]);
			str = din->ReadLine();
			din->Close();

			String^ str2 = "";
			int j = 0;
			int k = 0;
			points = 0;
			num_of_wins = 0;
			num_of_losses = 0;
			while (j < str->Length)
			{
				if (str[j] == '_')
				{
					if (k == 0)
					{
						points = int::Parse(str2);
						str2 = "";
					}

					if (k == 1)
					{
						num_of_wins = int::Parse(str2);
						str2 = "";
					}

					++k;
					++j;
				}

				else if (j == str->Length - 1)
				{
					str2 += str[j];
					num_of_losses = int::Parse(str2);
					++j;
				}

				else
				{
					str2 += str[j];
					++j;
				}
			}

			String^ name = data[p]->Remove(0, 8);
			DataGridViewRow^ row = gcnew DataGridViewRow();
			row->CreateCells(Leaders);
			row->Cells[0]->Value = p + 1;
			row->Cells[1]->Value = name->Remove(name->Length - 4);
			row->Cells[2]->Value = points;
			row->Cells[3]->Value = num_of_wins;
			row->Cells[4]->Value = num_of_losses;
			rows[num_of_rows] = row;
			++num_of_rows;
		}
	}

	DataGridViewRow^ dop = gcnew DataGridViewRow();
	for (int i = 0; i < num_of_rows - 1; ++i)
		for (int j = 0; j < num_of_rows - i - 1; ++j)
			if (int::Parse(rows[j]->Cells[2]->Value->ToString()) < int::Parse(rows[j + 1]->Cells[2]->Value->ToString()))
			{
				dop = rows[j];
				rows[j] = rows[j + 1];
				rows[j + 1] = dop;
			}
	for (int i = 0; i < num_of_rows; ++i)
	{
		if (rows[i]->Cells[1]->Value->ToString() == login)
			rows[i]->DefaultCellStyle->BackColor = Color::Gainsboro;
		rows[i]->Cells[0]->Value = i + 1;
		Leaders->Rows->Add(rows[i]);
	}
}

System::Void Project3::Leaders_Table::back_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
