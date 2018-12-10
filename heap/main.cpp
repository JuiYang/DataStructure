#include "maxHeap.h"

// 随机生成长度是n数组，　范围在[rangeL , rangeH]之间
int * generateRandomArray(int n, int rangeL, int rangeH){

	// 判断rangeH,rangeL
	assert(rangeH >= rangeL);
	// 以时间作为随机种子
	srand(time(NULL));
	int * arr = new int[n];
	for (int i =0 ; i<n ; i++){
		arr[i] = rand() % (rangeH - rangeL + 1) + rangeL;
	}
	return arr;
}

template <typename T>
void printArray(T arr[], int n){
	for (int i =0 ; i < n ; i++){
		cout <<arr[i] << " ";
	}
	cout << endl;
	return;
}

template<typename T>
void heapSort1(T * arr, int n){
	MaxHeap<T> maxHeap = MaxHeap<T>(n);
	for (int i = 0; i < n; ++i)
	{
		maxHeap.insert(arr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		arr[i] = maxHeap.extractMax();
	}
}

template<typename T>
void heapSort2(T * arr, int n){
	MaxHeap<int> maxHeap = MaxHeap<int>(arr, n);
	for (int i = 0; i < n; ++i)
	{
		arr[i] = maxHeap.extractMax();
	}
	// printArray(arr, n);
	
}


// 原地排序

template<typename T>
void __shiftDown(T * arr, int n , int i){
	int j = 2*i +1;
	while( 2*i+1 < n ){
		int j = 2*i+1;
		if (j+1 < n && arr[j+1] > arr[j] )
			j += 1;
		if (arr[j] < arr[i]) break;
		swap(arr[j], arr[i]);
		i = j;
	}
}

template<typename T>
void heapSort(T * arr, int n){
	// 先调整为一个大根堆
	// 第一个非叶子节点未(n-1)/2
	for (int i =(n-1)/2;i>= 0 ; i--){
		__shiftDown(arr, n, i);
	}
	
	// 取出最大值
	for (int i= n-1; i>0; i--){
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}
}

template<typename T>
void printArr(T * arr, int n){
	for (int i =0; i< n; i++)
		cout << arr[i] << " ";
	cout << endl;
}





int main(void){
	// int n = 1000000;
	// int * arr = generateRandomArray(n, 0, n);
	int n = 11;
	int aa[] = {2, 5, 6, 2, 1, 3, 5, 1, 9, 0 ,34};
	int * arr = aa;
	// MaxHeap<int> maxHeap = MaxHeap<int>(arr, n);
	// maxHeap.printfHeap();
	
	// printArray(arr, n);

	clock_t startTime = clock();
	
	// heapSort1(arr, n);
	// heapSort2(arr, n);
	heapSort(arr, n);
	printArr(arr, n);

	clock_t endTime = clock();
	cout <<" cost time: " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;


	// MaxHeap<int> maxHeap = MaxHeap<int>(100);
	// srand(time(NULL));
	// for (int i = 0; i < 15; ++i)
	// {
	// 	maxHeap.insert(rand() % 100);
	// }
	// cout << "maxheap " << maxHeap.getSize() << endl;
	// if (!maxHeap.isEmpty())
	// {
	// 	maxHeap.extractMax();
	// }
	// maxHeap.printfHeap();
	// maxHeap.extractMax();
	// cout << "extractMax after " << endl;
	// maxHeap.printfHeap();
	return 0;
}
