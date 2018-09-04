#include<stdio.h>
finsposc(FILE *f,long pos,char c)
{
	char nc;
	fseek(f,pos,SEEK_SET);
	while((nc=fgetc(f))!=EOF)
	{
		fseek(f,-1,SEEK_CUR);
		fputc(c,f);
		fseek(f,0,SEEK_CUR);
		c=nc;
	}
	fputc(c,f);
}
fdelposc(FILE *f,long pos)
{
	char c;
	fseek(f,pos+1,SEEK_SET);
	while((c=fgetc(f))!=EOF)
	{
		fseek(f,-2,SEEK_CUR);
		fputc(c,f);
		fseek(f,1,SEEK_CUR);
	}
	fseek(f,-1,SEEK_END);
	ftruncate(fileno(f), ftello(f));
}
main()
{
	FILE *f=fopen("Te.txt","w+");
	fputs("aravintharaj",f);
	finsposc(f,1L,'5');
	fdelposc(f,11L);
	fclose(f);
}
