#include "Alumno.h"

stAlumno cargarAlumno(){

    system("cls");

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
        fclose(archi);
    }else
        printf("ERROR AL ABRIR EL ARCHIVO");

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

void mostrarAlumnosDesdeArchivo(char archivoNombre[]){

    stAlumno alumnos[100];
    int i = 0;

    FILE *archi = NULL;

    archi = fopen(archivoNombre, "rb");

    if(archi){
        while(fread(alumnos, sizeof(stAlumno), 1, archi) > 0){
            printf("\n");
            mostrarAlumno(alumnos[i]);
        }
        fclose(archi);
    }else
        printf("ERROR AL ABRIR EL ARCHIVO\n");

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
        fclose(archi);
    }else
        printf("ERROR AL ABRIR EL ARCHIVO\n");

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
        fclose(archi);
    }else
        printf("ERROR AL ABRIR EL ARCHIVO\n");

return i;
}

void mostrarAlumnosRango (int min, int max){

    stAlumno alumnos;

    FILE * archi = NULL;

    archi = fopen(ALUMNOS, "rb");

    if(archi){
        while(fread(&alumnos, sizeof(stAlumno), 1, archi) > 0){
            if(alumnos.edad >= min && alumnos.edad <= max){
                mostrarAlumno(alumnos);
            }
        }
        fclose(archi);
    }else
        printf("ERROR AL ABRIR EL ARCHIVO\n");

}

void mostrarAlumnoMayor (char archivo[]){

    int mayor;
    int i = 0;
    stAlumno alumno[DIM];
    stAlumno aux;

    FILE * archi = NULL;

    archi = fopen(archivo, "rb");

    if(archi){

        while(fread(&aux, sizeof(stAlumno), 1, archi) > 0){
            alumno[i] = aux;
            i++;
        }

        mayor = buscaPosMayor(alumno, i);

        mostrarAlumno(alumno[mayor]);

        fclose(archi);
    }else
        printf("ERROR AL ABRIR EL ARCHIVO\n");

}

int buscaPosMayor (int nums[], int v){

    int mayor = nums[0];
    int posMayor = 0;


    for(int i = 0; i < v; i++){
        if(mayor < nums[i]){
            posMayor = i;
        }
    }

return posMayor;
}

int contarAlumnosAnio (char archivo[], int anio){

    int cant = 0;

    stAlumno aux;

    FILE *archi = NULL;

    archi = fopen(archivo, "rb");

    if(archi){
        while(fread(&aux, sizeof(stAlumno), 1, archi) > 0){
            if(anio == aux.anio){
                cant++;
            }
        }


        fclose(archi);
    }else
        printf("ERROR AL ABRIR EL ARCHIVO\n");


return cant;
}

void pasarArregloAArchivo (char archivo[], stAlumno arreglo[], int v){

    FILE * archi = NULL;

    archi = fopen(archivo, "wb");

    if(archi){
        fwrite(arreglo, sizeof(stAlumno), v, archi);

        fclose(archi);
    }else
        printf("ERROR AL ABRIR EL ARCHIVO\n");

}

int pasarArchivoAArregloAnio (char archivo[], stAlumno arreglo[], int anio){

    stAlumno aux;

    int i = 0;

    FILE * archi = NULL;

    archi = fopen(archivo, "rb");

    if(archi){
        while(fread(&aux, sizeof(stAlumno), 1, archi) > 0){
            if(aux.anio == anio){
                arreglo[i] = aux;
                i++;

            }
        }

        fclose(archi);
    }else
        printf("ERROR AL ABRIR EL ARCHIVO\n");

return i;
}

int contarRegistrosArchivo (char archivo[]){

    stAlumno aux;
    int cant = 0;

    FILE *archi = NULL;

    archi = fopen(archivo, "rb");

    if(archi){
        fseek(archi, 0, SEEK_END);
        cant = ftell(archi);

        cant /= sizeof(stAlumno);

        fclose(archi);
    }else
        printf("ERROR AL ABRIR EL ARCHIVO\n");

return cant;
}

int cargarArregloAlumnos (stAlumno arreglo[]){

    int i = 0;
    char control = 0;

    do{
        arreglo[i] = cargarAlumno();
        i++;

        printf("Para dejar de cargar persione esc...\n");
        fflush(stdin);
        control =
        getch();
    }while(control != 27 && i < DIM);


return i;
}

void mostrarUnRegistroArchivo (char archivo[], int nro){

    int i = 0;
    int bandera = 0;
    stAlumno aux;

    FILE *archi = NULL;

    archi = fopen(archivo, "rb");

    if(archi){
        int nroAlumnos = ftell(archi) / sizeof(stAlumno);
        if(nroAlumnos >= nro){
            nro *= sizeof(stAlumno);
            while(bandera = 1 && fread(&aux, sizeof(stAlumno), 1, archi) > 0){
                if(nro == i){
                    bandera = 1;
                }
            i++;
            }
        }else
            printf("EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO...\n");

        fclose(archi);
    }else
        printf("ERROR AL ABRIR EL ARCHIVO\n");

}
