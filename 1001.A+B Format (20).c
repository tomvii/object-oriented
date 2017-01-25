#include<stdio.h>
int main()
{
	int a,b,sum,d,e,u,digit,j,w=0,l[10]={0};
	digit=1;
	scanf("%d%d",&a,&b);
	sum=a+b;
	if(sum<0)
	{
		sum=-sum;
		printf("-");
	}
	d=sum;
	while(d>0)
	{
		d=d/10;
		digit=digit+1;
	}
	digit=digit-1;
	if(sum==0)
		digit=digit+1;
	for(j=0;j<digit;j++)
	{
		e=sum%10;
		l[digit-j]=e;
		sum=sum/10;
	}
	u=digit%3;
	for(j=1;j<=u;j++)
		printf("%d",l[j]);
	if(digit==3)
	{
		for(j=1;j<=3;j++)
			printf("%d",l[j]);    //3 digits
	}
	while(digit>3&&u<digit)
	{
		if(u!=0)
			printf(",");
		for(j=1;j<=3;j++)       
			printf("%d",l[u+j]);
		u=u+3;
	}
	return 0;
}