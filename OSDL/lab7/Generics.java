class Printer<T>{
    void print(T value){
        System.out.println("The value is : "+value);
    }
}

public class Generics {
    public static void main(String[] args) {
        Printer<Integer> xd=new Printer<>();
        xd.print(45);
    }
}
