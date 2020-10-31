#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class job{
public:
	int starting;
	int ending;
	int profit;

	
};
bool compare(job job1, job job2)
{
	return job1.ending < job2.ending;
}
int Maximum_Profit(job* arr, int n){
	sort(arr,arr+n,compare);
	int* maxProfit = new int[n];
	maxProfit[0] = arr[0].profit;
	for (int i = 1; i < n; ++i)
	{
		int option1 = maxProfit[i-1];
		int option2 = arr[i].profit;
		int index = -1;
	
			int low = 0 , high = i - 1;
        while( low <= high){
        	ll mid = (low + high)/2;
            if(arr[mid].ending == arr[i].starting){
                index = mid;
                break;
            }else if( arr[mid].ending > arr[i].starting){
                 high = mid - 1;
            }
            else{
            	index = mid;
                low = mid + 1;
            }
        }
		if(index!=-1){
			option2 +=maxProfit[index];
		}
		
		maxProfit[i] = max(option2,option1);
	}
	int ans = maxProfit[n-1];
	delete [] maxProfit;
	return ans;
}
int main(){
	int n;
	cin >> n;
	job* arr = new job[n];
	for (int i = 0; i < n; ++i)
		{
			cin >> arr[i].starting >> arr[i].ending>> arr[i].profit;
		}	
	cout << Maximum_Profit(arr, n);
}