#include "Alumno.h"

stAlumno cargarAlumno(){

    stAlumno alumno;

    FILE * archi = NULL;

    archi = fopen(ALUMNOS, "ab");

    if(archi != NULL){
        printf("NOMBRE y APELLIDO: ");
        fflush(stdin);
        gets(alumno.nombreYapellido);

        printf("\nANIO QUE CURSA: ");
        scanf("%d", &alumno.anio);

        printf("\nEDAD: ");
        scanf("%d", &alumno.edad);

        alumno.legajo = rand()%10000;

        fwrite(&alumno, sizeof(stAlumno), 1, archi);

    }else{
        printf("ERROR AL ABRIR EL ARCHIVO");
        fclose(archi);
    }

return alumno;
}

void cargarVariosAlumnos (stAlumno alumnos[]){

    char control = 0;
    int i = 0;

    do{
       alumnos[i] = cargarAlumno();
       i++;

       printf("Para dejar de cargar presione esc...\n");
       fflush(stdin);
       control = getch();

    }while(control != 27 && i < DIM);

}

void mostrarAlumnosDesdeArchivo(){

    stAlumno alumnos[100];
    int i = 0;

    FILE *archi = NULL;

    archi = fopen(ALUMNOS, "rb");

    if(archi){
        while(fread(alumnos, sizeof(stAlumno), 1, archi) > 0){
            printf("\n");
            mostrarAlumno(alumnos[i]);
        }

    }else{
        printf("ERROR AL ABRIR EL ARCHIVO\n");
        fclose(archi);
    }
}

void mostrarAlumno (stAlumno alumno){

    printf("NOMBRE Y APELLIDO: %s\n", alumno.nombreYapellido);

    printf("EDAD: %d\n", alumno.edad);

    printf("ANIO QUE CURSA: %d\n", alumno.anio);

    printf("LEGAJO: %d\n", alumno.legajo);
}

void pasarArchivoAPilaMayores (Pila * pilita, char archivo[]){

    stAlumno alumno;

    FILE * archi = NULL;

    archi = fopen(archivo, "rb");

    if(archi){
        while(fread(&alumno, sizeof(stAlumno), 1, archi) > 0){
            if(alumno.edad >= 18){
                apilar(pilita, alumno.legajo);
            }
        }

    }else{
        printf("ERROR AL ABRIR EL ARCHIVO\n");
        fclose(archi);
    }

}

int contarAlumnosMayores (char archivo[], int edad){

    int i = 0;

    stAlumno alumno;

    FILE *archi = NULL;

    archi = fopen(archivo, "rb");

    if(archi){
        while(fread(&alumno, sizeof(stAlumno), 1, archi) > 0){
            if(alumno.edad >= edad){
                i++;
            }
        }
    }else{
        printf("ERROR AL ABRIR EL ARCHIVO\n");
        fclose(archi);
    }

return i;
}

void mostrarAlumnosRango (int min, int max){

    stAlumno alumnos;

    FILE * archi = NULL;

    archi = fopen(ALUMNOS, "rb");

    if(archi){
        while(fread(&alumnos, sizeof(stAlumno), 1, archi) > 0){
            if(alumnos.edad >= min && alumnos.edad <= max){
            }
        }
    }else{
        printf("ERROR AL ABRIR EL ARCHIVO\n");
        fclose(archi);
    }
}
