#include<iostream>
using namespace std;
struct tree_attrs
{
	int sum_of_squares;
	int sum;
};
struct lazy_attrs
{
	int setter = 0;
	int incermentor = 0;
};
void build_tree(int* arr, tree_attrs* tree, int start, int end, int treenode)
{
	if(start == end){
		tree[treenode].sum = arr[start];
		tree[treenode].sum_of_square = (arr[start] * arr[start]);
		return;
	}
	int mid = (start + end)/2;
	build_tree(arr,tree,start,mid, 2 * treenode);
	build_tree(arr,tree,mid+1,end, 2 * treenode + 1);
	tree[treenode].sum = tree[2 * treenode].sum + tree[2 * treenode + 1].sum;
	tree[treenode].sum_of_square = tree[2 * treenode].sum_of_square + tree[2 * treenode + 1].sum_of_square;
}
void lazy_update_setter(tree_attrs* tree, lazy_attrs* lazy, int start, int end, int left, int right, int current_position, int x)
{
}
void lazy_update_incrementor(tree_attrs* tree, lazy_attrs* lazy, int start, int end, int left, int right, int current_position, int increment)
{
	
}

tree_attrs query(tree_attrs* tree, lazy_attrs *lazy, int start, int end, int left, int right, int treenode)
{	
}

int main()
{
	int t;
	cin >> t;
	int case_number = 1;
	while (t--)
	{
		cout << "Case " << case_number << ":" << endl;
		int n, q;
		cin >> n >> q;
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		tree_attrs* tree = new tree_attrs[4 * n]();
		lazy_attrs* lazy = new lazy_attrs[4 * n]();
		build_tree(arr, tree, 0, n - 1, 1);
		while (q--)
		{
			int type_of_operation;
			cin >> type_of_operation;
			if (type_of_operation == 2)
			{
				int left, right;
				cin >> left >> right;
				cout << query(tree, lazy, 0, n-1, left - 1, right - 1, 1).sum_of_squares<<endl;
			}
			else if (type_of_operation == 1)
			{
				int left, right;
				cin >> left >> right;
				int increment;
				cin >> increment;
				lazy_update_incrementor(tree, lazy, 0, n-1, left-1, right-1, 1, increment);
			}
			else
			{
				int left, right;
				cin >> left >> right;
				int x;
				cin >> x;
				lazy_update_setter(tree, lazy, 0, n-1, left-1, right-1, 1, x);
			}
		}
		case_number++;
	}
}