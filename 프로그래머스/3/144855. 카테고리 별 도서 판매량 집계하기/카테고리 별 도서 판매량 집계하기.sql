-- 코드를 입력하세요
SELECT CATEGORY,sum(sales) as TOTAL_SALES from book,book_sales where date_format(sales_date,'%Y-%m') = '2022-01' and book.book_id = book_sales.book_id group by category order by category;