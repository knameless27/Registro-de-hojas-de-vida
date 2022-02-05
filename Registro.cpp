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
		system(CLEAR);
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
			opc = 0;
			system(CLEAR);
			break;
		default:
			cout << "Ingreso Opcion no valida ";
		}
	} while (opc != 0);
}

void Registro::ingresar()
{
	fstream arIngreso("ingreso.txt");
	int op2;

	if (!arIngreso.is_open())
	{
		arIngreso.open("ingreso.txt", ios::out | ios::app); // el app, es pa que lo cree si no existe
	}

	system(CLEAR);
	cout << "\nCedula: ";
	cin >> cedula;
	cout << "\nPrimer nombre: ";
	cin >> nombre1;
	cout << "\nSegundo nombre: ";
	cin >> nombre2;
	cout << "\nPrimer apellido: ";
	cin >> apellido1;
	cout << "\nSegundo apellido: ";
	cin >> apellido2;
	cout << "\nTelefono: ";
	cin >> telefono;
	cout << "\nDireccion: ";
	cin >> direccion;
	cout << "\nCorreo electronico: ";
	cin >> correo;

	system(CLEAR);
	cout << "\n1. Guardar registro \n2. Regresar\n"
		 << endl;
	cout << "\nDigite una opcion: ";
	cin >> op2;

	if (op2 == 1)
	{
		arIngreso << " " << cedula << " " << nombre1 << " " << nombre2 << " " << apellido1 << " " << apellido2 << " " << telefono << " " << direccion << " " << correo << endl;

		cout << "\nRegistro guardado con exito!\n";
		system("pause");
		system(CLEAR);
	}
	arIngreso.close();
}

