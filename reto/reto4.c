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
    // Calcula estadísticas del texto: caracteres, palabras, espacios y líneas.
void calcularEstadisticas(const char* texto, int* caracteres, int* palabras, int* espacios, int* lineas) {
    *caracteres = *palabras = *espacios = *lineas = 0;
    int enPalabra = 0;  // Variable auxiliar para detectar inicios de palabras.

    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];

        if (c != '\n')
            (*caracteres)++;  // Cuenta caracteres (excepto saltos de línea).

        if (c == ' ') {
            (*espacios)++;    // Cuenta espacios.
            enPalabra = 0;    // Ya no estamos dentro de una palabra.
        } else if (c == '\n') {
            (*lineas)++;      // Cuenta líneas.
            enPalabra = 0;
        } else if (!enPalabra) {
            (*palabras)++;    // Detecta inicio de nueva palabra.
            enPalabra = 1;
        }
    }

    // Si el texto no termina en salto de línea, suma una línea más.
    if (texto[0] != '\0' && texto[strlen(texto) - 1] != '\n')
        (*lineas)++;
}

// Cuenta la cantidad de cada vocal (minúscula o mayúscula) sin usar tolower().
void contarVocales(const char* texto, int* a, int* e, int* i, int* o, int* u) {
    *a = *e = *i = *o = *u = 0;

    for (int j = 0; texto[j] != '\0'; j++) {
        char c = texto[j];
        if (c == 'a' || c == 'A') (*a)++;
        else if (c == 'e' || c == 'E') (*e)++;
        else if (c == 'i' || c == 'I') (*i)++;
        else if (c == 'o' || c == 'O') (*o)++;
        else if (c == 'u' || c == 'U') (*u)++;
    }
}

// Reemplaza todas las apariciones de una palabra por otra en un nuevo texto dinámico.
char* reemplazarPalabra(const char* texto, const char* palabra, const char* reemplazo) {
    int lenTexto = strlen(texto);
    int lenPalabra = strlen(palabra);
    int lenReemplazo = strlen(reemplazo);

    int nuevasOcurrencias = 0;
    const char* temp = texto;

    // Cuenta cuántas veces aparece la palabra a reemplazar.
    while ((temp = strstr(temp, palabra)) != NULL) {
        nuevasOcurrencias++;
        temp += lenPalabra;
    }

    // Calcula el nuevo tamaño del texto con reemplazos.
    int nuevoTam = lenTexto + nuevasOcurrencias * (lenReemplazo - lenPalabra);
    char* nuevoTexto = (char*)malloc(nuevoTam + 1);
    if (!nuevoTexto) {
        printf("Error al asignar memoria para el texto modificado.\n");
        return NULL;
    }

    // Copia texto al nuevo buffer con los reemplazos aplicados.
    const char* actual = texto;
    char* destino = nuevoTexto;

    while (*actual) {
        if (strstr(actual, palabra) == actual) {
            strcpy(destino, reemplazo);      // Copia la palabra de reemplazo.
            actual += lenPalabra;
            destino += lenReemplazo;
        } else {
            *destino++ = *actual++;          // Copia carácter normal.
        }
    }

    *destino = '\0';  // Finaliza cadena.
    return nuevoTexto;
}

/ Guarda las estadísticas, frecuencia de vocales y texto resultante en un nuevo archivo.
void guardarResultados(const char* nombreArchivo, int caracteres, int palabras, int espacios, int lineas,
                       int a, int e, int i, int o, int u, const char* texto) {
    FILE* archivo = fopen(nombreArchivo, "w");
    if (!archivo) {
        printf("No se pudo crear el archivo de salida.\n");
        return;
    }

    // Escribe estadísticas al archivo.
    fprintf(archivo, "Estadísticas:\n");
    fprintf(archivo, "Caracteres: %d\n", caracteres);
    fprintf(archivo, "Palabras: %d\n", palabras);
    fprintf(archivo, "Espacios: %d\n", espacios);
    fprintf(archivo, "Líneas: %d\n", lineas);

    // Escribe frecuencia de vocales.
    fprintf(archivo, "\nFrecuencia de vocales:\n");
    fprintf(archivo, "a: %d\n", a);
    fprintf(archivo, "e: %d\n", e);
    fprintf(archivo, "i: %d\n", i);
    fprintf(archivo, "o: %d\n", o);
    fprintf(archivo, "u: %d\n", u);

    // Escribe el texto resultante modificado.
    fprintf(archivo, "\nTexto resultante:\n%s\n", texto);

    fclose(archivo);
    printf("Resultados guardados en '%s'\n", nombreArchivo);
}

