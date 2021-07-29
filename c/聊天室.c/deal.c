#include "chatroom.h"
char s[200];
void *body(void *arg);
void mysql_in_del(char *buf);
void mysql_select(char *buf, pack *recv_pack, int t);
void mysql_con();
int mysql_closet();
void registered(pack *recv_pack);
void sign(pack *recv_pack);
void find_words(pack *recv_pack);
void send_file();
void my_err(char *err_string, int line)
{
    fprintf(stderr, "line %d  ", line);
    perror(err_string);
    exit(1);
}
void send_t(pack *s, int sock_fd)
{
    if (send(sock_fd, s, sizeof(pack), 0) < 0)
        my_err("send", __LINE__);
}
void recv_t(pack *s, int sock_fd)
{
    if (recv(sock_fd, s, sizeof(pack), 0) < 0)
        my_err("recv", __LINE__);
}
void *body(void *arg)
{
    pack *recv_pack = ((pack *)arg);
    int pid = pthread_self();
    switch (recv_pack->cho)
    {
    case 'a':
        sign(recv_pack); //登陆
        break;
    case 'b':
        registered(recv_pack); //注册
        break;
    case 'c':
        find_words(recv_pack);
        break;
    default:
        pthread_exit(&pid);
        break;
    }
    return NULL;
}
void mysql_in_del(char *buf) //修改数据库
{
    int flag;
    flag = mysql_query(&mysql, buf);
    if (flag)
    {
        printf("ERROR:%s\n", mysql_error(&mysql));
    }
}
void mysql_select(char *buf, pack *recv_pack, int t) //数据库查询
{
    int flag;
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    flag = mysql_query(&mysql, buf);
    if (flag)
    {
        mysql_error(&mysql);
    }
    result = mysql_store_result(&mysql);
    if (result)
    {
        // while ((field = mysql_fetch_field(result)) != 0)   查看表头
        // {
        //     printf("%-15s", field->name);
        // }
        // printf("\n");
        while ((row = mysql_fetch_row(result)) != 0)
        {
            for (unsigned int i = 0; i < mysql_num_fields(result); i++)
            {
                if (row[i])
                {
                    switch (t)
                    {
                    case 0:
                        recv_pack->send_nums = atoi((char *)row[i]);
                        break;
                    case 1:
                    {
                        strcpy(recv_pack->work, (char *)row[i]);  //密码
                        recv_pack->id = atoi((char *)row[i+1]);   //问题号
                        strcpy(recv_pack->nums, (char *)row[i+2]); //回答
                        return;
                    }
                    default:
                        break;
                    }
                }
            }
        }
    }
    mysql_free_result(result);
}
void mysql_con() //数据库初始化,连接
{
    unsigned int nums;
    MYSQL_RES *res = NULL;
    mysql_init(&mysql);
    // mysql_library_init(0, NULL, NULL);
    if (mysql_real_connect(&mysql, "127.0.0.1", "root", passwords, "chat", 0, NULL, 0) == NULL)
    {
        my_err("mysql_real_connect", __LINE__);
    }
    // mysql_set_character_set(&mysql, "utf8");
}
int mysql_closet()
{
    mysql_close(&mysql);
    mysql_library_end();
    printf("数据库关闭\n");
    return 0;
}
void registered(pack *recv_pack) //注册函数
{

    sprintf(s, "insert into user_all (username,password,question,answer)"
               "values(\"%s\",\"%s\",%d,\"%s\")",
            recv_pack->send_name, recv_pack->work, recv_pack->send_id, recv_pack->nums);
    mysql_in_del(s);
    sprintf(s, "select number from user_all where username=\'%s\' ", recv_pack->send_name);
    mysql_select(s, recv_pack, 0);
    printf("%d", recv_pack->send_nums);
    send_t(recv_pack, recv_pack->send_id);
    printf("注册成功\n");
    return;
}
void sign(pack *recv_pack) //登陆函数
{
    sprintf(s, "select * from user_all where number=%d and password=\'%s\'", recv_pack->send_nums, recv_pack->work);
    int flag = mysql_query(&mysql, s);
    if (!flag)
    {
        strncpy(recv_pack->work, "yes", 3);
        send_t(recv_pack, recv_pack->send_id);
        sprintf(s, "update user_all set status=1 where number=%d", recv_pack->send_nums); //将用户状态设置为上线
        printf("%s", s);
        flag = mysql_query(&mysql, s);
        if (flag)
        {
            printf("ERROR:%s\n", mysql_error(&mysql));
            exit(1);
        }
        send_t(recv_pack, recv_pack->send_id);
        printf("a new client sign server,name:%s ip:%s\n", recv_pack->send_nums);
    }
    else
    {
        printf("账号%d用户登陆失败\n", recv_pack->send_nums);
    }
}
void find_words(pack *recv_pack) //找回密码
{
    recv_t(recv_pack, recv_pack->send_id);
    sprintf(s, "select password,qusetion,answer from user_all where number=%d", recv_pack->send_nums);
    mysql_select(s,recv_pack,1);
    send_t(recv_pack,recv_pack->send_id);
}