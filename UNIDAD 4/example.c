#include <stdio.h>
#include <stdlib.h>

int main(void){
    /*
    preguntar al usuario cuantas letras tiene su nombre y apellido 
    reservendo memoria para almacenar eses datos (malloc)
    le pedimos al usuario que ingrese sus nombre y apellido
    y lo imprimimos en pantalla con un saludo adicional
    */

    nt main(void) {
        int letras_nombre, letras_apellido;
        char *nombre, *apellido;
        printf("¿Cuántas letras tiene su nombre? ");
        scanf("%d", &letras_nombre);
    
        printf("¿Cuántas letras tiene su apellido? ");
        scanf("%d", &letras_apellido);
    
        // Reservamos memoria
        nombre = (char *)malloc((letras_nombre + 1) * sizeof(char)); // +1 para el '\0'
        apellido = (char *)malloc((letras_apellido + 1) * sizeof(char));
    
        if (nombre == NULL || apellido == NULL) {
            printf("Error al asignar memoria.\n");
            return 1;
        }
    
    // Pedimos al usuario que ingrese su nombre y apellido
    printf("Ingrese su nombre: ");
    scanf("%s", nombre);

    printf("Ingrese su apellido: ");
    scanf("%s", apellido);

    // Mostramos el saludo
    printf("Hola %s %s, ¡bienvenido al programa!\n", nombre, apellido);

    // Liberamos memoria
    free(nombre);
    free(apellido);

    return 0;
}

