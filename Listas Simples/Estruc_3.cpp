/**************************************************************
 *                                                            *
 *   ESTRUCTURA DE DATOS SIMPLE                               *
 *                                                            *
 *   Version 1. Registro de usuario                           *
 *                                                            *
 *   AUTOR : OSVALDO RUEDA       ESTRUCTURA DE DATOS  		  *
 *                                                            *
 **************************************************************/
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cctype>
#include <limits>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int gotoxy(USHORT x,USHORT y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   
}

struct persona{
	char iden[12];
	char nom1[20];
	char ape1[20];
	char codmun[4];
};
int lim = 0;
persona usuarios[100]; 
//**********************PROCESO PRINCIPAL********************
void menu_llenados(), menu();
void  CAPTURA();
void estatico();
void manual();
void random();
string generadorletras(int largo);
string generadornum(int largo);
void archivo();
void consulta();
void eliminar();
void guardar();
void saludo(), despedida();
 // ****************  PRORAMA PRINCIPAL ********************
 main()
   {
	saludo();
	menu();
	despedida();
    }
//****************** FUNCION MENU LLENADOS ***************************
void menu_llenados(){
  int op ;
do {
	op=0;
  system("cls");
  system("color F0");
  gotoxy(31,6) ; cout << "LLENADO DE ESTRUCTURAS";
  gotoxy(35,7) ; cout << "TIPOS DE LLENADO" ;
  gotoxy(30,10); cout << "1. LLENADO ESTATICO" ;
  gotoxy(30,11); cout << "2. LLENADO MANUAL";
  gotoxy(30,12); cout << "3. LLENADO RANDOM";
  gotoxy(30,13); cout << "4. CARGAR DESDE ARCHIVO";
  gotoxy(30,14); cout << "5. SALIR";
  gotoxy(22,22); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
  cin >> op ;
  if (op== 1) {
   estatico();
  }
  if (op== 2) {
  manual();
  }
  if (op== 3) {
  random();
  }
  if (op== 4) {
  archivo();
  }

	} while((op!= 5)) ;

  }


//****************** FUNCION MENU PRINCIPAL ***************************


void menu()
  {
  int control ;
  do{ 
  control=0;
  system("cls");
  system("color F0");
  gotoxy(26,6) ; cout << "LLENADO DE ESTRUCTURAS";
  gotoxy(25,7) ; cout << "LLENADO, CONSULTA, GUARDAR" ;
  gotoxy(30,10); cout << "1. LLENADO O CAPTURA" ;
  gotoxy(30,11); cout << "2. CONSULTA";
  gotoxy(30,12); cout << "3. GUARDAR EN ARCHIVO";
  gotoxy(30,13); cout << "4. SALIR";
  gotoxy(22,22); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
  cin >> control ;
  if (control== 1) {
   menu_llenados();
  }
  if (control== 2) {
  consulta();
  }
  if (control== 3) {
  guardar();
  }
	} while(control!= 4) ;
  }



// *******************  FUNCION CREAR Y/O ADICIONAR ******************

void  CAPTURA()
  {
  
  }
 
 
 // ********************** CONSULTA ********************

 void consulta()
{
	system("cls");
  	system("color F0");
   if (lim==0){
   
          gotoxy(22,24); cout << " ESTRUCTURA VACIA";
}
else{ 	
	 int i=0;
	 //titulos
	 gotoxy (1,1);cout<<"   iden:            Nombre:            Apellido:            Codmun:"; 
	 for (i=0; i<lim;i++){
		gotoxy(2,2+i);cout<<usuarios[i].iden;
        gotoxy(22,2+i);cout<<usuarios[i].nom1;
        gotoxy(42,2+i);cout<<usuarios[i].ape1;
        gotoxy(62,2+i);cout<<usuarios[i].codmun;
		//	strcpy(elementos[contador].nombre, nombre);	
	}
		gotoxy(24,28); cout << "Pulse Cualquier tecla para Continuar";
		getch();
    }
}


 // ********************** GUARDAR A ARCHIVO ********************

void guardar(){
FILE *archivo = fopen("C:\\UPC2024\\ARCHIVO\\usuarios3.txt", "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
    }
else{
	
    for (int i = 0; i < lim; i++) {
        fprintf(archivo,"%s,%s,%s,%s\n", usuarios[i].iden, usuarios[i].nom1, usuarios[i].ape1, usuarios[i].codmun);
    }
}
    // Cerrar el archivo
    fclose(archivo);

    printf("Los datos han sido guardados en el archivo.\n");
    getch();

}    
    
    
void eliminar(){
	
	cout<<"Eliminar";
	
}


 // ********************** ESTATICO ********************
 void estatico(){
 		system("cls");
  		system("color F0");
  		cout<<"Carga de datos estaticos....";
        fflush(stdout);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//Registro 1
        strcpy(usuarios[lim].iden,"123456789");
        strcpy(usuarios[lim].nom1,"osvaldo");
        strcpy(usuarios[lim].ape1,"Rueda");
        strcpy(usuarios[lim].codmun,"621");
        lim++;
//Registro 2       
        strcpy(usuarios[lim].iden,"456789123");
        strcpy(usuarios[lim].nom1,"Braulio");
        strcpy(usuarios[lim].ape1,"Barrios");
        strcpy(usuarios[lim].codmun,"001");
        lim++;
//Registro 3      
        strcpy(usuarios[lim].iden,"789123456");
        strcpy(usuarios[lim].nom1,"Carlos");
        strcpy(usuarios[lim].ape1,"Oñate");
        strcpy(usuarios[lim].codmun,"740");
        lim++;        
        
        cout<<"Datos cargados a la estructura";
        getch();
        cout<<"Presiones una tecla para volver al menu";
 }
 
 
  // ********************** MANUAL ********************
 
