#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cctype>
#include <limits>
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int gotoxy(SHORT x, SHORT y){                                  
    COORD cp={x,y};                                                
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);  
	return 0;
}

struct NODO {
    char tipo[2];
    long  VALOR;
    char ape[20], nom[20];
    char sexo;
    int edad;
    char codmun[2];
    NODO  *SIG;
};

int MENU();
void  CAPTURA();
void  ARCHIVO();
void  CONSULTA();
void  ELIMINAR();
void GUARDAR();
void ERRORES();
int VALIDACION(long VALOR, int SW);

NODO  *CABEZA, *FIN ;
int cont=0;

// ****************  PROGRAMA PRINCIPAL ********************

int main() {
    MENU();
}

int MENU() {
    int op ;
    do {
        op=0;
        system("cls");
        system("color F0");
        gotoxy(26, 6); cout << "LISTAS ENLAZADAS SIMPLES";
        gotoxy(25, 7); cout << "CAPTURA, CONSULTA Y ELIMINACION DE CIUDADES";

        gotoxy(30, 11); cout << "1. CAPTURA";
        gotoxy(30, 12); cout << "2. CAPTURA DESDE ARCHIVO";
        gotoxy(30, 13); cout << "3. CONSULTA";
        gotoxy(30, 14); cout << "4. PARCIAL";
        gotoxy(30, 15); cout << "5. PARCIAL";
        gotoxy(30, 18); cout << "6. salir";
        gotoxy(22,22); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
        cin >> op ;
        if (op== 1) {
            CAPTURA();
        }
        if (op== 2) {
            ARCHIVO();
        }
        if (op== 3) {
            CONSULTA();
        }
        if(op == 4){
            GUARDAR();
        }
         if(op == 5){
            //ERRORES();
        }

    } while((op!= 6)) ;
    return 0;
}

// ******************* FUNCION CREAR Y/O ADICIONAR ******************

void  CAPTURA() {
    NODO *P ;
    int SW ;
    char OP = 'S';
    while (OP == 'S') {
        system("cls");
        gotoxy(26,5) ; cout << "LISTAS ENLAZADAS SIMPLES";
        gotoxy(36,7) ; cout << "CAPTURA DE DATOS";
        gotoxy(20,11); cout <<"VALOR : ";
        P = new NODO;
        gotoxy(29,11); cin >> P->VALOR ;
        SW = 0;
        SW = VALIDACION(P-> VALOR, SW);
        if (SW == 1)
            delete P;
        else {
            P->SIG = NULL ;
            if (CABEZA == NULL)
                CABEZA =  P ;
            else
                FIN->SIG = P;
            FIN = P;
        }
        do {
            gotoxy(29,20); cout <<"DESEA CONTINUAR S/N : ";
            OP = toupper(getch());
        } while((OP != 'S') && (OP != 'N'));
    }
}

void ARCHIVO() {
    ifstream archivo("C:\\UPC2024M\\ARCHIVO\\USUARIOS(11).txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {

        stringstream ss(linea);
        string tipo, ape, nom, codmun;
        char sexo;
        long valor;
        int edad;

        getline(ss, tipo, ',');
        ss >> valor; ss.ignore();
        getline(ss, ape, ',');
        getline(ss, nom, ',');
        ss >> sexo; ss.ignore();
        ss >> edad; ss.ignore();
        getline(ss, codmun);

        if (tipo != "" && valor > 0 && ape != "" && nom != "" && (sexo == 'M' || sexo == 'F') && edad > 0 && codmun != "") {
            NODO* P = new NODO;
            strcpy(P->tipo, tipo.c_str());
            P->VALOR = valor;
            strcpy(P->ape, ape.c_str());
            strcpy(P->nom, nom.c_str());
            P->sexo = sexo;
            P->edad = edad;
            strcpy(P->codmun, codmun.c_str());
            P->SIG = NULL;

            if (CABEZA == NULL) {
                CABEZA = P;
                FIN = P;
            } else {
                FIN->SIG = P;
                FIN = P;
            }
        } else {
           
            NODO* P = CABEZA;
            NODO* prev = NULL;
            while (P != NULL) {
                if (P->VALOR == valor) {
                    if (prev == NULL) {
                        CABEZA = P->SIG;
                    } else {
                        prev->SIG = P->SIG;
                    }
                    delete P;
                    break;
                }
                prev = P;
                P = P->SIG;
            }
        }
    }

    archivo.close();
}


// ********************** CONSULTA ********************
void CONSULTA() {
    if (CABEZA == NULL) {
        system("cls");
        gotoxy(22, 24);
        cout << " NO EXISTE LISTA";
        getch();
    } else {
        NODO *P = CABEZA;
        int F = 10, T = 1;
        system("cls");
        gotoxy(26, 5);
        cout << "LISTAS ENLAZADAS SIMPLES";
        gotoxy(31, 7);
        cout << "CONSULTA SIMPLE";
        gotoxy(8,9); cout<<"ID         APELLIDO   NOMBRE  Sexo  Edad  CodMun";
        while (P != NULL) {
            gotoxy(8,F);cout<<P->tipo << " " << P->VALOR << " " << P->ape << " " << P->nom << " "<< P->sexo << " " << P->edad << " " << P->codmun;
            P = P->SIG;
            F++;
            T++;
        }
        getch();
    }
}


// *********************** FUNCION VALIDACION **********************
int VALIDACION(long VALOR, int SW) {
    NODO *P = CABEZA;
    while ((P != NULL) && (SW == 0)) {
        if ( VALOR == P->VALOR) {
            SW = 1;
            gotoxy(40,11); cout << " REGISTRO EXISTE " ;
        }
        P  = P->SIG;
    }
    return SW;
}

void GUARDAR() {
    ofstream archivo("C:\\UPC2024M\\ARCHIVO\\USUARIOS(12).txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de salida." << endl;
        return;
    }

    NODO* usuario = CABEZA;
    string ciudad = "";

    while (usuario != NULL) {
        if (usuario->edad < 18 && usuario->sexo == 'F' && strcmp(usuario->tipo, "CC") == 0) {
            archivo << usuario->tipo << "," << usuario->VALOR << "," << usuario->ape << "," << usuario->nom << "," << usuario->sexo << "," << usuario->edad << "," << usuario->codmun << endl;
           
        }

        usuario = usuario->SIG;
    }

    archivo << ciudad;
    archivo.close();

    cout << "Datos de los usuarios de Talameque guardados en UsuariosTalameque.csv" << endl;
}