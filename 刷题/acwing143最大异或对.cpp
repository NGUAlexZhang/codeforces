#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[50],tot=1;
int trie[5000000][2];
ll ans;
void get(){
	int p=1;ll res=0;
	for(int i=31;i>=1;i--){
		int ch=a[i];
		if(trie[p][ch^1]){
			res+=(1<<(i-1));
			p=trie[p][ch^1];
		}
		else p=trie[p][ch];
	}
	ans=max(ans,res);
}
void insert(){
	int p=1;
	for(int i=31;i>=1;i--){
		int ch=a[i];
		if(trie[p][ch]==0) trie[p][ch]=++tot;
		p=trie[p][ch];
	}
}
int main(){
	cin>>n;
	int flag=0;
	while(n--){
		int x;
		cin>>x;
		for(int i=30;i>=0;i--)
			a[i+1]=(x>>i)&1;
		if(flag) get();
		insert();
		flag=1;
	}
	cout<<ans;
	return 0;
}
