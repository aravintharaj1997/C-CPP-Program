#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
unsortint(FILE *sort,FILE *index,FILE *out)
{
	int *a, *ind;
	int i=0,j,n=0,in=0,temp,min;
	char str[4],c;
	fseek(sort,0,SEEK_SET);
	fseek(index,0,SEEK_SET);
	while((c=fgetc(sort))!=EOF)
	{
		if ((c==' ')||(c==',')||(c == '.')||(c =='\n')||(c=='\t'))
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
	i=0;
	while((c=fgetc(index))!=EOF)
	{
		if ((c==' ')||(c==',')||(c == '.')||(c =='\n')||(c=='\t'))
		{
			str[i]='\0';
			if(in==0)
			{
				ind=(int *)malloc(sizeof(int));
			}
			else
				ind=(int *)realloc(ind,(in+1)*sizeof(int));
			ind[in++]=atoi(str);
			i=0;
			str[0]='\0';
		}
		else
		{
			str[i++]=c;
		}
	}
	for(i=in-1;i>=0;i--)
	{
				min=ind[i];
				temp=a[i];
				a[i]=a[min];
				a[min]=temp;

	}
	for(i=0;i<n;i++)
	{
		itoa(a[i],str,10);
		fputs(str,out);
		fputc(' ',out);
	}
	free(a);
	free(ind);
}
main(int argc,char **argv)
{
	FILE *sort, *index, *out;

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
	sort=fopen(argv[1],"r");
	index=fopen(argv[2],"r");	
	out=fopen(argv[3],"w");
	if((out==NULL)||(sort==NULL)||(index==NULL))
	{
		fprintf(stderr, "Can't open input file in list!\n");
		exit(1);
	}
	unsortint(sort,index,out);
	printf("Successfully run");
	fclose(sort);
	fclose(index);
	fclose(out);
}
