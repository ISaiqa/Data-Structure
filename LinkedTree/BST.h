#include<iostream>
#include"TreeNode.h"
using namespace std;

template <class T>
class BST
{
	private:
		TreeNode<T> *root;
	public:
		BST()
		{
			this->root=0;
		}
		void insert(T element);
		TreeNode<T>* getRoot();
		
		void preOrderTraversal(TreeNode<T>* t_root);
		void inOrderTraversal(TreeNode<T>* t_root);
		void postOrderTraversal(TreeNode<T>* t_root);
		TreeNode<T>* search(T element);
		TreeNode<T>* getParent(T element);
		
		TreeNode<T>* successor (TreeNode<T> *t_root);
		TreeNode<T>* predecessor(TreeNode<T> *t_root);
		TreeNode<T>* getChild (TreeNode<T> *t);
		TreeNode<T>* recursiveDelete(TreeNode<T>*t_root,T element);
		TreeNode<T>* minValue();
		TreeNode<T>* maxValue();
};
template <class T>
TreeNode<T>* BST<T>::minValue()
{
	TreeNode<T> *i=root;
	while(i->getLeft()!=0)
	{
		i=i->getLeft();
	}
	return i;
}
template <class T>
TreeNode<T>* BST<T>::maxValue()
{
	TreeNode<T> *i=root;
	while(i->getRight()!=0)
	{
		i=i->getRight();
	}
	return i;
}

template <class T>
TreeNode<T>* BST<T>::recursiveDelete(TreeNode<T>*t_root,T element)
{
	if (t_root==0)
	{
		return 0;
	}
	if(element<t_root->getInfo())
	{
		//deletion is possible in LST
		t_root->setLeft(recursiveDelete(t_root->getLeft(),element));
	}
	else if(element>t_root->getInfo())
	{
		//deletion is possible in RST
		t_root->setRight(recursiveDelete(t_root->getRight(),element));
	}
	else 
	{
		//element found at t_root delete it
		//case 1:t-root is a leaf node
		if (t_root->getLeft()==0 && t_root->getRight()==0)//check its leaf
		{
			delete t_root;
			return 0;
		}
		// case 2:t_root is a node with single child
		if (t_root->getLeft()==0 )//only roight child exist
		{
			TreeNode<T>* singleRight=t_root->getRight();
			delete t_root;//delete t_root and return right child
			return singleRight;		
		}
		else if(t_root->getRight()==0)
		{
			TreeNode<T>* singleLeft=t_root->getLeft();
			delete t_root;
			return singleLeft;	
		}
		
		//case 3:t-root has both child
		TreeNode<T> *ss=successor(t_root);
		t_root->setInfo(ss->getInfo());
		t_root->setRight(recursiveDelete(t_root->getRight(),ss->getInfo()));
                                          //get right brcause we are dealing with successor
	}
	return t_root; 	
}// delete
template <class T>
TreeNode<T>* BST<T>::search(T element)
{
		TreeNode<T>* temp=root;
		while(temp!=0)
		{//equal to root return the root info
			if(temp->getInfo()==element)
			{
				return temp;
			}
			//if smaller move left
			else if(element <temp->getInfo() )
			{
				temp=temp->getLeft();
			}
			//it  neither small nor equal means it is greater then root so move to right
			else 
			{
				temp=temp->getRight();
			}
		}
		cout<<"Element not foud!";
		return nullptr;
	
}
template <class T>
void BST<T>::insert(T element)
{
	TreeNode<T>* n=new TreeNode<T>(element);
	

	if(root==0)//if no root no tree already so new node would be the root
	{
		root=n;
	}
	else
	{
		//TreeNode<T>* p_temp=0;
		TreeNode<T>* temp=root;//start comparisons from root
		while(true)
	
		{
			//compare element  if smaller we check left node and if it is present we move there if not present we add new node there
			if(element <temp->getInfo())//if smaller check left node
			{
				//as no left node so move to left
				if(temp->getLeft()==0)//connect n
				{
					temp->setLeft(n);
					return;
				}
				else//node is already there process further
				{
					temp=temp->getLeft();
				}
			}
			else if(element>temp->getInfo())// if greater checkright node
			{// if right node is note there then connect
					if(temp->getRight()==0)//connect n
				{
					temp->setRight(n);
					return;
				}
				else//node is alreadyy there processe further
				{
					temp=temp->getRight();
				}
			}
			else
			{
				//if neither greater nor smaller then it is equal
				cerr<<"Duplicates are not allowed! \n";
			}
		}
	
	}
}
template <class T>
TreeNode<T>* BST<T>::getRoot()
{
	return this->root;
}
template <class T>
void BST<T>::preOrderTraversal(TreeNode<T>* t_root)
{
	if(t_root!=0)
	{
		cout<<t_root->getInfo()<<"\t";
		preOrderTraversal(t_root->getLeft());
		preOrderTraversal(t_root->getRight());
		
	}
}
template <class T>
void BST<T>::postOrderTraversal(TreeNode<T>* t_root)
{
	if(t_root!=0)
	{
	
		preOrderTraversal(t_root->getLeft());
		preOrderTraversal(t_root->getRight());
		cout<<t_root->getInfo()<<"\t";
		
	}
}
template <class T>
void BST<T>::inOrderTraversal(TreeNode<T>* t_root)
{
	if(t_root!=0)
	{
	
		preOrderTraversal(t_root->getLeft());
		cout<<t_root->getInfo()<<"\t";
		preOrderTraversal(t_root->getRight());
		
	}
}
template <class T>
TreeNode<T>* BST<T>::getParent(T element)
{
	TreeNode<T>* temp=root;
	TreeNode<T>* p_temp=0;
	while(temp->getInfo()!=element && temp!=0)
	{//either elemnt is found or we are at leaf node we need to stop
		p_temp=temp;//keep track of parent node
		//basically stay one node behind
		if(temp->getInfo()<element)
		{
			temp=temp->getLeft();
		}
		else
		temp=temp->getRight();
	}
	return p_temp;
}//get parent
template <class T>
TreeNode<T>* BST<T>:: predecessor (TreeNode<T> *t_root)
{
	if(t_root->getLeft()!=0)
	{
		TreeNode<T> *i=t_root->getLeft();
		while(i->getRight()!=0)
		{
			i=i->getRight();
		}
		return  i;
	}

	return 0;
}//find predeccessor  
template <class T>
TreeNode<T>* BST<T>:: getChild (TreeNode<T> *t)
{
	if(t->getRight()==0 && t->getLeft()==0)
	{//it is leaf node no child exist
		return 0;
	}
	else if(t->getRight()!=0&&t->getLeft()==0)
	{
		return t->getRight();
	}
	else 
		return t->getLeft();
}// get single child
template <class T>
TreeNode<T>* BST<T>::successor  (TreeNode<T> *t_root)
{
	if(t_root->getRight()!=0)
	{
		TreeNode<T> *i=t_root->getRight();
		while(i->getLeft()!=0)
		{
			i=i->getLeft();
		}
		return  i;
	}

		return 0;
}//find successor