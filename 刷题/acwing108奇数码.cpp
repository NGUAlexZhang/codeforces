#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[250005],n,b[250005];
ll ans;
void mysort(int l,int r){
	if(l>r) return;
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
		for(int i=1;i<=n*n;i++) cin>>a[i];
		ans=0;
		for(int i=1;i<=n*n;i++){
			if(a[i]==0){
				for(int j=i;j<n*n;j++) a[j]=a[j+1];
				break;
			}
		}
		//for(int i=1;i<n*n;i++) cout<<a[i]<<" ";
		//cout<<endl;
		mysort(1,n*n-1);
		ll ans1=ans;
		for(int i=1;i<=n*n;i++) cin>>a[i];
		ans=0;
		for(int i=1;i<=n*n;i++){
			if(a[i]==0){
				for(int j=i;j<n*n;j++) a[j]=a[j+1];
				break;
			}
		}
		mysort(1,n*n-1);
		ll ans2=ans;
		//cout<<ans1<<" "<<ans2<<endl;
		if(ans1%2==ans2%2){
			cout<<"TAK"<<endl;
		}
		else cout<<"NIE"<<endl;
	}
	return 0;
}
