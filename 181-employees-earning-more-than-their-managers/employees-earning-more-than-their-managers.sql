# Write your MySQL query statement below

select e1.name as employee
from employee e1
left join employee e2
on e1.managerID=e2.id
where e1.salary>e2.salary