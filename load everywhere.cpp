#include<iostream>
#include<algorithm>
#define INF 60000
using namespace std;
int load[1001][1001];
int n,m;
void prim(){//prim的思想，让一棵小树长大。 
	int count=0,pay=0; 
	int dist[n+1];
	int collect[n+1];
	int parent[n+1]={0};
	fill(collect,collect+1+n,-1);//初始化收录点集和点到树的距离，-1表未被收录，初始化距离为INF便于一步步缩小 
	fill(dist,dist+n+1,INF);
	dist[1]=0;//第一个点到树的距离标记为0，父节点标记为-1表示无父节点
	parent[1]=-1;
	while(1){
		int v=-1,min=INF;
		for(int i=1;i<=n;i++)//循环找到尚未收录的dist（节点到树的距离）最小的节点 
			if(collect[i]==-1&&dist[i]<min){
				v=i;
				min=dist[i];
			}
		collect[v]=true;
		dist[v]=0;
		if(v==-1)//如果没有找到这样的节点，break 
			break;
		for(int i=1;i<=n;i++)//查找v的所有尚未收入树的相连节点，更新他们到树的最小距离 
			if(load[v][i]!=INF)
				if(collect[i]==-1&&load[v][i]<dist[i]){
					dist[i]=load[v][i];
					parent[i]=v;
				}
	}
	for(int i=1;i<=n;i++)//检查收入树的节点数 
		if(collect[i]==true)
			count++;
	if(count!=n)//如果n个节点没有被全部收录，说明有节点没有联通，最小生成树不存在 
		cout<<-1;
	else{
		for(int i=1;i<=n;i++)//如果生成树存在，把所有边的权值相加输出即为建造公路的最小消耗。 
			if(parent[i]!=-1)
				pay+=load[i][parent[i]];
		cout<<pay;
	}
}
int main(){
	int a,b,cost;
	cin>>n>>m;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			load[i][j]=INF;
	for(int i=0;i<m;i++){
		cin>>a>>b>>cost;
		load[a][b]=load[b][a]=cost;
	}
	prim();
	return 0;
} 
