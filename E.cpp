#include <bits/stdc++.h>
using namespace std;
char s[5005];
string ss[5000*5000];
bool cmp(string a,string b){
	int lena=a.size(),lenb=b.size();
	for(int i=0;i<min(lena,lenb);i++){
		if(a[i]<b[i]) return 0;
		if(a[i]>b[i]) return 1;
	}
	return lena>lenb;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		int ans=0;
		for(int i=1;i<=n;i++){
		string all;
		for(int j=i;j<=n;j++){
			all+=s[j];
			if(ans==0||cmp(all,ss[ans])){
				ss[++ans]=all;
				continue;
			}
			int l=1,r=ans;
			while(l<=r){
				int mid=(l+r)>>1;
				if(cmp(ss[mid],all)){
					r=mid-1;
				}
				else l=mid+1;
			}
			if(ss[r]!=all)
				ss[r+1]=all;
		}
		}
		printf("%d\n",ans);
	}
	return 0;
}