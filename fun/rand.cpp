#include <bits/stdc++.h>
#define Maxn 200007
#define modp 1000000007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,q;
int last[Maxn],other[Maxn],pre[Maxn],cnt=0;
int pos1[Maxn],pos2[Maxn],que[Maxn],m=0;
int p[7];
char op[57];
int s[7][Maxn*2];
long long power(long long a,long long b)
{
	long long ans=1,now=a,left=b;
	while (left>0)
	{
		if (left%2==1) ans=(1LL*ans*now)%modp;
		left/=2;
		now=(1LL*now*now)%modp;
	}
	return ans;
}
void add(int id,int pos,int val)
{
	while (pos<=2*n)
	{
		s[id][pos]=(s[id][pos]+val)%modp;
		pos+=pos&(-pos);
	}
}
int query(int id,int pos)
{
	int res=0;
	while (pos>0)
	{
		res=(res+s[id][pos])%modp;
		pos-=pos&(-pos);
	}
	return res;
}
void insert(int u,int v)
{
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u,int fa)
{
	pos1[u]=++m;
	que[m]=u;
	for (int q=last[u];q;q=pre[q])
	{
		int v=other[q];
		if (v!=fa) dfs(v,u);
	}
	pos2[u]=m;
}
void update(int pos,int val)
{
	for (int i=1;i<=6;i++)
	{
		int del=0;
		while (val%p[i]==0)
		{
			val/=p[i];
			++del;
		}
		add(i,pos,del);
	}
}
int main()
{
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	p[1]=2,p[2]=3,p[3]=5,p[4]=7,p[5]=11,p[6]=13;
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read()+1,v=read()+1;
		insert(u,v),insert(v,u);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
	{
		int x=read();
		update(pos1[i],x);
	}
	q=read();
	while (q--)
	{
		scanf("%s",op);
		if (op[0]=='R')
		{
			int u=read()+1;
			long long ans=1,cnt=1;
			for (int i=1;i<=6;i++)
			{
				int sum=query(i,pos2[u])-query(i,pos1[u]-1);
				ans=(1LL*ans*power(p[i],sum))%modp;
				cnt=(1LL*cnt*(sum+1))%modp;
			}
			printf("%lld %lld\n",ans,cnt);
		} else
		{
			int u=read()+1,x=read();
			update(pos1[u],x);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}