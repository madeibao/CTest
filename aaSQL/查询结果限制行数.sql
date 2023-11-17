

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




select device_id from user_profile limit 2;
select device_id from user_profile limit 0,2;
select device_id from user_profile limit 2 offset 0;
select device_id from user_profile where id in(1,2);
select device_id from user_profile where id <=2;
select device_id from user_profile where id=1 or id=2;