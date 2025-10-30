//C语言第12天（25/10/29）

/**
* 一、没有类型的指针：
void* p不表示任何类型，但可以放入任意的地址
//1、定义两个变量
int a = 10 ;
short b = 20 ;
//指针变量（类型对应）
int* p1 = &a ;//指明地址
int* p2 = &b ;
printf("%d\n" , *p1) ;
printf("%d\n" , *p2) ;
//无类型指针的使用
//可等于一个指针（接受他的内存地址）
void* p3 = p1 ;
void* p4 = p2 ;
//但他无法获取指针中的具体数值，也无法进行加减法（报错）
//printf("%d" , *p3) ;
//printf("%p" , p3+1) ;


//运用场景：调用函数交换数据（好处是可以换算各种类型的数据，不用反复改数据类型）
#include <stdio.h>

void swap(void* p1 , void* p2 , int len) ;
int main(void) {
    long long c = 100L ;
    long long d = 200L ;
    swap(&c , &d , 8);//传送地址，void可接受所有数据类型
    printf("c=%d d=%d" , c , d);
}



void swap(void* p1 , void* p2 , int len)
{
//把void类型换成char
    char* pc1 = p1 ;
    char* pc2 = p2 ;
//一个字节一个字节的交换，就可以一个不漏的交换内存地址，从而达到交换数据
    char temp = 0 ;//定一个中间变量
    for (int i = 0 ; i  < len ; i++)
    {
        temp = *pc1 ;
        *pc1 = *pc2 ;
        *pc2 = temp ;
        pc1++ ;
        pc2++ ; //(内存地址加一个步长)
    }
}
二、二级指针和多级指针
指针也是一个变量，他本身也占用对应的地址
数据类型与指向空间中的数据类型一致
1、二级指针的格式：
int** 指针名//因为一级是int*
#include <stdio.h>

int main(void) {
    int a = 10;
    int b = 20;

    int *p = &a;
    int **pp = &p;//二级指针指向一级的地址
//作用一：利用二级指针修改一级指针中的地址
    *pp = &b;//一次解运算符，对pp来说是获取地址（已知pp的地址原先是二级指针）
//作用二：利用二级指针获取变量中记录的数据
    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", p);
    printf("%p\n", *pp);
    printf("%d\n", *p);
    printf("%d\n", **pp);//解引用运算符解两次得到对应值
}

三、数组指针
1、练习：利用指针遍历数组
#include <stdio.h>

int main(void) {
    //指针遍历数组
    //定义一个数组
    int arr[] = {1 , 3, 5 , 7 , 9};
    int len = sizeof(arr) / sizeof(arr[0]) ;
    //用指针指向首地址然后遍历
    int* p = &arr[0] ;//忘记加地址符了
    for(int i = 0 ; i < len ; i++)
    {
        printf("%d  " , *p);
        p++ ;//每次步长移动一个（移动到下一个数据的首地址）
    }
}
*/