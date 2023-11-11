


SELECT
	s.sid,
	s.sname,
	avg( c.score ) 
FROM
	t_mysql_student s,
	t_mysql_score c 
WHERE
	s.sid = c.sid 
GROUP BY
	s.sid,
	s.sname 
HAVING
	avg( c.score ) >= 60
