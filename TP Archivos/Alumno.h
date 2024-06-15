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
void mostrarAlumnosDesdeArchivo(char archivoNombre[]);
void pasarArchivoAPilaMayores (Pila * pilita, char archivo[]);
int contarAlumnosMayores (char archivo[], int edad);
void mostrarAlumnosRango (int min, int max);
void mostrarAlumnoMayor ();
int buscaPosMayor (int nums[], int v);
int contarAlumnosAnio (char archivo[], int anio);
void pasarArregloAArchivo (char archivo[], stAlumno arreglo[], int v);
int pasarArchivoAArregloAnio (char archivo[], stAlumno arreglo[], int anio);
int contarRegistrosArchivo (char archivo[]);
int cargarArregloAlumnos (stAlumno arreglo[]);
void mostrarUnRegistroArchivo (char archivo[], int nro);
void modificarRegistro (char archivo[], int legajo);
stAlumno modificarAlumno (stAlumno alumno);
void invertirDatosArchivo (char archivo[]);

#endif // ALUMNO_H_INCLUDED
