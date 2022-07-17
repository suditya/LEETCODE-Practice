# Write your MySQL query statement below
# select email from Person having count(email) > 1;
SELECT email 
FROM person 
GROUP BY email
HAVING COUNT(email)>1;