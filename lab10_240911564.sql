-- Based on the University database schema in Lab: 2, write a row trigger to insert
-- the existing values of the Instructor (ID, name, dept-name, salary) table into a new
-- table Old_ Data_Instructor (ID, name, dept-name, salary) when the salary table is
-- updated.

create or replace trigger log
after update on Instructor 
for each row
begin
    if updating then
    insert into Old_Data_Instructor
    values(
    :old.id,
    :old.name,
    :old.dept_name,
    :old.salary
  );
  end if;
end;
/

-- Based on the University Schema, write a database trigger on Instructor that checks
-- the following:
--  The name of the instructor is a valid name containing only alphabets.
--  The salary of an instructor is not zero and is positive
--  The salary does not exceed the budget of the department to which the
-- instructor belongs


-- Create a transparent audit system for a table Client_master (client_no, name,
-- address, Bal_due). The system must keep track of the records that are being
-- deleted or updated. The functionality being when a record is deleted or modified
-- the original record details and the date of operation are stored in the auditclient
-- (client_no, name, bal_due, operation, userid, opdate) table, then the delete or
-- update is allowed to go through

-- create table Client_master(
--     client_no number,
--     name varchar2(20),
--     address varchar2(20),
--     Bal_due number
-- );
-- create table auditclient(
--     client_no number,
--     name varchar2(20),
--     Bal_due number,
--     operation varchar2(20),
--     user_id number,
--     opdate date
-- );

ALTER TABLE auditclient MODIFY user_id VARCHAR2(30);

create or replace trigger log2
before delete or update on Client_master
for each row
begin
    case
        when deleting then
            insert into auditclient values(:old.client_no,:old.name,:old.bal_due,'DELETE',USER,SYSDATE);
        when updating then
            insert into auditclient values(:old.client_no,:old.name,:old.bal_due,'UPDATE',USER,SYSDATE);
    end case;
end;
/
