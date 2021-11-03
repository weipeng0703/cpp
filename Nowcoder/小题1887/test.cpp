#include<bits/stdc++.h>
using namespace std;

int main()
{
	bool first=true;
	int sum=0;
	int value;
	unsigned short i=0xFFFF;
	for (;i>=0;--i)
	{
		if (first)
		{
			value=65536;
			sum+=value%3;
			first=false;
		}
		else{
			sum+=--value%3;
			if (value<=0)
			{
				cout<<sum<<","<<i;
				break;
			}
		}
	}
	return 0;
}
