import java.util.*;
import javafx.application.*;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;

import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;


class Library{
    int bid;
    String bname;
    String aname;
    Library(int bid,String bname,String aname){
        this.bid=bid;
        this.bname=bname;
        this.aname=aname;
    }
    public String toString(){
        return bid+" "+bname+" "+aname;
    }
}

class Service <T extends Library>{
    ArrayList<T>list=new ArrayList<>();

    void addBook(T data){
        for(T x:list){
            if(x.bid==data.bid){
                System.out.println("Duplicate");
                return;
            }
        }
        list.add(data);
    }

    void listAll(){
        for(T x:list){
            System.out.println(x);
        }
    }

    void searchBook(int bid){
        for(T x:list){
            if(x.bid==bid){
                System.out.println("Book Found");
                System.out.println(x);
                return;
            }
        }
        System.out.println("No such book");
    }

    void searchAuth(String auth){
        for(T x:list){
            if(x.aname==auth){
                System.out.println("Author Found");
                System.out.println(x);
                return;
            }
        }
        System.out.println("No such book");
    }

    void deleteBook(int bid){
        for(T x:list){
            if(x.bid==bid){
                list.remove(x);
                System.out.println("Book Deleted");
                return;
            }
        }
    }
}


public class App2 extends Application{
    Service<Library> s=new Service<>();
    TextArea out=new TextArea();
    public void start(Stage stage){
        TextField bid=new TextField();
        TextField bname=new TextField();
        TextField aname=new TextField();

        Button add = new Button("Add");
        Button view= new Button("View");

        add.setOnAction(e->{
            int id=Integer.parseInt(bid.getText());
            s.addBook(new Library(
                id,
                bname.getText(),
                aname.getText()
            ));
        });
        out.setText("Added");

        view.setOnAction(e->{
            out.clear();
            for(Library x:s.list){
                out.appendText(x+"\n");
            }
        });

        VBox root=new VBox(10,bid,bname,aname,add,view,out);
        stage.setScene(new Scene(root,300,400));
        stage.show();
    }
    public static void main(String args[]){
        launch();
    }
}  
