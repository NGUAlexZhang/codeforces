#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*ll a[]={1,2,4,4,6,8,8,10,12,12,14,16,16,18,20,20,22,24,
 24,26,28,28,30,32,32,34,36,36,38,40,40,42,44,44,
 46,48,48,50,52,52,54,56,56,58,60,60,62,64,64,66};*/
ll a[1500000];
ll sum[1500000];
int main(){
	/*int n=sizeof(a)/8-1;
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}*/
	a[1]=0;
	int cnt=0;
	for(int i=2;i<=100000;i++){
		cnt++;
		if(cnt%3==0) a[i]=a[i-1];
		else a[i]=a[i-1]+2;
	}
	//for(int i=1;i<=20;i++) cout<<a[i]<<" ";
	for(int i=1;i<=100000;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		int l=1,r=100000;
		while(l<=r){
			
			int mid=(l+r)>>1;//cout<<mid<<endl;
			if(sum[mid]>=n) r=mid-1;
			else l=mid+1;
		}
		cout<<r+1<<endl;
	}
	return 0;
}
