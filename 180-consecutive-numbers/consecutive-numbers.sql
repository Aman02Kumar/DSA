select distinct l1.num as ConsecutiveNums
from Logs l1 ,  Logs l2 ,  Logs l3
Where l1.id = l2.id -1 AND  l2.id = l3.id -1 and
        L1.num = l2.num AND l2.num = l3.num