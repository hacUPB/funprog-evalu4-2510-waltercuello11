#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int caracteres;
    int palabras;
    int espacios;
    int lineas;
} Estadisticas;

typedef struct {
    int a, e, i, o, u;
} FrecuenciaVocales;

char* leerArchivo(const char* nombre) {
    FILE* archivo = fopen(nombre, "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }

    }

    fseek(archivo, 0, SEEK_END);
    long tam = ftell(archivo);
    rewind(archivo);

    char* buffer = (char*)malloc((tam + 1) * sizeof(char));
    if (!buffer) {
        printf("No se pudo asignar memoria.\n");
        fclose(archivo);
        return NULL;
    }

    fread(buffer, 1, tam, archivo);
    buffer[tam] = '\0';
    fclose(archivo);
    return buffer;
}

}
Estadisticas calcularEstadisticas(const char* texto) {
    Estadisticas est = {0, 0, 0, 0};
    int enPalabra = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];

        if (c != '\n')
            est.caracteres++;

        if (c == ' ') {
            est.espacios++;
            enPalabra = 0;
        } else if (c == '\n') {
            est.lineas++;
            enPalabra = 0;
        } else if (!enPalabra) {
            est.palabras++;
            enPalabra = 1;
        }
    }




