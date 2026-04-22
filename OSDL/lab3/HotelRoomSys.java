class Clean extends Thread{
    String rName;
    Clean(String rName){
        this.rName=rName;
    }
    @Override
    public void run(){
        for(int i=0;i<5;i++){
            System.out.println(rName+"is cleaned with"+(i+1));
            try{
                Thread.sleep(3000);
            }
            catch (InterruptedException e){
                System.out.println("Thread Interrupted !");
                
            }
        }
    }
}

class Deliver extends Thread{
    String food;
    Deliver(String food){
        this.food=food;
    }
    @Override
    public void run(){
        for(int i=1;i<=5;i++){
            System.out.println(i+" Food delivered.");
            try{Thread.sleep(2000);}
            catch(InterruptedException e){
                System.out.println("The thread was interrputed");
            }
        }
    }
}

class Maintain extends Thread{
    int no;
    Maintain(int no){this.no=no;}
    @Override
    public void run(){
        for(int i=1;i<=no;i++){
            System.out.println("Room no "+i+" maintained");
        }
    }
}

public class HotelRoomSys{
    public static void main(String[] args) {
        Clean c1=new Clean("Q123");
        Deliver d1=new Deliver("Butter Chicken");
        Maintain m1= new Maintain(4);
        c1.start();
        d1.start();;
        m1.start();
        
    }
}