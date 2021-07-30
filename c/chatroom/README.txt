聊天室项目文档
数据库初始化建表语句
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
    send_name varchar(10) not null,
    id int
);
create table groups(  
    id int not null ,
    nums int not null primary key auto_increment,
    group_name varchar(10),
    name  varchar(10) not null,
    status int(10) not null,
    idchar varchar(10)
);
create table group_histroy(  
     
    send_name varchar(20) not null,
    id int not null ,
    words varchar(40) not null
);
create table friend_histroy(  
    recv_name varchar(10) not null,
    send_name varchar(10) not null,
    status int null,
    words varchar(40) not null
);
create table message(  
    recv_name varchar(10) not null,
    send_name varchar(10) not null,
    id int not null,
    works varchar(100)  
);
create table files(  
    recv_name varchar(10) not null,
    send_name varchar(10) not null,
    file_name varchar(100) not null,
    id int not null
);
