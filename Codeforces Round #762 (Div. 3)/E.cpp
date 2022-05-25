#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[250000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		priority_queue<int>q;
		a[0]=-1;
		q.push(-1);
		int now=0;ll sum=0;
		bool flag=0;
		for(int i=0;i<=n;i++){
			if(flag){
				cout<<"-1 ";
				continue;
			}
			while(now+1<=n&&a[now+1]<i){
				q.push(a[now+1]);
				now++;
			}
			if(q.empty()){
				cout<<"-1 ";
				flag=1;
				continue;
			}
			sum+=(i-1-q.top());
			q.pop();
			ll rindex=upper_bound(a+1,a+1+n,i)-a,lindex=lower_bound(a+1,a+1+n,i)-a;
			cout<<sum+rindex-lindex<<" ";
		}
		cout<<endl;
	}
	return 0;
}
