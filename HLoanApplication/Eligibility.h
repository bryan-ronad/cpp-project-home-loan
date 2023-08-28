#pragma once
#include <iostream>
#include <map>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include "CalcServiceImpl.h"
using namespace std;

namespace HLoanApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Eligibility
	/// </summary>
	public ref class Eligibility : public System::Windows::Forms::Form
	{
	public:
		Eligibility(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Eligibility(String^ PAN)
		{
			InitializeComponent();
			label5->Text = PAN;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Eligibility()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label16;

	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label15;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label19;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label16);
			this->panel1->Controls->Add(this->label18);
			this->panel1->Controls->Add(this->label15);
			this->panel1->Controls->Add(this->label14);
			this->panel1->Controls->Add(this->label13);
			this->panel1->Location = System::Drawing::Point(40, 407);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(549, 268);
			this->panel1->TabIndex = 38;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(331, 167);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(21, 20);
			this->label11->TabIndex = 50;
			this->label11->Text = L":";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(371, 167);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 23);
			this->label8->TabIndex = 49;
			this->label8->Click += gcnew System::EventHandler(this, &Eligibility::label8_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Lucida Console", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(136, 200);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(61, 30);
			this->label9->TabIndex = 48;
			this->label9->Text = L"(₹)";
			this->label9->Click += gcnew System::EventHandler(this, &Eligibility::label9_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(21, 167);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(304, 23);
			this->label10->TabIndex = 47;
			this->label10->Text = L"Eligibile Loan Amount";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(371, 114);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 23);
			this->label7->TabIndex = 46;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(331, 114);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(21, 20);
			this->label16->TabIndex = 24;
			this->label16->Text = L":";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(35, 112);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(290, 23);
			this->label18->TabIndex = 22;
			this->label18->Text = L"Approval Probability";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(331, 54);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(21, 20);
			this->label15->TabIndex = 21;
			this->label15->Text = L":";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(371, 52);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(0, 23);
			this->label14->TabIndex = 20;
			this->label14->Click += gcnew System::EventHandler(this, &Eligibility::label14_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(94, 51);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(164, 23);
			this->label13->TabIndex = 8;
			this->label13->Text = L"Cibil Score";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(275, 170);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 20);
			this->label1->TabIndex = 41;
			this->label1->Text = L"-";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(492, 168);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 30);
			this->label2->TabIndex = 40;
			this->label2->Text = L"₹";
			this->label2->Click += gcnew System::EventHandler(this, &Eligibility::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(59, 167);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(192, 23);
			this->label3->TabIndex = 39;
			this->label3->Text = L"Annual Salary";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(275, 104);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(21, 20);
			this->label4->TabIndex = 44;
			this->label4->Text = L"-";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(120, 102);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(122, 23);
			this->label6->TabIndex = 42;
			this->label6->Text = L"Pan Card";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(329, 101);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 23);
			this->label5->TabIndex = 43;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(333, 168);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(153, 30);
			this->textBox1->TabIndex = 45;
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(224, 315);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 48);
			this->button1->TabIndex = 46;
			this->button1->Text = L"Check";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Eligibility::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(333, 221);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(153, 30);
			this->textBox2->TabIndex = 50;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(275, 223);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(21, 20);
			this->label12->TabIndex = 49;
			this->label12->Text = L"-";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Lucida Console", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(492, 221);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(25, 30);
			this->label17->TabIndex = 48;
			this->label17->Text = L"₹";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(59, 220);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(178, 23);
			this->label19->TabIndex = 47;
			this->label19->Text = L"Propery Cost";
			// 
			// Eligibility
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 727);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Name = L"Eligibility";
			this->Text = L"Eligibility";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ salary_Str = textBox1->Text;
	String^ property_cost_Str = textBox2->Text;

	std::string salary_str = msclr::interop::marshal_as<std::string>(salary_Str);

	long int salary = stol(salary_str);

	std::string property_str = msclr::interop::marshal_as<std::string>(property_cost_Str);
	long int propert_cost = stol(property_str);

	map<string, string> response = CalcServiceImpl::getEligibilityCheck(salary, propert_cost);
	String^ cibil_Str = msclr::interop::marshal_as<String^>(response["Cibil"]);
	String^ approval_Str = msclr::interop::marshal_as<String^>(response["ApprovalProbab"]);

	String^ eligibility_Str = msclr::interop::marshal_as<String^>(response["EligiblityAmt"]);

	
	label14->Text = cibil_Str;
	label7->Text = approval_Str;
	label8->Text = eligibility_Str;


}
private: System::Void label14_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
