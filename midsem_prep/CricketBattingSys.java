import java.util.*;

enum ShotType {
    SINGLE(1),
    DOUBLE(2),
    FOUR(4),
    SIX(6),
    OUT(0);

    int r;

    ShotType(int r) { this.r = r; }

    public int getRuns() {
        return r;
    }
}

interface BattingOperations {
    void playShot(ShotType shot);
    void getOut();
}

class CricketPlayer {
    String playerName;
    int runs = 0;
    boolean isOut = false;

    public boolean isOut() {
        return isOut;
    }

    public int getRuns() {
        return runs;
    }
}

class Batsman extends CricketPlayer implements BattingOperations {

    Batsman(String name) {
        this.playerName = name;
    }

    public synchronized void playShot(ShotType shot) {
        if (isOut) return;

        runs += shot.getRuns();
        System.out.println("Shot: " + shot +
                " | Total: " + runs);
    }

    public synchronized void getOut() {
        if (!isOut) {
            isOut = true;
            System.out.println(playerName + " is OUT!");
        }
    }
}

class BattingThread extends Thread {
    Batsman b;

    BattingThread(Batsman b) {
        this.b = b;
    }

    public void run() {
        while (!b.isOut()) {
            b.playShot(ShotType.FOUR);
            try { Thread.sleep(1000); }
            catch (InterruptedException e) {}
        }
    }
}

class FieldingThread extends Thread {
    Batsman b;

    FieldingThread(Batsman b) {
        this.b = b;
    }

    public void run() {
        try {
            Thread.sleep(3000);
            b.getOut();
        }
        catch (InterruptedException e) {
            System.out.println("Interrupt");
        }
    }
}

class UmpireThread extends Thread {
    Batsman b;

    UmpireThread(Batsman b) {
        this.b = b;
    }

    public void run() {
        while (!b.isOut()) {
            System.out.println("Score: " + b.getRuns());
            try { Thread.sleep(1500); }
            catch (InterruptedException e) {}
        }
        System.out.println("Final Score: " + b.getRuns());
    }
}

public class CricketBattingSys {
    public static void main(String[] args) {

        Batsman b = new Batsman("Virat");

        BattingThread bt = new BattingThread(b);
        FieldingThread ft = new FieldingThread(b);
        UmpireThread ut = new UmpireThread(b);

        bt.start();
        ft.start();
        ut.start();
    }
}