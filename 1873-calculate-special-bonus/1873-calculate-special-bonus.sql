# Write your MySQL query statement below
# SELECT OrderID, Quantity,
# CASE WHEN Quantity > 30 THEN 'The quantity is greater than 30'
# WHEN Quantity = 30 THEN 'The quantity is 30'
# ELSE 'The quantity is under 30'
# END AS QuantityText
# FROM OrderDetails;
select employee_id,
case
when employee_id%2=1 && name not like "M%"
then salary
else
0
end as bonus
from Employees 
order by employee_id;