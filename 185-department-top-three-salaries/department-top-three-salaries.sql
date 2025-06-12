# Write your MySQL query statement below
WITH rank_rows AS (
	SELECT departmentId, name, salary,
	DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) AS ranking
    FROM Employee
)
SELECT d.name AS 'Department' , r.name AS 'Employee' , r.salary AS 'Salary' FROM rank_rows AS r JOIN Department AS d 
ON r.departmentId = d.id
WHERE r.ranking BETWEEN 1 AND 3
ORDER BY Department ASC, Salary DESC;