#include <iostream>

using namespace std;

int main(void){
	return 0;
}

二叉树的前中后序遍历：（深度优先遍历）
	
前序遍历
中序遍历： 输出为有序（小->大）
后序遍历： 释放二叉树

二叉树的层次遍历：（广度优先遍历）
（二叉树+队列）

#include <queue>
// 层次遍历
void levelOrder(Node * root){
	queue<Node *> q;
	// 入队操作
	q.push(root);
	
	// 队列不为空
	while (!q.empty()){
		Node * p = q.front();
		// 出队操作
		q.pop();
		if (p->left != NULL){
			q.push(p->left);
		}
		
		if (p->right != NULL){
			q.push(p->right);
		}
		
		cout << p->key << endl;
		
	}
}


// 查找二叉树的最小值
Node * findMinMum(Node * root){
	if (root ->left == NULL)
		return root;
	return findMinMum(root->left);
}

// 查找二叉树的最大值
Node * findMaxMum(Node * root){
	if (root -> right == NULL)
		return root;
	return findMaxMum(root->right);
}