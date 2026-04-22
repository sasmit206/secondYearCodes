import java.util.*;
import java.io.*;

interface BookingOperations {
    void bookTicket() throws SeatUnavailableException;
    void cancelTicket()throws SeatUnavailableException;
    void displayLog();
}

class MovieShow{
    int showID;
    String movieName;
    int totalSeats;
    int availableSeats;
    MovieShow(int showID,String movieName,int totalSeats,int availableSeats){
        this.showID=showID;
        this.movieName=movieName;
        this.totalSeats=totalSeats;
        this.availableSeats=availableSeats;
    }
}

class SeatUnavailableException extends Exception{
    SeatUnavailableException(String message){
        super(message);
    }
}

class CustomerBooking extends MovieShow implements BookingOperations{
    CustomerBooking(int showID,String movieName,int totalSeats,int availableSeats){super(showID, movieName, totalSeats, availableSeats);}
    
    public synchronized void bookTicket() throws SeatUnavailableException{
        while(availableSeats==0){
            try{wait();}catch(Exception e){}
        }
        try{
            Thread.sleep(1000);
        }catch(Exception e){}
            try{
                FileWriter fw=new FileWriter("movie_log.txt");
                fw.write("BOOKED | Name : "+movieName);
            }catch(Exception e){}
            

            availableSeats--;
            System.out.println("BOOKING | Remaining Seats :"+availableSeats);
    }
    public synchronized void cancelTicket()throws SeatUnavailableException{
        if(availableSeats==totalSeats){throw new SeatUnavailableException("NO seats booked");}
        availableSeats++;
        notifyAll();
        System.out.println("Cancellation Successfull | Seats Left : "+availableSeats);
        try{
                FileWriter fw=new FileWriter("movie_log.txt",true);
                fw.write("CANCELLED | Name : "+movieName);
                fw.close();
            }catch(Exception e){}
    }

    public void displayLog(){
        
        int ch;
        String line="";
        try{
            FileReader fr= new FileReader("movie_log.txt");
            while((ch=fr.read())!=-1){
            line+=(char)ch;
            }
            fr.close();
        }catch(Exception e){}
        
        System.out.println(line);
    }
}

class SeatBook extends Thread{
    CustomerBooking cb;
    SeatBook(CustomerBooking cb){this.cb=cb;}
    @Override
    public void run(){
        try{
            cb.bookTicket();
        }
        catch(SeatUnavailableException e){System.out.println(e);}
    }
}

class SeatCancel extends Thread{
    CustomerBooking cb;
    SeatCancel(CustomerBooking cb){this.cb=cb;}
    @Override
    public void run(){
        try{
            cb.cancelTicket();
        }
        catch(SeatUnavailableException e){System.out.println(e);}
    }
}



public class MovieTicketBookSys {
    public static void main(String[] args) {
        CustomerBooking cb=new CustomerBooking(12,"Pushpa",35,32);
        SeatBook b1=new SeatBook(cb);
        b1.start();
        SeatCancel c1=new SeatCancel(cb);
        c1.start();
        cb.displayLog();
    }    
}
