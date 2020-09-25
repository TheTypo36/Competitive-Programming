#include<bits/stdc++.h>
using namespace std;
char* uniqueChar(char *str){
    // Write your code here
	unordered_set<char> s;
	for(int i = 0; str[i]!='\0'; i++){
		s.insert(str[i]);
    }
    char* ans = new char[100000];
    unordered_set<char>::iterator it;
    int j = 0;
  for(int i = 0 ; i < strlen(str); i++){
      if(s.find(str[i])==s.end()){
	continue;
      }
      			ans[j] = str[i];
      				j++;
				s.erase(str[i]);
  }
    ans[j] = '\0';
    return ans;
    
    
}
int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
