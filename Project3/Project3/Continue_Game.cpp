#include "Continue_Game.h"

System::Void Project3::Continue_Game::Continue_Game_Load(System::Object^ sender, System::EventArgs^ e)
{
	StreamReader^ din = File::OpenText("Players\\" + Login + ".txt");

	int i = 0;
	while ((data[i] = din->ReadLine()) != nullptr)
		++i;
	din->Close();

	String^ str = data[0];
	String^ str2 = "";
	int j = 0;
	int k = 0;
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

	if (int::Parse(data[7]) == 1)
	{
		but_in_height = 8;
		but_in_weight = 8;
		bombs = 10;
		level = 1;
		level_coefficient = 1;
		max_time = 50;
		min_points = 5;
	}

	else if (int::Parse(data[7]) == 2)
	{
		but_in_height = 16;
		but_in_weight = 16;
		bombs = 40;
		level = 2;
		level_coefficient = 4;
		max_time = 125;
		min_points = 15;
	}

	else if (int::Parse(data[7]) == 3)
	{
		but_in_height = 16;
		but_in_weight = 32;
		bombs = 99;
		level = 3;
		level_coefficient = 8;
		max_time = 400;
		min_points = 25;
	}

	save = bool::Parse(data[4]);
	sound = bool::Parse(data[5]);

	if (sound)
	{
		click = gcnew SoundPlayer("Sounds\\click.wav");
		tick = gcnew SoundPlayer("Sounds\\tick.wav");
		lose = gcnew SoundPlayer("Sounds\\lose.wav");
		win = gcnew SoundPlayer("Sounds\\win.wav");
	}

	else
	{
		click = gcnew SoundPlayer("Sounds\\silent.wav");
		tick = gcnew SoundPlayer("Sounds\\silent.wav");
		lose = gcnew SoundPlayer("Sounds\\silent.wav");
		win = gcnew SoundPlayer("Sounds\\silent.wav");
	}

	count_flags = int::Parse(data[8]);
	seconds = int::Parse(data[9]);
	count_empties = but_in_weight * but_in_height - bombs;

	restart_but->BackColor = System::Drawing::Color::DarkGray;
	restart_but->Location = System::Drawing::Point(but_in_weight * but_size / 2 + field_padding - resbut_size / 2, field_padding);
	restart_but->Size = System::Drawing::Size(resbut_size, resbut_size);
	restart_but->BackgroundImage = ImageList2->Images[0];
	restart_but->BackgroundImageLayout = ImageLayout::Center;
	Controls->Add(restart_but);

	time->Location = System::Drawing::Point(but_in_weight * but_size / 2 + field_padding + resbut_size / 2 + field_padding, field_padding);
	time->Size = System::Drawing::Size(60, resbut_size);
	time->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	time->BackColor = System::Drawing::Color::Transparent;
	time->Text = L"000";
	Controls->Add(time);

	flags->Location = System::Drawing::Point(but_in_weight * but_size / 2 - resbut_size - field_padding, field_padding);
	flags->Size = System::Drawing::Size(40, resbut_size);
	flags->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	flags->BackColor = System::Drawing::Color::Transparent;
	Controls->Add(flags);

	back_but->BackColor = System::Drawing::Color::DarkGray;
	back_but->Location = System::Drawing::Point(field_padding, field_padding);
	back_but->Size = System::Drawing::Size(resbut_size / 1.5, resbut_size);
	back_but->Text = "<";
	Controls->Add(back_but);

	pause_but->BackColor = System::Drawing::Color::DarkGray;
	pause_but->Location = System::Drawing::Point(but_in_weight * but_size / 2 + field_padding + resbut_size / 2 + field_padding + 60, field_padding);
	pause_but->Size = System::Drawing::Size(resbut_size / 1.25, resbut_size);
	pause_but->Text = "| |";
	Controls->Add(pause_but);

	ClientSize = System::Drawing::Size(but_in_weight * but_size + field_padding * 2, but_in_height * but_size + field_padding * 3 + resbut_size);

	create_field_continue();
}

