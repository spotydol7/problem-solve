-- 코드를 입력하세요
SELECT 
date_format(s.sales_date, '%Y') as YEAR, 
date_format(s.sales_date, '%m') as MONTH,
count(distinct(u.user_id)) as PURCHASED_USERS, 
round(count(distinct u.user_id) / (select count(*) from user_info where joined like '2021%'), 1) as PURCHASED_RATIO
from user_info u
join online_sale s
on u.user_id = s.user_id
where u.joined like '2021%'
group by YEAR, MONTH
order by YEAR, MONTH