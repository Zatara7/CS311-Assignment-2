#ifndef A2SUPPORT_INCLUDED
#define A2SUPPORT_INCLUDED

#define NUMBER_ENTRIES 15

////////////////////////////////////////////////////////////////////////////////
//
//  File          : a2support.h
//  Description   : This is the header file for the functions for assignment
//                  2 of the CMPSC311 course.  Students are required to define 
//                  the following functions and implement them in another
//                  file, a2support.c.
//
//  Author        : Patrick McDaniel
//  Created       : Mon Sep  9 05:11:24 PDT 2013 
//  Editor	  : Hayder Sharhan
//  Last Edit	  : Fri Sep 20

////////////////////////////////////////////////////////////////////////////////
//
// Function     : myRound
// Description  : This function will round an integer value at 0.5 and return
// an integer.
//
// Inputs       : float value
// Outputs      : rounded integer

////////////////////////////////////////////////////////////////////////////////
//
// Function     : printFArray
// Description  : This function will print all the elements of a float array.
//
// Inputs       : float[] array
// Outputs      : none

////////////////////////////////////////////////////////////////////////////////
//
// Function     : printIArray
// Description  : This function will print all the elements of an int array.
//
// Inputs       : int[] array
// Outputs      : nonw

////////////////////////////////////////////////////////////////////////////////
//
// Function     : incrementFloat
// Description  : This function will increment a pointer by the increment value
// passed to the function.
//
// Inputs       : float increment, float* value
// Outputs      : none
 
////////////////////////////////////////////////////////////////////////////////
//
// Function     : incrementInt
// Description  : This function will increment a pointer by the increment value
// passed to the function.
//
// Inputs       : int increment, int* value
// Outputs      : none

////////////////////////////////////////////////////////////////////////////////
//
// Function     : largestFloat
// Description  : This function will return the largest element in a float
// array.
//
// Inputs       : float[] array, int arraySize
// Outputs      : float largestElement

////////////////////////////////////////////////////////////////////////////////
//
// Function     : largestInt
// Description  : This function will return the largest element in an int
// array.
//
// Inputs       : int[] array, int arraySize
// Outputs      : int largestElement

////////////////////////////////////////////////////////////////////////////////
//
// Function     : bsortFloat
// Description  : This function will sort all the elements in a float array.
//
// Inputs       : float[] array
// Outputs      : none

////////////////////////////////////////////////////////////////////////////////
//
// Function     : bsortInt
// Description  : This function will sort all the elements in an int array.
//
// Inputs       : int[] array
// Outputs      : none

////////////////////////////////////////////////////////////////////////////////
//
// Function     : printCharline
// Description  : This function will print a line of the specified character
// with a count of the number inserted. If the count is larger than 80, the
// count will be defaulted to 80.
//
// Inputs       : char symbol, int count
// Outputs      : none

////////////////////////////////////////////////////////////////////////////////
//
// Function     : doHistogram
// Description  : This function will print a histogram of values displaying
// a labeled list of the count of each pool of values in the arrays.
//
// Inputs       : float[] array, int[] array, int sizeFloat, int sizeInt
// Outputs      : none

////////////////////////////////////////////////////////////////////////////////
//
// Function     : myLogF
// Description  : This function should replace the printf function. It accepts
// the same arguments as printf. It will then print what's passed to it to 
// stdout and stderr. Use the function myLogFl to print new lines. See below.
//
// Inputs       : const char *, ...
// Outputs      : 1 if successful , -1 otherwise

////////////////////////////////////////////////////////////////////////////////
//
// Function     : myLogFl
// Description  : This function should be used to start new lines. What it does
// is that it prints the date and time to stderr on each new line. You should only
// pass "\n" to this function.
//
// Inputs       : const char *, ...
// Outputs      : 1 if successful, -1 otherwise


int myRound(float);
void printFArray(float[], int);
void printIArray(int[], int);
void incrementFloat(float, float*);
void incrementInt(int, int*);
float largestFloat(float[], int);
int largestInt(int[], int);
void bsortFloat(float[], int);
void bsortInt(int[], int);
void printCharline(char, int);
void doHistogram(float[], int[], int, int);
int myLogF(const char*, ...);
int myLogFl(const char*, ...);

#endif
