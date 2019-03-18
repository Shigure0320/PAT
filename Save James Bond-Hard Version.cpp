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
bool fristjump(point p){//��һ����Ҫ���ϵ��İ뾶���� 
	int x,y,r;
	x=pow(p.x,2);
	y=pow(p.y,2);
	r=dis*dis;
	if(x+y<=r)
		return 1;
	else
		return 0;
}
bool jump(int a,int b){//�ж��Ƿ�������������ͷ֮����Ծ 
	int x,y,r;
	x=pow(p[a].x-p[b].x,2);
	y=pow(p[a].y-p[b].y,2);
	r=dis*dis;
	if(x+y<=r)
		return 1;
	else
		return 0;
}
bool isout(int v){//�ж��ܷ�ӵ�ǰ����� 
	if(p[v].x+dis>=50||p[v].x-dis<=-50||p[v].y+dis>=50||p[v].y+dis<=-50)
		return true;
	else
		return false;
}
void escape(point *p){
	int v,dist[n]={0},path[n]={-1};//dist��ʾ���ǵڼ�����path������Ծ��·�� 
	queue<int> q;
	for(int i=1;i<n+1;i++)//���ö������bfs������һ�������е���� 
		if(fristjump(p[i])){
			q.push(i); //��ĿҪ������в�ͬ�����·���������һ��������С��·����������Ҫ�������齫��һ���Ŀ����԰���Ծ����ǵݼ�����Ȼ������ӣ�����������д�ˣ���ͷ��˵�ɡ� 
			dist[i]=2;
		}
	while(!q.empty()){ //�������Ϊ�ձ�ʾû��һ�������������007�������
		v=q.front();
		if(isout(v))//����ܴӵ�ǰ������Ծ����������ѭ������·����� 
			break;
		q.pop();//������������Ѹýڵ���� 
		for(int i=1;i<=n;i++){
			if(jump(v,i)&&dist[i]==0){//�������ڵ������������δ�����ʹ�������ڵ���Ӳ���¼��ǰ����������һ����λ�� 
				dist[i]=dist[v]+1;
				path[i]=v;
				q.push(i);
			}
		}
	}
	if(q.empty()){//������е㶼����˳��ӱ�ʾû�����������007���ϰ��������� 
		cout<<0;
		return ;
	}
	else{
		cout<<dist[v]<<endl;//����ͨ��path���ʵ�·���Ƿ��ģ�Ҫͨ��ջ�����������Ծ˳�� 
		stack<int> s;
		s.push(v);//���һ����������ջ 
		for(int i=1;i<dist[v];i++){//������ջ֮ǰ���������� 
			s.push(path[v]);
			v=path[v];
		}
		while(!s.empty()){//��ջ 
			v=s.top();
			cout<<p[v].x<<" "<<p[v].y;
			s.pop();
			if(!s.empty())
				cout<<endl;
		}
	}
}
int main(){
	cin>>n>>dis;//���������������Ծ���� 
	if(dis>=42.5){//�����ֱ��һ�����м����ѣ�����1 
		cout<<1<<endl;
		return 0;
	}
	p[0].x=0,p[0].y=0;
	for(int i=1;i<n+1;i++)//������������� 
		cin>>p[i].x>>p[i].y;
	escape(p);
	return 0;
}
