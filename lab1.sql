--LAB EXERCISES:

--Create a table employee with ( emp_no, emp_name, emp_address)
CREATE TABLE employee(
  emp_no integer,
  emp_name varchar(20),	
  emp_address varchar(20));

--Insert five employees information.
  Insert into employee values(12,'lola','delhi');
  INSERT INTO employee VALUES (13, 'Amit', 'Mumbai');
  INSERT INTO employee VALUES (14, 'Sneha', 'Bangalore');
 INSERT INTO employee VALUES (15, 'Rahul', 'Chennai');
 INSERT INTO employee VALUES (16, 'Neha', 'Pune');

--Display names of all employees.
Select emp_name name from employee 

-- Display All Employees from Manipal
select emp_name name from employee where emp_address='Manipal'

--Add a column named salary to employee table.
alter table employee
add salary [integer]

--Assign the salary for all employees.
update employee set salary=71000 where emp_no=16;  (do similarly for multiple emp_no)


--View the structure of the table employee using describe.
describe employee;


--Delete all emp from Mangalore
delete from employee where emp_address Like '%Mangalore%'

-- Rename employee as employee1.
Rename employee as employee1;

-- Drop the table employee1.
drop table employee;








