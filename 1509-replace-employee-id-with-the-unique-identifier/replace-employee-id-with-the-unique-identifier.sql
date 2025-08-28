# Write your MySQL query statement below

select EmployeeUNI.unique_id , Employees.name
from Employees
LEFT join EmployeeUNI
on Employees.id = EmployeeUNI.id