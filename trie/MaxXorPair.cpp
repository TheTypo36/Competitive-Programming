#include <bits/stdc++.h>
using namespace std;

class trieNode{
public:
	trieNode* left;
	trieNode* right;
};

void insert(int n, trieNode* head){

	trieNode* curr = head;
	for(int j = 31 ; j>=0; j--){
		int b = (n>>j)&1;
		if(b==0){
			if(!curr->left){
				curr->left = new trieNode();
			}
			curr = curr -> left;
		}else{
			if(!curr->right){
				curr -> right =new trieNode();
			}
			curr = curr -> right;
		}
	}
}
int findMaxXorPair(int n,int* arr, trieNode* head){
	int maxXor = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		trieNode* curr = head;
		int currXor = 0;
		int curr_number = arr[i];
		for(int j = 31; j >=0 ; j--){
			int b = (curr_number >> j)&1; 
			if(b==0){
				if(curr->right){
					currXor += pow(2,j);
					curr =curr -> right;
				}else{
					curr = curr -> left;
				}
			}else{
				if(curr -> left){
					currXor += pow(2,j);

					curr = curr -> left;
				}else{
					curr = curr -> right;
				}
			}
		}
		if(currXor > maxXor){
			maxXor = currXor;
		}
	}
	return maxXor;
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	int* arr = new int [n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		
	}
	trieNode* head = new trieNode() ;
	for (int i = 0; i < n; ++i)
	{
		insert(arr[i],head);
		
	}
	int ans = findMaxXorPair(n,arr,head);
	cout << ans << endl;
	

}