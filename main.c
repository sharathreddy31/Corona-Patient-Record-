// MINI PROJECT ON  CORONA PATIENT RECORD ..........
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
 {
    unsigned int id;
    char person[30];
    char report[30];
    char status[30];
    struct node *next;
 }NODE;

NODE* addPerson(NODE *first)
{
    NODE *newnode,*temp;
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->next=NULL;
    printf("\nEnter the person details.....\n");
    printf("\nEnter The Person ID: ");
    scanf("%i",&newnode->id);
    printf("Name: ");scanf("%s",newnode->person);
    printf("Report: ");scanf("%s",newnode->report);
    printf("Current status : ");scanf("%s",newnode->status);
    if(first==NULL)
     first=newnode;
    else
  {
     temp=first;
     while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
  }
   printf("\nPerson %s is added to the list",newnode->person);
 return first;
}
void display(NODE *first)
{
 if(first==NULL)
 {
 printf("\nEmpty list");
 return;
 }
printf("\nPerson Details........\n");
printf("------------------------------------------------------------------------\n");
printf("\nNAME                     REPORT                   CURRENT STATUS\n");
printf("------------------------------------------------------------------------\n");
 while(first!=NULL)
 {
 printf("%-25s%-25s%-25s\n",first->person,first->report,first->status);
 first=first->next;
 }
}
NODE *searchperson(NODE *first)
{
 NODE *temp;
 unsigned int id1;
 char person[20];
  if(first==NULL)
   printf("\nEmpty list");
 else
 {
  //  printf("\nEnter the person name to search: ");
   // scanf("%s",person);
    printf("\nEnter the person ID to search:");
    scanf("%i",&id1);
    temp=first;
    // while(temp!=NULL && strcmp(temp->person,person)!=0)
    while(temp!=NULL&&temp->id!=id1)
        temp=temp->next;
    if(temp==NULL)
    printf("\nPerson with %i ID not existing in the list",id1);
    else
  {
    printf("\nPerson with %i ID is existing in the list",id1);
    printf("\nCurrent status of person (alive or dead) : %s",temp->status);
    printf("\nEnter new status of a person : ");
    scanf("%s",temp->status);
    printf("\nCurrent status of person %s is updated successfully!!\n", person);
  }
 }
 return first;
}
void displaybasedonstatus(NODE*first)
{

   NODE*temp;
   char status[20];
   if(first==NULL)
    printf("\nEmpty list");
   printf("enter either alive or dead \n");
   scanf("%s",status);
   temp=first;
   char s[]="alive";
   char a[]="dead";
   if(strcmp(status,s)==0||strcmp(status,a)==0)
   {
   printf("\nPerson Details........\n");
   printf("--------------------------------------------\n");
   printf("\nNAME                     CURRENT STATUS\n");
   printf("--------------------------------------------\n");
  while(temp!=NULL)
{
   if(strcmp(temp->status,status)==0)
  {
     printf("%-25s%-25s\n",temp->person,temp->status);
  }
    temp=temp->next;
}
  }
  else
    printf("Invalid status entered \n");
}

int main()
{
 NODE *first=NULL;
 int choice;
 printf("                                                WELCOME TO THE REPORTS SECTION OF CORONA TEST                         \n");
 printf("                                                ---------------------------------------------                         \n");
 while(1)
 {
 printf("\nSELECT OPTION 1 TO ADD PERSON IN THE LIST \nSELECT OPTION 2 TO UPDATE CURRENT STATUS OF THE PERSON IN THE LIST \nSELECT OPTION 3 TO DISPLAY LIST \nSELECT OPTION 4 TO DISPLAY THE NAMES OF PERSONS BASED ON THEIR CURRENT STATUS\nSELECT OPTION 5 TO EXIT FROM THE PANEL\n");
 printf("\nEnter your choice: ");
 scanf("%d",&choice);
 switch(choice)
 {
   case 1: first=addPerson(first);
           break;

  case 2: first=searchperson(first);
          break;
  case 3: display(first);
          break;
  case 4:displaybasedonstatus(first);
         break;

 case 5: exit(0);
 default: printf("\nInvalid choice");
 }
 }
 return 0;
}
