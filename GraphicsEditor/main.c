#include <stdio.h>

#define ROWS 10
#define COLS 20

char canvas[ROWS][COLS];

void initCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            canvas[i][j]='_';
        }
    }
}

void displayCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c",canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int x, int y, int width, int height)
{
    int i, j;

    for(i = y; i < y + height; i++)
    {
        for(j = x; j < x + width; j++)
        {
            if(i == y || i == y + height - 1 ||
               j == x || j == x + width - 1)
            {
                canvas[i][j] = '*';
            }
        }
    }
}

int main()
{
    initCanvas();

    drawRectangle(2, 2, 10, 5);

    displayCanvas();

    return 0;
}