#include <iostream>
#include <string.h>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <cctype>
#include <locale>

using namespace std;

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Nacimiento{
	char dia[3];
	char mes[3];
	char anio[5];
}fecha;

struct Nodo{
	char tipo[6];
	char id[12];
	char nombre[20];
	char nombre1[20];
	char apellido[20];
	char apellido1[20];
	char edad[4];
	char sexo[2];
	char codigom[4];
	
	Nodo *sig;
	Nodo *ant;
}Usuario;

Nodo *Cabeza=NULL, *Fin=NULL;

void Menu();
void CapturaManual();
void CargarNodos();
void Consultar();
void Eliminar();
void CalcularEdad();

int main() {
	system("color F0");
	Menu();	
	//MessageBox(NULL,"Hecho por Carlos Legro","Saliendo del programa",MB_OK);
}

void Menu(){
	int op;
	
	do 
	{
		system("cls");
		cout<<"Menu\n";
		cout<<"1. Capturan Manual\n";
		cout<<"2. Cargar Nodos\n";
		cout<<"3. Consultar\n";
//		cout<<"4. Eliminar\n";
		cout<<"5. Salir\n";
		cout<<"Elija una opcion: ";
		cin>>op;
		switch(op)
		{
			case 1:
				CapturaManual();
				break;
			case 2:
				CargarNodos();
				break;
			case 3:
				Consultar();
				break;
			case 4:
				//Eliminar();
				break;
			default:
				if(op>5){
					//MessageBox(NULL,"OPCION INVALIDA","ERROR",MB_OK | MB_ICONERROR);
				}
				break;
		}
	} while(op!=5);


}

void CapturaManual(){
	Nodo *p;
	char OP = 'S';
	
	while (OP == 'S')
    {
    	system("cls");
    	p = new Nodo;
    	cout<<"Registro de datos\n";
    	cout<<"Tipo documento: ";cin>>p->tipo;
    	cout<<"Identificacion: ";cin>>p->id;
    	cout<<"Nombre y apellido: \n";cin>>p->nombre;cin>>p->apellido;
    	cout<<"Edad: ";cin>>p->edad;
    	
		p->ant=NULL;
		p->sig=NULL;
		
		if(Cabeza==NULL){   	
    		Cabeza = p;
		}
		else{
			Fin->sig=p;
			p->ant=Fin;
		}
		Fin=p;
    	
    	do {
	     gotoxy(29,20); cout <<"DESEA CONTINUAR S/N : ";
	     OP = toupper(getch());
	  } while((OP != 'S') && (OP != 'N'));
     }
}

void agregarNodo(const char* tipo, const char* id, const char* apellido, const char* apellido1, const char* nombre, const char* nombre1, const char* dia, const char* mes,  const char* anio, const char* edad, const char* sexo, const char* codigom) {
    Nodo *p = new Nodo;

    // Asignar valores constantes a los datos del nodo
    strcpy(p->tipo, tipo);
    strcpy(p->id, id);
    strcpy(p->apellido, apellido);
    strcpy(p->apellido1, apellido1);
    strcpy(p->nombre, nombre);
    strcpy(p->nombre1, nombre1);
	strcpy(fecha.dia, dia);
	strcpy(fecha.mes, mes);
	strcpy(fecha.anio, anio);
	strcpy(p->edad, edad);
    strcpy(p->sexo, sexo);
    strcpy(p->codigom, codigom);

    p->sig = NULL;

    if (Cabeza == NULL) {
        Cabeza = p;
        Fin = p;
    } else {
        Fin->sig = p;
        Fin = p;
    }
}

bool ValidarFechaNacimiento(const Nacimiento& fechaNacimiento) {
    int dia = atoi(fechaNacimiento.dia);
    int mes = atoi(fechaNacimiento.mes);
    int anio = atoi(fechaNacimiento.anio);

    // Verificar si el día está en el rango válido para el mes
    if (dia < 1 || dia > 31) {
        return false;
    }

    // Verificar si el mes está en el rango válido
    if (mes < 1 || mes > 12) {
        return false;
    }

    // Verificar si el año está dentro del rango permitido
    if (anio < 1900 || anio > 2024) {
        return false;
    }

    // Verificar febrero y años bisiestos
    if (mes == 2) {
        if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
            return dia <= 29; // Febrero en año bisiesto tiene 29 días
        } else {
            return dia <= 28; // Febrero en año no bisiesto tiene 28 días
        }
    }

    // Verificar meses con 30 días
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return dia <= 30;
    }

    // Resto de los meses con 31 días
    return true;
}

int CalcularEdad(const Nacimiento& fechaNacimiento) {
    // Obtener la fecha actual
    time_t t = time(0);
    tm* now = localtime(&t);

    // Convertir la fecha de nacimiento a enteros
    int diaNacimiento = atoi(fechaNacimiento.dia);
    int mesNacimiento = atoi(fechaNacimiento.mes);
    int anioNacimiento = atoi(fechaNacimiento.anio);

    // Calcular la diferencia de años
    int edad = now->tm_year + 1900 - anioNacimiento;
    if (mesNacimiento > now->tm_mon + 1 || (mesNacimiento == now->tm_mon + 1 && diaNacimiento > now->tm_mday)) {
        // Si aún no ha pasado el cumpleaños este año, restamos 1
        edad--;
	}
	return edad;
}


