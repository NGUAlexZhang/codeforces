#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Node{
	ll pre,nxt;
	ll sum;
	bool flag;
	Node(){
		pre=nxt=sum=flag=0;
	}
	Node(ll ans1,ll ans2,ll ans3,bool ans4){
		pre=ans1,nxt=ans2,sum=ans3;
		flag=ans4;
	}
}node[(200005<<2)+5];
int a[200005];
void push_up(int mid,int rt){
	node[rt].sum=node[rt<<1].sum+node[rt<<1|1].sum;
	if(a[mid]<=a[mid+1]){
		node[rt].sum+=node[rt<<1].nxt*node[rt<<1|1].pre;
	}
	node[rt].pre=node[rt<<1].pre;
	if(node[rt<<1].flag&&a[mid]<=a[mid+1])
		node[rt].pre+=node[rt<<1|1].pre;
	node[rt].nxt=node[rt<<1|1].nxt;
	if(node[rt<<1|1].flag&&a[mid]<=a[mid+1])
		node[rt].nxt+=node[rt<<1].nxt;
	node[rt].flag=node[rt<<1].flag&&node[rt<<1|1].flag&&a[mid]<=a[mid+1];
}
void build(int l,int r,int rt){
	if(l==r){
		node[rt].pre=node[rt].nxt=node[rt].sum=1;
		node[rt].flag=1;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	push_up(mid,rt);
}
void update(int l,int r,int tar,int y,int rt){
	if(l==r){
		a[l]=y;
		node[rt].pre=node[rt].nxt=node[rt].sum=1;
		node[rt].flag=1;
		return;
	}
	int mid=(l+r)>>1;
	if(tar<=mid) update(l,mid,tar,y,rt<<1);	
	else update(mid+1,r,tar,y,rt<<1|1);
	push_up(mid,rt);
}
Node query(int l,int r,int L,int R,int rt){
	if(l>=L&&r<=R){
		Node tmp(node[rt].pre,node[rt].nxt,node[rt].sum,node[rt].flag);
		return tmp;
	}
	Node ans1,ans2;
	int mid=(l+r)>>1;
	if(L<=mid) ans1=query(l,mid,L,R,rt<<1);
	if(R>mid) ans2=query(mid+1,r,L,R,rt<<1|1);
	if(ans1.sum==0) return ans2;
	if(ans2.sum==0) return ans1;
	Node ans(ans1.pre,ans2.nxt,ans1.sum+ans2.sum,0);
	if(a[mid]<=a[mid+1]){
		ans.sum+=ans1.nxt*ans2.pre;
	}
	if(ans1.flag&&a[mid]<=a[mid+1]) ans.pre+=ans2.pre;
	if(ans2.flag&&a[mid]<=a[mid+1]) ans.nxt+=ans1.nxt;
	ans.flag=ans1.flag&&ans2.flag&&a[mid]<=a[mid+1];
	return ans;
}
void debug(int l,int r,int rt){
	cout<<l<<" "<<r<<" "<<node[rt].sum<<" "<<node[rt].pre<<" "<<node[rt].nxt<<" "<<node[rt].flag<<endl;
	if(l==r) return;
	int mid=(l+r)>>1;
	debug(l,mid,rt<<1);
	debug(mid+1,r,rt<<1|1);
}
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,n,1);
	while(q--){
		int opt,l,r;
		cin>>opt>>l>>r;
		if(opt==1){
			update(1,n,l,r,1);
		}
		else{
			Node ans=query(1,n,l,r,1);
			cout<<ans.sum<<endl;
		}
	}
	return 0;
}