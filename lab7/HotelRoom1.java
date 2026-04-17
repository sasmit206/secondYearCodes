/*
1. Develop a Java application that uses a generic class with two type parameters
to store hotel room information. The generic class should be capable of holding
different data types for room identifiers and room attributes.
• Create a generic class Room<T, U>
• T represents Room Number or Room ID
• U represents Room Type or Price
• Demonstrate usage with different data types (e.g., Integer, String, Double)
• Display stored room details
*/

class Room <T,U>{
    T rno;
    U price;
    void Print(T rno,U price){
        this.rno=rno;
        this.price=price;
        System.out.println(rno +" "+price);
    }
}
public class HotelRoom1 {
    public static void main(String[] args) {
        Room<String,Integer> r1=new Room<>();
        r1.Print("AB104", 34);
    }
}
