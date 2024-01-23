# Write your MySQL query statement below
select query_name, round(sum(rating / position) / count(query_name), 2) as quality,
round((select count(rating) from Queries q2 where rating < 3 and q2.query_name = q1.query_name) / count(query_name) * 100, 2) 
as poor_query_percentage
from Queries q1 
where query_name is not null
group by query_name;