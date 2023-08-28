#pragma once
#include <string>
#include <map>
#include <msclr/marshal_cppstd.h>
#include "Profile.h"
#include "ApplicationDAOImpl.h"
#include "ApplicationServiceImpl.h"

namespace HLoanApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminDashboard
	/// </summary>
	public ref class AdminDashboard : public System::Windows::Forms::Form
	{
	public:
		String^ _name;

		String^ _salary;
		String^ _PAN;
		String^ _password;


		String^ _Aadhaar;
		AdminDashboard(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//


		}
		String^ admin_id;
		void loadData() {
			ApplicationDAOImpl appDAOObj;

			ApplicationServiceImpl app_service_obj(appDAOObj);

			vector<map<string, string>> resp_obj = app_service_obj.getApplications();

			DataTable^ table = gcnew DataTable();
			table->Columns->Add("ApplicationId");
			table->Columns->Add("ApplicantId");
			table->Columns->Add("Status");
			table->Columns->Add("PropertyName");
			table->Columns->Add("LoanAmount");
			table->Columns->Add("Salary");
			table->Columns->Add("PAN");
			table->Columns->Add("Aadhar");


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

			}

			dataGridView1->DataSource = table;

		}
		bool check_number(string str) {
			for (int i = 0; i < str.length(); i++)
				if (isdigit(str[i]) == false)
					return false;
			return true;
		}

		AdminDashboard(String^ adminId,String^ name,String^ password,String^ salary, String^PAN,String^ Aadhar) {
			InitializeComponent();
			admin_id = adminId;
			_name = name;
			_salary = salary;
			_password = password;
			_PAN = PAN;

			_Aadhaar = Aadhar;

			std::string converted_applicantId = msclr::interop::marshal_as< std::string >(adminId);

			loadData();
			
		}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminDashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminDashboard::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(2, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(236, 822);
			this->panel1->TabIndex = 1;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(-63, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(359, 231);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Transparent;
			this->button5->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(3, 362);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(238, 70);
			this->button5->TabIndex = 2;
			this->button5->Text = L"Logout";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &AdminDashboard::button5_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Transparent;
			this->button4->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(3, 299);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(238, 70);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Profile";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &AdminDashboard::button4_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(3, 232);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(238, 70);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Loan Applications";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(249, 256);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(945, 415);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AdminDashboard::dataGridView1_CellContentClick);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(584, 138);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(236, 34);
			this->textBox1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(265, 144);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(304, 23);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Loan Application Id :";
			this->label1->Click += gcnew System::EventHandler(this, &AdminDashboard::label1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(845, 134);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(115, 46);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Appove";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminDashboard::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Lucida Console", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(956, 134);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(115, 46);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Reject";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AdminDashboard::button3_Click);
			// 
			// AdminDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ClientSize = System::Drawing::Size(1206, 703);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->panel1);
			this->Name = L"AdminDashboard";
			this->Text = L"AdminDashboard";
			this->Load += gcnew System::EventHandler(this, &AdminDashboard::AdminDashboard_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AdminDashboard_Load(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ applicationId = textBox1->Text;
	std::string converted_applicationId = msclr::interop::marshal_as< std::string >(applicationId);
	if (check_number(converted_applicationId)) {
		if (converted_applicationId != "") {

			ApplicationDAOImpl appDAOObj;

			long int int_applicationId = stol(converted_applicationId);

			ApplicationServiceImpl app_service_obj(appDAOObj);

			bool status=app_service_obj.updateApplicationStatus(int_applicationId, "APPROVED");

			if (status) {

				MessageBox::Show("Status updated");
				loadData();
			}
			else {
				MessageBox::Show("Enter valid id");
			}
		}
		else {
			MessageBox::Show("Please enter application id");
		}
	}
	else {
		MessageBox::Show("Application id does not contain any string/s");
	}

}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ applicationId = textBox1->Text;
	std::string converted_applicationId = msclr::interop::marshal_as< std::string >(applicationId);
	if (check_number(converted_applicationId)) {

	if (converted_applicationId !="") {
		ApplicationDAOImpl appDAOObj;
		long int int_applicationId = stol(converted_applicationId);

		ApplicationServiceImpl app_service_obj(appDAOObj);

		bool status=app_service_obj.updateApplicationStatus(int_applicationId, "REJECTED");
		if (status) {
			
				MessageBox::Show("status updated");
				loadData();
		}
		else {
			MessageBox::Show("Enter valid id");
		}
	}else {
		MessageBox::Show("Please enter application id");
	}
	}
	else {
		MessageBox::Show("Application id does not contain any string/s");
	}
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Profile^ profile = gcnew Profile(admin_id, _name, _password, _salary, _PAN, _Aadhaar);
	profile->ShowDialog();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
