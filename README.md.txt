二叉树的作用：为了解决数据的查找问题

二分查找法(非递归)：
	局限性：只有数据有序才能使用二分查找法查找数据。
// 实现（在有序的数组中，若找到key则返回，找不到则返回-1）
template<typename T>
int binarySearch(T * arr, int n , int target){
	int l = 0;
	int r = n-1;
	// 在arr闭区间[0, n-1]中查找target
	while (l <=r ){
		int middle = l+(r-l)/2;
		if ( arr[middle] == target){
			return middle;
		}else if (arr[middle] > target){
			// 在[0, middle-1]区间中查找target
			r = middle -1;
		}else {
			// 在[middle+1, r]闭区间查找target
			l = middle + 1;
		}
	}
	return -1;
}

// 递归实现二分查找
int bs (T * arr, int n , int target){
	return __bs(arr, 0, n-1, target);
}

int __bs (T * arr, int l, int r, int target){
	if ( l < r){
		int middle = l + (r-l)/2;
		if ( arr[middle] == target){
			return middle;
		}else if (arr[middle] > target){
			// 在[0, middle-1]区间中查找target
			return __bs(arr, l, middle-1, target);
		}else {
			// 在[middle+1, r]闭区间查找target
			return __bs(arr, middle+1, r, target);
		}
	}else {
		return -1;
	}
}
