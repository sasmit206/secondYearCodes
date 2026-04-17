/*
Develop a Java application that uses bounded type parameters to calculate room
charges. The application should accept only numeric values for pricing and discount
calculations.
• Create a generic class or method using <T extends Number>
• Accept room price and discount as generic parameters
• Perform calculations such as:
o Total price
o Discounted price
• Prevent non-numeric data types at compile time
*/

class calculate<T extends Number>{
    T tp;
    T d;
    calculate(T tp,T d){
        this.tp=tp;
        this.d=d;
    }
    void display(){
        double total = tp.doubleValue();
        double disc = d.doubleValue();
        double dp = total - disc;
        System.out.println("The og ToT : "+tp);
        System.out.println("The new Tot : "+dp);
    }
}
public class RoomCharges {
    public static void main(String[] args) {
        calculate <Integer> c=new calculate<>(1234,123);
        c.display();
    }
}
