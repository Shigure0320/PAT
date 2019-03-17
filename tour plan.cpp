#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 60000
using namespace std;
int n,m,s,d;
int T[500][500];
int P[500][500];
int dist[500];
int path[500];
int collect[500];
int cost[500];
void dijkstra(int s){
	memset(collect,false,sizeof(collect)); 
	dist[s]=0;
	cost[s]=0;
	while(1){ 
		int v=-1,min=INF;//��δ����Ľڵ���ѡһ��·����С�����룬��һ��ʱ����dist�ѱ���ʼ��Ϊ0��������㡣 
		for(int i=0;i<n;i++){
			if(min>dist[i]&&!collect[i]){
				v=i;
				min=dist[i];
			}
		}
		if(v==-1)//���Ҳ�������С��INF��δ��¼�ڵ�ʱ 
			break;
		collect[v]=true;//����ýڵ� 
		for(int i=0;i<n;i++){//̽����ýڵ���ӵĽڵ㣬����С·������ 
			if(T[v][i]!=-1&&collect[i]==false)
				if(dist[v]+T[v][i]<dist[i]){
					dist[i]=dist[v]+T[v][i];
					cost[i]=cost[v]+P[v][i];
					path[i]=v;
				}
				else if(dist[v]+T[v][i]==dist[i]&&cost[v]+P[v][i]<cost[i]){//�������ڵ������ͬ���Ѳ�ͬʱ��·������Ϊ����С���Ǹ� 
					cost[i]=cost[v]+P[v][i];
					path[i]=v;
				}
		}
	}
	if(dist[d]<INF){
		cout<<dist[d]<<" "<<cost[d];
	}
}
int main(){
	int a,b,length,price;
	memset(T,-1,sizeof(T));//��ʼ�����飬T�������֮��·���Ĵ�С��-1��ʾ��ͨ��P����һ�����е���һ�����й�·�ѵļ۸�
	memset(P,-1,sizeof(P));
	fill(dist,dist+500,INF);//dist��ʼ��Ϊһ���ǳ��������path��ʼ��Ϊ-1 
	fill(cost,cost+500,INF);// 
	memset(path,-1,sizeof(path));
	cin>>n>>m>>s>>d;
	for(int i=0;i<m;i++){
		cin>>a>>b>>length>>price;
		T[a][b]=T[b][a]=length;
		P[a][b]=P[b][a]=price;
	}
	dijkstra(s);
	return 0;
} 
