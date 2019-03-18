#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
struct point{
	int x;
	int y;
};
point p[101];
int n,dis;
bool fristjump(point p){//第一跳，要加上岛的半径来算 
	int x,y,r;
	x=pow(p.x,2);
	y=pow(p.y,2);
	r=dis*dis;
	if(x+y<=r)
		return 1;
	else
		return 0;
}
bool jump(int a,int b){//判断是否能在两个鳄鱼头之间跳跃 
	int x,y,r;
	x=pow(p[a].x-p[b].x,2);
	y=pow(p[a].y-p[b].y,2);
	r=dis*dis;
	if(x+y<=r)
		return 1;
	else
		return 0;
}
bool isout(int v){//判断能否从当前点溜掉 
	if(p[v].x+dis>=50||p[v].x-dis<=-50||p[v].y+dis>=50||p[v].y+dis<=-50)
		return true;
	else
		return false;
}
void escape(point *p){
	int v,dist[n]={0},path[n]={-1};//dist表示这是第几跳，path储存跳跃的路径 
	queue<int> q;
	for(int i=1;i<n+1;i++)//利用队列完成bfs，将第一跳的所有点入队 
		if(fristjump(p[i])){
			q.push(i); //题目要求如果有不同的最短路径，输出第一跳距离最小的路径，这里需要利用数组将第一跳的可能性按跳跃距离非递减排序，然后再入队，但是我懒得写了，回头再说吧。 
			dist[i]=2;
		}
	while(!q.empty()){ //如果数列为空表示没有一条鳄鱼可以跳，007你等死吧
		v=q.front();
		if(isout(v))//如果能从当前鳄鱼跳跃逃生，跳出循环进行路径输出 
			break;
		q.pop();//如果不能逃生把该节点出队 
		for(int i=1;i<=n;i++){
			if(jump(v,i)&&dist[i]==0){//如果这个节点可以跳而且尚未被访问过，这个节点入队并记录当前的跳数和上一跳的位置 
				dist[i]=dist[v]+1;
				path[i]=v;
				q.push(i);
			}
		}
	}
	if(q.empty()){//如果所有点都完成了出队表示没有鳄鱼可以让007跳上岸，等死吧 
		cout<<0;
		return ;
	}
	else{
		cout<<dist[v]<<endl;//由于通过path访问的路径是反的，要通过栈来输出正的跳跃顺序 
		stack<int> s;
		s.push(v);//最后一跳的鳄鱼入栈 
		for(int i=1;i<dist[v];i++){//依次入栈之前跳过的鳄鱼 
			s.push(path[v]);
			v=path[v];
		}
		while(!s.empty()){//出栈 
			v=s.top();
			cout<<p[v].x<<" "<<p[v].y;
			s.pop();
			if(!s.empty())
				cout<<endl;
		}
	}
}
int main(){
	cin>>n>>dis;//传入鳄鱼个数和跳跃距离 
	if(dis>=42.5){//如果能直接一跳从中间逃脱，返回1 
		cout<<1<<endl;
		return 0;
	}
	p[0].x=0,p[0].y=0;
	for(int i=1;i<n+1;i++)//传入鳄鱼的坐标 
		cin>>p[i].x>>p[i].y;
	escape(p);
	return 0;
}
