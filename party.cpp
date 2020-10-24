#include <bits/stdc++.h>
using namespace std;
pair<int,int> Costing(int* partiesFee,int * enjoyment, int parties, int budget)
{
	pair<int,int>** dp = new pair<int,int>*[parties+1];
	for (int i = 0; i < parties + 1; ++i)
	{
		dp[i] = new pair<int,int>[budget + 1];
		for (int j = 0; j < budget + 1; ++j)
		{
			dp[i][j].first = 0;
			dp[i][j].second = 0;
		}
	}
	for(int i = 1; i < parties + 1; i++)
	{
		for(int j = 1 ; j < budget + 1; j++)
		{
		 	if(partiesFee[i-1] > j)
		 	{
		 		dp[i][j] = dp[i-1][j];
		 	}else{
		 		pair<int,int> option1 = dp[i-1][j];
		 		pair<int,int> option2 = dp[i-1][j-partiesFee[i-1]];
		 		option2.first += partiesFee[i-1];
		 		option2.second += enjoyment[i-1];
		 		if(option2.second > option1.second)
		 		{
		 			dp[i][j] = option2;
		 		}else{
		 			dp[i][j] = option1;
		 		}
		 	}
		}
	}
	pair<int,int> ans = dp[parties][budget];
	for (int i = 0; i < parties + 1; ++i)
	{
		delete dp[i];
	}
	delete []dp;
	return ans;

}
pair<int,int> Costing_recur(int* partiesFee,int* enjoyment, int parties, int budget){
	if(budget == 0 || parties == 0){
		pair<int,int> baseAns ;
		baseAns.first = 0;
		baseAns.second = 0 ;
		return baseAns; 
	}

	if(budget < partiesFee[parties - 1]){
		return Costing_recur(partiesFee,enjoyment, parties - 1, budget);
	}else{
		pair<int,int> option1 = Costing_recur(partiesFee,enjoyment,parties-1,budget);
		pair<int,int> option2 = Costing_recur(partiesFee,enjoyment,parties - 1, budget - partiesFee[parties-1]);
		option2.first += partiesFee[parties-1];
		option2.second += enjoyment[parties-1];
		if(option2.second >= option1.second){
			return option2;
		}else{
			return option1;
		}
	}
}
int main(){
	
	while(true){
		int budget, parties;
		cin >> budget >> parties;
		if(budget == 0 && parties == 0){
			break;
		}
		int * partiesFee = new int[parties];
		int *enjoyment = new int[parties];
		for (int i = 0; i < parties; ++i)
		{
			cin >> partiesFee[i] >> enjoyment[i];	
		}
		pair<int,int > ans = Costing(partiesFee,enjoyment, parties, budget);
		cout << ans.first << " " << ans.second << endl;
		
	}
	return 0;
}