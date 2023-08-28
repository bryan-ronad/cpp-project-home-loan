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
	/// Summary for EMI
	/// </summary>
	public ref class EMI : public System::Windows::Forms::Form
	{
	public:
		EMI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		} 


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EMI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TrackBar^ trackBar3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TrackBar^ trackBar1;

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
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->panel1->Controls->Add(this->label19);
			this->panel1->Controls->Add(this->label20);
			this->panel1->Controls->Add(this->label21);
			this->panel1->Controls->Add(this->label16);
			this->panel1->Controls->Add(this->label17);
			this->panel1->Controls->Add(this->label18);
			this->panel1->Controls->Add(this->label15);
			this->panel1->Controls->Add(this->label14);
			this->panel1->Controls->Add(this->label13);
			this->panel1->Location = System::Drawing::Point(34, 464);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(536, 256);
			this->panel1->TabIndex = 37;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(331, 186);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(21, 20);
			this->label19->TabIndex = 27;
			this->label19->Text = L"-";
			this->label19->Click += gcnew System::EventHandler(this, &EMI::label19_Click);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Lucida Console", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(456, 183);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(25, 30);
			this->label20->TabIndex = 26;
			this->label20->Text = L"₹";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(51, 183);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(192, 23);
			this->label21->TabIndex = 25;
			this->label21->Text = L"Total Payment";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(331, 115);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(21, 20);
			this->label16->TabIndex = 24;
			this->label16->Text = L"-";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Lucida Console", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(456, 112);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(25, 30);
			this->label17->TabIndex = 23;
			this->label17->Text = L"₹";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(35, 112);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(220, 23);
			this->label18->TabIndex = 22;
			this->label18->Text = L"Payable Intrest";
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
			this->label15->Text = L"-";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Lucida Console", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(456, 51);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(25, 30);
			this->label14->TabIndex = 20;
			this->label14->Text = L"₹";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(94, 51);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(122, 23);
			this->label13->TabIndex = 8;
			this->label13->Text = L"Loan EMI";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(564, 384);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(28, 17);
			this->label9->TabIndex = 36;
			this->label9->Text = L"Yr";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(528, 380);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(28, 25);
			this->textBox3->TabIndex = 35;
			this->textBox3->Text = L"10";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(434, 360);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(48, 17);
			this->label10->TabIndex = 34;
			this->label10->Text = L"30Yr";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(31, 360);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(38, 17);
			this->label11->TabIndex = 33;
			this->label11->Text = L"1Yr";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(30, 307);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(94, 23);
			this->label12->TabIndex = 32;
			this->label12->Text = L"Tenure";
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(34, 380);
			this->trackBar3->Maximum = 30;
			this->trackBar3->Minimum = 1;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(435, 56);
			this->trackBar3->TabIndex = 31;
			this->trackBar3->TickFrequency = 3;
			this->trackBar3->Value = 10;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &EMI::trackBar3_Scroll);
			this->trackBar3->ValueChanged += gcnew System::EventHandler(this, &EMI::trackBar3_ValueChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(564, 258);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(18, 17);
			this->label5->TabIndex = 30;
			this->label5->Text = L"%";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(528, 250);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(28, 25);
			this->textBox2->TabIndex = 29;
			this->textBox2->Text = L"5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(434, 234);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(38, 17);
			this->label6->TabIndex = 28;
			this->label6->Text = L"20%";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(31, 234);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(28, 17);
			this->label7->TabIndex = 27;
			this->label7->Text = L"1%";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(30, 181);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(178, 23);
			this->label8->TabIndex = 26;
			this->label8->Text = L"Intrest Rate";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(34, 254);
			this->trackBar2->Maximum = 20;
			this->trackBar2->Minimum = 1;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(435, 56);
			this->trackBar2->TabIndex = 25;
			this->trackBar2->TickFrequency = 2;
			this->trackBar2->Value = 5;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &EMI::trackBar2_Scroll);
			this->trackBar2->ValueChanged += gcnew System::EventHandler(this, &EMI::trackBar2_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(564, 129);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(18, 17);
			this->label4->TabIndex = 24;
			this->label4->Text = L"L";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(509, 125);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(49, 25);
			this->textBox1->TabIndex = 23;
			this->textBox1->Text = L"25";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(434, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 17);
			this->label3->TabIndex = 22;
			this->label3->Text = L"200L";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(31, 105);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(28, 17);
			this->label2->TabIndex = 21;
			this->label2->Text = L"5L";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(30, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(164, 23);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Loan Amount";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(34, 125);
			this->trackBar1->Maximum = 200;
			this->trackBar1->Minimum = 5;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(435, 56);
			this->trackBar1->TabIndex = 19;
			this->trackBar1->TickFrequency = 20;
			this->trackBar1->Value = 25;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &EMI::trackBar1_Scroll);
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &EMI::trackBar1_ValueChanged);
			// 
			// EMI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(603, 768);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Name = L"EMI";
			this->Text = L"EMI";
			this->Load += gcnew System::EventHandler(this, &EMI::EMI_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	public:void EMILOGIC() {
		String^ la = ((trackBar1->Value).ToString());
		String^ ir = ((trackBar2->Value).ToString());
		String^ t = ((trackBar3->Value).ToString());
		std::string loan_amt_str = msclr::interop::marshal_as<std::string>(la);
		std::string intrest_rate_str = msclr::interop::marshal_as<std::string>(ir);
		std::string tenure_str = msclr::interop::marshal_as<std::string>(t);

		long int LoanAmt = stol(loan_amt_str) * 100000;
		long int IntrestRate = stol(intrest_rate_str);
		long int Tenure = stol(tenure_str);


		//
		// 
		// 
		// 
		


		//
		// 
		// 
		// 
		// 
		map<string, string> response = CalcServiceImpl::getEmi(LoanAmt, IntrestRate, Tenure);

		String^ loan_emi = msclr::interop::marshal_as<String^>(response["loan_emi"]);
		String^ payable_intrest = msclr::interop::marshal_as<String^>(response["payable_intrest"]);
		String^ total_payment = msclr::interop::marshal_as<String^>(response["total_payment"]);


		label15->Text = loan_emi;
		label16->Text = payable_intrest;
		label19->Text = total_payment;


	}
		public: event EventHandler^ ValueChanged;
		private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
			ValueChanged(this, EventArgs::Empty);

		}
private: System::Void trackBar1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = (trackBar1->Value).ToString();
	


	EMILOGIC();

}		

private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {
	ValueChanged(this, EventArgs::Empty);

}
private: System::Void trackBar2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox2->Text = (trackBar2->Value).ToString();
	EMILOGIC();
}
private: System::Void trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e) {
	ValueChanged(this, EventArgs::Empty);
}
private: System::Void trackBar3_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox3->Text = (trackBar3->Value).ToString();
	EMILOGIC();
}
private: System::Void label19_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void EMI_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
