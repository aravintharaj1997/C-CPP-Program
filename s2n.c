#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
	long long int n=0;
	int i;
	char a[]="Test",t[10];
	for(i=0;a[i]!='\0';i++)
		n=(n*1000)+((int)a[i]);
	printf("%lld",n);
	i=0;
	while(n!=0)
	{
		t[i++]=n%1000;
		n/=1000;
	}
	t[i]='\0';
	strrev(t);
	printf("\n%s",t);
}
