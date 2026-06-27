# Write your MySQL query statement below
select o.name  as Employee from Employee o
where o.salary>(select i.salary from Employee i 
                where o.managerID=i.id )