#include <bits/stdc++.h>
using namespace std;
int T,cnt1,cnt2;
int a[10],b[10];
int main()
{
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		for (int i=1;i<=6;i++)
			scanf("%d",&a[i]);
		for (int i=1;i<=6;i++)
			scanf("%d",&b[i]);
		cnt1=0,cnt2=0;
		for (int i=1;i<=6;i++)
			for (int j=1;j<=6;j++)
			{
				if (a[i]>b[j]) ++cnt1;
				if (a[i]<b[j]) ++cnt2;
			}
		if (cnt1>cnt2) printf("Alice\n");
		else if (cnt1<cnt2) printf("Bob\n");
		else printf("Tie\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
