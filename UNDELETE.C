#include<stdio.h>
#include<conio.h>
char filename[]="input.txt";
void main()
{
	FILE *input,*undo,*temp;
	char c,uc;
	int count,pos,choice;
	clrscr();
	input=fopen(filename,"w+");
	temp=fopen("t","w+");
	undo=fopen("undo","w+");
	for(;choice!=4;)
	{
		printf("\n1. Write\n2. Delete\n3. Undelete\n4. Exit\n");
		printf("\tEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				while((c=getch())!='\r')
				{
					putch(c);
					fputc(c,input);
				}
				break;
			case 2:
				fseek(input,0,SEEK_SET);
				pos=0;
				while((c=fgetc(input))!=EOF)
				{
					pos++;
					if((c<'a'||c>'z')&&(c<'A'||c>'Z')&&c!=' ')
					{
						putw(pos,undo);
						putw((int)c,undo);
						fputc(' ',temp);
					}
					else
					{
						fputc(c,temp);
					}
				}
				fclose(input);
				fclose(temp);
				remove(filename);
				rename("t",filename);
				input=fopen(filename,"r+");
				break;
			case 3:
				fseek(input,0,SEEK_SET);
				fseek(undo,0,SEEK_SET);
				temp=fopen("t","w+");
				pos=0;
				count=1;
				pos=getw(undo);
				uc=(char)getw(undo);
				while((c=fgetc(input))!=EOF)
				{
					if(pos==count)
					{
						fputc(uc,temp);
						pos=getw(undo);
						uc=(char)getw(undo);
					}
					else
					{
						fputc(c,temp);
					}
					count++;
				}
				fclose(input);
				fclose(temp);
				remove(filename);
				rename("t",filename);
				input=fopen(filename,"r+");
				break;
			case 4:
				break;
			default:
				printf("\nInvalid option\n");
		}
	}
	fclose(input);
}