void Registro::retirar()
{
	system("cls");

	string key = "";
	bool encontrado = false;
	int opc = 1;

	fstream arRetirar("ingreso.txt");
	ofstream tempo("auxiliar.txt");

	do
	{
		system(CLEAR);
		cout << "\n Elija el dato a retirar" << endl
			 << endl;
		cout << "1. Cedula" << endl;
		cout << "2. Primer nombre" << endl;
		cout << "3. Segundo nombre" << endl;
		cout << "4. Primer apellido " << endl;
		cout << "5. Segundo apellido " << endl;
		cout << "6. Telefono " << endl;
		cout << "7. Direccion " << endl;
		cout << "8. Correo" << endl;
		cout << "9. Salir del Menu" << endl
			 << endl;
		cout << "Digite Opcion :  ";
		cin >> opc;
		fflush(stdin);

		switch (opc)
		{
		case 1:
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
			fflush(stdin);

			cout << "Ingrese clave a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> cedula;
				if (cedula == key)
				{
					encontrado = true;
					cout << "Cedula:	" << cedula << endl;
					cout << "Cedula eliminada exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo << nombre1 << " " << nombre2 << " " << apellido1 << " " << apellido2 << " " << telefono << " " << direccion << " " << correo << " " << cedula << endl;
				}
				arRetirar >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
				arRetirar << "Primer nombre: " << nombre1 << endl;
				arRetirar << "Segundo nombre: " << nombre2 << endl;
				arRetirar << "Primer apellido: " << apellido1 << endl;
				arRetirar << "Segundo apellido: " << apellido2 << endl;
				arRetirar << "Telefono: " << telefono << endl;
				arRetirar << "Direccion: " << direccion << endl;
				arRetirar << "Correo electronico: " << correo << endl;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 2:
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
			fflush(stdin);

			cout << "Ingrese clave a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> cedula;
				if (cedula == key)
				{
					encontrado = true;
					cout << "Cedula:	" << cedula << endl;
					cout << "Cedula eliminada exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo << cedula << " " << nombre2 << " " << apellido1 << " " << apellido2 << " " << telefono << " " << direccion << " " << correo << " " << cedula << endl;
				}
				arRetirar >> cedula >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
				arRetirar << "Primer nombre: " << nombre1 << endl;
				arRetirar << "Segundo nombre: " << nombre2 << endl;
				arRetirar << "Primer apellido: " << apellido1 << endl;
				arRetirar << "Segundo apellido: " << apellido2 << endl;
				arRetirar << "Telefono: " << telefono << endl;
				arRetirar << "Direccion: " << direccion << endl;
				arRetirar << "Correo electronico: " << correo << endl;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 3:
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
			fflush(stdin);

			cout << "Ingrese clave a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> cedula;
				if (cedula == key)
				{
					encontrado = true;
					cout << "Cedula:	" << cedula << endl;
					cout << "Cedula eliminada exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo << nombre1 << " " << nombre2 << " " << apellido1 << " " << apellido2 << " " << telefono << " " << direccion << " " << correo << " " << cedula << endl;
				}
				arRetirar >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
				arRetirar << "Primer nombre: " << nombre1 << endl;
				arRetirar << "Segundo nombre: " << nombre2 << endl;
				arRetirar << "Primer apellido: " << apellido1 << endl;
				arRetirar << "Segundo apellido: " << apellido2 << endl;
				arRetirar << "Telefono: " << telefono << endl;
				arRetirar << "Direccion: " << direccion << endl;
				arRetirar << "Correo electronico: " << correo << endl;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 4:
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
			fflush(stdin);

			cout << "Ingrese clave a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> cedula;
				if (cedula == key)
				{
					encontrado = true;
					cout << "Cedula:	" << cedula << endl;
					cout << "Cedula eliminada exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo << nombre1 << " " << nombre2 << " " << apellido1 << " " << apellido2 << " " << telefono << " " << direccion << " " << correo << " " << cedula << endl;
				}
				arRetirar >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
				arRetirar << "Primer nombre: " << nombre1 << endl;
				arRetirar << "Segundo nombre: " << nombre2 << endl;
				arRetirar << "Primer apellido: " << apellido1 << endl;
				arRetirar << "Segundo apellido: " << apellido2 << endl;
				arRetirar << "Telefono: " << telefono << endl;
				arRetirar << "Direccion: " << direccion << endl;
				arRetirar << "Correo electronico: " << correo << endl;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 5:
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
			fflush(stdin);

			cout << "Ingrese clave a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> cedula;
				if (cedula == key)
				{
					encontrado = true;
					cout << "Cedula:	" << cedula << endl;
					cout << "Cedula eliminada exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo << nombre1 << " " << nombre2 << " " << apellido1 << " " << apellido2 << " " << telefono << " " << direccion << " " << correo << " " << cedula << endl;
				}
				arRetirar >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
				arRetirar << "Primer nombre: " << nombre1 << endl;
				arRetirar << "Segundo nombre: " << nombre2 << endl;
				arRetirar << "Primer apellido: " << apellido1 << endl;
				arRetirar << "Segundo apellido: " << apellido2 << endl;
				arRetirar << "Telefono: " << telefono << endl;
				arRetirar << "Direccion: " << direccion << endl;
				arRetirar << "Correo electronico: " << correo << endl;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 6:
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
			fflush(stdin);

			cout << "Ingrese clave a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> cedula;
				if (cedula == key)
				{
					encontrado = true;
					cout << "Cedula:	" << cedula << endl;
					cout << "Cedula eliminada exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo << nombre1 << " " << nombre2 << " " << apellido1 << " " << apellido2 << " " << telefono << " " << direccion << " " << correo << " " << cedula << endl;
				}
				arRetirar >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
				arRetirar << "Primer nombre: " << nombre1 << endl;
				arRetirar << "Segundo nombre: " << nombre2 << endl;
				arRetirar << "Primer apellido: " << apellido1 << endl;
				arRetirar << "Segundo apellido: " << apellido2 << endl;
				arRetirar << "Telefono: " << telefono << endl;
				arRetirar << "Direccion: " << direccion << endl;
				arRetirar << "Correo electronico: " << correo << endl;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 7:
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
			fflush(stdin);

			cout << "Ingrese clave a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> cedula;
				if (cedula == key)
				{
					encontrado = true;
					cout << "Cedula:	" << cedula << endl;
					cout << "Cedula eliminada exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo << nombre1 << " " << nombre2 << " " << apellido1 << " " << apellido2 << " " << telefono << " " << direccion << " " << correo << " " << cedula << endl;
				}
				arRetirar >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
				arRetirar << "Primer nombre: " << nombre1 << endl;
				arRetirar << "Segundo nombre: " << nombre2 << endl;
				arRetirar << "Primer apellido: " << apellido1 << endl;
				arRetirar << "Segundo apellido: " << apellido2 << endl;
				arRetirar << "Telefono: " << telefono << endl;
				arRetirar << "Direccion: " << direccion << endl;
				arRetirar << "Correo electronico: " << correo << endl;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 8:
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
			fflush(stdin);

			cout << "Ingrese clave a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> cedula;
				if (cedula == key)
				{
					encontrado = true;
					cout << "Cedula:	" << cedula << endl;
					cout << "Cedula eliminada exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo << nombre1 << " " << nombre2 << " " << apellido1 << " " << apellido2 << " " << telefono << " " << direccion << " " << correo << " " << cedula << endl;
				}
				arRetirar >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
				arRetirar << "Primer nombre: " << nombre1 << endl;
				arRetirar << "Segundo nombre: " << nombre2 << endl;
				arRetirar << "Primer apellido: " << apellido1 << endl;
				arRetirar << "Segundo apellido: " << apellido2 << endl;
				arRetirar << "Telefono: " << telefono << endl;
				arRetirar << "Direccion: " << direccion << endl;
				arRetirar << "Correo electronico: " << correo << endl;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 9:
			opc = 0;
			system(CLEAR);
			break;
		default:
			cout << "Ingreso una opcion no valida! ";
		}
	} while (opc != 0);

	arRetirar.close();
}

