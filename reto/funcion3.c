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