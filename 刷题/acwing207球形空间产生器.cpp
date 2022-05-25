#include <bits/stdc++.h>
using namespace std;
double a[30][30],b[30],c[30][30];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n;j++) scanf("%lf",&a[i][j]);
	}
	//cout<<a[2][1]*a[2][1]-a[3][1]*a[3][1]<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//cout<<b[i]<<endl;
			c[i][j]=2*(a[i][j]-a[i+1][j]);
			b[i]+=a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j];
			//cout<<c[i][j]<<" "<<a[i][j]*a[i][j]-a[i+i][j]*a[i+1][j]<<" "<<i<<" "<<j<<endl;
		}
		//cout<<b[i]<<endl;
	}

	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(fabs(c[j][i])>1e-8){
				for(int k=1;k<=n;k++)
					swap(c[i][k],c[j][k]);
				swap(b[i],b[j]);
			}
		}
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			double rate=c[j][i]/c[i][i];
			for(int k=1;k<=n;k++) c[j][k]-=c[i][k]*rate;
			b[j]-=b[i]*rate;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%.3f ",b[i]/c[i][i]);
	}
	return 0;
}
