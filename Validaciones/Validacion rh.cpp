#include <iostream>
#include <conio.h>

using namespace std;

int main(){

	char rh[3],	OP = 'S';
	int i=0;
	
	while(OP == 'S'){
		system("cls");
		cout<<"-----VALIDACION GRUPO SANGUINEO-----\n";
		cout<<"Digite grupo sanguineo: ";cin>>rh;
	
		for(i=0;i<3;i++){
			rh[i] = toupper(rh[i]);
		}
		
		int cont=0;
		
		if((rh[0] == 'O') or (rh[0] == 'A' && rh[1] == 'B') or (rh[0] == 'B')){
		
			while(rh[i] != '\0'){
				cont+=1;
				i++;
			}
			
			if(cont <= 2){
				if(rh[0] == 'O'){
					cout<<"Digite factor rh [+ o -]: ";cin>>rh[2];
					if(rh[2] == '+' or rh[2] == '-'){
						cout<<"GUARDADO";
					}else{
						cout<<"INVALIDO";
					}
				}
			}
			
			if(cont <= 3){
				if(rh[0] == 'A' && rh[1] == 'B'){
					cout<<"Digite factor rh [+ o -]: ";cin>>rh[3];
					if(rh[3] != '+' or rh[2] != '-'){
						cout<<"GUARDADO";
					}else{
						cout<<"INVALIDO";
					}
				}
			}
		
			if(cont <= 2){
				if(rh[0] == 'B'){
					cout<<"Digite factor rh [+ o -]: ";cin>>rh[2];
					if(rh[2] == '+' or rh[2] == '-'){
						cout<<"GUARDADO";
					}else{
						cout<<"INVALIDO";
					}
				}
			}
				
		}else{
			cout<<"NO VALIDO";
		}
		
		do{
			cout<<endl<<"Presione 'S' para continuar o 'N' para finalizar el programa ";
			OP = getch();
			OP = toupper(OP);
		}while((OP!='S')&&(OP!='N'));	
	}
	
	system("cls");
	cout<<"---Hecho por carlos legro---";
	getch();
}
