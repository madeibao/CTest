


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