// { Driver Code Starts
// driver
//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
struct Node* reverse(Node* head)
{
   if(head==nullptr||head->next==nullptr)
   return head;
   Node* pre=nullptr;
   Node* next;
   Node* curr=head;
   while(curr->next)
   {
       next=curr->next;
       curr->next=pre;
       pre=curr;
       curr=next;
   }
   curr->next=pre;
   return curr;
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    first=reverse(first);
    second=reverse(second);
    Node* ans=new Node(0);
    Node* temp=ans;
    int c=0;
    while(first&&second)
    {
        int sum=c+first->data+second->data;
        temp->next=new Node(sum%10);
        c=sum/10;
        temp=temp->next;
        first=first->next;
        second=second->next;
    }
    while(first)
    {
        int sum=c+first->data;
        temp->next=new Node(sum%10);
        c=sum/10;
        temp=temp->next;
        first=first->next;
    }
    while(second)
    {
        int sum=c+second->data;
        temp->next=new Node(sum%10);
        c=sum/10;
        temp=temp->next;
        second=second->next;
    }
    if(c!=0)
    temp->next=new Node(c);
    return reverse(ans->next);
}

