#ifndef _VALIDACIONES_H_
#define _VALIDACIONES_H_
#include <iostream>
#include <cctype>
#include <conio.h>
#include <limits>

using namespace std;

//Nombres y apellidos
void letras();
bool validarletras(char n[30]);

//Identificaciones
void Id();
bool validarId(char n[30]);

//Tipos de identificacion
void Tipo();
bool validarTipo(char n[30]);

//Codigo de municipio
void Codigo();
bool validarCodigo(char n[30]);

//Edad
void Edad();
bool validarEdad(char n[30]);

//Correo electronico
void Correo();
bool validarCorreo(char n[30]);

#endif