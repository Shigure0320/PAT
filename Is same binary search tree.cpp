#include<iostream>
#define Tree int
using namespace std;
struct TreeNode{
	Tree data;
	TreeNode *Left;
	TreeNode *Right;
	int flag;//flag用于判别当前是否访问过该节点 
};
TreeNode* NewNode(int v){
	TreeNode *T=(TreeNode*)malloc(sizeof(TreeNode));
	T->data=v;
	T->Left=T->Right=NULL;
	T->flag=0;
	return T;
}
TreeNode* Insert(TreeNode* &T,int v){//递归插入，二叉搜索树要求左子树小于根节点，右子树大于根节点 
	if(T==NULL)
		T=NewNode(v);
	else{
		if(v>T->data)
			T->Right=Insert(T->Right,v);
		else
			T->Left=Insert(T->Left,v);
	}
	return T;
}
TreeNode* MakeTree(int n){
	TreeNode* T;
	int v;
	cin>>v;
	T=NewNode(v);
	for(int i=1;i<n;i++){
		cin>>v;
		T=Insert(T,v);
	}
	return T;
}
int check(TreeNode* T,int v){
	if(T->flag){//递归检查 
		if(T->data<v)
			return check(T->Right,v);
		else if(T->data>v)
			return check(T->Left,v);
		else
			return 0;//在该节点已经访问过的情况下，如果v==T->data就表示该节点出现过两次，不是同一棵二叉搜索树 
	}
	else{
		if(T->data==v){
			T->flag=1;
			return 1;
		}
		else
			return 0;
	}
}
int Judge(TreeNode* T,int n){
	int flagA=0,v;//flagA用于判断当前序列是否仍与二叉树一致，而树中的flag用于判定当前是否访问过该节点。 
	cin>>v;
	if(v!=T->data)
		flagA=1;
	else
		T->flag=1;
	for(int i=1;i<n;i++){
		cin>>v;
		if(flagA!=1&&!(check(T,v)))//如果未check到该值或该值出现次数超过一次，表示该值的序列不是同一棵二叉搜索树 
			flagA=1;
	}
	if(flagA)
		return 0;
	else
		return 1;
}
void resetT(TreeNode *T){//完成对一个序列的扫描之后重置树T的flag 
	if(T->Left)
		resetT(T->Left);
	if(T->Right)
		resetT(T->Right);
	T->flag=0;
}
void FreeTree(TreeNode *T){
	if(T->Left)
		FreeTree(T->Left);
	if(T->Right)
		FreeTree(T->Right);
	free(T);
}
void preorder(TreeNode *T){//测试函数，输出树的先序遍历（题中未使用） 
	cout<<T->data<<" ";
	if(T->Left)
		preorder(T->Left);
	if(T->Right)
		preorder(T->Right); 
}
int main(){
	int n,l;
	TreeNode *T;
	cin>>n;
	while(n){
		cin>>l;
		T=MakeTree(n);
		for(int i=0;i<l;i++){
			if(Judge(T,n))
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		resetT(T);
		}
		FreeTree(T);
		cin>>n;
	}
	return 0;
}
