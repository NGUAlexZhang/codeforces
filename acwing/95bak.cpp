// 思路：我们枚举第一行的点击方法，共32种，完成第一行的点击后，固定第一行，
// 从第一行开始递推，若达到第n行不全为0，说明这种点击方式不合法。
// 在所有合法的点击方式中取点击次数最少的就是答案。
// 对第一行的32次枚举涵盖了该问题的整个状态空间，因此该做法是正确的
// 
// 时间复杂度：32*20*5*500 = 一百六十万
// 对第一行操作有32种可能 * 对前四行有20种操作可能 * 每一次操作都要改变5个灯的状态 * 最多读入的时候可能有500次light矩阵
//
// 最关键的两个性质
// 每一个位置最多只会被点击一次
// 如果固定了第一行，那么满足题意的点击方案最多只有一种
#include <bits/stdc++.h>
using namespace std;

const int N = 10;

char g[N][N];

void turn(int x,int y)
{
    int dx[5]={0,1,0,-1,0},dy[5]={0,0,1,0,-1};
    for(int i=0;i<5;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx>=0 && xx<5 && yy>=0 && yy<5)
        {
            g[xx][yy]^=1;
        }
    }
}

int work()
{
    int ans = 0x3f3f3f3f;
    for(int k=0;k< 1<<5;k++)
    {
        int res=0;
        char temp[N][N];
        memcpy(temp,g,sizeof g);
        for(int j=0;j<5;j++)
        {
            if(k>>j & 1)
            {
                res++;
                turn(0,j);
            }
        }
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(g[i][j]=='0')
                {
                    res++;
                    turn(i+1,j);
                }
            }
        }

        bool flag=true;
        for(int i=0;i<5;i++)
        {
            if(g[4][i]!='1')
            {
                flag=false;
                break;
            }
        }
        if(flag) ans = min(ans,res);
        memcpy(g,temp,sizeof g);
    }
    if(ans>6) return -1;
    else return ans;
}

int main()
{
    int n; cin>>n;
    while(n--)
    {
        for(int i=0;i<5;i++) cin>>g[i];
        cout<< work() <<endl;   
    }   
    return 0;
}