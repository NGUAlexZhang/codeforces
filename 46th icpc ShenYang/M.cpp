#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int nxt[1000005];
int main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	cout<<"1 1"<<endl;
	int head=1,tot=1;
	for(int i=2;i<=len;i++){
		while(tot!=nxt[tot]&&s[head+nxt[tot]]<s[i]) head=head+(tot-nxt[tot]),tot=nxt[tot];
		if(s[i]==s[head+nxt[tot]]&&tot){
			tot++;
			nxt[tot]=nxt[tot-1]+1;
		}
		else{
			tot++;
			nxt[tot]=0;
		}
		printf("%d %d\n",head,i);
	}
	return 0;
}
