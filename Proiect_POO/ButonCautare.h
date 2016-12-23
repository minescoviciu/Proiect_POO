#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Reflection;
using namespace System::Resources;

#include "ButonRotund.h"

/// <summary>
/// Summary for AdaugaPacientUserControl
/// </summary>
public ref class ButonCautare : public System::Windows::Forms::UserControl
{

private: System::Windows::Forms::Button^ butonCauta = gcnew Button();
private: System::Windows::Forms::TextBox^ textBox = gcnew TextBox();
private: ButonRotund^ butonRotund;
private: Color culoareBackGround;

public:
	ButonCautare(Color forColor)
	{
		InitializeComponent();
		//
		//TODO: Add the constructor code here
		//
		this->BackColor = Color::Transparent;
		culoareBackGround = forColor;

		//Import Imagini
		// Grab the assembly this is being called from
		Assembly^ assembly = Assembly::GetExecutingAssembly();
		AssemblyName^ assemblyName = assembly->GetName();

		// Grab the images from the assembly
		ResourceManager^ rm = gcnew ResourceManager(assemblyName->Name + ".ImageResources", assembly);
		Image^imagine = (Image^)rm->GetObject("searchIcon");

		//textBox
		this->textBox->Location = Point(10, 0);
		this->textBox->Name = L"textBox";
		this->textBox->Size = System::Drawing::Size(155, 20);
		this->textBox->TabIndex = 0;
		this->textBox->Text = L"Cauta";
		this->textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textBox->Margin = System::Windows::Forms::Padding(0);
		this->textBox->BackColor = forColor;
		this->textBox->MaxLength = 16;
		this->textBox->SelectionStart = this->textBox->Text->Length;
		this->textBox->SelectionLength = 0;
		this->textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ButonCautare::textBox_OnKeyDown);
		this->Controls->Add(textBox);
		//buton Cauta

		butonRotund = gcnew ButonRotund(culoareBackGround,imagine);
		butonRotund->Location = Point(textBox->Size.Width + 15, 0);
		butonRotund->Click += gcnew System::EventHandler(this, &ButonCautare::buttonCautare_Click);
		this->Controls->Add(butonRotund);
	}

protected:  System::Void OnPaint(PaintEventArgs^ e) override
	{
		Graphics^ g = e->Graphics;
		//g->FillEllipse(Brushes::Azure, 0, 0, 150, 30);
		Drawing2D::GraphicsPath^ path = gcnew Drawing2D::GraphicsPath();
		int width = this->Size.Width;
		int height = this->Size.Height;
		//partea stanga
		path->AddBezier(10, 0, 0, 5, 0, height - 5, 10, height);
		//partea dreapta
		path->AddBezier(width - 10, 0, width, 5, width, height - 5, width - 10, height);
		//linia de sus
		path->AddLine(10, 0, width - 10, 0);
		//linia de jos
		path->AddLine(10, height, width - 10, height);
		SolidBrush^ br = gcnew SolidBrush(culoareBackGround);
		g->FillPath(br, path);
		//Graphics graphics = e.Graphics;
		//Pen myPen = new Pen(Color.Black);
		//// Draw the button in the form of a circle
		//graphics.DrawEllipse(myPen, 0, 0, 100, 100);
		//myPen.Dispose();
	}

protected:
	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	~ButonCautare()
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
		// ButonCautare
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::SystemColors::ActiveCaption;
		this->Name = L"ButonCautare";
		this->Size = System::Drawing::Size(200, 20);
		this->ResumeLayout(false);

	}
#pragma endregion

	private: System::Void buttonCautare_Click(System::Object^  sender, System::EventArgs^  e)
	{
		MessageBox::Show("da");
	}
	
	void ButonCautare::textBox_OnKeyDown(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e)
	{
		if (e->KeyCode == Keys::Enter)
		{
			buttonCautare_Click(sender, e);
		}
		else if (textBox->Text->Equals("Cauta"))
		{
			textBox->Text = "";
		}
	}
};



