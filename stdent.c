#include "student.h"
pass root = {"123456\n", "asdfgh\n"};
void jie();
void first_jie();
void add(node *t);
void select(node *t);
void first_jie() //开始登陆界面
{
    printf("----欢迎来到学生管理系统------\n");
    char nums[10];
    while (1)
    {
        printf("管理员账号:");
        fgets(nums, 10, stdin);
        if (strcmp(nums, root.nums) != 0)
        {
            printf("账号错误");
            continue;
        }
        printf("管理员密码:");
        fgets(nums, 10, stdin);
        if (strcmp(nums, root.password) != 0)
        {
            printf("密码错误");
        }
        else
            break;
    }
    printf("----欢迎来到学生管理系统----\n");
    jie();
}
void add(node *t)
{
    node *q = t;
    while (q->next != NULL)
    {
        q = q->next;
    }
    node *p = (node *)malloc(sizeof(node));
    p->next = NULL;
    q->next = p;
    printf("请输入以下信息\n");
    printf("姓名:");
    fflush(stdout);
    scanf("%s", p->name);
    printf("学号:");
    fflush(stdout);
    scanf("%d", &p->number);
    printf("数学：");
    fflush(stdout);
    scanf("%d", &p->math);
    printf("语文：");
    fflush(stdout);
    scanf("%d", &p->chinese);
    p->all = p->math + p->chinese;
}
void del(node *t)
{
    if (t->next == NULL)
        printf("该系统无信息\n");
    char name[10];
    node *q, *p = t;
    while (p != NULL)
    {
        p = p->next;
    }
    printf("需要删除学生姓名：");
    fgets(name, 10, stdin);
    for (node *s = p; s = s->next; s->next != NULL)
    {
        if (strcmp(s->next->name, name) == 0)
        {
            q = s->next;
            s->next = s->next->next;
            free(q);
            return;
        }
    }
}
void change(node *t)
{
    int nums[10];
    printf("需要修改学生姓名:\n");
    scanf("%s", nums);
    for (node *p = t; p = p->next; p != NULL)
    {
        if (strcpy(p->name, nums) == 0)
        {
            printf("修改为：\n");
            printf("姓名:");
            fflush(stdout);
            scanf("%s", p->name);
            printf("学号:");
            fflush(stdout);
            scanf("%d", &p->number);
            printf("数学：");
            fflush(stdout);
            scanf("%d", &p->math);
            printf("语文：");
            fflush(stdout);
            scanf("%d", &p->chinese);
            p->all = p->math + p->chinese;
            return;
        }
    }
}
void select(node *t)
{
    node *p=t;
    
    for(;p=p->next;p!=NULL)
    {
        printf("姓名：%s 学号: %d 数学语文");
    }
}
void jie() //选择界面
{
    node *t;
    t = (node *)malloc(sizeof(node));
    while (1)
    {
        printf("------------------------\n");
        printf("--------请作出选择------\n");
        printf("1.增加学生信息   *   2删除学生信息\n");
        printf("3.修改学生信息   *   4查询学生信息\n");
        printf("5.退出学生系统\n");
        char s;
        s = getc(stdin);
        switch (s)
        {
        case '1':
            add(t);
            break;
        case '2':
            del(t);
        case '3':

        case '4':
        case '5':
        default:
            printf("无效不可解析选择\n");
            break;
        }
    }
}
int main()
{
    first_jie();
    return 0;
}