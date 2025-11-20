//C语言第23天（25/11/20）
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void){
//索取一个连续的内存空间
int* p = malloc(10 * sizeof(int)) ;
int size = 10 ;
//给空间赋值
for(int i = 0 ; i < size ; i++)
{
    p[i] = (i + 1)*10 ;
}
//遍历出里面的值
for(int i = 0 ; i < size ; i++)
{
    printf("%d " , *(p + i) );//忘记移动步长了，导致只取了首地址的值
}
printf("\n") ;
//释放该空间
free(p) ;
//再次遍历看看会发生什么
for(int i = 0 ; i < size ; i++)
{
    printf("%d " , *(p + i)) ;
}

}
/**
 * 一、动态内存配置函数的细节点：
 * 7、free释放完后的空间，里面的数据被称为脏数据，无法再被使用
 *
 * #include<stdio.h>
#include <stdlib.h>

int main(void){
//索取一个连续的内存空间
int* p = malloc(10 * sizeof(int)) ;
int size = 10 ;
//给空间赋值
for(int i = 0 ; i < size ; i++)
{
    p[i] = (i + 1)*10 ;
}
//遍历出里面的值
for(int i = 0 ; i < size ; i++)
{
    printf("%d " , *(p + i) );//忘记移动步长了，导致只取了首地址的值
}
printf("\n") ;
//释放该空间
free(p) ;
//再次遍历看看会发生什么
for(int i = 0 ; i < size ; i++)
{
    printf("%d " , *(p + i)) ;
}

}
 *8、calloc就比malloc多了个初始化的步骤
 * 9、realloc修改后的地址，地址值可能变化，但数据不会丢（若连着的空间被使用则可能变化）
 * 10、realloc修改后无需释放原来的空间，函数会自行处理
 */




































