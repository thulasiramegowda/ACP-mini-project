# 2D Graphics Editor Using Character Array

## Overview

This project is a simple 2D Graphics Editor developed in C. It uses a two-dimensional character array to create and display graphical objects in the console using the `*` and `_` characters.

## Features

* Draw Rectangle
* Draw Line (Horizontal and Vertical)
* Draw Triangle
* Draw Circle
* Display Canvas
* Clear Canvas
* Delete Area from Canvas
* Menu-Driven Interface

## Technologies Used

* Programming Language: C
* Compiler: GCC
* Data Structure: 2D Character Array

## Working

The program maintains a canvas using a 2D character array. Users can choose different options from the menu to draw shapes on the canvas. The canvas can be displayed, cleared, and specific areas can be deleted.

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
+---------------------------------------------+
| Rectangle | Line | Triangle | Circle | etc. |
+---------------------------------------------+
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

Rectangle

```text
**********
*        *
*        *
**********
```

Triangle

```text
*
**
***
****
*****
```

Line

```text
**************
```

Circle (Approximation)

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
8. Exit

## Project Structure

GraphicsEditor/

* main.c
* README.md

## How to Compile and Run

Compile:

gcc main.c -o editor

Run:

./editor

For Windows PowerShell:

.\editor.exe

## Author

Thulasi Rame Gowda
