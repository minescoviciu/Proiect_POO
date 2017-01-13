#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "ButonRotund.h"
#include "SQL_Acces.h"

#define CATELABELURI 7
#define CATETEXTBOXURI 6
#define CONNECTION_STRING "datasource=localhost;port=3306;username=minescoviciu;password=root1234;"

/// <summary>
/// Summary for AdaugaPacientUserControl
/// </summary>
public ref class AdaugaPacientUserControl : public System::Windows::Forms::UserControl
{

private: System::Windows::Forms::ComboBox^  comboBoxSex = gcnew ComboBox;
private: array<Label^>^labeluri = gcnew array<Label^>(CATELABELURI);
private: array<TextBox^>^textBoxuri = gcnew array<TextBox^>(CATETEXTBOXURI);

private: System::Windows::Forms::Button^ buttonAdauga = gcnew Button;

public:
	AdaugaPacientUserControl(void)
	{
		InitializeComponent();
		//
		//TODO: Add the constructor code here
		//
		CreeazaControale();
	}

private: System::Void CreeazaControale()
{
	//comboBoxSex//
	this->comboBoxSex->BackColor = System::Drawing::SystemColors::Window;
	this->comboBoxSex->Cursor = System::Windows::Forms::Cursors::Default;
	this->comboBoxSex->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	this->comboBoxSex->ForeColor = System::Drawing::SystemColors::WindowText;
	this->comboBoxSex->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Masculin", L"Feminin", L"Altul" });
	this->comboBoxSex->Location = System::Drawing::Point(133, 217);
	this->comboBoxSex->Name = L"comboBoxSex";
	this->comboBoxSex->Size = System::Drawing::Size(111, 21);
	this->comboBoxSex->TabIndex = CATETEXTBOXURI + 1;
	this->Controls->Add(comboBoxSex);
	//labeluri//
	array<String^>^numeLabeluri = gcnew array<String^>{"Nume", "Prenume", "Adresa", "Email", "Telefon", "Varsta", "Sex"};
	generareLabeluri(CATELABELURI, numeLabeluri);
	//textboxuri//
	generareTextBox(CATETEXTBOXURI);
	//butonAdauga//

	ButonRotund^buttonAdauga = gcnew ButonRotund(Color::Gold, "Adaugã");
	buttonAdauga->Location = Point(230, 285);
	buttonAdauga->Size = System::Drawing::Size(80, 20);
	buttonAdauga->Click += gcnew System::EventHandler(this, &AdaugaPacientUserControl::buttonAdauga_Click);
	buttonAdauga->Name = "buttonAdaua";
	this->buttonAdauga->TabIndex = comboBoxSex->TabIndex + 1;
	this->Controls->Add(buttonAdauga);

	/*this->buttonAdauga->Location = System::Drawing::Point(230, 285);
	this->buttonAdauga->Name = L"buttonAdauga";
	this->buttonAdauga->Size = System::Drawing::Size(75, 23);
	this->buttonAdauga->TabIndex = 2;
	this->buttonAdauga->Text = L"Adaugã";
	this->buttonAdauga->UseVisualStyleBackColor = true;
	this->buttonAdauga->Click += gcnew System::EventHandler(this, &AdaugaPacientUserControl::buttonAdauga_Click);
	this->buttonAdauga->TabIndex = comboBoxSex->TabIndex + 1;
	this->Controls->Add(buttonAdauga);*/
}

protected:
	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	~AdaugaPacientUserControl()
	{
		if (components)
		{
			delete components;
		}
	}

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
		this->SuspendLayout();
		// 
		// AdaugaPacientUserControl
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::SystemColors::ActiveCaption;
		this->Name = L"AdaugaPacientUserControl";
		this->Size = System::Drawing::Size(310, 310);
		this->ResumeLayout(false);

	}
#pragma endregion

private: System::Windows::Forms::Label^ generareLabelTemplate()
{
	Label^ temp = gcnew Label();
	temp->AutoSize = true;
	temp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(238)));
	temp->ForeColor = System::Drawing::SystemColors::ControlText;
	temp->Location = System::Drawing::Point(20, 35);
	temp->Name = L"labelDate";
	temp->Size = System::Drawing::Size(51, 16);
	temp->TabIndex = 0;
	temp->Text = L"label1";
	return temp;
}

