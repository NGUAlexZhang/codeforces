#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		if(n==1||m==1){
			int tmp=(n==1)?m:n;
			cout<<(tmp-1)/3+1<<endl;
			continue;
		}
		int tmp=m/3;
		int sum1=0,sum2=0;
		sum1=tmp*n;
		if(m%3){
			sum1+=(m%3)*(n/3);
			sum1+=n%3;
		}
		tmp=n/3;
		sum2=tmp*m;
		if(n%3){
			sum2+=(n%3)*(m/3);
			sum2+=m%3;
		}
		cout<<min(sum1,sum2)<<endl;
	}
	return 0;
}
