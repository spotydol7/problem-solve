-- 코드를 입력하세요
SELECT o.animal_id, o.name 
from animal_outs as o left outer join animal_ins as i
on i.animal_id = o.animal_id
where isnull(i.animal_id)