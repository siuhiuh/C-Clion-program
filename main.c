//C语言第20天（25/11/15）
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct spot
{
   int a ;//(4)0,1,2,3
   char b ;//(1)4
   char c ;//(1)5 (6,7)
   double d ;//(8) 8
   //0,1,2,3
   //4,5,6,7
   //此时并未对齐
   //8，（9，10，11）
   //（12，13，14，15）。为了能被最大的数据类型整除
   //共16位
};

int main(void) {
    //内存地址能被数据类型整除（数组的话就是首地址）
    //一、非结构体的数据类型验证地址是否为其整数倍
    int a ;
    printf("%d\n" , &a) ;//%p是16进制进行打印，%d是十进制进行打印
    //二、结构体验证它的字节计算方式
    //定义一个结构体：
    struct spot n ;
    printf("%zu\n" , sizeof(n)) ;
}



/**
* 一、结构体综合练习：投票选举
 * 共ABCD个景点
 *1、学生投票，用随机数模拟
 * 2、如果多景点投票数量一致，A优先B ， B优先于C
 *
 * #include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct spot
{
    char name[100] ;
    int count ;
};

int main(void) {
    //1、定义四个景点（结构体数组：相当于嵌套，可以同时容纳多个不同类型的数据）
    struct spot arr[4] = {{'A' , 0} , {'B', 0} ,{'C' , 0} ,{'D' , 0} };
    //可同时赋值，注意字符串赋值一定要加单引号

    //2、80个学生进行随机投票（随机数、循环）
    srand(time(NULL)) ;
    //这里的srand为什么不写在循环内：因为rand已经写在循环内了，取多少个rand就会有多少次srand
    for(int i = 0 ; i <= 80 ; i++)
    {
       //将rand变换为结构体数组的索引，需要一个新的变量
       int number = rand() % 4 ;//这里只能取0~4了
       //对应索引中的count就自动++
       arr[number].count++ ;

    }
    //3、比较出这四个景点票数的最大值
    //易忽略点：先设一个最大值，一般是数组中的第一个数据
    int max = arr[0].count ;
    for(int i = 1 ; i < 4 ; i++)
    {
        if(arr[i].count > max)//注意这里比较的是count
        {
            max = arr[i].count ;
        }
    }

    //4、将最大值对应的景点找出来（有相同值时，只取第一个值）
    //遍历数组
    for(int i = 0 ; i <4 ; i++)
    {
        if(arr[i].count == max)
        {
            printf("最受欢迎的景点为：%s , 总计票数： %d\n" , arr[i].name , arr[i].count) ;
        }
    }
//把所有数据遍历出来检查：
    for(int i = 0 ; i <4 ; i++)
    {
        printf("%s ,%d\n" , arr[i].name , arr[i].count) ;
    }

}
*/

/**
* 二、结构体内存对齐（结构体的内存分布）
 * 1、只能放在自己类型整数倍的内存地址上，对于任何数据类型都是如此
 *2、最后一个补位：结构体的总大小，是最大类型的整数倍
 *
 * #include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct spot
{
   int a ;//(4)0,1,2,3
   char b ;//(1)4
   char c ;//(1)5 (6,7)
   double d ;//(8) 8
   //0,1,2,3
   //4,5,6,7
   //此时并未对齐
   //8，（9，10，11）
   //（12，13，14，15）。为了能被最大的数据类型整除
   //共16位
};

int main(void) {
    //内存地址能被数据类型整除（数组的话就是首地址）
    //一、非结构体的数据类型验证地址是否为其整数倍
    int a ;
    printf("%d\n" , &a) ;//%p是16进制进行打印，%d是十进制进行打印
    //二、结构体验证它的字节计算方式
    //定义一个结构体：
    struct spot n ;
    printf("%zu\n" , sizeof(n)) ;
}
*/