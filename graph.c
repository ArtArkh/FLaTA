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

    // generating file for grpahviz
    FILE *graph = fopen("graph.gv", "w");
    fprintf(graph, "graph G {");
    
    char vertex = 'A';
    short int f;
    char temp;

    for(int j = 0; j < width; ++j) {
        f = 0;
        for(int i = 0; i < height && f < 2; ++i) {
            if(A[i][j] == 1) {
                if(f == 0)
                    temp = (char)(vertex + i);
                else if( f == 1) 
                    fprintf(graph, "%c--%c;", temp, (char)(vertex + i));
                ++f;
            }
        }
    }
    fprintf(graph, "}");
    fclose(graph);

    // start grephviz
    system("dot -Tpng graph.gv -o file.png && sxiv file.png");

    return 0;
}