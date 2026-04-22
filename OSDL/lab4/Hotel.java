class HotelRoomManagement {
    private int avlRoom;

    public HotelRoomManagement(int r) {
        this.avlRoom = r;
    }

    synchronized void bookRoom(String custName) {
        System.out.println(custName + " is trying to book a room...");

        while (avlRoom == 0) {
            System.out.println(custName + " is waiting...");
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted");
            }
        }

        avlRoom--;
        System.out.println(custName + " booked the room successfully!");
    }

    synchronized void releaseRoom(String custName) {
        avlRoom++;
        System.out.println(custName + " released the room.");
        notify();
    }
}

class Customer extends Thread {
    private HotelRoomManagement h;
    private boolean isBook;

    Customer(boolean isBook, String name, HotelRoomManagement h) {
        super(name);
        this.isBook = isBook;
        this.h = h;
    }

    @Override
    public void run() {
        if (isBook) {
            h.bookRoom(getName());
        } else {
            h.releaseRoom(getName());
        }
    }
}

public class Hotel {
    public static void main(String[] args) {
        HotelRoomManagement h = new HotelRoomManagement(1);

        Customer c1 = new Customer(true, "Ola", h);
        Customer c2 = new Customer(false, "Negaros", h);

        c1.start();
        c2.start();
    }
}
