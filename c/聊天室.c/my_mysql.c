
int main()
{
    MYSQL mysql;
    unsigned int nums;
    MYSQL_RES *res=NULL;
    mysql_init(&mysql);
    mysql_library_init(0,NULL,NULL);
    if(mysql_real_connect(&mysql,"127.0.0.1","root",password,"chat",0,NULL,0)==NULL)
    {
        my_err(mysql_real_connect,__LINE__);
    }


}