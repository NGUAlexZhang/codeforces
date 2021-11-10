#include <bits/stdc++.h>
using namespace std;
map<int,int>m;
int b[1000000],c[1000000];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		m[x]++;
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=q;i++) scanf("%d",&c[i]);
	int index=1;
	for(int i=1;i<=q;i++){
		if(m[b[index]]<m[b[i]]){
			index=i;
		}
		else
		if(m[b[index]]==m[b[i]]){
			if(m[c[index]]<m[c[i]]){
				index=i;
			}
		}
	}
	cout<<index;
	return 0;
}
