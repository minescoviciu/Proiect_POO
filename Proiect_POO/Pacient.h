#pragma once
ref class Pacient
{
public:
	//constructori
	Pacient(System::Xml::XmlNode^);
	//getteri
	System::String^ getNume();
	System::String^ getPrenume();
	System::String^ getAndresa();
	System::String^ getEmail();
	System::String^ getNumarTelefon();
	System::String^ getSex();
	int getVarsta();
	int getCod();
	//setteri
	//void setDatePersonale(int, System::String^);
private:
	System::String^ nume;
	System::String^ prenume;
	System::String^ andresa;
	System::String^ email;
	System::String^ numarTelefon;
	System::String^ sex;
	int varsta;
	int cod;
};

