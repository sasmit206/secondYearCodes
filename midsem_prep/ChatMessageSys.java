import java.util.*;
import java.io.*;

class chat{
    boolean written=false;
    boolean read=false;
    public synchronized void send(){
        try{
            FileWriter fw=new FileWriter("chatlog.txt",true);
            fw.write("hello\n");
            fw.close();
            written=true;
            notify();
        }
        catch (IOException e){};
    }

    public synchronized void read(){
        try{
            while(!written){
                try{wait();}
                catch(Exception e){}
            }
            FileReader fr= new FileReader("chatlog.txt");
            int ch;
            String l="";
            while((ch=fr.read())!=-1){
                l+=(char)ch;
            }
            fr.close();
            read=true;
            System.out.println(l);
            notify();
        }
        catch (IOException e){};
    }
    
    public synchronized void mod(){
        try{
            while(!(written&&read)){wait();}
            System.out.println("Done");
        }catch(Exception e){}
    }
}

class SenderThread extends Thread{
    chat c;
    SenderThread(chat c){
        this.c=c;
    }
    @Override
    public void run(){
        c.send();
    }
}

class RecieverThread extends Thread{
    chat c;
    RecieverThread(chat c){
        this.c=c;
    }
    @Override
    public void run(){
        c.read();
    }
}

class ModeratedThread extends Thread{
    chat c;
    ModeratedThread(chat c){this.c=c;}
    @Override
    public void run(){
        c.mod();
    }
}

public class ChatMessageSys{
    public static void main(String args[]){
        chat c=new chat();
        SenderThread s= new SenderThread(c);
        RecieverThread r= new RecieverThread(c);
        ModeratedThread m=new ModeratedThread(c);
        s.start();
        r.start();
        m.start();
    }
}