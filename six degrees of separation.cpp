#include<iostream>
#include<queue>
using namespace std;
int map[10001][10001]={0};
int visit[10001]={0};
queue<int> q;
int n,m;
int bfs(int i){
	int v=i,count,level=0,last,tail;
	while(!q.empty())
		q.pop();
	for(int j=1;j<n+1;j++)
		visit[j]=0;
	q.push(v);
	visit[v]=1;
	count=1;
	last=v;
	while(!q.empty()){
		v=q.front();
		q.pop();
		for(int j=1;j<n+1;j++)
			if(visit[j]==0&&map[v][j]==1){
				q.push(j);
				count++;
				tail=j;
				visit[j]=1;
			}
		if(last==v){
			last=tail;
			level++;
		}
		if(level==6)
			break;
	}
	return count;
}
void sds(int i){
	int count;
	count=bfs(i);
	printf("%d: %0.2lf%%\n",i,count*1.0/n*1.0*100);
}
int main(){
	int a,b;
	cin>>n>>m;//输入节点数和边数 
	for(int i=0;i<m;i++){
		cin>>a>>b;
		map[a][b]=1;
		map[b][a]=1;
	}
	for(int i=1;i<n+1;i++){
		sds(i);
	}
	return 0;
}