void manual(){
    char tecla;
    tecla='N';
    if (lim < 2) {

    do{
    	system("cls");
  		system("color F0");
        cout<<"\nFavor ingrese dato de la posicion "<<lim+1<<"::>";
        fflush(stdout);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout<<"\nFavor ingrese la identificación: "; 
        cin>>usuarios[lim].iden;
        cout<<"\nFavor ingrese el nombre: "; 
        cin>>usuarios[lim].nom1;
        cout<<"\nFavor ingrese el apellido: "; 
        cin>>usuarios[lim].ape1;
        cout<<"\nFavor ingrese codigo del municipio: "; 
        cin>> usuarios[lim].codmun;
        //strcpy(elementos[contador].nombre, nombre);
        lim++;
    	do{
    		cout<<"\nDesea ingresar mas elementos? s/n:";
    		tecla=getche();
		}while((toupper(tecla)!='S')and(toupper(tecla)!='N'));
	}while (toupper(tecla)=='S');
    }
	else {
        cout << "\n Arreglo de datos lleno." << endl;
    }

}

 // ********************** RANDOM ********************

void random(){
		int cant=0;
		system("cls");
  		system("color F0");
  		cout<<"Carga de datos estaticos....";
        fflush(stdout);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Digite la cantidad de elementos random que desea en al estructura: ";
        cin>>cant;
        if (cant>=(100-lim)){
        	cout<<"demasiados elementos";
		}
		else{
			srand(time(0)); // Inicializar la semilla aleatoria
			for (int i = 0; i < cant; ++i) {
			    strcpy(usuarios[lim].iden,generadornum(1).c_str());	
        		strcpy(usuarios[lim].nom1,generadorletras(1).c_str());
        		strcpy(usuarios[lim].ape1,generadorletras(1).c_str());
        		strcpy(usuarios[lim].codmun, generadornum(1).c_str());
        		lim++;        
			}
        	cout<<"Datos cargados a la estructura";
    	}
        cout<<"Presiones una tecla para volver al menu";
        getch();
}
/*****************************************************/
string generadorletras(int largo) {
    string nombre;
    int longitud = rand() % largo+3; 
    if (longitud < 1) longitud = 1; 
    for (int i = 0; i < longitud; ++i) {
        char letra = 'a' + rand() % 26; 
        nombre += letra;
    }
    return nombre;
}
/*****************************************************/
string generadornum(int largo) {
    string num;
    int longitud = rand() % largo+3; 
    if (longitud < 1) longitud = 1; 
    for (int i = 0; i < longitud; ++i) {
        char digito = '0' + rand() % 10; 
        num += digito;
    }
    return num;
}


/***********************************************/
void archivo(){
 string s;
 ifstream f("usuario2.txt");
 if (!f.is_open())
  {
    cout << "Error al abrir USUARIOS.txt\n";
    exit(EXIT_FAILURE);
  }
else{ 
	string linea;
	while (getline(f, linea)) {
		size_t pos1 = linea.find(',');
        size_t pos2 = linea.find(',', pos1 + 1);
        size_t pos3 = linea.find(',', pos2 + 1);
        //cout<<"\n"<<pos1<<"-"<<pos2<<"-"<<pos3;
		//cout <<"\n"<<linea;
		//cout<<"\n"<<linea.substr(0, pos1);
		//cout<<"-"<<linea.substr(pos1 + 1, pos2 - pos1 - 1);
	 	//cout<<"-"<<linea.substr(pos2 + 1,pos3 - pos2 - 1);
		//cout<<"-"<<linea.substr(pos3 + 1,pos3-linea.length()-1); //ultimo pedazo
		strcpy(usuarios[lim].iden,linea.substr(0, pos1).c_str());
        strcpy(usuarios[lim].nom1,linea.substr(pos1 + 1, pos2 - pos1 - 1).c_str());
        strcpy(usuarios[lim].ape1,linea.substr(pos2 + 1,pos3 - pos2 - 1).c_str());
        strcpy(usuarios[lim].codmun,linea.substr(pos3 + 1,pos3-linea.length()-1).c_str());
        lim++;
	}
 }
}
  	
void despedida(){
	cout <<"\nby osvaldo Rueda, 2024-1";
    getch();
}	
void saludo(){
	cout<<"hola";
	//cls 
}

 
