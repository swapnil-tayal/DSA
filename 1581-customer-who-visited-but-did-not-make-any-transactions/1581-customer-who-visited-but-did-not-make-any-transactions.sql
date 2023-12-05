# Write your MySQL query statement below
SELECT Visits.customer_id, COUNT(Visits.visit_id) AS count_no_trans FROM Visits LEFT JOIN Transactions
ON Visits.visit_id = Transactions.visit_id WHERE Transactions.amount IS null
GROUP BY Visits.customer_id;
