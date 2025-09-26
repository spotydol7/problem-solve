select e.dept_id, d.dept_name_en, round(avg(e.sal)) as AVG_SAL
from hr_employees e
join hr_department d on e.dept_id = d.dept_id
group by dept_id
order by AVG_SAL desc