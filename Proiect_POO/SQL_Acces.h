#pragma once
#include "Pacient.h"
#include "Mamografie.h"

ref class SQL_Acces
{
public:
	SQL_Acces(System::String^ connection_string);
	System::Void AdaugaPacient(System::String^ nume, System::String^ prenume, System::String^ adresa,
		System::String^ email, System::String^ numarTelefon, System::String^ sex, int varsta);
	System::Void AdaugaImagine(int id_pacient, System::String^ hash_cod,
		System::String^ locatie);
	System::Void AdaugaImagine(System::String^ numePacient, System::String^ prenumePacient, System::String^ hash_code,
		System::String^ locatie);
	Pacient^ GetPacient(System::String^ numePacient, System::String^ prenumePacient);
	array<Mamografie^>^  GetMamografii(System::String^ numePacient, System::String^ prenumePacient);
	array<Mamografie^>^ GetMamografii(int id_pacient);
	

private:
	//variabile
	System::String^ CONNECTION_STRING;
	System::Void InsertCommand(MySql::Data::MySqlClient::MySqlCommand^ command, MySql::Data::MySqlClient::MySqlConnection^ connection);
	//metode
	int GetPacientID(System::String^ nume, System::String^ prenume);
};

