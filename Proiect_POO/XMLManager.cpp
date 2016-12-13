#include "XMLManager.h" 



XMLManager::XMLManager(System::String^ path)
{
	xmlFilePath = path;
}

System::String^ XMLManager::adaugaNodFaraCopii(System::String^ nume, System::String^ valoare)
{
	return "<" + nume + ">" + valoare + "</" + nume + ">";
}

int XMLManager::iaCodUtilizator()
{
	System::Xml::XmlDocument^ doc = gcnew System::Xml::XmlDocument;
	doc->Load(xmlFilePath);
	System::Xml::XmlNode^ elem = doc->DocumentElement->LastChild;
	elem = elem->LastChild;
	return System::Int32::Parse(elem->InnerText) + 1;
}

System::Void XMLManager::writeXml(System::String^ nume, System::String^ prenume, System::String^ adresa,
	System::String^ email, System::String^ numarTelefon, System::String^ sex, int varsta)
{
	//deschide fisierul XML "Pacienti.xml"
	System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(xmlFilePath);
	System::String^ linie;
	System::String^ textXML;
	while (linie = sr->ReadLine())
	{
		if (linie == "</pacienti>") //cand ajunge la ultima linie adauga urmatorul nod (pacient)
		{
			System::String^ s = adaugaNodFaraCopii("pacient", adaugaNodFaraCopii("nume", nume) + System::Environment::NewLine +
				adaugaNodFaraCopii("prenume", prenume) + System::Environment::NewLine +
				adaugaNodFaraCopii("email", email) + System::Environment::NewLine +
				adaugaNodFaraCopii("adresa", adresa) + System::Environment::NewLine +
				adaugaNodFaraCopii("numarTelefon", numarTelefon) + System::Environment::NewLine +
				adaugaNodFaraCopii("sex", sex) + System::Environment::NewLine +
				adaugaNodFaraCopii("varsta", varsta.ToString()) + System::Environment::NewLine +
				adaugaNodFaraCopii("cod", iaCodUtilizator().ToString()));
			textXML += s + System::Environment::NewLine + "</pacienti>";
		}
		else
		{
			textXML += linie + System::Environment::NewLine;
		}
	}
	sr->Close();
	//scrie fisierul XML din nou
	System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(xmlFilePath);
	sw->WriteLine(textXML);
	sw->Close();
}

