select e.name
from Employee e
inner join employee m
on e.id = m.managerId
group by m.managerId
having count(m.managerId)>=5; 
