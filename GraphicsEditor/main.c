#include <stdio.h>
#include <string.h>

#define ROWS 25
#define COLS 60
#define MAX_OBJECTS 20

/* ---- Canvas ---- */
char canvas[ROWS][COLS];

/* ---- Shape types ---- */
typedef enum { RECT, LINE, TRIANGLE, CIRCLE } ShapeType;

typedef struct {
    int id;
    ShapeType type;
    int active;
    int x, y, x2, y2;
    int width, height;
    int radius;
} Object;

Object objects[MAX_OBJECTS];
int objCount = 0;
int nextId   = 1;

/* ---- Canvas helpers ---- */
void initCanvas()
{
    int i, j;
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            canvas[i][j] = '_';
}

void displayCanvas()
{
    int i, j;
    printf("\n    ");
    for (j = 0; j < COLS; j += 5) printf("%-5d", j);
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("%2d: ", i);
        for (j = 0; j < COLS; j++) printf("%c", canvas[i][j]);
        printf("\n");
    }
}

/* ---- Raw draw functions ---- */
void _drawRect(int x, int y, int w, int h)
{
    int i, j;
    for (i = y; i < y + h && i < ROWS; i++)
        for (j = x; j < x + w && j < COLS; j++)
            if (i == y || i == y+h-1 || j == x || j == x+w-1)
                canvas[i][j] = '*';
}

void _drawLine(int x1, int y1, int x2, int y2)
{
    int i;
    if (y1 == y2)
        for (i = x1; i <= x2 && i < COLS; i++) canvas[y1][i] = '*';
    else if (x1 == x2)
        for (i = y1; i <= y2 && i < ROWS; i++) canvas[i][x1] = '*';
    else
        printf("  Note: only horizontal/vertical lines supported.\n");
}

void _drawTriangle(int x, int y, int h)
{
    int i, j;
    for (i = 0; i < h; i++)
        for (j = 0; j <= i; j++)
            if (y+i < ROWS && x+j < COLS)
                canvas[y+i][x+j] = '*';
}

void _drawCircle(int cx, int cy, int r)
{
    int i, j, dx, dy;
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++) {
            dx = j - cx; dy = i - cy;
            if (dx*dx + dy*dy <= r*r) canvas[i][j] = '*';
        }
}

/* ---- Redraw all from object store ---- */
void redrawAll()
{
    int k;
    initCanvas();
    for (k = 0; k < objCount; k++) {
        if (!objects[k].active) continue;
        switch (objects[k].type) {
            case RECT:     _drawRect(objects[k].x, objects[k].y, objects[k].width, objects[k].height); break;
            case LINE:     _drawLine(objects[k].x, objects[k].y, objects[k].x2,   objects[k].y2);     break;
            case TRIANGLE: _drawTriangle(objects[k].x, objects[k].y, objects[k].height);               break;
            case CIRCLE:   _drawCircle(objects[k].x, objects[k].y, objects[k].radius);                 break;
        }
    }
}

/* ---- List objects ---- */
void listObjects()
{
    int k, any = 0;
    printf("\n  ID  Type        Parameters\n");
    printf("  --  ----------  --------------------------------\n");
    for (k = 0; k < objCount; k++) {
        if (!objects[k].active) continue;
        any = 1;
        switch (objects[k].type) {
            case RECT:
                printf("  %2d  Rectangle   x=%d y=%d w=%d h=%d\n",
                    objects[k].id, objects[k].x, objects[k].y, objects[k].width, objects[k].height); break;
            case LINE:
                printf("  %2d  Line        (%d,%d)->(%d,%d)\n",
                    objects[k].id, objects[k].x, objects[k].y, objects[k].x2, objects[k].y2); break;
            case TRIANGLE:
                printf("  %2d  Triangle    x=%d y=%d height=%d\n",
                    objects[k].id, objects[k].x, objects[k].y, objects[k].height); break;
            case CIRCLE:
                printf("  %2d  Circle      cx=%d cy=%d r=%d\n",
                    objects[k].id, objects[k].x, objects[k].y, objects[k].radius); break;
        }
    }
    if (!any) printf("  (no objects)\n");
}

/* ---- Find object by ID ---- */
int findById(int id)
{
    int k;
    for (k = 0; k < objCount; k++)
        if (objects[k].id == id && objects[k].active) return k;
    return -1;
}

/* ---- Add functions ---- */
void addRect(int x, int y, int w, int h)
{
    Object *o;
    if (objCount >= MAX_OBJECTS) { printf("Max objects reached!\n"); return; }
    o = &objects[objCount++];
    o->id = nextId++; o->type = RECT; o->active = 1;
    o->x = x; o->y = y; o->width = w; o->height = h;
    _drawRect(x, y, w, h);
    printf("  Rectangle added (ID %d)\n", o->id);
}

void addLine(int x1, int y1, int x2, int y2)
{
    Object *o;
    if (objCount >= MAX_OBJECTS) { printf("Max objects reached!\n"); return; }
    o = &objects[objCount++];
    o->id = nextId++; o->type = LINE; o->active = 1;
    o->x = x1; o->y = y1; o->x2 = x2; o->y2 = y2;
    _drawLine(x1, y1, x2, y2);
    printf("  Line added (ID %d)\n", o->id);
}

