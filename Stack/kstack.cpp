// A C++ program to demonstrate implementation of k stacks in a single  
// array in time and space efficient way 
#include<bits/stdc++.h> 
using namespace std; 
  
// A C++ class to represent k stacks in a single array of size n 
class kstacks
{
	int n;
	int *a;
	int *next;
	int k;
	int *tops;
	int free;
	public:
	kstacks(int k,int n)
	{
		this->n=n;
		this->k=k;
		a=new int[n];
		next=new int[n];
		tops=new int[k];
		for(int i=0;i<k;i++)
		tops[i]=-1;
		free=0;
		for(int i=0;i<n-1;i++)
		next[i]=i+1;
		next[n-1]=-1;
	}
	void push(int num,int k)
	{
		if(free==-1)
		{
			cout<<"Stack overflow"<<endl;
			return;
		}
		int i=free;
		free=next[free];
		a[i]=num;
		int j=tops[k-1];
		tops[k-1]=i;
		next[i]=j;
	}
	int pop(int k)
	{
		if(tops[k-1]==-1)
		{
			cout<<"Stack underflow"<<endl;
			return -1;
		}
		int num=a[tops[k-1]];
		int i=free;
		free=tops[k-1];
		tops[k-1]=next[free];
		next[free]=i;
		return num;
	}
};
int main()
{
	int k = 3, n = 10; 
    kstacks ks(k, n); 
  
    // Let us put some items in stack number 2 
    ks.push(15, 3); 
    ks.push(45, 3); 
  
    // Let us put some items in stack number 1 
    ks.push(17, 2); 
    ks.push(49, 2); 
    ks.push(39, 2); 
  
    // Let us put some items in stack number 0 
    ks.push(11, 1); 
    ks.push(9, 1); 
    ks.push(7, 1); 
  
    cout << "Popped element from stack 3 is " << ks.pop(3) << endl; 
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
	cout << "Popped element from stack 3 is " << ks.pop(3) << endl; 
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
	cout << "Popped element from stack 3 is " << ks.pop(3) << endl; 
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
  
    return 0; 
}

