//C语言第21天（25/11/16）
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


union MoneyType
{
   int moneyi ;
   double moneyd ;//最大字节8
   char moneystr[100] ;//这里的最大字节不是100，他是char，字节为1
};

int main(void) {
    union MoneyType money ;
    //各成员的内存地址
    printf("%p\n" , &(money.moneyi)) ;
    printf("%p\n" , &(money.moneyd)) ;
    printf("%p\n" , &(money.moneystr)) ;

    //各字节长度和总字节长度（遵循内存对齐）
    printf("%zu\n" , sizeof(money.moneyi)) ;
    printf("%zu\n" , sizeof(money.moneyd)) ;
    printf("%zu\n" , sizeof(money.moneystr)) ;
    printf("%zu\n" , sizeof(money)) ;

    //被覆盖的情况
    money.moneyi = 999 ;
    strcpy(money.moneystr , "10万") ;
    printf("%s\n" , money.moneystr) ;
    printf("%d\n" , money.moneyi) ;//此时会获取一个完全未知的数字

}


/**
 * 一、共同体：一种数据可能有多种类型
 * 钱的数目：整数，小数类型
 * 1、基本格式：（与结构体类似）
 * union Money
 * {
 * int a ;
 * char b ;
 * };
 *
 * #include <stdio.h>
#include <string.h>


union MoneyType
{
   int moneyi ;
   double moneyd ;
   char moneystr[100] ;
};

int main(void) {
    union MoneyType money ;
    //每次只能赋一个值

    //money.moneyi = 9999 ;
    strcpy(money.moneystr , "10万元") ;
    //打印类型和赋值有关(每次打印一个)

    //printf("%d\n" , money.moneyi) ;
    printf("%s\n" , money.moneystr) ;


}
 */

/**
 * 二、共用体的特点：
 * 1、共用体=联合体= 共同体
 * 2、所有的变量都是用同一个内存空间：但结构体的成员空间都是互相独立的
 * 3、共用体所占内存大小=最大成员的长度（也有内存对齐）
 * 4、每次只能给一个变量赋值，第二次赋值会覆盖第一次的数据
 *
 */

/**
 * 三、结构体和共用体的区别：
 * 1、代码使用区别：
 * 结构体：一个事物代表多个属性
 * 共用体：一个属性有多种类型
 * 2、存储方式：
 * 各存各
 * 存在一起，多个会覆盖
 * 3、内存占用：
 * 各个变量总和（受内存对齐影响）
 * 最大类型的字节（受内存对齐影响）
 *
 */
