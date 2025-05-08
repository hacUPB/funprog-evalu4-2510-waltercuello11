#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char Nombre[30];
    FILE *p_archivo;

    p_archivo = fopen("Texto1.txt", "w");
    fprintf(stdout, "Ingrese su nombre: \n"); // Mostrar mensaje en pantalla
    fgets(Nombre, sizeof(Nombre), stdin);    // Captura el nombre con espacios

    // Reemplazar el salto de línea '\n' al final con '\0'
    Nombre[strlen(Nombre) - 1] = '\0';

    if (p_archivo != NULL)
    {
        printf("Se crea el archivo.\n");

        // Escribir en el archivo
        fprintf(p_archivo, "Este texto de prueba para el archivo Texto1.txt\n");
        fprintf(p_archivo, "Hola %s, bienvenido al curso.\n", Nombre);

        fclose(p_archivo); // Cierra el archivo
    }
    else
    {
        printf("No se pudo crear el archivo.\n");
    }

    return 0;
}