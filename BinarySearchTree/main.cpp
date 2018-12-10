#include <iostream>
#include <queue>

using namespace std;

template<typename Value>
class BST{

	private:
		struct Node{
			Value value;
			Node * left;
			Node * right;
		
			Node(Value value){
				this->value = value;
				this->left = this->right = NULL;
			}
			
			Node (Node * node){
				this -> value = node -> value;
				this -> left = node -> left;
				this -> right = node -> right;
			}
		};
		
		
		Node * root;
		int count;
		
	public:
		BST(){
			root = NULL;
			count = 0;
		}
		
		~BST(){
			destory(root);
		}
		
		int getSize(){
			return count;
		}
		
		bool isEmpty(){
			return count==0;
		}
		
		
		void insertNode(Value value){
			root = __insertNode(root,value);
		}
		
		bool contain(Value value){
			__contain(root, value);
		}
		
		//Value * search(Value value){
		//	return search(root,value);
		//}
		
		
		
		// 前序遍历
		void preOrder(){
			__preOrder(root);
		}
		// 中序遍历
		void midOrder(){
			__midOrder(root);
		}
		// 后续遍历
		
		// 按层遍历
		void levelOrder(){
			__levelOrder(root);
		}
		
		// 返回二叉树中最小值节点
		Node * findMinMum(Node * root){
			assert(count > 0;);
			if (root ->left == NULL)
				return root;
			return findMinMum(root->left);
		}

		// 查找二叉树的最大值节点
		Node * findMaxMum(Node * root){
			assert(count > 0);
			if (root -> right == NULL)
				return root;
			return findMaxMum(root->right);
		}
		
		// 删除二叉树最大节点
		void removeMAX(){
			assert(count > 0);
			root = removeMAX(root);
		}
		
		void removeMIN(){
			assert(count > 0);
			root = removeMIN(root);
		}
		
		// 删除给定value的节点
		void delete(int value){
			root = delete(root, value);
		}

	private:
		Node * __insertNode(Node * node, Value value){
			// create root node
			if (node == NULL){
				count ++;
				return new Node(value);
			}
			
			if (node->value < value){
				node ->right = __insertNode(node->right, value);
			}else{
				node->left = __insertNode(node->left,value);
			}
			return node;
		}
		
		// weather binary tree contain key
		bool __contain(Node * root, Value key){
			if (root == NULL)
				return false;
			
			if (root->value == key)
				return true;
			else if (root->value < key)
				return __contain(root->right, key);
			else {
				return __contain(root->left, key);
			}
		}
		
		Value * __search(Node * root, Value key){
			if (root == NULL)
				return NULL;
			
			if (root ->value == key){
				return &(root->value);
			}else if (root->value < key){
				return __search(root->right , key);
			}else{
				return __search(root->left, key);
			}
		}
		
		void __preOrder(Node * root){
			if (root != NULL){
				cout << root->value <<endl ;
				__preOrder(root->left);
				__preOrder(root->right);
			}
		}
		
		void __midOrder(Node * root){
			if (root != NULL){
				__midOrder(root->left);
				cout << root->value << " ";
				__midOrder(root->right);
			}
		}
		
		void destory(Node * node){
			if (root != NULL){
				// 后续
				destory(node->left);
				destory(node->right);
				delete node;
				count --;
			}
		}
		
		void __levelOrder(Node * root){
			queue<Node *> q;
			q.push(root);
			while (!q.empty()){
				Node * p = q.front();
				q.pop();
				cout << p->value << " ";
				if (p->left != NULL) q.push(p->left);
				if (p->right != NULL) q.push(p->right);
			}
		}
		
		// 删除最大节点
		Node * removeMAX(Node * root){
			if (root -> right == NULL){
				Node * leftNode = root -> left ;
				delete root;
				count --;
				return leftNode;
			}
			root -> right = removeMAX(node -> right);
			return root;
		}
		
		// 删除最小节点
		Node * removeMIN(Node * root){
			if (root -> left = NULL){
				Node * rightNode = root -> right;
				delete root;
				count --;
				return rightNode;
			}
			
			root -> left = removeMIN(root->left);
			return root;
		}
		
		// 删除指定value的节点
		Node * delete(Node * root, int value){
			if ( root == NULL){
				return NULL;
			}
			
			if ( value < root -> value){
				root -> left = delete(root->left, value);
				return root;
			} else if (value > root -> value){
				root -> right = delete(root -> right, value);
				return root;
			}else {
				if (root -> left == NULL){
					Node * rightNode = root -> right;
					delete root;
					count --;
					return rightNode;
				} else if (root -> right == NULL){
					Node * leftNode = root -> left;
					delete root;
					count --;
					return leftNode;
				} else {
					// 由于removeMIN()方法会删除掉最小节点，所以rightMIN指针的指向也就不存在。
					// 所以我们需要重新复制最小节点Node(Node *node)
					// 获取最小值节点
					Node * rightMIN = new Node(findMinMum(root->right));
					count ++;
					// 给该节点左右孩子赋值
					// 获取删除最小节点的指针
					Node * node = removeMIN(root->right);
					rightMIN -> right = node;
					rightMIN -> left = root ->left;
					
					// 删除value 节点
					delete root;
					count --;
					return rightMIN;
				}
			}
		}
};


int main(void){
	BST<int> bst;
	int n = 8;
	int arr[] = {2, 5, 6, 1, 3, 9, 0 ,34};
	// 创建二叉树
	for (int i=0; i< n;i++){
		bst.insertNode(arr[i]);
	}
	
	// 查找值
	if(bst.contain(34)){
		cout << "find this key"<< endl;
	}else{
		cout << "this key is not in tree"<< endl;
	}
	cout << "count: " << bst.getSize() << endl;
	bst.preOrder();
	
	if (88){
		cout << "true" << endl;
	}else{
		cout << "false" << endl;
	}
	
	return 0;
}
