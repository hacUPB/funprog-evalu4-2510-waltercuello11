#include <stdio.h>

int main() {
    int n, i;
    float resistencia, suma = 0.0, Req;

    printf("Ingrese el número de resistencias en paralelo: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Ingrese el valor de la resistencia R%d (ohmios): ", i);
        scanf("%f", &resistencia);

        if (resistencia != 0)
            suma += 1.0 / resistencia;
        else {
            printf("Error: La resistencia no puede ser cero.\n");
            return 1;
        }
    }

    if (suma != 0)
        Req = 1.0 / suma;
    else {
        printf("Error: División por cero.\n");
        return 1;
    }

    printf("La resistencia equivalente es: %.2f ohmios\n", Req);
    return 0;
}