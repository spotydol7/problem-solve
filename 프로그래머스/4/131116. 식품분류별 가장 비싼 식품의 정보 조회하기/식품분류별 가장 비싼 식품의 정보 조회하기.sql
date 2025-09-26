-- 코드를 입력하세요
SELECT category, price as MAX_PRICE, product_name
from food_product
where (category, price) in (
    select category, max(price) 
    from food_product 
    group by category
    having category in ('국', '김치', '식용유', '과자')
)
order by MAX_PRICE desc;