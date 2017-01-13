#include "Mamografie.h"
#include "PrelucrareImagine.h"


Mamografie::Mamografie(System::String^ locatieEcografie)
{
	this->path = locatieEcografie;
	System::Drawing::Image^ img = System::Drawing::Image::FromFile(path);
	PrelucrareImagine x(img);
	this->hash = x.GetHash();
	this->id_mamografie = 0;
	this->id_pacient = 0;
}

Mamografie::Mamografie(System::String ^ locatieEcografie, System::String ^ hash)
{
	this->path = locatieEcografie;
	this->hash = hash;
	this->id_mamografie = 0;
	this->id_pacient = 0;
}

Mamografie::Mamografie(System::String ^ locatieEcografie, System::String ^ hash, int id_mamografie, int id_pacient)
{
	this->path = locatieEcografie;
	this->hash = hash;
	this->id_mamografie = id_mamografie;
	this->id_pacient = id_pacient;
}

Mamografie::Mamografie(const Mamografie ^& copie)
{
	this->path = copie->path;
	this->hash = copie->hash;
	this->id_mamografie = copie->id_mamografie;
	this->id_pacient = copie->id_pacient;
}

System::Void Mamografie::AfisareInMessageBox()
{
	System::Windows::Forms::MessageBox::Show(id_mamografie + "id pacient: " + id_pacient.ToString() + " locatie: " + path + " hash: " + hash);
}

System::String ^ Mamografie::GetHash()
{
	return this->hash;
}

System::String ^ Mamografie::GetPath()
{
	return this->path;
}

int Mamografie::GetID()
{
	return this->id_mamografie;
}

int Mamografie::GetIdPacient()
{
	return this->id_pacient;
}
