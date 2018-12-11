#ifndef UNION_FIND3_H_
#define UNION_FIND3_H_


// 改进：采用路径压缩降低树的层数，从而提供查找性能
// 并查集时间复杂度几乎时: O(1)

#include <iostream>
#include <cassert>

using namespace std;

namespace UF4{
	class UnionFind{
		private:
			int count;
			int * parent;
			// 改进：rank[i]记录以i为根的集合元素的层数
			int * rank;
		
		public:
			UnionFind(int n){
				this->count = n;
				parent = new int[n];
				rank = new int[n];
				// 初始化数据
				for (int i =0;i<n;i++){
					parent[i] = i;
					rank[i] = 1;
				}
			}
			
			~UnionFind(){
				delete [] parent;
			}
			
			// 查找Union根（生产时用此法）
			int find(int p){
				assert(p >= 0 && p<count);
				/**
				while( p != parent[p]){
					// 路径压缩
					parent[p] = parent[parent[p]];
					p = parent[p];
				}
				return p;
				*/
				
				//改进：将根节点的集合的所有元素指向根节点（面试可用此法）
				if( p!= parent[p]){
					parent[p] = find(parent[p]);
				}
				return parent[p];
			}
			
			bool isConnected (int p, int q){
				return find(p) == find(q);
			}
			
			// 将p连接到q上
			void unionElements(int p, int q){
				int pID = find(p);
				int qID = find(q);
				if (pID == qID) return;
				
				// 判断两个元素的根节点的集合元素个数
				if ( rank[pID] > rank[qID] ){
					parent[qID] = pID;
				}
				else if (rank[pID] < rank[qID]){
					parent[pID] = qID;
				}
				else { // rank[pID] == rank[qID]
					parent[qID] = pID;
					rank[pID] += 1;
				}
			}
	};
}

#endif