#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>

using namespace std;

template<typename T>
class MaxHeap{
	private:
		T * data;
		int count;
		int capacity;

		void shiftUp(int k){
			while ( k > 1 && data[k/2] < data[k]){
				swap(data[k/2], data[k]);
				k /= 2;
			}
		}

		void shiftDown(int k){
			while( 2*k <= count)
			{
				int j = 2*k;
				if (j+1 <= count && data[j+1] > data[j])
					j = j+1;
				if ( data[k] > data[j]) break;
				swap(data[j], data[k]);
				k = j ;
			}
		}

		void shiftDown(int k, int size){
			while( 2*k <= size)
			{
				int j = 2*k;
				if (j+1 <= size && data[j+1] > data[j])
					j = j+1;
				if ( data[k] > data[j]) break;
				swap(data[j], data[k]);
				k = j ;
			}
		}

	public:
		MaxHeap(int capacity){
			data = new T[capacity + 1];
			count = 0;
			this->capacity = capacity;
		}

		MaxHeap(T * arr, int n){
			data = new T[n + 1];
			this-> capacity = n;
			for (int i = 0; i < n; ++i)
			{
				data[i+1] = arr[i];
			}
			count = n;

			// update to max heap
			for (int i = count/2; i >= 1; --i)
			{
				shiftDown(i);
			}
		}

		~MaxHeap(){
			delete[] data;
		}

		int getSize(){
			return count;
		}

		bool isEmpty(){
			return count == 0;
		}

		void insert(int leaf){
			assert((count + 1) <= capacity);
			data[ count + 1] = leaf;
			count ++;
			// 调整堆，使其满足大根堆
			shiftUp(count);
		}

		void printfHeap(){
			// 堆的访问从数组下标是１开始
			for (int i = 1; i <= count; ++i)
			{
				cout << data[i] << " ";
			}
			cout << endl;
		}

		// get array with desc order
		int extractMax(){
			assert(count > 0);
			int max = data[1];
			swap(data[1], data[count]);
			count --;
			shiftDown(1);
			return max;
		}

		
		
		
};

#endif
