//数据库初始化建表语句
create database chat;
use chat;
create table user_all(   
    username varchar(10) not null,
    number  int unsigned not null primary key auto_increment,
    password varchar(20) not null,
    question int,
    answer varchar(10)
); 
create table friend(   
    recv_name varchar(10) not null,
    send_name varchar(10) not null
);
create table groups(  
    id int not null auto_increment primary key,
    group_name varchar(20) not null,
    status int(10) not null
);
create table group_histroy(  
    group_name varchar(20) not null,
    send_name varchar(20) not null,
    words varchar(40) not null
);
create table friend_histroy(  
    recv_name varchar(10) not null,
    send_name varchar(10) not null,
    words varchar(40) not null
);
create table message(  
    recv_name varchar(10) not null,
    send_name varchar(10) not null,
    id int not null,
    works varchar(40)  
);