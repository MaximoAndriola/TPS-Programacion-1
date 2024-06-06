#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define DIM 50
#include "pila.h"
#define ALUMNOS "alumnos.bin"


typedef struct {
     int legajo;
     char nombreYapellido [30];
     int edad;
     int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;

stAlumno cargarAlumno();
void cargarVariosAlumnos (stAlumno alumnos[]);
void mostrarAlumno (stAlumno alumno);
void mostrarAlumnosDesdeArchivo();
void pasarArchivoAPilaMayores (Pila * pilita, char archivo[]);
int contarAlumnosMayores (char archivo[], int edad);

#endif // ALUMNO_H_INCLUDED
