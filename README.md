# 2D Graphics Editor Using Character Array

## Overview

This project is a simple 2D Graphics Editor developed in C. The program uses a two-dimensional character array to create, display, modify, and manage graphical objects in the console using `*` and `_` characters.

## Features

* Draw Rectangle
* Draw Line (Horizontal and Vertical)
* Draw Triangle
* Draw Circle
* Display Canvas
* Clear Canvas
* Delete Area from Canvas
* Modify Objects
* Menu-Driven Interface

## Technologies Used

* Programming Language: C
* Compiler: GCC
* Data Structure: 2D Character Array

## Working

The application maintains a canvas using a 2D character array. Users can select different options from a menu to draw shapes, modify existing shapes, delete areas, clear the canvas, and display the current picture.

## System Flow Diagram

```text
+------------------+
|   Start Program  |
+------------------+
          |
          v
+------------------+
| Initialize Canvas|
+------------------+
          |
          v
+------------------+
| Display Menu     |
+------------------+
          |
          v
+------------------------------+
| User Selects an Option       |
+------------------------------+
          |
          v
+---------------------------------------------------+
| Rectangle | Line | Triangle | Circle | Modify etc |
+---------------------------------------------------+
          |
          v
+------------------+
| Update Canvas    |
+------------------+
          |
          v
+------------------+
| Display Canvas   |
+------------------+
          |
          v
+------------------+
| Exit Program ?   |
+------------------+
      |      |
     No     Yes
      |      |
      v      v
   Menu    End
```

## Canvas Representation

Example Canvas:

```text
__________________________________________________
__________________________________________________
_____**********___________________________________
_____*________*___________________________________
_____*________*___________________________________
_____**********___________________________________
__________________________________________________
__________________________________________________
```

## Shape Examples

### Rectangle

```text
**********
*        *
*        *
**********
```

### Triangle

```text
*
**
***
****
*****
```

### Line

```text
**************
```

### Circle (Approximation)

```text
   ***
 *     *
 *     *
   ***
```

## Menu Options

1. Draw Rectangle
2. Draw Line
3. Draw Triangle
4. Draw Circle
5. Display Canvas
6. Clear Canvas
7. Delete Area
8. Modify Object
9. Exit

## Project Structure

```text
GraphicsEditor/
│
├── main.c
└── README.md
```

## How to Compile and Run

### Compile

```bash
gcc main.c -o editor
```

### Run (Linux)

```bash
./editor
```

### Run (Windows PowerShell)

```powershell
.\editor.exe
```

## Learning Outcomes

* Understanding of 2D arrays in C
* Function-based program design
* Menu-driven applications
* Basic graphics representation using characters
* Object creation, deletion, and modification

## Author

Thulasi Rame Gowda
