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
			opc = 0;
			system("cls");
			break;
		default:
			cout << "Ingreso Opcion no valida ";
		}
	} while (opc != 0);
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
	arIngreso << endl<<aux_cedula << endl
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

	string key = "";
	string vacio = "";
	bool encontrado = false;
	int opc = 1;
	int contadur=0;

	ifstream arRetirar;
	ofstream tempo;

	do
	{
		system("cls");
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
		case 1: // cedula
			system("cls");
			arRetirar.open("ingreso.txt", ios::in);
			tempo.open("auxiliar.txt", ios::app);

			if (arRetirar.is_open())
			{	
				cout << "Ingrese la cedula a eliminar" << endl;
				cin >> key;		
				while (!arRetirar.eof())
				{
					arRetirar>>cedula;
					if (cedula == key)
					{
						encontrado = true;
						cout << "Cedula:	" << cedula << endl;
						cout << "Cedula eliminada exitosamente!" << endl;
						tempo <<endl<<vacio<<endl<<nombre1<< endl << nombre2 << endl <<apellido1 << endl <<apellido2 << endl <<telefono << endl <<direccion << endl <<correo;
						contadur++;
						system("pause");
					}
					else
					{
						tempo <<endl<<cedula<<endl<<nombre1<< endl << nombre2 << endl <<apellido1 << endl <<apellido2 << endl <<telefono << endl <<direccion << endl <<correo;
					}
					arRetirar >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
				}	
				arRetirar.close();
				tempo.close();
				if (encontrado == false)
				{
					cout << "Clave no encontrada" << endl;
					system("pause");
				}	
			}
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 2: // nombre1
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;

			cout << "Ingrese el primer nombre a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> nombre1;
				if (nombre1 == key)
				{
					encontrado = true;
					cout << "Primer nombre:	" << nombre1 << endl;
					cout << "Primer nombre eliminado exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo << endl<<cedula <<endl << nombre2 <<endl << apellido1 <<endl << apellido2 <<endl << telefono <<endl << direccion <<endl << correo;
				}
				arRetirar >> cedula >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
				// arRetirar << endl
				// 		  << cedula << endl
				// 		  << nombre2 << endl
				// 		  << apellido1 << endl
				// 		  << apellido2 << endl
				// 		  << telefono << endl
				// 		  << direccion << endl
				// 		  << correo;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
				system("pause");
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 3: // nombre2
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;

			cout << "Ingrese el segundo nombre a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> nombre2;
				if (nombre2 == key)
				{
					encontrado = true;
					cout << "Segundo nombre:	" << nombre2 << endl;
					cout << "Segundo nombre eliminado exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo <<endl<< cedula << endl<< nombre1 << endl<< apellido1 << endl<< apellido2 << endl<< telefono << endl<< direccion << endl<< correo;
				}
				arRetirar >> cedula >> nombre1 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;
				// arRetirar << endl
				// 		  << cedula << endl
				// 		  << nombre1 << endl
				// 		  << apellido1 << endl
				// 		  << apellido2 << endl
				// 		  << telefono << endl
				// 		  << direccion << endl
				// 		  << correo;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
				system("pause");
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 4: // apellido1
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;

			cout << "Ingrese el primer apellido a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> apellido1;
				if (apellido1 == key)
				{
					encontrado = true;
					cout << "Primer apellido:	" << apellido1 << endl;
					cout << "Primer apellido eliminado exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo <<endl<< cedula <<endl << nombre1 <<endl << nombre2 <<endl << apellido2 <<endl << telefono <<endl << direccion <<endl << correo;
				}
				arRetirar >> cedula >> nombre1 >> nombre2 >> apellido2 >> telefono >> direccion >> correo;
				// arRetirar << endl
				// 		  << cedula << endl
				// 		  << nombre1 << endl
				// 		  << nombre2 << endl
				// 		  << apellido2 << endl
				// 		  << telefono << endl
				// 		  << direccion << endl
				// 		  << correo;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
				system("pause");
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 5: // apellido2
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;

			cout << "Ingrese el segundo apellido a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> apellido2;
				if (apellido2 == key)
				{
					encontrado = true;
					cout << "Segundo apellido:	" << apellido2 << endl;
					cout << "Segundo apellido eliminado exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo <<endl<< cedula <<endl << nombre1 <<endl << nombre2 <<endl << apellido1 <<endl << telefono <<endl << direccion <<endl << correo;
				}
				arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> telefono >> direccion >> correo;
				// arRetirar << endl
				// 		  << cedula << endl
				// 		  << nombre1 << endl
				// 		  << nombre2 << endl
				// 		  << apellido1 << endl
				// 		  << telefono << endl
				// 		  << direccion << endl
				// 		  << correo;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
				system("pause");
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 6: // telefono
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;

			cout << "Ingrese telefono a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> telefono;
				if (telefono == key)
				{
					encontrado = true;
					cout << "Telefono:	" << telefono << endl;
					cout << "Telefono eliminado exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo << endl<<cedula <<endl << nombre1 <<endl << nombre2 <<endl << apellido1 <<endl << apellido2 <<endl << direccion <<endl << correo;
				}
				arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> direccion >> correo;
				// arRetirar << endl
				// 		  << cedula << endl
				// 		  << nombre1 << endl
				// 		  << nombre2 << endl
				// 		  << apellido1 << endl
				// 		  << apellido2 << endl
				// 		  << direccion << endl
				// 		  << correo;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
				system("pause");
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 7: // direccion
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;

			cout << "Ingrese direccion a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> direccion;
				if (direccion == key)
				{
					encontrado = true;
					cout << "Direccion:	" << direccion << endl;
					cout << "Direccion eliminada exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo << endl<<cedula <<endl << nombre1 <<endl << nombre2 <<endl << apellido1 <<endl << apellido2 <<endl << telefono <<endl << correo;
				}
				arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> correo;
				// arRetirar << endl
				// 		  << cedula << endl
				// 		  << nombre1 << endl
				// 		  << nombre2 << endl
				// 		  << apellido1 << endl
				// 		  << apellido2 << endl
				// 		  << telefono << endl
				// 		  << correo;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
				system("pause");
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 8: // correo
			system("cls");
			arRetirar.open("ingreso.txt");
			tempo.open("auxiliar.txt");
			arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion >> correo;

			cout << "Ingrese correo a eliminar" << endl;
			cin >> key;
			if (!arRetirar.eof())
			{
				arRetirar >> correo;
				if (correo == key)
				{
					encontrado = true;
					cout << "Correo:	" << correo << endl;
					cout << "Correo eliminado exitosamente!" << endl;
					system("pause");
				}
				else
				{
					tempo <<endl<< cedula << endl << nombre1 << endl<< nombre2 << endl << apellido1 << endl<< apellido2 << endl << telefono << endl << direccion;
				}
				arRetirar >> cedula >> nombre1 >> nombre2 >> apellido1 >> apellido2 >> telefono >> direccion;
				// arRetirar << "Cedula: " << cedula << endl;
				// arRetirar << "Primer nombre: " << nombre1 << endl;
				// arRetirar << "Segundo nombre: " << nombre2 << endl;
				// arRetirar << "Primer apellido: " << apellido1 << endl;
				// arRetirar << "Segundo apellido: " << apellido2 << endl;
				// arRetirar << "Telefono: " << telefono << endl;
				// arRetirar << "Direccion: " << direccion << endl;
			}
			if (encontrado == false)
			{
				cout << "Clave no encontrada" << endl;
				system("pause");
			}
			arRetirar.close();
			tempo.close();
			remove("ingreso.txt");
			rename("auxiliar.txt", "ingreso.txt");
			break;
		case 9: // salir
			opc = 0;
			system("cls");
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
}

int main()
{
	system("color 70");
	Registro inicio;
	inicio.menu();
}