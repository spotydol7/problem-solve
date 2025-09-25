-- 코드를 입력하세요
SELECT a.book_id, b.author_name, date_format(a.published_date, '%Y-%m-%d') as PUBLISHED_DATE
FROM book a
    join author b
    on a.author_id = b.author_id
WHERE a.category = '경제'
ORDER BY a.published_date asc;