private: System::Void generareLabeluri(int cate, array<String^>^nume)
{
	labeluri[0] = generareLabelTemplate();
	labeluri[0]->Text = nume[0] + ":";
	this->Controls->Add(labeluri[0]);
	for (int i = 1; i < cate; i++)
	{
		labeluri[i] = gcnew Label();
		labeluri[i]->Text = nume[i] + ":";
		labeluri[i]->Location = Point(labeluri[i - 1]->Location.X, labeluri[i - 1]->Location.Y + labeluri[0]->Size.Height + 20);
		labeluri[i]->Font = labeluri[0]->Font;
		labeluri[i]->AutoSize = true;
		labeluri[i]->ForeColor = labeluri[0]->ForeColor;
		labeluri[i]->Name = labeluri[0]->Name + "copie" + i;
		this->Controls->Add(labeluri[i]);
	}
}

private: System::Windows::Forms::TextBox^generareTextBoxTemplate()
{
	TextBox^temp = gcnew TextBox();
	temp->BackColor = System::Drawing::SystemColors::Window;
	temp->ForeColor = System::Drawing::SystemColors::WindowText;
	temp->Location = System::Drawing::Point(120, 35);
	temp->Name = L"textDate";
	temp->Size = System::Drawing::Size(147, 30);
	temp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(238)));
	temp->TabIndex = 1;
	temp->BorderStyle = System::Windows::Forms::BorderStyle::None;
	return temp;
}

private: System::Void generareTextBox(int cate)
{
	textBoxuri[0] = generareTextBoxTemplate();
	this->Controls->Add(textBoxuri[0]);
	for (int i = 1; i < cate; i++)
	{
		textBoxuri[i] = gcnew TextBox();
		textBoxuri[i]->Location = Point(textBoxuri[i - 1]->Location.X, textBoxuri[i - 1]->Location.Y + labeluri[0]->Size.Height + 20);
		textBoxuri[i]->Font = textBoxuri[0]->Font;
		textBoxuri[i]->Name = textBoxuri[0]->Name + "copie" + i;
		textBoxuri[i]->Size = textBoxuri[0]->Size;
		textBoxuri[i]->TabIndex = textBoxuri[i-1]->TabIndex + 1;
		textBoxuri[i]->BorderStyle = textBoxuri[0]->BorderStyle;
		textBoxuri[i]->Font = textBoxuri[0]->Font;
		this->Controls->Add(textBoxuri[i]);
	}

	comboBoxSex->Location = Point(textBoxuri[cate - 1]->Location.X, textBoxuri[cate - 1]->Location.Y + labeluri[0]->Size.Height + 20);

}

private: System::Boolean verificaDacaSaCompletatTot(Color culoareGresit, Color culoareCorect)
{
	int x;
	Boolean ok = true;
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
	if (textBoxuri[2]->Text->Length <= 2)
	{
		labeluri[2]->ForeColor = culoareGresit;
		ok = false;
	}
	else
	{
		labeluri[2]->ForeColor = culoareCorect;
	}
	if (!textBoxuri[3]->Text->Contains("@"))
	{
		labeluri[3]->ForeColor = culoareGresit;
		ok = false;
	}
	else
	{
		labeluri[3]->ForeColor = culoareCorect;
	}
	if (!Int32::TryParse(textBoxuri[4]->Text, x) || textBoxuri[4]->Text->Length != 10)
	{
		labeluri[4]->ForeColor = culoareGresit;
		ok = false;
	}
	else
	{
		labeluri[4]->ForeColor = culoareCorect;
	}
	if (!Int32::TryParse(textBoxuri[5]->Text, x) || textBoxuri[5]->Text->Length >3)
	{
		labeluri[5]->ForeColor = culoareGresit;
		ok = false;
	}
	else
	{
		labeluri[5]->ForeColor = culoareCorect;
	}
	if (comboBoxSex->Text->Length == 0)
	{
		labeluri[6]->ForeColor = culoareGresit;
		ok = false;
	}
	else
	{
		labeluri[6]->ForeColor = culoareCorect;
	}
	return ok;
}

private: System::Void shimbaCuloareLabeluri(Color culoare)
{
	for each (Label^ lab in labeluri)
	{
		if (lab != nullptr)
		{
			lab->ForeColor = culoare;
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
		SQL_Acces^ variabila = gcnew SQL_Acces(CONNECTION_STRING);
		variabila->AdaugaPacient(textBoxuri[0]->Text, textBoxuri[1]->Text,
			textBoxuri[2]->Text, textBoxuri[3]->Text,
			textBoxuri[4]->Text, comboBoxSex->Text,
			Int32::Parse(textBoxuri[5]->Text));

		textBoxuri[0]->Text = "";
		for each (Control^ con in textBoxuri)
		{
			if (con != nullptr)
				con->Text = "";
		}
		shimbaCuloareLabeluri(Color::Black);
	}
}
};
