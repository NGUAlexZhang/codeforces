#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[550000],n,b[550000];
ll ans;
void mysort(int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	mysort(l,mid);
	mysort(mid+1,r);
	int i=l,j=mid+1;
	int cnt=l-1;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){
			b[++cnt]=a[i];
			i++;
		}
		else{
			b[++cnt]=a[j];
			ans+=(mid-i+1);
			j++;
		}
	}
	while(i<=mid) b[++cnt]=a[i],i++;	
	while(j<=r) b[++cnt]=a[j],j++;
	for(i=l;i<=r;i++) a[i]=b[i];
}
int main(){
	while(cin>>n){
		if(n==0) return 0;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0;
		mysort(1,n);
		cout<<ans<<endl;
	}
	return 0;
}
