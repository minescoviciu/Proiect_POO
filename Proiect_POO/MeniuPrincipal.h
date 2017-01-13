#pragma once
#include "AdaugaPacientUserControl.h"
#include "ButonCautare.h"
#include "PrelucrareImagine.h"
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
	using namespace MySql::Data::MySqlClient;
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
			imagini->Images->Add((Image^)rm->GetObject("rose3"));
		

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

			//System::String^ path = "F:\\Visual Studio\\Programe Temp\\POO\\Proiect_POO\\Imagini\\canapea1.jpg";
			//Image^ img = Image::FromFile(path);
			//imagini->Images->Add(img);
			//System::Diagnostics::Stopwatch^ timer = System::Diagnostics::Stopwatch::StartNew();
			////imaginea trebuie incarcata direct din fisier;
			///*PrelucrareImagine x(img);*/
			//timer->Stop();
			//label1->Text = timer->ElapsedMilliseconds.ToString();
			
			BazaDeDate();
			SQL_Acces^ x = gcnew SQL_Acces(CONNECTION_STRING);
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	public:

		DataSet^ x;

	public:
		
#define CONNECTION_STRING "datasource=localhost;port=3306;username=minescoviciu;password=root1234;"

	private: void ShowInDataGrid(MySqlCommand^ cmdDataBase)
	{
		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDataBase;
			DataTable^ dbDataSet = gcnew DataTable();
			sda->Fill(dbDataSet);
			BindingSource^ bSource = gcnew BindingSource();

			bSource->DataSource = dbDataSet;
			dataGridView1->DataSource = bSource;
			sda->Update(dbDataSet);
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void BazaDeDate()
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(CONNECTION_STRING);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from poo_db.pacienti;", conDataBase);

		ShowInDataGrid(cmdDataBase);

		dataGridView1->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;
		dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;

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

	private: System::Windows::Forms::Label^  label1;










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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonPacientNou
			// 
			this->buttonPacientNou->BackColor = System::Drawing::Color::Maroon;
			this->buttonPacientNou->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->buttonPacientNou->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->buttonPacientNou->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPacientNou->Location = System::Drawing::Point(453, 452);
			this->buttonPacientNou->Name = L"buttonPacientNou";
			this->buttonPacientNou->Size = System::Drawing::Size(64, 53);
			this->buttonPacientNou->TabIndex = 0;
			this->buttonPacientNou->Text = L"Nou";
			this->buttonPacientNou->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->buttonPacientNou->UseVisualStyleBackColor = false;
			this->buttonPacientNou->Click += gcnew System::EventHandler(this, &MeniuPrincipal::buttonPacientNou_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(265, 352);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Peru;
			this->pictureBox1->ImageLocation = L"F:\\Visual Studio\\Programe Temp\\POO\\Proiect_POO\\Imagini\\canapea1.jpg";
			this->pictureBox1->Location = System::Drawing::Point(427, 84);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 319);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MeniuPrincipal::pictureBox1_MouseDown);
			this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &MeniuPrincipal::pictureBox1_MouseLeave);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MeniuPrincipal::pictureBox1_MouseMove);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(169, 173);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(177, 140);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(119, 403);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(240, 150);
			this->dataGridView1->TabIndex = 4;
			// 
			// MeniuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightCoral;
			this->ClientSize = System::Drawing::Size(997, 581);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonPacientNou);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MeniuPrincipal";
			this->Text = L"MeniuPrincipal";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
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

	private: void Crop()
	{
		if (cropHeight < 1 || cropWidth < 1)
			return;
		Rectangle rect(cropStartX, cropStartY, cropWidth, cropHeight);
		Bitmap^ original = gcnew Bitmap(pictureBox1->Image, pictureBox1->Width, pictureBox1->Height);
		Bitmap^ crop = gcnew Bitmap(cropWidth, cropHeight);
		Graphics^ g = Graphics::FromImage(crop);

		g->CompositingMode = System::Drawing::Drawing2D::CompositingMode::SourceCopy;
		g->CompositingQuality = System::Drawing::Drawing2D::CompositingQuality::HighQuality;
		g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::HighQualityBicubic;
		g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::HighQuality;
		g->PixelOffsetMode = System::Drawing::Drawing2D::PixelOffsetMode::HighQuality;

		g->DrawImage(original, 0, 0, rect, System::Drawing::GraphicsUnit::Pixel);

		pictureBox2->Image = crop;
	}

	private: int cropStartX;
	private: int cropStartY;
	private: int cropWidth;
	private: int cropHeight;
	private: Pen^ CropPen;

	private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			Cursor = Cursors::Cross;
			cropStartX = e->X;
			cropStartY = e->Y;

			CropPen = gcnew Pen(Color::Red, 1);
			CropPen->DashStyle = System::Drawing::Drawing2D::DashStyle::DashDotDot;
		}
		pictureBox1->Refresh();
	}
	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		if (pictureBox1->Image == nullptr)
			return;
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			pictureBox1->Refresh();
			cropWidth = e->X - cropStartX;
			cropHeight = e->Y - cropStartY;

			pictureBox1->CreateGraphics()->DrawRectangle(CropPen, cropStartX, cropStartY, cropWidth, cropHeight);
		}
	}
	private: System::Void pictureBox1_MouseLeave(System::Object^  sender, System::EventArgs^  e) 
	{
		Cursor = Cursors::Arrow;
	}
};
}
