#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
sortint(FILE *in , FILE *out, FILE *outi)
{
	int *a;
	char c,str[4];
	int i=0,n=0,min,j,temp;
	fseek(in,0,SEEK_SET);
	while(c!=EOF)
	{
		c=fgetc(in);
		if ((c==-1)||(c==' ')||(c==',')||(c == '.')||(c =='\n')||(c=='\t'))
		{
			str[i]='\0';
			if(n==0)
			{
				a=(int *)malloc(sizeof(int));
			}
			else
				a=(int *)realloc(a,(n+1)*sizeof(int));
			a[n++]=atoi(str);
			i=0;
			str[0]='\0';
		}
		else
		{
			str[i++]=c;
		}
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;	
			}
		}
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
			itoa(min,str,10);
			fputs(str,outi);
			fputc(' ',outi);
	}
	for(i=0;i<n;i++)
	{
		itoa(a[i],str,10);
		fputs(str,out);
		fputc(' ',out);
	}
	free(a);
	
}
main(int argc,char **argv)
{
	FILE *in, *sort, *index;

	if((argv[1]==NULL)||(argv[2]==NULL)||(argv[3]==NULL))
	{
		printf("Enter the file name\n");
		exit(1);
	}
	if((argv[4]!=NULL))
	{
		printf("Enter three file name only");
		exit(1);
	}
	in=fopen(argv[1],"r");
	sort=fopen(argv[2],"w");
	index=fopen(argv[3],"w");	
	if((in==NULL)||(sort==NULL)||(index==NULL))
	{
		fprintf(stderr, "Can't open input file in list!\n");
		exit(1);
	}
	sortint(in,sort,index);
	printf("Successfully run");
	fclose(in);
	fclose(sort);
	fclose(index);
}
