#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[550000],fen[550000],a[550000],pre[550000],ord[550000];
const int inf=1e16;
int n;
int lsb(int a) {
    return (a & -a);
}
void add(int pos, ll val) {
    while (pos<=n) {
        fen[pos]=max(fen[pos], val);
        pos+=lsb(pos);
    }
}
ll ask(int pos) {
    ll val=-inf;
    while (pos) {
        val=max(fen[pos], val);
        pos-=lsb(pos);
    }
    return val;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		vector<pair<ll,int> >p;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1]+a[i];
			p.push_back(make_pair(pre[i],-i));
		}
		sort(p.begin(),p.end());
		for(int i=0;i<n;i++){
			ord[-p[i].second]=i+1;
		}
		for(int i=1;i<=n;i++){
			fen[i]=-inf;
		}
		for(int i=1;i<=n;i++){
			dp[i]=(dp[i-1]+(a[i]<0 ? -1 : a[i]>0 ? 1 : 0));
			dp[i]=max(dp[i], ask(ord[i])+i);
            if (pre[i]>0) dp[i]=i;
			add(ord[i], dp[i]-i);
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}