# Write your MySQL query statement below

select em.unique_id ,e.name
from employees e
left join employeeUNI em
on e.id=em.id
