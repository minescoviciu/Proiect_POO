#include "SQL_Acces.h"

using namespace MySql::Data::MySqlClient;

SQL_Acces::SQL_Acces(System::String^ connection_string)
{
	CONNECTION_STRING = connection_string;
}

System::Void SQL_Acces::AdaugaPacient(System::String ^ nume, System::String ^ prenume, System::String ^ adresa,
				System::String ^ email, System::String ^ numarTelefon, System::String ^ sex, int varsta)
{
	System::String^ date ="'" + nume + "','" + prenume + "','" + adresa + "','" + email + "','" + numarTelefon + "'," + varsta.ToString() + ",'" + sex + "'";	
	MySqlConnection^ conDataBase = gcnew MySqlConnection(CONNECTION_STRING);
	System::String^ command =  "INSERT INTO poo_db.pacienti (nume,prenume,adresa,email,nr_telefon,varsta,sex) VALUES (" + date + ");";
	MySqlCommand^ cmdInsert = gcnew MySqlCommand( command, conDataBase);
	InsertCommand(cmdInsert, conDataBase);
}

System::Void SQL_Acces::AdaugaImagine(int id_pacient, System::String ^ hash_cod, System::String ^ locatie)
{
	System::String^ date = id_pacient + ",'" + hash_cod + "','" + locatie + "'" ;
	MySqlConnection^ conDataBase = gcnew MySqlConnection(CONNECTION_STRING);
	MySqlCommand^ cmdInsert = gcnew MySqlCommand("INSERT INTO poo_db.imagini (id_pacient,hash_cod,locatie) VALUES (" + date + ");", conDataBase);
	InsertCommand(cmdInsert, conDataBase);
}

System::Void SQL_Acces::AdaugaImagine(System::String ^ numePacient, System::String ^ prenumePacient, System::String ^ hash_cod, System::String ^ locatie)
{
	int id_pacient = GetPacientID(numePacient, prenumePacient);
	AdaugaImagine(id_pacient, hash_cod, locatie);
}

