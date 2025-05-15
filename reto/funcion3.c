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

    if (texto[0] != '\0' && texto[strlen(texto) - 1] != '\n')
        est.lineas++;

    return est;
}