#pragma once
#include "Mamografie.h"
ref class Pacient
{
public:
	//constructori
	Pacient(System::String^ nume, System::String^ prenume, System::String^ andresa, System::String^ email, System::String^ numarTelefon, int varsta, int id);
	Pacient(const Pacient^&copie);
	//setei
	System::Void SetMamografii(array<Mamografie^>^ mamografii);
	//getteri
	System::String^ GetNume();
	System::String^ GetPrenume();
	System::String^ GetAndresa();
	System::String^ GetEmail();
	System::String^ GetNumarTelefon();
	array<Mamografie^>^ GetMamografii();
	int GetVarsta();
	int GetID();
	//metode
	System::Void AfisareInMessageBox();
private:
	System::String^ nume;
	System::String^ prenume;
	System::String^ andresa;
	System::String^ email; 
	System::String^ numarTelefon;
	int varsta;
	int id;
	array<Mamografie^>^ imagini_mamografii;
};

