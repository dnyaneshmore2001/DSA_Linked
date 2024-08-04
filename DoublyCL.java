
class DoubluCLCL{

    public static void main(String []Arg){
        int iRet=0;


        Doubly Aobj=new Doubly();

        Aobj.InsertFirst(11);
        Aobj.InsertFirst(21);
        Aobj.InsertFirst(51);

        Aobj.Display();
        iRet=Aobj.iCount();
        
        System.err.println("Numrber of elements are : "+iRet);

        Aobj.InsertLast(101);
        Aobj.InsertLast(111);
        Aobj.InsertLast(151);
        Aobj.InsertLast(201);
        Aobj.Display();
        iRet=Aobj.iCount();
        
        System.err.println("Numrber of elements are : "+iRet);

        Aobj.DeleteFirst();
        Aobj.Display();
        iRet=Aobj.iCount();
        
        System.err.println("Numrber of elements are : "+iRet);

       
        Aobj.Display();
        iRet=Aobj.iCount();
        
        System.err.println("Numrber of elements are : "+iRet);

        Aobj.InsertAtPos(2003,5);
        Aobj.Display();
        iRet=Aobj.iCount();
        
        System.err.println("Numrber of elements are : "+iRet);

        Aobj.DeleteAtPos(5);
        Aobj.Display();
        iRet=Aobj.iCount();
        
        System.err.println("Numrber of elements are : "+iRet);










    }
}class node{

    public int data;
    public node next;
    public node prev;

    public node(int iValue){
        next=null;
        prev=null;
        data=iValue;

    }

}

class Doubly{

    private node First;
    private node Last;
    private int iCount;

    public Doubly(){

        System.out.println("Inside constructor: ");
        First=null;
        Last=null;
        iCount=0;


    }
    public void InsertFirst(int iNo){

        node newn=null;

        newn=new node(iNo);

        if((First==null) || (Last==null)){

            First=newn;
            Last=newn;

        }
        else{

            newn.next=First;

            First.prev=newn;
            
            First=newn;
        }
       
        Last.next=First;
        First.prev=Last;

        iCount++;

    }
    public void InsertLast(int iNo){

        node newn=null;

        newn=new node(iNo);

        if(First==null || Last==null){

            First=newn;
            Last = newn;

        }
        else{

            newn.prev=Last;
            Last.next=newn;
            Last=newn;
        }
        First.prev=Last;
        Last.next=First;
        iCount++;

    }

    public void Display(){
       if((First==null ) && (Last==null)){

        System.out.println("LL is empty: ");
        return;

       }
       System.out.println("Elements of LL are : ");
       System.out.println("<=>");
    
       do{

        System.out.print("|"+First.data+"|<=>");
        First=First.next;
       } while(First !=Last.next);
       System.out.println();
    }


int iCount(){

    return iCount;

}

public void DeleteFirst(){

    if(First==null && Last==null){

        System.out.println("The LL is empty : ");
    }
     else if(First==Last){
        First=null;
        Last=null;

     }
     else{

        First=First.next;

     }
     Last.next = First;
     First.prev = Last;

     iCount--;
}
public void DeleteLast(){
    if(First==null && Last==null){

        System.out.println("The LL is empty : ");
    }
     else if(First==Last){
        First=null;
        Last=null;

     }
     else{

        Last=Last.prev;
        Last.next=First;

     }
     Last.next = First;
     First.prev = Last;

     iCount--;

}

public void InsertAtPos(int iNo,int iPos){

   node newn=null;
   node temp=null;

   newn=new node(iNo);

   if(iPos<1 || iPos>iCount+1){

           System.out.println("Invalid Position !!");
            return;

   }
   if(iPos==1){

    InsertFirst(iNo);

   }
   else if(iPos==iCount+1){

    InsertLast(iNo);

   }
   else{

    temp=First;
    int i=0;

    for(i=1;i<iPos-1;i++){
        temp=temp.next;

    }
    temp.next.prev=newn;
    newn.next=temp.next;
    newn.prev=temp;
    temp.next=newn;

    iCount++;

    
   }
}
public void DeleteAtPos(int iPos){
    
 
   node temp=null;

  

   if(iPos<1 || iPos>iCount+1){

           System.out.println("Invalid Position !!");
            return;

   }
   if(iPos==1){

   DeleteFirst();


   }
   else if(iPos==iCount+1){

    DeleteLast();

   }
   else{

    temp=First;
    int i=0;

    for(i=1;i<iPos-1;i++){
        temp=temp.next;

    }
    temp.next=temp.next.next;

    iCount--;
   
}
}
}
