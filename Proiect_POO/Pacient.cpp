#include "Pacient.h" 


//constructori


Pacient::Pacient(System::String ^ nume, System::String ^ prenume, System::String ^ andresa, System::String ^ email, System::String ^ numarTelefon, int varsta, int id)
{
	this->nume = nume;
	this->prenume = prenume;
	this->andresa = andresa;
	this->email = email;
	this->numarTelefon = numarTelefon;
	this->varsta = varsta;
	this->id = id;
}

Pacient::Pacient(const Pacient ^& copie)
{
	this->nume = copie->nume;
	this->prenume = copie->prenume;
	this->andresa = copie->andresa;
	this->email = copie->email;
	this->numarTelefon = copie->numarTelefon;
	this->varsta = copie->varsta;
	this->id = copie->id;
}

System::Void Pacient::SetMamografii(array<Mamografie^>^ mamografii)
{
	this->imagini_mamografii = mamografii;
}

//geteri
System::String^ Pacient::GetNume()
{
	return this->nume;
}

System::String^ Pacient::GetPrenume()
{
	return this->prenume;
}

System::String^ Pacient::GetAndresa()
{
	return this->andresa;
}

System::String^ Pacient::GetEmail()
{
	return this->email;
}

System::String^ Pacient::GetNumarTelefon()
{
	return this->numarTelefon;
}

array<Mamografie^>^ Pacient::GetMamografii()
{
	return this->imagini_mamografii;
}

int Pacient::GetVarsta()
{
	return this->varsta;
}

int Pacient::GetID()
{
	return this->id;
}

System::Void Pacient::AfisareInMessageBox()
{
	System::Windows::Forms::MessageBox::Show(nume + " " + prenume + " adresa: " + andresa +
										" id: " +id.ToString() + " email: " + email + " telefon: " + numarTelefon + " varsta: " + varsta.ToString());
}