void Project3::Continue_Game::create_field_continue()
{
	int i = 10;
	int j = 0;
	int k = 0;
	String^ str1 = "";
	String^ str2 = "";
	for (int y = 0; y < but_in_height; ++y)
		for (int x = 0; x < but_in_weight; ++x)
		{
			but_extended^ but = gcnew but_extended();
			j = 0;
			str1 = data[i];
			str2 = "";
			k = 0;
			while (j < str1->Length)
			{
				if (str1[j] == '_')
				{
					if (k == 0)
						but->Enabled = bool::Parse(str2);
					else if (k == 1)
						but->isbomb = bool::Parse(str2);
					else if (k == 2)
						but->isflaged = bool::Parse(str2);
					else if (k == 3)
						but->isempty = bool::Parse(str2);
					str2 = "";
					++j;
					++k;
				}

				else if (str1[j] == '/0')
					but->isforbidden = bool::Parse(str2);

				str2 += str1[j];
				++j;
			}

			but->BackColor = System::Drawing::Color::FromName(unpush_color);
			but->Location = System::Drawing::Point(x * but_size + start_x, y * but_size + start_y);
			but->Size = System::Drawing::Size(but_size, but_size);
			but->FlatAppearance->BorderColor = System::Drawing::Color::Gray;
			but->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			allbuts[x, y] = but;
			if (!but->Enabled)
				but->BackColor = System::Drawing::Color::FromName(push_color);

			Controls->Add(but);
			out_flags();
			but->MouseUp += gcnew MouseEventHandler(this, &Continue_Game::field_click_continue);
			++i;
		}

	for (int y = 0; y < but_in_height; ++y)
		for (int x = 0; x < but_in_weight; ++x)
		{
			if (allbuts[x, y]->isflaged)
			{
				allbuts[x, y]->BackgroundImage = ImageList1->Images[9];
				allbuts[x, y]->BackgroundImageLayout = ImageLayout::Center;
			}

			if (!allbuts[x, y]->Enabled && count_bombs_around(x, y) != 0)
			{
				allbuts[x, y]->BackgroundImage = ImageList1->Images[count_bombs_around(x, y)];
				allbuts[x, y]->BackgroundImageLayout = ImageLayout::Center;
			}
		}
}

void Project3::Continue_Game::out_flags()
{
	if (count_flags > 9)
		flags->Text = Convert::ToString(count_flags);
	else if (count_flags < 10)
		flags->Text = "0" + Convert::ToString(count_flags);
}

void Project3::Continue_Game::field_click_continue(System::Object^ sender, MouseEventArgs^ e)
{
	but_extended^ but = (but_extended^)sender;

	if (!but->isforbidden && !pause)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left && !but->isflaged)
		{
			if (first_click_continue)
			{
				if (!but->isbomb)
				{
					click->Play();
					but->isempty = true;
					empty_click(but);
					first_click_continue = false;

					this->timer->Enabled = true;
					this->timer->Interval = 1000;
				}

				else
					boom(but);
			}

			else if (but->isbomb)
				boom(but);
			else
			{
				click->Play();
				but->isempty = true;
				empty_click(but);

			}

		}

		if (e->Button == System::Windows::Forms::MouseButtons::Right)
		{
			tick->Play();
			if (first_click_continue)
			{
				first_click_continue = false;
				this->timer->Enabled = true;
				this->timer->Interval = 1000;
			}

			if (!but->isflaged && count_flags > 0)
			{
				but->BackgroundImage = ImageList1->Images[9];
				but->BackgroundImageLayout = ImageLayout::Center;
				--count_flags;
				out_flags();
				but->isflaged = true;
			}

			else if (but->isflaged)
			{
				but->BackgroundImage = nullptr;
				++count_flags;
				out_flags();
				but->isflaged = false;
			}
		}
	}

	for (int y = 0; y < but_in_height; ++y)
		for (int x = 0; x < but_in_weight; ++x)
		{
			if (!allbuts[x, y]->Enabled)
				--count_empties;
		}
	if (count_empties == 0)
		winner();
	else
		count_empties = but_in_weight * but_in_height - bombs;
}

