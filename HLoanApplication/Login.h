#pragma once
#include "UserServiceImpl.h"
#include "UserDAOImpl.h"
#include "Register.h"
#include "UserDashboard.h"

#include "AdminDashboard.h"

#include <map>
#include <msclr/marshal_cppstd.h>


namespace HLoanApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
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
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(270, 261);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 48);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Login::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(325, 132);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(259, 30);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(325, 176);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(259, 30);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(186, 338);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(321, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Not Registered\? Click here";
			this->label1->Click += gcnew System::EventHandler(this, &Login::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(120, 132);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(122, 23);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Username";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(120, 179);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(122, 23);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Password";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(468, 225);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(116, 16);
			this->linkLabel1->TabIndex = 6;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Forgot Password\?";
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(747, 550);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Login";
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		UserDAOImpl userDaoObj;

		UserServiceImpl user_service_obj(userDaoObj);


		String^ username = textBox1->Text;


		string converted_username = msclr::interop::marshal_as< std::string >(username);


		System::String^ password = textBox2->Text;

		std::string converted_password = msclr::interop::marshal_as< std::string >(password);


		map<string, string> user_details = user_service_obj.login(converted_username, converted_password);
		long int status_code = stol(user_details["status_code"]);

		String^ status_message = msclr::interop::marshal_as< String^ >(user_details["status_message"]);
		String^ name = msclr::interop::marshal_as<String^>(user_details["first_name"] + " " + user_details["last_name"]);
		String^ salary = msclr::interop::marshal_as<String^>(user_details["salary"]);
		String^ PAN = msclr::interop::marshal_as<String^>(user_details["PAN"]);

		String^ Aadhaar = msclr::interop::marshal_as<String^>(user_details["Aadhaar"]);


		cout << user_details["is_admin"] << endl;
		if (status_code == 200) {
			MessageBox::Show(status_message);
			this->Close();

			if (user_details["is_admin"] == "1") {
				AdminDashboard^ a_dash = gcnew AdminDashboard(username,name,password, salary,PAN, Aadhaar);

				a_dash->Show();
				a_dash->Activate();
			}
			else {
				UserDashboard^ u_dash = gcnew UserDashboard(username,name,password,salary,PAN, Aadhaar);
				u_dash->Show();
				u_dash->Activate();


			}


			

		}
		else {
			MessageBox::Show(status_message);

		}
	}
	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

	Register^ register_page = gcnew Register();
	register_page->ShowDialog();
}
};
}
