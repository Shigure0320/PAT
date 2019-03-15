#include<iostream>
using namespace std;
int agg[10000];
void createA(int n){//ֵ��ʼ��Ϊ-1��ʾΪ������ 
	for(int i;i<n;i++)
		agg[i]=-1;
}
int root(int a){
	if(agg[a]>0)
		return root(agg[a]);
	else
		return a;
}
void Check(int a,int b){//���ڵ�ĸ���ͬ��������������� 
	if(root(a)==root(b))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}
void InputC(int a,int b){//���ø��ڵ�ĸ�ֵ�洢���Ĵ�С�������Ӽ����ʱ������С�鲢��С������������ 
	if(agg[root(a)]>agg[root(b)]){
		agg[root(a)]=root(b);
		agg[root(b)]--;
	}
	else{
		agg[root(b)]=root(a);
		agg[root(a)]--;
	}
}
void TotalC(int n){
	int total=0;
	for(int i=1;i<n+1;i++)
		if(agg[i]<0)
			total++;//����ֵС��0��ʾΪ���ڵ㣬�������ж������ӵĸ��� 
	if(total==1)
		cout<<"The network is connceted."<<endl;
	else
		cout<<"There are "<<total<<" components"<<endl;
	for(int i=0;i<n+1;i++)
		cout<<agg[i]<<" ";
}
int main(){
	int n,a,b;
	char v;
	cin>>n;//������ĸ��� 
	createA(n);
	while(v!='S'){
		cin>>v;//����ѡ�� 
		switch(v){
			case 'C':
				cin>>a>>b;
				Check(a,b);break;// ���ab֮���Ƿ���ͨ 
			case 'I':
				cin>>a>>b;
				InputC(a,b);break;//��ͨab 
			case 'S':TotalC(n);//�������벢������������ӵ�������� 
		}
	}
	return 0;
}
