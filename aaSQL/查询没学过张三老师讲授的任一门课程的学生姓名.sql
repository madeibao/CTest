SELECT
	sname 
FROM
	t_mysql_student 
WHERE
	sid NOT IN (
SELECT
	sc.sid 
FROM
	t_mysql_score sc,
	t_mysql_course c,
	t_mysql_teacher t 
WHERE
	t.tid = c.tid 
	AND sc.cid = c.cid 
	AND t.tname = "张三" 
	)
 



