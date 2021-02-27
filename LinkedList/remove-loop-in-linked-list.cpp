//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#
// { Driver Code Starts
// driver code
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

void removeLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
// } Driver Code Ends


/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    if(head==nullptr||head->next==nullptr)
    return;
    Node *slow=head;
    Node *fast=head;
    slow=slow->next;
    fast=fast->next->next;
    while(fast!=nullptr&&fast->next!=nullptr)
    {
        if(fast==slow)
        {
            break;
        }
        else
        {
            fast=fast->next->next;
            slow=slow->next;
        }
    }
   if(slow==fast)
   {
    slow=head;
    if(fast==slow)
    {
        while(fast->next!=slow)
        fast=fast->next;
    }
    else
    {
    while(fast->next!=slow->next)
    {
        fast=fast->next;
        slow=slow->next;
    }
    }
   
    fast->next=nullptr;
   }
    return;
   
}
