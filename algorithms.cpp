#include <algorithm>


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

void Merge(int ar[],int low, int mid, int high){
    int left,right,i;
    int aux[high+1];

    for(left = low, right = mid + 1, i = low; left <= mid && right <= high; i++){
        if(ar[left] <= ar[right])
            aux[i] = ar[left++];
        else
            aux[i] = ar[right++];
    }

    while(left <= mid)
        aux[i++] = ar[left++];

    while(right <= high)
        aux[i++] = ar[right++];

    for(i = low; i <= high; i++)
        ar[i] = aux[i];
    
}

void MergeSort(int ar[], int low, int high){


    if(low < high){
        int mid;
        mid = (low + high) / 2;
        MergeSort(ar, low, mid);
        MergeSort(ar, mid + 1, high);
        Merge(ar, low, mid, high);
    }
    else
        return;
}

int Partition(int ar[], int left, int right, int pivot){
    int leftP = left - 1;
    int rightP = right;

    while(1){
        while(ar[++leftP] < pivot);

        while(ar[rightP] > 0 && ar[--rightP] > pivot);

        if(leftP >= rightP)
            break;

        else{
            int aux = ar[leftP];
            ar[leftP] = ar[rightP];
            ar[rightP] = aux;
        }
    }

    int aux = ar[leftP];
    ar[leftP] = ar[right];
    ar[right] = aux; 

    return leftP;

}

void QuickSort(int ar[], int left, int right){
    if(right-left <= 0)
        return;
    else{
        int pivot = ar[right];
        int part = Partition(ar, left, right, pivot);
        QuickSort(ar, left, part-1);
        QuickSort(ar, part+1, right);
    }
}


void InsertOnHeap(int heapAr[], int value, int size){
    unsigned int pos;
    for(pos = ++size; pos > 1 && heapAr[pos/2] > value; pos /= 2){
        int aux = heapAr[pos];
        heapAr[pos] = heapAr[pos/2];
        heapAr[pos/2] = aux;
    }
    heapAr[pos] = value;
}

void sinkDown(int heapAr[], int pos, int size){//int a = mH[k];
		int smallest = pos;
		if(2*pos <= size && heapAr[smallest] > heapAr[2*pos]){
			smallest = 2*pos;
		}

        if(2*pos+1<= size && heapAr[smallest] > heapAr[2*pos + 1]){
			smallest = 2*pos + 1;
		}
        
		if(smallest != pos){
            //printf("Smallest: %d, Pos: %d\n",smallest, pos);
			int aux = heapAr[pos];
			heapAr[pos] = heapAr[smallest];
			heapAr[smallest] = aux;
			sinkDown(heapAr, smallest, size);
		}
}
int GetFromHeap(int heapAr[], int size){
    int ret = heapAr[1];
    heapAr[1] = heapAr[size];
    sinkDown(heapAr, 1 ,--size);
    return ret;
}

void HeapSort(int ar[], int size){
    int heapAr[size+1];
    int count = size;
    for(int i = 0; i < size; i++){
        InsertOnHeap(heapAr, ar[i], i);
    }
    for(int i = 0; i < size; i++){
        ar[i] = GetFromHeap(heapAr, count--);
    }

}

/*COUNTING-SORT (A, B, k)
for i ← 0 to k
      C[i] ← 0;
for j ← 1 to comprimento[A]
      C[A[j] ] ←  C[A[j] ] + 1;
//Agora C[i] contém o número de elementos iguais a i em A
for i ← 2 to k
       C[i] ← C[i] + C[i -1];
//Agora C[i] contém o número de elementos menores ou iguais a i.
for j ← comprimento[A]  downto 1
       B[C[A[j] ] ] ← A[j];
       C[A[j] ] ←  C[A[j] ] – 1; 
*/
void CountSort(int A[], int size){

    int min = *(std::min_element(A, A+size));
    if(min < 0){
        for(int i = 0; i < size; i++)
            A[i] -= min;
    }
    else
        min = 0;

    int k = *(std::max_element(A, A+size));
    int C[k+1];

    for(int i = 0; i <= k; i++)
        C[i] = 0;

    for(int j = 0; j < size; j++)
        C[A[j]]++;

    for(int i = 1; i <= k; i++)
        C[i] += C[i - 1];

    int B[size];

    for(int j = size - 1; j >= 0; j--){
        B[ C[ A[j] ] - 1 ] = A[j];
        C[A[j]]--;
    }

    for(int i = 0; i < size; i++){
        A[i] = B[i] + min;
    }

}

inline void CountSortAux(int A[], int size, int exp){
    int C[10] = {0};

    for(int j = 0; j < size; j++)
        C[ (A[j]/exp)%10 ]++;

    for(int i = 1; i < 10; i++)
        C[i] += C[i - 1];

    int B[size];

    for(int j = size - 1; j >= 0; j--){
        B[ C[ (A[j]/exp)%10 ] - 1 ] = A[j];
        C[ (A[j]/exp)%10 ]--;
    }

    std::copy(B, B+size, A);
}

void RadixSort(int A[], int size){

    int min = *(std::min_element(A, A+size));
    if(min < 0){
        for(int i = 0; i < size; i++)
            A[i] -= min;
    }

    int k = *(std::max_element(A, A+size));

    for(int exp = 1; k/exp > 0; exp *= 10)
        CountSortAux(A, size, exp);
    if(min < 0){
        for(int i = 0; i < size; i++)
            A[i] += min;
    }
    
}


