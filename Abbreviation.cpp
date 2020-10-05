#include <bits/stdc++.h>
using namespace std;

void abbr(string word,string ans,int count){
	if(word.length() == 0){
		if(count != 0){
			ans =ans+to_string(count) ;
			cout << ans << endl;
		}else{
			cout << ans << endl;
		}
		return ;

	}
	if(count>0){
		abbr(word.substr(1),ans+to_string(count)+word[0],0);
	}else{
		abbr(word.substr(1),ans+word[0],0);
	}
		abbr(word.substr(1),ans,count+1);
	
}
int main(){
	string n;
	cin >> n;
	abbr(n,"",0);
}