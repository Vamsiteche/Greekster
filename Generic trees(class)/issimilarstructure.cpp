
// C++ program to delete the
// leaf from the generic tree
 
#include <bits/stdc++.h>
using namespace std;
 
// a treenode class
class TreeNode {
public:
    int data;
    vector<TreeNode*> children;
 
    TreeNode(int data)
    {
        this->data = data;
    }
};
void linearit(TreeNode* root,TreeNode* &p)
{
	if(root==nullptr)
	return;
	vector<TreeNode*> v;
	for(int i=0;i<root->children.size();i++)
	{
		v.push_back(root->children[i]);
	}
	p->children.push_back(root);
	p=p->children[0];
	root->children.clear();
	for(int i=0;i<v.size();i++)
	{
		linearit(v[i],p);
	}
	return;
}
void Linearise_Tree(TreeNode* root)
{
	TreeNode *parent=new TreeNode(0);
	parent->children.push_back(root);
	linearit(root,parent);
}
// Recursive function which delete
// the leaf from tree
void removeLeaf(TreeNode* root)
{
    if(root==nullptr)
    return;
    for(int i=0;i<root->children.size();i++)
    {
    	if(root->children[i]->children.size()==0)
    	{
    		root->children.erase(root->children.begin()+i);
    		i--;
		}
	}
	for(int i=0;i<root->children.size();i++)
	removeLeaf(root->children[i]);
}
bool issimilar(TreeNode* first,TreeNode* second)
{
	if(first==second)
	return false;
	if(first==nullptr||second==nullptr)
	return false;
	if(first->children.size()!=second->children.size())
	return false;
	bool temp;
	for(int i=0;i<first->children.size();i++)
	{
		temp=issimilar(first->children[i],second->children[i]);
		if(!temp)
		return false;
	}
	return true;
}
// Function which will print the
// tree level wise
void printTheTree(TreeNode* root)
{
    if (root == NULL)
        return;
 
    cout << root->data << " "
         << ":";
    for (int i = 0;
         i < root->children.size();
         i++)
        cout << root->children[i]->data
 
             << " ";
    cout << endl;
 
    for (int i = 0;
         i < root->children.size();
         i++)
        printTheTree(root->children[i]);
}
 
// Driver code
int main()
{
    // 5
    //      / / \ \
    // 1  2  3  8
    //    /   /\  \
    // 15  4  5  6
 
    TreeNode* root = new TreeNode(5);
    TreeNode* child1 = new TreeNode(1);
    root->children.push_back(child1);
    TreeNode* child11 = new TreeNode(15);
    child1->children.push_back(child11);
    TreeNode* child2 = new TreeNode(2);
    root->children.push_back(child2);
    TreeNode* child21 = new TreeNode(4);
    TreeNode* child22 = new TreeNode(5);
    child2->children.push_back(child21);
    child2->children.push_back(child22);
    TreeNode* child3 = new TreeNode(3);
    root->children.push_back(child3);
    TreeNode* child31 = new TreeNode(6);
    child3->children.push_back(child31);
    TreeNode* child4 = new TreeNode(8);
    root->children.push_back(child4);
    

 
   // removeLeaf(root);
   //checking
   printTheTree(root);
   Linearise_Tree(root);
    printTheTree(root);
}
