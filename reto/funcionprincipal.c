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
