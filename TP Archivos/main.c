#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"
#include "time.h"


int main()
{
    srand(time(NULL));

    int i;
    Pila pilita;

    inicpila(&pilita);

    stAlumno alumnito[DIM];

//    cargarVariosAlumnos(alumnito);

    mostrarAlumnosDesdeArchivo();

//    pasarArchivoAPilaMayores(&pilita, ALUMNOS);
//
//    mostrar(&pilita);

//    i = contarAlumnosMayores(ALUMNOS, 18);


    return 0;
}
