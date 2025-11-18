//C语言第22天（25/11/18）
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void method(int* p , int size) ;
int main(void) {
    int *p = malloc(10 * sizeof(int));
    int size = 10;//自行定义一个size
    printf("%d\n", sizeof(p));//仅仅是指针的大小，而不是malloc空间的大小（包含多少个某类型的数据）
    free(p) ;
    //因此我们要学会两种赋值方式：利用循环
    for (int i = 0; i < 10; i++)//i是不能等于10的，索引超出，会导致程序空白
    {
        //方式一：解引用后赋值（注意p的指向要改变，增加步长）
        //*(p + i) = 1 + i ;
        //方式二：利用数组直接取索引赋值
        p[i] = 1 + i;
    }
    method(p , size) ;//这里的p不用取地址符，p本来就是指向地址的
    free(p) ;
}
void method(int* p , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d  " , p[i] ) ;
    }
}
/**
 * 一、动态内存分配：可任意请求地址
 * 1、需要掌握以下四个函数：均放在<stdlib.h>中
 * malloc（memory allocation） 作用：申请空间（连续空间）
 * realloc（re-allocation） 作用：修改空间大小
 *calloc（contiguous allocation） 作用：申请空间+数据初始化
 *free 作用：释放空间（以防申请空间太多，被挤爆）
 *
 * 2、函数1的运用：malloc
 *
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //要求：申请一片空间。放入10个int类型
    //malloc中写入的是字符的长度
    int* p = malloc(10 * sizeof(int)) ;//对于64位来说，int占4位，可写为malloc（400）；但这不具有通用性
    //此时输出地址，会指向首地址
    printf("%p\n" , p) ;
    //此时仅有内存，而没有具体的数值
    printf("%d\n" , *p) ;//会随机输出一个数字

    //因此我们要学会两种赋值方式：利用循环
    for(int i = 0 ; i < 10 ; i++)//i是不能等于10的，索引超出，会导致程序空白
    {
        //方式一：解引用后赋值（注意p的指向要改变，增加步长）
        *(p + i) = 1 + i ;
        //方式二：利用数组直接取索引赋值
        //p[i] = 1 + i ;
    }
    //循环遍历出来
    for(int i = 0 ; i < 10 ; i++)
    {
        printf("%d  " , *(p + i)) ;
        //printf("%d  " , p[i]) ;
    }

}
 *3、calloc函数（不常用）
 *
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //要求：申请一片空间。放入10个int类型
    //calloc中写入的是字符的数目以及类型长度
    int* p = calloc(10  ,sizeof(int)) ;//对于64位来说，int占4位，可写为malloc（400）；但这不具有通用性
    //此时输出地址，会指向首地址
    printf("%p\n" , p) ;
    //数据会初始化
    printf("%d\n" , *p) ;
 }
 *4、realloc（不常用）：
 *
 * #include <stdio.h>
#include <stdlib.h>

int main(void) {
    //要求：申请一片空间。放入10个int类型
    //calloc中写入的是字符的数目以及类型长度
    int* p = malloc(10 * sizeof(int)) ;//对于64位来说，int占4位，可写为malloc（400）；但这不具有通用性
    //此时输出地址，会指向首地址
    printf("%p\n" , p) ;
    //数据会初始化
    printf("%d\n" , *p) ;

    //因此我们要学会两种赋值方式：利用循环
    for(int i = 0 ; i < 10 ; i++)//i是不能等于10的，索引超出，会导致程序空白
    {
        //方式一：解引用后赋值（注意p的指向要改变，增加步长）
        //*(p + i) = 1 + i ;
        //方式二：利用数组直接取索引赋值
        p[i] = 1 + i ;
    }
    //利用realloc修改空间大小
    int* pp = realloc(p , 20 * sizeof(int)) ;
    //循环遍历出来
    for(int i = 0 ; i < 20 ; i++)//前十个已赋值，后十个随机
    {
        //printf("%d  " , *(p + i)) ;
        printf("%d  " , p[i]) ;
    }

}
 *5、free：释放空间（重要）
 *
 *#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //要求：申请一片空间。放入10个int类型
    //calloc中写入的是字符的数目以及类型长度
    int* p = malloc(10 * sizeof(int)) ;//对于64位来说，int占4位，可写为malloc（400）；但这不具有通用性
    //此时输出地址，会指向首地址
    printf("%p\n" , p) ;
    //数据会初始化
    printf("%d\n" , *p) ;

    //因此我们要学会两种赋值方式：利用循环
    for(int i = 0 ; i < 10 ; i++)//i是不能等于10的，索引超出，会导致程序空白
    {
        //方式一：解引用后赋值（注意p的指向要改变，增加步长）
        //*(p + i) = 1 + i ;
        //方式二：利用数组直接取索引赋值
        p[i] = 1 + i ;
    }
    //利用realloc修改空间大小
    int* pp = realloc(p , 20 * sizeof(int)) ;
    //循环遍历出来
    for(int i = 0 ; i < 20 ; i++)//前十个已赋值，后十个随机
    {
        //printf("%d  " , *(p + i)) ;
        printf("%d  " , p[i]) ;
    }
//free释放空间，因为是空间，所以用指针来赋值
free(pp) ;//无任何显示，但实际上已释放
}
 */

/**
 * 二、动态内存分配的函数细节：
 * 1、malloc创建的空间单位是字节
 * 2、malloc的返回值是一个void类型的指针，他没有步长的概念，需要强转
 * viod类型保证了函数的通用性
 * void* p = malloc(100) ;
 * //变为
 * int* p = malloc(100) ;
 * 3、malloc返回的仅仅是首地址，没有总大小，可以额外定义一个变量记录大小
 *
#include <stdio.h>
#include <stdlib.h>


void method(int* p , int size) ;
int main(void) {
    int *p = malloc(10 * sizeof(int));
    int size = 10;//自行定义一个size
    printf("%d\n", sizeof(p));//仅仅是指针的大小，而不是malloc空间的大小（包含多少个某类型的数据）

    //因此我们要学会两种赋值方式：利用循环
    for (int i = 0; i < 10; i++)//i是不能等于10的，索引超出，会导致程序空白
    {
        //方式一：解引用后赋值（注意p的指向要改变，增加步长）
        //*(p + i) = 1 + i ;
        //方式二：利用数组直接取索引赋值
        p[i] = 1 + i;
    }
    method(p , size) ;//这里的p不用取地址符，p本来就是指向地址的
}
void method(int* p , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d  " , p[i] ) ;
    }
}
 *
 * 4、malloc申请的空间不会自动消失，如果不能释放，会导致内存泄漏（内存满了）
 *
 * 5、malloc申请的空间过多，会产生虚拟内存（申请成功返回首地址，失败返回NULL）
 *
 * 6、此时仅有内存，而没有具体的数值。因此要学会赋值的两种方式
 */
