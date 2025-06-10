# Write your MySQL query statement below
# Write your MySQL query statement below
Select p.project_id, ROUND(Avg(e.experience_years), 2) as average_years
from Project p
Left Join Employee e
on p.employee_id = e.employee_id
group by p.project_id