void Project3::Continue_Game::empty_click(but_extended^ but)
{
	int bombs_around = 0;
	for (int y = 0; y < but_in_height; ++y)
		for (int x = 0; x < but_in_weight; ++x)
			if (allbuts[x, y] == but)
			{
				bombs_around = count_bombs_around(x, y);
				if (bombs_around == 0)
				{
					but->isempty = true;
					empty_but(x, y);
				}
			}

	if (bombs_around != 0)
	{
		but->BackgroundImage = ImageList1->Images[bombs_around];
		but->BackgroundImageLayout = ImageLayout::Center;
	}

	but->BackColor = System::Drawing::Color::FromName(push_color);
	but->Enabled = false;
}

int Project3::Continue_Game::count_bombs_around(int xb, int yb)
{
	int count_bombs = 0;
	for (int y = yb - 1; y <= yb + 1; ++y)
		for (int x = xb - 1; x <= xb + 1; ++x)
			if (x >= 0 && x < but_in_weight && y >= 0 && y < but_in_height)
				if (allbuts[x, y]->isbomb)
					++count_bombs;
	return count_bombs;
}

void Project3::Continue_Game::empty_but(int xb, int yb)
{
	for (int y = yb - 1; y <= yb + 1; ++y)
		for (int x = xb - 1; x <= xb + 1; ++x)
			if (x >= 0 && x < but_in_weight && y >= 0 && y < but_in_height)
			{
				if (count_bombs_around(x, y) == 0 && !allbuts[x, y]->isempty)
				{
					allbuts[x, y]->isempty = true;
					empty_but(x, y);
				}

				else if (count_bombs_around(x, y) != 0)
				{
					allbuts[x, y]->BackgroundImage = ImageList1->Images[count_bombs_around(x, y)];
					allbuts[x, y]->BackgroundImageLayout = ImageLayout::Center;
				}

				allbuts[x, y]->BackColor = System::Drawing::Color::FromName(push_color);
				allbuts[x, y]->Enabled = false;
			}
}

System::Void Project3::Continue_Game::pause_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!pause)
	{
		pause_but->Text = ">";
		timer->Enabled = false;
		pause = true;
	}

	else if (pause)
	{
		pause_but->Text = "| |";
		timer->Enabled = true;
		pause = false;
	}

}

void Project3::Continue_Game::restart_click(System::Object^ sender, MouseEventArgs^ e)
{
	timer->Enabled = false;
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		if ((first_click || islose || iswin) || (!first_click && (MessageBox::Show("Вы действительно хотите перезагрузить текущую игру?", "Перезапуск",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)))
		{
			for (int y = 0; y < but_in_height; ++y)
				for (int x = 0; x < but_in_weight; ++x)
					Controls->Remove(allbuts[x, y]);
			delete_all();
			create_field();
			restart_but->BackgroundImage = ImageList2->Images[0];
		}
		else
			timer->Enabled = true;
	}
}

void Project3::Continue_Game::create_field()
{
	for (int y = 0; y < but_in_height; ++y)
		for (int x = 0; x < but_in_weight; ++x)
		{
			but_extended^ but = gcnew but_extended();
			but->BackColor = System::Drawing::Color::FromName(unpush_color);
			but->Location = System::Drawing::Point(x * but_size + start_x, y * but_size + start_y);
			but->Size = System::Drawing::Size(but_size, but_size);
			but->FlatAppearance->BorderColor = System::Drawing::Color::Gray;
			but->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			but->isforbidden = false;
			allbuts[x, y] = but;
			Controls->Add(but);
			out_flags();
			but->MouseUp += gcnew MouseEventHandler(this, &Continue_Game::field_click);
		}
}

void Project3::Continue_Game::field_click(System::Object^ sender, MouseEventArgs^ e)
{
	but_extended^ but = (but_extended^)sender;

	if (!but->isforbidden && !pause)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left && !but->isflaged)
		{
			if (first_click)
			{
				click->Play();
				for (int y = 0; y < but_in_height; ++y)
					for (int x = 0; x < but_in_weight; ++x)
						if (allbuts[x, y] == but)
						{
							generate_bombs(x, y);
							break;
						}
				but->isempty = true;
				empty_click(but);
				first_click = false;

				this->timer->Enabled = true;
				this->timer->Interval = 1000;

			}

			else if (but->isbomb)
				boom(but);
			else
			{
				click->Play();
				but->isempty = true;
				empty_click(but);

			}

		}

		if (e->Button == System::Windows::Forms::MouseButtons::Right)
		{
			tick->Play();
			if (!but->isflaged && count_flags > 0)
			{
				but->BackgroundImage = ImageList1->Images[9];
				but->BackgroundImageLayout = ImageLayout::Center;
				--count_flags;
				out_flags();
				but->isflaged = true;
			}

			else if (but->isflaged)
			{
				but->BackgroundImage = nullptr;
				++count_flags;
				out_flags();
				but->isflaged = false;
			}
		}
	}

	for (int y = 0; y < but_in_height; ++y)
		for (int x = 0; x < but_in_weight; ++x)
		{
			if (!allbuts[x, y]->Enabled)
				--count_empties;
		}
	if (count_empties == 0)
		winner();
	else
		count_empties = but_in_weight * but_in_height - bombs;
}

