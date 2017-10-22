#include <bits/stdc++.h>
#define Maxn 307
#define inf 300000007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m;
int c[Maxn],p[Maxn][Maxn];
int f[Maxn][Maxn];
int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	n=read(),m=read();
	memset(c,0,sizeof(c));
	memset(p,0,sizeof(p));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			c[j]=read();
		sort(c+1,c+m+1);
		p[i][0]=0;
		for (int j=1;j<=m;j++)
			p[i][j]=p[i][j-1]+c[j];
	}
	f[0][0]=0;
	for (int i=1;i<=n;i++) f[0][i]=inf;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
		{
			f[i][j]=inf;
			for (int k=i-1;k<=j;k++)
				if (j-k<=m) f[i][j]=min(f[i][j],f[i-1][k]+p[i][j-k]+(j-k)*(j-k));
		}
	printf("%d\n",f[n][n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}