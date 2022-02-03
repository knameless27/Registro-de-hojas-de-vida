#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <string>

#define CLEAR "cls"

using namespace std;

class Registro
{
private:
	string cedula;
	string nombre;
	string codigo;

public:
	void ingresar();
	void retirar();
	void modificar();
	void listar();
	void menu();
};

void pausa();
void error();

// Menu general
void Registro::menu()
{
	int opc = 1;
	do
	{
		system(CLEAR);
		cout << "\n REGISTRO DE HOJAS DE VIDA" << endl
			 << endl;
		cout << "1. Ingresar Datos Agenda" << endl;
		cout << "2. Retirar Datos Agenda" << endl;
		cout << "3. Modificar Datos Agenda" << endl;
		cout << "4. Listar Datos Agenda " << endl;
		cout << "0. Salir del Menu" << endl
			 << endl;
		cout << "Digite Opcion :  ";
		cin >> opc;
		fflush(stdin);

		switch (opc)
		{
		case 1:
			ingresar();
			break;
		case 2:
			retirar();
			break;
		case 3:
			modificar();
			break;
		case 4:
			listar();
			break;
		default:
			cout << "Ingreso Opcion no valida ";
		}
	} while (opc != 0);
}

void Registro::ingresar()
{
	fstream arIngreso("ingreso.txt");
	string cedula, nombre1, nombre2, apellido1, apellido2, telefono, direccion, correo;
	int op2;

	if (!arIngreso.is_open())
	{
		arIngreso.open("ingreso.txt", ios::out);
	}
	
	cout << "\nCedula: ";
	getline(cin, cedula);
	cout << "\nPrimer nombre: ";
	getline(cin, nombre1);
	cout << "\nSegundo nombre: ";
	getline(cin, nombre2);
	cout << "\nPrimer apellido: ";
	getline(cin, apellido1);
	cout << "\nSegundo apellido: ";
	getline(cin, apellido2);
	cout << "\nTelefono: ";
	getline(cin, telefono);
	cout << "\nDireccion: ";
	getline(cin, direccion);
	cout << "\nCorreo electronico: ";
	getline(cin, correo);

	system(CLEAR);
	cout<<"\n1. Guardar registro \n2. Regresar\n"<<endl;
	cout<<"\nDigite una opcion: ";
	cin>>op2;

	if (op2==1)
	{
		arIngreso << "Cedula: " << cedula<<endl;
		arIngreso << "Primer nombre: " << nombre1<<endl;
		arIngreso << "Segundo nombre: " << nombre2<<endl;
		arIngreso << "Primer apellido: " << apellido1<<endl;
		arIngreso << "Segundo apellido: " << apellido2<<endl;
		arIngreso << "Telefono: " << telefono<<endl;
		arIngreso << "Direccion: " << direccion<<endl;
		arIngreso << "Correo electronico: " << correo<<endl;

		cout<<"\nRegistro guardado con exito!\n";
		system("pause");
		system(CLEAR);
	}
	arIngreso.close();
}

void Registro::retirar()
{
	cout << "chamaco pendejo";
}

void Registro::modificar()
{
	cout << "chamaco pendejo";
}

void Registro::listar()
{
	cout << "chamaco pendejo";
}

void pausa()
{
	cout << "Presiona Enter para continuar...";
	getch();
	system(CLEAR);
}

void error()
{
	cout << "No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
	cout << "la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
	cout << "clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}

int main()
{
	system("color 70");
	Registro inicio;
	inicio.menu();
}