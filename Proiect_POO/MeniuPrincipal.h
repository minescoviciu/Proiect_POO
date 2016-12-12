#pragma once
//#include "XMLManager.h"
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
	protected:

	protected:

	private: System::Windows::Forms::GroupBox^  groupBoxDataPersonale;

	private: System::Windows::Forms::Label^  labelDate;

	private: System::Windows::Forms::GroupBox^  groupBoxAdaugaVizualizeaza;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ComboBox^  comboBoxSex;
	private: System::Windows::Forms::Button^  buttonAdauga;
	private: System::Windows::Forms::Button^  buttonCautaPacient;
	private: System::Windows::Forms::Button^  buttonAdaugaImagine;






	protected:

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
			this->buttonPacientNou = (gcnew System::Windows::Forms::Button());
			this->groupBoxDataPersonale = (gcnew System::Windows::Forms::GroupBox());
			this->comboBoxSex = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->labelDate = (gcnew System::Windows::Forms::Label());
			this->groupBoxAdaugaVizualizeaza = (gcnew System::Windows::Forms::GroupBox());
			this->buttonAdauga = (gcnew System::Windows::Forms::Button());
			this->buttonCautaPacient = (gcnew System::Windows::Forms::Button());
			this->buttonAdaugaImagine = (gcnew System::Windows::Forms::Button());
			this->groupBoxDataPersonale->SuspendLayout();
			this->groupBoxAdaugaVizualizeaza->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonPacientNou
			// 
			this->buttonPacientNou->Location = System::Drawing::Point(528, 477);
			this->buttonPacientNou->Name = L"buttonPacientNou";
			this->buttonPacientNou->Size = System::Drawing::Size(64, 53);
			this->buttonPacientNou->TabIndex = 0;
			this->buttonPacientNou->Text = L"Pacient Nou";
			this->buttonPacientNou->UseVisualStyleBackColor = true;
			this->buttonPacientNou->Click += gcnew System::EventHandler(this, &MeniuPrincipal::buttonPacientNou_Click);
			// 
			// groupBoxDataPersonale
			// 
			this->groupBoxDataPersonale->Controls->Add(this->comboBoxSex);
			this->groupBoxDataPersonale->Controls->Add(this->textBox1);
			this->groupBoxDataPersonale->Controls->Add(this->labelDate);
			this->groupBoxDataPersonale->Location = System::Drawing::Point(6, 19);
			this->groupBoxDataPersonale->Name = L"groupBoxDataPersonale";
			this->groupBoxDataPersonale->Size = System::Drawing::Size(312, 323);
			this->groupBoxDataPersonale->TabIndex = 1;
			this->groupBoxDataPersonale->TabStop = false;
			this->groupBoxDataPersonale->VisibleChanged += gcnew System::EventHandler(this, &MeniuPrincipal::groupBoxDataPersonale_VisibleChanged);
			// 
			// comboBoxSex
			// 
			this->comboBoxSex->BackColor = System::Drawing::SystemColors::Window;
			this->comboBoxSex->Cursor = System::Windows::Forms::Cursors::Default;
			this->comboBoxSex->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxSex->ForeColor = System::Drawing::SystemColors::WindowText;
			this->comboBoxSex->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Masculin", L"Feminin", L"Altul" });
			this->comboBoxSex->Location = System::Drawing::Point(133, 217);
			this->comboBoxSex->Name = L"comboBoxSex";
			this->comboBoxSex->Size = System::Drawing::Size(111, 21);
			this->comboBoxSex->TabIndex = 2;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Window;
			this->textBox1->ForeColor = System::Drawing::SystemColors::WindowText;
			this->textBox1->Location = System::Drawing::Point(121, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(147, 20);
			this->textBox1->TabIndex = 1;
			// 
			// labelDate
			// 
			this->labelDate->AutoSize = true;
			this->labelDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelDate->ForeColor = System::Drawing::SystemColors::ControlText;
			this->labelDate->Location = System::Drawing::Point(22, 35);
			this->labelDate->Name = L"labelDate";
			this->labelDate->Size = System::Drawing::Size(51, 16);
			this->labelDate->TabIndex = 0;
			this->labelDate->Text = L"label1";
			// 
			// groupBoxAdaugaVizualizeaza
			// 
			this->groupBoxAdaugaVizualizeaza->Controls->Add(this->buttonAdauga);
			this->groupBoxAdaugaVizualizeaza->Controls->Add(this->groupBoxDataPersonale);
			this->groupBoxAdaugaVizualizeaza->Location = System::Drawing::Point(42, 32);
			this->groupBoxAdaugaVizualizeaza->Name = L"groupBoxAdaugaVizualizeaza";
			this->groupBoxAdaugaVizualizeaza->Size = System::Drawing::Size(448, 485);
			this->groupBoxAdaugaVizualizeaza->TabIndex = 3;
			this->groupBoxAdaugaVizualizeaza->TabStop = false;
			this->groupBoxAdaugaVizualizeaza->Visible = false;
			// 
			// buttonAdauga
			// 
			this->buttonAdauga->Location = System::Drawing::Point(353, 445);
			this->buttonAdauga->Name = L"buttonAdauga";
			this->buttonAdauga->Size = System::Drawing::Size(75, 23);
			this->buttonAdauga->TabIndex = 2;
			this->buttonAdauga->Text = L"Adaugã";
			this->buttonAdauga->UseVisualStyleBackColor = true;
			this->buttonAdauga->Click += gcnew System::EventHandler(this, &MeniuPrincipal::buttonAdauga_Click);
			// 
			// buttonCautaPacient
			// 
			this->buttonCautaPacient->Location = System::Drawing::Point(528, 419);
			this->buttonCautaPacient->Name = L"buttonCautaPacient";
			this->buttonCautaPacient->Size = System::Drawing::Size(64, 52);
			this->buttonCautaPacient->TabIndex = 4;
			this->buttonCautaPacient->Text = L"Cautã Pacient";
			this->buttonCautaPacient->UseVisualStyleBackColor = true;
			// 
			// buttonAdaugaImagine
			// 
			this->buttonAdaugaImagine->Location = System::Drawing::Point(528, 361);
			this->buttonAdaugaImagine->Name = L"buttonAdaugaImagine";
			this->buttonAdaugaImagine->Size = System::Drawing::Size(64, 52);
			this->buttonAdaugaImagine->TabIndex = 5;
			this->buttonAdaugaImagine->Text = L"Adaugã Imagine";
			this->buttonAdaugaImagine->UseVisualStyleBackColor = true;
			this->buttonAdaugaImagine->Click += gcnew System::EventHandler(this, &MeniuPrincipal::buttonAdaugaImagine_Click);
			// 
			// MeniuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1137, 574);
			this->Controls->Add(this->buttonAdaugaImagine);
			this->Controls->Add(this->buttonCautaPacient);
			this->Controls->Add(this->groupBoxAdaugaVizualizeaza);
			this->Controls->Add(this->buttonPacientNou);
			this->Name = L"MeniuPrincipal";
			this->Text = L"MeniuPrincipal";
			this->groupBoxDataPersonale->ResumeLayout(false);
			this->groupBoxDataPersonale->PerformLayout();
			this->groupBoxAdaugaVizualizeaza->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: array<Control^>^ toateControaleleCopie(GroupBox^ groupBox, int cate, String^ nume)
	{
		array<Control^>^ deReturnat = gcnew array<Control^>(cate);
		int k = 0;
		for each (Control^ con in groupBox->Controls)
		{
			for (int i = 1; i < cate; i++)
			{
				if (con->Name->Equals(nume + "copie" + i))
				{
					deReturnat[k++] = con;
					break;
				}
			}
		}
		return deReturnat;

	}

	private: System::Void shimbaCuloareLabeluri(GroupBox^ groupBox, Color culoare)
	{
		array<Control^>^ labeluri = toateControaleleCopie(groupBoxDataPersonale, CATELABELURI, labelDate->Name);
		for each (Label^ lab in labeluri)
		{
			if (lab != nullptr)
			{
				lab->ForeColor = culoare;
			}
		}
		labelDate->ForeColor = culoare;
	}

	private: System::Void generareLabeluri(Label^ temp, int cate, array<String^>^nume, GroupBox^ groupBox)
	{
		array<Label^>^labeluri = gcnew array<Label^>(cate);
		labeluri[0] = temp;
		labeluri[0]->Text = nume[0] + ":";
		for (int i = 1; i < cate; i++)
		{
			labeluri[i] = gcnew Label;
			labeluri[i]->Text = nume[i] + ":";
			labeluri[i]->Location = Point(labeluri[i - 1]->Location.X, labeluri[i - 1]->Location.Y + temp->Size.Height + 20);
			labeluri[i]->Font = temp->Font;
			labeluri[i]->AutoSize = true;
			labeluri[i]->ForeColor = temp->ForeColor;
			labeluri[i]->Name = temp->Name + "copie" + i;
			groupBox->Controls->Add(labeluri[i]);
		}
	}

	private: System::Void generareTextBox(TextBox^ temp, int cate, GroupBox^ groupBox)
	{
		array<TextBox^>^ textboxuri = gcnew array<TextBox^>(cate);
		textboxuri[0] = temp;
		for (int i = 1; i < cate; i++)
		{
			textboxuri[i] = gcnew TextBox;
			textboxuri[i]->Location = Point(textboxuri[i - 1]->Location.X, textboxuri[i - 1]->Location.Y + temp->Size.Height + 16);
			textboxuri[i]->Font = temp->Font;
			textboxuri[i]->Name = temp->Name + "copie" + i;
			textboxuri[i]->Size = temp->Size;
			groupBox->Controls->Add(textboxuri[i]);
		}

		comboBoxSex->Location = Point(textboxuri[cate - 1]->Location.X, textboxuri[cate - 1]->Location.Y + temp->Size.Height + 16);

	}

	private: System::Void stergeControale(Control^ control, GroupBox^ groupBox, int cate)
	{
		array<Control^>^deSters = toateControaleleCopie(groupBox, cate, control->Name);
		for each (Control^ con in deSters)
		{
			groupBox->Controls->Remove(con);
		}
	}

	private: System::Boolean verificaDacaSaCompletatTot(Color culoareGresit, Color culoareCorect)
	{
		array<Control^>^ textBoxuri = toateControaleleCopie(groupBoxDataPersonale, CATETEXTBOXURI, textBox1->Name);
		array<Control^>^ labeluri = toateControaleleCopie(groupBoxDataPersonale, CATELABELURI, labelDate->Name);
		int x;
		Boolean ok = true;
		if (textBox1->Text->Length <= 2)
		{
			labelDate->ForeColor = culoareGresit;
			ok = false;
		}
		else
		{
			labelDate->ForeColor = culoareCorect;
		}
		if (textBoxuri[0]->Text->Length <= 2)
		{
			labeluri[0]->ForeColor = culoareGresit;
			ok = false;
		}
		else
		{
			labeluri[0]->ForeColor = culoareCorect;
		}
		if (textBoxuri[1]->Text->Length <= 2)
		{
			labeluri[1]->ForeColor = culoareGresit;
			ok = false;
		}
		else
		{
			labeluri[1]->ForeColor = culoareCorect;
		}
		if (!textBoxuri[2]->Text->Contains("@"))
		{
			labeluri[2]->ForeColor = culoareGresit;
			ok = false;
		}
		else
		{
			labeluri[2]->ForeColor = culoareCorect;
		}
		if (!Int32::TryParse(textBoxuri[3]->Text, x) || textBoxuri[3]->Text->Length != 10)
		{
			labeluri[3]->ForeColor = culoareGresit;
			ok = false;
		}
		else
		{
			labeluri[3]->ForeColor = culoareCorect;
		}
		if (!Int32::TryParse(textBoxuri[4]->Text, x) || textBoxuri[4]->Text->Length >3)
		{
			labeluri[4]->ForeColor = culoareGresit;
			ok = false;
		}
		else
		{
			labeluri[4]->ForeColor = culoareCorect;
		}
		if (comboBoxSex->Text->Length == 0)
		{
			labeluri[5]->ForeColor = culoareGresit;
			ok = false;
		}
		else
		{
			labeluri[5]->ForeColor = culoareCorect;
		}
		return ok;
	}

	private: System::Void buttonPacientNou_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//writeXml("Ionescu", "Ioana", "str Cantacuzino nr 1", "ioanaionescu@yahoo.com", "0712123123", "femini", 56, 1);
		groupBoxAdaugaVizualizeaza->Visible = true;
	}

	private: System::Void groupBoxDataPersonale_VisibleChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (sender->Equals(groupBoxDataPersonale))
		{

			if (groupBoxDataPersonale->Visible == true)
			{
				array<String^>^s = gcnew array<String^>{"Nume", "Prenume", "Adresa", "Email", "Telefon", "Varsta", "Sex"};
				generareLabeluri(labelDate, CATELABELURI, s, groupBoxDataPersonale);
				generareTextBox(textBox1, CATETEXTBOXURI, groupBoxDataPersonale);
			}
			else
			{
				stergeControale(textBox1, groupBoxDataPersonale, CATELABELURI);
				stergeControale(labelDate, groupBoxDataPersonale, CATETEXTBOXURI);
			}
		}
	}

	private: System::Void buttonAdauga_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (!verificaDacaSaCompletatTot(Color::Red, Color::Green))
		{
			MessageBox::Show("Nu ati completat toate campurile sau ati completat gresit", "Atentie", MessageBoxButtons::OK);

		}
		else
		{
			array<Control^>^ textBoxuri = toateControaleleCopie(groupBoxDataPersonale, CATETEXTBOXURI, textBox1->Name);
			XMLManager newXml(XMLPATH);
			//XmlWriterClass^ newXml = gcnew XmlWriterClass("Pacienti.xml");
			newXml.writeXml(textBox1->Text, textBoxuri[0]->Text,
				textBoxuri[1]->Text, textBoxuri[2]->Text,
				textBoxuri[3]->Text, comboBoxSex->Text,
				Int32::Parse(textBoxuri[4]->Text));
			textBox1->Text = "";
			for each (Control^ con in textBoxuri)
			{
				if (con != nullptr)
					con->Text = "";
			}
			shimbaCuloareLabeluri(groupBoxDataPersonale, Color::Black);
		}
	}

	private: System::Void buttonAdaugaImagine_Click(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ fd = gcnew OpenFileDialog();
		if (fd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			//groupBoxImagine->BackgroundImage fd->FileName;
		}
	}
	};
}
