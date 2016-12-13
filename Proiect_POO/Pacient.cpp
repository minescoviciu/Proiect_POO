#include "Pacient.h" 


//constructori
pacient::pacient(System::Xml::XmlNode^ element)
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
System::String^ pacient::getNume()
{
	return this->nume;
}

System::String^ pacient::getPrenume()
{
	return this->prenume;
}

System::String^ pacient::getAndresa()
{
	return this->andresa;
}

System::String^ pacient::getEmail()
{
	return this->email;
}

System::String^ pacient::getNumarTelefon()
{
	return this->numarTelefon;
}

System::String^ pacient::getSex()
{
	return this->sex;
}

int pacient::getVarsta()
{
	return this->varsta;
}

int pacient::getCod()
{
	return this->cod;
}