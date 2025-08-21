#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int arr[7];
	for(int i=0;i<7;i++)
	{
	    cin>>arr[i];
    	
	}
	
	for(int i=0;i<7;i++)
	{
	    for(int j=i+1;j<7;j++)
	{
	    if(arr[j]>arr[0])
	    arr[0]=arr[j];
	}
	
	}
	cout<<arr[0];

}
