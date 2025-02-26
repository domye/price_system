#include <stdio.h>
#include "lian.h"
int main()
{
    system("chcp 65001");
    system("cls");
    goods *head = disk_init();
    int a;
    system("color 0A");
    printf("欢迎使用价格比较系统\n请输入以下数字后回车:\n1.添加商品\n2.列出商品\n3.删除商品\n4.查找最便宜的商品\n5.退出系统\nBy Domye\n");
    printf("请输入数字：");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        run_1(head);
        break;
    case 2:
        run_2(head);
        break;
    case 3:
        run_3(head);
        break;
    case 4:
        run_4(head);
        break;
    case 5:
        disk_free(head);
        printf("欢迎下次使用！\n");
        break;
    default:
        getchar();
        getchar();
        run_main(head);
        break;
    }
    return 0;
}
