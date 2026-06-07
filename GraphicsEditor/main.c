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

void drawLine(int x1, int y1, int x2, int y2)
{
    int i;

    if(y1 == y2)   // Horizontal line
    {
        for(i = x1; i <= x2; i++)
        {
            canvas[y1][i] = '*';
        }
    }
    else if(x1 == x2)   // Vertical line
    {
        for(i = y1; i <= y2; i++)
        {
            canvas[i][x1] = '*';
        }
    }
    else
    {
        printf("Only horizontal and vertical lines supported!\n");
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
        printf("2. Draw Line\n");
        printf("3. Display Canvas\n");
        printf("4. Clear Canvas\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
           
            case 1:
{
    int x, y, width, height;

    printf("Enter X coordinate: ");
    scanf("%d", &x);

    printf("Enter Y coordinate: ");
    scanf("%d", &y);

    printf("Enter Width: ");
    scanf("%d", &width);

    printf("Enter Height: ");
    scanf("%d", &height);

    drawRectangle(x, y, width, height);

    printf("Rectangle Drawn!\n");
    break;
}   

case 2:
{
    int x1, y1, x2, y2;

    printf("Enter x1: ");
    scanf("%d", &x1);

    printf("Enter y1: ");
    scanf("%d", &y1);

    printf("Enter x2: ");
    scanf("%d", &x2);

    printf("Enter y2: ");
    scanf("%d", &y2);

    drawLine(x1, y1, x2, y2);

    printf("Line Drawn!\n");
    break;
}


            case 3:
                displayCanvas();
                break;

            case 4:
                initCanvas();
                printf("Canvas Cleared!\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}