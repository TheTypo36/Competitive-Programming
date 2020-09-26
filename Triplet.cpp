// arr - input array
// size - size of array
// x - sum of triplets
#include<iostream>
#include<algorithm>
using namespace std;
void FindTriplet(int arr[], int size, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
	 sort(arr,arr+size);
    for(int i = 0 ; i < size; i++){
        int k = x-arr[i];
        int start = i+1;
    	int end = size - 1;
        while(start  < end){
            if(arr[start]+arr[end] == k){
                int count1 = 1;
                for(int p = start+1; p<=end; p++){
                    if(arr[p]==arr[start])
                        count1++;
                    else
                        break;
                }
                int count2 = 1;
                    for(int p = end-1; p>=start; p--){
                        if(arr[end] == arr[p])
                            count2++;
                        else
                            break;
                    }
                int combination = count1 * count2;
                if(arr[start] == arr[end]){
                    combination = (((end - start)+1)*(end - start)) /2;
                }
                while(combination--){
                cout << arr[i] << " " << arr[start] << " " << arr[end] << endl;
                }
               start+=count1;
                end-=count2;

            }else if(arr[start] + arr[end] > k){
                end--;
            }else{
                start++;
            }
        }
    }
}
int main() {

	int size;

	int x;
	cin>>size;
	
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;

	FindTriplet(input,size,x);
		
	return 0;
}