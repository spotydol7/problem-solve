-- 코드를 입력하세요
SELECT f.FLAVOR
from first_half f
join (select flavor, sum(total_order) as 'TOTAL_ORDER'
           from july
           group by flavor) j
on f.flavor = j.flavor
order by f.TOTAL_ORDER + j.TOTAL_ORDER desc
limit 3;