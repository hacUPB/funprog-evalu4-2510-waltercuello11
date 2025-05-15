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