#include<iostream>
#include<algorithm>
#define INF 60000
using namespace std;
int load[1001][1001];
int n,m;
void prim(){//prim��˼�룬��һ��С������ 
	int count=0,pay=0; 
	int dist[n+1];
	int collect[n+1];
	int parent[n+1]={0};
	fill(collect,collect+1+n,-1);//��ʼ����¼�㼯�͵㵽���ľ��룬-1��δ����¼����ʼ������ΪINF����һ������С 
	fill(dist,dist+n+1,INF);
	dist[1]=0;//��һ���㵽���ľ�����Ϊ0�����ڵ���Ϊ-1��ʾ�޸��ڵ�
	parent[1]=-1;
	while(1){
		int v=-1,min=INF;
		for(int i=1;i<=n;i++)//ѭ���ҵ���δ��¼��dist���ڵ㵽���ľ��룩��С�Ľڵ� 
			if(collect[i]==-1&&dist[i]<min){
				v=i;
				min=dist[i];
			}
		collect[v]=true;
		dist[v]=0;
		if(v==-1)//���û���ҵ������Ľڵ㣬break 
			break;
		for(int i=1;i<=n;i++)//����v��������δ�������������ڵ㣬�������ǵ�������С���� 
			if(load[v][i]!=INF)
				if(collect[i]==-1&&load[v][i]<dist[i]){
					dist[i]=load[v][i];
					parent[i]=v;
				}
	}
	for(int i=1;i<=n;i++)//����������Ľڵ��� 
		if(collect[i]==true)
			count++;
	if(count!=n)//���n���ڵ�û�б�ȫ����¼��˵���нڵ�û����ͨ����С������������ 
		cout<<-1;
	else{
		for(int i=1;i<=n;i++)//������������ڣ������бߵ�Ȩֵ��������Ϊ���칫·����С���ġ� 
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