void Project3::Continue_Game::generate_bombs(int xb, int yb)
{
	int count_bombs = 0;
	Random^ rand = gcnew Random();
	while (count_bombs < bombs)
	{
		int x = rand->Next(0, but_in_weight);
		int y = rand->Next(0, but_in_height);
		if (((x < xb - 1 || x > xb + 1) && (y < yb - 1 || y > yb + 1)) && !allbuts[x, y]->isbomb)
		{
			allbuts[x, y]->isbomb = true;
			++count_bombs;
		}
	}
}

void Project3::Continue_Game::winner()
{
	win->Play();
	timer->Enabled = false;
	if (Login != "Guest")
	{
		if (seconds < max_time)
			points += (max_time - seconds) * min_points * level_coefficient;
		else if (seconds >= max_time)
			points += min_points * level_coefficient;

		++num_of_wins;
	}
	iswin = true;
	restart_but->BackgroundImage = ImageList2->Images[1];
	restart_but->BackgroundImageLayout = ImageLayout::Center;
	MessageBox::Show("Вы победили!", "Поздравдяем");
}

void Project3::Continue_Game::boom(but_extended^ but)
{
	{
		lose->Play();
		timer->Enabled = false;
		if (Login != "Guest")
			++num_of_losses;
		restart_but->BackgroundImage = ImageList2->Images[2];
		restart_but->BackgroundImageLayout = ImageLayout::Center;
		for (int y = 0; y < but_in_height; ++y)
			for (int x = 0; x < but_in_weight; ++x)
			{
				allbuts[x, y]->isforbidden = true;

				if (allbuts[x, y] == but)
				{
					allbuts[x, y]->BackgroundImage = ImageList1->Images[0];
					allbuts[x, y]->BackgroundImageLayout = ImageLayout::Center;
				}

				else if (allbuts[x, y] != but && (allbuts[x, y]->isflaged && !allbuts[x, y]->isbomb))
				{
					allbuts[x, y]->BackgroundImage = ImageList1->Images[11];
					allbuts[x, y]->BackgroundImageLayout = ImageLayout::Center;
				}

				else if (allbuts[x, y]->isbomb && allbuts[x, y] != but && !allbuts[x, y]->isflaged)
				{
					allbuts[x, y]->BackgroundImage = ImageList1->Images[10];
					allbuts[x, y]->BackgroundImageLayout = ImageLayout::Center;
				}
			}
		islose = true;
	}
}

System::Void Project3::Continue_Game::timer_Tick(System::Object^ sender, System::EventArgs^ e)
{
	if (seconds < 1000)
	{
		if (seconds >= 99)
			razr = "";
		else if (seconds >= 9)
			razr = "0";
		else if (seconds <= 8)
			razr = "00";
		++seconds;
		time->Text = razr + Convert::ToString(seconds);
	}

	else
		time->Text = "999";
}

