#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int max;
	int min;
};
Node query(Node* tree, int start, int end,int treeNode, int left, int right){
	if(left > end || right < start){
		Node ans;
		ans.max = INT_MIN;
		ans.min = INT_MIN;
		return ans;
	}
	if(start>=left && end <=right){
		return tree[treeNode];
	}
	int mid = (start + end)/2;

	Node ans1 = query(tree, start, mid,2* treeNode,left,right);
	Node ans2 = query(tree, mid + 1, end , 2* treeNode +1, left, right);
	Node finalans ;
	finalans.max = max(ans1.max,ans2.max);
	finalans.min = min(max(ans2.max,ans1.min),max(ans1.max,ans2.min));
	return finalans;
}
void update(int* arr, Node* tree, int start,int end, int treeNode, int idx, int value){
	if(start == end){
		arr[idx] = value;
		tree[treeNode].max = value;
		tree[treeNode].min = INT_MIN;
		return;
	}
	int mid = (start + end)/2;
	if(idx > mid){
		update(arr,tree,mid+1,end,2*treeNode+1,idx,value);
	}
	else{
		update(arr,tree,start,mid,2*treeNode,idx,value);
	}
	Node left = tree[2*treeNode];
	Node right = tree[2*treeNode+1];
	tree[treeNode].max = max(left.max,right.max);
	
	tree[treeNode].min = min(max(left.max,right.min),max(right.max,left.min));

	return;
}
void build(int* arr, Node* tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode].max = arr[start];
		tree[treeNode].min = INT_MIN;
		return;
	}

	int mid =(start + end)/2;
	build(arr,tree,start,mid,2*treeNode);
	build(arr,tree,mid+1,end,2*treeNode+1);
	Node left = tree[2*treeNode];
	Node right = tree[2*treeNode+1];
	tree[treeNode].max = max(left.max,right.max);
	tree[treeNode].min = min(max(left.max,right.min),max(right.max,left.min));
	return;
}
int main(){
	int n;
	cin >> n;
	int* arr =new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		
	}
	int q;
	cin >> q;
	Node* tree = new Node[3*n];
	build(arr, tree, 0, n-1, 1);
	while(q--0){
		char ch;
		cin >> ch ;
		if(ch == 'Q'){
			int left, right;
			cin >> left >> right;
			Node ans = query(tree,0,n-1,1,left-1,right-1);
			cout << ans.min + ans.max << endl;
		}else if(ch == 'U'){
			int x,y;
			cin >> x >> y;
			update(arr,tree,0,n-1,1,x-1,y);
		}
	}
}