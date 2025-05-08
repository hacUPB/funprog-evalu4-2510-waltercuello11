#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *curso;
    char buffer[100];
    int nrc;

    // 1. Reservar memoria inicial
    curso = (char *)malloc(100 * sizeof(char));
    if (curso == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    // 2. Solicitar y guardar el nombre del curso
    printf("Ingrese el nombre del curso: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Eliminar salto de línea

    // 3. Redimensionar memoria al tamaño exacto
    curso = (char *)realloc(curso, (strlen(buffer) + 1) * sizeof(char));
    if (curso == NULL) {
        printf("Error al redimensionar memoria.\n");
        return 1;
    }
    strcpy(curso, buffer);

    // 4. Solicitar el código NRC
    printf("Ingrese el código NRC del curso: ");
    scanf("%d", &nrc);

    // 5. Mostrar los datos guardados
    printf("\nCurso: %s\n", curso);
    printf("NRC: %d\n", nrc);

    // Liberar memoria
    free(curso);
    return 0;
}