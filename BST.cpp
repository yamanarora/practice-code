#include<iostream>
using namespace std;

struct tree_node
{
  int val;
  tree_node *left,*right;
};

tree_node* create_node(int val)
{
  tree_node *newnode = new tree_node;
  newnode->val=val;
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;
}

class BST
{
  tree_node *root;

public:
  BST()
  {
    root=NULL;
  } 
  void insert(int val);
  tree_node *insert_helper(tree_node *node, int val);
  tree_node *search(int val);
  tree_node *search_helper(tree_node *node,int val);
  void print_BST();
  void inorder(tree_node *node);
  void delete_node(int val);
  tree_node* delete_Util(tree_node* node,int val);
  tree_node* find_min(tree_node *node);
};

void BST::insert(int val)
{
  root=insert_helper(root,val);
}

tree_node* BST::insert_helper(tree_node *node, int val)
{
  if(!node)
    return create_node(val);
  if(val<node->val)
    node->left = insert_helper(node->left,val);
  else
    node->right = insert_helper(node->right,val);
  return node;
}

tree_node* BST::search(int val)
{
  return search_helper(root,val);
}

tree_node* BST::search_helper(tree_node *node,int val)
{
  if(!node)
    return NULL;
  if(node->val==val)
    return node;
  if(val<node->val)
    return search_helper(node->left,val);
  return search_helper(node->right,val);
}

void BST::print_BST()
{
  inorder(root);
  cout<<endl;
} 

void BST::inorder(tree_node *node)
{
  if(!node)
    return;
  inorder(node->left);
  cout<<node->val<<" ";
  inorder(node->right);
} 

void BST::delete_node(int val)
{
  root = delete_Util(root,val);
}

tree_node* BST::delete_Util(tree_node *node,int val)
{
  if(!node)
    return NULL;

  if(val<node->val)
    node->left = delete_Util(node->left,val);
  else if(val>node->val)
    node->right = delete_Util(node->right,val);
  else
  { 
    if(!node->left&&!node->right)
    {   
      delete node;
      node = NULL;
    }
    else if(!node->left)
    {
      node = node->right;
    } 
    else if(!node->right)
    {
      node = node->left;
    } 
    else
    {
      tree_node *temp = find_min(node->right);
      node->val = temp->val;
      node->right = delete_Util(temp,temp->val);
    }  
  }  
  return node;
}

tree_node* BST::find_min(tree_node *node)
{
  while(node->left)
    node = node->left;
  return node;
}


int main()
{ 
  int n;
  cin>>n;
  BST bst;
  // 1 --> insert
  // 2 --> search
  // 3 --> print inorder traversal
  // 4 --> delete node
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
      bst.insert(val);
    } 
    else if(x==2)
    { 
      int val;
      cout<<"enter value to be searched:\n";
      cin>>val;
      tree_node *temp=bst.search(val);

      if(temp)
        cout<<temp->val<<endl;
      else
        cout<<-1<<endl;
    } 
    else if(x==3)
      bst.print_BST();
    else
    {
      int val;
      cout<<"enter value to be deleted:\n";
      cin>>val;
      bst.delete_node(val);
      bst.print_BST();
    }    
  } 
  return 0;
}
