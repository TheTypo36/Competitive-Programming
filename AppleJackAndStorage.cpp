#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define F first
#define S second
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n,0);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	unordered_map<int,int> freq;
	for(int i = 0; i < n; i++){
		freq[v[i]]++;
	}
	int queries ;
	cin >> queries;
	while(queries--){
		int query;
		char sign;
		cin >> sign;
		cin >> query;

		if(sign=='+')
			freq[query]++;
		else
			freq[query]--;

		int fourFeq = 0;
		int twoFeq = 0;
		for(unordered_map<int,int>::iterator it = freq.begin(); it!= freq.end(); it++){
				if(it->S >= 4){
					fourFeq= fourFeq+(it->S/4);
					if((it->S%4)>=2){
						twoFeq++;
					}
				}else if(it->S >= 2){
					twoFeq++;
				}
				//cout << "freq of " << it->first << " : " << it->second<<"\n";
		}
		if(fourFeq>=2){
			cout << "YES" << endl;
		}else if(fourFeq==1 && twoFeq>=2){
			cout << "YES" << endl;

		}else{
			cout << "NO" << endl;
		}
		//cout << "***************************" << "\n";

	}
	
}