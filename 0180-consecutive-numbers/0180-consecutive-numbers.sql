# Write your MySQL query statement below
select distinct l.num as ConsecutiveNums
from Logs l join Logs s
on l.id+1=s.id
join Logs c
on s.id+1=c.id
and l.num=s.num and l.num=c.num;

