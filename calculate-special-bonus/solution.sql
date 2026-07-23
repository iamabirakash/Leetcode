# Write your MySQL query statement below
select
    employee_id,
    CASE
        WHEN employee_id%2=1 AND name NOT LIKE 'M%' then salary
        ELSE 0
    END as bonus
    from Employees
    ORDER BY employee_id;