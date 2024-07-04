#ifndef _CRUD_H_
#define _CRUD_H_
#include <iostream>
#include <cctype>
#include <conio.h>
#include <limits>
#include <windows.h>
#include <string>
#include <random>
#include <math.h>
#include <sstream>
#include <fstream>

using namespace std;

//CRUD

struct Persona {
	char Identificacion[12];
	char TipoIdentifiacion[5];
	char Nombre[20];
	char Apellido[20];
	char Sexo[2];
	char Edad[4];
	char CodigoMun[6];
	char Correo[60];
};

extern Persona persona[100];

//Registro de usuarios
void AgregarManual();
void AgregarEstatico();
//Aleatorio
string identificacion();
string generarCorreos(char Nombre[20], char Apellido[20], char correos[50]);
string generarEdades();
void AgregarAleatorio();
void AgregarDesdeArchivo();

//Consulta de usuarios
void Consultar();

//Actualizacion de datos
void Modificar();

//Eliminacion de usuarios
int BuscarId(Persona persona[100], long long int borrar);
void Eliminar();

#endif