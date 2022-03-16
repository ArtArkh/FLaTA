#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 20
#define MAX_HEIGHT 20

int main()
{
    // reading matrix file and generating array with data from this file
    FILE *matrixFile = fopen("graph.txt", "r");

    if (matrixFile == NULL)
    {
        printf("Error! File 'graph.txt' not found!\n");
        getchar();
        return 1;
    }

    char curSym;

    int width = 0;
    int height = 0;
    short int A[MAX_HEIGHT][MAX_WIDTH];

    while ((curSym = getc(matrixFile)) != EOF)
    {
        if (curSym == '\n')
        {
            width = 0;
            ++height;
            continue;
        }
        if (curSym != ' ')
            A[height][width++] = (int)(curSym - '0');
    } ++height;
    fclose(matrixFile);

    // count number of unic edges    
    char vertex = 'A';
    short int f;
    char edge[2];
    char prevEdge[2] = {'0', '0'};
    int counter = 0;

    for(int j = 0; j < width; ++j) {
        f = 0;
        for(int i = 0; i < height && f < 2; ++i) {
            if(A[i][j] == 1) {
                if(f == 0)
                    edge[0] = (char)(vertex + i);
                else if( f == 1) {
                    
                    edge[1] = (char)(vertex + i);

                    if(edge[0] != prevEdge[0] || edge[1] != prevEdge[1])
                        ++counter;
                    
                    prevEdge[0] = edge[0];
                    prevEdge[1] = edge[1];
                }
                ++f;
            }
        }
    }

    // check graph and out result
    if(counter > (height-1)*(height-2)/2)
        printf("Граф связаный! Ребер: %d, Вершин: %d \n", counter, height);
    else
        printf("Граф несвязаный! Ребер: %d, Вершин: %d \n", counter, height);

    return 0;
}