// Función principal con menú interactivo.
int main() {
    int opcion;
    char nombreArchivo[MAX_FILENAME];
    char* contenido = NULL;
    int caracteres, palabras, espacios, lineas;
    int a, e, i, o, u;

    do {
        // Menú principal
        printf("\n--- MENÚ ---\n");
        printf("1. Ingresar nombre del archivo\n");
        printf("2. Calcular estadísticas del texto\n");
        printf("3. Calcular frecuencia de vocales\n");
        printf("4. Reemplazar palabra en el texto\n");
        printf("5. Guardar resultados en un nuevo archivo\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();  // Limpia el '\n' del buffer.

        if (opcion == 1) {
            printf("Nombre del archivo (.txt): ");
            fgets(nombreArchivo, MAX_FILENAME, stdin);
            nombreArchivo[strcspn(nombreArchivo, "\n")] = 0;  // Elimina salto de línea.

            if (contenido) {
                free(contenido);  // Libera memoria anterior si existía.
                contenido = NULL;
            }

            contenido = leerArchivo(nombreArchivo);  // Carga archivo en memoria.
            if (contenido)
                printf("Archivo cargado correctamente.\n");

        } else if (opcion == 2) {
            if (!contenido) {
                printf("Primero debe cargar un archivo.\n");
            } else {
                calcularEstadisticas(contenido, &caracteres, &palabras, &espacios, &lineas);
                printf("\nEstadísticas:\n");
                printf("Caracteres: %d\n", caracteres);
                printf("Palabras: %d\n", palabras);
                printf("Espacios: %d\n", espacios);
                printf("Líneas: %d\n", lineas);
            }

        } else if (opcion == 3) {
            if (!contenido) {
                printf("Primero debe cargar un archivo.\n");
            } else {
                contarVocales(contenido, &a, &e, &i, &o, &u);
                printf("\nFrecuencia de vocales:\n");
                printf("a: %d\n", a);
                printf("e: %d\n", e);
                printf("i: %d\n", i);
                printf("o: %d\n", o);
                printf("u: %d\n", u);
            }

        } else if (opcion == 4) {
            if (!contenido) {
                printf("Primero debe cargar un archivo.\n");
            } else {
                char palabra[MAX_PALABRA], reemplazo[MAX_PALABRA];
                printf("Palabra a buscar: ");
                fgets(palabra, MAX_PALABRA, stdin);
                palabra[strcspn(palabra, "\n")] = 0;

                printf("Palabra de reemplazo: ");
                fgets(reemplazo, MAX_PALABRA, stdin);
                reemplazo[strcspn(reemplazo, "\n")] = 0;

                char* nuevoContenido = reemplazarPalabra(contenido, palabra, reemplazo);
                if (nuevoContenido) {
                    free(contenido);
                    contenido = nuevoContenido;
                    printf("Reemplazo realizado correctamente.\n");
                }
            }

        } else if (opcion == 5) {
            if (!contenido) {
                printf("Primero debe cargar un archivo.\n");
            } else {
                char salida[MAX_FILENAME];
                printf("Nombre del archivo de salida: ");
                fgets(salida, MAX_FILENAME, stdin);
                salida[strcspn(salida, "\n")] = 0;

                guardarResultados(salida, caracteres, palabras, espacios, lineas,
                                  a, e, i, o, u, contenido);
            }

        } else if (opcion != 6) {
            printf("Opción no válida.\n");
        }

    } while (opcion != 6);  // Repite hasta que el usuario elija salir.

    if (contenido) free(contenido);  // Libera memoria final.

    printf("Programa finalizado.\n");
    return 0;
}
