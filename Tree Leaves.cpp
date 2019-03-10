#include<iostream>
#include<queue>
#define MAXTree 10
#define Tree int
#define Null -1
using namespace std;
/*按层从上到下输出树的叶节点*/
struct TreeNode{//用数组储存树
	Tree Left;
	Tree Right;
}T[MAXTree];
bool IsLeaves(TreeNode T){//判断该节点是否根节点 
	if(T.Left==Null&&T.Right==Null)
		return true;
	else
		return false;
}
void PutLeaves(Tree t){
	queue<Tree> Q;//用队列储存节点 
	Q.push(t);//把根节点压入队列 
	while(Q.size()){
		if(IsLeaves(T[Q.front()])){//判断当前节点是否根节点，如果是则打印 
			printf("%d",Q.front());
			if(Q.size()!=0)
				printf(" ");
		}
		if(T[Q.front()].Left!=Null)//判断该节点是否有孩子，如果有则依次将左右孩子压入队列 
			Q.push(T[Q.front()].Left);
		if(T[Q.front()].Right!=Null)
			Q.push(T[Q.front()].Right);
		Q.pop();//将该节点出队 
	}
}
Tree BuildTree(TreeNode T[]){
	int N,Root,check[MAXTree];
	char tl,tr;
	scanf("%d",&N);
	getchar();
	if(N>0){
		for(int i=0;i<N;i++)
			check[i]=0;//用检查数组判断根节点，如果没有任何一个节点指向该节点即为根节点 
		for(int i=0;i<N;i++){
			scanf("%c %c",&tl,&tr);
			getchar();
			if(tl!='-'){
				T[i].Left=tl-'0';
				check[T[i].Left]=1;
			}
			else
				T[i].Left=Null;
			if(tr!='-'){
				T[i].Right=tr-'0';
				check[T[i].Right]=1;
			}
			else
				T[i].Right=Null;
		}
		for(int i=0;i<N;i++){
			if(check[i]==0)
				return i;//返回判断的根节点序号 
		}
	}
	else
		return Null;
}
int main(){
	Tree R;
	R=BuildTree(T);
	PutLeaves(R);
	return 0;
}
