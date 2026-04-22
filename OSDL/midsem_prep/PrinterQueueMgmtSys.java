import java.io.FileReader;
import java.io.FileWriter;

interface InnerPrinterQueueMgmtSys {
    void printDocument(String documentName) throws QueueFullException;
    void cancelPrint(String documentName) throws InvalidCancelException;
    void displayLog();
}
class Printer{
    int PrinterID;
    int totSlots;
    int currJobs;
    Printer(int PrinterID,int totSlots,int currJobs){
        this.PrinterID=PrinterID;
        this.totSlots=totSlots;
        this.currJobs=currJobs;
    }
}

class PrinterQueue extends Printer implements InnerPrinterQueueMgmtSys{

    PrinterQueue(int PrinterID,int totSlots,int currJobs){
        super(PrinterID, totSlots, currJobs);
    }

    public synchronized void printDocument(String documentName) throws QueueFullException
    {
        while(currJobs==totSlots){
            try{wait();}catch(Exception e){}
        }
        try{
            FileWriter fw=new FileWriter("print_log.txt",true);
            fw.write("  Queued job : "+PrinterID+" Left Spots : "+(totSlots-currJobs)+"\n");
            fw.close();
        }catch(Exception e){}
        try {
            Thread.sleep(1000);
        } catch (Exception e) {
        }
        currJobs++;
    }

    public synchronized void cancelPrint(String documentName) throws InvalidCancelException
    {
        if(currJobs==0){
            throw new InvalidCancelException("No items in queue");
        }
        try {
            Thread.sleep(1000);
        } catch (Exception e) {
        }
        
        currJobs--;
        notifyAll();
    }
    public void displayLog()
    {
        int ch;
        int newL=0;
        int charCount=0;
        String line="";
        try{
            FileReader fr=new FileReader("print_log.txt");
            while((ch=fr.read())!=-1){
                line+=(char)ch;
                if(ch=='\n'){newL++;}
                charCount++;
            }
            System.out.println("No of Lines: "+newL);
            System.out.println("No of Char : "+charCount);
            System.out.println(line);
        }catch(Exception e){}
    }
}

class UserThread extends Thread{
    PrinterQueue pq;
    UserThread(PrinterQueue pq){this.pq=pq;}
    @Override
    public void run(){
        try{
            pq.printDocument(getName());
        }catch(Exception e){System.out.println(e);}
    }
}

class TechnicianThread extends Thread{
    PrinterQueue pq;
    TechnicianThread(PrinterQueue pq){this.pq=pq;}
    @Override
    public void run(){
        try{
            pq.cancelPrint(getName());
        }catch(Exception e){System.out.println(e);}
    }
}

class QueueFullException extends Exception{
    QueueFullException(String message){super(message);}
}
class InvalidCancelException extends Exception{
    InvalidCancelException(String message){super(message);}
}

public class PrinterQueueMgmtSys {
    public static void main(String[] args) {
        PrinterQueue pq=new PrinterQueue(12, 3, 3);
        UserThread u1=new UserThread(pq);
        TechnicianThread t1=new TechnicianThread(pq);
        u1.start();
        t1.start();
        try {   
            u1.join();
            t1.join();
        } catch (Exception e) {
        }
        pq.displayLog();
    }
}

