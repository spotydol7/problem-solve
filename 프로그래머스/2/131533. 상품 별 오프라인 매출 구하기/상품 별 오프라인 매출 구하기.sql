-- 코드를 입력하세요
SELECT p.product_code, sum(s.sales_amount) * p.price as SALES
from product p
inner join offline_sale s
on s.product_id = p.product_id
group by p.product_code
order by SALES desc, product_code asc;