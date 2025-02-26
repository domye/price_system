#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct good
{
    double num;
    double price;
    char *name;
    double bi;
    struct good *next;
} goods;
goods *disk_init();
void add_good(goods *p, char *name, double num, double price);
void list_good(goods *p);
void del_good(goods *p, int count);
void bi_max(goods *p);
void run_1(goods *p);
void run_main(goods *p);
void disk_free(goods *p);
void run_3(goods *p);
void run_2(goods *p);
void run_1(goods *p);
void run_4(goods *p);
void run_main(goods *p);
int count_good(goods *p);