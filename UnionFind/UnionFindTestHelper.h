#ifndef UNION_FIND_TEST1_H_
#define UNION_FIND_TEST1_H_

#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include <ctime>

namespace UnionFindTestHelper{
	void testUF1(int n){
		srand(time(NULL));
		UF1::UnionFind uf1 = UF1::UnionFind(n);
		
		time_t startTime = clock();
		
		for (int i =0; i<n ; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.unionElements(a, b);
		}
		
		for (int i =0; i<n; i++){
			int a = rand()%10;
			int b = rand()%10;
			uf1.unionElements(a, b);
		}
		
		time_t endTime = clock();
		
		cout << "cost time is: " << (double)(endTime-startTime)/CLOCKS_PER_SEC << endl;
	}
	
	void testUF2(int n){
		srand(time(NULL));
		UF2::UnionFind uf1 = UF2::UnionFind(n);
		
		time_t startTime = clock();
		
		for (int i =0; i<n ; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.unionElements(a, b);
		}
		
		for (int i =0; i<n; i++){
			int a = rand()%10;
			int b = rand()%10;
			uf1.unionElements(a, b);
		}
		
		time_t endTime = clock();
		
		cout << "cost time is: " << (double)(endTime-startTime)/CLOCKS_PER_SEC << endl;
	}
	
	void testUF3(int n){
		srand(time(NULL));
		UF3::UnionFind uf1 = UF3::UnionFind(n);
		
		time_t startTime = clock();
		
		for (int i =0; i<n ; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.unionElements(a, b);
		}
		
		for (int i =0; i<n; i++){
			int a = rand()%10;
			int b = rand()%10;
			uf1.unionElements(a, b);
		}
		
		time_t endTime = clock();
		
		cout << "cost time is: " << (double)(endTime-startTime)/CLOCKS_PER_SEC << endl;
	}
	
	void testUF4(int n){
		srand(time(NULL));
		UF3::UnionFind uf1 = UF3::UnionFind(n);
		
		time_t startTime = clock();
		
		for (int i =0; i<n ; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.unionElements(a, b);
		}
		
		for (int i =0; i<n; i++){
			int a = rand()%10;
			int b = rand()%10;
			uf1.unionElements(a, b);
		}
		
		time_t endTime = clock();
		
		cout << "cost time is: " << (double)(endTime-startTime)/CLOCKS_PER_SEC << endl;
	}
}



#endif