Pacient^ SQL_Acces::GetPacient(System::String ^ numePacient, System::String ^ prenumePacient)
{
	int DIMENSIUNE = 3;
	array<System::String^>^ atribute = gcnew array<System::String^>{"adresa", "email", "nr_telefon"};
	array<System::String^>^ atributeLuate = gcnew array<System::String^>(DIMENSIUNE);

	int varsta = 0;
	int id_pacient = 0;

	try
	{
		MySqlConnection^ connection = gcnew MySqlConnection(CONNECTION_STRING);
		connection->Open();

		for (int i = 0; i < DIMENSIUNE; i++)
		{
			System::String^ command = "SELECT " + atribute[i] + " FROM poo_db.pacienti WHERE nume='" + numePacient + "' and prenume='" + prenumePacient + "';";
			MySqlCommand^ cmdSelect = gcnew MySqlCommand(command, connection);
			MySqlDataReader^ reader;

			
			reader = cmdSelect->ExecuteReader();
			reader->Read();

			atributeLuate[i] = reader->GetValue(0)->ToString();

			reader->Close();
		}

		System::String^ command = "SELECT id_pacient, varsta FROM poo_db.pacienti WHERE nume='" + numePacient + "' and prenume='" + prenumePacient + "';";
		MySqlCommand^ cmdSelect = gcnew MySqlCommand(command, connection);
		MySqlDataReader^ reader;

		reader = cmdSelect->ExecuteReader();
		reader->Read();

		id_pacient = (int)reader->GetValue(0);
		varsta = (int)reader->GetValue(1);

		reader->Close();
		connection->Close();
	}
	catch (System::Exception^ e)
	{
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	Pacient^ x = gcnew Pacient(numePacient, prenumePacient, atributeLuate[0], atributeLuate[1], atributeLuate[2], varsta, id_pacient);
	return x;

}

array<Mamografie^>^  SQL_Acces::GetMamografii(System::String ^ numePacient, System::String ^ prenumePacient)
{
	int id_pacient = GetPacientID(numePacient,prenumePacient);
	array<Mamografie^>^ mamografii = GetMamografii(id_pacient);
	return mamografii;
}

array<Mamografie^>^  SQL_Acces::GetMamografii(int id_pacient)
{
	try
	{
		int DIMENSIUNE = 2;
		array<System::String^>^ atribute = gcnew array<System::String^>{"locatie", "hash_cod"};
		int cateMamografiAuFostGasite = 0;

		//conectare la data de baze

		MySqlConnection^ connection = gcnew MySqlConnection(CONNECTION_STRING);
		connection->Open();

		// vedem cate mamografii are pacientul cu id-ul respectiv

		System::String^ command = "SELECT COUNT(id_imagine) FROM poo_db.imagini WHERE id_pacient = " + id_pacient.ToString() + ";";
		MySqlCommand^ cmdSelect = gcnew MySqlCommand(command, connection);
		MySqlDataReader^ reader;
		reader = cmdSelect->ExecuteReader();
		reader->Read();

		cateMamografiAuFostGasite = reader->GetInt32(0);

		reader->Close();
		//declarara matricei unde vor fi stocate datele pt crearea obiectelor de tipul "mamografie"

		array<System::String^,2>^ atributeLuate = gcnew array<System::String^,2>(DIMENSIUNE,cateMamografiAuFostGasite);
		array<int>^ iduri_mamografii = gcnew array<int>(cateMamografiAuFostGasite);
		
		//selectarea locatiei si hash-ului dupa id-ul pacientului, se pun intr-o matrice de 2xcate;
		
		for (int i = 0; i < DIMENSIUNE; i++)
		{
			System::String^ command = "SELECT " + atribute[i] + " FROM poo_db.imagini WHERE id_pacient =" + id_pacient.ToString() + ";";
			MySqlCommand^ cmdSelect = gcnew MySqlCommand(command, connection);
			MySqlDataReader^ reader;
			reader = cmdSelect->ExecuteReader();

			for (int j = 0; j < cateMamografiAuFostGasite; j++)
			{
				reader->Read();
				atributeLuate[i, j] = reader->GetValue(0)->ToString();
			}
			reader->Close();
		}

		// selectarea id-ului mamografiei

		command = "SELECT id_imagine FROM poo_db.imagini WHERE id_pacient =" + id_pacient.ToString() + ";";
		cmdSelect = gcnew MySqlCommand(command, connection);
		reader = cmdSelect->ExecuteReader();

		for (int j = 0; j < cateMamografiAuFostGasite; j++)
		{
			reader->Read();
			iduri_mamografii[j] = (int)reader->GetValue(0);
		}

		reader->Close();
		connection->Close();
		
		//creaza mamografiile din interogari
		array<Mamografie^>^ deReturnat = gcnew array<Mamografie^>(cateMamografiAuFostGasite);
		for (int i = 0; i < cateMamografiAuFostGasite; i++)
		{
			deReturnat[i] = gcnew Mamografie(atributeLuate[0,i], atributeLuate[1,i], iduri_mamografii[i], id_pacient);
		}

		return deReturnat;
	}
	catch (System::Exception^ e)
	{
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
}

System::Void SQL_Acces::InsertCommand(MySql::Data::MySqlClient::MySqlCommand ^ command, MySql::Data::MySqlClient::MySqlConnection^ connection)
{
	MySqlDataReader^ reader;
	try
	{
		connection->Open();
		reader = command->ExecuteReader();
		reader->Read();
		reader->Close();
		connection->Close();
	}
	catch (System::Exception^ e)
	{
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
}

int SQL_Acces::GetPacientID(System::String ^ nume, System::String ^ prenume)
{
	int id = 0;
	try
	{
		MySqlConnection^ connection = gcnew MySqlConnection(CONNECTION_STRING);
		System::String^ command = "SELECT id_pacient FROM poo_db.pacienti WHERE nume='" + nume + "' and prenume='" + prenume + "';";
		MySqlCommand^ cmdSelect = gcnew MySqlCommand(command, connection);
		MySqlDataReader^ reader;

		connection->Open();
		reader = cmdSelect->ExecuteReader();
		reader->Read();
		id = (int)reader->GetValue(0);
		reader->Close();
		connection->Close();
	}
	catch (System::Exception^ e)
	{
		System::Windows::Forms::MessageBox::Show(e->Message);
	}

	return id;
}
