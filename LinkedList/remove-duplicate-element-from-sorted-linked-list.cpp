// { Driver Code Starts
//https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
#include <bits/stdc++.h>
using namespace std;
Node* keepXRemoveY(struct Node* head,int x,int y)
{
	
	Node* temp=new Node("dummy",0);
	Node* ans=temp;
	temp->next=head;
	while(temp!=nullptr)
	{
	
	for(int i=0;i<x;i++)
	{
		if(temp==nullptr)
		return ans->next;
		temp=temp->next;
	}
	Node* temp2=temp;
	for(int i=0;i<y;i++)
	{
		if(temp==nullptr)
		{
			temp2->next=nullptr;
			return ans->next;
		}
		temp=temp->next;
	}	
	temp2->next=temp;
}
return ans;
}

// root: head node

