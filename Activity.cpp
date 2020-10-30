#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> interval1, pair<int,int> interval2){
	return interval2.second < interval2.second;
}
int main(){
	int n;
	cin >> n;
	pair<int,int>* input = new pair<int,int>[n];
	for(int i = 0; i < n; i++)
	{
		int first, second;
		cin >> first >> second;
		input[i].first = first;
		input[i].second = second;
	}
	sort(input, input + n,compare);
	int count = 1 ;
	int curr_ending = input[0].second;
	for (int i = 1; i < n; ++i)
	{
		if(curr_ending <= input[i].first)
		{
			count++;
			curr_ending = input[i].second;
		}
	}
	cout << count << endl;
}