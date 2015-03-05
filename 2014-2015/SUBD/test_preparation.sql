create table Article_18( 	
	content long string,
	name varchar(30),
	published_on timestamp
);

create table Category(
	date_created_on timestamp,
	priority double
);

create table User(
	income float,
	picture_url string,
	created_on timestamp
);

create table Tag(
	name varchar(30),
	priority int
);

inserts.sql
insert into Article_18(content, name, published_on) values ('ASD', 'asd', 01/01/2014), ('QWE', 'qwe', 01/01/2014);
insert into Category(date_created_on, priority) values (01/01/2014, 1), (01/01/2014, 2);
insert into User(income, picture_url, created_on) values(123, 'www.com', 01/01/2014), (312, 'org.bg', 02/02/2013');
insert into Tag(name, int) values('pesho', 1), ('gosho'. 2);

selects1.sql
SELECT * FROM User;
