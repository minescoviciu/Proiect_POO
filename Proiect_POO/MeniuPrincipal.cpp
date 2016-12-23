#include "XMLManager.h"
#include "MeniuPrincipal.h"
#include "Pacient.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Xml;
using namespace std;
[STAThread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ProiectPOO::MeniuPrincipal form;

	XmlDocument^ doc = gcnew XmlDocument;
	doc->Load("XMLPacienti.xml");

	XmlNode^ elem = doc->DocumentElement->FirstChild;

	elem = elem->NextSibling;

	Pacient x(elem);

	Console::WriteLine(x.getNume());

	Application::Run(%form);
}
