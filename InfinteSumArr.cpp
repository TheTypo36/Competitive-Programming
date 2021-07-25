#include <bits/stdc++.h>
using namespace std;

 int mod = 1000000007;

long long sumTillX(vector<long long> &sumOfarr, long long r, int n ){
    
    long long count = (r/n)%mod;
    long long partialSum = (count*sumOfarr[n])%mod;
    //cout << partialSum << endl;
    long long remSum = (sumOfarr[r%n]);
   // cout << remSum << endl;
   	
    
    return ((partialSum + remSum)%mod);
   //cout << sumTillr <<endl;
  
    
}

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    // Write your code here
 	vector<int> ans;
    vector<long long> sumOfarr(n+1,0);
    	
    for(int i = 1; i <= n; i++){
        sumOfarr[i] = (sumOfarr[i-1]+arr[i-1])%mod;
        
    }
   

    for(int query = 0 ; query<q; query++){
    	long long l =  queries[query][0]-1;
        long long r =  queries[query][1];
    	long long sum = 0;
        
       // cout << "sumOfarr: " << sumOfarr << endl;
		long long sumTillR = sumTillX(sumOfarr,r,n);
       // cout << "sum Till R: " << sumTillr << endl;
        
        long long sumTillL = sumTillX(sumOfarr,l,n);
       // cout << "sum Till L: " << sumTilll<< endl;
        
        sum = (sumTillR - sumTillL+mod)%mod;
            //cout << sumTillr << " - "<<sumTilll<< " = "<< sum << endl;
        	
        ans.push_back((int)(sum%mod));
    }
    //cout << endl;
    return ans;
    
}

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int testcases;
	cin >> testcases;
	while(testcases--){
		int n;
		cin >> n;
		vector<int> arr(n,0);
		for(int i = 0 ;i < n; i++){
			cin >> arr[i];
		}
		
		int q;
		cin >> q;

		vector<vector<long long>> queries(q,vector<long long>(2,0));
		for(int i = 0 ; i < q; i++){
			int l , r;
			cin >> l >> r;
			queries[i][0] = l;
			queries[i][1] = r;
		}

		vector<int> ans = sumInRanges(arr,n,queries,q);

		for(int i = 0 ; i < ans.size(); i++){
			cout << ans[i] << " " ;
		}

	}

}