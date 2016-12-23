#pragma once
//#include "XMLManager.h"
#include "AdaugaPacientUserControl.h"
#include "ButonCautare.h"
namespace ProiectPOO {

#define CATELABELURI 7
#define CATETEXTBOXURI 6
#define XMLPATH "XMLPacienti.xml"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Reflection;
	using namespace System::Resources;

#pragma region Chestii

	/// <summary>
	/// Summary for MeniuPrincipal
	/// </summary>
	public ref class MeniuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MeniuPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			//Import Imagini
			// Grab the assembly this is being called from
			Assembly^ assembly = Assembly::GetExecutingAssembly();
			AssemblyName^ assemblyName = assembly->GetName();

			// Grab the images from the assembly
			ResourceManager^ rm = gcnew ResourceManager(assemblyName->Name + ".ImageResources", assembly);
			ImageList^ imagini = gcnew ImageList();
			imagini->Images->Add((Image^)rm->GetObject("plus_2"));
			imagini->Images->Add((Image^)rm->GetObject("plus_3"));
			imagini->Images->Add((Image^)rm->GetObject("searchIcon"));
			
			buttonPacientNou->Image = imagini->Images[0];

			ButonCautare^ bt = gcnew ButonCautare( Color::Gold);
			bt->Location = Point(10, 10);
			this->Controls->Add(bt);
			this->ActiveControl = bt;

			ButonRotund^br = gcnew ButonRotund(Color::Transparent, imagini);
			br->Location = Point(10, 40);
			//br->Size = System::Drawing::Size(200, 20);
			br->Click += gcnew System::EventHandler(this, &ProiectPOO::MeniuPrincipal::Click);
			this->Controls->Add(br);

			ButonRotund^br2 = gcnew ButonRotund(Color::Gold, "Buton1");
			br2->Location = Point(10, 70);
			br2->Size = System::Drawing::Size(70, 20);
			br2->Click += gcnew System::EventHandler(this, &ProiectPOO::MeniuPrincipal::Click);
			this->Controls->Add(br2);

			ButonRotund^br3 = gcnew ButonRotund(Color::Gold, "Buton2", imagini->Images[2]);
			br3->Location = Point(10, 100);
			br3->Size = System::Drawing::Size(100, 20);
			br3->Click += gcnew System::EventHandler(this, &ProiectPOO::MeniuPrincipal::Click);
			this->Controls->Add(br3);

		}

	private: System::Void Click(System::Object^  sender, System::EventArgs^  e)
	{
		MessageBox::Show("da");
	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MeniuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonPacientNou;
	private: System::Windows::Forms::RadioButton^  radioButton1;







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
			this->buttonPacientNou = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// buttonPacientNou
			// 
			this->buttonPacientNou->BackColor = System::Drawing::Color::Maroon;
			this->buttonPacientNou->FlatAppearance->BorderSize = 0;
			this->buttonPacientNou->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->buttonPacientNou->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->buttonPacientNou->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPacientNou->Location = System::Drawing::Point(453, 452);
			this->buttonPacientNou->Name = L"buttonPacientNou";
			this->buttonPacientNou->Size = System::Drawing::Size(64, 53);
			this->buttonPacientNou->TabIndex = 0;
			this->buttonPacientNou->Text = L"r";
			this->buttonPacientNou->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->buttonPacientNou->UseVisualStyleBackColor = false;
			this->buttonPacientNou->Click += gcnew System::EventHandler(this, &MeniuPrincipal::buttonPacientNou_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->BackColor = System::Drawing::Color::Transparent;
			this->radioButton1->FlatAppearance->BorderSize = 0;
			this->radioButton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton1->ForeColor = System::Drawing::Color::Black;
			this->radioButton1->Location = System::Drawing::Point(214, 388);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(84, 17);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = false;
			// 
			// MeniuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightCoral;
			this->ClientSize = System::Drawing::Size(558, 562);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->buttonPacientNou);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MeniuPrincipal";
			this->Text = L"MeniuPrincipal";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma endregion

	private: System::Void buttonPacientNou_Click(System::Object^  sender, System::EventArgs^  e)
	{
		AdaugaPacientUserControl^ temp = gcnew AdaugaPacientUserControl();
		temp->Location = Point(20, 20);
		this->Controls->Add(temp);
	}

	};
}
