#include <bits/stdc++.h>
using namespace std;
int a[150000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int num1=0,num2=0;
		bool flag=0;
		for(int i=1;i<=n;i++){
			//cout<<num2<<"  "<<a[i]<<endl;
			if((a[i]%2&&num1>a[i])||((a[i]%2==0)&&num2>a[i])){
				flag=1;
				break;
			}
			if(a[i]%2) num1=max(num1,a[i]);
			else num2=max(num2,a[i]);
			//cout<<num1<<"  "<<num2<<endl;
		}
		if(flag) puts("No");
		else puts("Yes");
	}
	return 0;
}
