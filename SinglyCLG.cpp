#include<iostream>
using namespace std;

template<class T>

struct nodeGSC{
    T data;
    struct nodeGSC *next;

};

template<class T>
   class SinglyCL{
     
      private:
         struct nodeGSC<T> * First;
         struct nodeGSC<T> * Last;
         int iCount;

       public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        
};

template<class T>
SinglyCL<T>::SinglyCL(){

    First=NULL;
    Last=NULL;
    iCount=0;

}
template<class T>

 void SinglyCL<T>::Display(){

    struct nodeGSC<T> * temp= First;

    if((First==NULL) && (Last==NULL)){

        printf("The LL is empty : ");
        return;

    }

     do{

        //printf("%d\t",temp->data);
        cout<< temp->data<<"\t ";

        temp=temp->next;

     }while(temp !=Last->next);
 }
 template<class T>
int SinglyCL<T>:: Count(){

return iCount;

}

template<class T>
void SinglyCL<T>::InsertFirst(T No){

    struct nodeGSC<T> *newn=NULL;

  newn=new nodeGSC<T>;


  newn->data=No;
  newn->next=NULL;

  if((First==NULL ) && ( Last==NULL))
  {

    First=newn;
    Last=newn;

  }
  else{

    newn->next=First;

    First=newn;

  }
  Last->next=First;

iCount++;

}
template<class T>
void SinglyCL<T>:: InsertLast(T No){

 struct nodeGSC<T>*newn=NULL;
    

  newn=new nodeGSC<T>;


  newn->data=No;
  newn->next=NULL;

  if((First==NULL ) && ( Last==NULL))
  {

    First=newn;
    Last=newn;

  }
  else{
   
    Last->next=newn;
    Last=newn;

    
  }
  Last->next=First;

  iCount++;


}
template<class T>
void SinglyCL<T>::InsertAtPos(T No,int iPos){

int i=0;
   

    struct nodeGSC<T> * temp=NULL;
    struct nodeGSC<T> * newn=NULL;
     

    if((iPos<1) || (iPos>iCount+1)){
       
       printf(" invalid input:");

        return;

    }
    if(iPos==1){

    InsertFirst(No);

    }
    else if(iPos == iCount+ 1){
     
       InsertLast(No);

    }

    else{

        temp =First;

        struct nodeGSC<T>*newn=NULL;

        newn = new nodeGSC<T>;

        newn->data = No;

        newn->next = NULL;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp -> next = newn;
    }

}
template<class T>

void SinglyCL<T>:: DeleteFirst(){

    if((First==NULL) && (Last==NULL)){

        printf("unable to delete the LL is emepty: ");
        return ;

    }
    else if(First==Last){

        delete First;
        First=NULL;
        Last=NULL;


    }
    else{

        First=First->next;
        delete Last->next;
        Last->next=First;


    }

iCount--;


}
template<class T>
void SinglyCL<T>:: DeleteLast(){
 struct nodeGSC<T>*temp=NULL;

    if((First==NULL) && (Last==NULL)){

        printf("unable to delete the LL is emepty: ");
        return ;

    }
    else if(First==Last){

        delete First;
        First=NULL;
        Last=NULL;


    }
    else{

        temp=First;
        while(temp->next!=Last){

            temp=temp->next;

        }
        delete Last;
        Last=temp;
        Last->next=First;

    }

iCount--;


}
template<class T>
void SinglyCL<T>::DeleteAtPos(int iPos){

int i = 0;
    
    struct nodeGSC<T> *  temp1 = NULL;
    struct nodeGSC<T> *  temp2 = NULL;


    if((iPos < 1) || (iPos > iCount))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1 -> next = temp2->next;
        delete temp2;
    }
}
int main(){
     cout<<"-------------- LinkdList of Integers --------------\n";

    SinglyCL<int> *Ciobj = new SinglyCL<int>();
    int CRet = 0;

    Ciobj->InsertFirst(51);
    Ciobj->InsertFirst(21);
    Ciobj->InsertFirst(11);

    Ciobj->Display();
    CRet = Ciobj->Count();
    cout<<"Number of elemensts are : "<<CRet<<endl;

    Ciobj->InsertLast(101);
    Ciobj->InsertLast(111);
    Ciobj->InsertLast(121);
    
    Ciobj->Display();
    CRet = Ciobj->Count();
    cout<<"Number of elemensts are : "<<CRet<<endl;

    Ciobj->InsertAtPos(105,5);

    Ciobj->Display();
    CRet = Ciobj->Count();
    cout<<"Number of elemensts are : "<<CRet<<endl;

    Ciobj->DeleteAtPos(5);
    Ciobj->Display();
    CRet = Ciobj->Count();
    cout<<"Number of elemensts are : "<<CRet<<endl;


    return 0;

}