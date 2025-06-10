# Write your MySQL query statement below

select c.id,c.movie, c.description,c.rating
from cinema c
where c.description!='boring' and mod(c.id,2)=1
order by c.rating DESC;