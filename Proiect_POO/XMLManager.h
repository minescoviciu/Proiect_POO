#pragma once
ref class XMLManager
{
public:
	//metode
	XMLManager(System::String^);
	System::Void writeXml(System::String^ nume, System::String^ prenume, System::String^ adresa,
		System::String^ email, System::String^ numarTelefon, System::String^ sex,
		int varsta);
private:
	//metode
	System::String^ adaugaNodFaraCopii(System::String^ nume, System::String^ valoare);
	int iaCodUtilizator();
	//variabile 
	System::String^ xmlFilePath;
};

