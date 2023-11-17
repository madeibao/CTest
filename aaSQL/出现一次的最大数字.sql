


select max(num) as num
	from MyNumbers
		where num not in(select num from MyNumbers group by num
		having count(num) > 1)



-- 出现一次的最大数字 -- 
select 
    max(s.num) as num
from
    (select 
        num
    from
        MyNumbers
    group by 
        num 
    having 
        count(num)=1) As s  