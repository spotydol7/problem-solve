select f.ID, n.FISH_NAME, f.LENGTH
from fish_info f
join fish_name_info n
on f.fish_type = n.fish_type
where f.fish_type in
(
    select fish_type
    from fish_info
    group by fish_type
    having length = max(length)
)
order by id
