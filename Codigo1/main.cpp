#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
	
/***********************************************************************************************/
int a, cp = 0,ci = 0, ap = 0, ai = 0;
char condi[20];
float pp = 0,pi = 0;
int cea = 0, cee = 0, cena = 0;
int acea = 0, acee = 0, acena = 0;
int proea = 0, proee = 0, proena = 0;

HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);

/***********************************************************************************************/


void menu();
void gotoxy(int x ,int y);
void cuadro(int x1, int y1, int x2, int y2);
void ingresar_datos();
void hacer_graficos(int a,int y);
void graficos();
void estadisticas();

/***********************************************************************************************/



void gotoxy(int x ,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}


/***********************************************************************************************/
void cuadro(int x1, int y1, int x2, int y2)
{
	int i;
	
	for (i=x1; i<=x2;i++)
	{
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
	}

	for (i=y1; i<=y2;i++)
	{
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
	}

	
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  

}

/***********************************************************************************************/



void ingresar_datos()
{
	char sigue, nombre[30];
	int cedula, anio, notaexa, edad;
	int prom, proe, proc, pros, promco, pcc, pea, pa;
	const int anioactu = 2024;
	
	do{
		system("cls");
		
		
		SetConsoleTextAttribute (hConsoleHandle, 7);
		cuadro(10,7,70,19);
		cuadro(18,3,43,5);
		SetConsoleTextAttribute (hConsoleHandle, 10);
		gotoxy(23,04); printf("INGRESANDO DATOS");

		SetConsoleTextAttribute (hConsoleHandle, 7);
		gotoxy(12,8); printf("INGRESE LOS SIGUIENTES DATOS DEL ESTUDIANTE");
		gotoxy(12,9); printf("NUMERO DE CEDULA :");
		scanf("%i", &cedula);
		gotoxy(12,10); printf("PRIMER NOMBRE :");
		scanf("%s",&nombre);
		gotoxy(12,11); printf("ANIO DE NACIMIENTO :");
		scanf("%i",&anio);
		gotoxy(12,12); printf("PROMEDIO FINAL DE ESTAS MATERIAS (REDONDEADO)");
		gotoxy(12,13); printf("MATEMATICAS :");
		scanf("%i",&prom);
		gotoxy(12,14); printf("ESPANOL: ");
		scanf("%i",&proe);
		gotoxy(12,15); printf("CIENCIAS: ");
		scanf("%i",&proc);
		gotoxy(12,16); printf("ESTUDIOS SOCIALES: ");
		scanf("%i",&pros);
		gotoxy(12,17); printf("NOTA DEL EXAMEN DE ADMISION: ");
		scanf("%i",&notaexa);
		
		edad = anioactu - anio;
		promco = (prom + proe + proc + pros)/4;
		pcc = promco * 0.4;
		pea = notaexa * 0.6;
		pa = pcc + pea;
		
		system("cls");
		
		SetConsoleTextAttribute (hConsoleHandle, 7);
		cuadro(10,7,70,21);
		cuadro(18,3,54,5);
		SetConsoleTextAttribute (hConsoleHandle, 10);
		gotoxy(23,04); printf("DATOS FINALES DEL ESTUDIANTE");
		
		SetConsoleTextAttribute (hConsoleHandle, 7);
		gotoxy(12,8); printf("Cedula: %i",cedula);
		gotoxy(12,9); printf("Nombre: %s",nombre);
		gotoxy(12,10); printf("Ano de nacimiento: %i",anio);
		gotoxy(12,11); printf("Edad: %i",edad);
		gotoxy(12,12); printf("Calificacion de matematicas: %i", prom);
		gotoxy(12,13); printf("Calificacion de espanol: %i", proe);
		gotoxy(12,14); printf("Calificacion de ciencias: %i", proc);
		gotoxy(12,15); printf("Calificacion de estudios sociales: %i", pros);
		gotoxy(12,16); printf("Promedio de colegio: %i",promco);
		gotoxy(12,17); printf("Porcentaje criterio colegio: %i",pcc);
		gotoxy(12,18); printf("Porcentaje examen admision: %i",pea);
		gotoxy(12,19); printf("Promedio admision: %i",pa); 		
		
		if(pa >= 85){
			gotoxy(12,20); printf("SU CALIFICACION ES: admitido ");
			cea = cea + 1;
			acea = acea + pa;
		}else if(pa >= 75 && pa <= 84){
			gotoxy(12,20); printf("SU CALIFICACION ES: en espera ");
			cee = cee + 1;
			acee = acee + pa;
		}else{
			gotoxy(12,20); printf("SU CALIFICACION ES: no admitido ");
			cena = cena + 1;
			acena = acena + pa;
		}
		
		
		
		SetConsoleTextAttribute (hConsoleHandle, 15);
		do{
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(11,23);printf("Desea ingresar otro estudiante S/N");
			sigue=getch();

		}while (toupper(sigue)!='S' && toupper(sigue)!='N');
		
	}while (tolower(sigue)=='s');
	
}




