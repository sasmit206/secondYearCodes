import java.util.*;

import javax.naming.InsufficientResourcesException;

import java.io.*;

interface AccountOperations {
    void deposit(double amount) ;
    void withdraw(double amount)throws InsufficientBallanceException;
    void displayLog();
}

class BankAccount {
    int acno;
    String acnm;
    double balance;
    BankAccount(int acno,String acnm,double balance){
        this.acno=acno;
        this.acnm=acnm;
        this.balance=balance;
    }
}

class InsufficientBallanceException extends Exception{
    InsufficientBallanceException(String message){super(message);}
}
class SavingsAccount extends BankAccount implements AccountOperations{
    SavingsAccount(int acno,String acnm,double balance){
        super(acno, acnm, balance);
    }

    public synchronized void deposit(double amount){
        balance+=amount;
        try{
            FileWriter fw = new FileWriter("bank_log.txt", true);
            fw.write("DEPOSIT | AMT = " + amount + " | BALANCE: " + balance + "\n");
            fw.close();
        }catch(Exception e){}
        notifyAll();
    }

    public synchronized void withdraw(double amount) throws InsufficientBallanceException{
        while(amount>balance){
            try{wait();}catch(Exception e){}
        }
        balance=balance-amount;
        System.out.println("Withdrawal Successfull | Balance : "+balance);
        try{
            FileWriter fw= new FileWriter("bank_log.txt",true);
            fw.write("WITHDRAWAL | AMT = "+amount+"BALANCE: "+balance+"\n");
            fw.close();
        }catch(Exception e){}

    }

    public void displayLog(){
        int ch;
        String line="";
        try{
            FileReader fr= new FileReader("bank_log.txt");
            while((ch=fr.read())!=-1){
                line+=(char)ch;
            }
            fr.close();
        }catch(Exception e){}
        System.out.println(line);
    }
}

class depositThread extends Thread{
    SavingsAccount s;
    depositThread(SavingsAccount s){this.s=s;}
    @Override
    public void run(){
        Scanner in=new Scanner(System.in);
        System.out.println("Enter amt to be deposited");
        int amt=in.nextInt();
        s.deposit(amt);
    }
}

class withdrawThread extends Thread{
    SavingsAccount s;
    withdrawThread(SavingsAccount s){this.s=s;}
    @Override
    public void run(){
        try{
            Scanner in=new Scanner(System.in);
            System.out.println("Enter amt to be withdrawn");
            int amt=in.nextInt();
            s.withdraw(amt);
        }catch(InsufficientBallanceException e){System.out.println(e);}
    }
}

public class BankMgmtSys{
    public static void main(String args[]){
        SavingsAccount s= new SavingsAccount(12, "Rohan", 69.420);
        depositThread d1=new depositThread(s);
        withdrawThread w1 = new withdrawThread(s);
        d1.start();
        try{
            Thread.sleep(1000);
        }catch(Exception e){}
        w1.start();
        try{
            d1.join();
            w1.join();
        }catch(Exception e){}
        System.out.println(s.balance);
        s.displayLog();
    }
}