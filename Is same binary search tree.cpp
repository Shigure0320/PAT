#include<iostream>
#define Tree int
using namespace std;
struct TreeNode{
	Tree data;
	TreeNode *Left;
	TreeNode *Right;
	int flag;//flag�����б�ǰ�Ƿ���ʹ��ýڵ� 
};
TreeNode* NewNode(int v){
	TreeNode *T=(TreeNode*)malloc(sizeof(TreeNode));
	T->data=v;
	T->Left=T->Right=NULL;
	T->flag=0;
	return T;
}
TreeNode* Insert(TreeNode* &T,int v){//�ݹ���룬����������Ҫ��������С�ڸ��ڵ㣬���������ڸ��ڵ� 
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
	if(T->flag){//�ݹ��� 
		if(T->data<v)
			return check(T->Right,v);
		else if(T->data>v)
			return check(T->Left,v);
		else
			return 0;//�ڸýڵ��Ѿ����ʹ�������£����v==T->data�ͱ�ʾ�ýڵ���ֹ����Σ�����ͬһ�ö��������� 
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
	int flagA=0,v;//flagA�����жϵ�ǰ�����Ƿ����������һ�£������е�flag�����ж���ǰ�Ƿ���ʹ��ýڵ㡣 
	cin>>v;
	if(v!=T->data)
		flagA=1;
	else
		T->flag=1;
	for(int i=1;i<n;i++){
		cin>>v;
		if(flagA!=1&&!(check(T,v)))//���δcheck����ֵ���ֵ���ִ�������һ�Σ���ʾ��ֵ�����в���ͬһ�ö��������� 
			flagA=1;
	}
	if(flagA)
		return 0;
	else
		return 1;
}
void resetT(TreeNode *T){//��ɶ�һ�����е�ɨ��֮��������T��flag 
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
void preorder(TreeNode *T){//���Ժ�������������������������δʹ�ã� 
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
