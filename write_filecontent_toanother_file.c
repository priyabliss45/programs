#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void StartWriting(char *f)
{
    FILE *fp;
    fp = fopen(f,"w");
    if(fp == NULL){
        fprintf(stderr,"Error in Opening File.\n");
    }
    else{
    char ch;
int i=1;
while(i<=100)
{
printf("Enter %d character:",i);
ch=fgetc(stdin);
if(ch=='\n')
{
printf("ENTER KEY is pressed.\n");
break;
}
else
{
fputc(ch,fp);i++;
}
ch=getchar();
}
    fclose(fp);
    }
}
void main(int argc, char** argv)
{
    char* f;
    int flag=0;
    char f2[30];
    if(argc == 1)
    {
    printf("Enter the file path:\n");
    gets(f2);
    if(fopen(f2, "r"))
    {printf("Cannot open the file because %s already exist.\n",f2);flag++;}
    else
    StartWriting(f2);
    if(flag>0)
    {
    printf("Enter the file path:\n");
    gets(f2);
    if(fopen(f2, "r"))
    printf("Cannot open the file because %s already exist.\n",f2);
    else
    StartWriting(f2);
    }
    }
    else
    {
     int flag=0;
      f = argv[1];
     if(fopen(f, "r"))
     {
	printf("Cannot open the file because %s already exist.\n",f);flag++;
     }
    else
    StartWriting(f);
    if(flag>0)
    {
    printf("Enter the file path:\n");
    gets(f2);
    if(fopen(f2, "r"))
    printf("Cannot open the file because %s already exist.\n",f2);
    else
    StartWriting(f2);
    }
    }
  }
