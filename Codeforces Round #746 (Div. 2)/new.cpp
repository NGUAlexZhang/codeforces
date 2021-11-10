#include <bits/stdc++.h>
#define ll long long
using namespace std;
int sg[1600000];
int main(){
	int T,cnt=0;
	//cin>>T;
	int n;
	while(1){
		cin>>n;
		if(n==0) return 0;
		int ans=0,flag=0;
		for(int i=1;i<=n;i++){
			ll c,s;
			cin>>s>>c;
			if(s==0||c==0) continue;
			if(c*c+c>=s){
				ans^=(s-c);
				//cout<<s-c<<endl;
				continue;
			}
			sg[s]=0;
			for(int i=s-1;i>=c;i--){
				if(i>1000||i+i*i>=s)
					sg[i]=s-i;
				else{
					sg[i]=0;
					s=i;
				}
			}
			ans^=sg[c];
		}
		printf("Case %d:\n",++cnt);
		if(ans) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
