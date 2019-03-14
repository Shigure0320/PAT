#include<stdio.h>
#include<stdlib.h>
typedef struct ElementList *Node;
struct ElementList{
	int coe;
	int index;
	Node Next;
};
Node addN(Node *T,int c,int i){//��һ�����������β��
 
	Node P;
	P=(Node)malloc(sizeof(ElementList));
	P->coe=c;
	P->index=i;
	P->Next=NULL;
	(*T)->Next=P;
	*T=P;
}
Node CreateN(){//����һԪ����ʽ���� 
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
Node addNN(Node P1,Node P2){//�ӷ����� 
	Node P,T,t1,t2,Rear;
	P=(Node)malloc(sizeof(struct ElementList));
	P->Next=NULL;
	Rear=P;
	t1=P1;t2=P2;
	while(t1&&t2){//���ڵ㰴��ָ����С���ν���������������������ʽ��ָ����ͬ��ʱ����ϵ����ӣ���ϵ���Ͳ�Ϊ�㣬����һ��ϵ��Ϊ�͵Ľڵ� 
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
	while(t1){//��һ��ѭ��������һ��������ɲ���֮���˳�����ʱ��Ҫ����һ�������ʣ��ڵ���������� 
		addN(&Rear,t1->coe,t1->index);
		t1=t1->Next;
	}
	while(t2){
		addN(&Rear,t2->coe,t2->index);
		t2=t2->Next;
	}
	T=P;
	P=P->Next;
	free(T);//�ӵ�ͷ��� 
	return P;
} 
void printN(Node p){//�������ʽ 
	while(p){
		printf("%d %d ",p->coe,p->index);
		p=p->Next;
	}
	printf("\n");
}
Node mutN(Node P1,Node P2){//�˷����㣬˼·���Ȱѵ�һ������ʽ�ĵ�һ�����һ������ʽ�ĳ˻�����������Ȼ��ѵ�һ������ʽʣ��Ľڵ���ڶ�������ʽ��˵Ľ�����β����������� 
	Node P,rear,t,t1,t2;
	t1=P1;t2=P2;
	P=(Node)malloc(sizeof(struct ElementList));
	P->Next=NULL;
	rear=P;
	if(!P1||!P2)
		return NULL;
	while(t2){//t1�ĵ�һ�������t2��˵Ľ���������� 
		addN(&rear,t1->coe*t2->coe,t1->index+t2->index);
		t2=t2->Next;
	}
	t1=t1->Next;
	while(t1){//����ѭ������t1��ʼ������P1����������κ�P2��˲���������� 
		t2=P2;
		rear=P;
		while(t2){
			int c,i;
			c=t1->coe*t2->coe;
			i=t1->index+t2->index;
			while(rear->Next&&rear->Next->index>i)//�ҵ�����P��ָ�������ڸ���˽���ĵ�һ�� 
				rear=rear->Next;
			if(rear->Next&&rear->Next->index==i){//�������ָ����ȣ�ϵ���Ͳ�Ϊ0����P�еĸ���ϵ�����£����Ϊ�㣬ɾ��P�е��� 
				if(rear->Next->coe+c){
					rear->Next->coe+=c;
				}
				else{
					t=rear->Next;
					rear->Next=t->Next;
					free(t);
				}
			}
			else{//���P��ָ��С�ڸ���˽�������ý������P���� 
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
	free(t2);//�ӵ�ͷ��� 
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
