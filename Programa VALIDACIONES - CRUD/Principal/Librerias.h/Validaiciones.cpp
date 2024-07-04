#include "Validaciones.h"
#include "Utilidades.h"

//Nombres y apellidos
void letras() {
	system("cls");
	char n[30];
	cin.ignore();
	cout<<"Nombre: ";
	cin.getline(n,30);
	
	if(!ValidarCampoVacio(n)) return;
	bool a = validarletras(n);
	ComprobarResultado(a);
}

bool validarletras(char n[30]) {

	int cont = ContarCaracteres(n);

	int espacio=0;
	for(int i=0; i<cont; i++) {
		if(isspace(n[i])) {
			espacio++;
		} else {
			espacio=0;
		}
		if(!isalpha(n[i]) and espacio>1) {
			cout<<"Solo se permiten letras y maximo 1 espacio";
			return false;
		}
	}

	if(cont<5 or cont>15) {
		cout<<"Se permiten entre 5 y 15 caracteres";
		return false;
	}

	if (isspace(n[0]) or isspace(n[cont - 1])) {
		cout << "No se permiten espacios al inicio o al final del nombre" << endl;
		return false;
	}

	return true;
}

//Identificaciones
void Id() {
	system("cls");
	char n[30];
	cin.ignore();
	cout<<"Identificacion: ";
	cin.getline(n,30);
	
	if(!ValidarCampoVacio(n)) return;
	bool a = validarId(n);
	ComprobarResultado(a);
}

bool validarId(char n[30]) {

	int cont = ContarCaracteres(n);

	for(int i=0; i<cont; i++) {
		if(!isdigit(n[i]) or isspace(n[i])) {
			cout<<"Solo se permiten numeros sin espacios";
			return false;
		}
	}

	if(cont<5 or cont>11) {
		cout<<"Se permiten entre 5 y 11 caracteres";
		return false;
	}

	return true;
}

//Tipos de identificacion
void Tipo() {
	system("cls");
	char n[30];
	cin.ignore();
	cout<<"Tipo de identifiacion: ";
	cin.getline(n,30);

	if(!ValidarCampoVacio(n)) return;
	bool a = validarTipo(n);
	ComprobarResultado(a);
}

bool validarTipo(char n[30]) {

	int cont = ContarCaracteres(n);

	for(int i=0; i<cont; i++) {
		if(!isalpha(n[i]) or isspace(n[i])) {
			cout<<"Solo se permiten letras, no se permiten espacios";
			return false;
		}
	}

	if(cont < 2 or cont > 4) {
		cout<<"Se permiten minimo 2 y maximo 4 caracteres";
		return false;
	}

	return true;
}

//Codigo de municipio
void Codigo() {
	system("cls");
	char n[30];
	cin.ignore();
	cout<<"Codigo municipio: ";
	cin.getline(n,30);
	
	if(!ValidarCampoVacio(n)) return;
	bool a = validarCodigo(n);
	ComprobarResultado(a);
}

bool validarCodigo(char n[30]) {

	int cont = ContarCaracteres(n);

	for(int i=0; i<cont; i++) {
		if(!isdigit(n[i]) or isspace(n[i])) {
			cout<<"Solo se permiten numeros sin espacios";
			return false;
		}
	}

	if(cont != 5) {
		cout<<"Se permiten solo 5 caracteres";
		return false;
	}

	return true;
}

//Edad
void Edad() {
	system("cls");
	char n[30];
	cin.ignore();
	cout<<"Edad: ";
	cin.getline(n,30);

	if(!ValidarCampoVacio(n)) return;
	bool a = validarEdad(n);
	ComprobarResultado(a);
}

bool validarEdad(char n[30]) {

	int cont = ContarCaracteres(n);

	for(int i=0; i<cont; i++) {
		if(!isdigit(n[i]) or isspace(n[i])) {
			cout<<"Solo se permiten numeros sin espacios";
			return false;
		}
	}

	if(cont > 3) {
		cout<<"Se permiten maximo 3 caracteres";
		return false;
	}

	return true;
}

//Correo electronico
void Correo(){
	system("cls");
	char n[30];
	cin.ignore();
	cout<<"Correo: ";
	cin.getline(n,30);
	
	if(!ValidarCampoVacio(n)) return;
	bool a = validarCorreo(n);
	ComprobarResultado(a);
}

bool validarCorreo(char n[30]){
	
	int cont = ContarCaracteres(n);
	int arrobaPos = PosArroba(n);

	int espacio=0;
	for(int i=0; i<cont; i++) {
		if(!isalnum(n[i]) and !validarCaracteresEspeciales(n[i]) and !isspace(n[i])) {
			cout<<"Solo se permiten letras o numeros sin espacios y los caracteres especiales \"'@','-','.',',','_'\"";
			return false;
		}	
	}
	
	if (arrobaPos == -1) {
        cout << "El correo debe contener exactamente un simbolo '@'" << endl;
        return false;
    }
	
	int punto=0;
	for(int i = arrobaPos + 1; i < cont; i++){
		if(n[i] == '.'){
			punto++;
		}
	}
	
	int pospunto = PosPrimerPunto(n);
	if(n[pospunto+1] == '.'){
		cout<<"No pueden haber 2 puntos consecutivos";
		return false;
	}
	
    if(punto>2){
    	cout<<"Debe haber solo un punto despues del arroba";
    	return false;
	}
	
	if(cont<5 or cont>50) {
		cout<<"Se permiten entre 3 y 50 caracteres";
		return false;
	}

	if (isspace(n[0]) or isspace(n[cont - 1])) {
		cout << "No se permiten espacios al inicio o al final del nombre" << endl;
		return false;
	}
	
	return true;
}