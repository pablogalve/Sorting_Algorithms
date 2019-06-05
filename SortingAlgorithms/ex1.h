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

void bubblesort(uint32 * arr, int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++)
		
		// Last i elements are already in place    
		for (j = 0; j < size - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}


// Mergesort functions /////////////////////////////////////////////////

void merge(uint32 *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int *L, *R; // sub-arrays a fusionar
	L = new int[n1];
	R = new int[n2];

	for (i = 0; i < n1; i++) L[i] = arr[l + i];
	for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

	// We merge subarrays at: arr[l..r]
	i = 0; // initial index from first subarray 
	j = 0; // final index from the second subarray 
	k = l; // initial index of merged subarray 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j])  arr[k] = L[i++];
		else		       arr[k] = R[j++];
		k++;
	}

	while (i < n1) { 
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) { 
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

void mergesort(uint32 *arr, int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;     // m: mid index

		mergesort(arr, l, m);        // we sort array's left fragment  
		mergesort(arr, m + 1, r);    // we sort array's right fragment  
		merge(arr, l, m, r);         // we merge both sub-arrays
	}
}



// Quicksort functions /////////////////////////////////////////////////

int Partitions(uint32* vec, int idxStart, int idxEnd) {
	int pivot = vec[idxStart]; // Posem el pivot a la primera posició
	int left = idxStart;
	int right = idxEnd;

	while (left < right) {
		// Decrementem apuntador dret
		while (vec[right] > pivot) right--;

		// Incrementem apuntador esquerra
		while ((left < right) && (vec[left] <= pivot)) left++;

		// Si left < right -> swap(vec[left], vec[right])
		if (left < right) {
			int aux = vec[left];
			vec[left] = vec[right];
			vec[right] = aux;
		}
	}

	// Posem el pivot a la seva nova posició (apuntador dret)
	int aux = vec[right];
	vec[right] = vec[idxStart];
	vec[idxStart] = aux;

	// Retornem la posició del pivot
	return right;
}


void quicksort(uint32 *array, int begin, int end)
{
int idxPivot;

	if (begin < end) {
		idxPivot = Partitions(array, begin, end);
		quicksort(array, begin, idxPivot - 1);
		quicksort(array, idxPivot + 1, end);
		}
}
