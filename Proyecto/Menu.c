#include <stdio.h>
#include <stdlib.h> //para el limpiar la consola
#include <ctype.h> //Para validar si es numero
#include "Estructura.h"
#include "AltaTrabajadores.h"
#include "ConsultasGenerales.h"
#include "ConsultaNumeroEmpleado.h"
#include "ConsultaPorNombre.h"//libreria para colores
#include <windows.h>
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_MAGENTA 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

int main() { 
    char entrada;
    int op;
    FILE *archivo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("Universidad Nacional de Ingenieria\n");
    printf("*************** UNI ***************\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("Proyecto de curso de programacion.\n");
    printf("Grupo: 1M3\n");
    printf("Equipo: 7");
    printf("Integrantes:\n");
    printf("1. Mileyda Ines Trana Castaneda\n");
    printf("2. Harold Yafer Molina Sandoval\n");
    printf("3. Mario Antonio Varela Alvarez\n");    
    Sleep(1000);
    system("cls");

    archivo = fopen("Archivo.txt", "a"); // Abre el archivo en modo "append" para agregar datos

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Cierra el archivo
    fclose(archivo);

     while(op!=6)
    {
        op = 0;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        
        printf("**********************************\n");
        printf("******** Menu principal **********\n");
        printf("**********************************\n");
        printf("1.- Dar de alta a trabajadores \n");
        printf("2.- Consultas generales\n");
        printf("3.- Consultas por numero de empleado\n");
        printf("4.- Consultas por nombre\n");
        printf("5.- Dar de baja a trabajadores\n");
        printf("6.- Salir\n");
        printf("********************************\n");
        printf("Indica la opcion del menu: \n");   
        scanf("%c", &entrada);
       
        if (isdigit(entrada)) {   
            op = entrada - '0'; 
            
            if(op <= 6 && op > 0){
                int resultado;
                printf("\n");
                switch(op)
                {
                    case 1: 
                     
                        printf("********************************\n");
                        printf("** Dar de alta a trabajadores **\n");
                        printf("********************************\n");

                        resultado = AltaTrabajador(); 

                        if (resultado == 1)
                        {
                            printf("Error al dar de alta a trabajadores");
                        }
                        
                        Sleep(2000);
                        break;
                    case 2: 
                    
                        printf("********************************\n");
                        printf("***** Consultas Generales ******\n");
                        printf("********************************\n");

                        ConsultasGenerales(); 
                        Sleep(2000);
                        break;
                    case 3: 
                        printf("*************************************\n");
                        printf("**Consultas por numero de empleado **\n");
                        printf("*************************************\n");

                        ConsultasNumeroEmpleado();  
                        Sleep(2000);
                        break;
                    case 4: 
                   
                         printf("*************************************\n");
                        printf("**Consultas por nombre **\n");
                        printf("*************************************\n");

                        ConsultasPorNombre(); 
                        Sleep(2000);
                        break;
                    case 5: 
                        printf("Opcion seleccionada del menu: %d\n", op);

                        Sleep(2000);
                        break;
                    case 6: 
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                        printf("Saliendo del sistema");
                        Sleep(1000);
                        break;
                }

                system("cls");

            } else {
                printf("La opcion seleccionada es incorrecta \n");
                Sleep(2000);
                system("cls");
            }  

        } else {        
            op = 0;    
            Sleep(2000);
            printf("La opcion no es valida \n");
            system("cls");
        }
        
    }
    return 0;
}
