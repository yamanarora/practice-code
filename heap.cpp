#include<iostream>
#include<vector>
using namespace std;

class heap
{
	vector<int> v;
	int size;
public:
	heap()
	{
		v.clear();
		size = 0;
	}
	heap(vector<int> v1); //initializing heap with a vector
	void insert(int x);
	void delete_min();
	int extract_min();
	void build_heap();
	void down_heapify(int i);
	void up_heapify(int i);
};

heap::heap(vector<int> v1)
{
	v = v1;
	size = v.size();
	build_heap();
}

void heap::build_heap()
{
	int i = size/2-1;
	while(i>=0)
	{
		down_heapify(i);
	}	
}

void heap::down_heapify(int i)
{
	int left = 2*i+1;
	int right = 2*(i+1);
	int smallest = i;
	if(left<size&&v[left]<v[smallest])
		smallest = left;
	if(right<size&&v[right]<v[smallest])
		smallest = right;
	if(smallest!=i)
	{
		swap(v[smallest],v[i]);
		down_heapify(smallest);
	}	
}

void heap::up_heapify(int i)
{
	int parent = (i-1)/2;
	if(parent>=0&&v[parent]>v[i])
	{
		swap(v[parent],v[i]);
		up_heapify(parent);
	}	
}

void heap::insert(int x)
{
	v.push_back(x);
	size++;
	up_heapify(size-1);
}

int heap::extract_min()
{
	if(size==0)
	{
		cout<<"heap is Empty\n";
		return -1;
	}

	int minimum = v[0];
	swap(v[0],v[size-1]);
	v.erase(v.begin()+size-1);
	size--;

	down_heapify(0);

	return minimum;
}

void heap::delete_min()
{
	if(size==0)
	{
		cout<<"heap is Empty\n";
		return;
	}
	
	swap(v[0],v[size-1]);
	v.erase(v.begin()+size-1);
	size--;

	down_heapify(0);
}

int main()
{ 
  int n;
  cin>>n;
  heap hp;
  // 1 --> insert
  // 2 --> extract_min
  // 3 --> delete_min
  for(int i=0;i<n;i++)
  {
    int x;
    cout<<"enter operation num:\n";
    cin>>x;
    if(x==1)
    { 
      int val;
      cout<<"enter value to be inserted:\n";
      cin>>val;
      hp.insert(val);
    } 
    else if(x==2)
      cout<<hp.extract_min()<<endl;	
    else if(x==3)
      hp.delete_min();
  } 
  return 0;
}
