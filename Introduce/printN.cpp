/**
 * @author Wishrem
 * @brief Chp1中例1的代码，这里并没有显示输出，而是压入了流中效果类似。
 */

#include <iostream>
#include <ctime>
#include <sstream>

std::stringbuf buf;
std::ostream out(&buf);

/*
    循环实现打印1-n
*/
void printN1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        out << i;
    }
    return;
}

/*
    递归实现打印1-n
*/
void printN2(int n)
{
    if (n)
    {
        printN2(n - 1);
        out << n;
    }
    return;
}

int main(int arg, char **args)
{
    if (arg < 2)
    {
        puts("指令：./[编译文件] [n的大小]");
        exit(EXIT_FAILURE);
    }

    clock_t start, end;
    int n = atoi(args[1]);

    if (n == 0)
    {
        puts("请输入正确n的值");
        exit(EXIT_SUCCESS);
    }

    start = clock();
    printN1(n);
    end = clock();
    printf("循环方法运行的时间为：%.3lf ms\n", (double)(end - start) / 1000);

    out.clear();
    start = clock();
    printN2(n);
    end = clock();
    printf("递归方法运行的时间为：%.3lf ms\n", (double)(end - start) / 1000);

    return 0;
}