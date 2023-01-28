#include <iostream>
#include<sstream> 
#include<string> 
using namespace std;

int main(){

int i,j;
int count = 1;

int max = 1;
string nums;


while(getline(cin,nums))
{
	// cout<<nums;
	stringstream ss(nums); 
	ss >>i >> j;

	// cout<<i<<" --- "<<j<<endl;
	bool swapped = false;
	if (i>j)
	{
		int t = i;
		i = j;
		j = t;
		swapped = true;
	} 
	for (int x = i; x<=j; x++)
	{
		count =1;
		int n = x;
		while(n != 1)
		{
		if (n%2 == 0)
			n /=2;
		else
			n = (n*3)+1;
		count++;
		}
		// cout << count;
		if (count > max)
			max = count;
		count= 1;
	}
	if (swapped)
	{
		int t = i;
		i = j;
		j = t;
	}
	cout<<i<<" "<<j<<" "<<max<<endl;
	max =0;
}

// cout<<max;
return 0;
}