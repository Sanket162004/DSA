# Write your MySQL query statement below

SELECT EmployeeUNI.unique_id , Employees.name  FROM EMPLOYEES
left JOIN EmployeeUNI ON Employees.id=EmployeeUNI.id; 



--   SELECT EmployeeUNI.unique_id, Employees.name
-- FROM Employees
-- LEFT JOIN EmployeeUNI
--   ON Employees.id = EmployeeUNI.id;
