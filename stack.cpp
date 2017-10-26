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

class Stack
{
	node *top;

public:
	Stack()
	{
		top=NULL;
	}
	void push(int x);
	int pop();
	bool isEmpty();
};

bool Stack::isEmpty()
{
	if(!top)
		return 1;
	return 0;
}

void Stack::push(int x)
{
	if(isEmpty())
	{
		top = create_node(x);
		return;
	}	

	node *temp = create_node(x);
	temp->next = top;
	top = temp;
}

int Stack::pop()
{
	if(isEmpty())
	{
		cout<<"Error: Stack is empty\n";
		return -1;
	}

	int x = top->val;
	top = top->next;
	return x;
}

int main()
{	
	int n;
	cin>>n;
	Stack s;
	// 1 --> push
	// 2 --> pop
	for(int i=0;i<n;i++)
	{
		int x;
		cout<<"enter operation num:\n";
		cin>>x;
		if(x==1)
		{	
			int val;
			cout<<"enter value to be pushed:\n";
			cin>>val;
			s.push(val);
		}	
		else
		{	
			cout<<s.pop();
		}		
	}	
	return 0;
}