#include"logic.c"
int main() {
	int arr[][] = {{1,1},{2,2},{8, 8],{4, 4},{9, 9}, {2,2},{7, 7}, {5,5}};
	int s =8;
	HeapSort(arr, s);
	for(int i = 0; i < s; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}
