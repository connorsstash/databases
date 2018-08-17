/*
Connor Pekovic
Databases 466 Section 2
Assignment 7 -  SQL DDL - creating a database.
Due Date: 3/28/2018
*/

/* 1. Deleting all the tables we're going to be making
        before hand. */
drop table if exists pets;
drop table if exists owner;

/* 2. Making an owner table with the data types.*/
create table owner 
	(ownerID int auto_increment primary key,
     firstName char(25),
     lastName char(25));

/* 3. Putting 5 records in owner. */
insert into owner values (100, 'Jonny','Mack');
insert into owner values (101, 'Tlyer','Seafeild');
insert into owner values (102, 'Tiffany','Graham');
insert into owner values (103, 'Jonny','Majcher');
insert into owner values (104, 'Nick','Pekovic');

/* 4. Selecting all the records from owner.*/
select * from owner;

/* 5.  Making a pets table with the date types.*/
create table pets
    (petID int auto_increment primary key,
    petName char(25),
    petDOB date,
    OwnerID int(25),
    foreign key (OwnerID) references owner(ownerID)on delete cascade);
    
/* 6.  Putting 5 records into pets.*/
insert into pets (petID, petName, petDOB, ownerID) values(1, 'Jonnny','2003-05-12', 101);
insert into pets (petID, petName, petDOB, ownerID) values(2, 'Buster','2009-06-12', 101);
insert into pets (petID, petName, petDOB, ownerID) values(3, 'Roufus','2017-02-04', 102);
insert into pets (petID, petName, petDOB, ownerID) values(4, 'Clifard','1990-01-01', 104);
insert into pets (petID, petName, petDOB, ownerID) values(5, 'Tigger','200002-02', 103);

/* 7. Selecting all the records from pets.*/
select * from pets;

/* 8. Add a column to the pets table called 'type_of_pet'.*/
alter table pets add type_of_pet char(10);

/* 9. Updating rows to add pet type.*/
update pets set type_of_pet = 'cat' where ownerID = 101;
update pets set type_of_pet = 'dog' where ownerID = 102;
update pets set type_of_pet = 'lizard' where ownerID = 103;
update pets set type_of_pet = 'tiger' where ownerID = 104;

/* 10. I changed the pets petDOB to the date data type.*/

/* 11. Selecting all the records from pets.*/
select * from pets;

/* 12. Define a view with 3 columns.  Owner first and last name, then pet name.*/
create view Owner_Relationships
as select owner.firstName as 'Owners First Name', owner.lastName as 'Owners Last Name', pets.petName as Pet from owner, pets where pets.ownerID = owner.ownerID;

/* 13. Do a select * on the view just created above.*/
select * from Owner_Relationships;