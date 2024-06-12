//Validaciones

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

void vejez();
void nombre();
void apellido();
void codmun();
void id();
void tipo();
void menu();

int main(){
	menu();
}

void menu(){
	
	int op;
	
	do{
		system("cls");
		cout<<"MENU VALIDACIONES\n";
		cout<<"1. Edad\n";
		cout<<"2. Nombre\n";
		cout<<"3. Apellido\n";
		cout<<"4. Codigo de municipio\n";
		cout<<"5. Identificaion\n";
		cout<<"6. Tipo\n";
		cout<<"7. Salir\n";
		cout<<"Digite una opcion: ";
		cin>>op;
	
		switch(op){
			case 1:
				vejez();
				break;
			case 2:
				nombre();
				break;
			case 3:
				apellido();
				break;
			case 4:
				codmun();
				break;
			case 5:
				id();
				break;
			case 6:
				tipo();
				break;
			default:
				if(op>7){
					 system("cls"); cout<<"opcion invalida"; getch();
				}
				break;
		}
	}while(op!=7);
	system("cls");
	cout<<"by carlos";
}

void vejez(){
	system("cls");
	
	int cont=0,i=0;
	char Edad[6];
	
	cout<<"Digite su edad: ";
	cin>>Edad;
	
	while(Edad[i] != '\0'){
		cont++;
		i++;
	}
	
	//i=0;
	if(cont >=1  && cont <= 3){
			for(i=0;i<cont;i++){
				if(Edad[i] <'0' or Edad[i]>'9'){
					cout<<"Solo numeros";
					getch();
					return;
				}
			}
			cout<<"valido";			
	}else{
		cout<<"\nEdad invalida debe tener entre 1-3 caracteres";
	}
	
	getch();
}

void nombre(){
	system("cls");
	
	int cont=0,i=0;
	char nom[20];
	
	cout<<"Digite su nombre: ";
	cin>>nom;
	
	while(nom[i] != '\0'){
		cont++;
		i++;
	}
	
	//i=0;
	if(cont >=5  && cont <= 20){
			for(i=0;i<cont;i++){
				if((nom[i] <'a' or nom[i]>'z') and (nom[i] <'A' or nom[i]>'Z')){
					cout<<"Solo letras";
					getch();
					return;
				}
			}
			cout<<"valido";			
	}else{
		cout<<"\ninvalida debe tener entre 5-20 caracteres";
	}
	
	getch();
}

void apellido(){
		system("cls");
	
	int cont=0,i=0;
	char ape[20];
	
	cout<<"Digite su apellido: ";
	cin>>ape;
	
	while(ape[i] != '\0'){
		cont++;
		i++;
	}
	
	//i=0;
	if(cont >=5  && cont <= 20){
			for(i=0;i<cont;i++){
				if((ape[i] <'a' or ape[i]>'z') and (ape[i] <'A' or ape[i]>'Z')){
					cout<<"Solo letras";
					getch();
					return;
				}
			}
			cout<<"valido";			
	}else{
		cout<<"\ninvalida debe tener entre 5-20 caracteres";
	}
	
	getch();
}

void codmun(){
	system("cls");
	
	int cont=0,i=0;
	char codmun[8];
	
	cout<<"Digite su codigo de municipio: ";
	cin>>codmun;
	
	while(codmun[i] != '\0'){
		cont++;
		i++;
	}
	
	//i=0;
	if(cont >=2  && cont <= 4){
			for(i=0;i<cont;i++){
				if(codmun[i] <'0' or codmun[i]>'9'){
					cout<<"Solo numeros";
					getch();
					return;
				}
			}
			cout<<"valido";			
	}else{
		cout<<"\nEdad invalida debe tener entre 2-4 caracteres";
	}
	
	getch();
}

void id(){
	system("cls");
	
	int cont=0,i=0;
	char id[15];
	
	cout<<"Digite su identificacion: ";
	cin>>id;
	
	while(id[i] != '\0'){
		cont++;
		i++;
	}
	
	//i=0;
	if(cont >=8  && cont <= 10){
			for(i=0;i<cont;i++){
				if(id[i] <'0' or id[i]>'9'){
					cout<<"Solo numeros";
					getch();
					return;
				}
			}
			cout<<"valido";			
	}else{
		cout<<"\nEdad invalida debe tener 8-10 caracteres";
	}
	
	getch();
}

void tipo(){
	system("cls");
	//O+, O-, AB+, A+, A-, B+, B-
	char tipo[5], a[]="O+", a1[]="O-", b[]="A+", b1[]="A-", c[]="B+", c1[]="B-", d[]="AB+", d1[]="AB-";
	int i=0, cont=0;
	
	cout<<"Digite su tipo de sangre: ";
	cin>>tipo;
	
	for(i=0; i<5; i++){
		tipo[i]=toupper(tipo[i]);
	}
	
	i=0;
	while(tipo[i] !='\0'){
		cont++;
		i++;
	}
	
	if(cont >= 2 and cont <= 3){
		for(int i=0;i<cont;i++){
			if(tipo[i]==a[i] or tipo[i]==a1[i] or tipo[i]==b[i] or tipo[i]==b1[i] or tipo[i]==c[i] or tipo[i]==c1[i] or tipo[i]==d[i] or tipo[i]==d1[i]) {
				cout<<"Valido";
				getch();
				return;
			}
		}
	}else{
		cout<<"invalido debe tener entre 2-3 caracteres";
	}
	
	getch();
}