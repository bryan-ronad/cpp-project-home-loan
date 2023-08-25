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
	/// Summary for StatusCheck
	/// </summary>
	public ref class StatusCheck : public System::Windows::Forms::Form
	{
	public:
		StatusCheck(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		StatusCheck(String^ applicantId)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			ApplicationDAOImpl appDAOObj;
			std::string converted_applicantId = msclr::interop::marshal_as< std::string >(applicantId);

			ApplicationServiceImpl app_service_obj(appDAOObj);

			vector<map<string, string>> resp_obj = app_service_obj.getApplicationsByApplicantId(converted_applicantId);

			DataTable^ table = gcnew DataTable();
			table->Columns->Add("ApplicationId");
			table->Columns->Add("Status");

			table->Columns->Add("LoanAmt");
			table->Columns->Add("PropertyName");


			for (const auto& map : resp_obj) {
				
					DataRow^ row = table->NewRow();
					for (const auto& obj : map) {

						cout << obj.first << endl;



						string key = obj.first;
						String^ converted_str = msclr::interop::marshal_as< String^ >(obj.second);
						String^ converted_str_key = msclr::interop::marshal_as< String^ >(obj.first);

						row[converted_str_key] = converted_str;

					}
					table->Rows->Add(row);


					cout << "-----" << endl;
				}

			dataGridView1->DataSource = table;
		




		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StatusCheck()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button2;
	protected:

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(39, 103);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(633, 355);
			this->dataGridView1->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(271, 488);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(152, 40);
			this->button2->TabIndex = 35;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &StatusCheck::button2_Click);
			// 
			// StatusCheck
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(716, 540);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"StatusCheck";
			this->Text = L"StatusCheck";
			this->Load += gcnew System::EventHandler(this, &StatusCheck::StatusCheck_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void StatusCheck_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
