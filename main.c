//C语言第11天（25/10/28）
/**
* 一、指针的运算（加减法）：
1、指针中数据类型的作用：获取字节数据的个数（int 4个字节 char(1) long(4) short(2) long long（8））
2、p+1是指指针移动对应数据类型的的字节数
3、实战：指针运算：字节移动（步长）
#include <stdio.h>


int main(void) {
    int a = 10 ;
    int* p = &a ;
    printf("%p\n" , p + 1) ;
    printf("%p" , p - 1) ;

}

二、指针的有意义和无意义操作：
1、有意义：指针跟着整数做加减操作（每次移动n个步长） 、 指针跟指针进行减操作（间隔步长）
//前提条件：保证内存空间是连续的
//数组中的内存地址是连续的
#include <stdio.h>


int main(void) {
    int arr[] = {1 , 2 , 3 , 4 , 5 , 6} ;
    int* p1 = &arr[0];
    printf("%d \n" , *p1) ;
    printf("%d \n" , *(p1 + 1)) ;//获取内部数据
//获取索引5的地址
    int* p2 = &arr[5] ;
    printf("%d \n" , p2 - p1) ;//可获得步长间隔（步长跟数据类型无关， 只是看他们间隔了几步）隔了五个长度，因为他们是连续的
    printf("%p \n " , p1) ; //地址与数据类型有关（他们的间隔是字节）
    printf("%p \n" , p2) ;
}
2、指针运算无意义操作：（均会报错）
指针跟整数进行乘除操作
指针跟指针进行加 、 乘 、 除操作

三、指向不明的指针：
1、***野指针：指针指向的空间未分配
#include <stdio.h>


int main(void) {
    int a = 10 ;
    int* p1 = &a ;
    printf("%p \n" , p1) ;
    printf("%d \n" , *p1) ;
//野指针的空间未分配？？？
    int* p2 = p1 + 10 ;//没有一个对应的变量，因此地址未知
    printf("%p \n" , p2) ; //+ 4*10个字节
    printf("%d \n" , *p2) ;//会取到一个未知的地址，获得未知的 意想不到的数据 因此他很不安全 可能会侵犯隐私（可能是其他程序数据）
}
2、***悬空指针：指针指向的空间已分配，但是被释放了（引入一个函数）
#include <stdio.h>

int* method();
int main(void) {


    int* p3 = method() ;
    //printf("拖点时间\n");
    printf("%p \n" , p3) ;
    printf("%d \n" , *p3) ;


}
int* method()
{
    int num = 10 ;
    int* p = &num ;
    return p ;//返回p即可（代指p的数据），上面对应了p的类型（指针）
}


*/