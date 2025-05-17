#include <stdio.h>      // Para funciones de entrada/salida como printf, scanf, fopen, etc.
#include <stdlib.h>     // Para funciones de gestión de memoria dinámica como malloc, free.
#include <string.h>     // Para funciones de manejo de cadenas como strlen, strcpy, strstr.

#define MAX_FILENAME 256  // Tamaño máximo para nombres de archivo.
#define MAX_PALABRA 100   // Tamaño máximo para palabras a buscar/reemplazar.

// Lee el contenido de un archivo de texto y lo devuelve como una cadena dinámica.
char* leerArchivo(const char* nombre) {
    FILE* archivo = fopen(nombre, "r");  // Abre el archivo en modo lectura.
    if (!archivo) {
        printf("No se pudo abrir el archivo.\n");
        return NULL;  // Retorna NULL si falla.
    }

    fseek(archivo, 0, SEEK_END);         // Mueve el puntero al final del archivo.
    long tam = ftell(archivo);           // Obtiene la posición actual (tamaño del archivo).
    rewind(archivo);                     // Vuelve al inicio del archivo.

    char* buffer = (char*)malloc((tam + 1) * sizeof(char));  // Reserva memoria para el contenido + '\0'.
    if (!buffer) {
        printf("No se pudo asignar memoria.\n");
        fclose(archivo);
        return NULL;
    }

    fread(buffer, 1, tam, archivo);  // Lee el archivo en el buffer.
    buffer[tam] = '\0';              // Agrega terminador nulo al final.
    fclose(archivo);
    return buffer;
}
    