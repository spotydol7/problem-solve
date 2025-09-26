with recursive temp as (
    select 0 as HOUR
    union all
    select HOUR + 1 from temp where HOUR < 23
)

select temp.hour, count(o.animal_id) as COUNT
from temp
left join animal_outs o
on temp.HOUR = HOUR(o.datetime)
group by temp.HOUR
order by temp.HOUR