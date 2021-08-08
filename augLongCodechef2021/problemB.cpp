#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define F first
#define S second
typedef long long ll;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		// int a1,a2,a3,a4;
		// cin >> a1 >> a2 >> a3 >> a4;

		// int problemSet = 0;
		// if(a1!=a2){
		// 	problemSet++;
		// }
		//  if(a3!=a1&&a3!=a2&& a4!=a1&&a4!=a2&&a4!=a3){
		// 	problemSet++;
		// }
		// cout << problemSet << endl;

		// // set<int> s;
		// // s.insert(a1);
		// // s.insert(a2);
		// // s.insert(a3);
		// // s.insert(a4);

		// // cout << s.size()/2 << endl;
		vector<int> difficulties(4,0);
		cin >> difficulties[0];
		cin >> difficulties[1];
		cin >> difficulties[2];
		cin >> difficulties[3];
		sort(difficulties.begin(),difficulties.end());

		if(difficulties[0]==difficulties[1]&&difficulties[1]==difficulties[2]&&difficulties[2]==difficulties[3]){
			cout << 0 << endl;
		}else if((difficulties[0]==difficulties[1]&&difficulties[1]==difficulties[2])||(difficulties[1]==difficulties[2]&&difficulties[2]==difficulties[3])){
			cout << 1 << endl;
		}else{
			cout << 2 << endl;
		}

	}
	return 0;
}