System::Void Project3::Continue_Game::back_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	timer->Enabled = false;
	if (save)
	{
		if (MessageBox::Show("Вы действительно хотите Выйти?", "Выход",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			this->Close();
		else
			timer->Enabled = true;
	}

	else
	{
		System::Windows::Forms::DialogResult result = MessageBox::Show("Вы хотите сохранить текущую игру?", "Выход",
			MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
		if (result == System::Windows::Forms::DialogResult::Yes)
		{
			save = true;
			this->Close();
		}

		else if (result == System::Windows::Forms::DialogResult::No)
			this->Close();

		else
			timer->Enabled = true;
	}
}

System::Void Project3::Continue_Game::Continue_Game_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	if (save)
	{
		timer->Enabled = false;

		if ((!first_click || !first_click_continue) && (!islose && !iswin))
		{
			StreamWriter^ sw = gcnew StreamWriter("Players\\" + Login + ".txt");
			if (Login != "Guest")
				sw->WriteLine(points + "_" + num_of_wins + "_" + num_of_losses);
			else
				sw->WriteLine(data[0]);

			for (int i = 1; i < 6; ++i)
				sw->WriteLine(data[i]);
			sw->WriteLine("true");
			sw->WriteLine(level);
			sw->WriteLine(count_flags);
			sw->WriteLine(seconds);

			for (int y = 0; y < but_in_height; ++y)
				for (int x = 0; x < but_in_weight; ++x)
				{
					sw->WriteLine(allbuts[x, y]->Enabled + "_" + allbuts[x, y]->isbomb + "_" + allbuts[x, y]->isflaged + "_" + allbuts[x, y]->isempty + "_" + allbuts[x, y]->isforbidden);
					Controls->Remove(allbuts[x, y]);
				}
			sw->Close();
			delete_all();
			Controls->Remove(time);
			Controls->Remove(flags);
			Controls->Remove(restart_but);
			Controls->Remove(back_but);
		}

		else if ((first_click || islose || iswin) && !first_click_continue)
		{
			StreamWriter^ sw = gcnew StreamWriter("Players\\" + Login + ".txt");
			if (Login != "Guest")
				sw->WriteLine(points + "_" + num_of_wins + "_" + num_of_losses);
			else
				sw->WriteLine(data[0]);

			for (int i = 1; i < 6; ++i)
				sw->WriteLine(data[i]);
			sw->WriteLine("false");
			sw->Close();

			for (int y = 0; y < but_in_height; ++y)
				for (int x = 0; x < but_in_weight; ++x)
					Controls->Remove(allbuts[x, y]);
			delete_all();
			Controls->Remove(time);
			Controls->Remove(flags);
			Controls->Remove(restart_but);
			Controls->Remove(back_but);
		}
	}

	else
	{
		StreamWriter^ sw = gcnew StreamWriter("Players\\" + Login + ".txt");
		if (Login != "Guest")
			sw->WriteLine(points + "_" + num_of_wins + "_" + num_of_losses);
		else
			sw->WriteLine(data[0]);

		for (int i = 1; i < 6; ++i)
			sw->WriteLine(data[i]);
		sw->WriteLine("false");
		sw->Close();

		for (int y = 0; y < but_in_height; ++y)
			for (int x = 0; x < but_in_weight; ++x)
				Controls->Remove(allbuts[x, y]);
		delete_all();
		Controls->Remove(time);
		Controls->Remove(flags);
		Controls->Remove(restart_but);
		Controls->Remove(back_but);
	}

}

System::Void Project3::Continue_Game::but_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e)
{
	if (e->KeyCode == Keys::Escape)
	{
		cons_dev->ShowDialog();
	}
}

void Project3::Continue_Game::delete_all()
{
	pause_but->Text = "| |";
	pause = false;
	timer->Enabled = false;
	first_click = true;
	count_flags = bombs;
	seconds = 0;
	count_empties = but_in_weight * but_in_height - bombs;
	iswin = false;
	islose = false;
	time->Text = "000";
}

void Project3::Continue_Game::form_Closed(System::Object^ sender, System::EventArgs^ e)
{
	StreamReader^ din = File::OpenText("Colors.txt");

	for (int i = 0; i < 3; ++i)
		colors[i] = din->ReadLine();
	din->Close();

	time->BackColor = System::Drawing::Color::FromName(colors[1]);
	flags->BackColor = System::Drawing::Color::FromName(colors[1]);
	push_color = colors[2];
	unpush_color = colors[0];

	for (int y = 0; y < but_in_height; ++y)
		for (int x = 0; x < but_in_weight; ++x)
		{
			if (allbuts[x, y]->Enabled)
				allbuts[x, y]->BackColor = System::Drawing::Color::FromName(unpush_color);
			else
				allbuts[x, y]->BackColor = System::Drawing::Color::FromName(push_color);
		}
}
