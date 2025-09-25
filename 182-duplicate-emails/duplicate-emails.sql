# Write your MySQL query statement belowfrom person

select email as Email
from person
group by email
having count(id)>1;