////////////////////////////////////////////////////////////////////////////////
//
//  File          : cmpsc311-f13-assign2.c
//  Description   : This is the main code file for the CMPSC311 assignment 2.  
//                  see class assignment for details on what needs to be added.
//
//  Author        : Patrick McDaniel
//  Created       : Mon Sep  9 05:11:24 PDT 2013
//  Editor	  : Hayder Sharhan
//  Last Edited	  : Fri Sep 20

#include <stdio.h>
#include <a2support.h>

////////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : This is the main function for the cmpsc311-f13-assign2 program.
//
// Inputs       : none
// Outputs      : 0 if successful, -1 otherwise

int main( void ) {

  // Declare your variables here
  float myFloats[NUMBER_ENTRIES];
  int myInts[NUMBER_ENTRIES];
  int i;

  // Read float values
  for ( i=0; i<NUMBER_ENTRIES; i++ ) {
    scanf( "%f", &myFloats[i] );
  }

  // Compute the integer array
  for ( i=0; i<NUMBER_ENTRIES; i++ ) {
    myInts[i] = myRound(myFloats[i]);
  }

  // Show the list of unsorted values
  myLogFl(""); // To print out the time for the first line
  printCharline( '*', 69 );
  myLogF( "Received and computed values" );
  myLogFl("\n");
  printFArray(myFloats, NUMBER_ENTRIES);
  printIArray(myInts, NUMBER_ENTRIES);

  
  // Increment the odd elements of floats by 10.2 and the
  // even elements of integers by 112 (zeroth item is even
  for(i=0; i<NUMBER_ENTRIES; i++) {
	if (!(i%2 == 0)) {
		incrementFloat(10.2, &myFloats[i]);
	}
  }

  for(i=0; i<NUMBER_ENTRIES; i++) {
	if (i%2 == 0) {
		incrementInt(112, &myInts[i]);
	}
  }
  
  
  // Now print out the largest element in each array
  myLogF( "The largest element of the float array is %6.2f", largestFloat(myFloats, NUMBER_ENTRIES) );
  myLogFl("\n");
  myLogF( "The largest element of the int array is %6d", largestInt(myInts, NUMBER_ENTRIES) );
  myLogFl("\n");
  // Show the list of unsorted values
  printCharline( '*', 69 );
  myLogF( "Altered values" );
  myLogFl("\n");
  printFArray(myFloats, NUMBER_ENTRIES);
  printIArray(myInts, NUMBER_ENTRIES);
	
  // Now sort the arrays
  bsortFloat(myFloats, NUMBER_ENTRIES);
  bsortInt(myInts, NUMBER_ENTRIES);

  // Now call the print functions on the float and integer arrays
  printCharline( '*', 69 );
  myLogF( "Sorted values" );
  myLogFl("\n");
  printFArray(myFloats, NUMBER_ENTRIES);
  
  printIArray(myInts, NUMBER_ENTRIES);

  // Create a historgram
  printCharline( '*', 69 );
  myLogF( "Historgram of values" );
  myLogFl("\n");
  doHistogram(myFloats, myInts, NUMBER_ENTRIES, NUMBER_ENTRIES);

  // Return successfully
  return( 0 );
}

