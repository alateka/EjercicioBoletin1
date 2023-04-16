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

    int counter = 0; 
    while ( asignaturas[counter].clave == NULL || counter <= 44 )
    {
        asignaturas[counter] = a;
        counter++;
    }
}

void list()
{
    int counter = 0;
    while (asignaturas[counter].clave == NULL || counter <= 44 )
    {
        printf("|n==========================\n");
        printf(">>> %c", asignaturas[counter].clave);
        counter++;
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