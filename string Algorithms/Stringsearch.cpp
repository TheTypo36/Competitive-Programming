#include <bits/stdc++.h>
using namespace std;
int* Lps(char t[]){
    int len = strlen(t);
    int* lps = new int[len];
    lps[0] = 0;
    int i = 1, j = 0;
    while(i < len){
        if(t[i] == t[j]){
            lps[i] = j + 1;
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
int findString(char S[], char T[]) {
    // Write your code here
	int slen = strlen(S);
    int tlen = strlen(T);
    
    int i = 0 , j = 0;
    
    int* lps = Lps(T);
    while(i < slen && j < tlen){
        if(S[i] == T[j]){
            i++;
            j++;
        }else{
            if(j!=0){
                j= lps[j-1];
            }else{
                i++;
            }
        }
    }
    if(j==tlen){
        return (i-j);
    }
    
    return -1;
}

int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}