#include"study.h"
void Fetch(struct Node **head,struct Node **end)
{
     FILE *fd;
    if ((fd = fopen("infromation.txt", "r")) < 0)
    {
        printf("文件打开错误！");
        return;
    }
    if(*head==NULL)
    {
        struct Node *temp=(struct Node *)malloc(sizeof(struct Node*));
        *head=temp;
        *end=temp;
        fscanf(fd,"%s %d %d %d %d\n",(*head)->name,&(*head)->number,&(*head)->math,&(*head)->chinese,&(*head)->sum);
    }
    struct Node *t=*head;
    while(t)
    {   
        struct Node *p=(struct Node *)malloc(sizeof(struct Node*));
        p->next=NULL;
        t->next=p;
        *end=p;
        if(5!=fscanf(fd,"%s %d %d %d %d",p->name,&p->number,&p->math,&p->chinese,&p->sum))
        {
            *end=t;
            t->next=NULL;
            break;
        }
        t=t->next;
    }
    fclose(fd);
}

void Sort(struct Node **head,struct Node **end)
{
    if(*head=NULL)
    {
        printf("库中无学生信息！\n");
        return ;
    }
    else if(*head==*end) //链表中只有一个节点时直接输出数据
    {
        printf("姓名：%s  学号：%d  语文：%d  数学：%d  总分：%d\n", (*head)->name, (*head)->number, (*head)->chinese, (*head)->math, (*head)->sum);
        return ;
    }
    struct Node *i=*head;
    struct Node *j=(*head)->next;
    

    

}

void Save(struct Node *head)
{
    FILE *fp;
    fp=fopen("stu.txt","w");
    struct Node *t=head;
    while(t)
    {
        fprintf(fp,"%s %d %d %d %d\n",t->name,t->number,t->math,t->chinese,t->sum);
        t=t->next;
    }
    printf("保存成功!\n");
    fclose(fp);
}

void Look(struct Node *head)
{
    if (head == NULL)
    {
        printf("库中没有学生信息！\n");
        return;
    }
    struct Node *t = head;
    while (t)
    {
        printf("姓名：%s  学号：%d  语文：%d  数学：%d  总分：%d\n", t->name, t->number, t->chinese, t->math, t->sum);
        t = t->next;
    }
}

void Revise(struct Node *head, struct Node *end)
{
    if (head == NULL)
        return;
    int flag;
    printf("请输入要修改学生的学号：\n");
    scanf("%d", &flag);
    struct Node *t = head;
    while (t)
    {
        if (t->number == flag)
            break;
        t = t->next;
    }
    if (t == NULL)
    {
        printf("查无此学生，请重新操作！\n");
        return;
    }
    printf("请输入要修改的学生姓名:\n");
    scanf("%s", t->name);
    printf("请输入要修改的学生学号:\n");
    scanf("%d", &t->number);
    printf("请输入要修改的学生语文成绩:\n");
    scanf("%d", &t->chinese);
    printf("请输入要修改的学生数学成绩:\n");
    scanf("%d", &t->math);
    t->sum = t->chinese + t->math;
    printf("修改成功！\n");
}

void Seek(struct Node *head, struct Node *end)
{
    int flag;
    if (head == NULL)
    {
        printf("库中没有学生信息！\n");
        return;
    }
    printf("请输入要查找学生的学号：\n");
    scanf("%d", &flag);
    struct Node *t = head;
    while (t)
    {
        if (t->number == flag)
        {
            printf("查找成功，学生信息如下：\n");
            printf("姓名：%s\n", t->name);
            printf("学号：%d\n", t->number);
            printf("数学成绩：%d\n", t->math);
            printf("语文成绩：%d\n", t->chinese);
            printf("总成绩：%d\n", t->sum);
            return;
        }
        t = t->next;
    }
    printf("库中没有此学生信息，请重新操作！\n");
}

void Interface(struct Node **head,struct Node **end)
{
    printf("          欢迎来到学生管理系统         \n");
    printf("请输入要进行的操作：\n");
    printf("1.增加学生信息|| 2.删除学生信息|| 3.查找学生信息\n4.修改学生信息|| 5.排列学生信息|| 6.查看所有信息\n7.保存学生信息|| 8.结束程序 \n");
}

void Add(struct Node **head, struct Node **end)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    printf("请输入学生姓名：\n");
    scanf("%s", temp->name);
    printf("请输入学生学号：\n");
    scanf("%d", &temp->number);
    printf("请输入学生的语文成绩：\n");
    scanf("%d", &temp->chinese);
    printf("请输入学生的数学成绩:\n");
    scanf("%d", &temp->math);
    temp->sum = temp->chinese + temp->math;
    printf("添加成功!\n");

    if (*head == NULL)
    {
        *head = temp;
        *end = temp;
    }
    else
    {
        (*end)->next = temp;
        (*end) = temp;
    }
}

void Delete(struct Node **head, struct Node **end)
{
    if (*head == NULL)
        return;
    int flag; //要进行删除操作的学生的学号
    printf("请输入要删除学生的学号：\n");
    scanf("%d", &flag);
    if (*head == *end && (*head)->number == flag)
    {
        free(*head);
        *head = NULL;
        *end = NULL;
        printf("删除成功！\n");
        return;
    }
    else if ((*head)->next == *end)
    {
        if ((*head)->number == flag)
        {
            struct Node *p = *head;
            *head = (*head)->next;
            free(p);
        }
        else if ((*end)->number == flag)
        {
            struct Node *p = *end;
            *end = *head;
            free(p);
        }
        printf("删除成功！\n");
    }
    else
    {
        struct Node *t = *head;
        if ((*head)->number == flag)
        {
            struct Node *temp = *head;
            *head = (*head)->next;
            free(temp);
            printf("删除成功！\n");
            return;
        }
        else
        {
            while (t != *end)
            {

                if (t->next->number == flag)
                {
                    struct Node *temp = t->next;
                    t->next = temp->next;
                    free(temp);
                    printf("删除成功！\n");
                    return;
                }
                t = t->next;
            }
        }
    }
}
int main(void)
{
    int operate; //选择的操作数字
    struct Node *head = NULL;
    struct Node *end = NULL;
    Fetch(&head,&end);
    while (1)
    {
        Interface(&head,&end);
        scanf("%d", &operate);
        switch (operate)
        {
        case 1:
            Add(&head, &end);
            break;
        case 2:
            Delete(&head, &end);
            break;
        case 3:
            Seek(head, end);
            break;
        case 4:
            Revise(head, end);
            break;
        case 6:
            Look(head);
            break;
        case 7:
            Save(head);
            break;
        case 8:
            return 0;
        }
    }
    return 0;
}