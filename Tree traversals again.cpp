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
	postorder(root-start+i+1,i+1,end);//到现在也搞不懂root-start的意义，但如果只用i+1的话会有一个测试点过不去。 
	post.push_back(in[i]);
}
int main(){//输入push和pop时忽略pop即得到先序遍历，利用堆栈记录中序遍历，利用前序和中序遍历确定后续遍历 
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
