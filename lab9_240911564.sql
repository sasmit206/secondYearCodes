-- Write a procedure to display a message “Good Day to You”.

create or replace procedure message is
begin
    dbms_output.put_line('Good Day To You');
end;
/

set SERVEROUTPUT on;
BEGIN   
    message;
end;
/

-- Based on the University Database Schema in Lab 2, write a procedure which takes
-- the dept_name as input parameter and lists all the instructors associated with the
-- department as well as list all the courses offered by the department. Also, write an
-- anonymous block with the procedure call

create or replace PROCEDURE lol(in_dept_name varchar2) is
begin
    For x in (
        Select name 
        from instructor i
        where in_dept_name=i.dept_name
    )
    loop
        dbms_output.put_line(x.name);
    end loop;

    For y in(
        Select title 
        from course c
        where c.dept_name=in_dept_name
    )
    loop
        dbms_output.put_line(y.title);
    end loop;
end;
/

begin
    lol('CSE');
end;
/

/*
Based on the University Database Schema in Lab 2, write a Pl/Sql block of code
that lists the most popular course (highest number of students take it) for each of
the departments. It should make use of a procedure course_popular which finds
the most popular course in the given department.
*/
set serverouput on;
create or replace procedure course_popular(in_dept_name varchar2) is
begin
    for rec in(
    select c.course_id,count(t.id) as cnt
    from course c
    left join takes t
    on c.course_id=t.course_id
    where c.dept_name=in_dept_name
    group by c.course_id
    HAVING COUNT(t.id)>=all(
        select count(t2.id)
        from course c2
        left join takes t2
        on c2.course_id=t2.course_id
        where c2.dept_name=in_dept_name
        group by c2.course_id
    )
    )LOOP
        dbms_output.put_line(rec.course_id);
    end loop;
end;
/

begin
    course_popular('CSE');
end;
/
show errors;

/*
Based on the University Database Schema in Lab 2, write a procedure which takes
the dept-name as input parameter and lists all the students associated with the
department as well as list all the courses offered by the department. Also, write an
anonymous block with the procedure call.
*/

set serveroutput on;

create or replace procedure dept_stu(in_dept_name varchar2) is
BEGIN
    for x in(
        select s.name
        from student s
        where s.dept_name=in_dept_name
    )
    loop
        dbms_output.put_line(x.name);
    end loop;

    for y in(
        select c.title
        from course c
        where c.dept_name=in_dept_name
    )
    loop
        dbms_output.put_line(y.title);
    end loop;
end;
/

begin
    dept_stu('CSE');
end;
/

show errors;




/*Write a function to return the Square of a given number and call it from an
anonymous block.*/
set serveroutput on;
create or replace function sq(num number)
return number
as
begin
    return num*num;
end;
/

declare
    numsq number;
begin 
    numsq:=sq(4);
    DBMS_OUTPUT.PUT_LINE(numsq);
end;
/


/*
Based on the University Database Schema in Lab 2, write a Pl/Sql block of code
that lists the highest paid Instructor in each of the Department. It should make use
of a function department_highest which returns the highest paid Instructor for the
given branch.
*/

create or replace function high_ins(in_dept_name varchar2)
return instructor.name%type
as 
begin
    for rec in (
        Select i.name
        from INSTRUCTOR i
        where i.DEPT_NAME=in_dept_name
        and i.salary>=all(
            select i.salary from INSTRUCTOR i where i.DEPT_NAME=in_dept_name
        )
    )
    loop
        return rec.name;
    end loop;
    return 'NO INS FOUND';
end;
/
declare
    ins_name instructor.name%type;
begin
    ins_name:=high_ins('&dept_name');
    DBMS_OUTPUT.PUT_LINE(ins_name);
end;
/

show errors;

/*
7. Based on the University Database Schema in Lab 2, create a package to include
the following:
a) A named procedure to list the instructor_names of given department
b) A function which returns the max salary for the given department
c) Write a PL/SQL block to demonstrate the usage of above package components
*/

create or replace package ins_info as

    procedure ins_of_dept(
        in_dept_name instructor.dept_name%type
    );

    function maxs_of_dept(
        in_dept_name instructor.dept_name%type
    ) return instructor.salary%type;

end ins_info;
/

create or replace package body ins_info as

    procedure ins_of_dept(in_dept_name instructor.dept_name%type) is
    begin 
        for rec in (
            Select i.name 
            from instructor i
            where i.dept_name=in_dept_name
        )
        loop
            dbms_output.put_line(rec.name);
        end loop;
    end;

    function maxs_of_dept(in_dept_name instructor.dept_name%type) 
    return instructor.salary%type
    as
    begin 
        for rec in (
            Select max(i.salary) as salary
            from instructor i
            where i.dept_name=in_dept_name
        )
        loop
            return rec.salary;
        end loop;
        return -1;
    end;
end ins_info;
/


declare 
    dept_name instructor.dept_name%type;
    salary instructor.salary%type;
begin
    ins_info.ins_of_dept('CSE');
    salary:=ins_info.maxs_of_dept('CSE');
    dbms_output.put_line(salary);
end;
/

show errors;
        




-- 8. Write a PL/SQL procedure to return simple and compound interest (OUT
-- parameters) along with the Total Sum (IN OUT) i.e. Sum of Principle and Interest
-- taking as input the principle, rate of interest and number of years (IN parameters).
-- Call this procedure from an anonymous block.

create or replace procedure calc_i(
    p in number,
    r in number,
    n in number,
    ci out number,
    si out number,
    total in out number
)
is
begin
    si:=(p*r*n)/100;
    ci:=p*power((1+r/100),n)-p;
    total:=si+ci;
end;
/

declare 
    p number :=1000;
    r number :=5;
    t number :=5;
    si number;
    ci number;
    total number:=-1;
begin
    calc_i(p,r,t,ci,si,total);
    dbms_output.put_line('SI: ' || si);
    dbms_output.put_line('CI: ' || ci);
    dbms_output.put_line('Total: ' || total);
end;
/

show errors;

