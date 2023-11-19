#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
struct CONTACTS
{
long phone;
char N[20],ADD[20],mail_id[30];
} member;
char query[20],N[20];
FILE *fp, *ft;
int i,n,ch,l,found;
int main()
{
main:
system("cls"); //Main menu //
printf("\n\t **** Welcome to Contact Management System ****");
printf("\n\n\n\t\t\tHOME PAGE\n\t\t=====================\n\t\t[1] ADD CONTACTS\n\t\t[2] LIST CONTACTS\n\t\t[3] SEARCH CONTACTS\n\t\t[4] EDIT CONTACTS\n\t\t[5] DELETE CONTACTS\n\t\t[0] EXIT\n\t\t=================\n\t\t");
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 0:
printf("\n\n\t\tEXIT?");
break;
//Add new contacts//
case 1:
system("cls");
fp=fopen("contact.dll","a");
for (;;)
{
fflush(stdin);
printf("\nName (Use identical):");
scanf("%[^\n]",&member.N);
if(stricmp(member.N,"")==0 || stricmp(member.N," ")==0)
break;
fflush(stdin);
printf("Phone:");
scanf("%ld",&member.phone);
fflush(stdin);
printf("address:");
scanf("%[^\n]",&member.ADD);
fflush(stdin);
printf("mail_id address:");
gets(member.mail_id);
printf("\n");
fwrite(&member,sizeof(member),1,fp);
}
fclose(fp);
break;
//list of contacts*//
case 2:
system("cls");
printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nNAME\t\tCONTACT NO\t ADDRESS\t\tE-mail Id.\n=================================================================\n\n");
for(i=97; i<=122; i=i+1)
{
fp=fopen("contact.dll","r");
fflush(stdin);
found=0;
while(fread(&member,sizeof(member),1,fp)==1)
{
if(member.N[0]==i || member.N[0]==i-32)
{
printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nmail_id\t: %s\n",member.N,
member.phone,member.ADD,member.mail_id);
found++;
}
}
if(found!=0)
{
printf("=========================================================== [%c]-(%d)\n\n",i-32,found);
getch();
}
fclose(fp);
}
break;
//search contacts//
case 3:
system("cls");
do
{
found=0;
printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");
fflush(stdin);
scanf("%[^\n]",&query);
l=strlen(query);
fp=fopen("contact.dll","r");
system("cls");
printf("\n\n..::Search result for '%s' \n===================================================\n",query);
while(fread(&member,sizeof(member),1,fp)==1)
{
for(i=0; i<=l; i++)
N[i]=member.N[i];
N[l]='\0';
if(stricmp(N,query)==0)
{
printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::mail_id\t: %s\n",member.N,member.phone,member.ADD,member.mail_id);
found++;
if (found%4==0)
{
printf("..:: Press any key to continue...");
getch();
}
}
}
if(found==0)
printf("\n..::No match found!");
else
printf("\n..::%d match(s) found!",found);
fclose(fp);
printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
scanf("%d",&ch);
}
while(ch==1);
break;
//edit contacts//
case 4:
system("cls");
fp=fopen("contact.dll","r");
ft=fopen("temp.dat","w");
fflush(stdin);
printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");
scanf("%[^\n]",N);
while(fread(&member,sizeof(member),1,fp)==1)
{
if(stricmp(N,member.N)!=0)
fwrite(&member,sizeof(member),1,ft);
}
fflush(stdin);
printf("\n\n..::Editing '%s'\n\n",N);
printf("..::Name(Use identical):");
scanf("%[^\n]",&member.N);
fflush(stdin);
printf("..::Phone:");
scanf("%ld",&member.phone);
fflush(stdin);
printf("..::address:");
scanf("%[^\n]",&member.ADD);
fflush(stdin);
printf("..::mail_id address:");
gets(member.mail_id);
printf("\n");
fwrite(&member,sizeof(member),1,ft);
fclose(fp);
fclose(ft);
remove("contact.dll");
rename("temp.dat","contact.dll");
break;
//delete contacts//
case 5:
system("cls");
fflush(stdin);
printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::TO DELETE CONTACT ENTER THE NAME:");
scanf("%[^\n]",&N);
fp=fopen("contact.dll","r");
ft=fopen("temp.dat","w");
while(fread(&member,sizeof(member),1,fp)!=0)
if (stricmp(N,member.N)!=0)
fwrite(&member,sizeof(member),1,ft);
fclose(fp);
fclose(ft);
remove("contact.dll");
rename("temp.dat","contact.dll");
break;
default:
printf("INVALID ENETRY");
break;
}
printf("\n\n\n..::ENTER CHOICE:\n\n\t[1] MAIN MENU\t\t[0] EXIT\n");
scanf("%d",&ch);
switch (ch)
{
case 1:
goto main;
case 0:
break;
default:
printf("INVALID ENTRY");
break;
}
return 0;
}
