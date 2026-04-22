import java.util.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;

class Student{
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
}
public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        Service<Student>s=new Service();
        
        int ch;
        Scanner in=new Scanner(System.in);
        do{
            
            System.out.println("Enter 1 to register,2 to display all, 3 to search by stu id, 4 to search course");
            ch=in.nextInt();
            switch(ch){
                
                case 1:
                    System.out.println("Enter student id, student name, Course name, Instructor name");
                    int sid;
                    String sname,cname,iname;
                    sid=in.nextInt();
                    sname=in.next();
                    cname=in.next();
                    iname=in.next();  
                    s.reg(new Student(sid, sname, cname, iname));
                    break;
                case 2:
                    s.displayAll();
                    break;
                case 3:
                    s.searchSID(1);
                    break;
                case 4:
                    s.searchCo("Lolo");
                    break;
                case 5:
                    break;
            }
        }while(ch<=5);
        
        s.displayAll();
    }
}
