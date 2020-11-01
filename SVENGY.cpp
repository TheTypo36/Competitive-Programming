#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
		ll n;
		cin >> n;
		ll* arr = new ll[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		//sort(A,A+n);
		ll energy = 0 ;
		ll i = 0;
		
		while(i < (n - 1)){
			ll j = i + 1;
			while(j < (n-1))
			{
				if((abs(arr[i])>abs(arr[j]))||((abs(arr[i])==abs(arr[j]))&&(arr[i]>0))){
					
					break;
				}else{
				j++;
				}
			}
			energy += ((j-i)*arr[i] +(j*j - i*i)*(arr[i]*arr[i]));
					i= j;
		}
	cout << energy << endl;
	return 0;
}