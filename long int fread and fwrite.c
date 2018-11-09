#include<stdio.h>
int putl(long int l,FILE *in)
{
	if(fwrite(&l,sizeof(long int),1,in)>0)
		return 1;
	return 0;
}
long int getl(FILE *in)
{
	long int l;
	if(fread(&l,sizeof(long int),1,in)>0)
		return l;
	return 0;
}
main()
{
	FILE *in;
	long int i;
	i=1234565644;
	in=fopen("input.txt","wb+");
	putl(i,in);
	fseek(in,0,SEEK_SET);
	i=0L;
	i=getl(in);
	printf("%ld",i);
}
