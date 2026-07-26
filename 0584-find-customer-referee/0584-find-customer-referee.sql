# Write your MySQL query statement below
select c.name
from Customer c
where c.referee_id not in(select id from Customer where id=2)
or c.referee_id is NULL;
