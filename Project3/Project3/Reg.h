#pragma once

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::IO;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Reg
	/// </summary>
	public ref class Reg : public System::Windows::Forms::Form
	{
	public:
		Reg(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Reg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ pass_box;
	protected:

	private: System::Windows::Forms::Button^ reg_but;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ log_box;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ back_but;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Reg::typeid));
			this->pass_box = (gcnew System::Windows::Forms::TextBox());
			this->reg_but = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->log_box = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->back_but = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// pass_box
			// 
			this->pass_box->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pass_box->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->pass_box->Location = System::Drawing::Point(112, 323);
			this->pass_box->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pass_box->Name = L"pass_box";
			this->pass_box->Size = System::Drawing::Size(373, 49);
			this->pass_box->TabIndex = 13;
			this->pass_box->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Reg::pass_box_PreviewKeyDown);
			// 
			// reg_but
			// 
			this->reg_but->BackColor = System::Drawing::Color::Silver;
			this->reg_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->reg_but->Location = System::Drawing::Point(150, 415);
			this->reg_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->reg_but->Name = L"reg_but";
			this->reg_but->Size = System::Drawing::Size(300, 46);
			this->reg_but->TabIndex = 12;
			this->reg_but->Text = L"Зарегистрироваться";
			this->reg_but->UseVisualStyleBackColor = false;
			this->reg_but->Click += gcnew System::EventHandler(this, &Reg::reg_but_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(226, 254);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 47);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Пароль";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(237, 92);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 47);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Логин";
			// 
			// log_box
			// 
			this->log_box->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->log_box->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->log_box->Location = System::Drawing::Point(112, 154);
			this->log_box->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->log_box->Name = L"log_box";
			this->log_box->Size = System::Drawing::Size(373, 49);
			this->log_box->TabIndex = 9;
			this->log_box->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Reg::log_box_PreviewKeyDown);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(176, 23);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(238, 47);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Регистрация";
			// 
			// back_but
			// 
			this->back_but->BackColor = System::Drawing::Color::Silver;
			this->back_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->back_but->Location = System::Drawing::Point(18, 568);
			this->back_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->back_but->Name = L"back_but";
			this->back_but->Size = System::Drawing::Size(150, 46);
			this->back_but->TabIndex = 15;
			this->back_but->Text = L"<<Назад";
			this->back_but->UseVisualStyleBackColor = false;
			this->back_but->Click += gcnew System::EventHandler(this, &Reg::back_but_Click);
			// 
			// Reg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(576, 632);
			this->Controls->Add(this->back_but);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pass_box);
			this->Controls->Add(this->reg_but);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->log_box);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->Name = L"Reg";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Reg";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void back_but_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void reg_but_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void log_box_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e);
	private: System::Void pass_box_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e);
	void enter();
};
}
