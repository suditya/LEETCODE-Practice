Select max(salary) as SecondHighestSalary
from Employee
where salary NOT IN (Select max(salary) from Employee)