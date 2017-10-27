#include<iostream>
using namespace std;

void merge(int arr[],int l,int r,int mid)
{
	int i=l;
	int j=mid+1;
	int k=0;
	int temp[r-l+1];
	while(i<=mid&&j<=r)
	{
		if(arr[i]<arr[j])
		{
			temp[k]=arr[i];
			i++;
		}	
		else
		{
			temp[k]=arr[j];
			j++;
		}	
		k++;
	}		

	while(i<=mid)
	{
		temp[k]=arr[i];
		k++;i++;
	}	

	while(j<=r)
	{
		temp[k]=arr[j];
		k++;j++;
	}	

	for(int i=0;i<r-l+1;i++)
	{
		arr[i+l]=temp[i];
	}	
}

void merge_sort(int arr[],int l,int r)
{
	if(l==r)
		return;
	int mid = l+(r-l)/2;
	merge_sort(arr,l,mid);
	merge_sort(arr,mid+1,r);

	merge(arr,l,r,mid);
}

int main()
{	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	merge_sort(arr,0,n-1);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
