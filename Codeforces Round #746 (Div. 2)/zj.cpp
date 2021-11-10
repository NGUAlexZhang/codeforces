#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1000000+10
using namespace std;
int sg[MAX];
int SG(int c,int s)
{
	memset(sg,0,sizeof(sg));
	sg[s]=0;
	int minn;
	for(int i=s-1;i>=c;i--)
	{
		if(i>1000||i+i*i>=s)
			sg[i]=s-i;
		else
		{
			sg[i]=0;
			s=i;
		}
			
	}
//	cout<<"SG: "<<c<<","<<s<<":"<<endl;
//	for(int i=0;i<10;i++)                      
//		cout<<sg[i]<<" ";
//	cout<<endl;
	return sg[c];
}

int main()
{
	int N;
	int ans;
	int c,s;
	int cnt=1;
	while(1)
	{
		scanf("%d",&N);
		if(!N)break;
		scanf("%d%d",&s,&c);
		ans=SG(c,s);
		for(int i=1;i<N;i++)
		{
			scanf("%d%d",&s,&c);
			ans=ans^SG(c,s);
			//cout<<SG(c,s)<<endl;
		}		
		printf("Case %d:\n",cnt++);
		if(ans)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}