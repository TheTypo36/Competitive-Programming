//Knuth morris pratt
#include <bits/stdc++.h>
using namespace std;

int* Lps(string pattern){
	int len = pattern.length();
	int* lps = new int[len];
	lps[0] = 0;
	int j=0,i=1;
	while(i<len){
		if(pattern[i] == pattern[j]){
			lps[i] = j+1;
			i++;
			j++;
		}else{
			if(j!=0){
				j = lps[j-1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}
bool KMPsearch(string text, string pattern){
	int textlen = text.length();
	int patternlen = pattern.length();

	int i = 0 , j = 0;
	int* lps = Lps(pattern);

	while(i < textlen && j < patternlen)
	{
		cout << i <<" " << j << endl; 
		if(text[i] == pattern[j]){
			i++;
			j++;
		}else{
			if(j!=0){
				j = lps[j-1];
			}else{
				i++;
			} 
		}
	}

	if (patternlen == j){
		return true;
	}
	
		return false;
	

	
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	string text,pattern;
	cin >> text >> pattern;
	
	bool ans = KMPsearch(text,pattern);
	if(ans==true){
		cout << "Yes" << endl;
	}else{ 
		cout << "No" << endl;
	}
	return 0;
	


}