void Registro::modificar()
{
	system("cls");

	fstream arModif("ingreso.txt");		   // creo la wea de fstream para modificar ingreso
	arModif.open("ingreso.txt", ios::in);  // aqui la abro y le digo que la voy a usar solo para lectura
	ofstream aux("auxiMod.txt", ios::out); // aqui abro y creo una variable ofstream para escritura

	arModif >> cedula; // en todo esto agarro los datos de cedula, nombre y demas
	arModif >> nombre1;
	arModif >> nombre2;
	arModif >> apellido1;
	arModif >> apellido2;
	arModif >> telefono;
	arModif >> direccion;
	arModif >> correo;

	string cedaux; // declaro variables auxiliares
	string cedaux2;

	if (arModif.is_open())
	{
		cout << "cedula: ";
		cin >> cedaux;
		arModif >> cedula;
		if (!arModif.eof())
		{
			arModif >> nombre1;
			arModif >> apellido1;
			arModif >> cedula;
			if (cedula == cedaux)
			{
				cout << "la nueva cedula pa: ";
				cin >> cedaux2;
				aux << cedaux2 << " " << nombre1 << " " << nombre2 << " " << apellido1 << " " << apellido2 << " " << telefono << " " << direccion << " " << correo << endl;
			}
			else
			{
				aux << nombre1 << " " << nombre2 << " " << apellido1 << " " << apellido2 << " " << telefono << " " << direccion << " " << correo << endl;
			}
			arModif >> cedula;
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

	ifstream arListar("ingreso.txt");
	arListar.open("ingreso.txt", ios::in);

	arListar >> cedula;
	arListar >> nombre1;
	arListar >> nombre2;
	arListar >> apellido1;
	arListar >> apellido2;
	arListar >> telefono;
	arListar >> direccion;
	arListar >> correo;

	if (!arListar.eof())
	{
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
	}
	arListar.close();
	system("pause");
}

void error()
{
	cout << "Hubo un error chamaco pendejo\n";
}

int main()
{
	system("color 70");
	Registro inicio;
	inicio.menu();
}