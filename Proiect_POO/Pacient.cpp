#include "Pacient.h" 


//constructori
Pacient::Pacient(System::Xml::XmlNode^ element)
{
	if (element->Name == "pacient")
	{
		for (int i = 0; i < element->ChildNodes->Count; i++)
		{
			if (element->ChildNodes[i]->Name == "nume")
				this->nume = element->ChildNodes[i]->InnerText;
			else if (element->ChildNodes[i]->Name == "prenume")
				this->prenume = element->ChildNodes[i]->InnerText;
			else if (element->ChildNodes[i]->Name == "numarTelefon")
				this->numarTelefon = element->ChildNodes[i]->InnerText;
			else if (element->ChildNodes[i]->Name == "andresa")
				this->andresa = element->ChildNodes[i]->InnerText;
			else if (element->ChildNodes[i]->Name == "email")
				this->email = element->ChildNodes[i]->InnerText;
			else if (element->ChildNodes[i]->Name == "varsta")
				this->varsta = __int32::Parse(element->ChildNodes[i]->InnerText);
			else if (element->ChildNodes[i]->Name == "sex")
				this->sex = element->ChildNodes[i]->InnerText;
			else if (element->ChildNodes[i]->Name == "cod")
				this->cod = __int32::Parse(element->ChildNodes[i]->InnerText);
		}
	}
}

//geteri
System::String^ Pacient::getNume()
{
	return this->nume;
}

System::String^ Pacient::getPrenume()
{
	return this->prenume;
}

System::String^ Pacient::getAndresa()
{
	return this->andresa;
}

System::String^ Pacient::getEmail()
{
	return this->email;
}

System::String^ Pacient::getNumarTelefon()
{
	return this->numarTelefon;
}

System::String^ Pacient::getSex()
{
	return this->sex;
}

int Pacient::getVarsta()
{
	return this->varsta;
}

int Pacient::getCod()
{
	return this->cod;
}