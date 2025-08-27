#include<stdio.h>
#include<math.h>
int main()
{   
     int n,r,a;
     printf("enter the how many terms are present in the geometric progression=");
	scanf("%d",&n);
	printf("enter the 1st term in the gp=");
	scanf("%d",&a);
    printf("enter the common ratio of your geomatric progression=");
	scanf("%d",&r);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum=sum+a;
		a=a*r;
	}
	printf("sum of the elements in the given gp is= %d",sum);
}