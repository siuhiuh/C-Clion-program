//C语言第15天（25/11/05）
#include <stdio.h>

int main(void) {
    //1、键盘录入一个字符串
    char str[100] ;
    printf("请录入一个字符串\n") ;
    scanf("%s" ,str) ;
    printf("接收到的字符串为：%s\n" , str) ;
    //2|遍历字符串中的每一个字符
    char* p = str ;//数组指针，取首地址

    while(1)
    {
        //利用指针获取字符串中的每一个字符，直到\0为止
        char c = *p ;//取到具体的值，用一个新变量来接收
        //判断当前字符是否为结束标记
        if(c == '\0')
        {
            break ;
        }
        printf("%c\n" , c) ;
        p++ ;
    }
}

/**
* 一、函数指针的练习
定义加减乘除四个函数：分别对应的 1 2 3 4
键盘录入三个数字

#include <stdio.h>

int add(int num1 , int num2) ;
int substract(int num1 , int num2) ;
int multiply(int num1 , int num2) ;
int divide(int num1 , int num2) ;
int main(void) {

//定义一个数组去装四个函数的指针
//函数指针数组：
    int (*arr[4]) (int , int) ={add , substract , multiply , divide} ;
//键盘录入两个进行运算的数字
    printf("请输入两个数字参与计算：") ;
//定义这两个数字
    int num1 ;
    int num2 ;
//用scanf_s看是否会报错
    scanf_s("%d %d" , &num1 , &num2) ;
//输入第三个数进行选择，调用函数
    printf("请选择计算方式") ;
    int choose ;
    scanf_s("%d" , &choose) ;
//难点：调用函数指针数组
    int res = (arr[choose - 1])(num1 , num2) ;//运用数组的索引来获取，放入实参。返回结果是一个数，用一个变量接住
    printf("%d" , res) ;


}
//写函数
int add(int num1 , int num2)
{
    return num1 + num2 ;
}

int substract(int num1 , int num2)
{
    return num1 - num2 ;
}

int multiply(int num1 , int num2)
{
    return num1 * num2 ;
}

int divide(int num1 , int num2)
{
    return num1 / num2 ;
} 

*/

/**
* 二、字符串两种定义方式和底层细节
*
 * 1、字符数组获取字符串，\0表示结束
 * 2、更常用的方式
 * #include <stdio.h>


int main(void) {
    //1、字符数组+双引号的方式来定义
    char str1[4] = "abc" ;
    printf("%s\n" , str1) ;//字符串是用%s输出，而不是%c
//需要注意的细节1：
//表面上看格式是abc，实际底层格式为{'a' , 'b' , 'c' , '\0'} ;
//细节二：
//数组的长度可以不写。但若要写，至少需要留结束标记的位置（即 > 字符个数+1）
//细节三：
//字符串+双引号的方式定义字符串，内容是可以自己改变的
str1[0] = 'Q' ;
printf("%s\n" , str1) ;

//2、利用指针+双引号的方式定义字符串
    char* str2 = "abcd" ;
    char* str3 = "abcd" ;
    printf("%s\n" , str2) ;
//需要注意的细节1：
//表面上看格式是abcd，实际底层格式为{'a' , 'b' , 'c' , 'd' , '\0'} ;
//细节二：
//指针+双引号的格式，会把字符串放入只读常量区
//特点：
//只可读，内容不可更改
//里面定义的字符串地址可复用
    //str2[0] = 'Q' ;
    //printf("%s\n" , str2) ;
    printf("%p\n" , str2) ;
    printf("%p\n" , str3) ;//共用地址

}
*/

/**
* 三、遍历字符串：
 * 键盘录入一个字符串，遍历它
 *#include <stdio.h>

int main(void) {
    //1、键盘录入一个字符串
    char str[100] ;
    printf("请录入一个字符串\n") ;
    scanf("%s" ,str) ;
    printf("接收到的字符串为：%s\n" , str) ;
    //2|遍历字符串中的每一个字符
    char* p = str ;//数组指针，取首地址

    while(1)
    {
        //利用指针获取字符串中的每一个字符，直到\0为止
        char c = *p ;//取到具体的值，用一个新变量来接收
        //判断当前字符是否为结束标记
        if(c == '\0')
        {
            break ;
        }
        printf("%c\n" , c) ;
        p++ ;
    }
}
*/