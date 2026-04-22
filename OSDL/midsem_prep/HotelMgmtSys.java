// Design and implement a Java-based Hotel Booking Management System.

// The system should simulate a real-world hotel where multiple customers attempt to book rooms concurrently. The hotel has a limited number of rooms, and booking requests must be handled safely to avoid data inconsistency.

// Each customer booking request must be processed in a separate thread. If no rooms are available, the booking thread must wait. When a room is released by another customer, waiting booking threads should be notified and allowed to proceed.

// Room details such as room number, room type, price per day, and booking status must be maintained using object-oriented principles. Use an enumeration to represent different room types and their base tariffs.

// All booking and cancellation details must be stored in a file and later read back and displayed to the user.

// Use appropriate thread synchronization techniques, simulate processing delays using Thread.sleep(), and handle all necessary exceptions.

import java.io.FileWriter;
import java.util.Scanner;

enum RoomType{
    SINGLE(1000),
    DOUBLE(2000),
    LUXURY(3000);
    int x;
    RoomType(int x){this.x=x;}
}
class Hotel{
    int rno;
    int rnum;
    RoomType rt;
    boolean stat;
    Hotel(int rno){
        this.rno=rno;
    }
    public synchronized void book(int rnum,RoomType rt,boolean stat){
        while(rno==0){
            try{
                wait();
            }catch(Exception e){}
        }
            try{
                Thread.sleep(100);
            }catch(Exception e){}
            rno--;
            this.rnum=rnum;
            this.rt=rt;

            this.stat=stat;
            System.out.println("Room Booking Successfull");
            System.out.println("Room Details : "+rnum+rt+stat);
            //FileWriter fw=new FileWriter("roomt.txt");
            // try{
            //     fw.write(rnum);
            //     //fw.write(rt);
            //     fw.write(rnum);

            // }catch(Exception e){}
    }
    public synchronized void cancel(){
        rno++;
        System.out.println("Room Cancelled.");
        notifyAll();
    }
}

class BookThread extends Thread{
    Hotel h;
    BookThread(Hotel h){this.h=h;}
    @Override
    public void run(){
        h.book(123, RoomType.DOUBLE, true);
    }
}

class CancelThread extends Thread{
    Hotel h;
    CancelThread(Hotel h){this.h=h;}
    @Override
    public void run(){
        h.cancel();
    }
}

public class HotelMgmtSys {
    public static void main(String[] args) {
        Scanner in= new Scanner(System.in);
        Hotel h=new Hotel(3);
        int ch;

        do{
            System.out.println("Enter 1 to book Room , 2 to cancel");
            ch=in.nextInt();
            if(ch==1){
                BookThread bt=new BookThread(h);
                bt.start();
            }
            else{
                CancelThread ct=new CancelThread(h);
                ct.start();
            }
            System.out.println("Enter 1 to continue Room booking");
            ch=in.nextInt();
        }while(ch==1);
        
    }
}
