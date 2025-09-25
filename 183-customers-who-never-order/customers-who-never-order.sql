# Write your MySQL query statement below
select c.name as customers
from customers c
left join orders o
on o.customerID=c.id
where o.customerID is NULL
