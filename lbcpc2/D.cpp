#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[100005],b[100005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	queue<int>q1;
	queue<int>q2;
	for(int i=n;i>=1;i--) q1.push(a[i]),q2.push(b[i]);
	ll sum1=0,sum2=0;
	while(q1.size()||q2.size()){
		if(q1.size()){
			if(q2.size()&&q2.front()>q1.front()) q2.pop();
			else{
				sum1+=q1.front();
				q1.pop();
			}
		}else if(q2.size()) q2.pop();
		if(q2.size()){
			if(q1.size()&&q1.front()>q2.front()) q1.pop();
			else{
				sum2+=q2.front();
				q2.pop();
			}
		}else if(q1.size()) q1.pop();	
	}
	cout<<sum1-sum2;
	return 0;
}
