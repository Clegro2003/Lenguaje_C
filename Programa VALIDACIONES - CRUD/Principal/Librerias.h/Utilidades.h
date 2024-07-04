#ifndef _UTILIDADES_H_
#define _UTILIDADES_H_
#include <iostream>
#include <cctype>
#include <conio.h>
#include <limits>

using namespace std;

void menu();
void menuAgregar();
bool validarCaracteresEspeciales(char n);
int ContarCaracteres(char n[30]);
bool ValidarCampoVacio(char n[30]);
void ComprobarResultado(bool a);
bool validarCaracteresEspeciales(char n);
int PosArroba(char n[50]);
int PosPrimerPunto(char n[50]);

#endif