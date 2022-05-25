#include <bits/stdc++.h>
using namespace std;
char s[250000];
char ans[250000];int cnt;
int main(){
	int n;
	cin>>n;
	cin>>(s+1);
	for(int i=1;i<=n;i++){
		cnt++;
		ans[cnt]=s[i];
		while((cnt-2>0&&ans[cnt-2]=='f')&&(cnt-1>0&&ans[cnt-1]=='o')&&(ans[cnt]=='x')){
			cnt-=3;
		}
	}
	cout<<cnt;
	return 0;
}
