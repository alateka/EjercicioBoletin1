#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct asignatura
{
    char clave;
    char titulo[80];
    char profesor[40];
    char descripcion[80];
};

#define TAMANIO_INICIAL 44
int counter = 0;
struct asignatura asignaturas[TAMANIO_INICIAL];
int tamanio = sizeof(asignaturas) / sizeof(asignaturas[0]);


void alta()
{
    struct asignatura a;
    printf("------------------------------------------\n");
    printf("==> Introduce los datos de la asignatura \n");
    printf("\n--> Clave: ");
    scanf(" %c", &a.clave);
    printf("\n--> Título de la asignatura: ");
    scanf("%s", &a.titulo);
    printf("\n--> Profesor: ");
    scanf("%s", &a.profesor);
    printf("\n--> Descripción: ");
    scanf("%s", &a.descripcion);

    asignaturas[counter] = a;
    counter++;
}

void eliminar()
{
    char claveBorrar;
    printf("\n==> Indique una clave");
    printf("\n--> ");
    scanf(" %c", &claveBorrar);

    for (int i = 0; i < TAMANIO_INICIAL; i++) {
        
        if ( asignaturas[i].clave == claveBorrar ) {

            while ( i < tamanio - 1 ) {
                asignaturas[i] = asignaturas[i + 1];
                i++;
            }
            tamanio--;
            counter--;
        }
    }
}

void list()
{
    int i = 0;
    while ( i <= TAMANIO_INICIAL )
    {
        if ( asignaturas[i].clave ) {
            
            printf("\n ==> Numero de la lista: %i", i);
            printf("\n==========================================\n >>> Clave asignatura: ");
            printf("%c", asignaturas[i].clave);
            printf("\n==========================================\n >>> Título: ");
            printf("%s", asignaturas[i].titulo);
            printf("\n==========================================\n >>> Profesor: ");
            printf("%s", asignaturas[i].profesor);
            printf("\n==========================================\n >>> Descripción: ");
            printf("%s", asignaturas[i].descripcion);
            printf("\n==========================================\n");
            printf("\n\n");
            i++;

        } else return;
        
    }
}

int main()
{
    int opcion = 0;
    while ( opcion != 4 ) 
    {
        printf("\n------------------------------------------\n");
        printf("==> Seleccione una opción \n");
        printf("- 1 ( Dar de alta una asignatura ) \n");
        printf("- 2 ( Listar asignaturas ) \n");
        printf("- 3 ( Eliminar una asignatura ) \n");
        printf("- 4 ( Salir ) \n");
        printf("\n--> ");
        scanf("%i", &opcion);

        switch (opcion)
        {
            case 1:
                alta();
                break;

            case 2:
                list();
                break;
            
            case 3:
                eliminar();
                break;

            default:
                break;
        }
    }
    
    return 0;
}