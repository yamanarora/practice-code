#include<iostream>
using namespace std;

struct node
{	
	int val;
	node *next;
};

class linked_list
{
	node *head;
public:

	linked_list(int x)
	{	
		head = create_node(x);
	}
	~linked_list();
	node* create_node(int x);
	void add_node(int x);
	void delete_node(int x);
	void print_list();
};

node* linked_list::create_node(int x)
{
	node *temp = new node;
	temp->val=x;
	temp->next=NULL;
	return temp;
}

void linked_list::add_node(int x)
{
	node *newnode=create_node(x);
	newnode->next=head;
	head=newnode;
}

void linked_list::delete_node(int x)
{	
	if(!head)
		return;
	if(head->val==x)
	{
		head=head->next;
		return;
	}	

	node *curr=head->next;
	node *prev=head;
	while(curr)
    {
    	if(curr->val==x)
    	{
    		prev->next=curr->next;
    		delete curr;
    		return;
    	}
    	prev=curr;
    	curr=curr->next;	
    }		
}

void linked_list::print_list()
{
	node *curr=head;
	while(curr)
	{
		cout<<curr->val<<" ";
		curr=curr->next;
	}
	cout<<endl;
}

linked_list::~linked_list()
{
	node *ptr=head;
	while(ptr)
	{
		node *temp=ptr;
		ptr=ptr->next;
		delete temp;
	}		
}

int main()
{	
	linked_list ll(5);
	//num of operations
	int n;
	cin>>n;
	// 1 --> add_node
	// 2 --> delete_node
	// 3 --> print_list
	for(int i=0;i<n;i++)
	{
		int x;
		cout<<"enter operation num:\n";
		cin>>x;
		if(x==1)
		{	
			int val;
			cout<<"enter value to be added:\n";
			cin>>val;
			ll.add_node(val);
		}	
		else if(x==2)
		{	
			int val;
			cout<<"enter value to be deleted:\n";
			cin>>val;
			ll.delete_node(val);
		}	
		else
			ll.print_list();	
	}	
	return 0;
}
