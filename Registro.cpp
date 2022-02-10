//Registro Agenda

#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>


//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

using namespace std;

class Agenda
{
	private:
    	string cedula;
    	string codigo;
    	string nombre;
    	string activo;

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
    	string instituto;
    	string titulo;
    	string fecha;

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


// Menu general Agenda
void Agenda::menu()
{
	int opc;
	opc = 9;
	do
	{
		system(CLEAR);
		cout <<"\n REGISTRAR DATOS AGENDA "<<endl<<endl;
		cout <<"1. Ingresar Datos Agenda"<<endl;
		cout <<"2. Retirar Datos Agenda"<<endl;
		cout <<"3. Modificar Datos Agenda"<<endl;
		cout <<"4. Listar Datos Agenda "<<endl;
		cout <<"5. Borrado Logico "<<endl;
		cout <<"6. Acticar Logico "<<endl;
			
		cout <<"0. Salir del Menu"<<endl<<endl;
		cout <<"Digite Opcion :  ";
		cin >> opc;
		fflush(stdin);
		
		switch(opc)
		{
			case 1: ingresar(); break;
			case 2: retirar(); break;
			case 3: modificar(); break;
			case 4: listar(); break;
			case 5: borrado_logico(); break;
			case 6: activar_logico(); break;
			
			default : cout <<"Ingreso Opcion no valida "; 
		}
	}
	while ( opc != 0 );	
}

// Ingresar datos
void Agenda::ingresar()
{
	ofstream escribir;
	/* string aux_nombre;
    string aux_codigo;
    string aux_cedula;
    string aux_activo;
	*/
	escribir.open("Agenda.txt",ios::app);
	
	if ( escribir.is_open() ) //Validamos que el archivo "escribir no presento error
 	{
		cout<<"\n\n Digite datos en la Agenda ";
		cout<<"\n\n Digite Nombre : ";
		getline(cin,nombre);
		
		if ( nombre == "" ) // validamos que el nombre no este vacio
		{
			do
			{
				cout<<"\n\n Digite Nombre : ";
				getline(cin,nombre);	
			}
			while (nombre == "" );
		}
		
		cout<<"\n\n Digite Codigo : ";
		getline(cin,codigo);
		if ( codigo == "" )
		{
			do
			{
				cout<<"\n\n Digite Codigo : ";
				getline(cin,codigo);	
			}
			while (codigo == "" );
		}
		
		cout<<"\n\n Digite Cedula : ";
		getline(cin,cedula);
		if ( cedula == "" )
		{
			do
			{
				cout<<"\n\n Digite Cedula : ";
				getline(cin,cedula);	
			}
			while (cedula == "" );
		}
	}
	activo = "0";
	escribir<<cedula<<endl<<codigo<<endl<<nombre<<endl<<activo<<endl;	

	/*
	escribir<<aux_cedula<<endl<<aux_codigo<<endl<<aux_nombre<<endl<<aux_activo<<endl;	

	
	este forma es igual a la linea anterior 
	escribir<<aux_cedula<<endl;
	escribir<<aux_codigo<<endl;
	escribir<<aux_nombre<<endl;	
	*/
	escribir.close();
	
}

//Modificar datos
void Agenda::modificar()
{
	ifstream lectura;
    ofstream auxiliar;
    
    bool encontrado=false;
    
    string auxCodigo;
    char respuesta[5];
    
    lectura.open("Agenda.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    
    cout<<"\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
    if ( lectura.is_open() && auxiliar.is_open() )
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del Amigo que deseas Modificar: ";
        getline(cin,auxCodigo);
        
        getline(lectura,cedula);
        while( !lectura.eof() )
        {
			getline(lectura,codigo);
            getline(lectura,nombre);
            getline(lectura,activo);

            if(auxCodigo == codigo && activo == "0")
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"Cedula : "<<cedula<<endl;
                cout<<"C\242digo : "<<codigo<<endl;
                cout<<"Nombre : "<<nombre<<endl;
                
                cout<<"MODIFICANDO DATOS DEL REGISTRO";
                
                cout<<"\n\n Digite Nombre : ";
				getline(cin,nombre);
		
				if ( nombre == "" ) // validamos que el nombre no este vacio
				{
					do
					{
						cout<<"\n\n Digite Nombre : ";
						getline(cin,nombre);	
					}
					while (nombre == "" );
				}
		
				cout<<"\n\n Digite Codigo : ";
				getline(cin,codigo);
				if ( codigo == "" )
				{
					do
					{
						cout<<"\n\n Digite Codigo : ";
						getline(cin,codigo);	
					}
					while (codigo == "" );
				}
		
				cout<<"\n\n Digite Cedula : ";
				getline(cin,cedula);
				if ( cedula == "" )
				{
					do
					{
						cout<<"\n\n Digite Cedula : ";
						getline(cin,cedula);	
					}
					while (cedula == "" );
            	}
                auxiliar<<cedula<<"\n"<<codigo<<"\n"<<nombre<<"\n"<<activo<<"\n";
            }
            else
            {
                auxiliar<<cedula<<"\n"<<codigo<<"\n"<<nombre<<"\n"<<activo<<"\n";
            }
            
            getline(lectura,cedula);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 el c\242digo: "<<auxCodigo<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("Agenda.txt");
    rename("auxiliar.txt","Agenda.txt");
    pausa();		
}

// borrado logico
void Agenda::borrado_logico()
{
   	ifstream lectura;
    ofstream auxiliar;
    
    bool encontrado=false;
    
    string auxCodigo;
    char respuesta[5];
    
    lectura.open("Agenda.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    
    cout<<"\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
    if ( lectura.is_open() && auxiliar.is_open() )
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del Amigo que deseas dar de baja: ";
        getline(cin,auxCodigo);
        
        getline(lectura,cedula);
        while( !lectura.eof() )
        {
			getline(lectura,codigo);
            getline(lectura,nombre);
            getline(lectura,activo);

            if(auxCodigo == codigo && activo == "0")
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"Cedula : "<<cedula<<endl;
                cout<<"C\242digo : "<<codigo<<endl;
                cout<<"Nombre : "<<nombre<<endl;
                
                cout<<"Realmente deseas dar de Baja-Logico  (s/n)?: ";
                cin.getline(respuesta,5);
                
                if(strcmp(respuesta,"s")==0 || strcmp(respuesta,"S")==0 ||
                   strcmp(respuesta,"si")==0 ||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                        
                  {
                    cout<<"\n\nEl Amigo se ha dado de baja correctamente\n\n";
                    activo = "1";
                    auxiliar<<cedula<<"\n"<<codigo<<"\n"<<nombre<<"\n"<<activo<<"\n";
                  }

                else
                {
                    cout<<"\n\nCliente conservado\n\n";
                    auxiliar<<cedula<<"\n"<<codigo<<"\n"<<nombre<<"\n"<<activo<<"\n";

                }

            }
            else
            {
                auxiliar<<cedula<<"\n"<<codigo<<"\n"<<nombre<<"\n"<<activo<<"\n";
            }
            
            getline(lectura,cedula);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 el c\242digo: "<<auxCodigo<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("Agenda.txt");
    rename("auxiliar.txt","Agenda.txt");
    pausa();
}

// activar logico
void Agenda::activar_logico()
{
   	ifstream lectura;
    ofstream auxiliar;
    
    bool encontrado=false;
    
    string auxCodigo;
    char respuesta[5];
    
    lectura.open("Agenda.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    
    cout<<"\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
    if ( lectura.is_open() && auxiliar.is_open() )
    {
        fflush(stdin);
        cout <<"Activando los Registros Inactivados"<<endl; 
        getline(lectura,cedula);
        while( !lectura.eof() )
        {
			getline(lectura,codigo);
            getline(lectura,nombre);
            getline(lectura,activo);
 
            activo = "0";
            auxiliar<<cedula<<"\n"<<codigo<<"\n"<<nombre<<"\n"<<activo<<"\n";
            
            getline(lectura,cedula);
        }
        cout <<"Fin Proceso de Activando los Registros"<<endl; 
    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("Agenda.txt");
    rename("auxiliar.txt","Agenda.txt");
    pausa();
}


// retirar
void Agenda::retirar()
{	
	ifstream lectura;
    ofstream auxiliar;
    
    bool encontrado=false;
    
    string auxCodigo;
    char respuesta[5];
    
    lectura.open("Agenda.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    
    cout<<"\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
    if ( lectura.is_open() && auxiliar.is_open() )
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del Amigo que deseas dar de baja: ";
        getline(cin,auxCodigo);
        
        getline(lectura,cedula);
        while( !lectura.eof() )
        {
			getline(lectura,codigo);
            getline(lectura,nombre);
            getline(lectura,activo);

            if(auxCodigo == codigo)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"Cedula : "<<cedula<<endl;
                cout<<"C\242digo : "<<codigo<<endl;
                cout<<"Nombre : "<<nombre<<endl;
                
                cout<<"Realmente deseas dar de baja  (s/n)?: ";
                cin.getline(respuesta,5);
                
                if(strcmp(respuesta,"s")==0 || strcmp(respuesta,"S")==0 ||
                   strcmp(respuesta,"si")==0 ||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                        
                  {
                    cout<<"\n\nEl Amigo se ha dado de baja correctamente\n\n";
                  }

                else
                {
                    cout<<"\n\nCliente conservado\n\n";
                    auxiliar<<cedula<<"\n"<<codigo<<"\n"<<nombre<<"\n"<<activo<<endl;

                }

            }
            else
            {
                auxiliar<<cedula<<"\n"<<codigo<<"\n"<<nombre<<"\n"<<activo<<endl;
            }
            
            getline(lectura,cedula);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 el c\242digo: "<<auxCodigo<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("Agenda.txt");
    rename("auxiliar.txt","Agenda.txt");
    pausa();
}

// Listar

void Agenda::listar()
{
    int i=0;
    ifstream lectura;
    lectura.open("Agenda.txt",ios::in);
    if(lectura.is_open())  // validamos que no presente error en la apertura del archivo
    {
        cout<<"\t\t\t\t***Listado de todos los clientes***\t\t\t\t\n\n";
        getline(lectura,cedula);
        
		
		while( !lectura.eof() ) // leer mmientras no sea el final del archivo
        {
            getline(lectura,codigo);
            getline(lectura,nombre);
            getline(lectura,activo);
            
            if (  activo == "0" )//( strcmp(activo,"0" == 0 )
            {
            	cout<<"Cedula : "<<cedula<<endl;
            	cout<<"C\242digo : "<<codigo<<endl;
            	cout<<"Nombre : "<<nombre<<endl;
                i++;
            	cout<<"\n";
        	}
            getline(lectura,cedula);
        }
        if(i==1)
			   cout<<"Hay un solo cliente registrado en este gimnasio\n\n";
        else
            cout<<"Hay un total de "<<i<<" clientes registrados en este gimnasio\n\n";
    }
    else
    {
        error();
    }
    lectura.close();
    pausa();
}
/*  fin procedimiento Agenda */

/* iniciamos procedimientos Estudios */
// Menu general Estudios
void Estudios::menu_est()
{
	int opc;
	opc = 9;
	do
	{
		system(CLEAR);
		cout <<"\n REGISTRAR DATOS ESTUDIOS "<<endl<<endl;
		cout <<"1. Ingresar Datos Estudios"<<endl;
		cout <<"2. Retirar Datos Estudios"<<endl;
		cout <<"3. Modificar Datos Estudios"<<endl;
		cout <<"4. Listar Datos Estudios "<<endl;
		cout <<"5. Borrado Logico Estudios"<<endl;
		cout <<"6. Acticar Logico Estudios"<<endl;
			
		cout <<"0. Salir del Menu"<<endl<<endl;
		cout <<"Digite Opcion :  ";
		cin >> opc;
		fflush(stdin);
		
		switch(opc)
		{
			case 1: ingresar_est(); break;
			case 2: retirar_est(); break;
			case 3: modificar_est(); break;
			case 4: listar_est(); break;
			case 5: borrado_logico_est(); break;
			case 6: activar_logico_est(); break;
			
			default : cout <<"Ingreso Opcion no valida "; 
		}
	}
	while ( opc != 0 );	
}

void Estudios::ingresar_est()
{
	ofstream escribir;  	// estudios
	ifstream lectura;		// Datos Agenda
	
	string bus_cedula;
	
	string aux1_nombre;
    string aux1_codigo;
    string aux1_cedula;
    string aux1_activo;
	int encontro;
	encontro = 0;

	lectura.open("Agenda.dat",ios::in);
	escribir.open("Estudios.dat",ios::app);
	if ( escribir.is_open() )
	{
		cout<<"Estudios";
	}
	else
	{
		escribir.close();
		ofstream escribir_est;
		escribir.open("Estudios.dat",ios::out);	
	}	
	
	cout<< "  entramos   1";
	pausa();
	if ( escribir.is_open() && lectura.is_open() ) //Validamos que el archivo "escribir no presento error
 	{
 		cout<< "  entramos   2";
		pausa();
		cout<<"\n\n Digite Datos de Estudios ";
		cout<<"\n\n Digite Cedula  : ";
		getline(cin,bus_cedula);
		
		if ( bus_cedula == "" ) // validamos que el nombre no este vacio
		{
			do
			{
				cout<<"\n\n Digite Cedula : ";
				getline(cin,bus_cedula);	
			}
			while (bus_cedula == "" );
		}
		
		getline(lectura,aux1_cedula);
        
		while( !lectura.eof() && encontro == 0)
        {
        		cout<< "  entramos   3";
				pausa();
				
			getline(lectura,aux1_codigo);
            getline(lectura,aux1_nombre);
            getline(lectura,aux1_activo);
            
            cout <<aux1_cedula <<endl<<aux1_nombre<<endl;

            if(aux1_cedula == bus_cedula)
            {
            	
            	cout <<aux1_cedula <<endl<<aux1_nombre<<endl;
		        encontro = 1;
				cout<<"\n\n Digite Instituto : ";
				getline(cin,instituto);
				if ( instituto == "" )
				{
					do
					{
						cout<<"\n\n Digite Instituto : ";
						getline(cin,instituto);	
					}
					while (instituto == "" );
				}
				
				cout<<"\n\n Digite titulo : ";
				getline(cin,titulo);
				if ( titulo == "" )
				{
					do
					{
						cout<<"\n\n Digite Titulo : ";
						getline(cin,titulo);	
					}
					while (titulo == "" );
				}
		
				cout<<"\n\n Digite Fecha Terminacion : ";
				getline(cin,fecha);
				if ( fecha == "" )
				{
					do
					{
						cout<<"\n\n Digite Fecha Terminacion : ";
						getline(cin,fecha);	
					}
					while (fecha == "" );
				}
			}
		}
	    cedula = bus_cedula;
		escribir<<cedula<<endl<<instituto<<endl<<titulo<<endl<<fecha<<endl;	
	}
	escribir.close();
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
}

void Estudios::modificar_est()
{
}

void Estudios::retirar_est()
{
}

main()
{
    system ("color f0");
    
	int opc;
	opc = 9;
	
	Agenda inicio;
	Estudios entrar;
	do
	{
		system(CLEAR);
		cout <<"\n MENU GENERAL "<<endl<<endl;
		cout <<"1. Agendas "<<endl;
		cout <<"2. Estudios"<<endl;
		cout <<"0. Salir del Menu"<<endl<<endl;
		cout <<"Digite Opcion :  ";
		cin >> opc;
		fflush(stdin);
		
		switch(opc)
		{
			case 1: 
    			inicio.menu();
			    break;
			case 2: 
			    entrar.menu_est();
				break;
			
			default : cout <<"Ingreso Opcion no valida "; 
		}
	}
	while ( opc != 0 );	
}

void pausa()
{
    cout<<"Presiona Enter para continuar...";
    getch();
    system(CLEAR);
}

void error()
{
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}