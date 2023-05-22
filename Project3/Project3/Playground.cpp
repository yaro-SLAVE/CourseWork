#include "Playground.h"

//Выполняется при загрузке формы. Открывает файл пользователя, по его настройкам строит игру. 
//Инициализирует главные элементы управления на форме и вызывает функцию create_field()
System::Void Project3::Playground::Playground_Load(System::Object^ sender, System::EventArgs^ e)
{
	StreamReader^ din = File::OpenText("Players\\" + Login + ".txt");

	for (int i = 0; i < 6; ++i)
		data[i] = din->ReadLine();
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

	if (bool::Parse(data[1]))
	{
		but_in_height = 8;
		but_in_weight = 8;
		bombs = 10;
		level = 1;
		level_coefficient = 1;
		max_time = 50;
		min_points = 5;
	}

	else if (bool::Parse(data[2]))
	{
		but_in_height = 16;
		but_in_weight = 16;
		bombs = 40;
		level = 2;
		level_coefficient = 4;
		max_time = 125;
		min_points = 15;
	}

	else if (bool::Parse(data[3]))
	{
		but_in_height = 16;
		but_in_weight = 32;
		bombs = 99;
		level = 3;
		level_coefficient = 8;
		max_time = 400;
		min_points = 30;
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

	count_flags = bombs;
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

	create_field();
}

//Создаёт поле пустых ячеек
void Project3::Playground::create_field()
{
	for (int y = 0; y < but_in_height; ++y)
		for (int x = 0; x < but_in_weight; ++x)
		{
			but_extend^ but = gcnew but_extend();
			but->BackColor = System::Drawing::Color::FromName(unpush_color);
			but->Location = System::Drawing::Point(x * but_size + start_x, y * but_size + start_y);
			but->Size = System::Drawing::Size(but_size, but_size);
			but->FlatAppearance->BorderColor = System::Drawing::Color::Gray;
			but->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			but->isforbidden = false;
			out_flags();
			but->MouseUp += gcnew MouseEventHandler(this, &Playground::field_click);
			but->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Playground::but_PreviewKeyDown);
			allbuts[x, y] = but;
			Controls->Add(but);
		}
}

//Выводит на Label flags количество флажков, которое может поставить пользователь
void Project3::Playground::out_flags()
{
	if (count_flags > 9)
		flags->Text = Convert::ToString(count_flags);
	else if (count_flags < 10)
		flags->Text = "0" + Convert::ToString(count_flags);
}

//Выполняется при нажатии кнопкой мыши на ячейку на поле. При первом нажатии вызывает функцию generate_bombs,
//чтобы на поле появились бомбы. При нажатии на левую кнопку мыши открывает ячейку, при нажатии на правую
//ставит флажок
void Project3::Playground::field_click(System::Object^ sender, MouseEventArgs^ e)
{
	but_extend^ but = (but_extend^)sender;

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

//Раскидывает случайным образом на поле бомбы в зависимости от того места, куда нажал пользователь
void Project3::Playground::generate_bombs(int xb, int yb)
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

//Вызывается, если пользователь нажал на ячейку без бомбы. Или показывает количество бомб в соседних ячейках,
//или открывает соседние ячейки, если в соседних нет бомб
void Project3::Playground::empty_click(but_extend^ but)
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

	but->BackColor = Color::FromName(push_color);
	but->Enabled = false;
}

//Подсчитывает количество бомб в соседних ячейках
int Project3::Playground::count_bombs_around(int xb, int yb)
{
	int count_bombs = 0;
	for (int y = yb - 1; y <= yb + 1; ++y)
		for (int x = xb - 1; x <= xb + 1; ++x)
			if (x >= 0 && x < but_in_weight && y >= 0 && y < but_in_height)
				if (allbuts[x, y]->isbomb)
					++count_bombs;
	return count_bombs;
}

//Вызывается, если в соседних ячейках от нажатой пустой нет бомб. Открывает все соседние от нажатой
void Project3::Playground::empty_but(int xb, int yb)
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

//Вызывается при нажатии на кнопку паузы и активирует режим паузы. Остановливает таймер и не даёт
//пользователю нажимать на ячейки на поле
System::Void Project3::Playground::pause_but_Click(System::Object^ sender, System::EventArgs^ e)
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

//Вызывается при нажатии на кнопку перезагрузки игры. Удаляет все ячейки с поля и создаёт новые.
//Также очищает таймер и счётчик флажков
void Project3::Playground::restart_click(System::Object^ sender, MouseEventArgs^ e)
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

//Выполняется, если игрок победил (открыл все ячейки без бомб).
//Останавливает таймер, прибавляет очки и увеличивает количество побед пользователю
void Project3::Playground::winner()
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

//Выполняется, если играл нажал на ячейку с бомбой. Останавливает таймер и увеличивает количество поражений
//пользователю
void Project3::Playground::boom(but_extend^ but)
{
	lose->Play();
	if (Login != "Guest")
		++num_of_losses;

	timer->Enabled = false;
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

//Выполняется каждый раз после активации таймера и его прохождения определённого интервала.
//Изменяет прошедшее время на Label time
System::Void Project3::Playground::timer_Tick(System::Object^ sender, System::EventArgs^ e)
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

//Выполняется после нажатия на кнопку выхода из игры. Выводит на экран предупреждающие сообщения и 
// в зависимости от ответа пользователя закрывает или незакрывает форму
System::Void Project3::Playground::back_but_Click(System::Object^ sender, System::EventArgs^ e)
{
	timer->Enabled = false;
	if (save)
	{
		if (MessageBox::Show("Вы действительно хотите Выйти?", "Выход",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			this->Close();
		else
		{
			timer->Enabled = true;
			timer->Interval = 1000;
		}
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
		{
			timer->Enabled = true;
			timer->Interval = 1000;
		}
	}
}

//Выполняется при закрытии формы. Записывает в файл пользователя количество очков, побед и поражений, а также
//если игра не законченна, то и данные о незаконченной игре
System::Void Project3::Playground::Playground_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	if (save)
	{
		timer->Enabled = false;
		if (first_click || islose || iswin)
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

		else if (!first_click)
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

//Выполняется при нажатии клавиши Escape. Открывает консоль разработчика
System::Void Project3::Playground::but_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e)
{
	if (e->KeyCode == Keys::Escape)
	{
		cons_dev->ShowDialog();
	}
}

//Ставит все настройки по умолчанию при выходе из игры или перезапуске игры
void Project3::Playground::delete_all()
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

//Выполняется при закрытии консоли разработчика
void Project3::Playground::form_Closed(System::Object^ sender, System::EventArgs^ e)
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
