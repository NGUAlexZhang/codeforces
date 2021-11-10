#include <bits/stdc++.h>
using namespace std;
struct Point{
	double x,y,dis;
	int m;
}p[1000];
int cnt=1;
bool cmp(Point a,Point b){
	if(a.dis==b.dis){
		if(a.m==b.m){
			if(a.m==1||a.m==2) return a.y<b.y;
			return a.y>b.y;
		}
		return a.m<b.m;
	}
	return a.dis<b.dis;
}
int main(){
	scanf("%lf,%lf",&p[1].x,&p[1].y);
	p[1].dis=sqrt(p[1].x*p[1].x+p[1].y*p[1].y);
	if(p[1].x>=0){
		if(p[1].y>=0) p[1].m=1;
		else p[1].m=2;
	}
	else{
		if(p[1].y>=0) p[1].m=4;
		else p[1].m=3;
	}
	
	while(scanf(",%lf,%lf",&p[++cnt].x,&p[cnt].y)!=EOF){
		p[cnt].dis=sqrt(p[cnt].x*p[cnt].x+p[cnt].y*p[cnt].y);
		if(p[cnt].x>=0){
			if(p[cnt].y>=0) p[cnt].m=1;
			else p[cnt].m=2;
		}
		else{
			if(p[cnt].y>=0) p[cnt].m=4;
			else p[cnt].m=3;
		}
	}
	sort(p+1,p+1+cnt,cmp);
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		if(i==1){
			cout<<p[i].x<<","<<p[i].y<<",";	
			continue;
		}
		cout<<","<<p[i].x<<","<<p[i].y;
	}
	return 0;
}