//Tres en raya
#include <iostream>
#include <stdlib.h>
#include <time.h> // como voy a crear numeros aleatorios necesito la libreria tiempo
using namespace std;

void loop (char c[3][3]);//prototipo de una funcion
void Intro_Primera(char c[3][3]);
void tablero(char c[3][3]);
void intro_Yo(char c[3][3]);
void intro_IA(char c[3][3]);
int ganador(char c[3][3]);
int main()
{
	char c[3][3];
	loop (c);	//llama a todas las funciones fundamentales y hace un refresco de pantalla
	system("pause");
	return 0;
}
void loop (char c[3][3]){
		
	int i,j;//hacemos un contador porque tenemos un numero finito de casillas
	i=0;
	int c2;
	int c3;
	string ver="";
	Intro_Primera (c);
	do{
	system("cls");
		cout<<"----------------------------------------------------Bienvenidos a Tic-Tac-Toe-------------------------------------------"<<endl;
	    tablero (c);
	    if(i % 2==0 )
	     {
	 	   intro_Yo(c);

	     }
	      else{
	 	    intro_IA(c);
	     }
	     j=ganador(c);
	     i++;

		
	}while(i < 9  && j==2);
	system("cls");
	if(j==0)
	{
		cout<<"Has ganado felicidades"<<endl;
	}
	else if(j==1)
	{
		cout<<"Que mal has perdido"<<endl;
	}
	else
	{
		cout<<"Hubo empate"<<endl;
	}
   

	
	
}

void Intro_Primera(char c[3][3])//para llenar la matriz
{
	int i,j;
	char aux;
	aux = '1';
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			c[i][j]=aux++;// aux='1','2'
		}
	}
	
}
void tablero(char c[3][3])//Para hacer el tablero
{
	int i,j;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
				cout<<" ";
				cout<<c[i][j];
				cout<<" |";	
		}
		if(i<2)
		{
			cout<<"\n------------\n";
		}
	}
	cout<<"\n\n";
}

void intro_Yo(char c[3][3])
{
	int i,j,k;
	char aux;
	do{
		do{
			cout<<"***Digite el numero para colocar ficha:";
			cin>>aux;
		}while(aux< '1' || aux> '9');
		k=0;
		switch(aux){
			case '1'://aqui estamos analizando la matriz en la posicion 0,0 corresponde al numero 1
				i=0;
				j=0;
				if(c[i][j]=='X' || c[i][j]=='O'){
					k=1;
					cout<<"La casilla esta ocupada intentalo con otro numero\n\n";
				}
			break;	
			case '2'://aqui estamos analizando la matriz en la posicion 0,1 corresponde al numero 2
				i=0;
				j=1;
				if(c[i][j]=='X' || c[i][j]=='O'){
					k=1;
					cout<<"La casilla esta ocupada intentalo con otro numero\n\n";
				}
			break;
			case '3'://aqui estamos analizando la matriz en la posicion 0,2 corresponde al numero 3
				i=0;
				j=2;
				if(c[i][j]=='X' || c[i][j]=='O'){
					k=1;
					cout<<"La casilla esta ocupada intentalo con otro numero\n\n";
				}
			break;
			case '4'://aqui estamos analizando la matriz en la posicion 1,0 corresponde al numero 4
				i=1;
				j=0;
				if(c[i][j]=='X' || c[i][j]=='O'){
					k=1;
					cout<<"La casilla esta ocupada intentalo con otro numero\n\n";
				}
			break;
			case '5'://aqui estamos analizando la matriz en la posicion 1,1 corresponde al numero 5
				i=1;
				j=1;
				if(c[i][j]=='X' || c[i][j]=='O'){
					k=1;
					cout<<"La casilla esta ocupada intentalo con otro numero\n\n";
				}
			break;
			case '6'://aqui estamos analizando la matriz en la posicion 1,2 corresponde al numero 6
				i=1;
				j=2;
				if(c[i][j]=='X' || c[i][j]=='O'){
					k=1;
					cout<<"La casilla esta ocupada intentalo con otro numero\n\n";
				}
			break;
			case '7'://aqui estamos analizando la matriz en la posicion 2,0 corresponde al numero 7
				i=2;
				j=0;
				if(c[i][j]=='X' || c[i][j]=='O'){
					k=1;
					cout<<"La casilla esta ocupada intentalo con otro numero\n\n";
				}
			break;
			case '8'://aqui estamos analizando la matriz en la posicion 2,1 corresponde al numero 8
				i=2;
				j=1;
				if(c[i][j]=='X' || c[i][j]=='O'){
					k=1;
					cout<<"La casilla esta ocupada intentalo con otro numero\n\n";
				}
			break;
			case '9'://aqui estamos analizando la matriz en la posicion 2,2 corresponde al numero 9
				i=2;
				j=2;
				if(c[i][j]=='X' || c[i][j]=='O'){
					k=1;
					cout<<"La casilla esta ocupada intentalo con otro numero\n\n";
				}
			break;
		}
	}while(k==1);
	c[i][j]='X';
}
void intro_IA(char c[3][3])
{
	int i,j,k;
	srand(time(NULL));// para la creacion de numeros aleatorios
	do{
		
		i= rand() % (3);// dos numeros aleatorios entre 0 y 2
		j= rand() % (3); // dos numeros aleatorios entre 0 y 2
		k=0;// para salir del bucle
		if(c[i][j]=='X' ||  c[i][j]=='O')
		{
			k=1;
		}
	}while(k==1);
	c[i][j]='O';
}

int ganador(char c[3][3]){
	if(c[0][0]=='X' || c[0][0]=='O')
	{
		if(c[0][0]== c[0][1] && c[0][1]==c[0][2])
		{
			if(c[0][0]=='X')
			{
				return 0;//He ganado
			}
			else{
				return 1;//He perdido
			}
			
		}
		if(c[0][0]==c[1][0] && c[1][0]==c[2][0])
		{
			if(c[0][0]=='X')
			{
				return 0;//He ganado
			}
			else{
				return 1;//He perdido
			}
		}
	}
	if(c[1][1]=='X' || c[1][1]=='O')
	{
		if(c[1][1]==c[0][0] && c[0][0]==c[2][2])
		{
			if(c[1][1]=='X')
			{
				return 0;//He ganado
			}
			else{
				return 1;//He perdido
			}
		}
		if(c[1][1]==c[1][0] && c[1][0]==c[1][2])
		{
			if(c[1][1]=='X')
			{
				return 0;//He ganado
			}
			else{
				return 1;//He perdido
			}
		}
		if(c[1][1]==c[2][0] && c[2][0]==c[0][2])
		{
			if(c[1][1]=='X')
			{
				return 0;//He ganado
			}
			else{
				return 1;//He perdido
			}
		}
		if(c[1][1]==c[0][1] && c[0][1]==c[2][1])
		{
			if(c[1][1]=='X')
			{
				return 0;//He ganado
			}
			else{
				return 1;//He perdido
			}
		}
		
		
	}
	if(c[2][2]=='X' || c[2][2]=='O')
	{
		if(c[2][2]==c[2][0] && c[2][0]==c[2][1])
		{
			if(c[2][2]=='X')
			{
				return 0;//He ganado
			}
			else{
				return 1;//He perdido
			}
		}
		if(c[2][2]==c[0][2] && c[0][2]==c[1][2])
		{
			if(c[2][2]=='X')
			{
				return 0;//He ganado
			}
			else{
				return 1;//He perdido
			}
		}		
	}
	return 2;// si no ocurre nada	
			
}
