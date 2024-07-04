#include "CRUD.h"

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int lim=0,posicion=0;
bool posborrado=true;
Persona persona[100];

//Registro Manual
void AgregarManual() {
	char op='S';
	while(op=='S') {
		system("cls");
		cout<<"Identificacion: ";cin>>persona[lim].Identificacion;
		
		cout<<"Tipo de identificacion: ";cin>>persona[lim].TipoIdentifiacion;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout<<"Nombre: ";cin.getline(persona[lim].Nombre,20);

		cout<<"Apellido: ";cin.getline(persona[lim].Apellido,20);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		cout<<"Sexo: ";cin>>persona[lim].Sexo;

		cout<<"Edad: ";cin>>persona[lim].Edad;

		cout<<"Codigo de municipio: ";cin>>persona[lim].CodigoMun;

		cout<<"Correo: ";cin>>persona[lim].Correo;

		lim++;
		do {
			cout<<"Desea continuar?[S/N]";
			op = toupper(getche());
		} while(op=='S' and op=='N');
	}
	cout<<"\nDatos Guardados!";
	getch();
}

//Registro Estatico
void AgregarEstatico() {
	system("cls");
	fflush(stdout);
	
	//Registro 1
	strcpy(persona[lim].Identificacion,"1234567890");
	strcpy(persona[lim].TipoIdentifiacion,"CC");
	strcpy(persona[lim].Nombre,"OSVALDO");
	strcpy(persona[lim].Apellido,"RUEDA");
	strcpy(persona[lim].Sexo,"M");
	strcpy(persona[lim].Edad,"46");
	strcpy(persona[lim].CodigoMun,"001");
	strcpy(persona[lim].Correo,"OsvaldoRueda@gmail.com");
	lim++;
	//Registro 2
	strcpy(persona[lim].Identificacion,"1066864409");
	strcpy(persona[lim].TipoIdentifiacion,"CC");
	strcpy(persona[lim].Nombre,"CARLOS");
	strcpy(persona[lim].Apellido,"LEGRO");
	strcpy(persona[lim].Sexo,"M");
	strcpy(persona[lim].Edad,"21");
	strcpy(persona[lim].CodigoMun,"001");
	strcpy(persona[lim].Correo,"Carloslegro@gmail.com");
	lim++;
	
	//Registro 3
	strcpy(persona[lim].Identificacion,"1065596133");
	strcpy(persona[lim].TipoIdentifiacion,"CC");
	strcpy(persona[lim].Nombre,"ISABEL");
	strcpy(persona[lim].Apellido,"DE LA ROSA");
	strcpy(persona[lim].Sexo,"F");
	strcpy(persona[lim].Edad,"38");
	strcpy(persona[lim].CodigoMun,"001");
	strcpy(persona[lim].Correo,"IsabelDelaRosa@gmail.com");
	
	if(posborrado==false) {
		for (int i = lim; i > lim; i--) {
			persona[i] = persona[i+1];
		}
		posborrado=true;
		posicion=0;
	}
	
	lim++;
	
	cout<<"DATOS CARGADOS!";
	getch();
}

//Registro Aletorio
string identificacion() {
	random_device a;
	mt19937 gen(a());
	long long minimo = 1000000000;
	long long maximo = 9999999999;
	uniform_int_distribution<long long> disp(minimo,maximo);
		
    long long numero_aleatorio = disp(gen);
    string n_str = to_string(numero_aleatorio);
    char n_char[23];
    snprintf(n_char,sizeof(n_char),"%s",n_str.c_str());
    return n_char;
}

string generarCorreos(const char* Nombre, const char* Apellido) {
	char correos[50];
    const char* dominios[] = {"gmail.com", "hotmail.com", "yahoo.com", "outlook.com"};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 3); // Índices para seleccionar dominios
    int dom = dis(gen);
    snprintf(correos, 50, "%s%s@%s", Nombre, Apellido, dominios[dom]); // Construir el correo
	
	return correos;
}

