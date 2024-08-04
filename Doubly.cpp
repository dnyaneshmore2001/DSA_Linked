#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;

};
typedef  struct node NODE;
typedef  struct node* PNODE;
typedef  struct node** PPNODE;

class Doubly{
    private:
     PNODE First;
     int iCount;
   
    public: 
       Doubly();
       void Display();
       int Count();


       void InsertFirst(int No);
       void InsertLast(int No);
       void InsertAtPos(int No,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

     
};
Doubly:: Doubly(){

    First=NULL;
    iCount=0;

}
void Doubly:: Display(){
   PNODE temp=First;

  while(temp!=NULL){

        printf("%d\t",temp->data);
        temp=temp->next;

    }



}
 int Doubly::Count(){

return iCount;


 }


void Doubly::InsertFirst(int No){

  PNODE newn=NULL;
  newn=new NODE;


  newn->data=No;
  newn->next=NULL;
  newn->prev=NULL;//$


  if(First==NULL){

    First=newn;

  }
  else{
    newn->next=First;
    First->prev=newn;//$

    First=newn;

  }
  iCount++;

}
void Doubly::InsertLast(int No){
    
PNODE newn=new NODE;

    newn->next=NULL;
    newn->prev=NULL;
    PNODE temp=NULL;

    newn->data=No;

    if(First==NULL){
        First=newn;

    }
    else{
        temp=First;


        while(temp->next!=NULL){

            temp=temp->next;

        }
        temp->next=newn;
        newn->prev=temp;
    }
    iCount++;
    
    
}
void Doubly::InsertAtPos(int No,int iPos){

     int i=0;

     PNODE newn=NULL;
     PNODE temp=NULL;

    

     if((iPos<1) || (iPos>iCount+1)){

        printf("Invalid posistion : ");
        return;

     }
     if(iPos==1){
        InsertFirst(No);
        return;

     }
     else if(iPos==iCount+1){

        InsertLast(No);

     }
     else{

        newn=new NODE;

        temp=First;


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
     iCount++;





}

void Doubly:: DeleteFirst(){

    if(First==NULL){
        printf("Unable to delete LL is empty: ");
        return;


    }
    else if(First->next==NULL){
    
         delete First;
         First=NULL;
    }
    else{

        First=First->next;
        delete First->prev;

        First->prev=NULL;

    }

    iCount--;


}
void Doubly:: DeleteLast(){
    PNODE temp=NULL;

     if(First==NULL){
        printf("Unable to delete LL is empty: ");
        return;


    }
    else if(First->next==NULL){
    
         delete First;
         First=NULL;
    }
    else{

        temp=First;
        while(temp->next->next!=NULL){

            temp=temp->next;

        }
        delete temp->next;
        temp->next=NULL;

    }
}
void Doubly::DeleteAtPos(int iPos){

     int i=0;

     PNODE newn=NULL;
     PNODE temp=NULL;

     

     if((iPos<1) || (iPos>iCount+1)){

        printf("Invalid posistion : ");
        return;

     }
     if(iPos==1){
        DeleteFirst();
        return;

     }
     else if(iPos==iCount+1){

        DeleteLast();

     }
     else{
        temp=First;

        for(i=1;i<iPos-1;i++){

            temp=temp->next;

        }
        temp->next =temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
     }
     iCount--;


}


int main(){

    Doubly obj;
    int iRet=0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);


    obj.Display();
    iRet=obj.Count();

    cout<<" Number of elements are : "<<iRet<<"\n";


    //obj.DeleteFirst();
     obj.Display();

    iRet=obj.Count();

    cout<<"Number of elements are :"<<iRet<<"\n";

  
    obj.InsertAtPos(105,5);
     obj.Display();

    iRet=obj.Count();

    cout<<" Number of elements are :"<<iRet<<"\n";

    obj.DeleteAtPos(5);
    obj.Display();

    iRet=obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";















    return 0;

}