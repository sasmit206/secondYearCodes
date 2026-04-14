
-- The HRD manager has decided to raise the salary of all the Instructors in a given
-- department number by 5%. Whenever, any such raise is given to the instructor, a
-- record for the same is maintained in the salary_raise table. It includes the Instuctor
-- Id, the date when the raise was given and the actual raise amount. Write a PL/SQL
-- block to update the salary of each Instructor and insert a record in the salary_raise
-- table.
-- salary_raise(Instructor_Id, Raise_date, Raise_amt)
	
declare
    i_id instructor.INSTRUCTOR_ID%TYPE;
    i_sal instructor.salary%TYPE;
    i_raise NUMBER;
    cursor c is
        Select INSTRUCTOR_ID,salary
        from instructor 
        where dept_no=&dept_no;

begin
    open c;
    if c%isopen then
        loop
            fetch c into i_id,i_sal;
            exit when c%notfound;
            i_raise:=i_sal*0.05;
            update instructor
            set salary=salary+i_raise
            where INSTRUCTOR_ID=i_id;

            insert into salary_raise(instructor_id,raise_date,raise_amt)values(i_id,sysdate,i_raise);
        end loop;
    end if;
    close c;
    commit;
end;
/


2.
Write a PL/SQL block that will display the ID, name, dept_name and tot_cred of
the first 10 students with lowest total credit.

declare 
    rec student%ROWTYPE;
    CURSOR c is
        select id, name,dept_name,tot_cred
        from STUDENT
        order by tot_cred asc;
begin
    open c;
    loop
        fetch c into rec;
        exit when c%notfound;

        dbms_output.put_line(rec.id||rec.name||rec.dept_name||rec.tot_cred);
        exit when c%rowcount=10;
    end loop;
    close c;
end;
/

/*
Find all students who take the course with Course-id: CS101 and if he/ she has
less than 30 total credit (tot-cred), deregister the student from that course. (Delete
the entry in Takes table)
*/

Declare
    cursor c is
        select s.id 
        from student s 
        join takes t
        on s.id=t.id
        where s.tot_cred<30
        and t.course_id='CS101';
    
BEGIN   
    for rec in c 
    loop 
        delete from takes 
        where takes.id=rec.id
        and takes.course_id='CS101';
        dbms_output.put_line('Deleted. : '||rec.id);
    end loop;
end;
/

/*
Alter StudentTable(refer Lab No. 8 Exercise) by resetting column LetterGrade to
F. Then write a PL/SQL block to update the table by mapping GPA to the
corresponding letter grade for each student.
*/

set serveroutput on;
update studenttable set lettergrade='F';

declare 
    cursor c is
        select * from studenttable
        for update;
    v_grade studenttable.LETTERGRADE%TYPE;

begin
    for rec in c
    loop
        IF rec.gpa >=0 AND rec.gpa < 4 THEN
		v_grade := 'F';
		ELSIF rec.gpa >=4 AND rec.gpa < 5 THEN
		v_grade := 'E';
		ELSIF rec.gpa >= 5 AND rec.gpa < 6 THEN
		v_grade := 'D';
		ELSIF rec.gpa >= 6 AND rec.gpa < 7 THEN
		v_grade := 'C';
		ELSIF rec.gpa >=7 AND rec.gpa < 8 THEN
		v_grade := 'B';
		ELSIF rec.gpa >=8 AND rec.gpa < 9 THEN
		v_grade := 'A';
		ELSIF rec.gpa >= 9 AND rec.gpa <= 10 THEN
		v_grade := 'A+';
		END IF;
    update studenttable set studenttable.lettergrade=v_grade where current of c;
    end loop;
end;
/
    

/*
Write a PL/SQL block to print the list of Instructors teaching a specified course.
*/

Declare 
    cursor c1 is
        select * 
        from INSTRUCTOR i
        join teaches t 
        on i.id=t.id
        where t.course_id='&course_id';
begin
    for rec in c1
    LOOP    
        dbms_output.put_line(rec.name);
    end loop;
end;
/


/*
Write a PL/SQL block to list the students who have registered for a course taught
by his/her advisor.
*/
declare
    cursor c1 is
        select s.name
        from student s
        join teaches t
        on s.advisor_id=t.id
        join takes tk
        on tk.course_id=t.course_id
        and tk.id=s.id;
begin
    for rec in c1 
    loop
        dbms_output.put_line(rec.name);
    end loop;
end;
/



        
        
    


