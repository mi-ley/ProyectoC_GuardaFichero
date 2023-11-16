#include <stdio.h>
#include <string.h>
#include <windows.h>

int AltaTrabajador() {  
    FILE *archivo;
    int cantRegistros;
    int contador = 0;
    int contador2 = 1;
    int aux = 0;
    char identificador[100];
    char NumeroEmpleado[100];
    char nombre[100];
    char apellido[100];
    char salario[15];    
    char cargo[100];
    char estado[15];
       
    //Hacemos un conteos de los registros  
    archivo = fopen("Archivo.txt", "r"); // Abre el archivo en modo lectura   
    char linea[1024]; 
    while (fgets(linea, sizeof(linea), archivo) != NULL) {                            
        contador += 1;
    }   
    fclose(archivo);

    printf("Cantidad de registros que desea ingresar: ");
    scanf("%d", &cantRegistros);        
    printf("\nCantidad de registros actuales: %d\n", contador); 
   
    do
    {   
        
        printf("\n Ingresando el registro %d de %d\n", contador2, cantRegistros);        
       
        aux = 0;
        //Aqui validamos que no ingresen el mismo numero de empleado
        while (aux >= 0)
        {    
            printf("Ingrese el numero del trabajador: ");
            scanf("%s", NumeroEmpleado);                

            archivo = fopen("Archivo.txt", "r"); // Abre el archivo en modo lectura  
            char linea2[1024]; 
            while (fgets(linea2, sizeof(linea2), archivo) != NULL) { 
                if (strstr(linea2, NumeroEmpleado) != NULL)
                {
                    aux += 1;
                }   
            }  
            
            fclose(archivo);

            if (aux > 0)
            {
                printf("El codigo del trabajador ingresado ya existe \n");
                aux = 0;
            }else{
                aux = -1;
            }    

        }
        
       
        printf("Ingrese el nombre del trabajador: ");
        scanf("%s", nombre);
        printf("Ingrese el apellido del trabajador: ");
        scanf("%s", apellido);
        printf("Ingrese el salario del trabajador: ");
        scanf("%s", salario);
        printf("Ingrese el cargo del trabajador: ");
        scanf("%s", cargo);
        strcpy(estado, "Activo");        

        //Guarda los registros
        archivo = fopen("Archivo.txt", "a"); // Abre el archivo en modo "append" para agregar datos
        if (archivo == NULL) {
            printf("No se pudo abrir el archivo.\n");
            return 1;
        }
       
        contador +=1;
        fprintf(archivo, "%d,", contador);
        fprintf(archivo, "%s,", NumeroEmpleado);
        fprintf(archivo, "%s,", nombre);
        fprintf(archivo, "%s,", apellido);
        fprintf(archivo, "%s,", salario);
        fprintf(archivo, "%s,", cargo);
        fprintf(archivo, "%s", estado); 
        fprintf(archivo, "\n");

        // Cierra el archivo
        fclose(archivo);  

        contador2 += 1; 
   
    } while (cantRegistros >= contador2);
   
    printf("\n Los datos del cliente han sido guardados en clientes.txt. \n");

    Sleep(1500);

    return 0;
}