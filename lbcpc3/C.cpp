#include <bits/stdc++.h>
using namespace std;
int a[250000];
priority_queue<int>q;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],q.push(a[i]);
	int index=1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[index]) index=i;
	}
	int l=index-1,r=index+1;
	q.pop();
	//int now=a[index];
	cout<<index<<endl;
	while(q.size()){
		if(q.top()!=a[l]&&q.top()!=a[r]){
			cout<<"NO";return 0;
		}
		if(a[l]==q.top()){
			l--;
		}
		else{
			r++;
		}
		q.pop();
	}
	cout<<"YES";
	return 0;
}
