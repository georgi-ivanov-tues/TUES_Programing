scp student@172.16.16.132:/home/student/calendar.sql calendar.sql

http://dev.mysql.com/downloads/workbench/

SELECT * FROM users LEFT JOIN groups_users on groups_users.user_id = users.id LEFT JOIN groups on  groups_users.group_id = groups.id;

/*Vsichki user-i koito nqmat grupi*/
SELECT users.name, groups.name 
FROM users 
LEFT JOIN groups_users on groups_users.user_id = users.id 
LEFT JOIN groups on groups_users.group_id = groups.id 
WHERE groups.name is null;

/*Grupite koito nqmat eventi*/
SELECT groups.name 
FROM groups 
LEFT JOIN events on events.group_id = groups.id 
WHERE events.title is null;

/*Vsichki unikalni sabitiq za dadena grupa*/
SELECT distinct events.title 
FROM events
LEFT JOIN groups on events.group_id = groups.id
WHERE groups.name = 'ПМ 2 Група';

exit
mysqldump -uroot -p calender > output.sql
