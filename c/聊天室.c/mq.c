#include "c_s.h"
int main()
{
    MYSQL mysql;
    unsigned int num_fields;
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    mysql_init(&mysql);
    mysql_library_init(0, NULL, NULL);
    mysql_real_connect(&mysql, "127.0.0.1", "root", "zhaozeyu1234", "chat", 0, NULL, 0);
    mysql_set_character_set(&mysql, "utf8");
    num_fields = mysql_num_fields(result);
    while (row = mysql_fetch_row(result))
    {
        for (int i = 0; i < num_fields; i++)
        {
            if (row[i])
            {
                printf("%-20s", row[i]);
            }
        }
        printf("\n");
    }
    mysql_close(&mysql);
    mysql_library_end();
    return 0;
}