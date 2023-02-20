#include<iostream>
using namespace std;
class Node
{
	public:
	string data;
	string mean;
	Node*left,*right;
	Node()
	{

		left=NULL;
		right=NULL;
	}
	Node(string w,string m)
	{
		data=w;
		mean=m;
		left=NULL;
		right=NULL;
	}

};
class BST
{
	Node*root;
	public:
	BST()
	{
	root=NULL;
	}
	void insert(string x,string m)
	{
		Node * tempNode=new Node(x,m); //allocate memory for new item
		if(root == NULL)
		{
			root = tempNode;
		}

		else
		{
			Node *current,*parent;
			current = root;
			parent = NULL; //parent will point to parent node
			while(1)
			{
					parent = current;
					if(x < parent->data)
					{
						current = current->left;
						if(current == NULL)
						{
							parent->left = tempNode;
							return;
						}
					}
					else
					{
						current = current->right;
						if(current == NULL)
						{
							parent->right= tempNode;
							return;
						}
					}
			}
		}
	}

	Node * rootval()
	{
		return root;
	}
	void display_ascending(Node * temp)
	{
		if(temp==NULL)
		{
			return;
		}

		display_ascending(temp->left);
		cout<<"keyword : "<<temp->data<<"           meaning : "<<temp->mean<<endl;
		display_ascending(temp->right);
	}
	void display_descending(Node * temp)
	{
		if(temp==NULL)
		{
			return;
		}

		display_descending(temp->right);
		cout<<"keyword : "<<temp->data<<"           meaning : "<<temp->mean<<endl;
		display_descending(temp->left);
	}
	Node * del(Node * temp,string str)
	{
		if(temp==NULL)
		{
			return temp;
		}
		if(temp->data<str)
		{
			temp->right=del(temp->right,str);
		}
		else if(temp->data>str)
		{
			temp->left=del(temp->left,str);
		}
		else
		{
			//only one child(right child)
			if(temp->left==NULL)
			{
				Node *p=temp->right;
				delete temp;
				return p;
			}
			//only one child(left child)
			else if(temp->right==NULL)
				{
				Node *q=temp->left;
				delete temp;
				return q;
			}
			//both left and right child is present
			else
			{
				Node * ptm=getmin(temp->right);
				temp->data=ptm->data;
				temp->right=del(temp->right,ptm->data);
			}

		}
		return temp;

	}
	Node * getmin(Node *temp)
	{
		while(temp->left!=NULL)
		{
			temp=temp->left;
		}
		return temp;
	}
	Node * search(string str)
	{
		Node *current=root;
		while(current->data!=str)
		{
			if(current!=NULL)
			{
				if(current->data>str)
				{
					current=current->left;
				}
				else
				{
					current=current->right;
				}
			}
			if(current==NULL)
			{
				//cout<<"\nKEYWORD NOT FOUND"<<endl;
				return NULL;
			}
		}

		if(current!=NULL)
		{
			cout<<"\nKEYWORD FOUND"<<endl;
		}
		return current;
	}
	void update(string str)
	{
		Node *temp=search(str);
		string dataa,meann;
		cout<<"\nENTER THE UPDATED MEANING : ";
		cin>>meann;
		temp->mean=meann;
	}

};
int main()
{
	BST b;
	string str,mean;
	int t;
	Node *temp;
	while(1)
	{
	cout<<"\nENTER YOUR CHOICE :\n1 . INSERT DATA \n2 . DELETE DATA\n3 . SEARCH KEYWORD \n4 . DISPLAY DATA IN ASCENDING ORDER\n5 . DISPLAY DATA IN DESCENDING ORDER.\n6 . UPDATE DATA\n7 . EXIT "<<endl;
	int choice;
	cin>>choice;
	if(choice==7)
	{
		break;
	}
	switch(choice)
	{
	case 1:
	cout<<"\nENTER THE TOTAL NUMBER OF DATA YOU WANT TO INSERT : ";
	cin>>t;
	for(int i=0;i<t;i++)
	{
	cout<<"\nENTER THE KEYWORD : ";
	cin>>str;
	cout<<"\nENTER THE MEANING : ";
	cin>>mean;
	b.insert(str,mean);
	cout<<endl<<endl;
	}
	break;

	case 2:
	cout<<"\nENTER THE KEYWORD WHICH YOU WANT TO DELETE : ";
	cin>>str;
	temp=b.rootval();
	b.del(temp,str);

	break;

	case 3:
	cout<<"\nENTER THE KEYWORD YOU WANT TO SEARCH : ";
	cin>>str;
	b.search(str);
	break;

	case 4:
	cout<<"\nDISPLAYING DATA IN ASCENDING ORDER : "<<endl;
	temp=b.rootval();
	b.display_ascending(temp);
	break;

	case 5:
	cout<<"\nDISPLAYING DATA IN DESCENDING ORDER : "<<endl;
	temp =b.rootval();
	b.display_descending(temp);
	break;

	case 6:
	cout<<"\nENTER THE KEYWORD WHOSE MEANING YOU WANT TO UPDATE : ";
	cin>>str;
	b.update(str);
	break;
	}
	}

}
