# Write your MySQL query statement below
select r.contest_id, round(count(r.user_id)/(select count(user_id) from Users) * 100, 2) as percentage 
from Register r
group by r.contest_id
order by round(count(r.user_id)/(select count(user_id) from Users) * 100, 2) desc, r.contest_id asc;
