#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
    struct node*prev;


};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE First,int No){


  PNODE newn=NULL;
  newn=(PNODE)malloc(sizeof(NODE));

  newn->data=No;
  newn->next=NULL;
  newn->prev=NULL;//$


  if(*First==NULL){

    *First=newn;

  }
  else{
    newn->next=*First;
   (*First)->prev=newn;//$

    *First=newn;

  }
}
void InsertLast(PPNODE First,int No){
PNODE newn=NULL;
PNODE temp=NULL;
  newn=(PNODE)malloc(sizeof(NODE));

  newn->data=No;
  newn->next=NULL;
  newn->prev=NULL;//$
  



  if(*First==NULL){

    *First=newn;

  }
  else{
    temp=*First;
    while(temp->next !=NULL){

        temp=temp->next;

    }
    temp->next=newn;
    newn->prev=temp;

  }

}
void Display(PNODE First){

    while(First !=NULL){

        printf("%d\t",First->data);
        First=First->next;

    }
}
int Count(PNODE First){
int iCnt=0;

    while(First !=NULL){

        iCnt++;

        First=First->next;


    }
    return iCnt;

}
void DeleteFirst(PPNODE First){
    if(*First==NULL){
        printf("Unable to delete LL is empty: ");
        return;


    }
    else if((*First)->next==NULL){
    
         free(*First);
         *First=NULL;
    }
    else{

        *First=(*First)->next;
        free((*First)->prev);

        (*First)->prev=NULL;

    }
}
void DeleteLast(PPNODE First){
    PNODE temp=NULL;

     if(*First==NULL){
        printf("Unable to delete LL is empty: ");
        return;


    }
    else if((*First)->next==NULL){
    
         free(*First);
         *First=NULL;
    }
    else{

        temp=*First;
        while(temp->next->next!=NULL){

            temp=temp->next;

        }
        free(temp->next);
        temp->next=NULL;

    }
}
void InsertAtPos(PPNODE First,int No,int iPos){
     int iLength=0;
     int i=0;

     PNODE newn=NULL;
     PNODE temp=NULL;

     iLength=Count(*First);

     if((iPos<1) || (iPos>iLength+1)){

        printf("Invalid posistion : ");
        return;

     }
     if(iPos==1){
        InsertFirst(First,No);
        return;

     }
     else if(iPos==iLength+1){

        InsertLast(First,No);

     }
     else{

        newn=(PNODE)malloc(sizeof(NODE));
        temp=*First;


        newn->data=No;
        newn->next=NULL;

        for(i=1;i<iPos-1;i++){

            temp=temp->next;

        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
    

     }

}
void DeleteAtPos(PPNODE First,int iPos){

int iLength=0;
     int i=0;

     PNODE newn=NULL;
     PNODE temp=NULL;

     iLength=Count(*First);

     if((iPos<1) || (iPos>iLength+1)){

        printf("Invalid posistion : ");
        return;

     }
     if(iPos==1){
        DeleteFirst(First);
        return;

     }
     else if(iPos==iLength+1){

        DeleteLast(First);

     }
     else{
        temp=*First;

        for(i=1;i<iPos-1;i++){

            temp=temp->next;

        }
        temp->next =temp->next->next;
        free(temp->next->prev);
        temp->next->prev=temp;


        
     }

}


int main(){

    PNODE Head=NULL;
    int iRet=0;


    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);

      
    InsertLast(&Head,101);
    InsertLast(&Head,111);
    InsertLast(&Head,121);

    Display(Head);
    iRet=Count(Head);
    printf("\nNumber of elements are %d\n",iRet);

    
/*
    DeleteFirst(&Head);
    Display(Head);
    iRet=Count(Head);
    printf("\nNumber of elements are %d\n",iRet);

    DeleteLast(&Head);

    Display(Head);
    iRet=Count(Head);
    printf("\nNumber of elements are %d\n",iRet);

*/
    InsertAtPos(&Head,105,5);
    Display(Head);
    iRet=Count(Head);
    printf("\nNumber of elements are %d\n",iRet);

    DeleteAtPos(&Head,5);
    Display(Head);
    iRet=Count(Head);
    printf("\nNumber of elements are %d\n",iRet);




    
}