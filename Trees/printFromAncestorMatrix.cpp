#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int n)
	{
		left=nullptr;
		right=nullptr;
		data=n;
	}
	TreeNode()
	{
		left=nullptr;
		right=nullptr;
		data=0;
	}
};
TreeNode* treeFromAncestorMatrix(vector<vector<int>> m)
{
	int n=m.size();
	bool visited[n];
	TreeNode* ans[n];
	for(int i=0;i<n;i++)
	ans[i]=new TreeNode(i);
	memset(visited,false,sizeof(visited));
	pair<int,int> ct[n];
	for(int i=0;i<n;i++)
	{
		int count=0;
		for(int j=0;j<n;j++)
		{
			if(m[i][j])
			count++;
		}
		ct[i]={count,i};
	}
	sort(ct,ct+n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(m[ct[i].second][j]==1&&visited[j]==false)
			{
				visited[j]=true;
				if(ans[ct[i].second]->left==nullptr)
				{
					ans[ct[i].second]->left=ans[j];
				}
				else
				{
					ans[ct[i].second]->right=ans[j];
				}
			}
		}
	}
	return ans[ct[n-1].second];
}
string preOrderTraversal(TreeNode* root)
{
	if(root==nullptr)
	return "";
	string s=to_string(root->data);
	string left=preOrderTraversal(root->left);
	string right=preOrderTraversal(root->right);
	string ans;
	for(int i=0;i<left.size();i++)
	{
		ans.push_back(' ');
	}
	ans+=s+"\n\n"+left;
	for(int i=0;i<s.size();i++)
	{
		ans.push_back(' ');
	}
	ans+=right;
	return ans;
}
void pretreverse(TreeNode* root)
{
	if(root==nullptr)
	return;
	cout<<root->data<<" ";
	pretreverse(root->left);
	pretreverse(root->right);
}
int main()
{
	vector<vector<int> >mat;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		vector<int> temp;
		for(int j=0;j<n;j++)
		{
			int tempi;
			cin>>tempi;
			temp.push_back(tempi);
		}
		mat.push_back(temp);
	}
	TreeNode* ans=treeFromAncestorMatrix(mat);
	string s=preOrderTraversal(ans);
	for(int i=0;i<s.size();i++)
	cout<<s[i];
	cout<<endl;
	pretreverse(ans);
}
