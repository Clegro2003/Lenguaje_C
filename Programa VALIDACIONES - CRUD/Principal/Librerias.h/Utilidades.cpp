#include "Utilidades.h"
#include "Validaciones.h"
#include "CRUD.h"

void menu() {
	int a;

	while(a != 5) {
		system("cls");

		cout<<"Menu Principal\n";
		cout<<" 1.Agregar\n 2.Consultar\n 3.Eliminar\n 4.Modificar\n 5.Salir\n"
		    " Digite un numero acorde a su eleccion: ";
		cin>>a;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch(a) {
			case 1:
				menuAgregar();
				break;
			case 2:
				Consultar();
				break;
			case 3:
				Eliminar();
				break;
			case 4:
				Modificar();
				break;
			default:
				if(cin.fail() or a < 1 or a > 5) {
					cin.clear(); // Limpia el estado de error de cin
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada no válida
					cout<<" opcion invalida!";
					getch();
					break;
				}
		}
	}
}

void menuAgregar() {
	int a;

	while(a != 6) {
		system("cls");

		cout<<"Menu de Registro\n";
		cout<<" 1.Manual\n 2.Estatico\n 3.Aleatorio\n 4.Desde archivo\n 5.Consultar\n 6.Volver\n"
		    " Digite un numero acorde a su eleccion: ";
		cin>>a;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch(a) {
			case 1:
				AgregarManual();
				break;
			case 2:
				AgregarEstatico();
				break;
			case 3:
				AgregarAleatorio();
				break;
			case 4:
				AgregarDesdeArchivo();
				break;
			case 5:
				Consultar();
				break;
			default:
				if(cin.fail() or a < 1 or a > 6) {
					cin.clear(); // Limpia el estado de error de cin
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada no válida
					cout<<" opcion invalida!";
					getch();
					break;
				}
		}
	}
}

int ContarCaracteres(char n[30]) {
	int cont=0;
	while(n[cont] != '\0') {
		cont++;
	}
	return cont;
}

bool ValidarCampoVacio(char n[30]) {
	if(n[0] == '\0') {
		cout<<"El campo no puede estar vacio";
		cin.ignore();
		return false;
	}
	return true;
}

void ComprobarResultado(bool a) {
	if(!a) {
		cout<<"\nInvalido";
	} else {
		cout<<"Guardado!";
	}
	getch();
}

bool validarCaracteresEspeciales(char n) {
	if(!(n == '@' or n == '-' or n == '.' or n == ',' or n == '_')) {
		return false;
	}
	return true;
}

int PosArroba(char n[50]) {
	int cont = ContarCaracteres(n);
	for(int i=0; i<cont; i++) {
		if(n[i] == '@') {
			return i;
		}
	}
	return -1;
}

int PosPrimerPunto(char n[50]) {
	int cont = ContarCaracteres(n);
	for(int i=0; i<cont; i++) {
		if(n[i] == '.') {
			return i;
		}
	}
	return -1;
}