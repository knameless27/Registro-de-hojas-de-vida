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

public:
	void ingresar_est();
	void retirar_est();
	void modificar_est();
	void listar_est();
	void borrado_logico_est();
	void activar_logico_est();
	void menu_est();
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
				cout << "fechaT de nacimiento : " << fechaN << endl;
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
		cout << "\n REGISTRAR DATOS ESTUDIOS " << endl
			 << endl;
		cout << "1. Ingresar Datos Estudios" << endl;
		cout << "2. Retirar Datos Estudios" << endl;
		cout << "3. Modificar Datos Estudios" << endl;
		cout << "4. Listar Datos Estudios " << endl;
		cout << "5. Borrado Logico Estudios" << endl;
		cout << "6. Acticar Logico Estudios" << endl;
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
	ofstream arIngresar; // estudios
	ifstream lectura;	 // Datos DBasicos

	string bus_cedula;

	string aux1_nombre;
	string aux1_codigo;
	string aux1_cedula;
	string aux1_activo;

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

		getline(lectura, aux1_cedula);

		while (!lectura.eof() && encontro == 0)
		{
			getline(lectura, aux1_codigo);
			getline(lectura, aux1_nombre);
			getline(lectura, aux1_activo);

			// cout <<aux1_cedula <<endl<<aux1_nombre<<endl;

			if (aux1_cedula == bus_cedula)
			{
				cout << aux1_cedula << endl
					 << aux1_nombre << endl;

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
				system("pause");
				if (n_dias < 6570)
				{
					cout << endl
						 << "No se puede postular porque usted es menor de edad!" << endl;
					return;
				}else if(n_dias < t_x){
						
					return;
				}
				cedula = bus_cedula;
				arIngresar << cedula << endl
						   << entidadEd << endl
						   << titulo << endl
						   << fechaT << endl;
			}
			getline(lectura, aux1_cedula);
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
}

void Estudios::borrado_logico_est()
{
}

void Estudios::listar_est()
{
	int i = 0;
	ifstream lectura;
	ifstream leer_est;

	string aux1_nombre;
	string aux1_codigo;
	string aux1_cedula;
	string aux1_activo;

	lectura.open("DBasicos.txt", ios::in);
	leer_est.open("Estudios.txt", ios::in);

	if (lectura.is_open() && leer_est.is_open()) // validamos que no presente error en la apertura del archivo
	{

		cout << "\t\t\t\t***Listado de todos los clientes***\t\t\t\t\n\n";
		getline(lectura, aux1_cedula);

		while (!lectura.eof()) // leer mmientras no sea el final del archivo
		{
			getline(lectura, aux1_codigo);
			getline(lectura, aux1_nombre);
			getline(lectura, aux1_activo);

			if (aux1_activo == "0") //( strcmp(activo,"0" == 0 )
			{
				cout << "Cedula : " << aux1_cedula << endl;
				cout << "C\242digo : " << aux1_codigo << endl;
				cout << "Nombre : " << aux1_nombre << endl;
				i++;

				getline(leer_est, cedula);

				while (!leer_est.eof()) // leer mmientras no sea el final del archivo
				{
					getline(leer_est, entidadEd);
					getline(leer_est, titulo);
					getline(leer_est, fechaT);

					if (aux1_cedula == cedula)
					{
						cout << "\n Instituto  : " << entidadEd;
						cout << "\n Titulo     : " << titulo;
						cout << "\n Fecha      : " << fechaT;
					}
					getline(leer_est, cedula);
				}
				cout << "\n";
				leer_est.close();
				leer_est.open("Estudios.txt", ios::in);
			}
			getline(lectura, aux1_cedula);
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
}

void Estudios::retirar_est()
{
}

main()
{
	system("color 37");

	int opc;
	opc = 9;

	DBasicos inicio;
	Estudios entrar;
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
			entrar.menu_est();
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
	cout << "No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
	cout << "la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
	cout << "clientes.txt, si el archivo tiene otro nombre2 ren\242mbrelo al ya mencionado\n\n";
}
