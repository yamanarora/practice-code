#include<bits/stdc++.h>
using namespace std;


int bsearch(int arr[],int l, int r,int x)
{
	if(r<l)
		return -1;
	int mid = l + (r-l)/2;

	if(arr[mid]==x)
		return mid;
	if(arr[mid]>x)
		return bsearch(arr,l,mid-1,x);
	return bsearch(arr,mid+1,r,x);
}
int main()
{	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int x;//element to be found
	cin>>x;
	sort(arr,arr+n);//sort the array
	cout<<bsearch(arr,0,n-1,x);
	return 0;
}