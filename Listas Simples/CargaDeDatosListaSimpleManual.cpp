#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <windows.h>
#include <sstream>

void setConsoleSize(int width, int height) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rect = {0, 0, static_cast<SHORT>(width - 1), static_cast<SHORT>(height - 1)};
	SetConsoleWindowInfo(console, TRUE, &rect);
}

int gotoxy(USHORT x,USHORT y) {
	COORD cp= {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);
}

using namespace std;

struct NodoUser {
	char tipo[5];
	char id[12];
	char nom[20];
	char ape[20];
	char edad[4];
	char sexo[4];
	char codc[6];

	NodoUser *sig;
};

NodoUser *Cabeza, *Fin;

void add();
void list();
void save();
void load();
void menu();

//Parcial
void punto1();//1. Generar un archivo que contenga Solo las mujeres de Aguachica.
void punto2();//2. Generar un archivo que contenga Solo los Hombres de Valledupar.
void punto3();//3. Generar un archivo que contenga las personas que tienen CC y son menores de edad
void punto4();//4. Generar un archivo que contenga las personas que tienen TI y son mayores de edad
void punto5();//5. Generar un archivo que contenga los registros con error en sus campos.
void punto6();//6. Hacer una consulta en pantalla que Cuente cuantas personas hay por ciudad.
void punto7();//7. Hacer una consulta en pantalla que cuente cuantas personas hay por tipo de documento.

int main() {
	Cabeza=NULL;
	menu();
}

void menu() {

	system("color F0");
	int op;

	do {
		system("cls");
		cout<<"MENU VALIDACIONES\n";
		cout<<"1. Agregar usuario\n";
		cout<<"2. Ver lista de usuarios\n";
		cout<<"3. Guardar en Archivo\n";
		cout<<"4. Cargar datos desde archivo\n";
		cout<<"5. Punto 1\n";
		cout<<"6. Punto 2\n";
		cout<<"7. Punto 3\n";
		cout<<"8. Punto 4\n";
		cout<<"9. Punto 5\n";
		cout<<"10. Punto 6\n";
		cout<<"11. Punto 7\n";
		cout<<"12. Salir \n";
		cout<<"Digite una opcion: ";
		cin>>op;

		switch(op) {
			case 1:
				add();
				break;
			case 2:
				list();
				break;
			case 3:
				save();
				break;
			case 4:
				load();
				break;
			case 5:
				punto1();
				break;
			case 6:
				punto2();
				break;
			case 7:
				punto3();
				break;
			case 8:
				punto4();
				break;
			case 9:
				punto5();
				break;
			case 10:
				punto6();
				break;
			case 11:
				punto7();
				break;
			default:
				if(op>12) {
					system("cls");
					cout<<"opcion invalida";
					getch();
				}
				break;
		}
	} while(op!=12);
	system("cls");
	cout<<"by carlos";
}

void add() {
	NodoUser *p;
	char op='S';

	while(op=='S')	{
		system("cls");
		cout<<"Capturar Datos\n";
		p = new NodoUser;
		cout<<"Tipo: ";
		cin>>p->tipo;

		p->sig=NULL;

		if(Cabeza==NULL) {
			Cabeza=p;
			Fin=p;
		} else {
			Fin->sig=p;
			Fin=p;
		}
		do {
			cout<<"Seguir?";
			op=toupper(getche());
		} while((op != 'S') && (op != 'N'));
	}
}

void list() {
	NodoUser *p=Cabeza;
	int cont=0;

	system("cls");
	system("color F0");

	if(Cabeza==NULL) {
		cout<<"no hay lista";
		getch();
	} else {
		gotoxy(5,1);
		cout<<"TIPO	ID		APELLIDO	NOMBRE		SEXO	 EDAD	  CODIGO DE CIUDAD";

		int i=0;
		while(p != NULL) {
			gotoxy(6,2+i);
			cout<<p->tipo;
			gotoxy(13,2+i);
			cout<<p->id;
			gotoxy(33,2+i);
			cout<<p->ape;
			gotoxy(49,2+i);
			cout<<p->nom;
			gotoxy(65,2+i);
			cout<<p->sexo;
			gotoxy(74,2+i);
			cout<<p->edad;
			gotoxy(88,2+i);
			cout<<p->codc;
			p=p->sig;
			cont++;
			i++;
		}

		gotoxy(31,12);
		cout<<"Existen "<<cont<<" elementos";
		getch();
	}
}

void save() {
	NodoUser *p=Cabeza;
	FILE *archivo = fopen("UsuarioParcial.txt","w");

	if(archivo == NULL) {
		perror("Error al abrir el archivo");
	} else {
		while(p != NULL) {
			fprintf(archivo, "%s\n", p->tipo);
			p=p->sig;
		}
	}

	system("cls");
	fclose(archivo);
	gotoxy(50,50);
	cout<<"Archivo UsuarioParcial.txt creado y cargado correctamente";
	getch();

}

