#include<iostream>
using namespace std;

struct node{
    int data;
    struct node*next;

};
typedef struct node NODE;
typedef struct node* PNODE;



class SinglyLL{

    private: 
       PNODE First;
       int iCount;

    public:
      
      SinglyLL();

      void Display();
      int Count();

      void InsertFirst(int No);
      void InsertLast(int No);
      void InsertAtPos(int No,int iPos);
       
      void DeleteFirst();
      void DeleteLast();
      void DeleteAtPos(int iPos);




  
};
 SinglyLL::SinglyLL(){
   cout<<"inside constructor: ";

    First=NULL;
    iCount=0;

 }
  void SinglyLL::Display(){

     PNODE temp=First;

    while(temp !=NULL){
        cout<<temp->data <<"\t";

        temp=temp->next;

    }
  }
int SinglyLL:: Count(){

  return iCount;


  }

void  SinglyLL::InsertFirst(int No){

PNODE newn=NULL;
newn=new NODE;

newn->data=No;
newn->next=NULL;


if(First==NULL){

    First=newn;

}
else{

    newn->next=First;

    First=newn;

}
iCount++;
}

void  SinglyLL::InsertLast(int No){

PNODE newn=NULL;
PNODE temp=NULL;

newn=new NODE;



newn->data=No;
newn->next=NULL;


if(First==NULL){

    First=newn;

}
else{
    temp=First;
    while(temp->next!=NULL){

        temp=temp->next;
        
    }
    temp->next=newn;
   

    
}
iCount++;
}

void  SinglyLL:: InsertAtPos(int No,int iPos){

    PNODE newn=NULL;
     PNODE temp=First;

 
    int i=0;

   
 

    if((iPos<1) || (iPos>iCount+1)){
        printf("Invalide position ");
        return;

    }
    if(iPos==1){

      InsertFirst(No);

    }
    else if(iPos==iCount+1){

        InsertLast(No);

    }
    else{
       
       newn=new NODE;
        newn->data=No;
        newn->next=NULL;
       for(i=1;i<iPos-1;i++){

        temp=temp->next;

       }
       newn->next=temp->next;
       temp->next=newn;
       iCount++;

    }



 }
       
void  SinglyLL::DeleteFirst(){

  PNODE temp=First;

    if(First==NULL){
        cout<<"Unalbe ro delete LL is empty: ";
        return;


    }
    else if(First->next==NULL){
        delete First;
        First=NULL;

    }
    else{
        First=First->next;
        delete temp;
    }

    iCount--;

}

void  SinglyLL:: DeleteLast(){

  PNODE temp=First;


    if(First==NULL){

        cout<<"The LL is empty Sorry: ";
        return;

    }
    else if(First->next==NULL){

        delete First;
        First=NULL;

    }
    else{

        while(temp->next->next!=NULL){

            temp=temp->next;

        }
        delete temp->next;
        temp->next=NULL;  
    }
    iCount--;

}
void  SinglyLL::DeleteAtPos(int iPos){
    PNODE temp1=NULL;
    PNODE temp2=NULL;

   
    int i=0;

   
   

    if((iPos<1) || (iPos>iCount+1)){
        printf("Invalide position ");
        return;

    }
    if(iPos==1){

      DeleteFirst();

    }
    else if(iPos==iCount+1){

        DeleteLast();

    }
    else{
        temp1=First;
       for(i=1;i<iPos-1;i++){

        temp1=temp1->next;

       }
      temp2=temp1->next;
      temp1->next=temp2->next;
      delete(temp2);

  iCount--;

    }


}


int main(){

   SinglyLL *obj=new SinglyLL();
   int iRet=0;

   obj->InsertFirst(51);
   obj->InsertFirst(21);
   obj->InsertFirst(11);

   
   obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();

    iRet=obj->Count();
    cout<<"\n Number of elements are : \n"<<iRet<<"\n";
     
     obj->InsertAtPos(105,5);
     obj->Display();
     iRet=obj->Count();
    cout<<"\n Number of elements are : \n"<<iRet<<"\n";

    obj->DeleteAtPos(5);
     obj->Display();
     iRet=obj->Count();
    cout<<"\n Number of elements are : \n"<<iRet<<"\n";







   





}