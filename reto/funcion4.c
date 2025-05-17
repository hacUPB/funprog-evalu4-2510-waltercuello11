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
