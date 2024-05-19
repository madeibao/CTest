
-- 表：cinema

-- +----------------+----------+
-- | Column Name    | Type     |
-- +----------------+----------+
-- | id             | int      |
-- | movie          | varchar  |
-- | description    | varchar  |
-- | rating         | float    |
+----------------+----------+
-- id 是该表的主键(具有唯一值的列)。
-- 每行包含有关电影名称、类型和评级的信息。
-- 评级为 [0,10] 范围内的小数点后 2 位浮点数。
 

-- 编写解决方案，找出所有影片描述为 非 boring (不无聊) 的并且 id 为奇数 的影片。
-- 返回结果按 rating 降序排列。
-- 结果格式如下示例。


select id, movie, description, rating
from cinema
where description <> 'boring' and id & 1
order by rating desc;



----------------------------------------------------------------------------------------------------------------------

select *
from cinema
where description not in('boring')
group by id having id%2 = 1
order by rating DESC;



----------------------------------------------------------------------------------------------------------

select id, movie, description, rating
from cinema
where description <> 'boring' and mod(id, 2)=1
order by rating desc;
