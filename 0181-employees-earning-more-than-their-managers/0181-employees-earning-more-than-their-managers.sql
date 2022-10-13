# Write your MySQL query statement below
SELECT E1.name AS Employee FROM Employee AS E1, Employee AS E2 WHERE E1.managerId = E2.id AND E1.salary > E2.salary;