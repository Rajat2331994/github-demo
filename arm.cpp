#include<iostream>
using namespace std;

int main()
{
	int arm,n,i=0;
	cout<<"enter no. to know The armstrong";
	cin>>arm;
	while(arm!=0)
	{
		n=arm%10;
		i=i+n*n*n;
		arm=arm/10;
	}
	
	if(arm==i)
	{
		cout<<"number is armstrong";
	}
	
	else
	{
	cout<<"number is not";
    }
	
}

