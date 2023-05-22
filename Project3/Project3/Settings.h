#pragma once


namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для Settings
	/// </summary>

	public ref class Settings : public System::Windows::Forms::Form
	{
	private:
		String^ Login;
		array<String^>^ data = gcnew array<String^>(32 * 16 + 20);


	public:
		Settings(String^ a)
		{
			InitializeComponent();

			this->Login = a;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RadioButton^ jun_flag;
	private: System::Windows::Forms::RadioButton^ mid_flag;
	private: System::Windows::Forms::RadioButton^ prof_flag;




	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ back_but;

	private: System::Windows::Forms::CheckBox^ save_box;
	private: System::Windows::Forms::CheckBox^ sound_box;





	protected:




	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Settings::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->jun_flag = (gcnew System::Windows::Forms::RadioButton());
			this->mid_flag = (gcnew System::Windows::Forms::RadioButton());
			this->prof_flag = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->back_but = (gcnew System::Windows::Forms::Button());
			this->save_box = (gcnew System::Windows::Forms::CheckBox());
			this->sound_box = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(140, 31);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(393, 81);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Настройки";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(15, 182);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(498, 61);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Уровень сложности";
			// 
			// jun_flag
			// 
			this->jun_flag->AutoSize = true;
			this->jun_flag->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->jun_flag->Location = System::Drawing::Point(22, 269);
			this->jun_flag->Margin = System::Windows::Forms::Padding(0);
			this->jun_flag->Name = L"jun_flag";
			this->jun_flag->Size = System::Drawing::Size(445, 40);
			this->jun_flag->TabIndex = 3;
			this->jun_flag->TabStop = true;
			this->jun_flag->Text = L"Новичок - Поле 8 х 8 - 10 мин";
			this->jun_flag->UseVisualStyleBackColor = true;
			// 
			// mid_flag
			// 
			this->mid_flag->AutoSize = true;
			this->mid_flag->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mid_flag->Location = System::Drawing::Point(22, 311);
			this->mid_flag->Margin = System::Windows::Forms::Padding(0);
			this->mid_flag->Name = L"mid_flag";
			this->mid_flag->Size = System::Drawing::Size(490, 40);
			this->mid_flag->TabIndex = 4;
			this->mid_flag->TabStop = true;
			this->mid_flag->Text = L"Опытный - Поле 16 х 16 - 40 мин";
			this->mid_flag->UseVisualStyleBackColor = true;
			// 
			// prof_flag
			// 
			this->prof_flag->AutoSize = true;
			this->prof_flag->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->prof_flag->Location = System::Drawing::Point(22, 352);
			this->prof_flag->Margin = System::Windows::Forms::Padding(0);
			this->prof_flag->Name = L"prof_flag";
			this->prof_flag->Size = System::Drawing::Size(557, 40);
			this->prof_flag->TabIndex = 5;
			this->prof_flag->TabStop = true;
			this->prof_flag->Text = L"Профессионал - Поле 16 х 32 - 99 мин";
			this->prof_flag->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(15, 423);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(200, 61);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Прочее";
			// 
			// back_but
			// 
			this->back_but->BackColor = System::Drawing::Color::Silver;
			this->back_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->back_but->Location = System::Drawing::Point(13, 634);
			this->back_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->back_but->Name = L"back_but";
			this->back_but->Size = System::Drawing::Size(150, 46);
			this->back_but->TabIndex = 16;
			this->back_but->Text = L"<<Назад";
			this->back_but->UseVisualStyleBackColor = false;
			this->back_but->Click += gcnew System::EventHandler(this, &Settings::back_Click);
			// 
			// save_box
			// 
			this->save_box->AutoSize = true;
			this->save_box->Checked = true;
			this->save_box->CheckState = System::Windows::Forms::CheckState::Checked;
			this->save_box->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->save_box->Location = System::Drawing::Point(22, 508);
			this->save_box->Margin = System::Windows::Forms::Padding(0);
			this->save_box->Name = L"save_box";
			this->save_box->Size = System::Drawing::Size(505, 40);
			this->save_box->TabIndex = 17;
			this->save_box->Text = L"Всегда сохранять игру при выходе";
			this->save_box->UseVisualStyleBackColor = true;
			// 
			// sound_box
			// 
			this->sound_box->AutoSize = true;
			this->sound_box->Checked = true;
			this->sound_box->CheckState = System::Windows::Forms::CheckState::Checked;
			this->sound_box->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sound_box->Location = System::Drawing::Point(22, 549);
			this->sound_box->Margin = System::Windows::Forms::Padding(0);
			this->sound_box->Name = L"sound_box";
			this->sound_box->Size = System::Drawing::Size(378, 40);
			this->sound_box->TabIndex = 18;
			this->sound_box->Text = L"Звуковое сопровождение";
			this->sound_box->UseVisualStyleBackColor = true;
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(651, 699);
			this->Controls->Add(this->sound_box);
			this->Controls->Add(this->save_box);
			this->Controls->Add(this->back_but);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->prof_flag);
			this->Controls->Add(this->mid_flag);
			this->Controls->Add(this->jun_flag);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Settings";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Сапер";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Settings::Settings_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Settings::Settings_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Settings_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Settings_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e);
	void data_write();
};
}
