#include <bits/stdc++.h>
using namespace std;
char s[100005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		cin>>(s+1);
		int len=strlen(s+1);
		int x=0,y=0;
		int ansx=1,ansy=1;
		bool flag=0;
		int minx=1,maxx=n,miny=1,maxy=m;
		for(int i=1;i<=len;i++){
			if(s[i]=='L') y--;
			if(s[i]=='R') y++;
			if(s[i]=='U') x--;
			if(s[i]=='D') x++;
			if(x<0){
				if(maxx+x<1) break;
				minx=max(minx,1+abs(x));
			}
			else{
				if(minx+x>n) break;
				maxx=min(maxx,n-x);
			}
			if(y<0){
				if(maxy+y<1) break;
				miny=max(miny,1+abs(y));
			}
			else{
				if(miny+y>m) break;
				maxy=min(maxy,m-y);
			}
			//cout<<i<<endl;
		}
		cout<<minx<<" "<<miny<<endl;
	}
	return 0;
}
