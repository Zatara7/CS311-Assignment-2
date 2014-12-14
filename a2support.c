////////////////////////////////////////////////////////////////////////////////
//
//  File          : a2support.c
//  Description   : This file will implement the functions in a2support.h used
//  		    for assignment2 in cmpsc311 class.
//
//  Creator	  : Hayder Sharhan
//  Created	  : Sun Sep 15
//  Last Edited	  : Fri Sep 20

#include <a2support.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>

int myRound(float value) {
	int temp = value; //floors the value
	int newValue;
	// Check if the different between the float and the floored value are larger
	// or less than 0.5
	if((value - temp) < 0.5) {
		newValue = temp;
	} else {
		newValue = temp+1;
	}

	return newValue;
}

void printFArray(float array[], int size) {
	int i;
	for(i=0; i < size; i++) {
		myLogF("%8.2f", array[i]); // 8.2 -> 8 spaces and 2 decimal points
	}
	myLogFl("\n");
}

void printIArray(int array[], int size) {
	int i;
	for(i=0; i < size; i++) {
		myLogF("%8i", array[i]);
	}
	myLogFl("\n");
}

void incrementFloat(float inc, float *value) {
	*value += inc;
}

void incrementInt(int inc, int *value) {
	*value += inc;
}

float largestFloat(float array[], int size) {
	int i;
	float newValue = array[0];
	for( i = 0; i < size; i++) {
		if (newValue < array[i]) {
			newValue = array[i];
		}
	}

	return newValue;
}

int largestInt(int array[], int size) {
	int i;
	int newValue = array[0];
	for( i = 0; i < size; i++) {
		if (newValue < array[i]) {
			newValue = array[i];
		}
	}

	return newValue;
}

void printCharline(char symbol, int count) {
	int i;
	// Check if count is larger than 80, default to 80
	if (count > 80) {
		count = 80;
	}
	for (i=0; i<count; i++) {
		myLogF("%c", symbol);
	}
	myLogFl("\n");
}

void bsortFloat(float array[], int size) {
	int i;
	int j;
	
	// Progress down the array
	for( i = size; i > 0; i--) {
		// Progress up untill the current count
		for( j = 0; j < (i-1); j++) {
			// Check current elements is larger than one next over, swap
			if (array[j] > array[j+1]) {
				float temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void bsortInt(int array[], int size) {
	int i;
	int j;

	//Progress down the array
	for( i = size; i>0; i--) {
		// Progress up until the current count
		for( j=0; j<(i-1); j++) {
			// Check current elements is larger than one next over, swap
			if (array[j] > array[j+1]) {
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void doHistogram(float myFloats[], int myInts[], int floatSize, int intSize) {
	int count[10] = { [0 ... 9] = 0}; // To keep track of each pool
	int i;
	
	
	// Increment count[] for the float array values
	for (i = 0; i < floatSize; i++) {
		if (myFloats[i] < 50) {
			count[0]++;
		} else if (myFloats[i] >= 50 && myFloats[i] < 100) {
			count[1]++;
                } else if (myFloats[i] >= 100 && myFloats[i] < 150) {
		        count[2]++;
	        } else if (myFloats[i] >= 150 && myFloats[i] < 200) {
			count[3]++;
                } else if (myFloats[i] >= 200 && myFloats[i] < 250) {
		        count[4]++;
                } else if (myFloats[i] >= 250 && myFloats[i] < 300) {
			count[5]++;
                } else if (myFloats[i] >= 300 && myFloats[i] < 350) {
			count[6]++;
		} else if (myFloats[i] >= 350 && myFloats[i] < 400) {
			count[7]++;
		} else if (myFloats[i] >= 400 && myFloats[i] < 450) {
			count[8]++;
		} else {
			count[9]++;
		}

	}

	// Increment count[] for int elements
	for (i = 0; i < intSize; i++) {
		//find ints
		if (myInts[i] < 50) { // 0 - 50
			count[0]++;
		} else if (myInts[i] >= 50 && myInts[i] < 100) { // 50 - 100
			count[1]++;
                } else if (myInts[i] >= 100 && myInts[i] < 150) { // 100 - 150
		        count[2]++;
	        } else if (myInts[i] >= 150 && myInts[i] < 200) { // 150 - 200
			count[3]++;
                } else if (myInts[i] >= 200 && myInts[i] < 250) { // 200 - 250
		        count[4]++;
                } else if (myInts[i] >= 250 && myInts[i] < 300) { // 250 - 300
			count[5]++;
                } else if (myInts[i] >= 300 && myInts[i] < 350) { // 300 - 350
			count[6]++;
		} else if (myInts[i] >= 350 && myInts[i] < 400) { // 350 - 400
			count[7]++;
		} else if (myInts[i] >= 400 && myInts[i] < 450) { // 400 - 450
			count[8]++;
		} else {
			count[9]++;
		}
	}
	
	// Find the largest pool in count[]
	int largest = largestInt(count, 10);
	
	// To make it look nice
	largest++;

	while (largest != 0) {
		// Print out current largest elements in the loop
		myLogF("%2i", largest);

		for ( i = 0; i < 10; i++) {
			// Print out a star if current count is equal to or larger than
			// current largest element.
			if (count[i] >= largest) {
				myLogF("%6c", '*');
			} else { 			// Or print out a blank space
				myLogF("%6c", ' ');
			}
		}
		myLogFl("\n");
		largest--; // Decrement largest current element
	}
	
	//footer
	myLogF("%2c", ' ');
	myLogF("%6s", "<50");
	myLogF("%6s", "050+");
	myLogF("%6s", "100+");
	myLogF("%6s", "150+");
	myLogF("%6s", "200+");
	myLogF("%6s", "250+");
	myLogF("%6s", "300+");
	myLogF("%6s", "350+");
	myLogF("%6s", "400+");
	myLogF("%6s", ">=450");
	myLogF("\n"); // Did not use myLogFl so date and time won't print on a blank
		      // Line.
}

int myLogF(const char *format, ...) {
	int n = 1;	// Used to return 1 if successful, -1 otherwise
	va_list ap, bp; // Used to grab the undefined argument passed

	va_start(ap, format);
	va_copy(bp, ap); // Copy the current argument so it could be used for stderr too
	
	// Print to stdout and stderr and check if any return -1 (unsuccessful)
	if (vfprintf(stdout, format, ap) == -1 ||
	vfprintf(stderr, format, bp) == -1) {
		n = -1;
	}
	va_end(ap);

	return n;
}

int myLogFl(const char *format, ...) {
	int n = 1; 	// Used to return 1 if successful, -1 otherwise
	va_list ap, bp; // Used to grab the undefined argument passed
	time_t current = time(NULL); // Current time

	va_start(ap, format);
	va_copy(bp, ap); // Copy the current argument so it could be used for stderr too
	
	// Print to stdout and stderr and check if any return -1
	if (vfprintf(stdout, format, ap) == -1 ||
	vfprintf(stderr, format, bp) == -1) {
		n = -1;
	}
	va_end(ap);	

	// To remove the /n in localtime, assign 24 characters to it since it has
	// 26 characters. The last two will be truncated.
	
	char timer[24];
	char timer2[24];
	strcpy(timer, asctime(localtime(&current)));
	
	int i;
	for (i = 0; i < 24; i++) {
		timer2[i] = timer[i];
	}
	
	// Print the time and date to stderr and check if that returns -1
	if (fprintf(stderr, "%24s ", timer2) == -1) {
		n = -1;
	}
	
	return n;
}

