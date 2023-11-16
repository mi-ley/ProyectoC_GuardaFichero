#include <stdio.h>
#include <windows.h>
#include <string.h>

int ConsultasPorNombre() {
    FILE *archivo;  
    char NombreConsultado[100];
    int aux = 0;
    char identificador[100];
    char NumeroEmpleado[100];
    char nombre[100];
    char apellido[100];
    char salario[15];    
    char cargo[100];
    char estado[15]; 
    
    archivo = fopen("Archivo.txt", "r"); // Abre el archivo en modo lectura

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    printf("Ingrese el Nombre del trabajador que desea consultar: \n");
    scanf("%s", &NombreConsultado);
          
    //Validamos si existe el Nombre del trabajador
    char linea1[1024]; 
    while (fgets(linea1, sizeof(linea1), archivo) != NULL) {               
        if (strstr(linea1, NombreConsultado) != NULL)
                {
                    aux += 1;
                }   
    }

    rewind(archivo); 
    
    //Si no encuentra el numero del trabajador retornamos al menu
    if (aux == 0){                        
        printf("Nombre de empleado no encontrado.\n");  
        Sleep(5000);  
        return 1;            
    } 

    char linea[1024]; 
    while (fgets(linea, sizeof(linea), archivo) != NULL) {  
        //Buscamos los registros del trabajador 
        if (strstr(linea, NombreConsultado) != NULL){
            //Separamos los valores                  
            char *token = strtok(linea, ",");    
            
            //Asignamos los valores al struct de empleados
            strcpy(identificador, token);
            // Llamar a strtok(NULL, ",") para obtener el siguiente token
            token = strtok(NULL, ",");

            strcpy(NumeroEmpleado, token);
            token = strtok(NULL, ",");
            strcpy(nombre, token);
            token = strtok(NULL, ",");
            strcpy(apellido, token);
            token = strtok(NULL, ",");
            strcpy(salario, token);
            token = strtok(NULL, ",");
            strcpy(cargo, token);
            token = strtok(NULL, ",");
            strcpy(estado, token);

            
            if (strstr(estado, "Activo") == NULL) {
                printf("El empleado %s se encuentra dado de Baja\n", nombre);
            }else{           
                printf("******************************** \n");
                printf("Identificador:  %s\n", identificador);
                printf("Num empleado:   %s\n", NumeroEmpleado);
                printf("Nombre:         %s\n", nombre);
                printf("Apellido:       %s\n", apellido);
                printf("Salario:        %s\n", salario);
                printf("Cargo:          %s\n", cargo);
                printf("Estado:         %s\n", estado);
            }  

        }     
    }  
    
    // Cierra el archivo
    fclose(archivo);  

    Sleep(5000);  

    return 0;
}