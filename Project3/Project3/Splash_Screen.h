#pragma once
#include "Log.h"

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Splash_Screen
	/// </summary>
	public ref class Splash_Screen : public System::Windows::Forms::Form
	{
	private:
		int i = -1;
		array <String^>^ comments = gcnew array<String^>(11);

	public:
		Splash_Screen(void)
		{
			InitializeComponent();
			
			comments[0] = "Выбираем поле для игры";
			comments[1] = "Выравниваем местность";
			comments[2] = "Ремонтируем изолентой флажки";
			comments[3] = "Закупаемся лопатами по скидке";
			comments[4] = "Готовим чёрные мешки";
			comments[5] = "Отбираем \"Добровольцев\"";
			comments[6] = "Достаём таблички с цифрами";
			comments[7] = "Снаряжаем добровольцев";
			comments[8] = "Раскидываем мины";
			comments[9] = "Отправляем добровольцев";
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Splash_Screen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Log^ log;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::PictureBox^ picture;
	private: System::Windows::Forms::Label^ label;
	private: System::Windows::Forms::ProgressBar^ pr_bar;
	protected:

	protected:
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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Splash_Screen::typeid));
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->picture = (gcnew System::Windows::Forms::PictureBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->pr_bar = (gcnew System::Windows::Forms::ProgressBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture))->BeginInit();
			this->SuspendLayout();
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &Splash_Screen::timer_Tick);
			// 
			// picture
			// 
			this->picture->Location = System::Drawing::Point(118, 12);
			this->picture->Name = L"picture";
			this->picture->Size = System::Drawing::Size(350, 450);
			this->picture->Image = Image::FromFile("Images\\splash.png");
			this->picture->TabIndex = 0;
			this->picture->TabStop = false;
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label->Location = System::Drawing::Point(50, 480);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(0, 32);
			this->label->TabIndex = 1;
			this->label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pr_bar
			// 
			this->pr_bar->Location = System::Drawing::Point(42, 549);
			this->pr_bar->Name = L"pr_bar";
			this->pr_bar->Size = System::Drawing::Size(490, 40);
			this->pr_bar->TabIndex = 2;
			pr_bar->Minimum = 1;
			pr_bar->Maximum = 10;
			pr_bar->Value = 1;
			pr_bar->Step = 1;
			// 
			// Splash_Screen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(578, 644);
			this->Controls->Add(this->pr_bar);
			this->Controls->Add(this->label);
			this->Controls->Add(this->picture);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Splash_Screen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Сапер";
			this->Load += gcnew System::EventHandler(this, &Splash_Screen::Splash_Screen_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Splash_Screen_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e);
	};
}
