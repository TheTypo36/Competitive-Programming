#include <bits/stdc++.h>
using namespace std;
#define size 1025
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, x;
	cin >> n >> k >> x;
	vector<int> rangers(size, 0);
	for (int i = 0; i < n; ++i)
	{
		int strength;
		cin >> strength;
	 	rangers[strength]++;
	}
	vector<int> ans(size, 0);
	for (int i = 0; i < k; ++i)
	{
		for (int i = 0; i <= 1024; ++i)
		{
			ans[i] = 0;
		}
		int sum = 0;
		int j;
		for ( j = 0; j <= 1024; ++j)
		{
			if (rangers[j]>0){
                int index = j ^ x;
                if (rangers[j] % 2 == 0){
                    ans[index] += (rangers[j]/2);
                    ans[j] += (rangers[j]/2);
                }
                else if(rangers[j] % 2 != 0){
                    if (sum %2 == 0){
                        ans[index] += ( (rangers[j] /2) + 1);
                        ans[j] += (rangers[j] / 2);
                    }else{
                        ans[index]+= (rangers[j] /2);
                        ans[j] += ((rangers[j]/2)+ 1);
                    }
                }
                sum += rangers[j];
                }
		
			}
			for(int i = 0 ; i <= 1024; i++)
			{
				rangers[i] = ans[i];
			}
	}


	for (int i = size-1; i >=0 ; --i)
	{
		if(ans[i] != 0){
			cout << i << " ";
			break;
		}	
	}
	for (int i = 0; i < size; ++i)
	{
		if(rangers[i] != 0){
			cout << i << endl;
			break;
		}
	}

	
}