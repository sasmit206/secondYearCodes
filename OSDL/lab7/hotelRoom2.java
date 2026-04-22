/*
2. Create a Java program for a hotel room management system that uses a generic
method to display room-related data of different types such as room numbers,
room types, prices, and booking status.
• Implement a generic method <T> void display(T data)
• Call the method with:
1. Room number (Integer)
2. Room type (String)
3. Price per night (Double)
4. Booking status (Boolean)
• Ensure type safety without explicit casting
*/
class Room{
    <T>void display(T data){
        System.out.println("The Value is : "+data);
    }
}
public class hotelRoom2 {
    public static void main(String[] args) {
        Room r1=new Room();
        r1.display(34);
        Room r2=new Room();
        r2.display("Deluxe");
    }
}
