#include "c_s.h"
MYSQL mysql;
void mysql_in_del(char buf)
{
    int flag;
    flag = mysql_real_query(mysql, buf);
    if (flag)
    {
        my_err(buf, __LINE__);
    }
}
void musql_select(char buf)
{
    int flag;
    MYSQL_RES *result;
    mysql_row row;
    MYSQL_FIELD *field;
    flag = mysql_real_query(mysql, buf);
    if (flag)
    {
        my_err(buf, __LINE__);
    }
    result = mysql_store_result(&mysql);
    while (field = mysql_fetch_field(result))
    {
        printf("-20s",field->name);
    }
    printf("\n");
    while (row = mysql_fetch_row(result))
    {
        for (int i = 0; i < mysql_num_fields; i++)
        {
            if (row[i])
            {
                printf("%-20s", row[i]);
            }
        }
        printf("\n");
    }
}
void mysql_con()   //数据库初始化,连接
{
    unsigned int nums;
    MYSQL_RES *res = NULL;
    mysql_init(&mysql);
    mysql_library_init(0, NULL, NULL);
    if (mysql_real_connect(&mysql, "127.0.0.1", "root", password, "chat", 0, NULL, 0) == NULL)
    {
        my_err(mysql_real_connect, __LINE__);
    }
    mysql_set_character_set(&mysql, "utf8");
}
int mysql_close()
{
    mysql_close(&mysql);
    mysql_library_end();
    printf("end\n");
    return 0;
}
int main()
{
   
    mysql_con();
}
