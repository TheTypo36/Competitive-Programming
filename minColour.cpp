#include <bits/stdc++.h>
using namespace std;
class rgb{
public:
	int red;
	int green;
	int blue;

	rgb(int red,int green, int blue){
		this->red = red;
		this->green = green;
		this->blue = blue;
	}
};
int main(){
	int n;
	cin >> n;
	std::vector<rgb> v(n);
	for (int i = 0; i < n; ++i)
	{
		int r,g,b;
		cin >> r >>g >> b;
		rgb input(r,g,b);
		v.push_back(input);
	}
	
}