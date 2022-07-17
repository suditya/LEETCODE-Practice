# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
# select distinct email from Person;
# delete email from person having count(email)>1;


delete p1 from person p1 , person p2 where p1.email=p2.email and p1.id > p2.id;