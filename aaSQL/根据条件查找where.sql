

drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');




-- 查询所有的列
select * from user_profile;


-- 查询多个列
SELECT  device_id,gender,age,university
from user_profile

-- 查询结果去重

两个解法：
1. 使用DISTINCT：SELECT DISTINCT university from user_profile;
2. 使用group by：SELECT university from user_profile GROUP BY universit


-- 查询结果限制返回行数
select 
    device_id
from 
    user_profile
limit 
    0,2

-- 查询结果重新命名

SELECT device_id as user_infors_example
FROM user_profile
LIMIT 2

-- 查找后来进行排序
SELECT device_id, age FROM user_profile  ORDER by age ASC 

升序排序asc可以省略，降序排列不能省略；

升序：select device_id,age from user_profile order by age;
降序：select device_id,age from user_profile order by age desc;

ASC  升序方式
SELECT device_id, age FROM user_profile  ORDER by age ASC 

-- 根据多个列来进行排序

SELECT device_id, gpa, age 
FROM user_profile 
ORDER BY gpa, age;


SELECT device_id, gpa, age
FROM user_profile
ORDER by gpa DESC, age DESC;


-- 根据条件查询
select device_id,university
from user_profile
where university = "北京大学"

--------------------------------------------------
select device_id,gender,age,university
from user_profile
where age > 24



-- 查询某一个年龄段信息

SELECT device_id,gender,age FROM user_profile WHERE age IN (20,21,22,23)


select device_id,gender,age
from user_profile
where age >=20 and age<=23


-- 查找不是复旦大学的学生的信息

select device_id,gender,age,university
from user_profile
#where university <> '复旦大学';
#where university != '复旦大学';
where university not in ('复旦大学');


-- where 过滤空值

过滤空值的三种方法：
(1) Where 列名 is not null
(2) Where 列名 != 'null'
(3) Where 列名 <> 'null'


-- 题目：现在运营想要找到男性且GPA在3.5以上(不包括3.5)的用户进行调研，请你取出相关数据。
-- 示例：user_profile

select device_id,gender,age,university,gpa 
from user_profile 
where gender = "male" and gpa > 3.5


select device_id,gender,age,university,gpa 
from user_profile 
where university = "北京大学" or gpa > 3.7


-- 题目：现在运营想要找到学校为北大、复旦和山大的同学进行调研，请你取出相关数据

select device_id,gender,age,university,gpa
from user_profile
WHERE university="北京大学" or university="复旦大学" or university="山东大学"


SELECT device_id,gender,age,university,gpa
FROM user_profile
WHERE university IN ("北京大学","复旦大学","山东大学")

-- 题目：现在运营想要找到gpa在3.5以上(不包括3.5)的山东大学用户 或 
-- gpa在3.8以上(不包括3.8)的复旦大学同学进行用户调研，请你取出相应数据

SELECT 
    device_id, gender, age, university,gpa 
from 
    user_profile 
where 
    (gpa > 3.8 and university = '复旦大学') or (gpa > 3.5 and university = '山东大学')



-- 题目：现在运营想查看所有大学中带有北京的用户的信息，请你取出相应数据。

SELECT device_id, age, university
FROM user_profile
WHERE university REGEXP "北京"


-- 查找GPA最高值
select gpa
from user_profile
where university = '复旦大学'
order by gpa DESC
limit 1


-- SQL17 计算男生人数以及平均GPA

select count(gender),round(avg(gpa),1) 
from user_profile
where gender='male'
group by gender



-- 题目：现在运营想要对每个学校不同性别的用户活跃情况和发帖数量进行分析，
-- 请分别计算出每个学校每种性别的用户数、30天内平均活跃天数和平均发帖数量。


-- 用户信息表：user_profile
-- 30天内活跃天数字段（active_days_within_30）
-- 发帖数量字段（question_cnt）
-- 回答数量字段（answer_cnt）


SELECT
    gender,
    university,
    COUNT(gender) user_num,
    AVG(active_days_within_30) avg_active_days,
    AVG(question_cnt) avg_question_cnt
FROM
    user_profile
GROUP BY
    university,
    gender


-- 题目：现在运营想查看每个学校用户的平均发贴和回帖情况，
-- 寻找低活跃度学校进行重点运营，请取出平均发贴数低于5的学校或平均回帖数小于20的学校。

SELECT
    university,
    avg(question_cnt) as avg_question_cnt,
    avg(answer_cnt) as avg_answer_cnt
from
    user_profile
group by
    university
having
    avg(question_cnt) < 5
    or avg(answer_cnt) < 20


-- # 聚合函数结果作为筛选条件时，不能用where，而是用having语法


-- 涉及到聚合函数，首先考虑分组

select 
    university,avg(question_cnt) avg_question_cnt
from 
    user_profile
group by 
    university
order by 
    avg_question_cnt




题目：现在运营想要查看所有来自浙江大学的用户题目回答明细情况，请你取出相应数据

示例 ：question_practice_detail

SELECT
    u.device_id,
    q.question_id,
    q.result
from
    question_practice_detail q,
    user_profile u
where
    university = '浙江大学'
    and q.device_id = u.device_id
