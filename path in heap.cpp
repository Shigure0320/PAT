#include<iostream>
using namespace std;
struct minheap{
	int dat[1000];
	int size;
};
int n,m; 
void insert(minheap &H,int a){//��ȫ�����������ʣ��ڵ�ĸ����±�Ϊ�ýڵ���±����2��������Ϊ�ýڵ���±����2��������Ϊ��2��1. 
	if(H.size>=1000){//��������������Ϣ��ʲô������ 
		cout<<"����"<<endl;
		return ;
	}
	
	int i;
	i=++H.size;//��¼�������һ���ڵ㲢��size+1�� 
	for(;H.dat[i/2]>a;i/=2)//�������һ���ڵ㵽����λ��
		H.dat[i]=H.dat[i/2];//���˱Ȳ���Ԫ�ش��ֵ��������ȫ������Ų������佫i�ĸ��ڵ��ֵ���Ƶ�i 
	H.dat[i]=a;//�Ѳ����ֵ��������i�ڵ�λ�ã���֤�ѵ����� 
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
	H.dat[0]=-10001;//0�±�λ�ò�������ݣ����һ��С���ѵ��ڱ� 
	H.size=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){//���������β���ն� 
		cin>>data;
		insert(H,data);
	}
	for(int i=0;i<m;i++){//����ڵ㣬����ڵ㵽�Ѷ���·�� 
		cin>>ind;
		prilod(H,ind);
		cout<<endl;
	}
	return 0;
}
