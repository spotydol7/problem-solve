-- 코드를 입력하세요
SELECT month(c.start_date) as MONTH, c.CAR_ID, count(c.history_id) as RECORDS 
from CAR_RENTAL_COMPANY_RENTAL_HISTORY c
where c.start_date >= '2022-08-01' and c.start_date < '2022-11-01'
and CAR_ID in (select CAR_ID from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
               where start_date >= '2022-08-01' and start_date < '2022-11-01'
               group by CAR_ID
               having count(history_id) > 4)
group by MONTH, CAR_ID
having RECORDS > 0
ORDER BY MONTH asc, CAR_ID desc