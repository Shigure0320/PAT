#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
vector<int>pre,in,post;
void postorder(int root,int start,int end){
	if(start>end)
		return ;
	int i=start;
	while(i<end&&in[i]!=pre[root])
		i++;
	postorder(root+1,start,i-1);
	postorder(root-start+i+1,i+1,end);//������Ҳ�㲻��root-start�����壬�����ֻ��i+1�Ļ�����һ�����Ե����ȥ�� 
	post.push_back(in[i]);
}
int main(){//����push��popʱ����pop���õ�������������ö�ջ��¼�������������ǰ����������ȷ���������� 
	int n,temp;
	stack<int> s;
	cin>>n;
	string t;
	while(cin>>t){
		if(t=="Push"){
			cin>>temp;
			s.push(temp);
			pre.push_back(temp);
		}
		else{
			in.push_back(s.top());
			s.pop();
		}
	}
	postorder(0,0,n-1);
	for(int i=0;i<n;i++){
		if(i==0)
			cout<<post[i];
		else
			cout<<" "<<post[i];
	}
	system("pause");
	return 0;
} 
