#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstdlib>

using namespace std;

class Registro
{
private:
	string cedula, nombre1, nombre2, apellido1, apellido2, telefono, direccion, correo;

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
		system("cls");
		cout << "\n REGISTRO DE HOJAS DE VIDA" << endl
			 << endl;
		cout << "1. Ingresar Datos Agenda" << endl;
		cout << "2. Retirar Datos Agenda" << endl;
		cout << "3. Modificar Datos Agenda" << endl;
		cout << "4. Listar Datos Agenda " << endl;
		cout << "5. Salir del Menu" << endl
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
		case 5:
			opc = 5;
			system("cls");
			break;
		default:
			cout << "Ingreso Opcion no valida ";
		}
	} while (opc != 5);
}

void Registro::ingresar()
{
	ofstream arIngreso;
	string aux_cedula;
	string aux_nombre1;
	string aux_nombre2;
	string aux_apellido1;
	string aux_apellido2;
	string aux_telefono;
	string aux_direccion;
	string aux_correo;

	arIngreso.open("ingreso.txt", ios::app);

	if (arIngreso.is_open())
	{
		cout << "\nCedula: ";
		getline(cin, aux_cedula);
		cout << "\nPrimer nombre: ";
		getline(cin, aux_nombre1);
		cout << "\nSegundo nombre: ";
		getline(cin, aux_nombre2);
		cout << "\nPrimer apellido: ";
		getline(cin, aux_apellido1);
		cout << "\nSegundo apellido: ";
		getline(cin, aux_apellido2);
		cout << "\nTelefono: ";
		getline(cin, aux_telefono);
		cout << "\nDireccion: ";
		getline(cin, aux_direccion);
		cout << "\nCorreo electronico: ";
		getline(cin, aux_correo);
	}
	arIngreso << endl
			  << aux_cedula << endl
			  << aux_nombre1 << endl
			  << aux_nombre2 << endl
			  << aux_apellido1 << endl
			  << aux_apellido2 << endl
			  << aux_telefono << endl
			  << aux_direccion << endl
			  << aux_correo;
	cout << "\nRegistro guardado con exito!\n";
	system("pause");
	system("cls");

	arIngreso.close();
}

void Registro::retirar()
{
	system("cls");

	ifstream arRetirar;
	ofstream aux;

	bool encontrado = false;

	string auxCedula;
	string respuesta;

	arRetirar.open("ingreso.txt", ios::in);
	aux.open("auxiliar.txt", ios::out);

	cout << "\t\t\t\tEliminar un registro\t\t\t\t\n\n";
	if (arRetirar.is_open() && aux.is_open())
	{
		cout << "Ingresa la cedula de la persona que desea eliminar: ";
		getline(cin, auxCedula);

		arRetirar>>cedula;
		while (!arRetirar.eof())
		{
			getline(arRetirar, nombre1);
			getline(arRetirar, nombre2);
			getline(arRetirar, apellido1);
			getline(arRetirar, apellido2);
			getline(arRetirar, telefono);
			getline(arRetirar, direccion);
			getline(arRetirar, correo);

			if (auxCedula == cedula)
			{
				encontrado = true;
				cout << "\n\nRegistro Encontrado\n\n";
				cout << "Cedula : " << cedula << endl;
				cout << "Primer nombre : " << nombre1 << endl;
				cout << "Segundo nombre : " << nombre2 << endl;
				cout << "Primer apellido : " << apellido1 << endl;
				cout << "Segundo apellido : " << apellido2 << endl;
				cout << "Telefono : " << telefono << endl;
				cout << "Direccion : " << direccion << endl;
				cout << "Correo : " << correo << endl
					 << endl;

				cout << "Realmente deseas eliminar a esta persona?  (s/n)?: ";
				getline(cin, respuesta);

				if (respuesta == "s" || respuesta == "si" || respuesta == "Si" || respuesta == "sI" || respuesta == "i")
				{
					cout << "\n\nSe ha eliminado la persona\n\n";
					system("pause");
				}
				else
				{
					cout << "\n\nCliente conservado\n\n";
					aux << cedula << endl
						<< nombre1 << endl
						<< nombre2 << endl
						<< apellido1 << endl
						<< apellido2 << endl
						<< telefono << endl
						<< direccion << endl
						<< correo<<endl;
					system("pause");
				}
			}
			else
			{
				aux << cedula << endl
					<< nombre1 << endl
					<< nombre2 << endl
					<< apellido1 << endl
					<< apellido2 << endl
					<< telefono << endl
					<< direccion << endl
					<< correo << endl;
			}
			getline(arRetirar, cedula);
		}
		if (encontrado == false)
		{
			cout << "\n\nNo se encontr\242 la cedula: " << auxCedula << "\n\n";
			system("pause");
		}
	}
	else
	{
		error();
	}
	arRetirar.close();
	aux.close();
	remove("ingreso.txt");
	rename("auxiliar.txt", "ingreso.txt");
}

