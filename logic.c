#include"head.h"
void initHeap(Heap* h, int size) {
	h -> arr = (priority*)malloc(size * sizeof(priority));
	h -> size = size;
	h -> rear = -1;
	return;
}

void swap(priority* a, priority* b) {
	int tempuniqueno = a -> unique_no;
	int tempcounter = a -> counter;
	a -> unique_no = b -> unique_no;
	a -> counter = b -> counter;
	b -> unique_no = tempuniqueno;
	b -> counter = tempcounter;
	return;
}

int isEmpty(Heap* h) {
	return(!(h -> rear));
}

int isFull(Heap* h) {
	return(h -> rear == h -> size - 1);
}

/*void HeapSort(int arr[], int size) {
	Heap newHeap;
	initHeap(&newHeap, size);
	for (int i = 0; i < size; i++) {
		insert(&newHeap, arr[i]);
	}
	int i = 0;
	while(!isEmpty(&newHeap)) {
		arr[i] = Remove(&newHeap);
		i++;
	}
}*/

void HeapSort(priority arr[], int size) {
	Heap newHeap;
	initHeap(&newHeap, size);
	for (int i = 0; i < size; i++) {
		insert(&newHeap, arr[i].unique_no, arr[i].counter);
	}
	int i = 0;
	while(!isEmpty(&newHeap)) {
		arr[i] = *(Remove(&newHeap));
		i++;
	}
}

/*void insert(Heap* h, int value) {
	if(h -> rear == h -> size - 1) {
		printf("Heap is full. Cannot insert value.\n");
		return;
	}
	h -> rear++;
	int i = h -> rear;
	while(i > 0 && value > h -> A[(i - 1) / 2]) {
		h -> A[i] = h -> A[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	h -> A[i] = value;
}*/

void insert(Heap* h, int uqn, int coun) {
	if(h -> rear == h -> size - 1) {
		printf("Heap is full. Cannot insert value.\n");
		return;
	}
	h -> rear++;
	int i = h -> rear;
	while(i > 0 && coun > (h -> arr[(i - 1) / 2].counter)) {
		h -> arr[i].counter = h -> arr[(i - 1) / 2].counter;
		h -> arr[i].unique_no = h -> arr[(i - 1) / 2].unique_no;
		i = (i - 1) / 2;
	}
	h -> arr[i].counter = coun;
	h -> arr[i].unique_no = uqn;
}

/*int Remove(Heap* h) {
	if(h -> rear < 0) {
		printf("Heap is empty. Cannot remove value.\n");
		return -1;
	}
	int removedValue = h -> A[0];
	h -> A[0] = h -> A[h -> rear];
	h -> rear--;
	heapify(h, 0);
	return removedValue;
}*/

/*priority Remove(Heap* h) {
	if(h -> rear < 0) {
		printf("Heap is empty. Cannot remove value.\n");
		return NULL;
	}
	priority removedValue = h -> arr[0];
	h -> arr[0] = h -> arr[h -> rear];
	h -> rear--;
	heapify(h, 0);
	return removedValue;
}*/

priority* Remove(Heap* h) {
	if(h -> rear < 0) {
		printf("Heap is empty. Cannot remove value.\n");
		return NULL;
	}
	priority* removedValue = &(h -> arr[0]);
	h -> arr[0] = h -> arr[h -> rear];
	h -> rear--;
	heapify(h, 0);
	return removedValue;
}

void heapify(Heap* h, int index) {
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if(left <= h -> rear && h -> arr[left].counter > h -> arr[largest].counter) largest = left;
	if(right <= h -> rear && h -> arr[right].counter > h -> arr[largest].counter) largest = right;
	if(largest != index) {
		swap(&h -> arr[index], &h -> arr[largest]);
		heapify(h, largest);
	}
	return;
}
