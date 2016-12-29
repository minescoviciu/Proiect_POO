#pragma once
ref class PrelucrareImagine
{
public:
	PrelucrareImagine(System::Drawing::Image^);
	System::Void CeaMaiApropiataImagine();

private:
	//metode
	System::Void IncarcaCelelalteImagini();
	int PrelucrareImagine::DistantaHemming(System::UInt64, System::UInt64);
	System::Drawing::Bitmap^ RedimensionareImagine(System::Drawing::Image^, int);
	// face imaginea gri si o redimensioneaza
	double ValoareMedie(array<double,2>^);
	System::UInt64 CreareBiti(System::Drawing::Image^);
	array<double, 2>^ ObtineDCT(array<double, 2>^, int);
	array<int, 2>^ ObtineIDCT(array<double, 2>^, int);
	array<double, 2>^ Obtine8x8dinDCT(System::Drawing::Bitmap^);
	array<double, 2>^ Obtine8x8dinImagine(System::Drawing::Bitmap^);
	//variabile
	System::UInt64 biti64;
	array<System::Drawing::Image^>^ imagini;
	System::Drawing::Bitmap^ imagineInitiala;
};

