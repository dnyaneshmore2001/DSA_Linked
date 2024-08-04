
class Queue{

    public static void main(String[] args) {
        int iRet=0;


        QueueX Aobj =new  QueueX();
        Aobj.EnQueue(11);
        Aobj.EnQueue(21);
        Aobj.EnQueue(51);
        Aobj.EnQueue(101);
        Aobj.EnQueue(121);
        Aobj.EnQueue(151);
        Aobj.Display();
        iRet=Aobj.Count();
        System.out.println("Number of elements are : "+iRet);

        Aobj.DeQueue();
        Aobj.Display();
        iRet=Aobj.Count();
        System.out.println("Number of elements are : "+iRet);


    }
}
class node{

   public int data;
   public node next;

   node(int iNo){
    
      data=iNo;
      next=null;
   }
}

class QueueX{

    public node First;
    int iCount;

    public QueueX(){

        First=null;
        iCount=0;

    }
public void EnQueue(int No){
    node newn=null;
    node temp=null;


     newn=new node(No);

    newn.data=No;
    newn.next=null;

    if(First==null){

        First=newn;
    }
    else
    {
        temp=First;

        while(temp.next!=null){

            temp=temp.next;

        }
        temp.next=newn;
      
    }
    iCount++;
}

public void Display(){

    node temp=First;

   while (temp !=null) { 
    System.out.print("|"+temp.data+"|->");
    temp=temp.next;
   }
   System.out.print("| null |\n");

  
   
}
public int Count(){

    return  iCount;

}
public void DeQueue(){

    if(First==null){
        System.out.println("The LL is empty: ");
        return;
    }
    else if(First.next==null){

        First=null;

    }
    else{

        First=First.next;


    }
    iCount--;

}


}