string generarEdades() {
    random_device a;
    mt19937 gen(a());
    uniform_int_distribution<> dis(15, 60); // Edades entre 18 y 60 años
    int edad = abs(dis(gen));
    string edad_str = to_string(edad);
    const char* edad_char = edad_str.c_str(); 
	return edad_char;
}

void AgregarAleatorio() {
	const char* nombres[] = {
		"Juan", "María", "Luis", "Ana", "Carlos", "Laura", "Pedro", "Sofía", "Jorge", "Valeria",
        "Miguel", "Camila", "Diego", "Gabriela", "Andrés", "Valentina", "José", "Fernanda", "Antonio", "Paula",
        "Ricardo", "Isabella", "Fernando", "Daniela", "Sebastián", "Juliana", "Gustavo", "Catalina", "Martín", "Verónica"
	};
    const char* apellido[] = {
		"Gómez", "Martínez", "Rodríguez", "López", "González", "Hernández", "Pérez", "Sánchez", "Ramírez",
        "Flores", "Díaz", "Vargas", "Rojas", "Cruz", "Morales", "Álvarez", "Ortiz", "Silva", "Castro", "Torres",
        "Ruiz", "Acosta", "Mendoza", "Aguilar", "Jiménez", "Suárez", "Romero", "Herrera", "Chávez", "Fuentes"
	};
	
	random_device a;
    mt19937 gen(a());
    uniform_int_distribution<> dis(0, 29);
    int letra = abs(dis(gen));

    uniform_int_distribution<> disp(0, 2);
    int numero = abs(disp(gen));
	
	uniform_int_distribution<> displ(0, 4);
    int codigo = abs(displ(gen));

	const char* tipoidentificacion[] = {"CC", "TI", "CE"};
	
	const char* codigomun[] = {"001", "002", "003", "004", "005"};
	
	const char* sexo[] = {"F","M","T"};
	
	char correo[30];
	string email = generarCorreos(nombres[letra],apellido[letra]);
	
	strcpy(persona[lim].Identificacion,identificacion().c_str());
	strcpy(persona[lim].TipoIdentifiacion,tipoidentificacion[numero]);
	strcpy(persona[lim].Nombre,nombres[letra]);
	strcpy(persona[lim].Apellido,apellido[letra]);
	strcpy(persona[lim].Sexo,sexo[numero]);
	strcpy(persona[lim].Edad,generarEdades().c_str());
	strcpy(persona[lim].CodigoMun,codigomun[codigo]);
	strcpy(persona[lim].Correo,email.c_str());
	lim++;
	
	cout<<"Usuario Agregado!";getch();
}

//Registro Archivo
void AgregarDesdeArchivo() {
	ifstream arch("C:/Users/carlo/Downloads/CLASES/Programa VALIDACIONES - CRUD/Principal/Librerias.h/RegistroCabeceras.txt");

	if(!arch.is_open()){
		cout<<"no se pudo abrir el archivo";getch();
		return;
	}
	
	string linea;
	while(getline(arch,linea)){
		stringstream ss(linea);
        string id, tipo, nombre, apellido, sexo, edad, codigonom, correo;

        getline(ss, id, ',');
        getline(ss, tipo, ',');
        getline(ss, nombre, ',');
        getline(ss, apellido, ',');
        getline(ss, sexo, ',');
        getline(ss, edad, ',');
        getline(ss, codigonom, ',');
        getline(ss, correo, ',');
        
	    strcpy(persona[lim].Identificacion, id.c_str());
	    strcpy(persona[lim].TipoIdentifiacion, tipo.c_str());
	    strcpy(persona[lim].Nombre, nombre.c_str());
	    strcpy(persona[lim].Apellido, apellido.c_str());
	    strcpy(persona[lim].Sexo, sexo.c_str());
	    strcpy(persona[lim].Edad, edad.c_str());
	    strcpy(persona[lim].CodigoMun, codigonom.c_str());
	    strcpy(persona[lim].Correo, correo.c_str());
	    lim++;
	}
	
	cout<<"Usuarios agregados!";getch();
}

