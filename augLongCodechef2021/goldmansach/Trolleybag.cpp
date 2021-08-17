#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define F first
#define S second
typedef long long ll;

using namespace std;

string resultantSecretCode(string S){
	string res="";
	for(int i = 0 ; i < S.size(); i++){
		if(S[i]==S[i+1]){
			i++;
		}
			res+=S[i];
	}
	return 	res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	string S;
	cin >> S;
	cout << resultantSecretCode(S);
	return 0;
}