void load() {
	ifstream archivo("USUARIOS.txt");

	if(!archivo.is_open()) {
		cout<<"Error al abrir el archivo";
	}

	string linea;
	while(getline(archivo, linea)) {

		stringstream ss(linea);
		string tipo, id, ape, nom, sexo, edad, codc;

		getline(ss, tipo,',');
		getline(ss, id,',');
		getline(ss, ape,',');
		getline(ss, nom,',');
		getline(ss, sexo,',');
		getline(ss, edad,',');
		getline(ss, codc);

		if(tipo != "") {
			NodoUser *p = new NodoUser;
			strcpy(p->tipo, tipo.c_str());
			strcpy(p->id, id.c_str());
			strcpy(p->ape, ape.c_str());
			strcpy(p->nom, nom.c_str());
			strcpy(p->sexo, sexo.c_str());
			strcpy(p->edad, edad.c_str());
			strcpy(p->codc, codc.c_str());
			p->sig=NULL;

			if(Cabeza == NULL) {
				Cabeza=p;
				Fin=p;
			} else {
				Fin->sig=p;
				Fin=p;
			}

		}
	}

	system("cls");
	gotoxy(30,50);
	cout<<"Datos cargados correctamente";
	getch();
}

void load2(){
	
}

void punto1() {
//1. Generar un archivo que contenga Solo las mujeres de Aguachica.
	NodoUser *p=Cabeza;
	int cont=0;

	system("cls");
	system("color F0");

	if(Cabeza==NULL) {
		cout<<"no hay lista";
		getch();
	} else {
		gotoxy(5,1);
		cout<<"TIPO	ID		APELLIDO	NOMBRE		SEXO	 EDAD	  CODIGO DE CIUDAD";

		int i=0;
		while(p != NULL) {
			if(strcmp(p->sexo,"F")==0 && strcmp(p->codc,"011")==0) {
				gotoxy(6,2+i);
				cout<<p->tipo;
				gotoxy(13,2+i);
				cout<<p->id;
				gotoxy(33,2+i);
				cout<<p->ape;
				gotoxy(49,2+i);
				cout<<p->nom;
				gotoxy(65,2+i);
				cout<<p->sexo;
				gotoxy(74,2+i);
				cout<<p->edad;
				gotoxy(88,2+i);
				cout<<p->codc;
				p=p->sig;
				cont++;
				i++;
			} else {
				p=p->sig;
			}
		}

		gotoxy(31,12);
		cout<<"Existen "<<cont<<" elementos";
		getch();
	}
}

void punto2() {
//2. Generar un archivo que contenga Solo los Hombres de Valledupar.
	NodoUser *p=Cabeza;
	int cont=0;

	system("cls");
	system("color F0");

	if(Cabeza==NULL) {
		cout<<"no hay lista";
		getch();
	} else {
		gotoxy(5,1);
		cout<<"TIPO	ID		APELLIDO	NOMBRE		SEXO	 EDAD	  CODIGO DE CIUDAD";

		int i=0;
		while(p != NULL) {
			if(strcmp(p->sexo,"M")==0 && strcmp(p->codc,"001")==0) {
				gotoxy(6,2+i);
				cout<<p->tipo;
				gotoxy(13,2+i);
				cout<<p->id;
				gotoxy(33,2+i);
				cout<<p->ape;
				gotoxy(49,2+i);
				cout<<p->nom;
				gotoxy(65,2+i);
				cout<<p->sexo;
				gotoxy(74,2+i);
				cout<<p->edad;
				gotoxy(88,2+i);
				cout<<p->codc;
				p=p->sig;
				cont++;
				i++;
			} else {
				p=p->sig;
			}
			//gotoxy(6,2+i);cout<<p->tipo<<"	"<<p->id<<"		"<<p->ape<<"		"<<p->nom<<" 	"<<p->sexo<<" 	"<<p->edad<<"		 "<<p->codc;
		}

		gotoxy(31,12);
		cout<<"Existen "<<cont<<" elementos";
		getch();
	}
}

void punto3() {
//3. Generar un archivo que contenga las personas que tienen CC y son menores de edad
}

void punto4() {
//4. Generar un archivo que contenga las personas que tienen TI y son mayores de edad
}

void punto5() {
//5. Generar un archivo que contenga los registros con error en sus campos.
	NodoUser *p=Cabeza;
	int cont=0;

	system("cls");
	system("color F0");

	if(Cabeza==NULL) {
		cout<<"no hay lista";
		getch();
	} else {
		gotoxy(5,1);
		cout<<"TIPO	ID		APELLIDO	NOMBRE		SEXO	 EDAD	  CODIGO DE CIUDAD";

		int i=0;
		while(p != NULL) {
		 bool tieneError = false;
            for (int i = 0; p->tipo[i] != '\0'; i++) {
                if (!isalpha(p->tipo[i])) {
                    tieneError = true;
                    break;
                }
            }

            
            if (tieneError) {
                gotoxy(6,2+i);
				cout<<p->tipo;
				cont++;
				p=p->sig;
				cont++;
				i++;
            }else{
			}

            p = p->sig;
		}
	}

		gotoxy(31,12);
		cout<<"Existen "<<cont<<" elementos";
		getch();
}

void punto6() {
//6. Hacer una consulta en pantalla que Cuente cuantas personas hay por ciudad.
	
}

void punto7() {
//7. Hacer una consulta en pantalla que cuente cuantas personas hay por tipo de documento.

}