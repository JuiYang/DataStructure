#include "GeneralArrayHelper.h"

using namespace GeneralArrayHelper;

// select sort, every time we can get the smallest or the biggest value , and so ...
// such as small to big
// set template
template <typename T>
void selectSort(T * arr, int n)
{
	for (int i = 0; i < n ; i ++)
	{
		int tmp = i;
		for (int j = i+1; j < n; ++j)
		{
			/* code */
			if (arr[tmp] > arr[j])
			{
				tmp = j;
			}

		}
		swap(arr[i], arr[tmp]);
	}
	return;
}

// insert sort 
// 相比选择排序，插入排序提前终止内层循环
// 近乎有序的数组，使用插入排序算法，时间复杂度由Ｏ(n^2)  --> Ｏ(n), 比如系统日志
template<typename T>
void insertSort(T * arr, int n){
	for (int i = 1; i < n; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			if (arr[j] < arr[j-1])
			{
				swap(arr[j], arr[j-1]);
			}else{
				break;
			}
		}
	}
}

// insert sort optmistic 
template<typename T>
void insertSortOptimistic(T * arr, int n){
	for (int i = 1; i < n; ++i)
	{
		int tmp = arr[i];
		int j = i ;
		for ( ; j > 0 && tmp < arr[j-1] ; --j)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = tmp;
	}
}

// bubbleSort
template<typename T>
void bubbleSort(T * arr, int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			/* code */
			if (arr[j]>arr[j+1])
			{
				swap(arr[j], arr[j+1]);
			}
		}
	}
}


template<typename T>
void merge(T * arr, int l, int m, int r){
	T * tmpArray = new T[r-l+1];
	// merge
	int i = l;
	int j = m+1;
	int k = 0;
	while( i <= m && j <= r ){
		// compare data and swap
		if ( arr[i] < arr[j] )
			tmpArray[k++] = arr[i++];
		else
			tmpArray[k++] =  arr[j++];
	}
	if ( i > m){
		//copy right
		while ( j <= r){
			tmpArray[k++] = arr[j++];
		}
	}

	if ( j > r){
		// copy left
		while ( i <= m ){
			tmpArray[k++] = arr[i++];
		}
	}

	// copy tempArr data to arr 
	for (int i = 0; i < k; ++i)
	{
		arr[ i+ l] = tmpArray[i];
	}

	// release source
	delete[] tmpArray;
}

template<typename T>
void __mergeSort(T *arr, int l , int r){
	if (l >= r)
		return;
	int middle = (l + r) /2;
	__mergeSort(arr, l, middle);
	__mergeSort(arr, middle+1, r);
	merge(arr, l, middle, r);

}


// 归并排序
template<typename T>
void mergeSort(T * arr, int n){
	// 二分
	__mergeSort(arr, 0, n-1);
}



template<typename T>
int getMiddleIndex(T * arr, int l, int r){
	int middle = (l + r)/2;
	if (arr[l] < arr[r])
	{
		if (arr[l] > arr[middle])
		{
			return l;
		}else if (arr[r] < arr[middle])
		{
			return r;
		}else
		{
			return middle;
		}
	}else{
		if (arr[l] < arr[middle])
		{
			return l;
		}else if(arr[r] > arr[middle])
		{
			return r;
		}else{
			return middle;
		}
	}
}

template<typename T>
int getSentryIndex(T * arr, int l , int r){
	int middleIndex = getMiddleIndex(arr, l, r);
	swap(arr[middleIndex], arr[r]);
	int i = l;
	int j = r-1;
	while( i < j){
		while( i < j && arr[i] <= arr[r] ){
			i++;
		}
		while( i < j && arr[j] >= arr[r] ){
			j--;
		}
		swap( arr[i], arr[j]);
	}
	swap(arr[i], arr[r]);
	return i;
}

template<typename T>
void __quickSort(T * arr, int l , int r){
	if (l >= r)
		return;
	int index = getSentryIndex(arr, l, r);
	__quickSort(arr, l , index-1);
	__quickSort(arr, index+1, r);
}

// quick sort 
template<typename T>
void quickSort(T * arr, int n){
	// get middle data
	__quickSort(arr, 0, n-1);
}

int main (void){
	int n = 100000;
	int * arr = generateRandomArray(n , 0, n);
	// int n = 11;
	// int aa[] = {2, 5, 6, 2, 1, 3, 5, 1, 9, 0 ,34};	
	// int * arr = aa;
	// SelectSort(arr, n);
	// testSort("Select Sort", insertSort, arr, n);
	testSort("Select Sort", quickSort, arr, n);
	if (arr != NULL)
	{
		/* code */
		// printArrat(arr, n);
	}
	
	// // release resourse
	delete[] arr;
	cout << "sublime text " << endl;
	return 0;
}
