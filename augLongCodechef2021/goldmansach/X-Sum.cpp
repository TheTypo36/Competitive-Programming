#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define F first
#define S second
typedef long long ll;

using namespace std;

int findXSum(vector<int> hist , int p){
	int xsum = 0;
	for(int i = 0 ;i < p-1; i++){
		xsum = xsum+ abs(hist[i]-hist[i+1]);
	}
	return xsum;
}
vector<int> createHistogram(vector<vector<int>> img, int p){
	vector<int> hist(p,0);
	int i = 0 ;
	while( i < p){
		int count = 0;
		int j = 0; 
		while(j < p){
			if(img[j][i] == 1){
				count++;
			}

			j++;
		}
		hist[i]=count;

		i++;
	}
	return hist;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int p , n;
	cin >> p >> n;
	vector<vector<int>> img(p, vector<int>(p,0));
	for(int i = 0; i < p ; i++){
		for(int j = 0; j < p ; j++){
			cin >> img[i][j];
		}
	}
	vector<int> hist = createHistogram(img, p);
	unordered_map<int,vector<int>> sei;
	for(int i = 0 ; i < p ; i++){
		sei[hist[i]].push_back(i);
	}
	while(n--){
		int i , replacement;
		cin >> i >> replacement;
		for (int j = 0; j < p; ++j)
		{
			if(hist[j] == i){
				hist[j] = replacement;
			}
		}
		int xsum = findXSum(hist, p);
		cout << xsum << endl;
	}

	return 0;
}