
#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include<stdio.h>
using namespace std;

//节点值
int inOrderPos[10005];
int postOrderPos[10005];

int t = 0;
char c;
int node_index = 0;
int k = 0;

int index_sum[10005];  
int index[10005];  
struct treeNode
{
	int value;
	treeNode* leftNode;
	treeNode* rightNode;
};

treeNode node[10005];
inline treeNode* NewNode()  
{  
    node[node_index].leftNode = NULL;  
    node[node_index].rightNode = NULL;  
    return &node[node_index++];  
}  

treeNode*  build(int *in, int *post, int leng)
{
	if(leng == 0) return NULL;
	int i = leng -1;
	while(in[i] !=    post[leng-1]) i--;
	treeNode* tree =  NewNode();
	tree ->value = post[leng-1];  
	tree->leftNode =  build(in, post,i);
	tree->rightNode = build(in+i+1,post+i,leng-i-1);
	return tree;

}
void dfs(treeNode* root, int n)
{
	if(!root->leftNode && ! root->rightNode )
	{	 index_sum[k] = n + root->value; 
		 index[k] = root->value;
		 k++;
		 return;
	}
	if(root->leftNode)dfs(root->leftNode,n + root->value);
	if(root->rightNode)dfs(root->rightNode, n + root->value);
}


int main(int argc, char *argv[])
{
	
	while(scanf("%d%c", &inOrderPos[t++], &c) !=EOF)
	{
		if(c == '\n')
		{
			for(int i=0;i<t;i++)
			{
				scanf("%d", &postOrderPos[i]);
			}
			memset(index_sum,0, sizeof(index_sum));
			memset(index,0, sizeof(index));
			node_index = 0;
			k = 0;

			treeNode* root = build(inOrderPos,postOrderPos,t);
			 dfs(root, 0);  
			 int min = index_sum[0];  
			 int min_index = 0;  
			 for (int i = 0; i < k; i ++)  
			 {  
				 if (min > index_sum[i])  
				 {  
					 min = index_sum[i];  
					 min_index = i;  
				 }  
			 }  
			 printf("%d\n",index[min_index]);  
			 memset(inOrderPos, 0, sizeof(inOrderPos));  
			 memset(postOrderPos, 0, sizeof(postOrderPos));  
             t = 0;  
		}

	}

	return 0;

}
