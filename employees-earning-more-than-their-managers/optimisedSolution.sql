# Write your MySQL query statement below
select e.name as Employee
from Employee e
join Employee m
on e.managerId=m.id
where e.salary > m.salary
-- # Write your MySQL query statement below
-- select name as Employee from Employee e1 where salary > (select salary from Employee where id=e1.managerId);