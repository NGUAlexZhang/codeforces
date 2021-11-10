#include <bits/stdc++.h>
using namespace std;
int main(){
	char s[1005];
	scanf("%s",s+1);
	int len=strlen(s+1);
	int point=len+1;
	for(int i=1;i<=len;i++){
		if(s[i]=='.'){
			point=i;
			break;
		}
	}
	for(int i=1;i<point;i++) printf("%c",s[i]);
	printf("\n");
	int end=0;
	for(int i=len;i>=point;i--){
		if(s[i]!='0'){
			end=i;
			break;
		}
	}
	for(int i=point+1;i<=end;i++) printf("%c",s[i]);
	return 0;
}