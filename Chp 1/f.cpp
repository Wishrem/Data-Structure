/**
 * @author Wishrem
 * @brief Chp2中例1的代码
 */

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

/*
    朴素写法实现
*/
void f1(int n, double a[], double x)
{
    double p = a[0];
    for (int i = 1; i <= n; i++)
        p += a[i] * pow(x, i);
    printf("计算结果为：%.2lf\n", p);
}

/*
    优化算法实现
*/
void f2(int n, double a[], double x)
{
    double p = a[n];
    for (int i = n; i > 0; i--)
        p = a[i - 1] + x * p;
    printf("计算结果为：%.2lf\n", p);
}

int main(int arg, char **args)
{
    if (arg < 3)
    {
        puts("指令：./[编译文件] [n的大小] [x的大小]");
        exit(EXIT_FAILURE);
    }

    clock_t start, end;
    int n = atoi(args[1]);
    double x = atof(args[2]);

    if (n == 0)
    {
        puts("请输入正确n的值");
        exit(EXIT_SUCCESS);
    }
    else if (x == 0)
    {
        puts("请输入正确x的值");
        exit(EXIT_SUCCESS);
    }

    // 随机生成ai 范围为0-9
    int lb = 0, ub = 9;
    double a[n + 1];
    for (int i = 0; i <= n; i++)
        a[i] = rand() % (ub - lb + 1) + lb;

    start = clock();
    f1(n, a, x);
    end = clock();
    printf("朴素方法运行的时间为：%.3lf ms\n", (double)(end - start) / 1000);

    start = clock();
    f2(n, a, x);
    end = clock();
    printf("优化算法方法运行的时间为：%.3lf ms\n", (double)(end - start) / 1000);

    return 0;
}