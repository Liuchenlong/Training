#include<stdio.h>		//n���˲μӣ�ÿ��������m���˳��ھ�������һ��
int main()
{
	int n,m;
	int z,k;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		scanf("%d%d",&n,&m);
		int res=1;
		while(n>m){res++;n-=m-1;} 
		if(n==m)printf("%d\n",res); 
		else printf("cannot do this\n");
		} 
	return 0;
	} 
