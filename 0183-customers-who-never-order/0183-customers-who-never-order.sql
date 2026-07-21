# Write your MySQL query statement below
select c.name as Customers
from Customers c
where  not exists (select o.customerID from Orders o
where o.customerID=c.id)

