import java.util.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;

class Appointment{
    int pid;
    String pname,docname,date,time;
    Appointment(int pid,String pname,String docname,String date,String time){
        this.pid=pid;
        this.pname=pname;
        this.docname=docname;
        this.date=date;
        this.time=time;
    }

    public String toString(){
        return pid+" "+pname+" "+docname+" "+date+" "+time;
    }
}

class Service <T extends Appointment> {
    ArrayList<T>list=new ArrayList<>();
    HashMap<Integer,T>mpp=new HashMap<>();

    void add(T data) throws Exception{
        if(mpp.containsKey(data.pid)){throw new Exception("Patient Already present");}
        list.add(data);
        mpp.put(data.pid,data);
    }

    void viewAll(){
        for(T x:list){
            System.out.println(x);
        }
    }

    void searchPID(int pid){
        if(!mpp.containsKey(pid)){
            System.out.println("Not found");
            return;
        }
        for(T x:list){
            if(x.pid==pid){
                System.out.println(x);
            }
        }
    }

    void searchDocName(String docname){
        for(T x:list){
            if(x.docname.equalsIgnoreCase(docname)){
                System.out.println(x);
            }
        }
    }

    void cancelAppointment(int pid){
        T obj=mpp.get(pid);
        list.remove(obj);
        mpp.remove(pid);
    }
}

public class App extends Application{
    Service<Appointment>s=new Service<>();
    TextArea out=new TextArea();

    public void start(Stage stage){
        TextField pid = new TextField();
        TextField name = new TextField();
        TextField doc = new TextField();
        TextField date = new TextField();
        TextField time = new TextField();

        Button add=new Button("add");
        Button view= new Button("View");

        add.setOnAction(e->{
            try{
                s.add(new Appointment(Integer.parseInt(pid.getText()),
                name.getText(),
                doc.getText(),
                date.getText(),
                time.getText()
            ));
            out.setText("Added");
            }
            catch(Exception ex){}
        });

        view.setOnAction(e->{
            out.clear();
            for(Appointment a:s.list){
                out.appendText(a+"\n");
            }
        });
        VBox root = new VBox(10, pid, name, doc, date, time, add, view, out);
        stage.setScene(new Scene(root,400,300));
        stage.show();
    }

    public static void main(String args[]) throws Exception{
        launch();

    }
}

