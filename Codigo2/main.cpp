#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;
const int Total_Carros = 50; // Constante para limitar cantidad de carros

struct Vehiculo { // Estructura para informacion de los vehiculos
    string placa;
    string marca;
    string modelo;
    int tipo_Vehiculo;
    int tipo_Lavado;
    int precio;
};

// Variables globales
Vehiculo vehiculos[Total_Carros];
int num_Vehiculos = 0;
int numFactura = 1;

// Funciones
void gotoxy(int x, int y);
void setColor(int color);
void Menu();
void DatosVehiculos();
void Estadisticas_Vehiculos();
void Estadisticas_Lavados();
void Grafico_Vehiculos();
void Grafico_Lavados();
void grafico(int a, int y);


void gotoxy(int x, int y) { // Funcion que permite mover cursor a una posicion especifica
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) { // Funcion para color de texto
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Menu() { // Funcion para Menu
   	int opcion;
    do {
        system("cls");
    setColor(15);   
    gotoxy(17, 8); cout << "Menu";
    setColor(6);
    gotoxy(17, 10); cout << "1- Ingresar Datos Vehiculos";
    gotoxy(17, 11); cout << "2- Ver Estadisticas Vehiculos Lavados segun tipo de Vehiculo";
    gotoxy(17, 12); cout << "3- Ver Estadisticas Vehiculos Lavados segun tipo de Lavado";
    gotoxy(17, 13); cout << "4- Ver Grafico Vehiculos Lavados por tipo de Vehiculo";
    gotoxy(17, 14); cout << "5- Ver Grafico Vehiculos Lavados por tipo de Lavado";
    gotoxy(17, 15); cout << "6- Salir";
     setColor(15);
    gotoxy(17, 20); cout << "Seleccione la opcion que desee: ";
    cin >> opcion;     
    
        switch(opcion) {
            case 1:
                DatosVehiculos(); break;
            case 2:
                Estadisticas_Vehiculos(); break;
            case 3:
                Estadisticas_Lavados(); break;
            case 4:
                Grafico_Vehiculos(); break;
            case 5:
                Grafico_Lavados(); break;
            case 6:
                break;
            default:
            	system("cls");
            	setColor(15);
            	gotoxy(17, 8); cout << "Debe seleccionar una opcion valida, vuelva a intentarlo.\n";
            	gotoxy(17, 10); cout << "Debe seleccionar una opcion valida, vuelva a intentarlo.\n";
            	gotoxy(17, 12); cout << "Debe seleccionar una opcion valida, vuelva a intentarlo.\n";
        		break;
        }
   } while (opcion != 6);
}

void DatosVehiculos() { // Funcion para ingresar los datos de los vehiculos
    char continuar;
    do {
        if (num_Vehiculos >= Total_Carros) {
            gotoxy(22, 15); cout << "Se ha alcanzado el limite maximo de vehiculos.\n";
            break;
        }
        Vehiculo& veh = vehiculos[num_Vehiculos];  // referencia al vehiculo actual
        system("cls");
        setColor(15);
        gotoxy(17, 3); cout << "INGRESAR DATOS DE VEHICULOS";
        setColor(6);
        gotoxy(17, 6); cout << "Ingrese el numero de placa: ";
        cin >> veh.placa;
        gotoxy(17, 7); cout << "Ingrese la marca: ";
        cin >> veh.marca;
        gotoxy(17, 8); cout << "Ingrese el modelo: ";
        cin >> veh.modelo;
        gotoxy(17, 9); cout << "Ingrese el tipo de vehiculo (1=Sencillo, 2=4x4, 3=Microbus o Camion): ";
        cin >> veh.tipo_Vehiculo;
        gotoxy(17, 10); cout << "Ingrese el tipo de lavado (1=Solo Lavado, 2=Lavado, Aspirado y Encerado): ";
        cin >> veh.tipo_Lavado;
        
        switch(veh.tipo_Vehiculo) { // calcular el precio basado en el tipo de vehiculo y tipo de lavado
            case 1:
                veh.precio = (veh.tipo_Lavado == 1) ? 3000 : 5000; break;
            case 2:
                veh.precio = (veh.tipo_Lavado == 1) ? 5000 : 7000; break;
            case 3:
                veh.precio = (veh.tipo_Lavado == 1) ? 7000 : 12000; break;
            default:
                gotoxy(22, 12); cout << "Tipo de vehiculo invalido.\n"; continue;
        }
       
        setColor(15);  // mostrar los datos ingresados
        gotoxy(17, 13); cout << "Factura #" << numFactura++;
        gotoxy(17, 14); cout << "Placa: " << veh.placa;
        gotoxy(17, 15); cout << "Marca: " << veh.marca;
        gotoxy(17, 16); cout << "Modelo: " << veh.modelo;
        gotoxy(17, 17); cout << "Tipo de vehiculo: " << ((veh.tipo_Vehiculo == 1) ? "Sencillo" : (veh.tipo_Vehiculo == 2) ? "4x4" : "Microbus o Camion");
        gotoxy(17, 18); cout << "Tipo de lavado: " << ((veh.tipo_Lavado == 1) ? "Solo Lavado" : "Lavado, Aspirado y Encerado");
        gotoxy(17, 19); cout << "Precio a pagar: " << veh.precio << " colones";
        num_Vehiculos++;
        setColor(15);
        gotoxy(17, 21); cout << "Desea continuar? (S/N): ";
        cin >> continuar;
    } while (continuar == 'S' || continuar == 's');
}

void Estadisticas_Vehiculos() { // Funcion para ver estadisticas de vehiculos lavados segun tipo de vehiculo
    int cantidadSencillos = 0, cantidad4x4 = 0, cantidadMicrobus = 0;
    int dineroSencillos = 0, dinero4x4 = 0, dineroMicrobus = 0;

    
    for (int i = 0; i < num_Vehiculos; i++) { // Ciclo para estadisticas de vehiculos
        switch (vehiculos[i].tipo_Vehiculo) {
            case 1:
                cantidadSencillos++;
                dineroSencillos += vehiculos[i].precio; break;
            case 2:
                cantidad4x4++;
                dinero4x4 += vehiculos[i].precio; break;
            case 3:
                cantidadMicrobus++;
                dineroMicrobus += vehiculos[i].precio; break;
        }
    }
  
    system("cls");  // Muestra estadisticas
    setColor(15);
    gotoxy(17, 8); cout << "INFORMACION ESTADISCA POR VEHICULOS";
    setColor(6);
    gotoxy(17, 10); cout << "Cantidad de Vehiculos Tipo Sencillos: " << cantidadSencillos;
    gotoxy(17, 11); cout << "Dinero Recaudado por Vehiculos Tipo Sencillos: " << dineroSencillos << " colones";
    gotoxy(17, 12); cout << "Cantidad de Vehiculos Tipo 4x4: " << cantidad4x4;
    gotoxy(17, 13); cout << "Dinero Recaudado por Vehiculos Tipo 4x4: " << dinero4x4 << " colones";
    gotoxy(17, 14); cout << "Cantidad de Vehiculos Tipo Microbus o Camion: " << cantidadMicrobus;
    gotoxy(17, 15); cout << "Dinero Recaudado por Vehiculos Tipo Microbus o Camion: " << dineroMicrobus << " colones";
    setColor(15);
    gotoxy(17, 20); cout << "<Pulse tecla para regresar al menu>";
    getch();
}

void Estadisticas_Lavados() {  // funcion para ver estadisticas de vehiculos lavados segun tipo de lavado
    int Solo_Lavado = 0, Lavado_Completo = 0;
    int dinero_SoloLavado = 0, dinero_LavadoCompleto = 0;
    
    for (int i = 0; i < num_Vehiculos; i++) {   // recorrer el arreglo de vehiculos para calcular las estadisticas
        switch (vehiculos[i].tipo_Lavado) {
            case 1:
                Solo_Lavado++;
                dinero_SoloLavado += vehiculos[i].precio; break;
            case 2:
                Lavado_Completo++;
                dinero_LavadoCompleto += vehiculos[i].precio; break;
        }
    }

    // mostrar las estadisticas
    system("cls");
    setColor(6);
    gotoxy(17, 8); cout << "INFORMACION ESTADISTICA POR LAVADO";
    setColor(15);
    gotoxy(17, 10); cout << "Cantidad de Vehiculos con Solo Lavado: " << Solo_Lavado;
    gotoxy(17, 11); cout << "Dinero Recaudado por Vehiculos con Solo Lavado: " << dinero_SoloLavado << " colones";
    gotoxy(17, 12); cout << "Promedio Dinero Recaudado por Vehiculos con Solo Lavado: " << (Solo_Lavado > 0 ? dinero_SoloLavado / Solo_Lavado : 0) << " colones";
    gotoxy(17, 13); cout << "Cantidad de Vehiculos con Lavado, Aspirado y Encerado: " << dinero_LavadoCompleto;
    gotoxy(17, 14); cout << "Dinero Recaudado por Vehiculos con Lavado, Aspirado y Encerado: " << dinero_LavadoCompleto << " colones";
    gotoxy(17, 15); cout << "Promedio Dinero Recaudado por Vehiculos con Lavado, Aspirado y Encerado: " << (Lavado_Completo > 0 ? dinero_LavadoCompleto / Lavado_Completo : 0) << " colones";
    setColor(6);
    gotoxy(17, 20); cout << "<Pulse tecla para regresar al menu>";
    getch();
}


void Grafico_Vehiculos() { // funcion para ver grafico de vehiculos lavados por tipo de vehiculo
    int Sencillos = 0, Vehiculo_4x4 = 0, Microbus = 0;   
	    for (int i = 0; i < num_Vehiculos; i++) {  // recorrer el arreglo de vehiculos y calcula cantidades ppor tipo de vehiculo
	        switch (vehiculos[i].tipo_Vehiculo) {
	            case 1:
	                Sencillos++; break;
	            case 2:
	                Vehiculo_4x4++; break;
	            case 3:
	                Microbus++; break;
	        }
	    }

    // mostrar el grafico
    system("cls");
    setColor(15);
    gotoxy(17, 8); cout << "GRAFICA TIPO DE VEHICULO";
    setColor(6);
    gotoxy(17, 12); cout << "Veh. Sencillos: ";
    grafico(Sencillos, 12);
    gotoxy(17, 14); cout << "Veh. 4x4: ";
    grafico(Vehiculo_4x4, 14);
    gotoxy(17, 16); cout << "Veh. Pesados: ";
    grafico(Microbus, 16);
    setColor(15);
    gotoxy(17, 20); cout << "<Pulse tecla para regresar al menu>";
    getch();
}

// funcion para ver grafico de vehiculos lavados por tipo de lavado
void Grafico_Lavados() {
    int cantidadSoloLavado = 0, cantidadCompleto = 0;

    // recorrer el arreglo de vehiculos para calcular las cantidades
    for (int i = 0; i < num_Vehiculos; i++) {
        switch (vehiculos[i].tipo_Lavado) {
            case 1:
                cantidadSoloLavado++; break;
            case 2:
                cantidadCompleto++; break;
        }
    }
    
    // mostrar el grafico
    system("cls");
    setColor(15);
    gotoxy(17, 8); cout << "GRAFICA TIPO DE LAVADO";
    setColor(6);
    gotoxy(17, 12); cout << "Lavado sencillo: ";
    grafico(cantidadSoloLavado, 12);
    gotoxy(17, 14); cout << "Lavado Completo: ";
    grafico(cantidadCompleto, 14);
    setColor(15);
    gotoxy(17, 20); cout << "<Pulse tecla para regresar al menu>";
    getch();
}

// funcion para hacer los graficos
void grafico(int a, int y) {
    int i;
    int j = 40;
    for (i = 1; i <= a; i++) {
        gotoxy(j, y);
        printf("%c", 178);
        j++;
    }
}

int main(int argc, char** argv) {
	
	 Menu(); //Llama a la funcion Menu para iniciar el programa
    
	return 0;
}
