#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		double a, b, c, x0, x1, y0, y1, y2;
		cin >> a >> b >> c;
		cin >> x0 >> x1 >> y0 >> y1 >> y2;
		if(x0*x0*a+b*x0+c<=y0){
			cout<<"No"<<endl;
			continue;
		}
		if(x1*x1*a+b*x1+c==y0){
			cout<<"No"<<endl;
			continue;
		}
		if(x1*x1*a+b*x1+c<y0){
			cout<<"Yes"<<endl;
			continue;
		}
		double y=x1*x1*a+b*x1+c;
		if(y>y2||y<y1){
			cout<<"No"<<endl;
			continue;
		}
		x1+=(x1-x0);
		y=x1*x1*a+b*x1+c;
		if(y<y0){
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
	return 0;
}
