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

int counter = 0;

struct asignatura asignaturas[44];


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

void list()
{
    int i = 0;
    while ( i <= 44 )
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
    while (opcion != 3) 
    {
        printf("------------------------------------------\n");
        printf("==> Seleccione una opción \n");
        printf("- 1 ( Dar de alta una asignatura ) \n");
        printf("- 2 ( Listar asignaturas ) \n");
        printf("- 3 ( Salir ) \n");
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

            default:
                break;
        }
    }
    
    return 0;
}