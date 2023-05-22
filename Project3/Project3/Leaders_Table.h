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
	/// Сводка для Leaders_Table
	/// </summary>
	public ref class Leaders_Table : public System::Windows::Forms::Form
	{
	private:
		String^ login = "";
		array<DataGridViewRow^>^ rows = gcnew array <DataGridViewRow^>(200);

	public:
		Leaders_Table(String^ a)
		{
			InitializeComponent();
			
			this->login = a;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Leaders_Table()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ Leaders;
	protected:

	protected:




	private: System::Windows::Forms::Button^ back_but;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Login;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Points;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Num_of_wins;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Num_of_losses;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Leaders_Table::typeid));
			this->Leaders = (gcnew System::Windows::Forms::DataGridView());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Login = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Points = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Num_of_wins = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Num_of_losses = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->back_but = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Leaders))->BeginInit();
			this->SuspendLayout();
			// 
			// Leaders
			// 
			this->Leaders->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->Leaders->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Leaders->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Number, this->Login,
					this->Points, this->Num_of_wins, this->Num_of_losses
			});
			this->Leaders->Location = System::Drawing::Point(13, 111);
			this->Leaders->Name = L"Leaders";
			this->Leaders->ReadOnly = true;
			this->Leaders->RowHeadersWidth = 62;
			this->Leaders->RowTemplate->Height = 28;
			this->Leaders->Size = System::Drawing::Size(916, 388);
			this->Leaders->TabIndex = 0;
			// 
			// Number
			// 
			this->Number->FillWeight = 40;
			this->Number->HeaderText = L"Место";
			this->Number->MinimumWidth = 8;
			this->Number->Name = L"Number";
			this->Number->ReadOnly = true;
			// 
			// Login
			// 
			this->Login->FillWeight = 130;
			this->Login->HeaderText = L"Имя";
			this->Login->MinimumWidth = 8;
			this->Login->Name = L"Login";
			this->Login->ReadOnly = true;
			// 
			// Points
			// 
			this->Points->FillWeight = 120;
			this->Points->HeaderText = L"Очки";
			this->Points->MinimumWidth = 8;
			this->Points->Name = L"Points";
			this->Points->ReadOnly = true;
			// 
			// Num_of_wins
			// 
			this->Num_of_wins->FillWeight = 50;
			this->Num_of_wins->HeaderText = L"Побед";
			this->Num_of_wins->MinimumWidth = 8;
			this->Num_of_wins->Name = L"Num_of_wins";
			this->Num_of_wins->ReadOnly = true;
			// 
			// Num_of_losses
			// 
			this->Num_of_losses->FillWeight = 50;
			this->Num_of_losses->HeaderText = L"Поражений";
			this->Num_of_losses->MinimumWidth = 8;
			this->Num_of_losses->Name = L"Num_of_losses";
			this->Num_of_losses->ReadOnly = true;
			// 
			// back_but
			// 
			this->back_but->BackColor = System::Drawing::Color::Silver;
			this->back_but->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->back_but->Location = System::Drawing::Point(13, 44);
			this->back_but->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->back_but->Name = L"back_but";
			this->back_but->Size = System::Drawing::Size(150, 46);
			this->back_but->TabIndex = 17;
			this->back_but->Text = L"<<Назад";
			this->back_but->UseVisualStyleBackColor = false;
			this->back_but->Click += gcnew System::EventHandler(this, &Leaders_Table::back_but_Click);
			// 
			// Leaders_Table
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1035, 526);
			this->Controls->Add(this->back_but);
			this->Controls->Add(this->Leaders);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Leaders_Table";
			this->Text = L"Сапер";
			this->Load += gcnew System::EventHandler(this, &Leaders_Table::Leaders_Table_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Leaders))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Leaders_Table_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void back_but_Click(System::Object^ sender, System::EventArgs^ e);
};
}
