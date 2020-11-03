//juego de tres en raya

#include <stdio.h>
#include<time.h>
#include<windows.h>

void cuadricula(char v[][3]);
void raya(char v[][3]);
void numero_random(char v[][3]);
int ganar(char v[][3]);
int ganar_maq(char v[][3]);


//********************FUNCIÓN PRINCIPAL****************************
int main(){
	
	char v[3][3]={'1','2','3','4','5','6','7','8','9',};
	int x,y,t;
	t=1000;
	
	do{
		x=0; //variable si he ganado
		y=0; //variable si ha ganado máquina
		cuadricula(v);//veo la cuadricula
		raya(v); //coloco mi ficha
		system("cls");
		cuadricula(v);
		Sleep(t);
		x=ganar(v);
		system("cls");
		if(x==0)
		{
			numero_random(v);//maquina coloca ficha
			y=ganar_maq(v);
		}
	}while(x==0 && y==0);
	
	if(x==1)
	{
		printf("\r");
		cuadricula(v);
		printf("\nHe ganado\n");
	}
	if(y==1)
	{
		cuadricula(v);
		printf("\nMaquina ha ganado\n");
	}
	
	system("pause");
	return 0;	
}

//********************FUNCIÓN: PINTO LA CUADRICULA****************************
void cuadricula(char v[][3])
{
	int i, j;
	
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%c : ",v[i][j]);			
	
		}
		printf("\n");
	}
}

//********************FUNCIÓN: COLOCO MI FICHA****************************
void raya(char v[][3])
{
	int i, j, n;
	char l;
	
	n=0;
	printf("Coloca tu ficha: ");
	fflush(stdin);
	scanf("%c", &l);
			
	for(i=0;i<3 && n!=1;i++)
	{
		for(j=0;j<3 && n!=1;j++)// && v[i][j]!='X' && v[i][j]!='O'
		{
			if(l==v[i][j])
			{
				v[i][j]='X';
				n==1;
			}			
		}
	}
}


//********************FUNCIÓN: MAQUINA COLOCA FICHA****************************
void numero_random(char v[][3])
{

	int i, j, m, s;
	char k;
	srand(time(NULL));
		
	do{
		s=0;
		m=rand()%10;
		switch(m){
			case 0: k='1';break;
			case 1: k='2';break;
			case 2: k='3';break;
			case 3: k='4';break;
			case 4: k='5';break;
			case 5: k='6';break;
			case 6: k='7';break;
			case 7: k='8';break;
			case 8: k='9';break;
		}
		for(i=0;i<3 && s==0;i++)
		{
			for(j=0;j<3 && s==0;j++)
			{
	
				if(k==v[i][j])
				{
					v[i][j]='O';
					s=1;
				}
			}
		}
	}while(s==0);
}

//********************FUNCIÓN: COMPRUEBO SI HE GANADO****************************
int ganar(char v[][3])
{
	int i, j, cont, s;
	s=0;
	cont=0;
	
		//Compruebo horizontal y verticalmente
		for(i=0;i<3 && s==0;i++)
		{
			for(j=0;j<3;j++)
			{
				if(v[i][j]=='X')
				{
				
					cont++;
				
				}			
			}
			if(cont==3)
				{
					s=1;
					
				}
				else{
					cont=0;
				}
		}
		for(j=0;j<3 && s==0;j++)
		{
			for(i=0;i<3;i++)
			{
				if(v[i][j]=='X')
				{
				
					cont++;
				
				}			
			}
			if(cont==3)
				{
					s=1;
					
				}
				else{
					cont=0;
				}
			
		}	
		
		
		//compruebo diagonalmente
		i=0;
		j=0;
		while(i<3 && j<3 && s==0)
		{
			if(v[i][j]=='X')
			{
				
				cont++;
				
			}		
			i++;
			j++;
		}
		if(cont==3)
		{
			s=1;
				
		}
		else{
			cont=0;
		}
		
		i=0;
		j=2;	
		while(i<3 && j>=0 && s==0)
		{
			if(v[i][j]=='X')
			{
				
				cont++;
				
			}		
			i++;
			j--;
		}
			if(cont==3)
			{
				s=1;
					
			}
			else{
				cont=0;
			}
			
	return s;
}


//********************FUNCIÓN: COMPRUEBO SI LA MÁQUINA HA GANADO****************************
int ganar_maq(char v[][3])
{
	int i, j, cont, s;
	s=0;
	cont=0;
	
		for(i=0;i<3 && s==0;i++)
		{
			for(j=0;j<3;j++)
			{
				if(v[i][j]=='O')
				{
				
					cont++;
				
				}			
			}
			if(cont==3)
				{
					s=1;
					
				}
				else{
					cont=0;
				}
		}
		for(j=0;j<3 && s==0;j++)
		{
			for(i=0;i<3;i++)
			{
				if(v[i][j]=='O')
				{
				
					cont++;
				
				}			
			}
			if(cont==3)
				{
					s=1;
					
				}
				else{
					cont=0;
				}
			
		}	
		i=0;
		j=0;
		while(i<3 && j<3)
		{
			if(v[i][j]=='O')
			{
				
				cont++;
				
			}		
			i++;
			j++;
		}
			if(cont==3)
			{
				s=1;
					
			}
			else{
				cont=0;
			}
		i=0;
		j=2;	
		while(i<3 && j>=0)
		{
			if(v[i][j]=='O')
			{
				
				cont++;
				
			}		
			i++;
			j--;
		}
			if(cont==3)
			{
				s=1;
					
			}
			else{
				cont=0;
			}
			
	return s;
}


