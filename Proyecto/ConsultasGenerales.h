#include <stdio.h>
#include <windows.h>

int ConsultasGenerales() {    
    char salir = 'N';
    FILE *archivo;  
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
     
    char linea[1024]; 
    while (fgets(linea, sizeof(linea), archivo) != NULL) {     
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
                
        //strcmp nos retorna 0 si el estado es False
        if (strcmp(estado, "Activo") == 0) {
            printf("El empleado %s no se encuentra %s\n", nombre, estado);
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
     
    printf("Para regresar al menu principal Ingrese la letra S porteriormente presione Enter :\n");
    while(toupper(salir) != 'S')
    {              
        scanf("%c", &salir);              
    }      
   
    // Cierra el archivo
    fclose(archivo);  

    return 0;
}