//Consultar
void Consultar() {
	int cont=0, i=0;
	system("cls");

	if(lim==0) {
		cout<<"no hay lista";
	} else {

		gotoxy(10,0);
		cout<<"Lista de personas registradas";
		gotoxy(5,2);
		cout<<"Identificacion  Tipo Documento   Nombre   Apellido    Sexo    Edad   Codigo Municipio     Correo Electronico";
		for(i=0; i<lim; i++) {
				gotoxy(7,3+i);cout<<persona[i].Identificacion;
				gotoxy(25,3+i);cout<<persona[i].TipoIdentifiacion;
				gotoxy(38,3+i);cout<<persona[i].Nombre;
				gotoxy(47,3+i);cout<<persona[i].Apellido;
				gotoxy(61,3+i);cout<<persona[i].Sexo;
				gotoxy(68,3+i);cout<<persona[i].Edad;
				gotoxy(79,3+i);cout<<persona[i].CodigoMun;
				gotoxy(94,3+i);cout<<persona[i].Correo;
				cont++;
		}
		gotoxy(70,0);cout<<"Hay "<<cont<<" personas registradas";
	}
	getch();
}

//Modificar
void Modificar() {
	int modificar,eleccion;
	cout<<"Digite la identificacion del usuario a modificar: ";
	cin>>modificar;

	int posicion = BuscarId(persona,modificar);
	if(posicion!=-1) {
		cout<<"\nSeguro que desea modificar datos del usuario "<<persona[posicion].Identificacion<<" ?";
		cout<<"\n 1.Si\n 2.No\n :";
		cin>>eleccion;
		if(eleccion == 1) {

			cout<<"Identificacion: ";
			cin>>persona[posicion].Identificacion;

			cout<<"Tipo de identificacion: ";
			cin>>persona[posicion].TipoIdentifiacion;
			fflush(stdin);

			cout<<"Nombre: ";
			cin.getline(persona[posicion].Nombre,20);

			cout<<"Apellido: ";
			cin.getline(persona[posicion].Apellido,20);

			cout<<"Sexo: ";
			cin>>persona[posicion].Sexo;

			cout<<"Edad: ";
			cin>>persona[posicion].Edad;

			cout<<"Codigo de municipio: ";
			cin>>persona[posicion].CodigoMun;

			cout<<"Correo: ";
			cin>>persona[posicion].Correo;
			cout<<"Usuario modificado con exito";
		}
		getch();
	}
}

//Eliminar
int BuscarId(Persona persona[100], long long int borrar) {
	string borrar_str = to_string(borrar);

	for(int i=0; i<lim; i++) {
		if(strcmp(persona[i].Identificacion,borrar_str.c_str()) ==0 ) {
			cout<<"Usuario "<<persona[i].Nombre<<" "<<persona[i].Apellido<<" con identificacion "<<persona[i].Identificacion<<" encontrado";
			return i;
		}
	}

	cout<<"Usuario "<<borrar<<" no encontrado";
	getch();
	return -1;
}

void Eliminar() {
	long long int borrar;
	int eleccion;
	cout<<"Digite la identificacion del usuario a eliminar: ";
	cin>>borrar;

	posicion = BuscarId(persona,borrar);
	if(posicion!=-1) {
		cout<<"\nSeguro que desea eliminar al usuario "<<persona[posicion].Nombre<<" "<<persona[posicion].Apellido<<" ?";
		cout<<"\n 1.Si\n 2.No\n :";
		cin>>eleccion;
		if(eleccion == 1) {

			strcpy(persona[posicion].Identificacion,"");
			strcpy(persona[posicion].TipoIdentifiacion,"");
			strcpy(persona[posicion].Nombre,"");
			strcpy(persona[posicion].Apellido,"");
			strcpy(persona[posicion].Sexo,"");
			strcpy(persona[posicion].Edad,"");
			strcpy(persona[posicion].CodigoMun,"");
			strcpy(persona[posicion].Correo,"");
			cout<<"Usuario eliminado con exito";

			for (int i = posicion; i < lim+1; ++i) {
				persona[i] = persona[i + 1];
			}
			lim--;
			posborrado=false;
		}

		getch();
	}
}