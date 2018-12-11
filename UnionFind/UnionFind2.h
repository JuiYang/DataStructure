#ifndef UNION_FIND2_H_
#define UNION_FIND2_H_

#include <iostream>
#include <cassert>

using namespace std;

namespace UF2{
	class UnionFind{
		private:
			int count;
			int * parent;
		
		public:
			UnionFind(int n){
				this->count = n;
				parent = new int[n];
				// 初始化数据
				for (int i =0;i<n;i++){
					parent[i] = i;
				}
			}
			
			~UnionFind(){
				delete [] parent;
			}
			
			// 查找Union根
			int find(int p){
				assert(p >= 0 && p<count);
				while( p != parent[p]){
					p = parent[p];
				}
				return p;
			}
			
			bool isConnected (int p, int q){
				return find(p) == find(q);
			}
			
			// 将p连接到q上
			void unionElements(int p, int q){
				int pID = find(p);
				int qID = find(q);
				if (pID == qID) return;
				parent[pID] = qID;
			}
	};
}

#endif