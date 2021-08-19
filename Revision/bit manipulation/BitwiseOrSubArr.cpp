#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define F first
#define S second
typedef long long ll;



int subarrayBitwiseORs(vector<int>& arr) {

	set<int> ans;
	for(int i = 0; i < arr.size(); i++){
		ans.insert(arr[i]);
		for(int j = i - 1; j>=0 ; j--){
			arr[j] = arr[j] | arr[i];
			ans.insert(arr[j]);
		}
	}

	for(auto it = ans.begin(); it!=ans.end(); it++){
		cout << *it << endl;
	}
	return ans.size();
        
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n,0);
	for(int i = 0 ; i < n; i++){
		cin >> arr[i];
	}
	int ans = subarrayBitwiseORs(arr);

	cout << ans << endl;







}