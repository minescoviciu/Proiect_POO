#pragma once
ref class Mamografie
{
public:
	//constructori
	Mamografie(System::String^ locatieEcografie);
	Mamografie(System::String^ locatieEcografie, System::String^ hash);
	Mamografie(System::String^ locatieEcografie, System::String^ hash, int id_mamografie, int id_pacient);
	Mamografie(const Mamografie^& copie);
	System::Void AfisareInMessageBox();
	//geteri
	System::String^ GetHash();
	System::String^ GetPath();
	int GetID();
	int GetIdPacient();

private:
	System::String^ path;
	System::String^ hash;
	int id_mamografie;
	int id_pacient;
};

