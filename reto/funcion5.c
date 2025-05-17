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