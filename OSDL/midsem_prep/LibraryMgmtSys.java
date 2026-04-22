// Design and implement a Library Book Lending System demonstrating object-oriented concepts with the following requirements:

// 1.⁠ ⁠Define an interface ItemOperations with methods:

// checkout()

// returnItem()



// 2.⁠ ⁠Create a base class LibraryItem containing:

// itemID

// title

// author

// isAvailable



// 3.⁠ ⁠Create a class StudentMember that inherits from LibraryItem and implements the interface.


// 4.⁠ ⁠Define a custom Exception class InvalidTransactionException.


// 5.⁠ ⁠Implement multithreading in the library environment:

// A thread representing a student borrowing a book.

// A thread representing a librarian processing returns.

// Synchronize threads to avoid race conditions.



// 6.⁠ ⁠Use exception handling to manage:

// Borrowing unavailable items.

// Returning items that were not borrowed.

// 7.⁠ ⁠Output:

// Display transaction logs.

// Show available items after operations are performed.
import java.util.*;
import java.io.*;

interface  ItemOperations {
    void checkout() throws InvalidTransactionException;
    void returnItem(int itemID)throws InvalidTransactionException;
}

class LibraryItem { 
    int itemID;
    String title,author;
    boolean isAvailable;
    LibraryItem(int itemID,String tite,String author,boolean isAvailable){
        this.itemID=itemID;
        this.title=title;
        this.author=author;
        this.isAvailable=isAvailable;
    }
}
class StudentMember extends LibraryItem implements ItemOperations{
    StudentMember(int itemID,String tite,String author,boolean isAvailable){
        super(itemID, tite, author, isAvailable);
    }
    public synchronized void checkout() throws InvalidTransactionException{
        if(!isAvailable){throw new InvalidTransactionException("Nahi hai bhai");}
        isAvailable=false;
        System.out.println("Issued the book w/ ID: "+itemID);

    }
    public synchronized void returnItem(int itemID) throws InvalidTransactionException{
        if(!isAvailable){throw new InvalidTransactionException("Nahi hai bhai");}
        System.out.println("Return Book ID: "+itemID);
        isAvailable=true;
    }
}

class BorrowThread extends Thread{
    StudentMember book;
    BorrowThread(StudentMember book){
        this.book=book;
    }
    @Override
    public void run(){
        try{
            book.checkout();
        }
        catch(InvalidTransactionException e){System.out.println(e);}
    }
}

class ReturnThread extends Thread{
    StudentMember book;
    ReturnThread(StudentMember book){
        this.book=book;
    }
    @Override
    public void run(){
        try{
            book.returnItem(12);
        }
        catch(InvalidTransactionException e){System.out.println(e);}
    }
}


class InvalidTransactionException extends Exception{
    InvalidTransactionException(String message){
        super(message);
    }
}

public class LibraryMgmtSys {
    public static void main(String[] args) {
        StudentMember s=new StudentMember(12, "The Namesake", "Jhumpa Lahiri", true);
        BorrowThread b1=new BorrowThread(s);
        ReturnThread r1=new ReturnThread(s);
        b1.start();
        r1.start();

        
    }
}
