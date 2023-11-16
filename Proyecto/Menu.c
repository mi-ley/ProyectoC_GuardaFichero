#include <stdio.h>
#include <windows.h> //para el sleep
#include <stdlib.h> //para el limpiar la consola
#include <ctype.h> //Para validar si es numero
#include "Estructura.h"
#include "AltaTrabajadores.h"
#include "ConsultasGenerales.h"
#include "ConsultaNumeroEmpleado.h"
#include "ConsultaPorNombre.h"

int main() { 
    char entrada;
    int op;
    FILE *archivo;

    printf("Universidad Nacional de Ingenieria\n");
    printf("*************** UNI ***************\n");
    printf("Proyecto de curso de programacion.\n");
    printf("Grupo: 1M3\n");
    printf("Integrantes:\n");
    printf("1. Mileyda Ines Trana Castaneda\n");
    printf("2. ----------------------------\n");
    printf("3. ----------------------------\n");    
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
        printf("**********************************\n");
        printf("******** Menu principal **********\n");
        printf("**********************************\n");
        printf("1.- Dar de alta a trabajadores\n");
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
