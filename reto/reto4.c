#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int caracteres;
    int palabras;
    int espacios;
    int lineas;
} Estadisticas;

char* leerArchivo(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        perror("Error al abrir el archivo");
        return NULL;
    }

    fseek(archivo, 0, SEEK_END);
    long tam = ftell(archivo);
    rewind(archivo);

    char* contenido = (char*)malloc(tam + 1);
    if (!contenido) {
        perror("Error al asignar memoria");
        fclose(archivo);
        return NULL;
    }
