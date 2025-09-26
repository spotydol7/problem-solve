-- 코드를 입력하세요
SELECT b.title, b.board_id, r.reply_id, r.writer_id, r.contents, date_format(r.created_date, '%Y-%m-%d') as CREATED_DATE
from used_goods_board b
inner join used_goods_reply r on b.board_id = r.board_id
where b.CREATED_DATE like '2022-10-%'
order by CREATED_DATE ASC, title asc