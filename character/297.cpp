#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char str[1024], str2[1024];
int node_index = 0;
int pos1,pos2;
int sum = 0;

struct Node
{
	char data;
	Node* son[4];
};
Node node[1000];

Node* creatNode()
{
	node[node_index].data = 0;
	for(int i=0;i<4;i++) node[node_index].son[i] = NULL;
	return &node[node_index++];
}


Node* buildTree(Node* root, int &pos, char *str)
{
	++pos;
	if(pos == strlen(str) ) return NULL;
	root = creatNode();
	root->data = str[pos];
	if(str[pos] == 'p')
	{
		for(int i=0;i<4;i++)
		{
			if(root->son[i] == NULL)
			root->son[i] = buildTree(root->son[i], pos,str);
		}

	}
	return root;
}
void dfs(Node* root1, Node* root2,int level)
{
	if(!root1&&!root2)return;

	if(!root1)
	{
		if(root2->data == 'f')
		{
			sum += 1024>>(level*2);
			return;

		}
		for(int i=0;i<4;i++)dfs(root1,root2->son[i],level+1);
		return;
	}
	if(!root2)
	{
		if(root1->data == 'f')
		{
			sum += 1024>>(level*2);return;

		}
		for(int i=0;i<4;i++)dfs(root1->son[i],root2,level+1);
		return;
	}

		if(root1->data =='f' || root2->data =='f')
		{
			sum += 1024>>(level*2);
			return;
		}

		for(int i=0;i<4;i++)
			dfs(root1->son[i],root2->son[i],level+1);

}

void init()
{
	Node* root1 = NULL; 
	Node* root2 = NULL;
	pos1 = -1;pos2 = -1;
	node_index = 0;
	root1 = buildTree(root1,pos1,str);
	root2 = buildTree(root2,pos2,str2);
	sum = 0;
	dfs(root1,root2,0);
	printf("There are %d black pixels.\n", sum);  

}


int main()
{

	int t;
	scanf("%d", &t);
	getchar();
	while(t--)
	{
		scanf("%s %s", &str, &str2);
		init();

	}

	return 0;


}
