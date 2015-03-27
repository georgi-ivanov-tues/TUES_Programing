create table migration_1 (
	id INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
	user_name varchar(255),
	password varchar(255),
	ip_v4_address varchar(255)
);
	 
create table migration_2 (
	id INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY ,
	slug varchar(255),
	url varchar(255),
	domain_word varchar(255)
);

insert into migration_1(id, user_name, password, ip_v4_address) select id, user_name, password, ip_v4_address from fadelabbott;
insert into migration_2(id, slug, url, domain_word) select id, slug, url, domain_word from fadelabbott;
