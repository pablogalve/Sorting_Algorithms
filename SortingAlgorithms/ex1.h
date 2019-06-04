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


// Bubblesort functions ////////////////////////////////////////////////

void bubblesort(uint32 * array, int size)
{

	// TODO: Insert your code here

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
	
	const int n1 = mid - begin + 1;
	int n2 = end - mid;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = array[begin + i];
	for (j = 0; j < n2; j++)
		R[j] = array[mid + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}
}

void mergesort(uint32 *array, int begin, int end)
{
	if (begin < end)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = begin + (end - begin) / 2;

		// Sort first and second halves 
		mergesort(array, begin, m);
		mergesort(array, m + 1, end);

		merge(array, begin, m, end);
	}
}

void swap(uint32 *array, uint32 *array2) {
	uint32 *aux;

	aux = array;
	array = array2;
	array2 = array;

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
