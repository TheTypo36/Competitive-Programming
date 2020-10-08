#include <bits/stdc++.h>
using namespace std;

int minCost(int n,string s1, string s2){
	
	int ans = 0;
	for(int i = 0 ; i < n;i++ ){
		if(s1[i]==s2[i]){
			continue;
		}else{
			if(i+1 < n&&s1[i]!=s1[i+1]&&s1[i+1]!=s2[i+1]){
				ans++;
				i++;
			}
			else if(s1[i]!=s2[i]){
				ans++;
			}
		}
	}
	return ans;
}
int main(){
	int n;
	cin >> n;
	string s , s2;
	cin >> s >> s2;
	cout << minCost(n,s,s2) << endl;
}