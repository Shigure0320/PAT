#include<iostream>
using namespace std;
struct minheap{
	int dat[1000];
	int size;
};
int n,m; 
void insert(minheap &H,int a){//完全二叉树的性质，节点的根的下标为该节点的下标除以2，左子树为该节点的下标乘以2，右子树为乘2加1. 
	if(H.size>=1000){//如果队满则输出信息并什么都不做 
		cout<<"堆满"<<endl;
		return ;
	}
	
	int i;
	i=++H.size;//记录树的最后一个节点并把size+1。 
	for(;H.dat[i/2]>a;i/=2)//遍历最后一个节点到根的位置
		H.dat[i]=H.dat[i/2];//过滤比插入元素大的值，将它们全部向下挪，该语句将i的父节点的值下移到i 
	H.dat[i]=a;//把插入的值赋给最后的i节点位置，保证堆的性质 
}
void prilod(minheap H,int l){ 
	int i=l;
	cout<<H.dat[i];
	while(i>1){
		i/=2;
		cout<<" "<<H.dat[i];
	}
}
int main(){
	minheap H;
	int data,ind;
	H.dat[0]=-10001;//0下标位置不存放数据，存放一个小顶堆的哨兵 
	H.size=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){//将数据依次插入空堆 
		cin>>data;
		insert(H,data);
	}
	for(int i=0;i<m;i++){//输入节点，输出节点到堆顶的路径 
		cin>>ind;
		prilod(H,ind);
		cout<<endl;
	}
	return 0;
}
