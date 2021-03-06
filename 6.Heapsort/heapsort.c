#include <stdio.h>

#define PARENT(i) ((i + 1)/2 - 1)
#define LEFT(i) (2*i + 1)
#define RIGHT(i) (2*i + 2)

void printList(int *array, int size){
	int i = 0;
	for(;i<size; i++){
		printf("%d ", array[i]);
	}
}

void exchange(int *heap, int i, int j){
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}

void maxHeapify(int *heap,int heapSize, int i){
	int left = LEFT(i), right = RIGHT(i), largest;
	
	if(left < heapSize && heap[i] < heap[left]) 
		largest = left;
	else 
		largest = i;
	
	if(right < heapSize && heap[largest] < heap[right]) 
		largest = right;
	
	if (largest  != i) {
		exchange(heap, i, largest);
		maxHeapify(heap, heapSize, largest);
	} 
}

void buildMaxHeap(int *heap, int heapSize){
	int i = 0;
	for(; i < heapSize/ 2 + 1; i++){
		maxHeapify(heap, heapSize, i);
	}
}

void heapSort(int *heap, int heapSize){
	buildMaxHeap(heap, heapSize);
	int i = heapSize - 1;
	for(;i > 0; i--){
		exchange(heap, 0, i);
		heapSize--;
		maxHeapify(heap, heapSize, 0);
	}
}

int main(int argc, char *argv[])
{
	int heap[] = {16,4,10,14,7,9,3,2,8,1};
	int heapSize = sizeof(heap)/ sizeof(int);
	
	heapSort(heap, heapSize);
	printList(heap, heapSize);
	return 0;
}
