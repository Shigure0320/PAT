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
		int v=-1,min=INF;//从未收入的节点中选一个路径最小的收入，第一趟时起点的dist已被初始化为0，收入起点。 
		for(int i=0;i<n;i++){
			if(min>dist[i]&&!collect[i]){
				v=i;
				min=dist[i];
			}
		}
		if(v==-1)//当找不到距离小于INF的未收录节点时 
			break;
		collect[v]=true;//收入该节点 
		for(int i=0;i<n;i++){//探测与该节点相接的节点，将最小路径保存 
			if(T[v][i]!=-1&&collect[i]==false)
				if(dist[v]+T[v][i]<dist[i]){
					dist[i]=dist[v]+T[v][i];
					cost[i]=cost[v]+P[v][i];
					path[i]=v;
				}
				else if(dist[v]+T[v][i]==dist[i]&&cost[v]+P[v][i]<cost[i]){//当两个节点距离相同消费不同时，路径更新为消费小的那个 
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
	memset(T,-1,sizeof(T));//初始化数组，T储存城市之间路径的大小，-1表示不通，P储存一座城市到另一座城市过路费的价格
	memset(P,-1,sizeof(P));
	fill(dist,dist+500,INF);//dist初始化为一个非常大的数，path初始化为-1 
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
