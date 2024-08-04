#include<iostream>
using namespace std;

template<class T>

struct nodeDL{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;

};

template<class T>

class Doubly{
    private:
     struct nodeDL<T> *First;
     int iCount;
   
    public: 
       Doubly();
       void Display();
       int Count();


       void InsertFirst(T No);
       void InsertLast(T No);
       void InsertAtPos(T No,T iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(T iPos);

     
};
template<class T>
Doubly<T>:: Doubly(){

    First=NULL;
    iCount=0;

}
template<class T>
void Doubly<T>:: Display(){
   struct nodeDL<T> * temp=First;

  while(temp!=NULL){

        cout<<"| "<<First->data <<"| <=> ";
        temp=temp->next;

    }
}
template<class T>
 int Doubly<T>::Count(){

return iCount;


 }

template<class T>
void Doubly<T>::InsertFirst(T No){

  struct nodeDL<T> *newn=NULL;
  newn=new nodeDL<T>;


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
template<class T>
void Doubly<T>::InsertLast(T No){
    
struct nodeDL<T> * newn =new nodeDL<T>;

    newn->next=NULL;
    newn->prev=NULL;
    struct nodeDL<T> *temp=NULL;

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
template<class T>
void Doubly<T>::InsertAtPos(T No,T  iPos){

     int i=0;

     struct nodeDL<T> * newn=NULL;
     struct nodeDL<T> * temp=NULL;

    

     if((iPos<1) || (iPos>iCount+1)){

        cout<<"Invalid posistion : ";
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

        newn=new nodeDL<T>;

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
template<class T>
void Doubly<T>:: DeleteFirst(){

    if(First==NULL){
        cout<<"Unable to delete LL is empty: ";
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
template<class T>
void Doubly<T>:: DeleteLast(){
    struct nodeDL<T> *temp=NULL;

     if(First==NULL){
        cout<<"Unable to delete LL is empty: ";

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
template<class T>
void Doubly<T>::DeleteAtPos(T iPos){

     int i=0;

     struct nodeDL<T>  * newn=NULL;
     struct nodeDL<T> * temp=NULL;

     

     if((iPos<1) || (iPos>iCount+1)){

        cout<<"Invalid posistion ";
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

   // LL of integer
    cout<<"-------------- LinkdList of Integers --------------\n";

    Doubly<int> *iobj = new Doubly<int>();
    int iRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);
    
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->InsertAtPos(105,5);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->DeleteAtPos(5);
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of character
    cout<<"-------------- LinkdList of Chracters --------------\n";

    Doubly<char> *cobj = new Doubly<char>();

    cobj->InsertFirst('D');
    cobj->InsertFirst('F');
    cobj->InsertFirst('R');

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cobj->InsertLast('E');
    cobj->InsertLast('Y');
    cobj->InsertLast('U');
    
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cobj->InsertAtPos('W',5);

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cobj->DeleteAtPos(5);
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of float
    cout<<"-------------- LinkdList of Floats --------------\n";

    Doubly<float> *fobj = new Doubly<float>();

    fobj->InsertFirst(90.78f);
    fobj->InsertFirst(78.99f);
    fobj->InsertFirst(67.99f);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fobj->InsertLast(45.67f);
    fobj->InsertLast(54.78f);
    fobj->InsertLast(77.89f);
    
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fobj->InsertAtPos(88.56,5);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fobj->DeleteAtPos(5);
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of double

    cout<<"-------------- LinkdList of Doubles --------------\n";

    Doubly<double> *dobj = new Doubly<double>();

    dobj->InsertFirst(90.78978);
    dobj->InsertFirst(78.99645);
    dobj->InsertFirst(67.9934);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dobj->InsertLast(45.67867);
    dobj->InsertLast(54.78534);
    dobj->InsertLast(77.89324);
    
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dobj->InsertAtPos(88.56987,5);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dobj->DeleteAtPos(5);
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

   Doubly<int> *idobj = new Doubly<int>();

    idobj->InsertFirst(51);
    idobj->InsertFirst(21);
    idobj->InsertFirst(11);
    
    idobj->InsertLast(101);
    idobj->InsertLast(111);
    idobj->InsertLast(121);
    
    idobj->Display();
    iRet = idobj->Count();

    idobj->DeleteAtPos(5);
    
    idobj->Display();
    iRet = idobj->Count();
    return 0;
}
    