#include<iostream>
#include<queue>
#define MAXTree 10
#define Tree int
#define Null -1
using namespace std;
/*������ϵ����������Ҷ�ڵ�*/
struct TreeNode{//�����鴢����
	Tree Left;
	Tree Right;
}T[MAXTree];
bool IsLeaves(TreeNode T){//�жϸýڵ��Ƿ���ڵ� 
	if(T.Left==Null&&T.Right==Null)
		return true;
	else
		return false;
}
void PutLeaves(Tree t){
	queue<Tree> Q;//�ö��д���ڵ� 
	Q.push(t);//�Ѹ��ڵ�ѹ����� 
	while(Q.size()){
		if(IsLeaves(T[Q.front()])){//�жϵ�ǰ�ڵ��Ƿ���ڵ㣬��������ӡ 
			printf("%d",Q.front());
			if(Q.size()!=0)
				printf(" ");
		}
		if(T[Q.front()].Left!=Null)//�жϸýڵ��Ƿ��к��ӣ�����������ν����Һ���ѹ����� 
			Q.push(T[Q.front()].Left);
		if(T[Q.front()].Right!=Null)
			Q.push(T[Q.front()].Right);
		Q.pop();//���ýڵ���� 
	}
}
Tree BuildTree(TreeNode T[]){
	int N,Root,check[MAXTree];
	char tl,tr;
	scanf("%d",&N);
	getchar();
	if(N>0){
		for(int i=0;i<N;i++)
			check[i]=0;//�ü�������жϸ��ڵ㣬���û���κ�һ���ڵ�ָ��ýڵ㼴Ϊ���ڵ� 
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
				return i;//�����жϵĸ��ڵ���� 
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
