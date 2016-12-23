#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Reflection;
using namespace System::Resources;

/// <summary>
/// Summary for AdaugaPacientUserControl
/// </summary>
public ref class ButonRotund : System::Windows::Forms::UserControl
{

private: System::Windows::Forms::PictureBox^ pictureBox = gcnew PictureBox();
private: System::Windows::Forms::Label^ label = gcnew Label();
private: Color culoareBackGround;
private: ImageList^ imagini;
public:

	ButonRotund(void)
	{
		InitializeComponent();
		
	}
	ButonRotund(Color culoare)
	{
		Constructor1(culoare);
	}

	ButonRotund(Color culoare, String^ text)
	{
		Constructor1(culoare);
		InitializareLabel(text);
	}

	ButonRotund(Color culoare, System::Drawing::Image^ imagine)
	{
		Constructor1(culoare);
		InitializarePictureBox(imagine);
	}

	ButonRotund(Color culoare, String^ text, System::Drawing::Image^ imagine)
	{
		Constructor1(culoare);
		InitializareLabel(text);
		InitializarePictureBox(imagine);
	}

	ButonRotund(Color culoare, System::Windows::Forms::ImageList^ imagini_)
	{
		Constructor1(culoare);
		InitializarePictureBox(imagini_->Images[0]);
		
		this->imagini = imagini_;
		this->pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ButonRotund::PictureBox_OnMouseDown);
		this->pictureBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ButonRotund::PictureBox_OnMouseUp);
	}

private:	void Constructor1(Color culoare)
	{
		InitializeComponent();
		this->BackColor = Color::Transparent;
		this->culoareBackGround = culoare;
	}
private:	void InitializarePictureBox(Image^imagine)
{
	this->pictureBox->Name = L"pictureBox";
	this->pictureBox->Location = System::Drawing::Point(this->Size.Width - this->Size.Height, 1);
	this->pictureBox->Size = System::Drawing::Size(this->Size.Height, this->Size.Height);
	this->pictureBox->TabIndex = 1;
	this->pictureBox->TabStop = false;
	this->pictureBox->Image = imagine;
	this->pictureBox->Click += gcnew System::EventHandler(this, &ButonRotund::Control_Click);
	this->Resize += gcnew System::EventHandler(this, &ButonRotund::OnResize);
	this->Controls->Add(pictureBox);
}
private:	Void InitializareLabel(String^ text)
{
	this->label->AutoSize = true;
	this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(238)));
	this->label->Location = System::Drawing::Point(10, 0);
	this->label->Name = L"label";
	//this->label->Size = System::Drawing::Size(51, 20);
	this->label->TabIndex = 1;
	this->label->Text =text;
	this->Controls->Add(label);
}

protected:  System::Void OnPaint(PaintEventArgs^ e) override
{
	Graphics^ g = e->Graphics;
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

}

protected:
	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	~ButonRotund()
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
		this->Name = L"ButonRotund";
		this->Size = System::Drawing::Size(20, 20);
		this->ResumeLayout(false);

	}
#pragma endregion

private: System::Void Control_Click(System::Object^  sender, System::EventArgs^  e)
{
		this->OnClick(e);
}

private: System::Void PictureBox_OnMouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	pictureBox->Image = imagini->Images[1];
}

private: System::Void PictureBox_OnMouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	 pictureBox->Image = imagini->Images[0];
}

private: System::Void OnResize(System::Object^ sender, System::EventArgs^ e)
{
	this->pictureBox->Location = System::Drawing::Point(this->Size.Width - this->Size.Height, 1);
	this->pictureBox->Size = System::Drawing::Size(this->Size.Height, this->Size.Height);
}

};
