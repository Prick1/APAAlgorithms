#include <stdio.h>


void InsertionSort(int ar[], int size){
	int position;
	int valueToInsert;	
	for(int i = 1; i < size; i++){
		position = i;
		valueToInsert = ar[i];

		while(position > 0 && ar[position-1] > valueToInsert){
			ar[position] = ar[position-1];
			position--;
		}

		ar[position] = valueToInsert;

	}
}

void SelectionSort(int ar[],int size){
	int smallIndex;
	
	for(int i = 0; i < size; i++){
		smallIndex = i;

		for(int j = i + 1; j < size; j++){
			
			if(ar[j] < ar[smallIndex])
				smallIndex = j;

		}

		int aux = ar[i];
		ar[i] = ar[smallIndex];
		ar[smallIndex] = aux;
	}


}


int main(){
	int ar[] = {5, 4, 3, 2, 1};
	int ar2[] = {5, 4, 3, 2, 1};

	printf("Array antes da ordenação: \n");

	for(int i = 0; i < 5; i++)
		printf("%d\t", ar[i]);

	InsertionSort(ar, 5);
	printf("\nOrdenação por Insertion Sort: \n");

	for(int i = 0; i < 5; i++)
		printf("%d\t", ar[i]);

	SelectionSort(ar2, 5);
	printf("\nOrdenação por Selection Sort: \n");

	for(int i = 0; i < 5; i++)
		printf("%d\t", ar2[i]);
	printf("\n");

	return 0;
}

