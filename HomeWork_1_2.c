#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

/* Function for getting int or throwing error*/
void getInt(int *n)
{
    int result = scanf("%d", n);

    if (result < 1)
    {
        printf("The value was entered incorrectly");
        exit(1);
    }
}

int main(void)
{
    char *locale = setlocale(LC_ALL, "");
    int i, n, j, temp;

    printf("Enter the number of elements of the set: ");
    getInt(&n);

    int dec[n], bin[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter element number %d: ", i + 1);
        getInt(&temp);

        dec[i] = temp;

        /* writing bin number */
        bin[i] = 0;

        for (j = 0; temp > 0; j++)
        {
            bin[i] += (temp % 2) * pow(10.0, j);
            temp /= 2;
        }
    }

    for (i = 0; i < n; i++)
        printf("%d in decimal - %d in binary\n", dec[i], bin[i]);

    getchar();
    getchar();
    return 0;
}