#pragma once
#include "Settings.h"
#include "Playground.h"
#include "Continue_Game.h"
#include "Leaders_Table.h"

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Сводка для Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		String^ Login = "";
		array<String^>^ data = gcnew array<String^>(7);

	public:
		Main(String^ a)
		{
			InitializeComponent();

			this->Login = a;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Settings^ sett;
	private: Playground^ pl_gr;
	private: Continue_Game^ cont_game;
	private: Leaders_Table^ lead;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ newGame_but;
	private: System::Windows::Forms::Button^ sett_but;
	private: System::Windows::Forms::Button^ lead_but;
	private: System::Windows::Forms::Button^ rules_but;
	private: System::Windows::Forms::Button^ about_but;
	private: System::Windows::Forms::Button^ exit_but;
	private: System::Windows::Forms::Button^ continue_but;

	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->newGame_but = (gcnew System::Windows::Forms::Button());
			this->sett_but = (gcnew System::Windows::Forms::Button());
			this->lead_but = (gcnew System::Windows::Forms::Button());
			this->rules_but = (gcnew System::Windows::Forms::Button());
			this->about_but = (gcnew System::Windows::Forms::Button());
			this->exit_but = (gcnew System::Windows::Forms::Button());
			this->continue_but = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(260, 31);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(230, 81);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Меню";
			// 
			// newGame_but
			// 
			this->newGame_but->BackColor = System::Drawing::Color::Gainsboro;
			this->newGame_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->newGame_but->Location = System::Drawing::Point(225, 247);
			this->newGame_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->newGame_but->Name = L"newGame_but";
			this->newGame_but->Size = System::Drawing::Size(300, 77);
			this->newGame_but->TabIndex = 1;
			this->newGame_but->Text = L"Новая Игра";
			this->newGame_but->UseVisualStyleBackColor = false;
			this->newGame_but->Click += gcnew System::EventHandler(this, &Main::newGame_but_Click);
			// 
			// sett_but
			// 
			this->sett_but->BackColor = System::Drawing::Color::Gainsboro;
			this->sett_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sett_but->Location = System::Drawing::Point(225, 334);
			this->sett_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->sett_but->Name = L"sett_but";
			this->sett_but->Size = System::Drawing::Size(300, 77);
			this->sett_but->TabIndex = 2;
			this->sett_but->Text = L"Настройки";
			this->sett_but->UseVisualStyleBackColor = false;
			this->sett_but->Click += gcnew System::EventHandler(this, &Main::sett_but_Click);
			// 
			// lead_but
			// 
			this->lead_but->BackColor = System::Drawing::Color::Gainsboro;
			this->lead_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lead_but->Location = System::Drawing::Point(225, 421);
			this->lead_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->lead_but->Name = L"lead_but";
			this->lead_but->Size = System::Drawing::Size(300, 77);
			this->lead_but->TabIndex = 3;
			this->lead_but->Text = L"Рейтинг";
			this->lead_but->UseVisualStyleBackColor = false;
			this->lead_but->Click += gcnew System::EventHandler(this, &Main::lead_but_Click);
			// 
			// rules_but
			// 
			this->rules_but->BackColor = System::Drawing::Color::Gainsboro;
			this->rules_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->rules_but->Location = System::Drawing::Point(225, 508);
			this->rules_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->rules_but->Name = L"rules_but";
			this->rules_but->Size = System::Drawing::Size(300, 77);
			this->rules_but->TabIndex = 4;
			this->rules_but->Text = L"Правила";
			this->rules_but->UseVisualStyleBackColor = false;
			this->rules_but->Click += gcnew System::EventHandler(this, &Main::rules_but_Click);
			// 
			// about_but
			// 
			this->about_but->BackColor = System::Drawing::Color::Gainsboro;
			this->about_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->about_but->Location = System::Drawing::Point(225, 595);
			this->about_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->about_but->Name = L"about_but";
			this->about_but->Size = System::Drawing::Size(300, 77);
			this->about_but->TabIndex = 5;
			this->about_but->Text = L"О Программе";
			this->about_but->UseVisualStyleBackColor = false;
			this->about_but->Click += gcnew System::EventHandler(this, &Main::about_but_Click);
			// 
			// exit_but
			// 
			this->exit_but->BackColor = System::Drawing::Color::Gainsboro;
			this->exit_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->exit_but->Location = System::Drawing::Point(225, 682);
			this->exit_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->exit_but->Name = L"exit_but";
			this->exit_but->Size = System::Drawing::Size(300, 154);
			this->exit_but->TabIndex = 6;
			this->exit_but->Text = L"Выйти из аккаунта";
			this->exit_but->UseVisualStyleBackColor = false;
			this->exit_but->Click += gcnew System::EventHandler(this, &Main::exit_but_Click);
			// 
			// continue_but
			// 
			this->continue_but->BackColor = System::Drawing::Color::Gainsboro;
			this->continue_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->continue_but->Location = System::Drawing::Point(225, 160);
			this->continue_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->continue_but->Name = L"continue_but";
			this->continue_but->Size = System::Drawing::Size(300, 77);
			this->continue_but->TabIndex = 7;
			this->continue_but->Text = L"Продолжить";
			this->continue_but->UseVisualStyleBackColor = false;
			this->continue_but->Visible = false;
			this->continue_but->Click += gcnew System::EventHandler(this, &Main::continue_but_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(726, 846);
			this->Controls->Add(this->continue_but);
			this->Controls->Add(this->exit_but);
			this->Controls->Add(this->about_but);
			this->Controls->Add(this->rules_but);
			this->Controls->Add(this->lead_but);
			this->Controls->Add(this->sett_but);
			this->Controls->Add(this->newGame_but);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Сапер";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Main::Main_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Main_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void sett_but_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void exit_but_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void newGame_but_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rules_but_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void continue_but_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void lead_but_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void about_but_Click(System::Object^ sender, System::EventArgs^ e);
		   void forms_Closed(System::Object^ sender, System::EventArgs^ e);
};
}
