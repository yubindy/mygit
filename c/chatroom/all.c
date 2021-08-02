#include "chatroom.h"
MYSQL mysql;
pthnode *pthead;
int mes = 0;
int ep_fd;
int grchat = 1;
node *head = NULL;
node *end = NULL;
groupnode *grohead = NULL;
infonode *ifhead = NULL;
pthread_mutex_t fchat = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t chatgroup = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t group = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mysqs = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lockwords = PTHREAD_MUTEX_INITIALIZER;
void panduan_message(pack *recv_pack);
void *body(void *arg);
void mysql_in_del(char *buf);
int mysql_select(char *buf, pack *recv_pack, int t);
void mysql_select_words(char *buf, pack *recv_pack, int t);
void mysql_con();
int mysql_closet();
void registered(pack *recv_pack);
void sign(pack *recv_pack);
void find_words(pack *recv_pack);
void send_file();
int find_status(char *name,int nums,int fds);
void add_friend(pack *recv_pack);
void del_friend(pack *recv_pack);
void select_friend(pack *recv_pack);
void chat_friend(pack *recv_pack);
void message(pack *recv_pack);
void fri_histroy(pack *recv_pack);
void create_group(pack *recv_pack);
void del_group(pack *recv_pack);
void allgroup(pack *recv_pack);
void groupmember(pack *recv_pack);
void cleargroup(pack *recv_pack);
void setgroup(pack *recv_pack);
void joingroup(pack *recv_pack);
infonode *find_info(char *s);
void group_chat(pack *recv_pack);
void group_histroy(pack *recv_pack);
void send_file(pack *recv_pack);
void recv_file(pack *recv_pack);
void delmumber(pack *recv_pack);
void blackmumber(pack *recv_pack)
{
    char s[200];
    int t = 0;
    sprintf(s, "select * from friend where recv_name=\'%s\'and send_name=\'%s\'union "
               "select * from friend where recv_name=\'%s\'and send_name=\'%s\'",
            recv_pack->recv_name, recv_pack->send_name, recv_pack->send_name, recv_pack->recv_name);
    if (t == mysql_select(s, recv_pack, 3)) //如果没有加好友
    {
        strcpy(recv_pack->work, "对不起，你暂时没有该好友");
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    sprintf(s, "update friend set id=1 where recv_name=\'%s\'and send_name=\'%s\'",
            recv_pack->recv_name, recv_pack->send_name);
    mysql_in_del(s);
    sprintf(s, "update friend set id=1 where recv_name=\'%s\'and send_name=\'%s\'",
            recv_pack->send_name, recv_pack->recv_name);
    mysql_in_del(s);
    strcpy(recv_pack->work, "设置成功，已经屏蔽该用户消息");
    send_t(recv_pack, recv_pack->send_id);
}
void delmumber(pack *recv_pack)
{
    char s[200];
    int t = 0;
    sprintf(s, "select * from groups where id=%d and name=\'%s\' and id>0",
            recv_pack->id, recv_pack->send_name);
    t = mysql_select(s, recv_pack, 3);
    if (t == 0)
    {
        strncpy(recv_pack->work, "你没有该群的管理人员权限", sizeof(recv_pack->work));
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    sprintf(s, "delete from groups where name=\'%s\' and id=%d", recv_pack->recv_name, recv_pack->id);
    mysql_in_del(s);
    sprintf(recv_pack->work, "已经将你从群聊%d中移除", recv_pack->id);
    sprintf(s, "insert into message(recv_name,send_name,id,works)values(\'%s\',\'%s\',%d,\'%s\')",
            recv_pack->recv_name, recv_pack->send_name, 8, recv_pack->work);
    mysql_in_del(s);
    sprintf(recv_pack->work, "已经将\'%s\'从群聊%d中移除", recv_pack->recv_name, recv_pack->id);
    send_t(recv_pack, recv_pack->send_id);
}
void send_file(pack *recv_pack)
{
    char files[100], rands[20];
    char s[200];
    char sizefile[1024];
    int fd, filesize, nfs, number = 0;
    struct epoll_event ep_id;
    int recvsize = 1023;
    filesize = recv_pack->id;
    nfs = filesize / 1023 + 1;
    getcwd(files, sizeof(files));
    memset(rands, 0, sizeof(rands));
    rand_file(rands);
    files[strlen(files)] = '/';
    strncat(files, rands, sizeof(rands));
    sprintf(s, "insert into message(recv_name,send_name,id,works)values(\'%s\',\'%s\',%d,\'%s\')",
            recv_pack->recv_name, recv_pack->send_name, 10, files);
    mysql_in_del(s);
    sprintf(s, "insert into files(recv_name,send_name,file_name,id)values(\'%s\',\'%s\',\'%s\',1)",
            recv_pack->recv_name, recv_pack->send_name, files);
    mysql_in_del(s);
    while (nfs--)
    {
        if (filesize < 1023)
            recvsize = filesize;
        filesize -= 1023;
        recv(recv_pack->send_id, sizefile, recvsize, 0);
        fd = open(files, O_WRONLY | O_CREAT | O_APPEND, 0644);
        write(fd, sizefile, recvsize);
    }
    close(fd);
    ep_id.data.fd = recv_pack->send_id;
    ep_id.events = EPOLLIN;
    epoll_ctl(ep_fd, EPOLL_CTL_ADD, recv_pack->send_id, &ep_id); //将该文件描述符添加到epoll
    strcpy(recv_pack->work, "已经成功发送");
    send_t(recv_pack, recv_pack->send_id);
}
void group_histroy(pack *recv_pack)
{
    char s[200];
    int t;
    pthnode *pt = pthead->next;
    sprintf(s, "select * from groups where name=\'%s\' and idchar=\'%d\'", recv_pack->send_name, recv_pack->id);
    if (mysql_select(s, recv_pack, 3) == 0)
    {
        strcpy(recv_pack->work, "你没有加入到该群聊");
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    sprintf(s, "select * from group_histroy where id=%d", recv_pack->id);
    t = mysql_select(s, recv_pack, 4);
    recv_pack->status = t;
    sprintf(recv_pack->work, "该群一共有%d条消息记录", t);
    send_t(recv_pack, recv_pack->send_id);
    sprintf(s, "select send_name,words from group_histroy where id=%d", recv_pack->id);
    pthread_mutex_lock(&lockwords);
    mysql_select_words(s, recv_pack, 3);
    for (int i = 0; i < t; i++)
    {
        send(recv_pack->send_id, pt, sizeof(pthnode), 0);
        pt = pt->next;
    }
    pthread_mutex_unlock(&lockwords);
}
void group_chat(pack *recv_pack) //群聊
{
    grchat = 1;
    char s[200];
    pthnode *information = (pthnode *)malloc(sizeof(pthnode));
    sprintf(s, "select * from groups where id=%d and name=\'%s\'",
            recv_pack->send_nums, recv_pack->send_name);
    if (recv_pack->id == 1)
    {
        if (mysql_select(s, recv_pack, 3) == 0)
        {
            strcpy(recv_pack->work, "对不起，你没有加入群聊\n");
            send_t(recv_pack, recv_pack->send_id);
            grchat = 0;
            return;
        }
        send_t(recv_pack, recv_pack->send_id);
    }
    node *t = head, *p;
    pthread_mutex_lock(&lock);
    while (t != NULL)
    {
        if (strcmp(t->t, recv_pack->send_name) == 0)
        {
            t->groupid = recv_pack->send_nums;
        }
        if (t->next == NULL)
            break;
        t = t->next;
    }
    t = head->next;
    pthread_mutex_unlock(&lock);
    if (strcmp(recv_pack->work, "~exit") == 0)
    {
        grchat = 0;
        return;
    }
    sprintf(s, "insert into group_histroy (send_name,id,words) values(\'%s\',%d,\'%s\')",
            recv_pack->send_name, recv_pack->send_nums, recv_pack->work);
    mysql_in_del(s);
    sprintf(s, "insert into message (recv_name,send_name,id,works) values(%d,\'%s\',%d,\'%s\')",
            recv_pack->send_nums, recv_pack->send_name, recv_pack->send_nums, recv_pack->work);
    mysql_in_del(s);
    pthread_mutex_lock(&chatgroup);
    while (t != NULL)
    {
        if (t->groupid == recv_pack->send_nums && strcmp(t->t, recv_pack->send_name) != 0)
        {
            send_t(recv_pack, t->id);
        }
        if (t->next == NULL)
            break;
        t = t->next;
    }
    pthread_mutex_unlock(&chatgroup);
    return;
}
void joingroup(pack *recv_pack) //加入群
{
    char s[200];
    sprintf(s, "select * from groups where id=%d and name=\'%s\'",
            recv_pack->send_nums, recv_pack->send_name);
    if (mysql_select(s, recv_pack, 3) == 1)
    {
        strcpy(recv_pack->work, "对不起，你已经加入群聊，不可重复加入");
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
sprintf(s, "insert into message(recv_name,send_name,id,works)values(\'%d\',\'%s\',3,\'%d\')",
        recv_pack->id, recv_pack->send_name, recv_pack->id);
mysql_in_del(s);
strcpy(recv_pack->work, "加入申请已发送");
send_t(recv_pack, recv_pack->send_id);
}
void cleargroup(pack *recv_pack) //解散群
{
    char s[200];
    groupnode *p = grohead->next;
    int t;
    sprintf(s, "select * from groups where status=2 and id=%d and name=\'%s\'",
            recv_pack->id, recv_pack->send_name);
    t = mysql_select(s, recv_pack, 3);
    if (t == 0)
    {
        strcpy(recv_pack->work, "你还不是该群的群主，没有权利解散群聊");
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    else
    {
        sprintf(s, "select name from groups where id=%d", recv_pack->id);
        pthread_mutex_lock(&group);
        mysql_select_words(s, recv_pack, 5);
        for (int i = 0; i < t; i++)
        {
            sprintf(s, "insert into message(recv_name,send_name,id)" //将群解散消息逐一发送用户
                       "values(\'%s\',\'%s\',9,\'已经解散群%d\')",
                    p->name, recv_pack->send_name, recv_pack->id);
            mysql_in_del(s);
            p = p->next;
        }
        pthread_mutex_unlock(&group);
        sprintf(s, "delete from groups where id=%d", recv_pack->id);
        mysql_in_del(s);
        strcpy(recv_pack->work, "解散群聊成功");
        send_t(recv_pack, recv_pack->send_id);
    }
}
void setgroup(pack *recv_pack) //设置群管理员
{
    char s[200];
    char bus[40];
    int t = 0;
    sprintf(s, "select * from groups where id=%d and name=\'%s\'",
            recv_pack->id, recv_pack->recv_name);
    t = mysql_select(s, recv_pack, 3);
    if (t == 0)
    {
        strcpy(recv_pack->work, "对不起，没有在该群中找到此人");
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    sprintf(s, "select * from groups where id=%d and name=\'%s\' and status>0",
            recv_pack->id, recv_pack->send_name);
    t = mysql_select(s, recv_pack, 3);
    if (t == 0)
    {
        strcpy(recv_pack->work, "对不起，你暂时不是该群的管理员");
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    sprintf(s, "update groups set status=1 where id=%d and name=\'%s\'",
            recv_pack->id, recv_pack->recv_name);
    mysql_in_del(s);
    strcpy(recv_pack->work, "已经设置管理员成功");
    send_t(recv_pack, recv_pack->send_id);
    sprintf(s, "insert into message(recv_name,send_name,id,works)"
               "values(\'%s\',\'%s\',8,\'成功把你设置为群号%d的管理员\')",
            recv_pack->recv_name, recv_pack->send_name, recv_pack->id);
    mysql_in_del(s);
}
void groupmember(pack *recv_pack) //查看群中所有群成员
{
    char s[200];
    int t;
    int id;
    groupnode *p = grohead->next;
    sprintf(s, "select * from groups where id=%d", recv_pack->id);
    id = recv_pack->id;
    recv_pack->id = mysql_select(s, recv_pack, 4);
    t = recv_pack->id;
    send_t(recv_pack, recv_pack->send_id);
    sprintf(s, "select name,status from groups where id=%d", id);
    pthread_mutex_lock(&group);
    mysql_select_words(s, recv_pack, 6);
    for (int i = 0; i < t; i++)
    {
        if (send(recv_pack->send_id, p, sizeof(groupnode), 0) < 0)
        {
            my_err("send", __LINE__);
        }
        p = p->next;
    }
    pthread_mutex_unlock(&group);
}
void allgroup(pack *recv_pack) //查看所有群
{
    char s[200];
    int t;
    groupnode *p = grohead->next;
    sprintf(s, "select * from groups where name=\'%s\'", recv_pack->send_name);
    recv_pack->id = mysql_select(s, recv_pack, 4);
    t = recv_pack->id;
    send_t(recv_pack, recv_pack->send_id);
    sprintf(s, "select id from groups where name=\'%s\'", recv_pack->send_name);
    pthread_mutex_lock(&group);
    mysql_select_words(s, recv_pack, 4);
    for (int i = 0; i < t; i++)
    {
        if (send(recv_pack->send_id, p, sizeof(groupnode), 0) < 0)
        {
            my_err("send", __LINE__);
        }
        p = p->next;
    }
    pthread_mutex_unlock(&group);
}
void create_group(pack *recv_pack) //创建群
{
    char s[200];
    sprintf(s, "insert into groups(id,group_name,name,status)values(1,\'%s\',\'%s\',2)",
            recv_pack->recv_name, recv_pack->send_name);
    mysql_in_del(s);
    sprintf(s, "select nums from groups where group_name=\'%s\'", recv_pack->recv_name);
    mysql_select(s, recv_pack, 0);
    sprintf(s, "update groups set id=%d,idchar=%d where nums=%d", recv_pack->send_nums, recv_pack->send_nums, recv_pack->send_nums);
    mysql_in_del(s);
    strcpy(recv_pack->work, "创建群成功");
    send_t(recv_pack, recv_pack->send_id);
}
void del_group(pack *recv_pack) //退出群
{
    char s[200];
    sprintf(s, "select * from groups where id=%d", recv_pack->id);
    if (mysql_select(s, recv_pack, 3) == 0)
    {
        strcpy(recv_pack->work, "你的群聊中不存在该群");
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    sprintf(s, "delete from groups where id=%d and name=\'%s\'",
            recv_pack->id, recv_pack->send_name);
    mysql_in_del(s);
    strcpy(recv_pack->work, "成功退出该群");
    send_t(recv_pack, recv_pack->send_id);
}
infonode *find_info(char *s)
{
    infonode *t = ifhead;
    while (t->next != NULL)
    {
        if (strcmp(s, t->name) == 0)
            return t;
        t = t->next;
    }
    if (strcmp(s, t->name) == 0)
        return t;
    return NULL;
}
void panduan_message(pack *recv_pack) //判断该对应用户，是否有消息
{
    char s[200];
    sprintf(s, "select send_name,id,works from message where recv_name=\'%s\'and id>0"
               " union  select a.send_name,a.works,a.id from message a,groups b where"
               " a.works=b.idchar and a.id=3 and b.status>0 and b.name=\'%s\'",
            recv_pack->send_name, recv_pack->send_name);
    recv_pack->status = mysql_select(s, recv_pack, 3);
    send_t(recv_pack, recv_pack->send_id);
    return;
}
int find_status(char *name,int nums,int fds) //查找用户在线否
{
    node *cname = head;
    if(nums==0)
    {
    while (cname != NULL)
    {
        if (strcmp(cname->t, name) == 0)
        {
            return 1;
        }
        if (cname == NULL)
            return 0;
        cname = cname->next;
    }
    return 0;
    }
    else
    {
        while (cname != NULL)
    {
        if (fds==cname->id)
        {
            return 1;
        }
        if (cname == NULL)
            return 0;
        cname = cname->next;
    }
    return 0;
    }
    return 0;
}
void chat_friend(pack *recv_pack) //私聊
{
    char s[200];
    int t = 0;
    int findr = 0;
    infonode *recv, *send;
    recv;
    send;
    recv = find_info(recv_pack->send_name);
    while (1)
    {
        sprintf(s, "select send_name,words from friend_histroy where recv_name=\'%s\'and status=1", recv_pack->send_name);
        findr = mysql_select(s, recv_pack, 5);
        if (findr > 0) //如果有，读出来
        {
            send_t(recv_pack, recv_pack->send_id);
            pthread_mutex_lock(&fchat);
            recv->send_id--;
            pthread_mutex_unlock(&fchat);
            sprintf(s, "update friend_histroy set status=0 where recv_name=\'%s\' and words=\'%s\'", recv_pack->send_name, recv_pack->work);
            mysql_in_del(s);
            if (strcmp(recv_pack->work, "~exit") == 0)
            {
                sprintf(s, "update message set id=0 where recv_name=\'%s\'and send_name=\'%s\'",
                        recv_pack->recv_name, recv_pack->send_name);
                mysql_in_del(s);
                sprintf(s, "update message set id=0 where send_name=\'%s\'and recv_name=\'%s\'",
                        recv_pack->recv_name, recv_pack->send_name);
                mysql_in_del(s);
                return;
            }
        }
        else //如果无，写进去
        {
            sprintf(s, "select id from friend where recv_name=\'%s\'and send_name=\'%s\'union "
                       "select id from friend where recv_name=\'%s\'and send_name=\'%s\'",
                    recv_pack->recv_name, recv_pack->send_name, recv_pack->send_name, recv_pack->recv_name);
            if (t == mysql_select(s, recv_pack, 7)) //如果没有加好友
            {
                strcpy(recv_pack->work, "对不起，你暂时没有该好友");
                send_t(recv_pack, recv_pack->send_id);
                return;
            }
            if (recv_pack->id == 1)
            {
                strcpy(recv_pack->work, "对不起，对方已经将你屏蔽不会收到消息");
                send_t(recv_pack, recv_pack->send_id);
                return;
            }
            sprintf(s, "insert into friend_histroy (recv_name,send_name,status,words)" //加入好友历史
                       "values(\'%s\',\'%s\',1,\'%s\')",
                    recv_pack->recv_name, recv_pack->send_name, recv_pack->work);
            mysql_in_del(s);
            if (t == find_status(recv_pack->recv_name,recv_pack->nums,0)) //如果对方不在线,加入消息表
            {
                sprintf(s, "insert into message(recv_name,send_name,id,works)" //id=7，好友未读消息
                           "values(\'%s\',\'%s\',7,\'%s\')",
                        recv_pack->recv_name, recv_pack->send_name, recv_pack->work);
                mysql_in_del(s);
                strcpy(recv_pack->work, "对不起，该好友没有上线\n");
                send_t(recv_pack, recv_pack->send_id);
            }
            else
            {
                sprintf(s, "insert into message(recv_name,send_name,id,works)" //id=6
                           "values(\'%s\',\'%s\',6,\'%s\')",
                        recv_pack->recv_name, recv_pack->send_name, recv_pack->work);
                mysql_in_del(s);
                send = find_info(recv_pack->recv_name);
                pthread_mutex_lock(&fchat);
                send->send_id++;
                pthread_mutex_unlock(&fchat);
                if (strcmp(recv_pack->work, "~exit") == 0)
                {
                    sprintf(s, "update message set id=0 where recv_name=\'%s\'and send_name=\'%s\'",
                            recv_pack->recv_name, recv_pack->send_name);
                    mysql_in_del(s);
                    sprintf(s, "update message set id=0 where send_name=\'%s\'and recv_name=\'%s\'",
                            recv_pack->recv_name, recv_pack->send_name);
                    mysql_in_del(s);
                    return;
                }
            }
        }
        while (1)
        {
            if (recv->send_id > 0)
                break;
            sleep(1);
        }
    }
}
void mysql_select_words(char *buf, pack *recv_pack, int t) //查询多条信息,写入链表
{
    int flag;
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    pthnode *s = pthead->next;
    pthread_mutex_lock(&mysqs);
    flag = mysql_query(&mysql, buf);
    if (flag)
    {
        mysql_error(&mysql);
    }
    result = mysql_store_result(&mysql);
    pthread_mutex_unlock(&mysqs);
    // printf("buf:%s\n", buf);
    if (result)
    {
        int number = mysql_num_rows(result);
        // printf("number:%d\n", number);
        // printf("cont:%d\n", mysql_field_count(&mysql));
        if (t == 0)
        {
            while ((row = mysql_fetch_row(result)) != 0)
            {
                printf("here1 :%lld\n", pthread_self());
                for (unsigned int i = 0; i < mysql_num_fields(result); i++)
                {
                    if (row[i])
                    {
                        if (strcmp((char *)row[i], recv_pack->send_name) != 0)
                        {
                            strcpy(s->work, (void *)row[i]);
                            s->status = find_status(s->work,0,0);
                            s = s->next;
                        }
                    }
                }
            }
            sprintf(recv_pack->work, "%d", number);
        }
        else if (t == 1)
        {
            while ((row = mysql_fetch_row(result)) != 0)
            {
                for (unsigned int i = 0; i < mysql_num_fields(result); i++)
                {
                    if (row[i])
                    {
                        strcpy(s->name, (void *)row[i]);
                        s->status = atoi(row[i + 1]);
                        if (row[i + 2] != NULL)
                            strncpy(s->work, row[i + 2], sizeof(s->work));
                        s = s->next;
                    }
                    break;
                }
            }
            sprintf(recv_pack->work, "%d", number);
        }
        else if (t == 3)
        {
            while ((row = mysql_fetch_row(result)) != 0)
            {
                for (unsigned int i = 0; i < mysql_num_fields(result); i++)
                {
                    if (row[i])
                    {
                        strcpy(s->name, (void *)row[i]);
                        strcpy(s->work, row[i + 1]);
                        s = s->next;
                    }
                    break;
                }
            }
        }
        else if (t == 4)
        {
            groupnode *p = grohead->next;
            while ((row = mysql_fetch_row(result)) != 0)
            {
                for (unsigned int i = 0; i < mysql_num_fields(result); i++)
                {
                    if (row[i])
                    {
                        p->id = atoi((void *)row[i]);
                        p = p->next;
                    }
                    break;
                }
            }
        }
        else if (t == 5)
        {
            groupnode *p = grohead->next;
            while ((row = mysql_fetch_row(result)) != 0)
            {
                for (unsigned int i = 0; i < mysql_num_fields(result); i++)
                {
                    if (row[i])
                    {
                        strcpy(p->name, (void *)row[i]);
                        p = p->next;
                    }
                    break;
                }
            }
        }
        else if (t == 6)
        {
            groupnode *p = grohead->next;
            while ((row = mysql_fetch_row(result)) != 0)
            {
                for (unsigned int i = 0; i < mysql_num_fields(result); i++)
                {
                    if (row[i])
                    {
                        strcpy(p->name, (void *)row[i]);
                        p->id = atoi(row[i + 1]);
                        p = p->next;
                    }
                    break;
                }
            }
        }
    }
    else
    {
        if (t == 1)
            sprintf(recv_pack->work, "%d", 0);
    }
    mysql_free_result(result);
}
void my_err(char *err_string, int line)
{
    fprintf(stderr, "line %d  ", line);
    perror(err_string);
    exit(1);
}
void send_t(pack *s, int fd)
{
    ssize_t nfs;
    if ((nfs = send(fd, s, sizeof(pack), 0)) < 0)
        my_err("send", __LINE__);
    printf("%zd\n", fd);
}
void recv_t(pack *s, int fd)
{
    if (recv(fd, s, sizeof(pack), 0) < 0)
        my_err("recv", __LINE__);
}
void recv_file(pack *recv_pack)
{
    char s[200], file[100];
    int fd, flag;
    int t = 0;
    off_t st;
    struct epoll_event ep_id;
    struct stat buf;
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    sprintf(s, "select file_name from files where recv_name=\'%s\' and id>0", recv_pack->send_name);
    t = mysql_select(s, recv_pack, 3);
    if (t == 0)
    {
        strcpy(recv_pack->work, "你暂时没有需要接收的文件");
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    else
        strcpy(recv_pack->work, "正在接收中请稍后");
    pthread_mutex_lock(&mysqs);
    flag = mysql_query(&mysql, s);
    if (flag)
    {
        mysql_error(&mysql);
    }
    result = mysql_store_result(&mysql);
    pthread_mutex_unlock(&mysqs);
    if (result)
    {
        while ((row = mysql_fetch_row(result)) != 0)
        {
            for (unsigned int i = 0; i < mysql_num_fields(result); i++)
            {
                if (row[i])
                {
                    strcpy(file, row[i]);
                    break;
                }
            }
        }
    }
    fd = open(file, O_RDONLY);
    fstat(fd, &buf);
    recv_pack->id = buf.st_size;
    send_t(recv_pack, recv_pack->send_id);
    sendfile(recv_pack->send_id, fd, NULL, buf.st_size);
    close(fd);
    recv_t(recv_pack, recv_pack->send_id);
    if (strcmp(recv_pack->work, "yes") == 0)
    {
        sprintf(s, "update file set id=0 where file_name=\'%s\' and id>0", file);
    }
    ep_id.data.fd = recv_pack->send_id;
    ep_id.events = EPOLLIN;
    epoll_ctl(ep_fd, EPOLL_CTL_ADD, recv_pack->send_id, &ep_id); //将该文件描述符添加到epolli
}
void *body(void *arg)
{
    pack *packs = ((pack *)arg);
    pack *recv_pack = (pack *)malloc(sizeof(pack));
    memcpy((void *)recv_pack, (void *)packs, sizeof(pack));
    switch (recv_pack->cho)
    {
    case 'a':
        sign(recv_pack); //登陆
        return NULL;
    case 'b':
        registered(recv_pack); //注册
        return NULL;
    case 'c':
        find_words(recv_pack);
        return NULL;
    case 'd':
        add_friend(recv_pack);
        break;
    case 'e':
        del_friend(recv_pack);
        break;
    case 'f':
        select_friend(recv_pack);
        break;
    case 'g':
        chat_friend(recv_pack);
        break;
    case 'j':
        message(recv_pack);
        break;
    case 'h':
        create_group(recv_pack);
        break;
    case 'i':
        del_group(recv_pack);
        break;
    case 'n':
        fri_histroy(recv_pack);
        break;
    case 'o':
        allgroup(recv_pack);
        break;
    case 'r':
        setgroup(recv_pack);
        break;
    case 'p':
        groupmember(recv_pack);
        break;
    case 'k':
        group_chat(recv_pack);
        break;
    case 's':
        cleargroup(recv_pack);
        break;
    case 't':
        joingroup(recv_pack);
        break;
    case 'w':
        group_histroy(recv_pack);
        break;
    case 'x':
        send_file(recv_pack);
        break;
    case 'y':
        recv_file(recv_pack);
        break;
    case 'u':
        delmumber(recv_pack);
        break;
    case 'z':
        blackmumber(recv_pack);
        break;
    default:
        break;
    }
    if (recv_pack->cho == 'k' && grchat == 1)
        return NULL;
    panduan_message(recv_pack);
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
int mysql_select(char *buf, pack *recv_pack, int t) //数据库查询单条消息或判断存在
{
    int flag;
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    int number = 0;
    pthread_mutex_lock(&mysqs);
    flag = mysql_query(&mysql, buf);
    if (flag)
    {
        mysql_error(&mysql);
    }
    result = mysql_store_result(&mysql);
    pthread_mutex_unlock(&mysqs);
    if (result)
    {
        // while ((field = mysql_fetch_field(result)) != 0)   查看表头
        // {
        //     printf("%-15s", field->name);
        // }
        // printf("\n");
        if (t == 4)
        {
            number = mysql_num_rows(result); //计算查询结果数量
            return number;
        }
        while ((row = mysql_fetch_row(result)) != 0)
        {
            for (unsigned int i = 0; i < mysql_num_fields(result); i++)
            {
                if (row[i])
                {
                    switch (t)
                    {
                    case 0: //注册
                        recv_pack->send_nums = atoi((char *)row[i]);
                        return 0;
                    case 1: //找回密码
                    {
                        strncpy(recv_pack->work, (char *)row[i], sizeof(row[i]));         //密码
                        recv_pack->id = atoi((char *)row[i + 1]);                         //问题号
                        strncpy(recv_pack->nums, (char *)row[i + 2], sizeof(row[i + 2])); //回答
                        mysql_free_result(result);
                        return 0;
                    }
                    case 2: //登陆
                    {
                        strncpy(recv_pack->work, right, sizeof(right)); //只要能找到数据，就正确
                        strcpy(recv_pack->send_name, (void *)row[i]);
                        mysql_free_result(result);
                        return 0;
                    }
                    case 3:
                    {
                        //只要能找到数据，就正确
                        mysql_free_result(result);
                        return 1;
                    }
                    case 6:
                    {
                        strcpy(recv_pack->recv_name, row[i]);
                        return 1;
                    }
                    case 5:
                    {
                        strcpy(recv_pack->recv_name, row[i]);
                        strcpy(recv_pack->work, row[i + 1]);
                        return 1;
                    }
                    case 7:
                    {
                        recv_pack->id = atoi(row[i]);
                        mysql_free_result(result);
                        return 1;
                    }
                    default:
                        break;
                    }
                }
            }
        }
    }
    mysql_free_result(result);
    return 0;
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
    char s[200];
    sprintf(s, "insert into user_all (username,password,question,answer)"
               "values(\'%s\',\'%s\',%d,\'%s\')",
            recv_pack->send_name, recv_pack->work, recv_pack->id, recv_pack->nums);
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
    char s[200];
    if(find_status(recv_pack->send_name,recv_pack->send_nums,1)==1)
    {
        strncpy(recv_pack->work,"该用户已经登陆，不可重复登陆，请重试",sizeof(recv_pack->work));
        send_t(recv_pack,recv_pack->send_id);
        return;
    }
    sprintf(s, "select username from user_all where number=%d and password=\'%s\'", recv_pack->send_nums, recv_pack->work);
    mysql_select(s, recv_pack, 2);
    send_t(recv_pack, recv_pack->send_id);
    if (strcmp(recv_pack->work, right) != 0)
    {
        return;
    }
    pthread_mutex_lock(&lock);
    node *p = (node *)malloc(sizeof(node));
    strcpy(p->t, recv_pack->send_name);
    p->id = recv_pack->send_id;
    end->next = p;
    end = p;
    end->next = NULL;
    pthread_mutex_unlock(&lock);
    infonode *pe, *qe;
    pe = ifhead;
    while (pe->next != NULL)
    {
        pe = pe->next;
    }
    qe = (infonode *)malloc(sizeof(infonode));
    strcpy(qe->name, recv_pack->send_name);
    qe->send_id = 0;
    pe->next = qe;
    qe->next = NULL;
    printf("用户登陆成功");
}
void find_words(pack *recv_pack) //找回密码
{
    char s[200];
    sprintf(s, "select password,question,answer from user_all where number=%d", recv_pack->send_nums);
    mysql_select(s, recv_pack, 1);
    send_t(recv_pack, recv_pack->send_id);
}
void add_friend(pack *recv_pack) //加好友
{
    char s[200];
    int t = 0, n = 0;
    sprintf(s, "select * from user_all where username=\'%s\'", recv_pack->recv_name);
    t = mysql_select(s, recv_pack, 3);
    sprintf(s, "select id from friend where recv_name=\'%s\'and send_name=\'%s\'union "
               "select id from friend where recv_name=\'%s\'and send_name=\'%s\'",
            recv_pack->recv_name, recv_pack->send_name, recv_pack->send_name, recv_pack->recv_name);
    n = mysql_select(s, recv_pack, 7); //如果没有加好友
    if (t == 0)
    {
        strcpy(recv_pack->work, "没有找到该用户"); //没有找到好友
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    else if (strcmp(recv_pack->send_name, recv_pack->recv_name) == 0) //如果添加自己为好友
    {
        strcpy(recv_pack->work, "对不起，不能添加自己为好友");
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    else if (n == 1)
    {
        strcpy(recv_pack->work, "对不起，你已经添加此人为好友,不可以重复加好友");
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    else
    {
        strcpy(recv_pack->work, "申请已经发送请等待");
    }
    recv_pack->id = 1;
    sprintf(s, "insert into message(recv_name,send_name,id)values(\'%s\',\'%s\',%d)",
            recv_pack->recv_name, recv_pack->send_name, recv_pack->id); //将消息写进表中
    send_t(recv_pack, recv_pack->send_id);
    mysql_in_del(s);
}
void del_friend(pack *recv_pack) //删除好友
{
    char s[200];
    int t = 0;
    sprintf(s, "select recv_name,send_name from friend where recv_name=\'%s\'and send_name=\'%s\'union "
               "select recv_name,send_name from friend where recv_name=\'%s\'and send_name=\'%s\'",
            recv_pack->recv_name, recv_pack->send_name, recv_pack->send_name, recv_pack->recv_name);
    if (t == mysql_select(s, recv_pack, 3))
    {
        strcpy(recv_pack->work, "你并不存在该好友"); //没有找到好友
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    sprintf(s, "delete from friend where recv_name=\'%s\'and send_name=\'%s\'", recv_pack->recv_name, recv_pack->send_name);
    mysql_in_del(s);
    sprintf(s, "delete from friend where recv_name=\'%s\'and send_name=\'%s\'", recv_pack->send_name, recv_pack->recv_name);
    mysql_in_del(s);
    recv_pack->id = 2;
    sprintf(s, "insert into message(recv_name,send_name,id)values(\'%s\',\'%s\',%d)",
            recv_pack->recv_name, recv_pack->send_name, recv_pack->id); //将消息写进表中
    strcpy(recv_pack->work, "你已经删除该好友");
    send_t(recv_pack, recv_pack->send_id);
    mysql_in_del(s);
}
void fri_histroy(pack *recv_pack) //查看好友历史
{
    char s[200];
    int t = 0;
    pthnode *p = pthead->next;
    sprintf(s, "select * from friend where recv_name=\'%s\'and send_name=\'%s\'union "
               "select * from friend where recv_name=\'%s\'and send_name=\'%s\'",
            recv_pack->recv_name, recv_pack->send_name, recv_pack->send_name, recv_pack->recv_name);
    if (t = mysql_select(s, recv_pack, 3) == 0) //如果没有加好友
    {
        strcpy(recv_pack->work, "对不起，你暂时没有该好友");
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    sprintf(s, "select send_name,words from friend_histroy where recv_name=\'%s\'and send_name=\'%s\'union "
               "select send_name,words from friend_histroy where recv_name=\'%s\'and send_name=\'%s\'",
            recv_pack->recv_name, recv_pack->send_name, recv_pack->send_name, recv_pack->recv_name);
    recv_pack->id = mysql_select(s, recv_pack, 4);
    t = recv_pack->id;
    send_t(recv_pack, recv_pack->send_id);
    pthread_mutex_lock(&lockwords);
    mysql_select_words(s, recv_pack, 3);
    for (int i = 0; i < t; i++)
    {
        send(recv_pack->send_id, (void *)p, sizeof(pthnode), 0); //每次发送1个节点的数据
        p = p->next;
    }
    pthread_mutex_unlock(&lockwords);
}
void select_friend(pack *recv_pack)
{
    char s[200];
    int all;
    ssize_t nfs;
    pthnode *t = pthead->next;
    sprintf(s, "select recv_name,send_name from friend where recv_name=\'%s\' "
               "union select recv_name,send_name from friend where send_name=\'%s\'",
            recv_pack->send_name, recv_pack->send_name);
    pthread_mutex_lock(&lockwords);
    //memset(pthead, 0, sizeof(pthnode) * (size + 1));
    mysql_select_words(s, recv_pack, 0);
    all = mysql_select(s, recv_pack, 4);
    recv_pack->id = all;
    send_t(recv_pack, recv_pack->send_id);
    for (int i = 0; i < all; i++)
    {
        if ((nfs = send(recv_pack->send_id, t, sizeof(pthnode), 0)) < 0)
        {
            my_err("send", __LINE__);
        }
        printf("%zd\n", nfs);
        t = t->next;
    }
    pthread_mutex_unlock(&lockwords);
}
void message(pack *recv_pack) //消息中心
{
    char s[400];
    int number;
    int all;
    pthnode *t = pthead->next;
    sprintf(s, "select send_name,id,works from message where recv_name=\'%s\'and id>0"
               " union  select a.send_name,a.id,a.works from message a,groups b where"
               " a.recv_name=b.idchar and a.id=3 and b.status>0 and b.name=\'%s\'",
            recv_pack->send_name, recv_pack->send_name);
    pthread_mutex_lock(&lockwords);
    mysql_select_words(s, recv_pack, 1);
    all = atoi(recv_pack->work);
    sprintf(s, "select send_name,id,works from message where recv_name=\'%s\'and id>0"
               " union  select a.send_name,a.id,a.works from message a,groups b where"
               " a.recv_name=b.idchar and a.id=3 and b.status>0 and b.name=\'%s\'",
            recv_pack->send_name, recv_pack->send_name);
    number = mysql_select(s, recv_pack, 4);
    recv_pack->id = number; //好友请求数量
    send_t(recv_pack, recv_pack->send_id);
    while (all--) //处理all个请求
    {
        send(recv_pack->send_id, (void *)t, sizeof(pthnode), 0); //每次发送1个节点的数据
        if (t->status == 1)
        {
            recv_t(recv_pack, recv_pack->send_id);
            if (strcmp(recv_pack->work, "yes") == 0)
            {
                sprintf(s, "insert into friend(recv_name,send_name,id)" //加入好友
                           "values(\'%s\',\'%s\',0)",
                        recv_pack->send_name, recv_pack->recv_name);
                mysql_in_del(s);
                sprintf(s, "update message set id=4,send_name=\'%s\',recv_name=\'%s\'"
                           " where recv_name=\'%s\' and send_name=\'%s\'",
                        recv_pack->send_name, recv_pack->recv_name,
                        recv_pack->send_name, recv_pack->recv_name);
                mysql_in_del(s);
            }
            else
            {
                sprintf(s, "update message set id=0 where send_name=\'%s\' and works=\'%s\'",
                        t->name, t->work);
                mysql_in_del(s);
            }
        }
        else if (t->status == 3)
        {
            recv_t(recv_pack, recv_pack->send_id);
            if (strcmp(recv_pack->work, "yes") == 0)
            {
                sprintf(s, "insert into groups(id,name,status,idchar)" //加入群表
                           "values(%d,\'%s\',0,\'%s\')",
                        atoi(t->work), t->name, t->work);
                mysql_in_del(s);
                sprintf(s, "update message set id=5,recv_name=\'%s\'"
                           " where send_name=\'%s\' and works=\'%s\'",
                        t->name, t->name, t->work);
                mysql_in_del(s);
            }
            else
            {
                sprintf(s, "update message set id=0 where send_name=\'%s\' and works=\'%s\'",
                        t->name, t->work);
                mysql_in_del(s);
            }
        }
        else if (t->status == 5)
        {
            sprintf(s, "update message set id=0 where recv_name=\'%s\'",
                    recv_pack->send_name);
            mysql_in_del(s);
        }
        t = t->next;
    }
    sprintf(s, "update message set id=0 where recv_name=\'%s\' and (id!=4 or id!=5)", recv_pack->send_name);
    mysql_in_del(s); //信息传完后，将所有状态设置为0,已发送
    pthread_mutex_unlock(&lockwords);
}
int main()

{
    int lid, cid;
    signal(SIGPIPE, SIG_IGN);
    head = (node *)malloc(sizeof(node));
    head->next = NULL;
    ifhead = (infonode *)malloc(sizeof(infonode));
    ifhead->next = NULL;
    end = head;
    pack *packs = (pack *)malloc(sizeof(pack));
    pthead = (pthnode *)malloc(sizeof(pthnode));
    pthnode *a, *b = pthead;
    for (int i = 0; i < size; i++)
    {
        a = (pthnode *)malloc(sizeof(pthnode));
        b->next = a;
        b = b->next;
    }
    b->next = NULL;
    grohead = (groupnode *)malloc(sizeof(groupnode));
    groupnode *x, *y = grohead;
    for (int i = 0; i < size; i++)
    {
        x = (groupnode *)malloc(sizeof(groupnode));
        y->next = x;
        y = y->next;
    }
    y->next = NULL;
    struct sockaddr_in client_addr, server_addr;
    lid = socket(AF_INET, SOCK_STREAM, 0);
    if (lid < 0)
    {
        my_err("socket", __LINE__);
    }
    int opt_val = 1;
    if (setsockopt(lid, SOL_SOCKET, SO_REUSEADDR, (void *)&opt_val, sizeof(int)) < 0)
    {
        my_err("setsockopt", __LINE__);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (bind(lid, (struct sockaddr *)&server_addr, sizeof(server_addr)))
    {
        my_err("bind", __LINE__);
    }
    if (listen(lid, 20) < 0)
    {
        my_err("listen", __LINE__);
    }
    ep_fd = epoll_create(size);
    struct epoll_event ep_id;
    struct epoll_event ep_ids[size];
    ep_id.data.fd = lid;
    ep_id.events = EPOLLIN;
    epoll_ctl(ep_fd, EPOLL_CTL_ADD, lid, &ep_id);
    int events = size;
    pthread_t pid;
    int tsize, nfs;
    socklen_t client_len = sizeof(client_addr);
    mysql_con();
    while (1)
    {
        if ((nfs = epoll_wait(ep_fd, ep_ids, events, -1)) < 0)
        {
            if (nfs == -1)
            {
                if (errno != EINTR)
                    my_err("epoll_wait", __LINE__);
            }
        }
        for (int i = 0; i < nfs; i++)
        {
            if (ep_ids[i].data.fd == lid) //有新的客户端连接
            {
                if ((cid = accept(lid, (struct sockaddr *)&client_addr, &client_len)) < 0)
                {
                    my_err("accept", __LINE__);
                }
                printf("连接到新的客户端:%s\n", inet_ntoa(client_addr.sin_addr));
                printf("accept:%d\n", cid);
                ep_id.data.fd = cid;
                ep_id.events = EPOLLIN;
                epoll_ctl(ep_fd, EPOLL_CTL_ADD, cid, &ep_id);
            }
            else if (ep_ids[i].events & EPOLLIN) //读数据
            {
                if ((tsize = recv(ep_ids[i].data.fd, packs, sizeof(pack), 0)) < 0)
                {
                    my_err("recv", __LINE__);
                }
                else if (tsize == 0) //对端客户端关闭
                {
                    close(ep_ids[i].data.fd);
                    node *t = head;
                    node *o;
                    pthread_mutex_lock(&lock);
                    while (t->next != NULL)
                    {
                        if (t->next->id == ep_ids[i].data.fd)
                        {
                            if (t->next == end)
                            {
                                end = t;
                            }
                            o = t->next;
                            t->next = t->next->next;
                            free(o);
                            break;
                        }
                        t = t->next;
                    }
                    pthread_mutex_unlock(&lock);
                    epoll_ctl(ep_fd, EPOLL_CTL_DEL, ep_ids[i].data.fd, &ep_id);
                }
                else
                {
                    packs->send_id = ep_ids[i].data.fd;
                    if (packs->cho == 'x' || packs->cho == 'y')
                    {
                        epoll_ctl(ep_fd, EPOLL_CTL_DEL, ep_ids[i].data.fd, &ep_id);
                    }
                    if (pthread_create(&pid, NULL, body, (void *)packs))
                    {
                        my_err("thread_create", __LINE__);
                    }
                    pthread_detach(pid);
                }
            }
        }
    }
    mysql_closet();
    return 0;
}