void CargarNodos(){
//	ifstream arch("USUARIOS_F_quiz_erroneas.txt");
//	ifstream arch("USUARIOS_REAL.TXT");
	ifstream arch("dataset_actores.txt");

	if(!arch.is_open()){
		cout<<"no se pudo abrir el archivo";
		return;
	}
	
	string linea;
	while(getline(arch,linea)){
		Nodo *p =new Nodo;
		stringstream ss(linea);
        string tipo, id, apellido, apellido1, nombre, nombre1, dia, mes, anio, sexo, codigom;

        getline(ss, tipo, ',');
        getline(ss, id, ',');
        getline(ss, apellido, ',');
        getline(ss, apellido1, ',');
        getline(ss, nombre, ',');
        getline(ss, nombre1, ',');
        getline(ss, sexo, ',');
        getline(ss, dia, '/');
        getline(ss, mes, '/');
        getline(ss, anio, ',');
        getline(ss, codigom, ',');
        
        // Validaciones
	
		//PT, CC, RC TI
	
		string a="abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
	
		if (tipo.find_first_not_of(a) != string::npos) continue;
//		if(tipo!="CC" and tipo!="PT" and tipo!="TI" and tipo!="RC") continue;
		if(sexo != "M" and sexo != "F")continue;
//    	// Si encuentra al menos un carácter que no es un dígito, continuamos con la próxima iteración del bucle    
		if (id.find_first_not_of("0123456789") != string::npos) continue;
		
		if (codigom.find_first_not_of("0123456789") != string::npos) continue;
		
		if (dia.find_first_not_of("0123456789") != string::npos) continue;
		
		if (mes.find_first_not_of("0123456789") != string::npos) continue;

		if (anio.find_first_not_of("0123456789") != string::npos) continue;
		
 	   // Si encuentra al menos un carácter que no es una letra, continuamos con la próxima iteración del bucle
		if (nombre.find_first_not_of(a) != string::npos) continue;

		if (nombre1.find_first_not_of(a) != string::npos) continue;

		if (apellido.find_first_not_of(a) != string::npos) continue;

		if (apellido1.find_first_not_of(a) != string::npos) continue;

		Nacimiento fechaNacimiento;
		strcpy(fechaNacimiento.dia, dia.c_str());
		strcpy(fechaNacimiento.mes, mes.c_str());
		strcpy(fechaNacimiento.anio, anio.c_str());

		if (!ValidarFechaNacimiento(fechaNacimiento)) {
            continue;
        }

        int edad = CalcularEdad(fechaNacimiento);
        
		agregarNodo(tipo.c_str(), id.c_str(), apellido.c_str(), apellido1.c_str(), nombre.c_str(), nombre1.c_str(), dia.c_str(), mes.c_str(), anio.c_str(), to_string(edad).c_str(), sexo.c_str(), codigom.c_str());
	}
	
	Nodo *p = new Nodo;
	cout<<"Lista cargada";
	getch();
}

void Consultar(){
	Nodo *p = new Nodo;
	int i=0, cont=0, TIPO;
	system("cls");
	if(Cabeza == NULL){
	  cout<<"no hay lista";
	}
	else{
		system("cls");
		gotoxy(32, 10); cout << "1. IZQUIERDA A DERECHA";
	    gotoxy(32, 11); cout << "2. DERECHA A IZQUIERDA";
	    gotoxy(32, 13); cout << "3. SALIR        ";
	    
	    do {
	        gotoxy(22, 16); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
	        cin >> TIPO;
	        if (TIPO < 1 || TIPO > 3) {
	            gotoxy(30, 22); cout << "Opcion no valida";
	        }
	    } while ((TIPO < 1) || (TIPO > 3));
	    
	    if (TIPO == 3) return;
	
	    p = (TIPO == 1) ? Cabeza : Fin;
	    system("cls");
			//p=Cabeza;
			gotoxy(20,0);cout<<"Consulta de registros"<<endl;
			gotoxy(4,2);cout<<"N  TIPO     ID	 APELLIDO    APELLIDO2  NOMBRE1    NOMBRE2        EDAD     SEXO    COD_MUNICPIO";
		
		while(p!=NULL){
			if(strcmp(p->sexo,"F")==0){
				gotoxy(4,3+i);cout<<i+1;
				gotoxy(8,3+i);cout<<p->tipo;
				gotoxy(13,3+i);cout<<p->id;
				gotoxy(25,3+i);cout<<p->apellido;
				gotoxy(37,3+i);cout<<p->apellido1;
				gotoxy(48,3+i);cout<<p->nombre;
				gotoxy(59,3+i);cout<<p->nombre1;
				gotoxy(75,3+i);cout<<p->edad;
				gotoxy(85,3+i);cout<<p->sexo;
				gotoxy(95,3+i);cout<<p->codigom;
				cont++;
				i++;
			}
				p = (TIPO == 1) ? p->sig : p->ant;
		
			if(i==40){
				gotoxy(5, 4+i); cout << "Presione cualquier tecla para continuar...";
                getch();
                system("cls");
                gotoxy(4, 2); cout << "TIPO    ID	     APELLIDO	APELLIDO2   NOMBRE1    NOMBRE2          EDAD       SEXO  COD_MUNICPIO";
                i = 0;
			}
		}
		gotoxy(75,0);cout<<"Existen "<<cont<<" registros";
	}
	
	gotoxy(4, 4+i); cout << "Presione cualquier tecla para continuar...";
	getch();

}