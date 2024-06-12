#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <sstream>

using namespace std;

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Nodo{
	char tipo[4];
	char id[11];
	char apellido1[20];
	char apellido2[20];
	char nombre1[20];
	char nombre2[20];
	char sexo[2];
	char edad[3];
	char codigom[4];
	
	Nodo *sig;
};

Nodo *cabeza=NULL, *fin;

void agregarNodo(const char* tipo, const char* id, const char* apellido1, const char* nombre1, const char* sexo, const char* edad, const char* codigom) {
    Nodo *p = new Nodo;

    // Asignar valores constantes a los datos del nodo
    strcpy(p->tipo, tipo);
    strcpy(p->id, id);
    strcpy(p->apellido1, apellido1);
    strcpy(p->nombre1, nombre1);
    strcpy(p->sexo, sexo);
    strcpy(p->edad, edad);
    strcpy(p->codigom, codigom);

    p->sig = nullptr;

    if (cabeza == nullptr) {
        cabeza = p;
        fin = p;
    } else {
        fin->sig = p;
        fin = p;
    }
}

void Consultar(){
	system("cls");
	
	Nodo *temp = cabeza;
	int i=0, cont=0;
	gotoxy(30,1);cout<<"Datos Resgistrados";
	gotoxy(4,2);cout<<"Tipo	ID	  APELLIDO  	NOMBRE	SEXO	EDAD	CODIGO";
	while(temp!=NULL){
		gotoxy(5,3+i);cout<<temp->tipo;
		gotoxy(12,3+i);cout<<temp->id;
		gotoxy(27,3+i);cout<<temp->apellido1;
		gotoxy(40,3+i);cout<<temp->nombre1;
		gotoxy(49,3+i);cout<<temp->sexo;
		gotoxy(57,3+i);cout<<temp->edad;
		gotoxy(65,3+i);cout<<temp->codigom;
		temp = temp->sig;
		i++;
		cont++;
	}
	
	gotoxy(30,4+i);cout<<"Hay "<<cont<<" usuarios Registrados";
	getch();
}

void CargarNodos(){
	ifstream arch("USUARIOS_F.TXT");
	if(!arch.is_open()){
		cout<<"no se pudo abrir el archivo";
		return;
	}
	
	string linea;
	while(getline(arch,linea)){
		
		stringstream ss(linea);
        string tipo, id, apellido1, nombre1, sexo, edad, codigom;

        getline(ss, tipo, ';');
        getline(ss, id, ';');
        getline(ss, apellido1, ';');
        getline(ss, nombre1, ';');
        getline(ss, sexo, ';');
        getline(ss, edad, ';');
        getline(ss, codigom, ';');
        agregarNodo(tipo.c_str(), id.c_str(), apellido1.c_str(), nombre1.c_str(), sexo.c_str(),edad.c_str(), codm.c_str());
	}
	cout<<"Lista cargada";
	getch();
}

void menu(){
	int op;
	do{
		system("cls");
		cout<<"MENU PRINCIPAL\n";
		cout<<"1. Cargar Lista\n";
		cout<<"2. Mostrar Lista\n";
		cout<<"3. Salir\n";
		cout<<"Digite una opcion: ";
		cin>>op;
		
		switch(op){
			case 1:
				CargarNodos();
				break;
			case 2:
				Consultar();
				break;
			default:
				if(op>3) cout<<"opcion invalida";
		}
	}while(op!=3);
}


int main(){
	agregarNodo("CC","1066864409","Legro","Carlos","M","21","001");
	agregarNodo("CC","1065596133","De La Rosa","Isabel","F","24","001");

	menu();
}
