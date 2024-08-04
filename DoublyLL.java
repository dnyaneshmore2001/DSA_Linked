
class DoublyLL{

    public static void main(String []Args){

        Doubly Aobj=new Doubly();

        int iRet=0;

        Aobj.InsertFirst(51);
        Aobj.InsertFirst(21);
        Aobj.InsertFirst(11);

        Aobj.Display();

        Aobj.InserLast(101);
        Aobj.InserLast(111);
        Aobj.InserLast(151);
        Aobj.Display();
        iRet=Aobj.iCount();
        System.out.println("Number of node are : "+iRet);

        

        Aobj.DeleteFirst();

        Aobj.Display();

        iRet=Aobj.iCount();
        
        System.out.println("Number of node are : "+iRet);

        Aobj.DeleteLast();
        iRet=Aobj.iCount();
        System.out.println("Number of node are : "+iRet);

        Aobj.Display();
        
        Aobj.InsertAtPos(1001,5);

        iRet=Aobj.iCount();
        Aobj.Display();
        System.out.println("Number of node are : "+iRet);

        Aobj.DeleteAtPos(5);

        Aobj.Display();
        iRet=Aobj.iCount();
        System.out.println("Number of node are : "+iRet);
    }
}
class node{

    public int data;
    public node next;
    public node prev;


    public node(int iValue){

        data=iValue;
        next=null;
        prev=null;

    }

}

class Doubly{

    private node First;
    private int iCount;

    public Doubly()
    {
        First=null;
        iCount=0;

    }

    public void Display(){

        node temp=First;

        
        System.out.print("|null|<=>");

        while(temp !=null){

            System.out.print("|"+temp.data+"|<=>");
            temp=temp.next;

        }
        System.out.print("|null|\n");



    }

    public int iCount(){

        return  iCount;
        
    }
    public void InsertFirst(int No){

        node newn=null;

        newn=new node(No);

        if(First==null){

            First=newn;

        }
        else{
            First.prev=newn;
            newn.next=First;
            First=newn;

        }
        iCount++;


    }

    public void InserLast(int No){

        node temp=null;
        node newn=null;


        newn=new node(No);

        if(First==null){

            First=newn;

        }
        else{

            temp=First;


            while(temp.next !=null){

                temp=temp.next;

            }
            temp.next=newn;
            newn.prev=temp;
        }
        iCount++;


    }

    public void  DeleteFirst(){

        

        if(First==null){

            System.out.println("The LL is empty");
            return;

            
        }
        else if(First.next==null){

            First=null;

        }
        else{

            First=First.next;
            First.prev=null;


        }

        iCount--;

    }

    public void DeleteLast(){

        node temp=null;
        if(First==null){

            System.out.println("The LL is empty");
            return;
        }
        else{

            temp=First;

        while(temp.next.next !=null) {
            
            temp=temp.next;

            
        }
        temp.next=null; 
        }

        iCount--;


    }

    public void InsertAtPos(int iNo,int iPos){

        node temp=null;
        node newn=null;
       

        if((iPos<1) || (iPos>iCount +1)){

            System.out.println("Invalide position");
            return;

        }
        else if(iPos==1){

            InsertFirst(iNo);
        }

        else{

            int i=0;

            newn=new node(iNo);
            newn.data=iNo;
            newn.next=null;
            newn.prev=null;
            temp=First;

            for(i=1;i<iPos-1;i++){

                temp=temp.next;

            }
           newn.next=temp.next;
           newn.prev=temp;
           temp.next=newn;
           
        }
        iCount++;

    }

    public void DeleteAtPos(int iPos){

        if((iPos<1) || (iPos>iCount +1)){

            System.out.println("Invalide position");
            return;

        }

        
        if(iPos==1){

           DeleteFirst();
        }
        else if(iPos==iCount){

            DeleteLast();

        }

        else{

            int i=0;

            node temp=null;

            temp=First;
            for(i=1;i<iPos-1;i++){

                temp=temp.next;

            }
            temp.next=temp.next.next;
            temp.next.prev = temp;
             

            
        }
        iCount--;

    }



    }

