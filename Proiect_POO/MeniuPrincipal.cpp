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

	Application::Run(%form);
}
