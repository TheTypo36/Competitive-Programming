#include<bits/stdc++.h>
using namespace std;


struct warrior{
	int a;
	int b;
};
struct tree_att{
	warrior value;
	int index;
};
void buildTree(warrior* arr,tree_att* tree,int start,int end,int treeNode){
	if(start == end){
		tree[treeNode].index = start;
		tree[treeNode].value = arr[start];
		return;
	}
	int mid = (start + end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);
	tree_att c1 = tree[2*treeNode];
	tree_att c2 = tree[2*treeNode+1];
	if(c1.value.a>c2.value.a||c2.value.a>c1.value.a){
		if(c1.value.a>c2.value.a){
		tree[treeNode] = c1;

	}else{
		tree[treeNode] = c2;
		

	}
	}else if(c1.value.b>c2.value.b||c2.value.b>c1.value.b){
		if(c1.value.b>c2.value.b){
		tree[treeNode] = c1;
	

	}else{
		tree[treeNode] = c2;
		

	}
	}else{
		if(c1.index>=c2.index){
			tree[treeNode]= c1;
		}	else{
			tree[treeNode] = c2;

		}
	}
}
tree_att query(tree_att* tree,int start, int end, int left, int right, int treeNode){
	//completely outside
	if(left > end || right < start){
		tree_att basecase;
		basecase.index = 0;
		basecase.value.a = 0;
		basecase.value.b = 0;
		return basecase;
	}
	//compeletely inside;
	if(start>=left && end <= right){
		return tree[treeNode];
	}
	// partially inside and partially outside
	int mid = (start + end)/2;
	tree_att c1 = query(tree,start,mid,left,right,2*treeNode);
	tree_att c2  = query(tree,mid+1,end,left,right,2*treeNode+1);
	tree_att ans;
	
	if(c1.value.a>c2.value.a||c2.value.a>c1.value.a){
		if(c1.value.a>c2.value.a){
		ans = c1;

	}else{
		ans = c2;
		

	}
	}else if(c1.value.b>c2.value.b||c2.value.b>c1.value.b){
		if(c1.value.b>c2.value.b){
		ans = c1;
	

	}else{
		ans = c2;
		

	}
	}else{
		if(c1.index>=c2.index){
			ans= c1;
		}	else{
			ans = c2;

		}
	}
	return ans;
}
int main(){

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin>>n;
	warrior* arr = new warrior[n]();
	for(int i = 0 ; i < n; i++){
		cin >> arr[i].a;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].b;
	}
	tree_att* tree = new tree_att[4*n]();
	buildTree(arr,tree,0,n-1,1);
	int q;
	cin >> q;
	while(q--){
		int l;
		int r;
		cin >> l >> r;
		tree_att ans = query(tree,0,n-1,l-1,r-1,1);
		cout << ans.index<< endl;
	}
}