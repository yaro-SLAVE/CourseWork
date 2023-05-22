#pragma once
#include "Cons_Devel.h"

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Media;

	/// <summary>
	/// —водка дл€ Playground
	/// </summary>
	
	public ref class but_extend : public System::Windows::Forms::Button
	{
	public:
		bool isbomb;
		bool isflaged;
		bool isempty;
		bool isforbidden;
	};

	public ref class Playground : public System::Windows::Forms::Form
	{
	private:
		String^ Login = "";
		array<String^>^ data = gcnew array<String^>(6);
		array<String^>^ colors = gcnew array<String^>(3);
		int seconds = 0;
		String^ razr;
		int resbut_size = 40;
		int field_padding = 15;
		int start_x = field_padding;
		int start_y = field_padding * 2 + resbut_size;
		int but_in_height = 8;
		int but_in_weight = 8;
		int but_size = 28;
		int bombs = 10;
		int count_flags = bombs;
		int count_empties = but_in_weight * but_in_height - bombs;
		bool first_click = true;
		bool iswin = false;
		bool islose = false;
		bool save = true;
		bool sound = true;
		int level = 1;
		int level_coefficient = 1;
		int max_time = 50;
		int min_points = 10;
		int points = 0;
		int num_of_wins = 0;
		int num_of_losses = 0;
		bool pause = false;
		String^ push_color = "Gainsboro";
		String^ unpush_color = "DarkGray";
		array< but_extend^, 2>^ allbuts = gcnew array< but_extend^, 2 >(32, 16);
		ImageList^ ImageList1 = gcnew ImageList();
		ImageList^ ImageList2 = gcnew ImageList();

	public:
		Playground(String^ a)
		{
			InitializeComponent();

			cons_dev = gcnew Cons_Devel();
			cons_dev->Owner = this;
			this->cons_dev->Closed += gcnew EventHandler(this, &Playground::form_Closed);
			cons_dev->Hide();

			this->Login = a;
		}
	private: Cons_Devel^ cons_dev;
	private: Label^ time;
	private: Label^ flags;
	private: Timer^ timer;
	private: but_extend^ restart_but;
	private: Button^ back_but;
	private: Button^ pause_but;
	private: SoundPlayer^ click;
	private: SoundPlayer^ tick;
	private: SoundPlayer^ lose;
	private: SoundPlayer^ win;
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Playground()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Playground::typeid));

			this->ImageList1->ImageSize = System::Drawing::Size(but_size - 2, but_size - 2);
			this->ImageList1->Images->Add(Image::FromFile("Images\\boom.png"));//0
			this->ImageList1->Images->Add(Image::FromFile("Images\\1.png"));//1
			this->ImageList1->Images->Add(Image::FromFile("Images\\2.png"));//2
			this->ImageList1->Images->Add(Image::FromFile("Images\\3.png"));//3
			this->ImageList1->Images->Add(Image::FromFile("Images\\4.png"));//4
			this->ImageList1->Images->Add(Image::FromFile("Images\\5.png"));//5
			this->ImageList1->Images->Add(Image::FromFile("Images\\6.png"));//6
			this->ImageList1->Images->Add(Image::FromFile("Images\\7.png"));//7
			this->ImageList1->Images->Add(Image::FromFile("Images\\8.png"));//8
			this->ImageList1->Images->Add(Image::FromFile("Images\\flag.png"));//9
			this->ImageList1->Images->Add(Image::FromFile("Images\\bomb.png"));//10
			this->ImageList1->Images->Add(Image::FromFile("Images\\not_flag.png"));//11

			this->ImageList2->ImageSize = System::Drawing::Size(resbut_size - 5, resbut_size - 5);
			this->ImageList2->Images->Add(Image::FromFile("Images\\smile.png"));//0
			this->ImageList2->Images->Add(Image::FromFile("Images\\win.png"));//1
			this->ImageList2->Images->Add(Image::FromFile("Images\\lose.png"));//2

			this->timer = gcnew(Timer);
			this->timer->Tick += gcnew System::EventHandler(this, &Playground::timer_Tick);

			this->restart_but = gcnew but_extend();
			this->restart_but->BackColor = System::Drawing::Color::DarkGray;
			this->restart_but->Location = System::Drawing::Point(but_in_weight * but_size / 2 + field_padding - resbut_size / 2, field_padding);
			this->restart_but->Size = System::Drawing::Size(resbut_size, resbut_size);
			this->restart_but->BackgroundImage = ImageList2->Images[0];
			this->restart_but->BackgroundImageLayout = ImageLayout::Center;
			this->Controls->Add(restart_but);
			this->restart_but->MouseUp += gcnew MouseEventHandler(this, &Playground::restart_click);
			this->restart_but->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Playground::but_PreviewKeyDown);

			this->time = gcnew(Label);
			this->time->Location = System::Drawing::Point(but_in_weight * but_size / 2 + field_padding + resbut_size / 2 + field_padding, field_padding);
			this->time->Size = System::Drawing::Size(60, resbut_size);
			this->time->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->time->BackColor = System::Drawing::Color::Transparent;
			this->time->Text = L"000";
			this->Controls->Add(time);

			this->flags = gcnew(Label);
			this->flags->Location = System::Drawing::Point(but_in_weight * but_size / 2 - resbut_size - field_padding, field_padding);
			this->flags->Size = System::Drawing::Size(40, resbut_size);
			this->flags->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->flags->BackColor = System::Drawing::Color::Transparent;
			this->Controls->Add(flags);

			this->back_but = gcnew(Button);
			this->back_but->BackColor = System::Drawing::Color::DarkGray;
			this->back_but->Location = System::Drawing::Point(field_padding, field_padding);
			this->back_but->Size = System::Drawing::Size(resbut_size / 1.5, resbut_size);
			this->back_but->Text = "<";
			this->Controls->Add(back_but);
			this->back_but->Click += gcnew System::EventHandler(this, &Playground::back_but_Click);
			this->back_but->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Playground::but_PreviewKeyDown);

			this->pause_but = gcnew(Button);
			this->pause_but->BackColor = System::Drawing::Color::DarkGray;
			this->pause_but->Location = System::Drawing::Point(but_in_weight * but_size / 2 + field_padding + resbut_size / 2 + field_padding + 60, field_padding);
			this->pause_but->Size = System::Drawing::Size(resbut_size / 1.25, resbut_size);
			this->pause_but->Text = "| |";
			this->Controls->Add(pause_but);
			this->pause_but->Click += gcnew System::EventHandler(this, &Playground::pause_but_Click);
			this->pause_but->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Playground::but_PreviewKeyDown);

			this->ClientSize = System::Drawing::Size(but_in_weight * but_size + field_padding * 2, but_in_height * but_size + field_padding * 3 + resbut_size);

			this->SuspendLayout();
			// 
			// Playground
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(but_in_weight * but_size + field_padding * 2, but_in_height * but_size + field_padding * 3 + resbut_size);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Playground";
			this->Text = L"—апер";
			this->AutoSize = true;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &Playground::Playground_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Playground::Playground_FormClosing);
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void Playground_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pause_but_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e);   
	private: System::Void back_but_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Playground_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void but_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e);
		   void create_field();
		   void out_flags();
		   void field_click(System::Object^ sender, MouseEventArgs^ e);
		   void generate_bombs(int xb, int yb);
		   void empty_click(but_extend^ but);
		   int count_bombs_around(int xb, int yb);
		   void empty_but(int xb, int yb);
		   void restart_click(System::Object^ sender, MouseEventArgs^ e);
		   void winner();
		   void boom(but_extend^ but);
		   void delete_all();
		   void form_Closed(System::Object^ sender, System::EventArgs^ e);
	};
}
