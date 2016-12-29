#include "PrelucrareImagine.h"

#define PI 3.14159265359
#define SIZESMALL 8
#define SIZELONG 32

PrelucrareImagine::PrelucrareImagine(System::Drawing::Image^ imagine)
{
	IncarcaCelelalteImagini();
	//System::String^ path = "F:\\Visual Studio\\Programe Temp\\POO\\Proiect_POO\\Imagini\\lala.jpg";
	//lkl
	biti64 = CreareBiti(imagine);
	CeaMaiApropiataImagine();
}

System::Void PrelucrareImagine::CeaMaiApropiataImagine()
{
	int k = 0;
	for (int i = 0; i < imagini->Length; i++)
	{
		System::UInt64 bitiImagineDeComparat= CreareBiti(imagini[i]);
		int distanta = DistantaHemming(biti64, bitiImagineDeComparat);
		if (distanta < 15)
		{
			k++;
			float procent = ((64.0f - (float)distanta) / 64.0f) * 100;
			System::String^ path = "F:\\Visual Studio\\Programe Temp\\POO\\Proiect_POO\\Imagini\\"+ procent + "%" + k +".jpg";
			imagini[i]->Save(path);
		}
	}
}

System::Void PrelucrareImagine::IncarcaCelelalteImagini()
{
	array<System::String^>^fileEntries = System::IO::Directory::GetFiles(System::IO::Directory::GetCurrentDirectory() + "\\img");
	System::Collections::IEnumerator^ files = fileEntries->GetEnumerator();
	imagini = gcnew array<System::Drawing::Image^>(fileEntries->Length);
	int i = 0;
	while (files->MoveNext())
	{
		System::String^ fileName = safe_cast<System::String^>(files->Current);
		System::Drawing::Image^ imagine = dynamic_cast<System::Drawing::Image^>(System::Drawing::Image::FromFile(fileName,true));
		imagini[i] = imagine;
		i++;
	}
}

int PrelucrareImagine::DistantaHemming(System::UInt64 x, System::UInt64 y)
{
	int distanta = 0;
	System::UInt64 val = x^y;
	while (val)
	{
		distanta++;
		val &= val - 1;
	}
	return distanta;
}

System::Drawing::Bitmap ^ PrelucrareImagine::RedimensionareImagine(System::Drawing::Image^ imagine, int size)
{
	System::Drawing::Bitmap^ img = gcnew System::Drawing::Bitmap(imagine);
	for (int i = 0; i < imagine->Width; i++)
	{
		for (int j = 0; j < imagine->Height; j++)
		{
			System::Drawing::Color culoareInitiala = img->GetPixel(i, j);
			int grayScale = (int)((culoareInitiala.R * 0.3) + (culoareInitiala.G * 0.59) + (culoareInitiala.B * 0.11));
			System::Drawing::Color culoareNoua = System::Drawing::Color::FromArgb(grayScale, grayScale, grayScale);
			img->SetPixel(i, j, culoareNoua);
		}
	}

	System::Drawing::Bitmap^ destImg = gcnew System::Drawing::Bitmap(size, size);
	System::Drawing::Rectangle destRect(0, 0, size, size);
	
	destImg->SetResolution(img->HorizontalResolution, img->VerticalResolution);

	System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(destImg);
	g->CompositingMode = System::Drawing::Drawing2D::CompositingMode::SourceCopy;
	g->CompositingQuality = System::Drawing::Drawing2D::CompositingQuality::HighQuality;
	g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::HighQualityBicubic;
	g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::HighQuality;
	g->PixelOffsetMode = System::Drawing::Drawing2D::PixelOffsetMode::HighQuality;

	System::Drawing::Imaging::ImageAttributes^ wrapMode = gcnew System::Drawing::Imaging::ImageAttributes();
	wrapMode->SetWrapMode(System::Drawing::Drawing2D::WrapMode::TileFlipXY);

	g->DrawImage(img, destRect, 0, 0,img->Width, img->Height,  System::Drawing::GraphicsUnit::Pixel, wrapMode);

	

	return destImg;
}

