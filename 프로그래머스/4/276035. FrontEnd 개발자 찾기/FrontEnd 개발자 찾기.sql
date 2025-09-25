select distinct d.id, d.email, d.first_name, d.last_name
from developers d join skillcodes s
where d.skill_code = d.skill_code|s.code and s.category like 'Front End'
order by id