/***********************************************************************************************/
void hacer_graficos(int a,int y)
{
int i;int j=20;
for (i=1; i<=a; i++)
	{
		gotoxy (j,y); printf("%c",178);
		j++;
	}
}

/***********************************************************************************************/
void graficos()
{    
	system("cls");
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	cuadro(24,2,49,4);
	cuadro(20,13,55,15);
	
	
	SetConsoleTextAttribute (hConsoleHandle, 10);
	gotoxy(27,3); printf("***** GRAFICOS *****"); 
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	
	gotoxy(2,6);	printf("AMDMITIDOS");
	hacer_graficos(cea,6);
	
	gotoxy(2,8);	printf("EN ESPERA");
	hacer_graficos(cee,8);
	
	gotoxy(2,10);	printf("NO ADMITIDOS");
	hacer_graficos(cena,10);
	
	SetConsoleTextAttribute (hConsoleHandle, 10);
	gotoxy(21,14);	printf(" << Pulse tecla para Abandonar >>");
	getch();
}

/***********************************************************************************************/
void estadisticas()
{
	system ("cls");
	SetConsoleTextAttribute (hConsoleHandle, 15);
	cuadro(25,2,55,4);
	cuadro(2,6,48,10);
	cuadro(2,11,48,15);
	cuadro(25,23,55,25);
	cuadro(2,16,48,20);
	
	if(cea == 0){
		proea = 0;
	}else{
		proea = acea / cea;
	}
		
	if(cee == 0){
		proee = 0;
	}else{
		proee = acee / cee;
	}
		
	if(cena == 0){
		proena = 0;
	}else{
		proena = acena / cena;
	}


	
	
	SetConsoleTextAttribute (hConsoleHandle, 10);
	gotoxy(27,3); printf("*****Ver Estadisticas*****");   
	SetConsoleTextAttribute (hConsoleHandle, 15);   
		       
	gotoxy(4,7);  printf("CANTIDAD ESTUDIANTES ADMITIDOS: %i",cea);
	gotoxy(4,9); printf("PROMEDIO ESTUDIANTES ADMITIDOS: %i",proea);
	
	gotoxy(4,12); printf("CANTIDAD ESTUDIANTES EN ESPERA: %i",cee);
	gotoxy(4,14);  printf("PROMEDIO ESTUDIANTES EN ESPERA: %i",proee);
	
	gotoxy(4,17); printf("CANTIDAD ESTUDIANTES NO ADMITIDOS: %i",cena);
	gotoxy(4,19); printf("PROMEDIO ESTUDIANTES NO ADMITIDOS %i",proena);
	
	SetConsoleTextAttribute (hConsoleHandle, 10);
	gotoxy(27,24); printf("<Pulse tecla para Abandonar>");
	getch();
}





/***********************************************************************************************/

void menu()

{
	char opc,conti;
	
	do{
		

		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, 7);
		cuadro(16,2,65,6); 
		cuadro(8,8,72,22);
		cuadro(8,23,72,25); 
	

		SetConsoleTextAttribute (hConsoleHandle, 10);
	    gotoxy(22,4);printf("***** MENU PRINCIPAL DEL PROGRAMA *****");
        SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(15,10);printf("[1]  INGRESAR DATOS");
		gotoxy(15,12);printf("[2]  ESTADISTICAS");
		gotoxy(15,14);printf("[3]  GRAFICOS");
		gotoxy(57,20);printf("<<[4] SALIR>>");
		
		SetConsoleTextAttribute(hConsoleHandle,15);
		gotoxy(15,24);printf("Su opcion es: ");
		opc=getch();

		switch(opc)
		{
		case '1': ingresar_datos();break;
		case '2': estadisticas(); break;
		case '3': graficos(); break;
		case '4': 
				
			system("cls");
			
			SetConsoleTextAttribute (hConsoleHandle, 2);
			cuadro(18,8,63,14);
			
			gotoxy(20,10);printf("Estas seguro que quieres salir del sistema");
			
			gotoxy(20,12);printf("Desea salir del programa S/N");
			conti=getch();

			if (conti=='N' || conti=='n')
				menu();
			else if (conti=='S' || conti=='s')

		
				break; 
		
		}
			

		}while(opc!='4');

	}


/********************************************************************************************/

int main() {
	menu();
	return 0;
}
