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