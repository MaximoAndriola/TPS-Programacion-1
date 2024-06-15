#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"
#include "time.h"

void mostrarOpciones ();
void subMenuMostrarAlumnos ();
void subMenuContarAlumnos ();

int main()
{
    srand(time(NULL));

    menu();

    return 0;
}

void menu (){

    char control = 0;
    int opcion = 0;
    int i = 0;
    int anio;
    int legajo;

    Pila pilita;
    inicpila(&pilita);

    stAlumno alumnito[DIM];

    do{
        mostrarOpciones();

        scanf("%d", &opcion);

        switch(opcion){

        case 1:

            subMenuMostrarAlumnos();

            break;

        case 2:

            cargarVariosAlumnos(alumnito);

            break;

        case 3:

            subMenuContarAlumnos();

            break;

        case 4:

            printf("INGRESAR QUE ANIO DESEA COPIAR: ");
            scanf("%d", &anio);

            i = pasarArchivoAArregloAnio(ALUMNOS, alumnito, anio);

            system("cls");
            mostrarAlumno(alumnito[0]);
            printf("\n%d alumnos fueron copiados", i);

            break;

        case 5:

            system("cls");
            printf("LEGAJO:");
            scanf("%d", &legajo);

            modificarRegistro(ALUMNOS, legajo);

            break;

        case 6:

            invertirDatosArchivo(ALUMNOS);


            break;
        }

        system("pause");
        system("cls");
    }while(opcion != 27);
}

void mostrarOpciones (){

    printf("----------------------------------------------\n");
    printf("1- MOSTRAR ALUMNOS CARGADOS\n");
    printf("----------------------------------------------\n");
    printf("2- CARGAR NUEVO ALUMNO\n");
    printf("----------------------------------------------\n");
    printf("3- CONTAR ALUMNOS\n");
    printf("----------------------------------------------\n");
    printf("4- DESCARGAR DATOS DE UN CURSO\n");
    printf("----------------------------------------------\n");
    printf("5- MODIFICAR UN REGISTRO\n");
    printf("----------------------------------------------\n");
    printf("6- INVERTIR EL REGISTRO DE ALUMNOS\n");
    printf("----------------------------------------------\n");

}

void subMenuMostrarAlumnos (){

    system("cls");

    int opcion = 0;
    int min;
    int max;
    int nro;

    printf("----------------------------------------------\n");
    printf("1- MOSTRAR TODOS LOS ALUMNOS\n");
    printf("----------------------------------------------\n");
    printf("2- FILTRAR POR EDAD\n");
    printf("----------------------------------------------\n");
    printf("3- MOSTRAR MAYORES\n");
    printf("----------------------------------------------\n");
    printf("4- MOSTRAR UN REGISTRO\n");
    printf("----------------------------------------------\n");


    scanf("%d", &opcion);

    switch(opcion){

    case 1:

        system("cls");

        mostrarAlumnosDesdeArchivo(ALUMNOS);

        break;

    case 2:

        printf("EDAD MINIMA: ");
        scanf("%d", &min);

        printf("\nEDAD MAXIMA: ");
        scanf("%d", &max);

        mostrarAlumnosRango(min, max);

        break;

    case 3:

        mostrarAlumnoMayor(ALUMNOS);

        break;

    case 4:

        printf("NUMERO DE REGISTRO: ");
        scanf("%d", &nro);

        mostrarUnRegistroArchivo(ALUMNOS, nro);

        break;
    }

}

void subMenuContarAlumnos (){

    system("cls");

    int opcion = 0;
    int edadMin = 0;
    int anio = 0;
    int cant = 0;

    printf("----------------------------------------------\n");
    printf("1- CONTAR MAYORES\n");
    printf("----------------------------------------------\n");
    printf("2- CONTAR POR ANIO\n");
    printf("----------------------------------------------\n");
    printf("3- CONTAR REGISTROS EN EL ARCHIVO\n");
    printf("----------------------------------------------\n");

    scanf("%d", &opcion);

    switch(opcion){

    case 1:

        system("cls");
        printf("EDAD MINIMA: ");
        scanf("%d", &edadMin);

        cant = contarAlumnosMayores(ALUMNOS, edadMin);

        printf("----------------------------------------------\n");
        printf("%d alumnos\n", cant);
        printf("----------------------------------------------\n");

        break;

    case 2:

        system("cls");
        printf("ANIO: ");
        scanf("%d", &anio);

        cant = contarAlumnosAnio(ALUMNOS, anio);

        printf("----------------------------------------------\n");
        printf("%d alumnos\n", cant);
        printf("----------------------------------------------\n");

        break;

    case 3:

        system("cls");

        cant = contarRegistrosArchivo(ALUMNOS);

        printf("----------------------------------------------\n");
        printf("%d alumnos\n", cant);
        printf("----------------------------------------------\n");

        break;
    }
}
