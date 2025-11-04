//C语言第14天（25/11/04）
#include <stdio.h>

int main(void) {
///定义一个数组：
    int arr1[3] = {1 , 2 , 3} ;
    int arr2[3] = {1 , 2 , 6} ;
//定义二维数组
    int* arr[2] = {arr1 , arr2} ;
//获取指针（重点）
    int** p = arr ;
//循环嵌套
    for(int i = 0 ; i < 2 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            printf("%d " , *(*p + j)) ;
        }
        printf("\n") ;
        p++ ;
    }
}


/**
* 一、利用指针遍历第一种格式的二维数组
1、定义格式
数据类型* 指针名 = arr ；
二维时：int[5]* p = arr ;
格式优化：int(* p) [5] = arr ;
2、代码
#include <stdio.h>

int main(void) {
//定义一个二维数组
    int arr[2][4] =
            {
                    {1,  2,  3,  4},
                    {11, 22, 33, 44}
            };
//定义指针
    int (*p)[4] = arr;//不用取地址符？
//验证二维数组的步长（数据类型字符长度*一维中的数据个数）
    printf("%p\n", p);
    printf("%p\n", p + 1);
//遍历数组
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", *(*p + j)); //*p是一维数组首地址
        }
        printf("\n");
        p++;//二维指针移动（遍历下一个一维数组）
    }
}

二、用指针遍历第二种二维数组格式
1、定义格式
第二种定义格式的二维数组里面放的是内存地址：
int** p = arr ;
2、代码运行
#include <stdio.h>

int main(void) {
///定义一个数组：
    int arr1[3] = {1 , 2 , 3} ;
    int arr2[3] = {1 , 2 , 6} ;
//定义二维数组
    int* arr[2] = {arr1 , arr2} ;
//获取指针（重点）
    int** p = arr ;
//循环嵌套
    for(int i = 0 ; i < 2 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            printf("%d " , *(*p + j)) ;
        }
        printf("\n") ;
        p++ ;
    }
}

三、数组指针和指针数组
1、数组指针：指向数组的指针
比如int* p = arr ;//步长为int 4
int (*p)[5] = &arr ;//难道面对数组地址符是可写可不写吗，这是二维数组指针
//类型是一维数组
2、指针数组：存放指针的数组
int *p[5] //存放int类型的指针
int* arr[2] = {arr1 , arr2} ;

*/

/**
* 四、函数指针
 *
 *#include <stdio.h>

void method1() ;
int method2(int num1 , int num2) ;
int main(void) {
//难点在于函数指针定义格式
//复制函数注释
    void (* p1)() = method1 ;
    int (* p2)(int , int) = method2 ;//只需要写出形参的类型

    //调用函数
    p1() ;
    int num = p2(12 , 120) ;//return的是一个数值，因此要用一个新的变量来接收
    printf("%d" , num) ;
}
void method1()
{
    printf("method1\n") ;
}
int method2(int num1 , int num2)

{
    printf("method2\n") ;
    return num1 + num2 ;
}
*/