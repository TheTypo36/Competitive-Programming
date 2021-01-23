#include <bits/stdc++.h>
using namespace std;

class trieNode{
public:
	trieNode* left;
	trieNode* right;
};
void naiveApproach(int* arr, int  n){
	int maxXor = INT_MIN;
	for(int i = 0; i < n; i++){
		int currXor = 0;
		for(int j = i; j < n; j++){
			
			currXor = currXor ^ arr[j];
			if(currXor > maxXor){
				maxXor = currXor;
			}
		}
	}
	cout << maxXor << endl;
}
void insert(trieNode* head, int value){

	trieNode* curr = head;
	for(int i = 31; i >= 0; i--){
		int b = (value >> i)&1;
		if(b==0){
			if(!curr->left){
				curr->left = new trieNode();
			}
			curr = curr -> left;
		}else{
			if(!curr->right){
				curr -> right = new trieNode();
			}
			curr = curr -> right;
		}
	}
}
int findMaxXOrSubarray(trieNode* head, int * arr , int n){
	trieNode* curr = head;
	int maxXor = INT_MIN;
	for (int i = 0; i < n; ++i)
	{	int currXor = 0;
		int value = arr[i];
		for(int j = 31; j >= 0; j--){
			int b = (value >> j)&1;
			if(b==0){
				if(curr -> right){
					currXor += pow(2,j);
					curr = curr -> right;
				}else{
					curr = curr -> left;
				}
			}else{
				if(curr -> left){
					currXor += pow(2,j);
					curr = curr ->  right;
				}else{
					curr = curr ->  left;
				}

			}
		}
		if(currXor>maxXor){
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

	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	//naiveApproach(arr, n);

	trieNode * head = new trieNode();
	int  a = 0;	
	for (int i = 0; i < n; ++i)
	{
		a = a ^ arr[i];
		insert(head, a);	
	}
	int ans = findMaxXOrSubarray(head, arr, n);
	 cout << ans << endl;
}