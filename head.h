#include<stdio.h>
#include<stdlib.h>

typedef struct priority {
	int unique_no;
	int counter;
}priority;

typedef struct Heap{
	priority* arr;
	int size;
	int rear;
}Heap;

void initHeap(Heap* h, int size);

void swap(priority* a, priority* b);

int isEmpty(Heap* h);

int isFull(Heap* h);

void HeapSort(priority arr[], int size);

void insert(Heap* h, int uqn, int coun);

priority* Remove(Heap* h);

void heapify(Heap* h, int index);