void addTriangle(int x, int y, int h)
{
    Object *o;
    if (objCount >= MAX_OBJECTS) { printf("Max objects reached!\n"); return; }
    o = &objects[objCount++];
    o->id = nextId++; o->type = TRIANGLE; o->active = 1;
    o->x = x; o->y = y; o->height = h;
    _drawTriangle(x, y, h);
    printf("  Triangle added (ID %d)\n", o->id);
}

void addCircle(int cx, int cy, int r)
{
    Object *o;
    if (objCount >= MAX_OBJECTS) { printf("Max objects reached!\n"); return; }
    o = &objects[objCount++];
    o->id = nextId++; o->type = CIRCLE; o->active = 1;
    o->x = cx; o->y = cy; o->radius = r;
    _drawCircle(cx, cy, r);
    printf("  Circle added (ID %d)\n", o->id);
}

/* ---- Delete object ---- */
void deleteObject(int id)
{
    int k = findById(id);
    if (k == -1) { printf("  Object ID %d not found.\n", id); return; }
    objects[k].active = 0;
    redrawAll();
    printf("  Object ID %d deleted.\n", id);
}

/* ---- Modify object ---- */
void modifyObject(int id)
{
    int k = findById(id);
    Object *o;
    if (k == -1) { printf("  Object ID %d not found.\n", id); return; }
    o = &objects[k];
    printf("  Modifying ");
    switch (o->type) {
        case RECT:
            printf("Rectangle (current: x=%d y=%d w=%d h=%d)\n", o->x, o->y, o->width, o->height);
            printf("  New X: ");      scanf("%d", &o->x);
            printf("  New Y: ");      scanf("%d", &o->y);
            printf("  New Width: ");  scanf("%d", &o->width);
            printf("  New Height: "); scanf("%d", &o->height);
            break;
        case LINE:
            printf("Line (current: (%d,%d)->(%d,%d))\n", o->x, o->y, o->x2, o->y2);
            printf("  New x1: "); scanf("%d", &o->x);
            printf("  New y1: "); scanf("%d", &o->y);
            printf("  New x2: "); scanf("%d", &o->x2);
            printf("  New y2: "); scanf("%d", &o->y2);
            break;
        case TRIANGLE:
            printf("Triangle (current: x=%d y=%d h=%d)\n", o->x, o->y, o->height);
            printf("  New X: ");      scanf("%d", &o->x);
            printf("  New Y: ");      scanf("%d", &o->y);
            printf("  New Height: "); scanf("%d", &o->height);
            break;
        case CIRCLE:
            printf("Circle (current: cx=%d cy=%d r=%d)\n", o->x, o->y, o->radius);
            printf("  New Center X: "); scanf("%d", &o->x);
            printf("  New Center Y: "); scanf("%d", &o->y);
            printf("  New Radius: ");   scanf("%d", &o->radius);
            break;
    }
    redrawAll();
    printf("  Object ID %d updated.\n", id);
}

/* ---- Main ---- */
int main()
{
    int choice;
    initCanvas();

    while (1) {
        printf("\n+------------------------------+\n");
        printf("|     2D Graphics Editor       |\n");
        printf("+------------------------------+\n");
        printf("|  ADD                         |\n");
        printf("|   1. Draw Rectangle          |\n");
        printf("|   2. Draw Line               |\n");
        printf("|   3. Draw Triangle           |\n");
        printf("|   4. Draw Circle             |\n");
        printf("+------------------------------+\n");
        printf("|  MANAGE                      |\n");
        printf("|   5. Display Canvas          |\n");
        printf("|   6. List Objects            |\n");
        printf("|   7. Modify Object           |\n");
        printf("|   8. Delete Object           |\n");
        printf("|   9. Clear All               |\n");
        printf("+------------------------------+\n");
        printf("|  10. Exit                    |\n");
        printf("+------------------------------+\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int x, y, w, h;
                printf("Enter X Y Width Height: ");
                scanf("%d %d %d %d", &x, &y, &w, &h);
                addRect(x, y, w, h);
                break;
            }
            case 2: {
                int x1, y1, x2, y2;
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                addLine(x1, y1, x2, y2);
                break;
            }
            case 3: {
                int x, y, h;
                printf("Enter X Y Height: ");
                scanf("%d %d %d", &x, &y, &h);
                addTriangle(x, y, h);
                break;
            }
            case 4: {
                int cx, cy, r;
                printf("Enter CenterX CenterY Radius: ");
                scanf("%d %d %d", &cx, &cy, &r);
                addCircle(cx, cy, r);
                break;
            }
            case 5:
                displayCanvas();
                break;
            case 6:
                listObjects();
                break;
            case 7: {
                int id;
                listObjects();
                printf("\nEnter Object ID to modify: ");
                scanf("%d", &id);
                modifyObject(id);
                break;
            }
            case 8: {
                int id;
                listObjects();
                printf("\nEnter Object ID to delete: ");
                scanf("%d", &id);
                deleteObject(id);
                break;
            }
            case 9:
                initCanvas();
                objCount = 0;
                nextId   = 1;
                printf("  Canvas cleared.\n");
                break;
            case 10:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}