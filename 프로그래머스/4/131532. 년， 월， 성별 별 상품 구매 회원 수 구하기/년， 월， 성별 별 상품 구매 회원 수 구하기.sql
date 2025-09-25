-- 코드를 입력하세요
SELECT year(o.sales_date) as YEAR, month(o.sales_date) as MONTH, u.gender as GENDER, count(distinct u.user_id) as USERS
from online_sale o
inner join user_info u
on o.user_id = u.user_id
where u.gender is not null
group by YEAR, MONTH, GENDER
order by YEAR, MONTH, GENDER