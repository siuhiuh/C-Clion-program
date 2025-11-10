//C语言第16天（25/11/10）
#include <stdio.h>
#include <string.h>

int main(void) {
//以下用三种字符串定义方式
char* str1 = "ahh" ;//用指针时不需要定义长度(只读)
char str2[100] = "你aHh" ;
char str3[3] = {'x' , 'i' , '\0'};//要留出\0的位置

//1、strlen计算长度函数：输出时不计算结束标记的长度
//int len1 = strlen(str1) ;
//int len2 = strlen(str2) ;
//int len3 = strlen(str3) ;
//
//printf("%d\n" , len1) ;
//printf("%d\n" , len2) ;//中文字符占三个字节 3 -- 6
//printf("%d\n" , len3) ;

//2、strcat:拼接（第二个字符串的内容复制粘贴到第一个字符串后面）
//前提1：第一个字符串是可以被修改的，否则无法输出
//前提2：第一个字符串的空间足以容纳下总长度
//strcat(str2 , str3) ;
//printf("%s\n" , str2) ;
//printf("%s\n" , str3) ;

//3、strcpy：拷贝（第二个字符串的内容复制后覆盖第一个字符串的内容）
//前提1：第一个字符串是可以被修改的，否则无法输出
//前提2：第一个字符串的空间足以容纳下总长度
//    strcpy(str2 , str3) ;
//    printf("%s\n" , str2) ;
//    printf("%s\n" , str3) ;

//4、strcmp：比较，完全一样则返回0 ，不一样返回任意非零数
//int res = strcmp(str1 , str2) ;
//printf("%d\n" , res) ;

//5、strlwr：变小写，前提是可修改，而且无法改变中文
//strlwr(str2) ;
//printf("%s\n" , str2) ;

//6、strupr：变大写
strupr(str3) ;
printf("%s" , str3) ;
}

/**
* 一、字符串数组：遍历多个字符串
 * 定义一个数组存储五个学生的名字并遍历
 *#include <stdio.h>

int main(void) {
    //1、定义一个二维数组，存储多个名字
    //不知道具体字符串长度，只要能保证不超出范围就行（留出\0的位置）
char strArr[2][100] =
        {
        "tanlinjie" ,
        "tangxiaoqi"
        };
//2、遍历数组（利用指针）
for(int i = 0 ; i < 2 ; i++)
{
    char* str = strArr[i] ;//赋值给一个指针
    printf("%s\n" , str) ;//%s和%d的使用格式不同，%s不需要解引用
}
//2、方式2：定义一个数组指针
char* strArr1[2] =
        {
                "tanlinjie" ,
                "tangxiaoqi"
        };
for(int i = 0 ; i < 2 ; i++)//指针若是超出范围则不显示数据，但若是字符串数组则可正常输出
{
    char* str = strArr1[i] ;
    printf("%s\n" , str) ;
    //不同的循环中，相同的变量名可以反复使用
}
}
*/

/**
* 二、字符（string）串常见函数（6个）
 *#include <stdio.h>
#include <string.h>

int main(void) {
//以下用三种字符串定义方式
char* str1 = "ahh" ;//用指针时不需要定义长度(只读)
char str2[100] = "你aHh" ;
char str3[3] = {'x' , 'i' , '\0'};//要留出\0的位置

//1、strlen计算长度函数：输出时不计算结束标记的长度
//int len1 = strlen(str1) ;
//int len2 = strlen(str2) ;
//int len3 = strlen(str3) ;
//
//printf("%d\n" , len1) ;
//printf("%d\n" , len2) ;//中文字符占三个字节 3 -- 6
//printf("%d\n" , len3) ;

//2、strcat:拼接（第二个字符串的内容复制粘贴到第一个字符串后面）
//前提1：第一个字符串是可以被修改的，否则无法输出
//前提2：第一个字符串的空间足以容纳下总长度
//strcat(str2 , str3) ;
//printf("%s\n" , str2) ;
//printf("%s\n" , str3) ;

//3、strcpy：拷贝（第二个字符串的内容复制后覆盖第一个字符串的内容）
//前提1：第一个字符串是可以被修改的，否则无法输出
//前提2：第一个字符串的空间足以容纳下总长度
//    strcpy(str2 , str3) ;
//    printf("%s\n" , str2) ;
//    printf("%s\n" , str3) ;

//4、strcmp：比较，完全一样则返回0 ，不一样返回任意非零数
//int res = strcmp(str1 , str2) ;
//printf("%d\n" , res) ;

//5、strlwr：变小写，前提是可修改，而且无法改变中文
//strlwr(str2) ;
//printf("%s\n" , str2) ;

//6、strupr：变大写
strupr(str3) ;
printf("%s" , str3) ;
}
 *
*/