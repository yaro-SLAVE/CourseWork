#include "Cons_Devel.h"

System::Void Project3::Cons_Devel::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    StreamWriter^ sw = gcnew StreamWriter("Colors.txt");

    sw->WriteLine(comboBox1->Text);
    sw->WriteLine(comboBox2->Text);
    sw->WriteLine(comboBox3->Text);
    sw->Close();
    this->Close();
}

System::Void Project3::Cons_Devel::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    StreamWriter^ sw = gcnew StreamWriter("Colors.txt");

    sw->WriteLine("DarkGray");
    sw->WriteLine("Transporter");
    sw->WriteLine("Gainsboro");
    sw->Close();
    this->Close();
}
