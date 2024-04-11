#include"logic.c"
int main() {
	Heap a;
	initHeap(&a, 7);
	printf("%d, %d\n", isEmpty(&a), isFull(&a));
	insert(&a, 1, 8);
	insert(&a, 2, 2);
	insert(&a, 3, 4);
	insert(&a, 4, 3);
	insert(&a, 5, 7);
	insert(&a, 6, 6);
	insert(&a, 7, 5);
	for(int i = 0; i < 7; i++) {
		printf("Unique no. = %d, Counter = %d\n", a.arr[i].unique_no, a.arr[i].counter);
	}
	priority* max = Remove(&a);
	printf("%d, %d\n", max->unique_no, max->counter);
	for(int i = 0; i < 6; i++) {
		printf("Unique no. = %d, Counter = %d\n", a.arr[i].unique_no, a.arr[i].counter);
	}
	return 0;
}

