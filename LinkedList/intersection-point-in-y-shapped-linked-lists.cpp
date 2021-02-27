// { Driver Code Starts
//https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#
#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    if(head1==NULL||head2==NULL)
    return -1;
    if(head1==head2)
    return head1->data;
    int k1=1,k2=1;
    Node *temp1=head1,*temp2=head2;
    while(temp1!=nullptr)
    {
        k1++;
        temp1=temp1->next;
    }
    while(temp2!=nullptr)
    {
        k2++;
        temp2=temp2->next;
    }
    int count=abs(k1-k2);
    temp1=head1;
    temp2=head2;
    if(k1>k2)
    {
        int i=0;
        while(i<count)
        {
        temp1=temp1->next;
        i++;
        }
        while(temp1&&temp2)
        {
            if(temp1==temp2)
            return temp1->data;
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    else
    {
        int i=0;
        while(i<count)
        {
        temp2=temp2->next;
        i++;
        }
        while(temp2&&temp1)
        {
            if(temp1==temp2)
            return temp2->data;
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return -1;
}
