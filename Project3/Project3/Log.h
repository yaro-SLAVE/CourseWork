#pragma once
#include "Reg.h"
#include "Main.h"

		

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::IO;
	using namespace System::Drawing;


	public ref class Log : public System::Windows::Forms::Form
	{
	public:
		String^ Login = "";
	private: System::Windows::Forms::Button^ reg_but;
	public:
	private: System::Windows::Forms::Button^ guest_but;
	public:
		Log(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Log()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Reg^ reg;
	private: Main^ main;
	private: System::Windows::Forms::TextBox^ log_box;

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ enter_but;


	private: System::Windows::Forms::Label^ label3;




	private: System::Windows::Forms::TextBox^ pass_box;
	private: System::Windows::Forms::Button^ exit_but;
	private: System::ComponentModel::IContainer^ components;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Log::typeid));
			this->log_box = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->enter_but = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pass_box = (gcnew System::Windows::Forms::TextBox());
			this->exit_but = (gcnew System::Windows::Forms::Button());
			this->reg_but = (gcnew System::Windows::Forms::Button());
			this->guest_but = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// log_box
			// 
			this->log_box->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->log_box->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->log_box->Location = System::Drawing::Point(150, 115);
			this->log_box->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->log_box->Name = L"log_box";
			this->log_box->Size = System::Drawing::Size(373, 49);
			this->log_box->TabIndex = 0;
			this->log_box->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Log::log_box_PreviewKeyDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(274, 46);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 47);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Логин";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(264, 185);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 47);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Пароль";
			// 
			// enter_but
			// 
			this->enter_but->BackColor = System::Drawing::Color::Silver;
			this->enter_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->enter_but->Location = System::Drawing::Point(262, 323);
			this->enter_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->enter_but->Name = L"enter_but";
			this->enter_but->Size = System::Drawing::Size(150, 46);
			this->enter_but->TabIndex = 4;
			this->enter_but->Text = L"Вход";
			this->enter_but->UseVisualStyleBackColor = false;
			this->enter_but->Click += gcnew System::EventHandler(this, &Log::enter_but_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(68, 415);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(246, 27);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Не Зарегистрированы\?";
			// 
			// pass_box
			// 
			this->pass_box->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pass_box->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->pass_box->Location = System::Drawing::Point(150, 254);
			this->pass_box->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pass_box->Name = L"pass_box";
			this->pass_box->PasswordChar = '*';
			this->pass_box->Size = System::Drawing::Size(373, 49);
			this->pass_box->TabIndex = 8;
			this->pass_box->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Log::pass_box_PreviewKeyDown);
			// 
			// exit_but
			// 
			this->exit_but->BackColor = System::Drawing::Color::Silver;
			this->exit_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->exit_but->Location = System::Drawing::Point(18, 645);
			this->exit_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->exit_but->Name = L"exit_but";
			this->exit_but->Size = System::Drawing::Size(150, 46);
			this->exit_but->TabIndex = 9;
			this->exit_but->Text = L"<<Выход";
			this->exit_but->UseVisualStyleBackColor = false;
			this->exit_but->Click += gcnew System::EventHandler(this, &Log::exit_but_Click);
			// 
			// reg_but
			// 
			this->reg_but->BackColor = System::Drawing::Color::Silver;
			this->reg_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->reg_but->Location = System::Drawing::Point(322, 405);
			this->reg_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->reg_but->Name = L"reg_but";
			this->reg_but->Size = System::Drawing::Size(288, 46);
			this->reg_but->TabIndex = 10;
			this->reg_but->Text = L"Зарегистрируйтесь!";
			this->reg_but->UseVisualStyleBackColor = false;
			this->reg_but->Click += gcnew System::EventHandler(this, &Log::reg_but_Click);
			// 
			// guest_but
			// 
			this->guest_but->BackColor = System::Drawing::Color::Silver;
			this->guest_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->guest_but->Location = System::Drawing::Point(184, 499);
			this->guest_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->guest_but->Name = L"guest_but";
			this->guest_but->Size = System::Drawing::Size(288, 46);
			this->guest_but->TabIndex = 11;
			this->guest_but->Text = L"Продолжить как гость";
			this->guest_but->UseVisualStyleBackColor = false;
			this->guest_but->Click += gcnew System::EventHandler(this, &Log::guest_but_Click);
			// 
			// Log
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(651, 709);
			this->Controls->Add(this->guest_but);
			this->Controls->Add(this->reg_but);
			this->Controls->Add(this->exit_but);
			this->Controls->Add(this->pass_box);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->enter_but);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->log_box);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->Name = L"Log";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Сапер";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Log::Log_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void reg_but_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void guest_but_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void enter_but_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void exit_but_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void log_box_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e);
	private: System::Void pass_box_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e);
	private: System::Void Log_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
		   void forms_Closed(System::Object^ sender, System::EventArgs^ e);
		   void enter();
};
}
