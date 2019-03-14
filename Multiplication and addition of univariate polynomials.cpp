#include<stdio.h>
#include<stdlib.h>
typedef struct ElementList *Node;
struct ElementList{
	int coe;
	int index;
	Node Next;
};
Node addN(Node *T,int c,int i){//将一个项接在链表尾部
 
	Node P;
	P=(Node)malloc(sizeof(ElementList));
	P->coe=c;
	P->index=i;
	P->Next=NULL;
	(*T)->Next=P;
	*T=P;
}
Node CreateN(){//创建一元多项式链表 
	Node T,Prear,L;
	int N,c,i;
	T=(Node)malloc(sizeof(ElementList));
	T->Next=NULL;
	scanf("%d",&N);
	Prear=T;
	while(N--){
		scanf("%d %d",&c,&i);
		addN(&Prear,c,i);
	}
	L=T;T=T->Next;free(L);
	return T;
} 
Node addNN(Node P1,Node P2){//加法运算 
	Node P,T,t1,t2,Rear;
	P=(Node)malloc(sizeof(struct ElementList));
	P->Next=NULL;
	Rear=P;
	t1=P1;t2=P2;
	while(t1&&t2){//将节点按照指数大小依次接入新链表，当有两个多项式有指数相同项时，将系数相加，若系数和不为零，接入一个系数为和的节点 
		if(t1->index==t2->index){
			if(t1->coe+t2->coe){
				addN(&Rear,(t1->coe+t2->coe),t1->index);
			}
			t1=t1->Next;
			t2=t2->Next;
		}
		else if(t1->index>t2->index){
			addN(&Rear,t1->coe,t1->index);
			t1=t1->Next;
		}
		else{
			addN(&Rear,t2->coe,t2->index);
			t2=t2->Next;
		}
	}
	while(t1){//上一个循环在其中一个链表完成操作之后退出，此时需要把另一个链表的剩余节点接入新链表 
		addN(&Rear,t1->coe,t1->index);
		t1=t1->Next;
	}
	while(t2){
		addN(&Rear,t2->coe,t2->index);
		t2=t2->Next;
	}
	T=P;
	P=P->Next;
	free(T);//扔掉头结点 
	return P;
} 
void printN(Node p){//输出多项式 
	while(p){
		printf("%d %d ",p->coe,p->index);
		p=p->Next;
	}
	printf("\n");
}
Node mutN(Node P1,Node P2){//乘法运算，思路：先把第一个多项式的第一项和另一个多项式的乘积构造新链表，然后把第一个多项式剩余的节点与第二个多项式相乘的结果依次插入新链表中 
	Node P,rear,t,t1,t2;
	t1=P1;t2=P2;
	P=(Node)malloc(sizeof(struct ElementList));
	P->Next=NULL;
	rear=P;
	if(!P1||!P2)
		return NULL;
	while(t2){//t1的第一项和整个t2相乘的结果构造链表 
		addN(&rear,t1->coe*t2->coe,t1->index+t2->index);
		t2=t2->Next;
	}
	t1=t1->Next;
	while(t1){//二重循环，对t1开始的所有P1链表的项依次和P2相乘并将结果插入 
		t2=P2;
		rear=P;
		while(t2){
			int c,i;
			c=t1->coe*t2->coe;
			i=t1->index+t2->index;
			while(rear->Next&&rear->Next->index>i)//找到链表P中指数不大于该相乘结果的第一项 
				rear=rear->Next;
			if(rear->Next&&rear->Next->index==i){//如果两项指数相等，系数和不为0，将P中的该项系数更新，如果为零，删除P中的项 
				if(rear->Next->coe+c){
					rear->Next->coe+=c;
				}
				else{
					t=rear->Next;
					rear->Next=t->Next;
					free(t);
				}
			}
			else{//如果P中指数小于该相乘结果，将该结果插入P链表 
				t=(Node)malloc(sizeof(struct ElementList));
				t->coe=c;
				t->index=i;
				t->Next=rear->Next;
				rear->Next=t;
				rear=rear->Next;
			}
			t2=t2->Next;
			}
	t1=t1->Next;
	}
	t2=P;
	P=P->Next;
	free(t2);//扔掉头结点 
	return P;
	}
int main(){
	Node p1,p2,pa,px;
	p1=CreateN();
	p2=CreateN();
	pa=addNN(p1,p2);
	printN(pa);
	px=mutN(p1,p2);
	printN(px);
	return 0;
}
