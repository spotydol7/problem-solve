select a.ID 
from ecoli_data a
join ecoli_data b on a.parent_id = b.id
join ecoli_data c on b.parent_id = c.id
where c.parent_id is NULL
order by a.ID asc