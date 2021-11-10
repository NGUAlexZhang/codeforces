#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[1000000];
bool cmp(ll a,ll b)
{
	return a<b;
}
int main()
{
	int n,m;
	ll def,atk,poww=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]),poww+=a[i];
	
	sort(a,a+n,cmp);
	//for(int i=0;i<n;i++) cout<<a[i]<<" ";
	//cout<<endl;
//	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	//cout<<endl;
	scanf("%d",&m);
	for(int i=0;i<m;i++) 
	{
		ll pow=poww;
		ll num=0;
		scanf("%lld%lld",&def,&atk);
		if(a[0]>def) 
		{
			pow-=a[0];
			if(atk>pow)	num+=(atk-pow);
		}
		else if(a[n-1]<def) 
		{
			//cout<<"an-1 "<<a[n-1]<<endl;
			pow-=a[n-1],num+=(def-a[n-1]);	
			//cout<<"pow"<<pow<<endl;
			if(atk>pow)	
			{
				num+=(atk-pow);
				
			}
		}
		else
		{
			int pos=lower_bound(a,a+n,def)-a;
			//cout<<pos<<" "<<a[1]<<endl;
			ll num1,num2,pow1,pow2;
			num1=num;
			num2=num;
			pow1=pow;
			pow2=pow;
			num2+=def-a[pos-1];
			pow1-=a[pos];
			pow2-=a[pos-1];
			//cout<<pow1<<" "<<a[1]<<endl;
			if(atk>pow1) num1+=(atk-pow1);
			if(atk>pow2) num2+=(atk-pow2);
			//cout<<num1<<" "<<num2<<endl;
			num=min(num1,num2);
			//cout<<a[1]<<endl;
			
		}
		cout<<num<<endl;
	}
	return 0;
}
