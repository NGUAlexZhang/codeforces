#include <bits/stdc++.h>
using namespace std;
double a[10][10],b[10],tmp[10][10];
int main(){
	bool cnm=0;
	double maxA=-1,maxB=-1;
	for(int i=1;i<=3;i++)
	for(int j=1;j<=2;j++){
		cin>>a[j][i];
		if(j==1) maxA=max(maxA,a[1][i]);
		else maxB=max(maxB,a[2][i]);
		if(a[j][i]==1) cnm=1;
	}
	a[3][1]=a[3][2]=a[3][3]=1;
	int n;
	cin>>n;
	while(n--){
		cin>>b[1]>>b[2];
		if(b[1]>maxA||b[2]>maxB){
			cout<<"NO\n";
			continue;
		}
		b[3]=1;
		for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++) tmp[i][j]=a[i][j];
		for(int i=1;i<=3;i++){
			for(int j=i;j<=3;j++){
				if(fabs(tmp[j][i])>1e-8){
					for(int k=1;k<=3;k++) swap(tmp[i][k],tmp[j][k]);
					swap(b[i],b[j]);
				}
			}
			for(int j=1;j<=3;j++){
				if(i==j) continue;
				double rate=tmp[j][i]/tmp[i][i];
				for(int k=i;k<=3;k++) tmp[j][k]-=tmp[i][k]*rate;
				b[j]-=b[i]*rate;
			}
		}
		bool flag=0;
		//for(int i=1;i<=3;i++) printf("%.3f ",b[i]/tmp[i][i]);
		//cout<<endl;
		for(int i=1;i<=3;i++) //printf("%.3f ",b[i]/tmp[i][i]);
			if((!cnm&&tmp[i][i]==0)||b[i]/tmp[i][i]<0) flag=1;
		if(flag) cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}
