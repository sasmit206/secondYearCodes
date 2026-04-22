import java.util.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import java.io.*;

class Student implements Serializable{
    int sid;
    String sname;
    String cname;
    String iname;
    Student(int sid, String sname, String cname, String iname){
        this.sid = sid;
        this.sname = sname;
        this.cname = cname;
        this.iname = iname;
    }
    public String toString(){
        return sid+sname+cname+iname;
    }
}

class Service<T extends Student>{
    ArrayList<T>list=new ArrayList<>();

    void reg(T obj)throws Exception{
        for(Student x:list){
            if(x.sid==obj.sid){
                System.out.println("Duplicate Entry. Terminating..");
                throw new Exception("No Duplicate Allowed");
            }
        }
        list.add(obj);
    }
    void displayAll(){
        for(Student x:list){
            System.out.println(x);
        }
    }

    void searchSID(int sid){
        for(Student x:list){
            if(x.sid==sid){
                System.out.println("Found");
                System.out.println(x);
                return;
            }
        }
        System.out.println("NOt found");
    }

    void searchCo(String cname){
        for(Student x:list){
            if(x.cname==cname){
                System.out.println("FOund");
                System.out.println(x);
                return;    
            }
        }
        System.out.println("NOt found");
    }

    void delCo(String cname)throws Exception{
        for(Student x:list){
            if(x.cname.equalsIgnoreCase(cname)){
                list.remove(x);
                System.out.println("Removed the course : "+cname);
                return; 
            }
        }
        throw new Exception("Course NOt found");
    }

    void saveToFile(){
        try{
            FileOutputStream fos=new FileOutputStream("lol.txt");
            ObjectOutputStream oos=new ObjectOutputStream(fos);
            oos.writeObject(list);
            fos.close();
            oos.close();
        }
        catch(Exception ex){
            System.out.println(ex);
            
        }
        
    }
}
public class App2 extends Application{
    Service<Student>s=new Service();
    TextArea out=new TextArea();
    Student x=new Student(1, "Lol", "CSE", "Jashma");
    public void start(Stage stage){
        TextField sid=new TextField();
        TextField sname=new TextField();
        TextField cname=new TextField();
        TextField iname=new TextField();

        Button addStu=new Button("Add Student");
        Button viewStu=new Button("View All Students");
        Button searchStu=new Button("Search Student");
        Button searchC=new Button("Search Course");
        Button delC=new Button("Delete Course");
        Button saveF=new Button("Save File");

        addStu.setOnAction(e->{
            try{
                s.reg(
                    new Student(Integer.parseInt(sid.getText()), sname.getText(), cname.getText(), iname.getText())
                );
                out.appendText("Added :)");
            }
            catch(Exception ex){}
        });

        viewStu.setOnAction(e->{
            out.appendText("The following is total data:");
            try{
                out.clear();
                for(Student x:s.list){
                    out.appendText(x+"\n");
                }
            }
            catch(Exception ex){}
        });

        searchStu.setOnAction(e->{
            try{
                out.clear();
                for(Student x:s.list){
                    if(x.sid==Integer.parseInt(sid.getText())){
                        out.clear();
                        out.appendText("Found\n"+x);
                        return;
                    }
                }
            }
            catch(Exception ex){}
        });

        searchC.setOnAction(e->{
            try{
                out.clear();
                for(Student x:s.list){
                    if(x.cname.equalsIgnoreCase(cname.getText())){
                        out.clear();
                        out.appendText("Found COurse : \n"+x);
                        return;
                    }
                }
            }
            catch(Exception ex){}
        });

        delC.setOnAction(e->{
            try{
                out.clear();
                for(Student x:s.list){
                    if(x.cname.equalsIgnoreCase(cname.getText())){
                        out.clear();
                        out.appendText("Deleted COurse : \n"+x);
                        s.list.remove(x);
                        return;
                    }
                }
            }
            catch(Exception ex){}
        });

        saveF.setOnAction(e->{
            try{
                s.saveToFile();
                out.appendText("Saved");
            }
            catch(Exception ex){}
        });




        VBox root=new VBox(10,sid,sname,cname,iname,addStu,viewStu,searchStu,searchC,delC,saveF,out);
        stage.setScene(new Scene(root,300,400));
        stage.show();
    }
    public static void main(String[] args) throws Exception {
        launch();
    }
}
