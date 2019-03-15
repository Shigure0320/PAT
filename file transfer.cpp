#include<iostream>
using namespace std;
int agg[10000];
void createA(int n){//值初始化为-1表示为无链接 
	for(int i;i<n;i++)
		agg[i]=-1;
}
int root(int a){
	if(agg[a]>0)
		return root(agg[a]);
	else
		return a;
}
void Check(int a,int b){//两节点的根相同即两计算机已链接 
	if(root(a)==root(b))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}
void InputC(int a,int b){//利用根节点的负值存储树的大小，在链接计算机时按树大小归并，小树附到大树上 
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
			total++;//出现值小于0表示为根节点，即网络中独立链接的个数 
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
	cin>>n;//计算机的个数 
	createA(n);
	while(v!='S'){
		cin>>v;//操作选择 
		switch(v){
			case 'C':
				cin>>a>>b;
				Check(a,b);break;// 检查ab之间是否联通 
			case 'I':
				cin>>a>>b;
				InputC(a,b);break;//联通ab 
			case 'S':TotalC(n);//结束输入并检查网络中链接的整体个数 
		}
	}
	return 0;
}
