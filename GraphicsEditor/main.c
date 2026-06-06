#include <stdio.h>

#define ROWS 25
#define COLS 50

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
    int choice;

    initCanvas();

    while(1)
    {
        printf("\n");
        printf("===== 2D Graphics Editor =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Display Canvas\n");
        printf("3. Clear Canvas\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                drawRectangle(2, 2, 15, 6);
                printf("Rectangle Drawn!\n");
                break;

            case 2:
                displayCanvas();
                break;

            case 3:
                initCanvas();
                printf("Canvas Cleared!\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}