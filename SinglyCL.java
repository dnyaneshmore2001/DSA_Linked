



class SinglyCL{

    public static void main(String []Arg){
        int iRet=0;


        SinglyCLX Aobj=new SinglyCLX();
        Aobj.InsertFirst(51);
        Aobj.InsertFirst(21);
        Aobj.InsertFirst(11);
        
        Aobj.InsertLast(101);
        Aobj.InsertLast(111);
        Aobj.InsertLast(201);

        Aobj.Display();

        iRet=Aobj.Count();
        System.out.println("\nNumber of nodes are : "+iRet);


        Aobj.DeleteFirst();
        Aobj.Display();

        iRet=Aobj.Count();
        System.out.println("\nNumber of nodes are : "+iRet);

       
        

        Aobj.InsertatPos(501,5);
        Aobj.Display();

        iRet=Aobj.Count();
        System.out.println("\nNumber of nodes are : "+iRet);


        Aobj.DeleteAtPos(5);
        Aobj.Display();

        iRet=Aobj.Count();
        System.out.println("\nNumber of nodes are : "+iRet);



    }
}


class node{

   public  int data;
   public node next;

}

class SinglyCLX{

    private node First;
    private node Last;
    private int  iCount;


    public SinglyCLX(){

        System.out.println("Inside Singly Counstructor !!");
        First=null;
        Last=null;
        iCount=0;


    }
    public void Display(){
        if(First==null || Last==null){

            System.out.println("Sorry the LL is empty : ");
            return;

        }

        do{

         System.out.print("|"+First.data+"|=>");
        // System.out.println("=>");
         First=First.next;

        }while(First !=Last.next);

    }

    public int Count(){

        return iCount;


    }
    public void InsertFirst(int No){

        node newn=null;
        newn=new node();
        newn.next=null;
        newn.data=No;


        if((First==null) || (Last==null)){

            Last=newn;
        }
        else{

            newn.next=First;
        }
        First=newn;

        Last.next=First;

        iCount++;
        
       
    }
    
    public void InsertLast(int No){

        node newn=null;

        newn=new node();
        newn.next=null;
        newn.data=No;

        if((First==null ) || (Last==null)){

            First=newn;
            Last=newn;

        }
        else{

            Last.next=newn;
            Last=newn;
        }
        Last.next=First;
        iCount++;
    }

    public void DeleteFirst(){

        if((First==null) || (Last==null)){

            System.out.println("The LL is Empty : ");
            return;

        }
        else if(First == Last)
        {
            First  = null;
            Last = null;
        }
        else{

            First=First.next;

            Last.next=First;
            
        }

        iCount--;
    }

    public void DeleteLast(){

        node temp=null;
        temp=First;

        if((First==null) || (Last==null)){

            System.out.println("The LL is Empty : ");
            return;

        }
        else if(First == Last)
        {
            First  = null;
            Last = null;
        }
        
        else{

            while(temp.next !=Last) {

                temp=temp.next;
                
            }
            temp.next=First;

        }

        iCount--;


    }
    public void InsertatPos(int No,int iPos){

       node temp=null;
       int i=0;
     

       if(iPos<1 || iPos>iCount+1)
        {
            System.out.println("Invalid Position !!");
            return;
        }
        if(iPos == iCount+1)
        {
            InsertLast(No);
        }
        else if(iPos == 1)
        {
            InsertFirst(No);
        }
        else{

            temp=First;
            node newn=new node();

            newn.next=null;
            newn.data=No;
           
            for(i=1;i<iPos-1;i++){

                temp=temp.next;

            }
            newn.next=temp.next;
            temp.next=newn;
        }
        iCount++;

    }


    public void DeleteAtPos(int iPos){

       node temp=null;
       int i=0;
       

     

       if(iPos<1 || iPos>iCount+1)
        {
            System.out.println("Invalid Position !!");
            return;
        }
        if(iPos == iCount+1)
        {
           DeleteLast();
        }
        else if(iPos == 1)
        {
            DeleteFirst();
        }
        else{

            temp=First;
           
            for(i=1;i<iPos-1;i++){

                temp=temp.next;

            }
            temp.next=temp.next.next;
           
        }
        iCount--;


    }
}

