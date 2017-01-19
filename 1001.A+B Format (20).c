#include<stdio.h>
int main()
{
	int a,b,c,d,e,u,i,j,w=0,l[10]={0};
	i=1;
	scanf("%d%d",&a,&b);
	c=a+b;
	if(c<0)
	{
		c=-c;
		printf("-");
	}
	d=c;
	while(d>0)
	{
		d=d/10;
		i=i+1;
	}
	i=i-1;
	if(c==0)
		i=i+1;
	for(j=0;j<i;j++)
	{
		e=c%10;
		l[i-j]=e;
		c=c/10;
	}
	u=i%3;
	for(j=1;j<=u;j++)
		printf("%d",l[j]);
	if(i==3)
	{
		for(j=1;j<=3;j++)
			printf("%d",l[j]);   //漏掉的3位数情况！！！
	}
	while(i>3&&u<i)
	{
		if(u!=0)
			printf(",");
		for(j=1;j<=3;j++)
			printf("%d",l[u+j]);
		u=u+3;
	}

	return 0;
}