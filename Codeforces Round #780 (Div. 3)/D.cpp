#include <bits/stdc++.h>
using namespace std;
int a[250000],num20[250000],num21[250000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,sum=0,maxn=0,ans1=0,ans2=0;
		cin>>n;
		vector<int>zero,fu;
		for(int i=1;i<=n;i++) cin>>a[i];
		a[0]=a[n+1]=0;
		num20[0]=0;
		for(int i=0;i<=n+1;i++){
			if(a[i]==0) zero.push_back(i);
			if(a[i]<0) fu.push_back(i);
			if(i==0) continue;
			num20[i]=num20[i-1]+(a[i]==2||a[i]==-2);
		}
		num21[n+1]=0;
		for(int i=n;i>=0;i--){
			num21[i]=num21[i+1]+(a[i]==2||a[i]==-2);
			sum+=(a[i]==2||a[i]==-2);
		}
		int p=0;
		for(int i=0;i<zero.size()-1;i++){
			int loc1=zero[i],loc2=zero[i+1];
			while(p<fu.size()&&fu[p]<loc1) p++;
			int cnt=0;
			vector<int>inner;
			for(int j=p;j<fu.size()&&fu[j]<loc2;j++){
				inner.push_back(fu[j]);
			}
			//cout<<inner.size()<<endl;
			/*for(int i=0;i<=n+1;i++){
				cout<<num20[i]<<" "<<num21[i]<<endl;
			}
			cout<<sum<<endl;*/
			//cout<<inner.size()<<endl;
			if(inner.size()%2==0){
				int tmp=sum-num20[loc1]-num21[loc2];
				//cout<<tmp<<endl;
				if(tmp>maxn){
					ans1=loc1,ans2=loc2;
					maxn=tmp;
				}
			}
			else{
				for(int j=0;j<inner.size();j+=2){
					//cout<<inner[j]<<endl;
					int tmp=sum-num20[inner[j]]-num21[loc2];
					//cout<<tmp<<" ";
					if(tmp>maxn){
						ans1=inner[j],ans2=loc2;
						maxn=tmp;
					}
					tmp=sum-num20[loc1]-num21[inner[j]];
					//cout<<tmp<<endl;
					if(tmp>maxn){
						ans1=loc1,ans2=inner[j];
						maxn=tmp;
					}
				}
			}
		}
		if(maxn==0){
			//cout<<"11\n";
			cout<<n<<" 0"<<endl;
		}
		else{
			cout<<ans1<<" "<<n+1-ans2<<endl;
		}
	}
	return 0;
}
