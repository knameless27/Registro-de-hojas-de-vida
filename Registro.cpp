#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <vector>
#include <ratio>
#include <chrono>

// Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix) || defined(__unix__) || defined(__unix) || defined(__APPLE__) || defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

using namespace std;

class DBasicos
{
private:
	string cedula, nombre1, nombre2, apellido1, apellido2, telefono, direccion, correo, RH, fechaN = "", sexToS, nacioTos, estTos, activo;
	int sexo, nacionalidad, estadoCv, diaN, mesN, anoN;

public:
	void ingresar();
	void retirar();
	void modificar();
	void listar();
	void borrado_logico();
	void activar_logico();
	void menu();
};

class Estudios
{
private:
	string cedula;
	string entidadEd;
	string titulo;
	string fechaT;
	string activoE;
	int diaN, mesN, anoN;

public:
	void ingresar_est();
	void retirar_est();
	void modificar_est();
	void listar_est();
	void borrado_logico_est();
	void activar_logico_est();
	void menu_est();
};

class HLaboral
{
private:
	string cedula;
	string empresa;
	string cargo;
	string fechaIni;
	string fechaTer;
	string activoH;
	int diaN, mesN, anoN,diaN2, mesN2, anoN2;

public:
	void ingresar_H();
	void retirar_H();
	void modificar_H();
	void listar_H();
	void borrado_logico_H();
	void activar_logico_H();
	void menu_H();
};
void pausa();
void error();

void DBasicos::menu()
{
	int opc;
	opc = 9;
	do
	{
		system(CLEAR);
		cout << "\nRegistrar datos basicos" << endl
			 << endl;
		cout << "1. Ingresar Datos Basicos" << endl;
		cout << "2. Retirar Datos Basicos" << endl;
		cout << "3. Modificar Datos Basicos" << endl;
		cout << "4. Listar Datos Basicos " << endl;
		cout << "5. Borrado Logico " << endl;
		cout << "6. Activar Logico " << endl;
		cout << "7. Salir del Menu" << endl
			 << endl;
		cout << "Digite una opcion :  ";
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
			borrado_logico();
			break;
		case 6:
			activar_logico();
			break;
		case 7:
			opc = 0;
			break;
		default:
			cout << "Digito una opcion no valida! ";
		}
	} while (opc != 0);
}

void DBasicos::ingresar()
{
	system(CLEAR);

	ofstream arIngresar;
	arIngresar.open("DBasicos.txt", ios::app);

	int opt = 0;

	if (arIngresar.is_open())
	{
		cout << "\n\n Datos basicos!";
		cout << "\n\n Digite la cedula: ";
		getline(cin, cedula);

		if (cedula == "")
		{
			do
			{
				cout << "\n\n Digite la cedula: ";
				getline(cin, cedula);
			} while (cedula == "");
		}

		cout << "\n\n Digite su primer nombre: ";
		getline(cin, nombre1);

		if (nombre1 == "")
		{
			do
			{
				cout << "\n\n Digite su primer nombre: ";
				getline(cin, nombre1);
			} while (nombre1 == "");
		}

		cout << "\n\n Digite su segundo nombre: ";
		getline(cin, nombre2);

		if (nombre2 == "")
		{
			do
			{
				cout << "\n\n Digite su segundo nombre: ";
				getline(cin, nombre2);
			} while (nombre2 == "");
		}

		cout << "\n\n Digite su primer apellido: ";
		getline(cin, apellido1);

		if (apellido1 == "")
		{
			do
			{
				cout << "\n\n Digite su primer apellido: ";
				getline(cin, apellido1);
			} while (apellido1 == "");
		}

		cout << "\n\n Digite su segundo apellido: ";
		getline(cin, apellido2);

		if (apellido2 == "")
		{
			do
			{
				cout << "\n\n Digite su segundo apellido: ";
				getline(cin, apellido2);
			} while (apellido2 == "");
		}

		cout << "\n\n Digite su telefono: ";
		getline(cin, telefono);

		if (telefono == "")
		{
			do
			{
				cout << "\n\n Digite su telefono: ";
				getline(cin, telefono);
			} while (telefono == "");
		}

		cout << "\n\n Digite su direccion: ";
		getline(cin, direccion);

		if (direccion == "")
		{
			do
			{
				cout << "\n\n Digite su direccion: ";
				getline(cin, direccion);
			} while (direccion == "");
		}

		cout << "\n\n Digite su correo electronico: ";
		getline(cin, correo);

		if (correo == "")
		{
			do
			{
				cout << "\n\n Digite su correo: ";
				getline(cin, correo);
			} while (correo == "");
		}

		cout << "\n\n Digite su sexo: ";

		cout << endl
			 << "1. Masculino";
		cout << endl
			 << "2. Femenino";
		cout << endl
			 << endl
			 << "(1/2): ";
		cin >> opt;

		switch (opt)
		{
		case 1:
			sexo = 1;
			break;
		case 2:
			sexo = 2;
			break;
		default:
			do
			{
				cout << "\n\n Digite su sexo: ";
				cin >> sexo;
			} while (sexo != 1 || sexo != 2);
			break;
		}
		auto sextS = std::to_string(sexo);
		sexToS = sextS;

		cout << "\n\n Digite su nacionalidad: ";

		cout << endl
			 << "1. Colombiano";
		cout << endl
			 << "2. Extranjero";
		cout << endl
			 << endl
			 << "(1/2): ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			nacionalidad = 1;
			break;
		case 2:
			nacionalidad = 2;
			break;
		default:
			do
			{
				cout << "\n\n Digite su nacionalidad: ";
				cin >> nacionalidad;
			} while (nacionalidad != 1 || nacionalidad != 2);
			break;
		}
		auto nactS = std::to_string(nacionalidad);
		nacioTos = nactS;

		cout << "\n\n Digite su estado civil: ";

		cout << endl
			 << "1. soltero";
		cout << endl
			 << "2. casado";
		cout << endl
			 << "3. separado";
		cout << endl
			 << "4. viudo";
		cout << endl
			 << endl
			 << "(1/2/3/4): ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			estadoCv = 1;
			break;
		case 2:
			estadoCv = 2;
			break;
		case 3:
			estadoCv = 3;
			break;
		case 4:
			estadoCv = 4;
			break;
		default:
			do
			{
				cout << "\n\n Digite su estado civil: ";
				cin >> estadoCv;
			} while (estadoCv != 1 || estadoCv != 2 || estadoCv != 3 || estadoCv != 4);
			break;
		}
		auto esttS = std::to_string(estadoCv);
		estTos = esttS;

		cout << "\n\n Digite el dia de su nacimiento: ";
		cin >> diaN;

		cout << endl
			 << " Digite su mes de nacimiento: ";
		cin >> mesN;

		cout << endl
			 << " Digite su año de nacimiento: ";
		cin >> anoN;

		auto diatS = std::to_string(diaN);
		auto mestS = std::to_string(mesN);
		auto anotS = std::to_string(anoN);

		fechaN = diatS + "-" + mestS + "-" + anotS;

		tm timeinfo = tm();
		int anotemp = anoN - 1900;
		timeinfo.tm_mday = diaN;
		timeinfo.tm_mon = mesN + 1;
		timeinfo.tm_year = anotemp;

		auto t_x = mktime(&timeinfo);
		auto tp_x = chrono::system_clock::from_time_t(t_x);
		auto tp_hoy = chrono::system_clock::now();
		auto diferencia = tp_hoy - tp_x;

		const int SEGS_POR_DIA = 60 * 60 * 24;
		typedef chrono::duration<int, ratio<SEGS_POR_DIA>> dias_t;
		int n_dias = chrono::duration_cast<dias_t>(diferencia).count();

		if (n_dias < 6570)
		{
			cout << endl
				 << "No se puede postular porque usted es menor de edad!" << endl;
			return;
		}
	}

	system("pause");
	cout << "\n\n Digite su RH: ";
	getline(cin, RH);

	if (RH == "")
	{
		do
		{
			cout << "\n\n Digite su RH: ";
			getline(cin, RH);
		} while (RH == "");
	}

	activo = "0";
	arIngresar << cedula << endl
			   << nombre1 << endl
			   << nombre2 << endl
			   << apellido1 << endl
			   << apellido2 << endl
			   << telefono << endl
			   << direccion << endl
			   << correo << endl
			   << sexo << endl
			   << nacionalidad << endl
			   << estadoCv << endl
			   << diaN << "-" << mesN << "-" << anoN << endl
			   << RH << endl
			   << activo << endl;

	arIngresar.close();
}

