#pragma once
#include "ApplicationDAOImpl.h"
#include "ApplicationServiceImpl.h"
#include <map>
#include <string>
#include <msclr/marshal_cppstd.h>

namespace HLoanApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Payment
	/// </summary>
	public ref class Payment : public System::Windows::Forms::Form
	{
	public:
		Payment(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void loadData(String^ converted_applicantd) {
			std::string converted_applicantId = msclr::interop::marshal_as< std::string >(converted_applicantd);

			ApplicationDAOImpl appDAOObj;

			ApplicationServiceImpl app_service_obj(appDAOObj);

			vector<map<string, string>> resp_obj = app_service_obj.getApplicationsByApplicantIdApproved(converted_applicantId);
			DataTable^ table = gcnew DataTable();
			table->Columns->Add("ApplicationId");
			table->Columns->Add("PropertyName");
			table->Columns->Add("LoanAmt");

			table->Columns->Add("amountPaid");
			table->Columns->Add("tenure (in months)");
			table->Columns->Add("tenure_remaining (in months)");
			table->Columns->Add("emi");
			table->Columns->Add("intrestRate");




			for (const auto& map : resp_obj) {

				DataRow^ row = table->NewRow();
				for (const auto& obj : map) {
					string key = obj.first;
					String^ converted_str = msclr::interop::marshal_as< String^ >(obj.second);
					String^ converted_str_key = msclr::interop::marshal_as< String^ >(obj.first);
					row[converted_str_key] = converted_str;
				}
				table->Rows->Add(row);
			}

			dataGridView1->DataSource = table;

		}
		String^ str_applicantId;
		Payment(String^ applicantId)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			str_applicantId = applicantId;
			loadData(applicantId);




		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Payment()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(292, 599);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(152, 40);
			this->button2->TabIndex = 37;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Payment::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(60, 214);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(633, 355);
			this->dataGridView1->TabIndex = 36;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Payment::dataGridView1_CellContentClick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(579, 132);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 34);
			this->button1->TabIndex = 40;
			this->button1->Text = L"Pay";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Payment::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(70, 87);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(234, 23);
			this->label1->TabIndex = 39;
			this->label1->Text = L"Application Id :";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(310, 81);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(236, 34);
			this->textBox1->TabIndex = 38;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(126, 138);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(178, 23);
			this->label2->TabIndex = 42;
			this->label2->Text = L"Amount     :";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(310, 132);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(236, 34);
			this->textBox2->TabIndex = 41;
			// 
			// Payment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(753, 707);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Payment";
			this->Text = L"Payment";
			this->Load += gcnew System::EventHandler(this, &Payment::Payment_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Payment_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	string app_id = msclr::interop::marshal_as< std::string >(textBox1->Text);
	string amt = msclr::interop::marshal_as< std::string >(textBox2->Text);

	long int converted_app_id = stol(app_id);
	long int converted_amt = stol(amt);


	ApplicationDAOImpl app_doa_obj;
	ApplicationServiceImpl app_serivce(app_doa_obj);

	bool isSuccess = app_serivce.updatePayment(converted_app_id, converted_amt);
	if (isSuccess) {
		MessageBox::Show("Success, paid amount");
	}
	else {
		MessageBox::Show("Failed to add amount");
	}
	loadData(str_applicantId);


}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