double PrelucrareImagine::ValoareMedie(array<double, 2>^ matrice)
{
	double medie = 0;
	for (int i = 0; i < SIZESMALL; i++)
	{
		for (int j = 0; j < SIZESMALL; j++)
		{
			medie += matrice[i,j];
		}
	}
	medie -= matrice[0, 0];
	medie = (double)(medie / (SIZESMALL - 1));
	return medie;
}
//SIZELONG
System::UInt64 PrelucrareImagine::CreareBiti(System::Drawing::Image ^img)
{
	System::Drawing::Bitmap^ imagine = RedimensionareImagine(img, SIZELONG);
	array<double, 2>^ matrice8x8 = Obtine8x8dinDCT(imagine);
	//array<double, 2>^ matrice8x8 = Obtine8x8dinImagine(imagine);
	System::UInt64 biti = 0;
	double medie = ValoareMedie(matrice8x8);
	for (int i = 0; i < SIZESMALL; i++)
	{
		for (int j = 0; j < SIZESMALL; j++)
		{
			if (medie < matrice8x8[i,j])
			{
				int k = i* SIZESMALL + j;
				System::UInt64 aux = 1;
				aux = aux << k;
				biti = biti | aux;
			}
		}
	}
	return biti;
}

array<double, 2>^ PrelucrareImagine::ObtineDCT(array<double, 2>^ matriceInitiala, int SIZE)
{
	array<double, 1>^ coeficienti = gcnew array<double, 1>(SIZE);
	array<double, 2>^ matrice = gcnew array<double, 2>(SIZE, SIZE);
	double radicalSizePatrat = System::Math::Sqrt(SIZE * SIZE);

	coeficienti[0] = 1 / System::Math::Sqrt(2.0);
	for (int i = 1; i < SIZE; i++)
	{
		coeficienti[i] = 1;
	}

	for (int u = 0; u < SIZE; u++)
	{
		for (int v = 0; v < SIZE; v++)
		{
			double sum = 0.0;
			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < SIZE; j++)
				{
					sum += System::Math::Cos(((2.0*i + 1) / (2.0*SIZE))*u*PI) *  System::Math::Cos(((2.0*j + 1) / (2.0*SIZE))*v*PI) * matriceInitiala[i, j];
				}
			}
			double aux = 2 * coeficienti[u] * coeficienti[v] / radicalSizePatrat;
			sum *= aux;
			//sum *= coeficienti[u] * coeficienti[v] / 4.0;
			matrice[u,v] = sum;
		}
	}
	return matrice;
}

array<int, 2>^ PrelucrareImagine::ObtineIDCT(array<double, 2>^ matriceInitiala, int SIZE)
{
	array<double, 1>^ coeficienti = gcnew array<double, 1>(SIZE);
	array<int, 2>^ matrice = gcnew array<int, 2>(SIZE, SIZE);

	coeficienti[0] = 1 / System::Math::Sqrt(2);
	for (int i = 1; i < SIZE; i++)
	{
		coeficienti[i] = 1;
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			double sum = 0.0;
			for (int u = 0; u < SIZE; u++)
			{
				for (int v = 0; v < SIZE; v++)
				{
					double aux = 2 * coeficienti[u] * coeficienti[v] / SIZE;
					sum += aux * System::Math::Cos(((2.0*i + 1) / (2.0*SIZE))*u*PI) *  System::Math::Cos(((2.0*j + 1) / (2.0*SIZE))*v*PI) * matriceInitiala[u,v];
				}
			}
			matrice[i, j] = (int)sum + 1;
		}
	}
	return matrice;
}

array<double, 2>^ PrelucrareImagine::Obtine8x8dinDCT(System::Drawing::Bitmap^ img)
{
	array<double, 2>^ matriceDCT = gcnew array<double, 2>(SIZELONG, SIZELONG);
	array<double, 2>^ matriceInitiala = gcnew array<double, 2>(SIZELONG, SIZELONG);
	for (int i = 0; i < SIZELONG; i++)
	{
		for (int j = 0; j < SIZELONG; j++)
		{
			matriceDCT[i, j] = img->GetPixel(i, j).R;
			matriceInitiala[i,j] = img->GetPixel(i, j).R;
		}
	}
	matriceDCT = ObtineDCT(matriceDCT, SIZELONG);
	//array<int, 2>^ IDCT = ObtineIDCT(matriceDCT, SIZELONG);
	return matriceDCT;
}

array<double, 2>^ PrelucrareImagine::Obtine8x8dinImagine(System::Drawing::Bitmap ^ img)
{
	array<double, 2>^ matrice = gcnew array<double, 2>(SIZESMALL, SIZESMALL);
	for (int i = 0; i < SIZESMALL; i++)
	{
		for (int j = 0; j < SIZESMALL; j++)
		{
			matrice[i, j] = img->GetPixel(i, j).R;
		}
	}
	return matrice;
}
