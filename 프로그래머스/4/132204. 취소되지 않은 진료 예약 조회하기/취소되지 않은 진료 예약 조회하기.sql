-- 코드를 입력하세요
SELECT a.apnt_no, p.pt_name, a.pt_no, a.mcdp_cd, d.dr_name, a.apnt_ymd
from appointment a
join patient p on a.pt_no = p.pt_no
join doctor d on a.mddr_id = d.dr_id
where a.apnt_cncl_ymd is null
and d.mcdp_cd = 'CS'
and year(a.apnt_ymd) = 2022 
and month(a.apnt_ymd) = 4
and day(a.apnt_ymd) = 13
order by a.apnt_ymd asc
