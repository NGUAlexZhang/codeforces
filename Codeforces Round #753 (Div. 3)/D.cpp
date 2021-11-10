#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[250000];
char s[250000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		priority_queue<int,vector<int>,greater<int> >q1,q2;
		cin>>(s+1);
		for(int i=1;i<=n;i++){
			if(s[i]=='B') q1.push(a[i]);
			else q2.push(a[i]);
		}
		bool flag=0;
		for(int i=1;i<=n;i++){
			while(q1.size()&&q1.top()<i) q1.pop();
			if(q1.size()){
				//cout<<1<<endl;
				q1.pop();
				continue;
			}
			//cout<<4<<endl;
			if(q2.empty()||q2.top()>i){
				//cout<<2<<endl;
				flag=1;
				break;
			}
			//cout<<3<<endl;
			q2.pop();
		}
		if(flag){
			cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}
	return 0;
}