void DBasicos::modificar()
{
	system(CLEAR);
	
	ifstream lectura;
	ofstream auxiliar;

	bool encontrado = false;

	string auxCodigo;
	string tempCed;
	char respuesta[5];
	int opt = 0;

	lectura.open("DBasicos.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);

	cout << "\t\t\t\t\255Modificar datos!\t\t\t\t\n\n";
	if (lectura.is_open() && auxiliar.is_open())
	{
		fflush(stdin);
		cout << "Digite la cedula de la persona a modificar: ";
		getline(cin, auxCodigo);

		getline(lectura, cedula);
		while (!lectura.eof())
		{
			getline(lectura, nombre1);
			getline(lectura, nombre2);
			getline(lectura, apellido1);
			getline(lectura, apellido2);
			getline(lectura, telefono);
			getline(lectura, direccion);
			getline(lectura, correo);
			getline(lectura, sexToS);
			getline(lectura, nacioTos);
			getline(lectura, estTos);
			getline(lectura, fechaN);
			getline(lectura, RH);
			getline(lectura, activo);

			if (auxCodigo == cedula && activo != "")
			{
				encontrado = true;
				cout << "\n\nRegistro Encontrado\n\n";
				cout << "Cedula : " << cedula << endl;
				cout << "Nombres : " << nombre1 << " " << nombre2 << endl;
				cout << "Apellidos : " << apellido1 << " " << apellido2 << endl;
				cout << "telefono : " << telefono << endl;
				cout << "direccion : " << direccion << endl;
				cout << "correo : " << correo << endl;
				cout << "sexo : ";
				if (sexToS == "1")
				{
					cout << "Masculino" << endl;
				}
				else
				{
					cout << "Femenino" << endl;
				};
				cout << "nacionalidad : ";
				if (nacioTos == "1")
				{
					cout << "Colombiano" << endl;
				}
				else
				{
					cout << "Extranjero" << endl;
				};
				cout << "estado civil : ";
				if (estTos == "1")
				{
					cout << "soltero" << endl;
				}
				if (estTos == "2")
				{
					cout << "casado" << endl;
				}
				if (estTos == "3")
				{
					cout << "separado" << endl;
				}
				if (estTos == "4")
				{
					cout << "viudo" << endl;
				}
				cout << "fechaT de nacimiento : " << fechaN << endl;
				cout << "RH : " << RH << endl;

				cout << endl<<"MODIFICANDO DATOS DEL REGISTRO";

				cout << "\n\n Digite la cedula: ";
				getline(cin, tempCed);

				if (tempCed == "")
				{
					do
					{
						cout << "\n\n Digite la cedula: ";
						getline(cin, tempCed);
					} while (tempCed == "");
				}

				cout << "\n\n Digite su primer nombre: ";
				getline(cin, nombre1);

				if (nombre1 == "")
				{
					do
					{
						cout << "\n\n Digite su primer nombre: ";
						getline(cin, nombre1);
					} while (nombre1 == "");
				}

				cout << "\n\n Digite su segundo nombre : ";
				getline(cin, nombre2);

				if (nombre2 == "")
				{
					do
					{
						cout << "\n\n Digite su segundo nombre: ";
						getline(cin, nombre2);
					} while (nombre2 == "");
				}

				cout << "\n\n Digite su primer apellido: ";
				getline(cin, apellido1);

				if (apellido1 == "")
				{
					do
					{
						cout << "\n\n Digite su primer apellido: ";
						getline(cin, apellido1);
					} while (apellido1 == "");
				}

				cout << "\n\n Digite su segundo apellido: ";
				getline(cin, apellido2);

				if (apellido2 == "")
				{
					do
					{
						cout << "\n\n Digite su segundo apellido: ";
						getline(cin, apellido2);
					} while (apellido2 == "");
				}

				cout << "\n\n Digite su telefono: ";
				getline(cin, telefono);

				if (telefono == "")
				{
					do
					{
						cout << "\n\n Digite su telefono: ";
						getline(cin, telefono);
					} while (telefono == "");
				}

				cout << "\n\n Digite su direccion: ";
				getline(cin, direccion);

				if (direccion == "")
				{
					do
					{
						cout << "\n\n Digite su direccion: ";
						getline(cin, direccion);
					} while (direccion == "");
				}

				cout << "\n\n Digite su correo electronico: ";
				getline(cin, correo);

				if (correo == "")
				{
					do
					{
						cout << "\n\n Digite su correo: ";
						getline(cin, correo);
					} while (correo == "");
				}

				cout << "\n\n Digite su sexo: ";

				cout << endl
					 << "1. Masculino";
				cout << endl
					 << "2. Femenino";
				cout << endl
					 << endl
					 << "(1/2): ";
				cin >> opt;

				switch (opt)
				{
				case 1:
					sexo = 1;
					break;
				case 2:
					sexo = 2;
					break;
				default:
					do
					{
						cout << "\n\n Digite su sexo: ";
						cin >> sexo;
					} while (sexo != 1 || sexo != 2);
					break;
				}
				auto sextS = std::to_string(sexo);
				sexToS = sextS;

				cout << "\n\n Digite su nacionalidad: ";

				cout << endl
					 << "1. Colombiano";
				cout << endl
					 << "2. Extranjero";
				cout << endl
					 << endl
					 << "(1/2): ";
				cin >> opt;
				switch (opt)
				{
				case 1:
					nacionalidad = 1;
					break;
				case 2:
					nacionalidad = 2;
					break;
				default:
					do
					{
						cout << "\n\n Digite su nacionalidad: ";
						cin >> nacionalidad;
					} while (nacionalidad != 1 || nacionalidad != 2);
					break;
				}
				auto nactS = std::to_string(nacionalidad);
				nacioTos = nactS;

				cout << "\n\n Digite su estado civil: ";

				cout << endl
					 << "1. soltero";
				cout << endl
					 << "2. casado";
				cout << endl
					 << "3. separado";
				cout << endl
					 << "4. viudo";
				cout << endl
					 << endl
					 << "(1/2/3/4): ";
				cin >> opt;
				switch (opt)
				{
				case 1:
					estadoCv = 1;
					break;
				case 2:
					estadoCv = 2;
					break;
				case 3:
					estadoCv = 3;
					break;
				case 4:
					estadoCv = 4;
					break;
				default:
					do
					{
						cout << "\n\n Digite su estado civil: ";
						cin >> estadoCv;
					} while (estadoCv != 1 || estadoCv != 2 || estadoCv != 3 || estadoCv != 4);
					break;
				}
				auto esttS = std::to_string(estadoCv);
				estTos = esttS;

				cout << "\n\n Digite el dia de su nacimiento: ";
				cin >> diaN;

				cout << endl
					 << " Digite su mes de nacimiento: ";
				cin >> mesN;

				cout << endl
					 << " Digite su año de nacimiento: ";
				cin >> anoN;

				auto diatS = std::to_string(diaN);
				auto mestS = std::to_string(mesN);
				auto anotS = std::to_string(anoN);

				fechaN = diatS + "-" + mestS + "-" + anotS;

				tm timeinfo = tm();
				int anotemp = anoN - 1900;
				timeinfo.tm_mday = diaN;
				timeinfo.tm_mon = mesN + 1;
				timeinfo.tm_year = anotemp;

				auto t_x = mktime(&timeinfo);
				auto tp_x = chrono::system_clock::from_time_t(t_x);
				auto tp_hoy = chrono::system_clock::now();
				auto diferencia = tp_hoy - tp_x;

				const int SEGS_POR_DIA = 60 * 60 * 24;
				typedef chrono::duration<int, ratio<SEGS_POR_DIA>> dias_t;
				int n_dias = chrono::duration_cast<dias_t>(diferencia).count();

				if (n_dias < 6570)
				{
					cout << endl
						 << "No se puede postular porque usted es menor de edad!" << endl;
					return;
				}
				system("pause");
				cout << "\n\n Digite su RH: ";
				getline(cin, RH);

				if (RH == "")
				{
					do
					{
						cout << "\n\n Digite su RH: ";
						getline(cin, RH);
					} while (RH == "");
				}

				auxiliar << cedula << endl
						 << nombre1 << endl
						 << nombre2 << endl
						 << apellido1 << endl
						 << apellido2 << endl
						 << telefono << endl
						 << direccion << endl
						 << correo << endl
						 << sexo << endl
						 << nacionalidad << endl
						 << estadoCv << endl
						 << diaN << "-" << mesN << "-" << anoN << endl
						 << RH << endl
						 << activo << endl;
			}
			else
			{
				auxiliar << cedula << endl
						 << nombre1 << endl
						 << nombre2 << endl
						 << apellido1 << endl
						 << apellido2 << endl
						 << telefono << endl
						 << direccion << endl
						 << correo << endl
						 << sexo << endl
						 << nacionalidad << endl
						 << estadoCv << endl
						 << diaN << "-" << mesN << "-" << anoN << endl
						 << RH << endl
						 << activo << endl;
			}
			getline(lectura, cedula);
		}
		if (encontrado == false)
		{
			cout << "\n\nNo se encontr\242 la cedula: " << auxCodigo << "\n\n";
		}
	}
	lectura.close();
	auxiliar.close();
	remove("DBasicos.txt");
	rename("auxiliar.txt", "DBasicos.txt");
	pausa();
}

void DBasicos::borrado_logico()
{
	system(CLEAR);

	ifstream lectura;
	ofstream auxiliar;

	bool encontrado = false;

	string auxCodigo;
	char respuesta[5];

	lectura.open("DBasicos.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);

	cout << "\t\t\t\t*** Eliminar hoja de vida de forma logica ***\t\t\t\t\n\n";
	if (lectura.is_open() && auxiliar.is_open())
	{
		fflush(stdin);
		cout << "Ingresa la cedula de la persona que deseas eliminar: ";
		getline(cin, auxCodigo);

		getline(lectura, cedula);
		while (!lectura.eof())
		{
			getline(lectura, nombre1);
			getline(lectura, nombre2);
			getline(lectura, apellido1);
			getline(lectura, apellido2);
			getline(lectura, telefono);
			getline(lectura, direccion);
			getline(lectura, correo);
			getline(lectura, sexToS);
			getline(lectura, nacioTos);
			getline(lectura, estTos);
			getline(lectura, fechaN);
			getline(lectura, RH);
			getline(lectura, activo);

			if (auxCodigo == cedula && activo != "")
			{
				encontrado = true;
				cout << "\n\nRegistro Encontrado\n\n";
				cout << "Cedula : " << cedula << endl;
				cout << "Nombres : " << nombre1 << " " << nombre2 << endl;
				cout << "Apellidos : " << apellido1 << " " << apellido2 << endl;
				cout << "telefono : " << telefono << endl;
				cout << "direccion : " << direccion << endl;
				cout << "correo : " << correo << endl;
				cout << "sexo : ";
				if (sexToS == "1")
				{
					cout << "Masculino" << endl;
				}
				else
				{
					cout << "Femenino" << endl;
				};
				cout << "nacionalidad : ";
				if (nacioTos == "1")
				{
					cout << "Colombiano" << endl;
				}
				else
				{
					cout << "Extranjero" << endl;
				};
				cout << "estado civil : ";
				if (estTos == "1")
				{
					cout << "soltero" << endl;
				}
				if (estTos == "2")
				{
					cout << "casado" << endl;
				}
				if (estTos == "3")
				{
					cout << "separado" << endl;
				}
				if (estTos == "4")
				{
					cout << "viudo" << endl;
				}
				cout << "fechaT de nacimiento : " << fechaN << endl;
				cout << "RH : " << RH << endl;

				cout << "Realmente deseas dar de Baja-Logico  (s/n)?: ";
				cin.getline(respuesta, 5);

				if (strcmp(respuesta, "s") == 0 || strcmp(respuesta, "S") == 0 ||
					strcmp(respuesta, "si") == 0 || strcmp(respuesta, "SI") == 0 ||
					strcmp(respuesta, "Si") == 0 || strcmp(respuesta, "sI") == 0)

				{
					cout << "\n\nEl Amigo se ha dado de baja correctamente\n\n";
					activo = "";
					auxiliar << cedula << endl
						 << nombre1 << endl
						 << nombre2 << endl
						 << apellido1 << endl
						 << apellido2 << endl
						 << telefono << endl
						 << direccion << endl
						 << correo << endl
						 << sexo << endl
						 << nacionalidad << endl
						 << estadoCv << endl
						 << diaN << "-" << mesN << "-" << anoN << endl
						 << RH << endl
						 << activo << endl;
				}

				else
				{
					cout << "\n\nCliente conservado\n\n";
					auxiliar << cedula << endl
						 << nombre1 << endl
						 << nombre2 << endl
						 << apellido1 << endl
						 << apellido2 << endl
						 << telefono << endl
						 << direccion << endl
						 << correo << endl
						 << sexo << endl
						 << nacionalidad << endl
						 << estadoCv << endl
						 << diaN << "-" << mesN << "-" << anoN << endl
						 << RH << endl
						 << activo << endl;
				}
			}
			else
			{
				auxiliar << cedula << endl
						 << nombre1 << endl
						 << nombre2 << endl
						 << apellido1 << endl
						 << apellido2 << endl
						 << telefono << endl
						 << direccion << endl
						 << correo << endl
						 << sexo << endl
						 << nacionalidad << endl
						 << estadoCv << endl
						 << diaN << "-" << mesN << "-" << anoN << endl
						 << RH << endl
						 << activo << endl;
			}

			getline(lectura, cedula);
		}
		if (encontrado == false)
		{
			cout << "\n\nNo se encontr\242 la cedula: " << auxCodigo << "\n\n";
		}
	}
	else
	{
		error();
	}
	lectura.close();
	auxiliar.close();
	remove("DBasicos.txt");
	rename("auxiliar.txt", "DBasicos.txt");
	pausa();
}

void DBasicos::activar_logico()
{
	system(CLEAR);

	ifstream lectura;
	ofstream auxiliar;

	bool encontrado = false;

	string auxCodigo;
	char respuesta[5];

	lectura.open("DBasicos.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);

	cout << "\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
	if (lectura.is_open() && auxiliar.is_open())
	{
		fflush(stdin);
		cout << "Activando los Registros Inactivados" << endl;
		getline(lectura, cedula);
		while (!lectura.eof())
		{
			getline(lectura, nombre1);
			getline(lectura, nombre2);
			getline(lectura, apellido1);
			getline(lectura, apellido2);
			getline(lectura, telefono);
			getline(lectura, direccion);
			getline(lectura, correo);
			getline(lectura, sexToS);
			getline(lectura, nacioTos);
			getline(lectura, estTos);
			getline(lectura, fechaN);
			getline(lectura, RH);
			getline(lectura, activo);

			activo = "0";
			auxiliar << cedula << endl
						 << nombre1 << endl
						 << nombre2 << endl
						 << apellido1 << endl
						 << apellido2 << endl
						 << telefono << endl
						 << direccion << endl
						 << correo << endl
						 << sexo << endl
						 << nacionalidad << endl
						 << estadoCv << endl
						 << diaN << "-" << mesN << "-" << anoN << endl
						 << RH << endl
						 << activo << endl;

			getline(lectura, cedula);
		}
		cout << "Fin Proceso de Activando los Registros" << endl;
	}
	else
	{
		error();
	}
	lectura.close();
	auxiliar.close();
	remove("DBasicos.txt");
	rename("auxiliar.txt", "DBasicos.txt");
	pausa();
}

void DBasicos::retirar()
{
	system(CLEAR);

	ifstream lectura;
	ofstream auxiliar;

	bool encontrado = false;

	string auxCodigo;
	char respuesta[5];

	lectura.open("DBasicos.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);

	cout << "\t\t\t\t*** Eliminar una hoja de vida ***\t\t\t\t\n\n";
	if (lectura.is_open() && auxiliar.is_open())
	{
		fflush(stdin);
		cout << "Ingresa la cedula del registro que deseas dar eliminar: ";
		getline(cin, auxCodigo);

		getline(lectura, cedula);
		while (!lectura.eof())
		{
			getline(lectura, nombre1);
			getline(lectura, nombre2);
			getline(lectura, apellido1);
			getline(lectura, apellido2);
			getline(lectura, telefono);
			getline(lectura, direccion);
			getline(lectura, correo);
			getline(lectura, sexToS);
			getline(lectura, nacioTos);
			getline(lectura, estTos);
			getline(lectura, fechaN);
			getline(lectura, RH);
			getline(lectura, activo);

			if (auxCodigo == cedula)
			{
				encontrado = true;
				cout << "\n\nRegistro Encontrado\n\n";
				cout << "Cedula : " << cedula << endl;
				cout << "Nombres : " << nombre1 << " " << nombre2 << endl;
				cout << "Apellidos : " << apellido1 << " " << apellido2 << endl;
				cout << "telefono : " << telefono << endl;
				cout << "direccion : " << direccion << endl;
				cout << "correo : " << correo << endl;
				cout << "sexo : ";
				if (sexToS == "1")
				{
					cout << "Masculino" << endl;
				}
				else
				{
					cout << "Femenino" << endl;
				};
				cout << "nacionalidad : ";
				if (nacioTos == "1")
				{
					cout << "Colombiano" << endl;
				}
				else
				{
					cout << "Extranjero" << endl;
				};
				cout << "estado civil : ";
				if (estTos == "1")
				{
					cout << "soltero" << endl;
				}
				if (estTos == "2")
				{
					cout << "casado" << endl;
				}
				if (estTos == "3")
				{
					cout << "separado" << endl;
				}
				if (estTos == "4")
				{
					cout << "viudo" << endl;
				}
				cout << "fechaT de nacimiento : " << fechaN << endl;
				cout << "RH : " << RH << endl;

				cout << endl<<"Realmente deseas dar de baja  (s/n)?: ";
				cin.getline(respuesta, 5);

				if (strcmp(respuesta, "s") == 0 || strcmp(respuesta, "S") == 0 ||
					strcmp(respuesta, "si") == 0 || strcmp(respuesta, "SI") == 0 ||
					strcmp(respuesta, "Si") == 0 || strcmp(respuesta, "sI") == 0)
				{
					cout << "\n\n\255La hoja de vida se ha eliminado correctamente!\n\n";
				}
				else
				{
					cout << "\n\n\255Hoja de vida conservada!\n\n";
					auxiliar << cedula << endl
							 << nombre1 << endl
							 << nombre2 << endl
							 << apellido1 << endl
							 << apellido2 << endl
							 << telefono << endl
							 << direccion << endl
							 << correo << endl
							 << sexo << endl
							 << nacionalidad << endl
							 << estadoCv << endl
							 << diaN << "-" << mesN << "-" << anoN << endl
							 << RH << endl
							 << activo << endl;
				}
			}
			else
			{
				auxiliar << cedula << endl
						 << nombre1 << endl
						 << nombre2 << endl
						 << apellido1 << endl
						 << apellido2 << endl
						 << telefono << endl
						 << direccion << endl
						 << correo << endl
						 << sexo << endl
						 << nacionalidad << endl
						 << estadoCv << endl
						 << diaN << "-" << mesN << "-" << anoN << endl
						 << RH << endl
						 << activo << endl;
			}

			getline(lectura, cedula);
		}
		if (encontrado == false)
		{
			cout << "\n\nNo se encontr\242 la cedula: " << auxCodigo << "\n\n";
		}
	}
	else
	{
		error();
	}
	lectura.close();
	auxiliar.close();
	remove("DBasicos.txt");
	rename("auxiliar.txt", "DBasicos.txt");
	pausa();
}

void DBasicos::listar()
{
	system(CLEAR);

	int i = 0;
	ifstream lectura;
	lectura.open("DBasicos.txt", ios::in);
	if (lectura.is_open()) // validamos que no presente error en la apertura del archivo
	{
		cout << "\t\t\t\t***Listado de todos los clientes***\t\t\t\t\n\n";
		getline(lectura, cedula);

		while (!lectura.eof()) // leer mmientras no sea el final del archivo
		{
			getline(lectura, nombre1);
			getline(lectura, nombre2);
			getline(lectura, apellido1);
			getline(lectura, apellido2);
			getline(lectura, telefono);
			getline(lectura, direccion);
			getline(lectura, correo);
			getline(lectura, sexToS);
			getline(lectura, nacioTos);
			getline(lectura, estTos);
			getline(lectura, fechaN);
			getline(lectura, RH);
			getline(lectura, activo);

			if (activo != "") //( strcmp(activo,"0" == 0 )
			{
				cout << "Cedula : " << cedula << endl;
				cout << "Nombres : " << nombre1 << " " << nombre2 << endl;
				cout << "Apellidos : " << apellido1 << " " << apellido2 << endl;
				cout << "telefono : " << telefono << endl;
				cout << "direccion : " << direccion << endl;
				cout << "correo : " << correo << endl;
				cout << "sexo : ";
				if (sexToS == "1")
				{
					cout << "Masculino" << endl;
				}
				else
				{
					cout << "Femenino" << endl;
				};
				cout << "nacionalidad : ";
				if (nacioTos == "1")
				{
					cout << "Colombiano" << endl;
				}
				else
				{
					cout << "Extranjero" << endl;
				};
				cout << "estado civil : ";
				if (estTos == "1")
				{
					cout << "soltero" << endl;
				}
				if (estTos == "2")
				{
					cout << "casado" << endl;
				}
				if (estTos == "3")
				{
					cout << "separado" << endl;
				}
				if (estTos == "4")
				{
					cout << "viudo" << endl;
				}
				cout << "fecha de nacimiento : " << fechaN << endl;
				cout << "RH : " << RH << endl;
				i++;
				cout << "\n";
			}
			else
			{
				error;
			}
			getline(lectura, cedula);
		}
		if (i == 1)
			cout << "Hay una sola persona que ha registrado su hoja de vida\n\n";
		else
			cout << "Hay un total de " << i << " personas que han registrado sus hojas de vida\n\n";
	}
	else
	{
		error();
	}
	lectura.close();
	pausa();
}

void Estudios::menu_est()
{
	int opc;
	opc = 9;
	do
	{
		system(CLEAR);
		cout << "\n REGISTRAR DATOS DE ESTUDIOS " << endl
			 << endl;
		cout << "1. Ingresar Datos de Estudios" << endl;
		cout << "2. Retirar Datos de Estudios" << endl;
		cout << "3. Modificar Datos de Estudios" << endl;
		cout << "4. Listar Datos de Estudios " << endl;
		cout << "5. Borrado Logico de Estudios" << endl;
		cout << "6. Activar Logico de Estudios" << endl;
		cout << "7. Salir del Menu" << endl
			 << endl;
		cout << "Digite Opcion :  ";
		cin >> opc;
		fflush(stdin);

		switch (opc)
		{
		case 1:
			ingresar_est();
			break;
		case 2:
			retirar_est();
			break;
		case 3:
			modificar_est();
			break;
		case 4:
			listar_est();
			break;
		case 5:
			borrado_logico_est();
			break;
		case 6:
			activar_logico_est();
			break;
		case 7:
			opc=0;
			break;
		default:
			cout << "Ingreso Opcion no valida ";
		}
	} while (opc != 0);
}

void Estudios::ingresar_est()
{
	system(CLEAR);

	ofstream arIngresar; // estudios
	ifstream lectura;	 // Datos DBasicos

	string bus_cedula;

	string cedula;
	string entidadEd;
	string titulo;
	string fechaT;

	int encontro;
	encontro = 0;

	lectura.open("DBasicos.txt", ios::in);
	arIngresar.open("Estudios.txt", ios::app);
	if (arIngresar.is_open())
	{
		cout << "Estudios";
	}
	else
	{
		arIngresar.close();
		ofstream escribir_est;
		arIngresar.open("Estudios.txt", ios::out);
	}

	if (arIngresar.is_open() && lectura.is_open()) // Validamos que el archivo "arIngresar no presento error
	{
		cout << "\n\n Digite Datos de Estudios ";
		cout << "\n\n Digite Cedula  : ";
		getline(cin, bus_cedula);
		fflush(stdin);

		if (bus_cedula == "") // validamos que el nombre2 no este vacio
		{
			do
			{
				cout << "\n\n Digite Cedula : ";
				getline(cin, bus_cedula);
			} while (bus_cedula == "");
		}

		getline(lectura, cedula);

		while (!lectura.eof() && encontro == 0)
		{

			if (cedula == bus_cedula)
			{
				encontro = 1;
				cout << "\n\n Digite Instituto : ";
				getline(cin, entidadEd);
				if (entidadEd == "")
				{
					do
					{
						cout << "\n\n Digite Instituto : ";
						getline(cin, entidadEd);
					} while (entidadEd == "");
				}

				cout << "\n\n Digite titulo : ";
				getline(cin, titulo);
				if (titulo == "")
				{
					do
					{
						cout << "\n\n Digite Titulo : ";
						getline(cin, titulo);
					} while (titulo == "");
				}

				cout << "\n\n Digite el dia de terminacion: ";
				cin >> diaN;

				cout << endl
					 << " Digite su mes de terminacion: ";
				cin >> mesN;

				cout << endl
					 << " Digite su año de terminacion: ";
				cin >> anoN;

				auto diatS = std::to_string(diaN);
				auto mestS = std::to_string(mesN);
				auto anotS = std::to_string(anoN);

				fechaT = diatS + "-" + mestS + "-" + anotS;

				tm timeinfo = tm();
				int anotemp = anoN - 1900;
				timeinfo.tm_mday = diaN;
				timeinfo.tm_mon = mesN + 1;
				timeinfo.tm_year = anotemp;

				auto t_x = mktime(&timeinfo);
				auto tp_x = chrono::system_clock::from_time_t(t_x);
				auto tp_hoy = chrono::system_clock::now();
				auto diferencia = tp_hoy - tp_x;
				
				const int SEGS_POR_DIA = 60 * 60 * 24;
				typedef chrono::duration<int, ratio<SEGS_POR_DIA>> dias_t;
				int n_dias = chrono::duration_cast<dias_t>(diferencia).count();

				timeinfo.tm_mday = 22;
				timeinfo.tm_mon = 1;
				timeinfo.tm_year = 122;

				auto t_x1 = mktime(&timeinfo);
				auto tp_x1 = chrono::system_clock::from_time_t(t_x1);
				auto tp_hoy1 = chrono::system_clock::now();
				auto diferenciaHoy = tp_hoy1 - tp_x1;
				
				const int SEGS_POR_DIA1 = 60 * 60 * 24;
				typedef chrono::duration<int, ratio<SEGS_POR_DIA1>> dias_t;
				int n_diasHoy = chrono::duration_cast<dias_t>(diferenciaHoy).count();
				if ((n_dias+6570)< 6570)
				{
					cout << endl
						 << "No se puede postular porque usted ha puesto una fecha incorrecta!" << endl;
					return;
				}
				else if (n_dias < 0)
				{
					cout << endl
						 << "No se puede postular porque usted ha puesto una fecha incorrecta!" << endl;
					return;
				}
				activoE="0";
				cedula = bus_cedula;
				arIngresar << cedula << endl
						   << entidadEd << endl
						   << titulo << endl
						   << fechaT << endl
						   << activoE << endl;
				system("pause");
			}
			getline(lectura, cedula);
		}
		if (encontro == 0)
		{
			cout << "\n\n Cedula no existe en el archivo";
			getch();
		}
	}
	arIngresar.close();
	lectura.close();
}

void Estudios::activar_logico_est()
{
	system(CLEAR);

	ifstream lectura;
	ofstream auxiliar;

	bool encontrado = false;

	string auxCodigo;
	char respuesta[5];

	lectura.open("Estudios.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);

	cout << "\t\t\t\t*** Activar de forma logica a un estudiante ***\t\t\t\t\n\n";
	if (lectura.is_open() && auxiliar.is_open())
	{
		fflush(stdin);
		cout << "Activando los Registros Inactivos" << endl;
		getline(lectura, cedula);
		while (!lectura.eof())
		{
			getline(lectura, entidadEd);
			getline(lectura, titulo);
			getline(lectura, fechaT);
			getline(lectura, activoE);

			activoE = "0";
			auxiliar << cedula << endl
						   << entidadEd << endl
						   << titulo << endl
						   << fechaT << endl
						   << activoE << endl;

			getline(lectura, cedula);
		}
		cout << "\255La activacion de registros ha concluido!" << endl;
	}
	else
	{
		error();
	}
	lectura.close();
	auxiliar.close();
	remove("Estudios.txt");
	rename("auxiliar.txt", "Estudios.txt");
	pausa();
}

void Estudios::borrado_logico_est()
{
	system(CLEAR);

	ifstream lectura;
	ofstream auxiliar;

	bool encontrado = false;

	string auxCodigo;
	char respuesta[5];

	lectura.open("Estudios.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);

	cout << "\t\t\t\t*** Eliminar estudiante de forma logica ***\t\t\t\t\n\n";
	if (lectura.is_open() && auxiliar.is_open())
	{
		fflush(stdin);
		cout << "Ingresa la cedula de la persona que deseas eliminar: ";
		getline(cin, auxCodigo);

		getline(lectura, cedula);
		while (!lectura.eof())
		{
			getline(lectura, entidadEd);
			getline(lectura, titulo);
			getline(lectura, fechaT);
			getline(lectura, activoE);

			if (auxCodigo == cedula && activoE != "")
			{
				encontrado = true;
				cout << "\n\nRegistro Encontrado\n\n";
				cout << "Cedula : " << cedula << endl;
				cout << "Entidad educativa : " << entidadEd<<endl;
				cout << "Titulo : " << titulo<< endl;
				cout << "Fecha de terminacion : " << fechaT << endl;

				cout << "Realmente deseas dar de Baja-Logico  (s/n)?: ";
				cin.getline(respuesta, 5);

				if (strcmp(respuesta, "s") == 0 || strcmp(respuesta, "S") == 0 ||
					strcmp(respuesta, "si") == 0 || strcmp(respuesta, "SI") == 0 ||
					strcmp(respuesta, "Si") == 0 || strcmp(respuesta, "sI") == 0)

				{
					cout << "\n\nEl Amigo se ha dado de baja correctamente\n\n";
					activoE = "";
					auxiliar << cedula << endl
						   << entidadEd << endl
						   << titulo << endl
						   << fechaT << endl
						   << activoE << endl;
				}

				else
				{
					cout << "\n\nCliente conservado\n\n";
					auxiliar << cedula << endl
						   << entidadEd << endl
						   << titulo << endl
						   << fechaT << endl
						   << activoE << endl;
				}
			}
			else
			{
				auxiliar << cedula << endl
						   << entidadEd << endl
						   << titulo << endl
						   << fechaT << endl
						   << activoE << endl;
			}

			getline(lectura, cedula);
		}
		if (encontrado == false)
		{
			cout << "\n\nNo se encontr\242 la cedula: " << auxCodigo << "\n\n";
		}
	}
	else
	{
		error();
	}
	lectura.close();
	auxiliar.close();
	remove("Estudios.txt");
	rename("auxiliar.txt", "Estudios.txt");
	pausa();
}

void Estudios::listar_est()
{
	system(CLEAR);

	int i = 0;
	ifstream lectura;
	ifstream leer_est;

	string cedulaAux, nombre1Aux, nombre2Aux, apellido1Aux, apellido2Aux, telefonoAux, direccionAux, correoAux, SextoSAux, nacioToSAux, estToSAux, fechaNAux, RHAux, activoAux;

	string cedulaAx;
	string entidadEdAx;
	string tituloAx;
	string fechaTAx;
	string activoEAx;

	lectura.open("DBasicos.txt", ios::in);
	leer_est.open("Estudios.txt", ios::in);

	if (lectura.is_open() && leer_est.is_open()) // validamos que no presente error en la apertura del archivo
	{

		cout << "\t\t\t\t***Listado de todos los registros***\t\t\t\t\n\n";
		getline(lectura, cedulaAux);
		while (!lectura.eof()) // leer mmientras no sea el final del archivo
		{
			getline(lectura, nombre1Aux);
			getline(lectura, nombre2Aux);
			getline(lectura, apellido1Aux);
			getline(lectura, apellido2Aux);
			getline(lectura, telefonoAux);
			getline(lectura, direccionAux);
			getline(lectura, correoAux);
			getline(lectura, SextoSAux);
			getline(lectura, nacioToSAux);
			getline(lectura, estToSAux);
			getline(lectura, fechaNAux);
			getline(lectura, RHAux);
			getline(lectura, activoAux);

			if (activoAux != "") //( strcmp(activo,"0" == 0 )
			{
				cout<<"Datos de "<<nombre1Aux<<": "<<endl<<endl;
				cout << "Cedula : " << cedulaAux << endl;
				cout << "Nombres : " << nombre1Aux << " " << nombre2Aux << endl;
				cout << "Apellidos : " << apellido1Aux << " " << apellido2Aux << endl;
				cout << "telefono : " << telefonoAux << endl;
				cout << "direccion : " << direccionAux << endl;
				cout << "correo : " << correoAux << endl;
				cout << "sexo : ";
				if (SextoSAux == "1")
				{
					cout << "Masculino" << endl;
				}
				else
				{
					cout << "Femenino" << endl;
				};
				cout << "nacionalidad : ";
				if (nacioToSAux == "1")
				{
					cout << "Colombiano" << endl;
				}
				else
				{
					cout << "Extranjero" << endl;
				};
				cout << "estado civil : ";
				if (estToSAux == "1")
				{
					cout << "soltero" << endl;
				}
				if (estToSAux == "2")
				{
					cout << "casado" << endl;
				}
				if (estToSAux == "3")
				{
					cout << "separado" << endl;
				}
				if (estToSAux == "4")
				{
					cout << "viudo" << endl;
				}
				cout << "fecha de nacimiento : " << fechaNAux << endl;
				cout << "RH : " << RHAux << endl;
				cout << "\n";
				
				getline(leer_est, cedulaAx);

				while (!leer_est.eof()) // leer mmientras no sea el final del archivo
				{
					getline(leer_est, entidadEdAx);
					getline(leer_est, tituloAx);
					getline(leer_est, fechaTAx);
					getline(leer_est, activoE);

					if (cedulaAux == cedulaAx)
					{
						if(activoE!="")
						{
							cout << "____________________________________________" << endl;
							cout << "Estudios de " << nombre1Aux << ":" << endl
								 << endl;
							cout << "cedula : " << cedulaAx << endl;
							cout << "Entidad educativa : " << entidadEdAx << endl;
							cout << "Titulo : " << tituloAx << endl;
							cout << "Fecha de terminacion : " << fechaTAx << endl;
							cout << "--------------------------------------------" << endl;
						}
					}
					getline(leer_est, cedulaAx);
				}
				cout << "\n";
				leer_est.close();
				leer_est.open("Estudios.txt", ios::in);
			}
			getline(lectura, cedulaAux);
		}		
	}
	else
	{
		error();
	}
	lectura.close();
	leer_est.close();
	pausa();
}

void Estudios::modificar_est()
{
	system(CLEAR);

	ifstream lectura;
	ofstream auxiliar;

	bool encontrado = false;

	string auxCodigo;
	string tempCed;
	char respuesta[5];
	int opt = 0;

	lectura.open("Estudios.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);

	cout << "\t\t\t\t\255Modificar datos!\t\t\t\t\n\n";
	if (lectura.is_open() && auxiliar.is_open())
	{
		fflush(stdin);
		cout << "Digite la cedula de la persona a modificar: ";
		getline(cin, auxCodigo);

		getline(lectura, cedula);
		while (!lectura.eof())
		{
			getline(lectura, entidadEd);
			getline(lectura, titulo);
			getline(lectura, fechaT);
			getline(lectura, activoE);

			if (auxCodigo == cedula && activoE != "")
			{
				encontrado = true;
				cout << "\n\nRegistro Encontrado\n\n";
				cout << "Cedula : " << cedula << endl;
				cout << "Entidad educativa : " << entidadEd<<endl;
				cout << "Titulo : " << titulo<< endl;
				cout << "Fecha de terminacion : " << fechaT << endl;
				
				cout << endl<<"MODIFICANDO DATOS DEL REGISTRO";

				tempCed=cedula;

				cout << "\n\n Digite Instituto : ";
				getline(cin, entidadEd);
				if (entidadEd == "")
				{
					do
					{
						cout << "\n\n Digite Instituto : ";
						getline(cin, entidadEd);
					} while (entidadEd == "");
				}

				cout << "\n\n Digite titulo : ";
				getline(cin, titulo);
				if (titulo == "")
				{
					do
					{
						cout << "\n\n Digite Titulo : ";
						getline(cin, titulo);
					} while (titulo == "");
				}

				cout << "\n\n Digite el dia de terminacion: ";
				cin >> diaN;

				cout << endl
					 << " Digite su mes de terminacion: ";
				cin >> mesN;

				cout << endl
					 << " Digite su año de terminacion: ";
				cin >> anoN;

				auto diatS = std::to_string(diaN);
				auto mestS = std::to_string(mesN);
				auto anotS = std::to_string(anoN);

				fechaT = diatS + "-" + mestS + "-" + anotS;

				tm timeinfo = tm();
				int anotemp = anoN - 1900;
				timeinfo.tm_mday = diaN;
				timeinfo.tm_mon = mesN + 1;
				timeinfo.tm_year = anotemp;

				auto t_x = mktime(&timeinfo);
				auto tp_x = chrono::system_clock::from_time_t(t_x);
				auto tp_hoy = chrono::system_clock::now();
				auto diferencia = tp_hoy - tp_x;
				
				const int SEGS_POR_DIA = 60 * 60 * 24;
				typedef chrono::duration<int, ratio<SEGS_POR_DIA>> dias_t;
				int n_dias = chrono::duration_cast<dias_t>(diferencia).count();

				if ((n_dias+6570)< 6570)//fecha de nacimiento
				{
					cout << endl
						 << "No se puede modificar porque usted ha puesto una fecha incorrecta!" << endl;
						 system("pause");
					return;
				}else if(n_dias < 0){ //verificar fecha de hoy
						cout << endl
						 << "No se puede modificar porque usted ha puesto una fecha incorrecta!" << endl;
						 system("pause");
					return;
				}

				auxiliar << tempCed << endl
						   << entidadEd << endl
						   << titulo << endl
						   << fechaT << endl
						   << activoE << endl;
			}
			else
			{
				auxiliar << cedula << endl
						   << entidadEd << endl
						   << titulo << endl
						   << fechaT << endl
						   << activoE << endl;
			}
			getline(lectura, cedula);
		}
		if (encontrado == false)
		{
			cout << "\n\nNo se encontr\242 la cedula: " << auxCodigo << "\n\n";
		}
	}
	lectura.close();
	auxiliar.close();
	remove("Estudios.txt");
	rename("auxiliar.txt", "Estudios.txt");
	pausa();
}

void Estudios::retirar_est()
{
	system(CLEAR);

	ifstream lectura;
	ofstream auxiliar;

	bool encontrado = false;

	string auxCodigo;
	char respuesta[5];

	lectura.open("Estudios.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);

	cout << "\t\t\t\t*** Eliminar un registro de estudiante ***\t\t\t\t\n\n";
	if (lectura.is_open() && auxiliar.is_open())
	{
		fflush(stdin);
		cout << "Ingresa la cedula del registro que deseas eliminar: ";
		getline(cin, auxCodigo);

		getline(lectura, cedula);
		while (!lectura.eof())
		{
			getline(lectura, entidadEd);
			getline(lectura, titulo);
			getline(lectura, fechaT);
			getline(lectura, activoE);

			if (auxCodigo == cedula)
			{
				encontrado = true;
				cout << "\n\nRegistro Encontrado\n\n";
				cout << "Cedula : " << cedula << endl;
				cout << "Entidad educativa : " << entidadEd<<endl;
				cout << "Titulo : " << titulo<< endl;
				cout << "Fecha de terminacion : " << fechaT << endl;

				cout << endl<<"Realmente deseas dar de baja (s/n)?: ";
				cin.getline(respuesta, 5);

				if (strcmp(respuesta, "s") == 0 || strcmp(respuesta, "S") == 0 ||
					strcmp(respuesta, "si") == 0 || strcmp(respuesta, "SI") == 0 ||
					strcmp(respuesta, "Si") == 0 || strcmp(respuesta, "sI") == 0)
				{
					cout << "\n\n\255Los datos del estudiante se ha eliminado correctamente!\n\n";
				}
				else
				{
					cout << "\n\n\255Datos de estudiantes conservados!\n\n";
					auxiliar << cedula << endl
						   << entidadEd << endl
						   << titulo << endl
						   << fechaT << endl
						   << activoE << endl;
				}
			}
			else
			{
				auxiliar << cedula << endl
						   << entidadEd << endl
						   << titulo << endl
						   << fechaT << endl
						   << activoE << endl;
			}

			getline(lectura, cedula);
		}
		if (encontrado == false)
		{
			cout << "\n\nNo se encontr\242 la cedula: " << auxCodigo << "\n\n";
		}
	}
	else
	{
		error();
	}
	lectura.close();
	auxiliar.close();
	remove("Estudios.txt");
	rename("auxiliar.txt", "Estudios.txt");
	pausa();
}

void HLaboral::menu_H()
{
	int opc;
	opc = 9;
	do
	{
		system(CLEAR);
		cout << "\n REGISTRAR DATOS DE HISTORIA LABORAL " << endl
			 << endl;
		cout << "1. Ingresar Datos de su historia laboral" << endl;
		cout << "2. Retirar Datos de su historia laboral" << endl;
		cout << "3. Modificar Datos de su historia laboral" << endl;
		cout << "4. Listar Datos de su historia laboral" << endl;
		cout << "5. Borrado Logico de su historia laboral" << endl;
		cout << "6. Activar Logico de su historia laboral" << endl;
		cout << "7. Salir del Menu" << endl
			 << endl;
		cout << "Digite Opcion :  ";
		cin >> opc;
		fflush(stdin);

		switch (opc)
		{
		case 1:
			ingresar_H();
			break;
		case 2:
			retirar_H();
			break;
		case 3:
			modificar_H();
			break;
		case 4:
			listar_H();
			break;
		case 5:
			borrado_logico_H();
			break;
		case 6:
			activar_logico_H();
			break;
		case 7:
			opc=0;
			break;
		default:
			cout << "Ha ingresado una opcion no valida ";
		}
	} while (opc != 0);
}

void HLaboral::ingresar_H()
{
	system(CLEAR);

	ofstream arIngresar; // estudios
	ifstream lectura;	 // Datos DBasicos

	string bus_cedula;

	string cedula;
	string empresa;
	string cargo;
	string fechaIni;
	string fechaTer;
	string activoH;

	int encontro;
	encontro = 0;

	lectura.open("DBasicos.txt", ios::in);
	arIngresar.open("HLaboral.txt", ios::app);
	if (arIngresar.is_open())
	{
		cout << "Historia laboral";
	}
	else
	{
		arIngresar.close();
		ofstream escribir_est;
		arIngresar.open("HLaboral.txt", ios::out);
	}

	if (arIngresar.is_open() && lectura.is_open()) // Validamos que el archivo "arIngresar no presento error
	{
		cout << "\n\n Digite Datos de Estudios ";
		cout << "\n\n Digite Cedula  : ";
		getline(cin, bus_cedula);
		fflush(stdin);

		if (bus_cedula == "") // validamos que el nombre2 no este vacio
		{
			do
			{
				cout << "\n\n Digite Cedula : ";
				getline(cin, bus_cedula);
			} while (bus_cedula == "");
		}

		getline(lectura, cedula);

		while (!lectura.eof() && encontro == 0)
		{

			if (cedula == bus_cedula)
			{
				encontro = 1;
				cout << "\n\n Digite Empresa : ";
				getline(cin, empresa);
				if (empresa == "")
				{
					do
					{
						cout << "\n\n Digite Empresa : ";
						getline(cin, empresa);
					} while (empresa == "");
				}

				cout << "\n\n Digite cargo : ";
				getline(cin, cargo);
				if (cargo == "")
				{
					do
					{
						cout << "\n\n Digite cargo : ";
						getline(cin, cargo);
					} while (cargo == "");
				}

				cout << "\n\n Digite el dia de inicio: ";
				cin >> diaN;

				cout << endl
					 << " Digite su mes de inicio: ";
				cin >> mesN;

				cout << endl
					 << " Digite su año de inicio: ";
				cin >> anoN;

				auto diatS = std::to_string(diaN);
				auto mestS = std::to_string(mesN);
				auto anotS = std::to_string(anoN);

				fechaIni = diatS + "-" + mestS + "-" + anotS;

				tm timeinfo = tm();
				int anotemp = anoN - 1900;
				timeinfo.tm_mday = diaN;
				timeinfo.tm_mon = mesN + 1;
				timeinfo.tm_year = anotemp;

				auto t_x = mktime(&timeinfo);
				auto tp_x = chrono::system_clock::from_time_t(t_x);
				auto tp_hoy = chrono::system_clock::now();
				auto diferencia = tp_hoy - tp_x;

				const int SEGS_POR_DIA = 60 * 60 * 24;
				typedef chrono::duration<int, ratio<SEGS_POR_DIA>> dias_t;
				int n_dias = chrono::duration_cast<dias_t>(diferencia).count();

				cout << "\n\n Digite el dia de terminacion: ";
				cin >> diaN2;

				cout << endl
					 << " Digite su mes de terminacion: ";
				cin >> mesN2;

				cout << endl
					 << " Digite su año de terminacion: ";
				cin >> anoN2;

				auto diatS2 = std::to_string(diaN2);
				auto mestS2= std::to_string(mesN2);
				auto anotS2 = std::to_string(anoN2);

				fechaTer = diatS2 + "-" + mestS2 + "-" + anotS2;

				int anotemp2 = anoN - 1900;
				timeinfo.tm_mday = diaN;
				timeinfo.tm_mon = mesN + 1;
				timeinfo.tm_year = anotemp2;

				auto t_x1 = mktime(&timeinfo);
				auto tp_x1 = chrono::system_clock::from_time_t(t_x1);
				auto tp_hoy1 = chrono::system_clock::now();
				auto diferenciaHoy = tp_hoy1 - tp_x1;
				
				const int SEGS_POR_DIA1 = 60 * 60 * 24;
				typedef chrono::duration<int, ratio<SEGS_POR_DIA1>> dias_t;
				int n_diasHoy = chrono::duration_cast<dias_t>(diferenciaHoy).count();
				if ((n_dias+6569)< 6570)//inicio trabajo con fecha de nacimiento
				{
					cout << endl
						 << "No se puede postular porque usted ha puesto una fecha incorrecta!" << endl;
					return;
				}
				else if ((n_diasHoy-n_dias)< 0)//fecha en que salio
				{
					cout << endl
						 << "No se puede postular porque usted ha puesto una fecha incorrecta!" << endl;
					return;
				}
				activoH="0";
				cedula = bus_cedula;
				arIngresar << cedula << endl
						   << empresa << endl
						   << cargo << endl
						   << fechaIni << endl
						   << fechaTer << endl
						   << activoH << endl;
				system("pause");
			}
			getline(lectura, cedula);
		}
		if (encontro == 0)
		{
			cout << "\n\n La cedula no existe en el archivo";
			getch();
		}
	}
	arIngresar.close();
	lectura.close();
}

void HLaboral::activar_logico_H()
{
	system(CLEAR);

	ifstream lectura;
	ofstream auxiliar;

	bool encontrado = false;

	string auxCodigo;
	char respuesta[5];

	lectura.open("HLaboral.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);

	cout << "\t\t\t\t*** Activar de forma logica ***\t\t\t\t\n\n";
	if (lectura.is_open() && auxiliar.is_open())
	{
		fflush(stdin);
		cout << "Activando los Registros Inactivos" << endl;
		getline(lectura, cedula);
		while (!lectura.eof())
		{
			getline(lectura, empresa);
			getline(lectura, cargo);
			getline(lectura, fechaIni);
			getline(lectura, fechaTer);
			getline(lectura, activoH);

			activoH = "0";
			auxiliar << cedula << endl
						   << empresa << endl
						   << cargo << endl
						   << fechaIni << endl
						   << fechaTer << endl
						   << activoH << endl;

			getline(lectura, cedula);
		}
		cout << "\255El proceso de activacion de registros ha concluido exitosamente!" << endl;
	}
	else
	{
		error();
	}
	lectura.close();
	auxiliar.close();
	remove("HLaboral.txt");
	rename("auxiliar.txt", "HLaboral.txt");
	pausa();
}

void HLaboral::borrado_logico_H()
{
	system(CLEAR);

	ifstream lectura;
	ofstream auxiliar;

	bool encontrado = false;

	string auxCodigo;
	char respuesta[5];

	lectura.open("HLaboral.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);

	cout << "\t\t\t\t*** Eliminar Historia laboral de forma logica ***\t\t\t\t\n\n";
	if (lectura.is_open() && auxiliar.is_open())
	{
		fflush(stdin);
		cout << "Ingresa la cedula de la persona que deseas eliminar: ";
		getline(cin, auxCodigo);

		getline(lectura, cedula);
		while (!lectura.eof())
		{
			getline(lectura, empresa);
			getline(lectura, cargo);
			getline(lectura, fechaIni);
			getline(lectura, fechaTer);
			getline(lectura, activoH);

			if (auxCodigo == cedula && activoH != "")
			{
				encontrado = true;
				cout << "\n\nRegistro Encontrado\n\n";
				cout << "Cedula : " << cedula << endl;
				cout << "Empresa : " << empresa<<endl;
				cout << "Cargo : " << cargo<< endl;
				cout << "Fecha de inicio : " << fechaIni << endl;
				cout << "Fecha de terminacion : " << fechaTer << endl;

				cout << "Realmente deseas dar de Baja-Logico  (s/n)?: ";
				cin.getline(respuesta, 5);

				if (strcmp(respuesta, "s") == 0 || strcmp(respuesta, "S") == 0 ||
					strcmp(respuesta, "si") == 0 || strcmp(respuesta, "SI") == 0 ||
					strcmp(respuesta, "Si") == 0 || strcmp(respuesta, "sI") == 0)

				{
					cout << "\n\nEl Amigo se ha dado de baja correctamente\n\n";
					activoH = "";
					auxiliar << cedula << endl
						   << empresa << endl
						   << cargo << endl
						   << fechaIni << endl
						   << fechaTer << endl
						   << activoH << endl;
				}
				else
				{
					cout << "\n\nCliente conservado\n\n";
					auxiliar << cedula << endl
						   << empresa << endl
						   << cargo << endl
						   << fechaIni << endl
						   << fechaTer << endl
						   << activoH << endl;
				}
			}
			else
			{
				auxiliar << cedula << endl
						   << empresa << endl
						   << cargo << endl
						   << fechaIni << endl
						   << fechaTer << endl
						   << activoH << endl;
			}

			getline(lectura, cedula);
		}
		if (encontrado == false)
		{
			cout << "\n\nNo se encontr\242 la cedula: " << auxCodigo << "\n\n";
		}
	}
	else
	{
		error();
	}
	lectura.close();
	auxiliar.close();
	remove("HLaboral.txt");
	rename("auxiliar.txt", "HLaboral.txt");
	pausa();
}

void HLaboral::listar_H()
{
	system(CLEAR);

	int i = 0;
	ifstream lectura;
	ifstream leer_est;

	string cedulaAux, nombre1Aux, nombre2Aux, apellido1Aux, apellido2Aux, telefonoAux, direccionAux, correoAux, SextoSAux, nacioToSAux, estToSAux, fechaNAux, RHAux, activoAux;

	string cedulaAx;
	string empresaAx;
	string cargoAx;
	string fechaIniAx;
	string fechaTerAx;
	string activoHAx;

	lectura.open("DBasicos.txt", ios::in);
	leer_est.open("HLaboral.txt", ios::in);

	if (lectura.is_open() && leer_est.is_open()) // validamos que no presente error en la apertura del archivo
	{

		cout << "\t\t\t\t***Listado de todos los registros de historia laboral***\t\t\t\t\n\n";
		getline(lectura, cedulaAux);
		while (!lectura.eof()) // leer mmientras no sea el final del archivo
		{
			getline(lectura, nombre1Aux);
			getline(lectura, nombre2Aux);
			getline(lectura, apellido1Aux);
			getline(lectura, apellido2Aux);
			getline(lectura, telefonoAux);
			getline(lectura, direccionAux);
			getline(lectura, correoAux);
			getline(lectura, SextoSAux);
			getline(lectura, nacioToSAux);
			getline(lectura, estToSAux);
			getline(lectura, fechaNAux);
			getline(lectura, RHAux);
			getline(lectura, activoAux);

			if (activoAux != "") //( strcmp(activo,"0" == 0 )
			{
				cout<<"Datos de "<<nombre1Aux<<": "<<endl<<endl;
				cout << "Cedula : " << cedulaAux << endl;
				cout << "Nombres : " << nombre1Aux << " " << nombre2Aux << endl;
				cout << "Apellidos : " << apellido1Aux << " " << apellido2Aux << endl;
				cout << "telefono : " << telefonoAux << endl;
				cout << "direccion : " << direccionAux << endl;
				cout << "correo : " << correoAux << endl;
				cout << "sexo : ";
				if (SextoSAux == "1")
				{
					cout << "Masculino" << endl;
				}
				else
				{
					cout << "Femenino" << endl;
				};
				cout << "nacionalidad : ";
				if (nacioToSAux == "1")
				{
					cout << "Colombiano" << endl;
				}
				else
				{
					cout << "Extranjero" << endl;
				};
				cout << "estado civil : ";
				if (estToSAux == "1")
				{
					cout << "soltero" << endl;
				}
				if (estToSAux == "2")
				{
					cout << "casado" << endl;
				}
				if (estToSAux == "3")
				{
					cout << "separado" << endl;
				}
				if (estToSAux == "4")
				{
					cout << "viudo" << endl;
				}
				cout << "fecha de nacimiento : " << fechaNAux << endl;
				cout << "RH : " << RHAux << endl;
				cout << "\n";
				
				getline(leer_est, cedulaAx);

				while (!leer_est.eof()) // leer mmientras no sea el final del archivo
				{
					getline(leer_est, empresaAx);
					getline(leer_est, cargoAx);
					getline(leer_est, fechaIniAx);
					getline(leer_est, fechaTerAx);
					getline(leer_est, activoH);

					if (cedulaAux == cedulaAx)
					{
						if(activoH!="")
						{
							cout << "____________________________________________" << endl;
							cout << "Cedula : " << cedulaAx << endl;
							cout << "Empresa : " << empresaAx << endl;
							cout << "Cargo : " << cargoAx << endl;
							cout << "Fecha de inicio : " << fechaIniAx << endl;
							cout << "Fecha de terminacion : " << fechaTerAx << endl;
							cout << "--------------------------------------------" << endl;
						}
					}
					getline(leer_est, cedulaAx);
				}
				cout << "\n";
				leer_est.close();
				leer_est.open("HLaboral.txt", ios::in);
			}
			getline(lectura, cedulaAux);
		}		
	}
	else
	{
		error();
	}
	lectura.close();
	leer_est.close();
	pausa();
}

void HLaboral::modificar_H()
{
	system(CLEAR);

	ifstream lectura;
	ofstream auxiliar;

	bool encontrado = false;

	string auxCodigo;
	string tempCed;
	char respuesta[5];
	int opt = 0;

	lectura.open("HLaboral.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);

	cout << "\t\t\t\t\255Modificar datos!\t\t\t\t\n\n";
	if (lectura.is_open() && auxiliar.is_open())
	{
		fflush(stdin);
		cout << "Digite la cedula de la persona a modificar: ";
		getline(cin, auxCodigo);

		getline(lectura, cedula);
		while (!lectura.eof())
		{
			getline(lectura, empresa);
			getline(lectura, cargo);
			getline(lectura, fechaIni);
			getline(lectura, fechaTer);
			getline(lectura, activoH);

			if (auxCodigo == cedula && activoH != "")
			{
				encontrado = true;
				cout << "\n\nRegistro Encontrado\n\n";
				cout << "Cedula : " << cedula << endl;
				cout << "Empresa : " << empresa<<endl;
				cout << "Cargo : " << cargo<< endl;
				cout << "Fecha de inicio : " << fechaIni << endl;
				cout << "Fecha de terminacion : " << fechaTer << endl;
				
				cout << endl<<"MODIFICANDO DATOS DEL REGISTRO";

				tempCed=cedula;

				cout << "\n\n Digite empresa : ";
				getline(cin, empresa);
				if (empresa == "")
				{
					do
					{
						cout << "\n\n Digite empresa : ";
						getline(cin, empresa);
					} while (empresa == "");
				}

				cout << "\n\n Digite cargo : ";
				getline(cin, cargo);
				if (cargo == "")
				{
					do
					{
						cout << "\n\n Digite Cargo : ";
						getline(cin, cargo);
					} while (cargo == "");
				}

				cout << "\n\n Digite el dia de inicio: ";
				cin >> diaN;

				cout << endl
					 << " Digite su mes de inicio: ";
				cin >> mesN;

				cout << endl
					 << " Digite su año de inicio: ";
				cin >> anoN;

				auto diatS = std::to_string(diaN);
				auto mestS = std::to_string(mesN);
				auto anotS = std::to_string(anoN);

				fechaIni = diatS + "-" + mestS + "-" + anotS;

				tm timeinfo = tm();
				int anotemp = anoN - 1900;
				timeinfo.tm_mday = diaN;
				timeinfo.tm_mon = mesN + 1;
				timeinfo.tm_year = anotemp;

				auto t_x = mktime(&timeinfo);
				auto tp_x = chrono::system_clock::from_time_t(t_x);
				auto tp_hoy = chrono::system_clock::now();
				auto diferencia = tp_hoy - tp_x;

				const int SEGS_POR_DIA = 60 * 60 * 24;
				typedef chrono::duration<int, ratio<SEGS_POR_DIA>> dias_t;
				int n_dias = chrono::duration_cast<dias_t>(diferencia).count();

				cout << "\n\n Digite el dia de terminacion: ";
				cin >> diaN2;

				cout << endl
					 << " Digite su mes de terminacion: ";
				cin >> mesN2;

				cout << endl
					 << " Digite su año de terminacion: ";
				cin >> anoN2;

				auto diatS2 = std::to_string(diaN2);
				auto mestS2= std::to_string(mesN2);
				auto anotS2 = std::to_string(anoN2);

				fechaTer = diatS2 + "-" + mestS2 + "-" + anotS2;

				int anotemp2 = anoN - 1900;
				timeinfo.tm_mday = diaN;
				timeinfo.tm_mon = mesN + 1;
				timeinfo.tm_year = anotemp2;

				auto t_x1 = mktime(&timeinfo);
				auto tp_x1 = chrono::system_clock::from_time_t(t_x1);
				auto tp_hoy1 = chrono::system_clock::now();
				auto diferenciaHoy = tp_hoy1 - tp_x1;
				
				const int SEGS_POR_DIA1 = 60 * 60 * 24;
				typedef chrono::duration<int, ratio<SEGS_POR_DIA1>> dias_t;
				int n_diasHoy = chrono::duration_cast<dias_t>(diferenciaHoy).count();
				if ((n_dias+6569)< 6570)//inicio trabajo con fecha de nacimiento
				{
					cout << endl
						 << "No se puede postular porque usted ha puesto una fecha incorrecta!" << endl;
					return;
				}
				else if ((n_diasHoy-n_dias)< 0)//fecha en que salio
				{
					cout << endl
						 << "No se puede postular porque usted ha puesto una fecha incorrecta!" << endl;
					return;
				}

				auxiliar << tempCed << endl
						   << empresa << endl
						   << cargo << endl
						   << fechaIni << endl
						   << fechaTer << endl
						   << activoH << endl;
			}
			else
			{
				auxiliar << cedula << endl
						   << empresa << endl
						   << cargo << endl
						   << fechaIni << endl
						   << fechaTer << endl
						   << activoH << endl;
			}
			getline(lectura, cedula);
		}
		if (encontrado == false)
		{
			cout << "\n\nNo se encontr\242 la cedula: " << auxCodigo << "\n\n";
		}
	}
	lectura.close();
	auxiliar.close();
	remove("HLaboral.txt");
	rename("auxiliar.txt", "HLaboral.txt");
	pausa();
}

void HLaboral::retirar_H()
{
	ifstream lectura;
	ofstream auxiliar;

	bool encontrado = false;

	string auxCodigo;
	char respuesta[5];

	lectura.open("HLaboral.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);

	cout << "\t\t\t\t*** Eliminar una historia laboral ***\t\t\t\t\n\n";
	if (lectura.is_open() && auxiliar.is_open())
	{
		fflush(stdin);
		cout << "Ingresa la cedula del registro que deseas dar eliminar: ";
		getline(cin, auxCodigo);

		getline(lectura, cedula);
		while (!lectura.eof())
		{
			getline(lectura, cargo);
			getline(lectura, empresa);
			getline(lectura, fechaIni);
			getline(lectura, fechaTer);
			getline(lectura, activoH);

			if (auxCodigo == cedula)
			{
				encontrado = true;
				cout << "\n\nRegistro Encontrado\n\n";
				cout << "Cedula : " << cedula << endl;
				cout << "Empresa : " << empresa<<endl;
				cout << "Cargo : " << cargo<< endl;
				cout << "Fecha de inicio : " << fechaIni << endl;
				cout << "Fecha de terminacion : " << fechaTer << endl;

				cout << endl<<"Realmente deseas dar de baja  (s/n)?: ";
				cin.getline(respuesta, 5);

				if (strcmp(respuesta, "s") == 0 || strcmp(respuesta, "S") == 0 ||
					strcmp(respuesta, "si") == 0 || strcmp(respuesta, "SI") == 0 ||
					strcmp(respuesta, "Si") == 0 || strcmp(respuesta, "sI") == 0)
				{
					cout << "\n\n\255La historia laboral se ha eliminado correctamente!\n\n";
				}
				else
				{
					cout << "\n\n\255Historia laboral conservada!\n\n";
					auxiliar << cedula << endl
						   << empresa << endl
						   << cargo << endl
						   << fechaIni << endl
						   << fechaTer << endl
						   << activoH << endl;
				}
			}
			else
			{
				auxiliar << cedula << endl
						   << empresa << endl
						   << cargo << endl
						   << fechaIni << endl
						   << fechaTer << endl
						   << activoH << endl;
			}

			getline(lectura, cedula);
		}
		if (encontrado == false)
		{
			cout << "\n\nNo se encontr\242 la cedula: " << auxCodigo << "\n\n";
		}
	}
	else
	{
		error();
	}
	lectura.close();
	auxiliar.close();
	remove("HLaboral.txt");
	rename("auxiliar.txt", "HLaboral.txt");
	pausa();
}

main()
{
	system("color 37");

	int opc;
	opc = 9;

	DBasicos inicio;
	Estudios entrar;
	HLaboral palJale;
	do
	{
		system(CLEAR);
		cout << "\n \255Registro de hojas de vida!" << endl
			 << endl;
		cout << "1. Datos basicos" << endl;
		cout << "2. Estudios" << endl;
		cout << "3. Historia laboral" << endl;
		cout << "4. Salir del Menu" << endl
			 << endl;
		cout << "Digite Opcion :  ";
		cin >> opc;
		fflush(stdin);

		switch (opc)
		{
		case 1:
			inicio.menu();
			break;
		case 2:
			entrar.menu_est();
			break;
		case 3:
			palJale.menu_H();
			break;
		case 4:
			opc = 0;
			break;
		default:
			cout << "Digito una opcion no valida!";
		}
	} while (opc != 0);
}

void pausa()
{
	cout << "Presiona Enter para continuar...";
	getch();
	system(CLEAR);
}

void error()
{
	cout << "Error!";
}

//Andres Camilo Gonzalez Velasquez - 20201187519
//Cristian Stiven Perdomo Garcia - 20201188463