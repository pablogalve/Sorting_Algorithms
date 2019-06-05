#pragma once

// INSTRUCTIONS:
// - Press 'b' to call the bubblesort function
// - Press 'm' to call the mergesort function
// - Press 'q' to call the quicksort function
// - Press space to randomize the tile set
// - Press <esc> to exit

// Change these numbers to resize the tile grid dimensions
#define GRID_WIDTH 100
#define GRID_HEIGHT 100

void swap(uint32 *array, uint32 *array2) {
	uint32 *aux;

	aux = array;
	array = array2;
	array2 = array;

}
// Bubblesort functions ////////////////////////////////////////////////

void bubblesort(uint32 * array, int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++)

		// Last i elements are already in place    
		for (j = 0; j < size - i - 1; j++)
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
}


// Mergesort functions /////////////////////////////////////////////////

void merge(uint32 *array, int begin, int mid, int end)
{
	// Create the two subarrays
	// TODO

	// Copy array parts into the subarrays
	// TODO

	// Initialize indices for tmp1, tmp2, and array, respectively
	int i = 0;
	int j = 0;
	int k = begin;

	// Merge tmp1 and tmp2 into array
	// TODO

	// Delete tmp arrays
	// TODO
	
}

void mergesort(uint32 *array, int begin, int end)
{
	


}



// Quicksort functions /////////////////////////////////////////////////

int partition(uint32 *array, int begin, int end)
{
	// Take the last value (for example) as the pivot
	// Could be any other value in the array
	uint32 pivot = array[end];

	// Initialize the pivot index at the beginning
	int pivotIndex = begin-1;
	for (int j = begin; j <= end - 1; j++) {
		if (array[j] <= pivot) {
			pivotIndex++;
			swap(&array[pivotIndex], &array[j]);
		}
	}
	swap(&array[pivotIndex+1], &array[end]);
	// Traversing the array:
	// Each value we find that is less than the pivot we push
	// it to the left (swap) and increase the pivot index
	// TODO

	// Put the pivot in its position
	// TODO

	return pivotIndex+1;
}


void quicksort(uint32 *array, int begin, int end)
{

	// TODO: Insert your code here
	if (begin < end) {
		int pi = partition(array, begin, end);

		quicksort(array, begin, pi - 1);
		quicksort(array, pi + 1, end);
	}
}
