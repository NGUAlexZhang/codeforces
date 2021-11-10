#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[150000],b[150000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n%2==0){
			for(int i=1;i<=n;i+=2){
					cout<<-a[i+1]<<" "<<a[i]<<" ";
					b[i]=-a[i+1],b[i+1]=a[i];
				/*else {
					cout<<a[i+1]<<" "<<a[i]<<" ";
					b[i]=a[i+1],b[i+1]=a[i];
				}*/
			}
		}
		else{
			for(int i=1;i<=n-3;i+=2){
					cout<<-a[i+1]<<" "<<a[i]<<" ";
					b[i]=-a[i+1],b[i+1]=a[i];
				/*else {
					cout<<a[i+1]<<" "<<a[i]<<" ";
					b[i]=a[i+1],b[i+1]=a[i];
				}*/
			}
			ll sum1=0,sum2=0;
			int index=0;
			for(int i=n-2;i<=n;i++){
				int sum=0;
				for(int j=n-2;j<=n;j++){
					if(i==j) continue;
					sum+=a[j];
				}
				if(sum==0) continue;
				index=i;
				sum1=sum,sum2=a[i];
			}
			int ans1,ans2;
			ans1=-sum2,ans2=sum1;
			for(int i=n-2;i<=n;i++){
				if(i==index) {
					cout<<ans2<<" ";
					b[i]=ans2;
				}
				else {
					cout<<ans1<<" ";
					b[i]=ans1;
				}
			}
			
		}
		ll sum=0;
		for(int i=1;i<=n;i++) sum+=a[i]*b[i];
		cout<<endl;
		//cout<<sum<<endl;
	}
	return 0;
}
