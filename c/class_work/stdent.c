#include "student.h"
pass root = {"123456\n", "asdfgh\n"};
void qtsort(node *p, node *q) //排序链表
{
    node *t = q->next;
    if (t->next != NULL)
    {
        node *s = t->next;
        p->next = t;
        t->next = q;
        q->next = s;
    }
    else
    {
        p->next = t;
        t->next = q;
        q->next = NULL;
    }
}
void first_jie() //开始登陆界面
{
    printf("------欢迎来到学生管理系统------\n");
    char nums[10];
    while (1)
    {
        printf("管理员账号:");
        fgets(nums, 10, stdin);
        if (strcmp(nums, root.nums) != 0)
        {
            printf("账号错误\n");
            continue;
        }
        printf("管理员密码:");
        fgets(nums, 10, stdin);
        if (strcmp(nums, root.password) != 0)
        {
            printf("密码错误\n");
        }
        else
            break;
    }
    printf("-------欢迎来到学生管理系统--------\n");
    jie();
}
void add(node *t) //添加学生信息
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
    printf("添加完成\n");
}
void del(node *t) //删除学生信息
{
    if (t->next == NULL)
        printf("该系统无信息\n");
    int num;
    node *q;
    printf("需要删除学生学号：");
    scanf("%d", &num);
    for (node *s = t; s->next != NULL; s = s->next)
    {
        if (s->next->number == num)
        {
            q = s->next;
            s->next = s->next->next;
            free(q);
            printf("删除成功\n");
            return;
        }
    }
    printf("该系统中无此学生信息\n");
}
void change(node *t) //修改学生信息
{
    int nums;
    printf("需要修改学生学号:\n");
    scanf("%d", &nums);
    for (node *p = t; p != NULL; p = p->next)
    {
        if (p->number == nums)
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
            printf("修改完成\n");
            return;
        }
    }
    printf("该系统中无此学生信息\n");
}
void save(node *t) //保存链表到文件中
{
    FILE *fd;
    fd = fopen("infromation.txt", "w+");
    node *s = t;
    while (s->next != NULL)
    {
        s = s->next;
        fprintf(fd, "%s %d %d %d %d\n", s->name, s->number, s->math, s->chinese, s->all);
    }
    fclose(fd);
    printf("保存完成\n");
}
void sorts(node *t) //排序链表
{
    printf("1.按学号排序\n2.按照总分排序\n3.按照数学成绩\n4.按照语文成绩\n");
    char rt, re;
    node *p, *q;
    int we = 10;
    scanf("%c %c", &re, &rt);
    if (rt == '1')
    {
        while (we--)
        {
            for (p = t; p->next->next->next != NULL; p = p->next)
            {
                for (q = p; q->next->next != NULL; q = q->next)
                {
                    if (q->next->number > q->next->next->number)
                    {
                        qtsort(q, q->next);
                    }
                }
            }
        }
    }
    else if (rt == '2')
    {
        while (we--)
        {
            for (p = t; p->next->next->next != NULL; p = p->next)
            {
                for (q = p; q->next->next != NULL; q = q->next)
                {
                    if (q->next->all > q->next->next->all)
                    {
                        qtsort(q, q->next);
                    }
                }
            }
        }
    }
    else if (rt == '3')
    {
        while (we--)
        {
            for (p = t; p->next->next->next != NULL; p = p->next)
            {
                for (q = p; q->next->next != NULL; q = q->next)
                {
                    if (q->next->math > q->next->next->math)
                    {
                        qtsort(q, q->next);
                    }
                }
            }
        }
    }
    else if (rt == '4')
    {
        while (we--)
        {
            for (p = t; p->next->next->next != NULL; p = p->next)
            {
                for (q = p; q->next->next != NULL; q = q->next)
                {
                    if (q->next->chinese > q->next->next->chinese)
                    {
                        qtsort(q, q->next);
                    }
                }
            }
        }
    }
    else
    {
        printf("无效不可解析输入\n");
        return;
    }
    p = t;
    printf("排序后链表\n");
    while (p->next != NULL)
    {
        p = p->next;
        printf("名字%s 学号%d  数学%d 语文%d 总分%d\n", p->name, p->number, p->math, p->chinese, p->all);
    }
}
void reads(node *t) //从文件中读取数据
{
    FILE *fd;
    fd = fopen("infromation.txt", "r+");
    node *s = (node *)malloc(sizeof(node));
    node *p, *x;
    t->next = s;
    while (fscanf(fd, "%s %d %d %d %d\n", s->name, &s->number, &s->math, &s->chinese, &s->all) == 5)
    {
        p = (node *)malloc(sizeof(node));
        s->next = p;
        x = s;
        s = s->next;
    }
    p = x->next;
    x->next = NULL;
    free(p);
    fclose(fd);
    printf("文件中读取数据完成\n");
}
void selects(node *t) //查询学生信息
{
    int num;
    printf("1.全部查询\n2.按学号查询\n");
    scanf("%d", &num);
    if (num == 2)
    {
        printf("需要查询学生学号\n");
        scanf("%d", &num);
        for (node *p = t; p != NULL; p = p->next)
        {
            if (p->number == num)
            {
                printf("名字%5s 学号%5d  数学%5d 语文%5d 总分%5d\n", p->name, p->number, p->math, p->chinese, p->all);
                return;
            }
        }
        printf("该系统中无此学生信息\n");
    }
    else if (num == 1)
    {
        for (node *p = t->next; p != NULL; p = p->next)
        {
            printf("名字%s 学号%d  数学%d 语文%d 总分%d\n", p->name, p->number, p->math, p->chinese, p->all);
        }
    }
    else
        printf("无效不可解析输入\n");
}
void jie() //选择处理界面
{
    node *t;
    t = (node *)malloc(sizeof(node));
    printf("------------登陆成功--------------\n");
    reads(t);
    while (1)
    {
        printf("--------------------------------------\n");
        printf("---------------请作出选择-------------\n");
        printf("1.增加学生信息    *    2.删除学生信息\n");
        printf("3.修改学生信息    *    4.查询学生信息\n");
        printf("5.退出学生系统    *   6.排序学生信息\n");
        printf("7.保存学生信息\n");
        printf("--------------------------------------\n");
        char s;
        s = getc(stdin);
        switch (s)
        {
        case '1':
            add(t);
            break;
        case '2':
            del(t);
            break;
        case '3':
            change(t);
            break;
        case '4':
            selects(t);
            break;
        case '5':
            exit(0);
            break;
        case '6':
            sorts(t);
            break;
        case '7':
            save(t);
            break;
        default:
            printf("无效不可解析输入\n");
            break;
        }
        char nt;
        scanf("%c", &nt);
    }
}
int main()
{
    first_jie();
    return 0;
}