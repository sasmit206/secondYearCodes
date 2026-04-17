// 1. Design and implement a Hotel Management System in Java using the
// Collection Framework to manage hotel operations efficiently. The system
// should store, retrieve, update, and process hotel-related data dynamically
// using appropriate collection classes.
// System Requirements
// Room Management
// Store room details such as:
// Room Number
// Room Type (Single, Double, Deluxe, Suite)
// Room Price per Day
// Availability Status
// Allow adding new rooms and displaying all available rooms.
// Customer Management                  HERE
// Maintain customer details including:
// Customer ID
// Name
// Contact Number
// Room Number Allocated                
// Support operations to add, view, and remove customer records.
// Booking Management
// Enable room booking and checkout functionality.
// Update room availability automatically after booking or checkout.
// Prevent booking of already occupied rooms.
// Collections Usage
// Use suitable collection classes such as:
// ArrayList to store room and customer objects
// HashMap to map room numbers to customer details
// Iterator to traverse and manage records
// Apply sorting (e.g., by room price or room number) using Collections.sort().
// Menu-Driven Interface
// Provide a console-based menu with options such as:
// Add Room
// Display Available Rooms
// Add Customer
// Book Room
// Checkout Customer
// Display All Customers
// Exit
// Constraints
// Do not use arrays for data storage.
// All data must be handled using Java Collections.
// Ensure proper validation and exception handling.
import java.util.*;

class mgmtRoom<T>{
    ArrayList<T>rnos=new ArrayList<>();
    ArrayList<String>rtypes=new ArrayList<>();
    ArrayList<Double>rprices=new ArrayList<>();
    ArrayList<String>ravls=new ArrayList<>();

    void addRoom(T rno,String rtype,Double rprice,String ravl){
        rnos.add(rno);
        rtypes.add(rtype);
        rprices.add(rprice);
        ravls.add(ravl);
    }
    
    void displayRoom(){
        for(T x:rnos){System.out.println(x);}
        for(String x:rtypes){System.out.println(x);}
        for(Double x:rprices){System.out.println(x);}
        for(String x:ravls){System.out.println(x);}
    }


    ArrayList<T>cids=new ArrayList<>();
    ArrayList<String>cnames=new ArrayList<>();
    ArrayList<Integer>cnos=new ArrayList<>();
    ArrayList<T>crnos=new ArrayList<>();

    void addCustomer(T cid,String cname,Integer number,T rno){
        cids.add(cid);
        cnames.add(cname);
        cnos.add(number);
        crnos.add(rno);
    }

    void viewCustomer(){
        for(T x:cids){System.out.println(x);}
        for(String x:cnames){System.out.println(x);}
        for(Integer x:cnos){System.out.println(x);}
        for(T x:crnos){System.out.println(x);}
    }

    void removeCustomer(T cid){
        int flag=0;
        for(T x:cids){
            if(x==cid){
                System.out.println("Removing Customer..");
                flag=1;
                cids.remove(x);
            }
        }
        if(flag==0){System.out.println("Cust not present");
        }
    }
}

public class hms{
    public static void main(String[] args) {
        mgmtRoom<Integer>mr1=new mgmtRoom<>();
        mr1.addRoom(1, "Deluxe", 4570.6, "Avl");
        mr1.displayRoom();

        mgmtRoom<String>mr2=new mgmtRoom<>();
        mr2.addRoom("A102", "Deluxe", 4570.6, "Avl");
        mr2.displayRoom();
    }
}