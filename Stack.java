class Stack{

    public static void main(String[] args) {
        int iRet=0;


        StackX Aobj=new  StackX();
        Aobj.Push(11);
        Aobj.Push(21);
        Aobj.Push(51);
        Aobj.Push(101);
        Aobj.Push(111);
        Aobj.Push(121);
        
        

        Aobj.Display();
        iRet=Aobj.Count();
        System.out.println("number of elements in stack are : "+iRet);

        Aobj.Pop();
        Aobj.Display();
        iRet=Aobj.Count();
        System.out.println("number of elements in stack are : "+iRet);

        

        
    }
}
class node{

   public int data;
  public   node next;

   public node(int iValue){

        data=iValue;
        next=null;
    }

}

class StackX{
     
    public node First;
    public int iCount;

    public StackX(){

        System.out.println("inside constructor: ");

        First=null;
        iCount=0;

    }
    public void Push(int iNo){

        node newn=null;
        newn=new node(iNo);

        if(First==null){

            First=newn;

        }
        else{

            newn.next=First;
            First=newn;

        }
        iCount++;
    }

    public void Pop(){

        if(First==null){
            System.out.println("LL is Already Empty: ");
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

    public void Display(){

        node temp=First;

       while (temp !=null) { 
        System.out.print("|"+temp.data+"|->");
        temp=temp.next;
       }
       System.out.print("| null |\n");

      
       
    }
    public int Count()
    {
       return iCount;
   }
}
