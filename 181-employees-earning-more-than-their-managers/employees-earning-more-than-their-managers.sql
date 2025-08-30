select q.name as Employee
from Employee q
join Employee w
on q.managerId = w.id
where q.salary > w.salary