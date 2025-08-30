# Write your MySQL query statement below
-- select  q.name 
-- from Employee q
-- join Employee w
-- on q.id = w.managerId
-- group by q.managerId
-- having count(q.id) >= 5

SELECT q.name
FROM Employee q
JOIN Employee w
  ON q.id = w.ManagerId
GROUP BY q.id
HAVING COUNT(w.id) >= 5;
