#include <bits/stdc++.h>
using namespace std;
int a[250000],sum[250000];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),
		sum[i]=sum[i-1]^a[i];
		if(n%2){
			if(sum[n]){
				printf("NO\n");
				continue;
			}
			cout<<"YES"<<endl;
			printf("%d\n",n/2*2-1);
			for(int i=1;i<n;i+=2) printf("%d ",i);
			for(int i=n-4;i>=1;i-=2) printf("%d ",i);
			printf("\n");
		}
		else{
			int index=0;
			for(int i=1;i<=n;i+=2){
				if(sum[i]==0&&sum[n]^sum[i]==0){
					index=i;
					break;
				}
			}

			if(!index){
				printf("NO\n");
				continue;
			}
			cout<<"YES"<<endl;
			printf("%d\n",max(index/2*2-1,0)+max((n-index)/2*2-1,0));
			for(int i=1;i<index;i+=2){
				printf("%d ",i);
			}
			for(int i=index-4;i>=1;i-=2) printf("%d ",i);
			for(int i=index+1;i<n;i+=2) printf("%d ",i);
			for(int i=n-4;i>=index+1;i-=2) printf("%d ",i);
			cout<<endl;
		}
	}
	return 0;
}
