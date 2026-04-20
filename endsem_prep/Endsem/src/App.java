import java.util.ArrayList;
import java.util.HashMap;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.scene.control.*;

import java.io.*;

class Book implements Serializable{
    int bid;
    String btitle;
    String bname;
    String genre;
    String stat;
    Book(int bid,String btitle,String bname,String genre,String stat){
        this.bid=bid;
        this.btitle=btitle;
        this.bname=bname;
        this.genre=genre;
        this.stat=stat;
    }
    public String toString(){
        return bid+" "+btitle+" "+bname+" "+genre+" "+stat;
    }
}

class Member implements Serializable{
    String mname;
    int mno;
    int mid;
    Member(String mname,int mno,int mid){
        this.mname=mname;
        this.mno=mno;
        this.mid=mid;
    }
    public String toString(){
        return mname+" "+mno+" "+mid;
    }
}

class Service<T extends Book,U extends Member>{
    ArrayList<Book>list=new ArrayList<>();
    HashMap<Integer,Book>mpp=new HashMap<>();

    ArrayList<Member>mlist=new ArrayList<>();
    HashMap<Integer,Member>m_mpp=new HashMap<>();

    void addBook(Book b)throws Exception{
        if(mpp.containsKey(b.bid)){
            throw new Exception("BID already present");
        }
        mpp.put(b.bid,b);
        list.add(b);
    }

    void viewAll(){
        for(Book b:list){
            System.out.println(b);
        }
    }
    void viewAv(){
        for(Book b:list){
            if(b.stat.equalsIgnoreCase("available"))
                System.out.println(b);
        }
    }

    void addMem(Member m) throws Exception{
        if(m_mpp.containsKey(m.mid)){
            throw new Exception("member ID already present");
        }
        m_mpp.put(m.mid,m);
        mlist.add(m);
    }

    void viewMem(){
        for(Member m:mlist){
            System.out.println(m); 
        }
    }

    void issueBook(Member m,Book b) throws Exception{
        if(b.stat.equalsIgnoreCase("not available")){
            throw new Exception("Book already Issued");
        }
        for(Book bk:list){
            if(bk.bid==b.bid){bk.stat="not available";}
        }
    }

    void returnBook(Book b) throws Exception{
        for(Book bk:list){
            if(b.bid==bk.bid){
                bk.stat="available";
                return;
            }
        }
        throw new Exception("Book Not Found");
    }

    void saveToFile(){
        try{
            FileWriter fw=new FileWriter("books.txt",true);
            for(Book b:list){
                fw.write(b+"\n");
            }
            for(Member m:mlist){
                fw.write(m+"\n");
            }
            fw.close();
        }
        catch(Exception ex){System.out.println("no");
        }

    }

}

public class App extends Application{

    TextArea out=new TextArea();
    public void start(Stage stage){
        Button sample=new Button("sample");

        Service<Book,Member>s=new Service<>();
        
        Label lbid=new Label("Book Id");
        TextField bid=new TextField();
        Label lbtitle=new Label("Book Title");
        TextField btitle=new TextField();
        Label lbname=new Label("Author Name");
        TextField bname=new TextField();
        Label lgenre=new Label("Book Genre");
        TextField genre=new TextField();
        Label lstat=new Label("Book Status");
        TextField stat=new TextField();

        Button addBk=new Button("Add Book");
        Button viewBk=new Button("View Book");
        Button viewABk=new Button("View Available Books");
        Button rBook=new Button("Return Book");

        addBk.setOnAction(e->{
            out.clear();
            out.appendText("Added Book");
            try{
                s.addBook(new Book(Integer.parseInt(bid.getText()),btitle.getText(),bname.getText(),genre.getText(),stat.getText()));
            }
            catch(Exception ex){
                out.appendText(ex+"\n");
            }
        });

        viewABk.setOnAction(e->{
            out.clear();
            for(Book b:s.list){
                if(b.stat.equalsIgnoreCase("available")){
                    out.appendText(b+"\n");
                }
            }
        });

        rBook.setOnAction(e->{
            out.clear();
            try{
                 s.returnBook(new Book(Integer.parseInt(bid.getText()), btitle.getText(), bname.getText(), genre.getText(), stat.getText()));
                 out.appendText("Returned Book");
            }
            catch(Exception ex){
                out.appendText(ex+"\n");
            }
        });
           

        Label lmname=new Label("Member Name");
        TextField mname=new TextField();
        Label lmno=new Label("Member Number");
        TextField mno=new TextField();
        Label lmid=new Label("Member Id");
        TextField mid=new TextField();
        

        viewBk.setOnAction(e->{
            out.clear();
            out.appendText("Displaying all Books");
            for(Book b:s.list){
                out.appendText(b+"\n");
            }
        });

        Button addMem=new Button("Add Member");
        Button viewMem=new Button("View Members");

        addMem.setOnAction(e->{
            out.clear();
            try{
                s.addMem(new Member(mname.getText(), Integer.parseInt(mno.getText()), Integer.parseInt(mid.getText())));
                out.appendText("Added member");
            }
            catch(Exception ex){
                out.appendText(ex+"\n");
            }
        });

        viewMem.setOnAction(e->{
            out.clear();
            out.appendText("Displaying all Members:\n");
            for(Member m:s.mlist){
                out.appendText(m+"\n");
            }
        });

        Button lib=new Button("Issue Book");

        lib.setOnAction(e->{
            try{
                 s.issueBook(new Member(mname.getText(), Integer.parseInt(mno.getText()), Integer.parseInt(mid.getText())),new Book(Integer.parseInt(bid.getText()),btitle.getText(),bname.getText(),genre.getText(),stat.getText()));
                 out.appendText("Issued Book");
            }
            catch(Exception ex){
                out.appendText(ex+"\n");
            }
        });

        Button save=new Button("Save to File");
        save.setOnAction(e->{
            s.saveToFile();
        });

        VBox root=new VBox(lbid,bid,lbtitle,btitle,lbname,bname,lgenre,genre,lstat,stat,addBk,viewBk,viewABk,lmname,mname,lmno,mno,lmid,mid,addMem,viewMem,lib,rBook,save,out);
        stage.setScene(new Scene(root,800,800));
        stage.show();
        
        
    }
    public static void main(String[] args) throws Exception {
        launch();
    }
}
