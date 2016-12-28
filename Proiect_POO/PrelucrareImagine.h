#pragma once
ref class PrelucrareImagine
{
public:
	PrelucrareImagine(System::Drawing::Image^);
	System::Drawing::Image^ CeaMaiApropiataImagine();

private:
	//metode
	System::Void IncarcaCelelalteImagini();
	int DistantaHemming(System::Byte, System::Byte);
	array<System::Byte>^ VectorDinImagine(System::Drawing::Image^);
	array<System::Byte>^ VectorDinImagine(System::Drawing::Bitmap^);
	System::Drawing::Image^ ImagineDinVector(array<System::Byte>^);
	//variabile
	array<System::Byte>^ vectorBiti;
	array<System::Drawing::Image^>^ imagini;
};