void Registro::modificar()
{
	system("cls");

	string cedaux; // declaro variables auxiliares
	string cedaux2;
	bool encontrado = false;

	fstream arModif; // creo la wea de fstream para modificar ingreso
	ofstream aux;	 // aqui abro y creo una variable ofstream para escritura

	arModif.open("ingreso.txt", ios::in); // aqui la abro y le digo que la voy a usar solo para lectura
	aux.open("auxiMod.txt", ios::out);

	if (arModif.is_open() && aux.is_open())
	{
		cout << "cedula a buscar: ";
		cin >> cedaux;

		arModif >> cedula;
		while (!arModif.eof())
		{
			getline(arModif, nombre1);
			getline(arModif, nombre2);
			getline(arModif, apellido1);
			getline(arModif, apellido2);
			getline(arModif, telefono);
			getline(arModif, direccion);
			getline(arModif, correo);
			if (cedaux == cedula)
			{
				encontrado=true;
				cout << "la nueva cedula pa: ";
				cin >> cedaux2;
				aux << endl
					<< cedaux2 << nombre1
					<< endl
					<< nombre2 << endl
					<< apellido1 << endl
					<< apellido2 << endl
					<< telefono << endl
					<< direccion << endl
					<< correo << endl;
				cout << "cedula guardada correctamente!"<<endl;
				system("pause");
			}
			else
			{
				aux << cedula << endl
					<< nombre1 << endl
					<< nombre2 << endl
					<< apellido1 << endl
					<< apellido2 << endl
					<< telefono << endl
					<< direccion << endl
					<< correo << endl;
			}
			getline(arModif,cedula);
		}
		if (encontrado==false)
		{
			cout<<"no se ha encontrado la cedula "<<cedaux<<endl;
			system("pause");
		}
		

		arModif.close();
		aux.close();
	}
	else
	{
		error;
	}
	remove("ingreso.txt");
	rename("auxiMod.txt", "ingreso.txt");
}

void Registro::listar()
{
	system("cls");

	ifstream arListar;
	arListar.open("ingreso.txt", ios::in);

	getline(arListar, cedula);
	if (arListar.is_open())
	{
		getline(arListar, cedula);

		while (!arListar.eof())
		{
			getline(arListar, nombre1);
			getline(arListar, nombre2);
			getline(arListar, apellido1);
			getline(arListar, apellido2);
			getline(arListar, telefono);
			getline(arListar, direccion);
			getline(arListar, correo);

			cout << "----------------------------" << endl;
			cout << "Cedula: " << cedula << endl;
			cout << "Primer nombre: " << nombre1 << endl;
			cout << "Segundo nombre: " << nombre2 << endl;
			cout << "Primer apellido: " << apellido1 << endl;
			cout << "Segundo apellido: " << apellido2 << endl;
			cout << "Telefono: " << telefono << endl;
			cout << "Direccion: " << direccion << endl;
			cout << "Correo: " << correo << endl;
			cout << "----------------------------" << endl;
			cout << endl;

			getline(arListar, cedula);
		}
	}
	arListar.close();
	system("pause");
}

void error()
{
	cout << "Hubo un error xd\n";
	system("pause");
}

int main()
{
	system("color 70");
	Registro inicio;
	inicio.menu();
}