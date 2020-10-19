#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void conIntoAscii(string s,int* input, int n){
	for (int i = 0; i < n; ++i)
	{
		input[i] = (int)s[i];
	}
	//cout << input[0] << endl;
	return;
}
string funnyOrNOt(string s, string rev){
	int* AsciiValueS = new int[s.length()];
	int* AsciiValueRev = new int[rev.length()];
	conIntoAscii(s,AsciiValueS,s.length());
	conIntoAscii(rev,AsciiValueRev,rev.length());
	// for (int i = 0; i < s.length(); ++i)
	// {
	// 		cout <<AsciiValueS[i] << " " ;
	// }
	// cout << endl;
	// for (int i = 0; i < s.length(); ++i)
	// {
	// 	cout << AsciiValueRev[i] << " ";
	// }
	// cout << endl;
	for (int i = 0; i < s.length(); i+=2)
	{
		if(i+1 < s.length()){
			int diff1= abs(AsciiValueRev[i] - AsciiValueRev[i+1]);
			int diff2 = abs(AsciiValueS[i] - AsciiValueS[i+1]);
			if(diff1 != diff2){
				return "Not Funny";
			}
		}
	}
	return "Funny";
}
string reverse(string s){
	string rev = "";
	for (int i = s.length() - 1; i>=0; --i)
	{
		rev = rev + s[i];
	}
	//cout << rev << endl;
	return rev;
}
int main()
{
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		string s;
		cin >> s;
		string rev = reverse(s);
		cout << funnyOrNOt(s,rev) << endl;
	}
	return 0;
}