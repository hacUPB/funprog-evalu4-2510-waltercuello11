
int main(void)
{
    int temp[24];  /* Con esto ya tenemos declaradas las 24 variables */
    float media = 0;
    int hora, mayor = 0;

    /* Ahora tenemos que dar el valor de cada una */
    for (hora = 0; hora < 24; hora++)
    {
        temp[hora] = (rand() % ((35 - 14) + 1)) + 14;
        media += temp[hora];
        printf("%d ----> %d\n", hora, temp[hora]);
    }

    printf("\n\n");
    media = media / 24;
    mayor = temp[0];
    for (int i = 1; i < 24; i++)
    {
        if (temp[i] > mayor)
            mayor = temp[i];
    }
}

printf("\nla temperatura media es %f\n",media);
printf("mayor =%d\n", mayor);
return 0;

