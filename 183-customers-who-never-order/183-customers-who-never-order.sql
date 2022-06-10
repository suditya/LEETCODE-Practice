# Write your MySQL query statement below
select Customers.name as Customers from Customers left join Orders on Customers.id=Orders.customerID where customerID is null; 