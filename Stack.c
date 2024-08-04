#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node*next;

};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;


void Push(PPNODE First,int No){
 
   PNODE newn=NULL;

   newn=(PNODE)malloc(sizeof(NODE));
    newn->data=No;
    newn->next=NULL;

    if(*First==NULL){

        *First=newn;

    }
    else{

        newn->next=*First;
        *First=newn;

    }

     
}
int Pop(PPNODE First){

  int iValue=0;
  PNODE temp=NULL;

  if(*First==NULL){

    printf("unable top pop the element as stack is empty : ");

    return -1;

  }
  else{

    temp=*First;
    
    iValue=(*First)->data;
    *First=(*First)->next;
    free(temp);
  }
return iValue;



}
void Display(PNODE First){
     printf("Elements of stack are : \n");
 

    while(First!= NULL)
    {
        printf("%d\n",First->data);
        First= First -> next;
    }
    
    printf("\n");
}
int Count(PNODE First){
int iCnt=0;

    while(First!= NULL)
    {
       iCnt++;

        First= First -> next;
    }
    
return iCnt;

}
int main(){

PNODE Head=NULL;
int iRet=0;
int iRetX=0;

Push(&Head,51);
Push(&Head,21);
Push(&Head,11);
Push(&Head,101);

Display(Head);
iRet=Count(Head);
printf("Number of elements of stack  %d\n",iRet);


iRetX=Pop(&Head);
printf("Poped element of stack is : %d\n",iRetX);
Display(Head);
iRet=Count(Head);
printf("Number of elements of stack : %d\n",iRet);

Push(&Head,111);

Display(Head);
iRet=Count(Head);
printf("Number of elements of stack : %d\n",iRet);



    return 0;

}