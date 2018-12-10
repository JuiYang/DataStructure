#ifndef GENERALARRAYHELPER_H_
#define GENERALARRAYHELPER_H_

#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>

using namespace std;

namespace GeneralArrayHelper{
	
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
	void printArrat(T arr[], int n){
		for (int i =0 ; i < n ; i++){
			cout <<arr[i] << " ";
		}
		cout << endl;
		return;
	}

	// function point 
	template<typename T>
	void testSort(string sortName, void (* sort)(T *, int ), T *arr,  int n)
	{
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		cout << sortName << " cost time: " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
		return ;
	}

	// copy array
	template<typename T>
	T * copyArray(T * arr, int n){
		T * newArr = new T[n];
		copy(arr, arr+n, newArr);
		return newArr;
	}
}


#endif