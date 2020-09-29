#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
		ll n;
		cin >> n;
		ll* shops = new ll[n];
				ll sum = 0;

    for (ll i = 0; i < n; ++i)
		{
			int input;
        cin >> input;
        sum+=input;
         shops[i] = sum;
		}
	
		
		ll q; 
		cin >> q;
		while(q--){
			ll x ;
			cin >> x;
            if(x < shops[0]){
                cout << 0 << " " <<x << endl;
                continue;
            }
			ll low = 0; 
			ll high = n - 1;
                ll ans = -1 ;

			while(low <= high)
			{
				ll mid = (low + high) / 2;
				
				if(shops[mid]<=x){
					ans = mid;
						low = mid + 1;
				}else{

					high = mid - 1;
				
				}
			}
            cout << ans + 1 << " " << x- shops[ans] << endl;
		}
	
	return 0;
}