#include<stdio.h>
int min2(int a,int b){if(a>b)return b;return a;}
int main()
{
	int l;
	while(scanf("%d",&l)!=EOF&&l)
	{
		int n;
		scanf("%d",&n);
		int i,j,k,a[60];
		int kx[60][60][60];	//kx[i][j][k]��ʾ�� a[i]��a[k]֮���ж�a[j] i<j<k 
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		a[0]=0;
		a[n+1]=l;
		for(i=0;i<=n+1;i++)for(j=i+1;j<=n+1;j++)for(k=j+1;k<=n+1;k++)kx[i][j][k]=a[k]-a[i];
		int dp[60][60];		//dp[i][j]��ʾ��a[i]��a[j]֮�����еĶ��е����ܴﵽ����С���� 
		i=0;
		for(j=0;j<=n+1-i;j++)dp[j][j+i]=0;
		i=1;
		for(j=0;j<=n+1-i;j++)dp[j][j+i]=0;
		for(i=2;i<=n+1;i++)
		{
			for(j=0;j<=n+1-i;j++)
			{
				//Ŀ��dp[j][j+i]=min(dp[j,k]+dp[k,i+j]+kx[i,k,i+j])
				int min=2147483630;
				for(k=j+1;k<=j+i-1;k++)min=min2(min,dp[j][k]+dp[k][i+j]+kx[j][k][i+j]);
				dp[j][j+i]=min;
				}
			}
	//	for(i=n+1;i>=0;i--){for(j=0;j<=n+1;j++)printf("%6d",dp[i][j]);printf("\n");}
		printf("The minimum cutting is %d.\n",dp[0][n+1]);
		}
	return 0;
	}
