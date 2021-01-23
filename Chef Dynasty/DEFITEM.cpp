#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int queries;
		cin >> queries;
		vector<int> vec(n,0);
		for (int i = 0; i < n; ++i)
		{
			cin >> vec[i];
		}
		unordered_map<int,pair<int,int>> pos;
		int back=0,front=0;
		for (int i = 0; i < n; ++i)
		{
			
		    back+=vec[i];
            //front+=vec[n-1-i];
            

			pos[vec[i]].first=back;
		}
		for(int i = n-1; i >= 0; i--){
			front+=vec[i];
			pos[vec[i]].second=front;
		}
		//unordered_map<int,pair<int,int>>::iterator it;
		// for(auto it = pos.begin(); it!=pos.end();it++){
		// 	auto secondPart = it->second;
		// 	cout <<it->first<<":"<< secondPart.first<<" "<< secondPart.second << endl;
		// }
		while(queries--){
			int q;
			cin >> q;
			pair<int,int> ans = pos[q];
			cout <<min(ans.first,ans.second) << endl;
			//cout << "max:"<<max(ans.first,ans.second) << endl;

		}
	}
}