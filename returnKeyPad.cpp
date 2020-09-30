#include <bits/stdc++.h>
using namespace std;
string key(int n){
	
	switch(n){
	case 2:
		return "abc";
		break;
	case 3:
		return "def";
		break;
	case 4:
		return "ghi";
		break;
	case 5:
		return "jkl";
		break;
	case 6:
		return "mno";
		break;
	case 7:
		return "pqrs";
		break;
	case 8:
		return "tuv";
		break;
	case 9:
		return "wxyz";
		break;
	default:
		return "";
		break;
	}
}
void printKeypad(int n, string ans){
	if(n==0){
		cout << ans << endl;
		return ;
	}
	string s = key(n%10);
	for (int i = 0; i < s.length(); ++i)
	{
		printKeypad(n/10,s[i]+ans);
	}

}
int keypad(int n, string* output){
	if(n == 0 || n == 1){
		output[0] = "";
		return 1;
	}

	int recur = keypad(n/10,output);
	int k = n % 10;
	string str = key(k);
	int p = recur;
	for (int i = 0; i < str.length(); ++i)
	{
		for (int j = 0; j < recur; ++j)
		{
			output[p] = output[j] + str[i];
			p++;	
		}
		
	}
	for(int i = recur ; i < p; i++){
		output[i-recur] = output[i];
	}
	return p - recur;


}

int main(){
    int num;
    cin >> num;
/*
    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
  */
    printKeypad(num,"");
    return 0;
}
