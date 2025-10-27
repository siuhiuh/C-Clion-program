//C语言第十天（25/10/27）
/**
* 一、什么是指针：内存地址
1、指针变量简称指针
2、定义格式：
数据类型 * 变量名（数据类型：跟指向变量类型保持一致）
int a = 10;
int* p1 = &a ;//意为a的地址存到指针中，指针代表的内存地址指向变量a
3、指针的作用：
（1）查询数据：*指针名（*是解引用运算符:通过后面的地址去获取对应的数据）
#include <stdio.h>

int main(void) {
    int a = 10;
    int* p = &a ;//格式尽量保持这样以保持区分
    printf("%d\n" , *p);
}
(2)实战：利用指针去存储数据 / 修改数据
#include <stdio.h>

int main(void) {
    int a = 10 ;
    int* p  = &a ;
    *p =  100 ;
    printf("%d\n" , *p);
    printf("%d \n" , a) ;

}
(3)指针的使用细节：指针变量占用的大小，跟数据类型无关，跟编译器有关（如64位：8字节2的8次方）
#include <stdio.h>

int main(void) {
    int a = 10 ;
    int* p1 = &a ;

    char b = 'A' ;
    char* p2 = &b ;
    printf("%zu \n", *p1);
    printf("%zu \n", *p2);

}

(4)不能直接把一个数值直接给指针变量
int a = 10 ;
int* p = 500 ;//500没有被编译器留内存地址

二、指针的灵活之处：
1、作用一：利用指针去操控其他函数中的变量：
#include <stdio.h>

void swap(int num1 , int num2 );
int main(void) {

//定义两个变量：
    int a = 10;
    int b = 20 ;
    printf("交换前： %d %d \n", a , b);
//仅仅调用函数：
    swap(a , b);//将a b 传递过去
    printf("交换后： %d %d \n", a , b);//发现a b并未交换



}
void swap(int num1 , int num2 )
{
//该函数此时只对num1 num2有用，而不是a b
    int temp = num1 ;
    num1 = num2 ;
    num2 = temp ;
}
//利用指针来操控变量（实质上是传递变量地址，对地址中的变量数据*p进行交换）
#include <stdio.h>

void swap(int* p1 , int* p2  );
int main(void) {

    void swap(int* p1 , int* p2);

    int a= 10 ;
    int b = 20 ;
    printf("交换后：%d %d " , a , b);
    swap(&a , &b);
    printf("交换后：%d %d " , a , b);


}
void swap(int* p1 , int* p2  )
{
    int temp = *p1;
    *p1 = *p2 ;
    *p2 = temp ;
}
 2、作用一的一些细节：
#include <stdio.h>

int* method();
int main(void) {
    int* p = method() ;//格式尽量保持这样以保持区分
    printf("%d\n" , *p);
}

int* method()
{
    static int a = 10 ;//加上static这个变量能一直保存到程序结束
    return &a ;//int* 是指针类型（指针内存地址），所以要返回a的地址
}
*/

/**
 *三、指针的作用二：函数返回多个值
 * 1、练习：定义一个函数，求数组的最大和最小值，并进行返回
 *#include <stdio.h>

void getMaxAndMin(int arr[] , int len , int* max , int* min);
int main(void) {
    //定义一个函数，求数组的最大和最小值，并进行返回
    //定义一个数组
    int arr[] = {1 ,2 ,3 , 4 , 5};
    int len = sizeof(arr) / sizeof(arr[0]) ;
    //调用函数？
    int max = arr[0] ;
    int min = arr[0] ;//前面提过*p的存在必须是前面存在的变量，因此要构造这两个变量
    getMaxAndMin(arr , len , &max , &min);//传递这些数据，其中max和min因为函数创建的是指针，因此需要传递地址

    printf("数组的最大值为：%d" , max);
    printf("数组的最小值为：%d" , min);
}
//为什么用了指针就可以输出多个变量了呢？而且max和min输出时就不用加地址符号了？
//因为指针不用返回参数值

void getMaxAndMin(int arr[] , int len , int* max , int* min)//没有返回值，用void
{
    *max = arr[0] ;//一般取0索引为初始基准值
    for(int i = 0 ; i < len ; i++)
    {
        if(arr[i] > *max)
        {
            *max = arr[i] ;
        }
    }
    *min = arr[0] ;
    for(int i = 0 ; i < len ; i++)
    {
        if(arr[i] < *min)
        {
            *min = arr[i] ;
        }
    }
    //若使用返回值，只能使用一次，可现在一共要返回两个变量
}
 */

/**
* 四、指针作用三：利用指针函数的结果和状态分开
 * 1、练：定义一个函数，将两数相除，获取他们的余数
 *#include <stdio.h>

int getRemainder(int num1 , int num2 , int* res );
int main(void) {
    //定义一个函数，将两数相除，获取他们的余数
    int num1 = 11 ;
    int num2 = 0 ;
    int res ;
    int flag = getRemainder(num1 , num2 , &res );//当函数中返回数据值时引入变量。不需要时直接调用
    if(!flag)//flag == 0
    {
        res = num1 % num2;
        printf("%d" , res) ;
    }

}

int getRemainder(int num1 , int num2 , int* res )//有返回值，用数据类型
{
    //两数相除取余
   if(num2 == 0)
    {
        return 1 ;//不再往下进行
    }
    *res = num1 % num2 ;//给指针赋值均用解引用运算符
    return 0;
}
*/