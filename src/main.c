#include <stdio.h>
#include <string.h>

struct asignatura
{
    char clave;
    char titulo[80];
    char profesor[40];
    char descripcion[80];
};

struct asignatura asignaturas[44];


int alta()
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
    while ( counter <= 44 )
    {
        if ( asignaturas[counter].clave == NULL ) {
            asignaturas[counter] = a;
            counter = 45;
        }
        counter++;
    }
}

int main()
{
    int opcion = 0;
    while (opcion != 2)
    {
        printf("------------------------------------------\n");
        printf("==> Seleccione una opción \n");
        printf("- 1 ( Dar de alta una asignatura ) \n");
        printf("- 2 ( Salir ) \n");
        printf("\n--> ");
        scanf("%i", &opcion);

        switch (opcion)
        {
            case 1:
                alta();
                break;
            
            default:
                break;
        }
    }
    
    return 0;
}