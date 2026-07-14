# Write your MySQL query statement below
select class from Courses GROUP BY class HAVING count(class)>=5;