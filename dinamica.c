#include <stdio.h>

int main(void){
    int i; //en la pila
    int *puntero, tamano; //pila
    printf("ingrese tamano: ");
    scanf("%d",&tamano);
    printf("\n");

    puntero = (int *) malloc(tamano * sizeof(int));
    for(i=0;i<tamano;i++){
        puntero[i]=i+1;
        printf("%d\n",puntero[i]);
    }

    free(puntero);
    return 0;
}