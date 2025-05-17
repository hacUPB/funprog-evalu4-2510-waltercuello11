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