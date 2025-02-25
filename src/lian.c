#include "lian.h"
// 初始化链表
goods *disk_init()
{
    goods *p = (goods *)malloc(sizeof(goods));
    p->num = 0;
    p->price = 0;
    p->next = NULL;
    return p;
}

// 添加商品
void add_good(goods *p, double num, double price)
{
    goods *q = (goods *)malloc(sizeof(goods));
    q->num = num;
    q->price = price;
    q->next = p->next;
    p->next = q;
}

// 列出商品信息
void list_good(goods *p)
{
    int i = 0;
    while (p->next != NULL)
    {
        printf("商品编号：%d,商品单量：%lf,商品价格：%lf\n", i, p->next->num, p->next->price);
        p = p->next;
        i++;
    }
}

// 删除商品
void del_good(goods *p, int count)
{
    int i = 0;
    while (p->next != NULL && i < count)
    {
        i++;
        p = p->next;
    }
    if (i == count)
    {
        goods *q = p->next;
        p->next = q->next;
        free(q);
    }
}

// 计算商品性价比并找到最高值
void bi_max(goods *p)
{
    goods *current = p;     // 当前节点指针
    double max_bi = -1;     // 初始化为负值确保首次比较成立
    goods *max_good = NULL; // 记录最高性价比商品

    while (current != NULL)
    {
        // 计算当前节点的性价比
        current->bi = (double)current->price / current->num;

        // 更新最高性价比记录
        if (current->bi > max_bi)
        {
            max_bi = current->bi;
            max_good = current;
        }

        // 移动到下一个节点
        current = current->next;
    }

    if (max_good != NULL)
    {
        printf("最高性价比商品：单价 %.2lf，单量 %lf，性价比值 %.2f\n", max_good->price, max_good->num, max_good->bi);
    }
}

// 释放内存
void disk_free(goods *p)
{
    goods *q = p->next;
    while (q != NULL)
    {
        p->next = q->next;
        free(q);
        q = p->next;
    }
    free(p);
}

void run_main(goods *p)
{
    system("cls");
    int a;
    printf("欢迎使用价格比较系统\n请输入以下数字后回车:\n1.添加商品\n2.列出商品\n3.删除商品\n4.查找最便宜的商品\n5.退出系统\nBy Domye\n");
    printf("请输入数字：");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        run_1(p);
        break;
    case 2:
        run_2(p);
        break;
    case 3:
        run_3(p);
        break;
    case 4:
        run_4(p);
        break;
    case 5:
        disk_free(p);
        printf("欢迎下次使用！\n");
        break;
    default:
        printf("输入错误，请重新输入！\n");
        scanf("%d", &a);
        run_main(p);
        break;
    }
}

void run_1(goods *p)
{
    system("cls");
    double num, price;
    // 判断总量输入
    printf("请输入该商品总量：");
    while (scanf("%lf", &num) != 1 || num <= 0)
    {
        printf("输入错误，请重新输入！\n");
        while (getchar() != '\n')
            ; // 清空输入缓冲区
    }

    printf("请输入该商品单价：");

    // 判断单价输入
    while (scanf("%lf", &price) != 1 || price <= 0)
    {
        printf("输入错误，请重新输入！\n");
        while (getchar() != '\n')
            ; // 清空输入缓冲区
    }

    add_good(p, num, price);
    system("cls");
    printf("已添加商品\n按回车返回主菜单\n");
    getchar();
    getchar();
    run_main(p);
}
void run_2(goods *p)
{
    system("cls");
    list_good(p);
    printf("按回车返回主菜单\n");
    getchar();
    getchar();
    run_main(p);
}

void run_3(goods *p)
{
    system("cls");
    printf("请输入要删除的商品编号\n");
    int count;
    while (scanf("%d", &count) != 1 || count <= 0)
    {
        printf("输入错误，请重新输入！\n");
        while (getchar() != '\n')
            ; // 清空输入缓冲区
    }
    del_good(p, count);
    system("cls");
    printf("已删除商品\n按回车返回主菜单\n");
    getchar();
    getchar();
    run_main(p);
}

void run_4(goods *p)
{
    system("cls");
    bi_max(p);
    printf("按回车返回主菜单\n");
    getchar();
    getchar();
    run_main(p);
}
// 解决中文乱码问题
#pragma execution_character_set("utf-8")