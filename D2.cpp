#include <bits/stdc++.h>
using namespace std;
char s[350005];
int sum[350005],a[350005];
int main(){
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,q;
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1];
			a[i]=(s[i]=='+'?1:-1);
			a[i]*=(i%2?1:-1);
			sum[i]+=a[i];
		}
		map<int,vector<int> >m[2];
		for(int i=0;i<n;i++){
			if(a[i+1]==-1) m[0][sum[i]].push_back(i);
			else m[1][sum[i]].push_back(i);
		}
		//cout<<sum[14]-sum[3]<<endl;
		//m[0][0].push_back(0);m[1][0].push_back(0);
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			if(sum[r]==sum[l-1]){
				printf("0\n");
				continue;
			}
			int x=sum[r]-sum[l-1];
			int ans=(x%2?1:2);
			printf("%d\n",ans);
			if(ans==2){
				printf("%d ",l);
				l++;
			}
			x=sum[r]-sum[l-1];
			int tar=(x+1)/2;
			int index=lower_bound(m[0][tar+sum[l-1]].begin(),m[0][tar+sum[l-1]].end(),l-1)-m[0][tar+sum[l-1]].begin();
			//cout<<index<<endl;
			if(index<m[0][tar+sum[l-1]].size()&&m[0][tar+sum[l-1]][index]<r){
				printf("%d\n",m[0][tar+sum[l-1]][index]+1);
				continue;
			}
			tar=(x-1)/2;
			index=lower_bound(m[1][tar+sum[l-1]].begin(),m[1][tar+sum[l-1]].end(),l-1)-m[1][tar+sum[l-1]].begin();
			//cout<<index<<endl;
			printf("%d\n",m[1][tar+sum[l-1]][index]+1);
		}
	}
	return 0;
}