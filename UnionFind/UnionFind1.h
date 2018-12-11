#ifndef UNION_FIND1_H_
#define UNION_FIND1_H_

#include <iostream>
#include <cassert>

using namespace std;

namespace UF1{
	class UnionFind{
		private:
			int count;
			int * data;
		
		public:
			UnionFind(int n){
				this->count = n;
				data = new int[n];
				for (int i = 0 ; i< n; i++){
					data[i] = i;
				}
			}
			
			~UnionFind(){
				delete [] data;
			}
			
			int find(int p){
				assert(p >= 0 && p<count);
				return data[p];
			}
			
			bool isConnected (int p, int q){
				return find(p) == find(q);
			}
			
			void unionElements(int p, int q){
				int pID = find(p);
				int qID = find(q);
				if (pID == qID) return;
				for (int i=0; i< count; i++){
					if (data[i] == pID)
						data[i] = qID;
				}
			}
	};
}

#endif