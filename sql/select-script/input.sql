use BabyName;

show tables;
describe BabyName;
select distinct year from BabyName where name = 'connor' limit 50;
select distinct name from BabyName where year = "1996" limit 50;
select Max(count), gender, year, name from BabyName where year = "1996" group by gender limit 50;  
select * from BabyName where name="Luke" ORDER BY name,count,year limit 50;
select count(name) from BabyName;
select count(name), year from BabyName where year = "1960" limit 50;
select count(name) as NumOfNames, gender, year from BabyName where year = "1964" group by gender limit 50;
select distinct count(name), place from BabyName group by place limit 50;
