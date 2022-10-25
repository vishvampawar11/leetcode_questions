# Write your MySQL query statement below
SELECT SalesPerson.name from 
Orders join Company ON (Orders.com_id = Company.com_id and Company.name = "RED")
RIGHT JOIN SalesPerson ON Orders.sales_id = SalesPerson.sales_id WHERE Orders.com_id IS NULL;