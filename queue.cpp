#include<iostream>
using namespace std;

struct node
{
	int val;
	node *next;
};

node* create_node(int x)
{
	node *temp = new node;
	temp->val=x;
	temp->next=NULL;
	return temp;
}

class queue
{
	node *front,*rear;

public:
	queue()
	{
		front=NULL;
		rear=NULL;
	}
	void enqueue(int x);
	void dequeue();
	int front_ele();
	bool isEmpty();
};

bool queue::isEmpty()
{
	if(!rear)
		return 1;
	return 0;
}

void queue::enqueue(int x)
{
	if(isEmpty())
	{
		rear = create_node(x);
		front = rear;
		return;
	}	

	rear->next = create_node(x);
	rear = rear->next;
}

void queue::dequeue()
{
	if(isEmpty())
	{
		cout<<"Error: queue is empty\n";
		return;
	}

	front = front->next;
	if(!front)
		rear = NULL;
}

int queue::front_ele()
{
	if(isEmpty())
	{
		cout<<"Error: queue is empty\n";
		return -1;
	}	
	return front->val;
}

int main()
{	
	int n;
	cin>>n;
	queue q;
	// 1 --> enqueue
	// 2 --> dequeue
	// 3 --> print front element
	for(int i=0;i<n;i++)
	{
		int x;
		cout<<"enter operation num:\n";
		cin>>x;
		if(x==1)
		{	
			int val;
			cout<<"enter value to be enqueued:\n";
			cin>>val;
			q.enqueue(val);
		}	
		else if(x==2)
		{	
			int val;
			q.dequeue();
		}	
		else
			cout<<q.front_ele();	
	}	
	return 0;
}