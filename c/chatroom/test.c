/*练习mysql数据库的查询*/
#include "c_s.h"
int main()
{
	MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char query[100];
	int flag, t;
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "zhaozeyu1234", "test", 0, NULL, 0))
	{
		printf("Failed to connect to Mysql!\n");
		return 0;
	}
	else
	{
		printf("Connected to Mysql successfully!\n");
	}
	char buf[]="t_st";
	sprintf(query,"select * from \"%s\"",buf);
	//strcpy(query,"select * from t_st");
	/*查询，成功则返回0*/
	flag = mysql_query(&mysql, query);
	if (flag)
	{
		printf("Query failed!\n");
		return 0;
	}
	else
	{
		printf("[%s] made...\n", query);
	}
	/*mysql_store_result讲全部的查询结果读取到客户端*/
	res = mysql_store_result(&mysql);
	MYSQL_FIELD *field;
	while ((field = mysql_fetch_field(res)))   //表头
	{
		printf("%-10s", field->name);
	}
	printf("\n");
	/*mysql_fetch_row检索结果集的下一行*/
	while (row = mysql_fetch_row(res))
	{
		/*mysql_num_fields返回结果集中的字段数目*/
		for (t = 0; t < mysql_num_fields(res); t++)
		{
			printf("%-10s", row[t]);
		}
		printf("\n");
	}
	mysql_close(&mysql);
	return 0;
}