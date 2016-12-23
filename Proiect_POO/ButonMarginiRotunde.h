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

private: Color culoareBackGround;
public:

	ButonRotund(void)
	{
		InitializeComponent();

	}

	ButonRotund(Color culoare)
	{
		InitializeComponent();
		this->BackColor = Color::Transparent;
		this->culoareBackGround = culoare;
	}

protected:  System::Void OnPaint(PaintEventArgs^ e) override
{
	Graphics^ g = e->Graphics;
	SolidBrush^ sb = gcnew SolidBrush(culoareBackGround);
	g->FillEllipse(sb, 0, 0, this->Size.Width, this->Size.Height);
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
		this->Size = System::Drawing::Size(200, 20);
		this->ResumeLayout(false);

	}
#pragma endregion

private: System::Void Control_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->OnClick(e);
}
};

