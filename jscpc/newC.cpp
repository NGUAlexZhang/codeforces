#include <bits/stdc++.h>
using namespace std;
int a[100],b[100];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n=0;
		vector<int> ans;
		map<int,int>is;
		ans.push_back(-1);
		for(int i=0;i<=9;i++) cin>>a[i],n+=a[i];
		bool flag=0;
		for(int i=1;i<=9;i++){
			if(a[i]!=0) flag=1;
		}
		if(!flag&&a[0]==1){
			for(int i=1;i<=a[0];i++) cout<<0;
			continue;
		}
		for(int i=0;i<=9;i++) b[i]=a[i];
		int maxi=9;
		for(int i=9;i>=0;i--){
			if(a[maxi]<a[i]) maxi=i;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=9;j++){
				if(a[j]==0||(i==1&&j==0)||maxi==j) continue;
				int len=ans.size();
				if(ans[len-1]!=j){
					ans.push_back(j);
					a[j]--;
					break;
				}
			}
		}
		int len=ans.size();
		if(len<a[maxi]){
			cout<<-1<<endl;
			continue;
		}
		auto s=&ans[len-a[maxi]+1],t=&ans[len];
		sort(s,t);
		if(len==a[maxi]&&maxi==0){
			cout<<-1<<endl;
			continue;
		}
		len=ans.size();
		for(int i=0;i<len;i++){
			if(i)
				cout<<ans[i];
			if((len-1-i)+1<=a[maxi]) cout<<maxi;
		}
		cout<<endl;
	}
	return 0;
}
