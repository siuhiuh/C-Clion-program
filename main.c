//C语言第26天（25/11/28）
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void){
   //1、以只读方式打开文件
   FILE* file = fopen("C:\\Users\\admin\\Desktop\\a.txt" , "r") ; //文件路径，文件模式选取

   //while循环
   //2、读取数据：读不到返回null
   //定义一个数组（将文件内容存为数组来读取）
   char arr[1024] ;//一般长度直接设为1024
   char* str ;//数组名称，数组长度（直接引用最长长度），文件名称
   while((str = fgets(arr , 1024 , file) ) != NULL)//null必须大写
   {
      printf("%s" , str) ;
   }
}

/**
* 五、读取数据函数的应用：
 * 1、一次读一行（fgets，读不到返回null）
 *
 * #include<stdio.h>


int main(void){
   //1、以只读方式打开文件
   FILE* file = fopen("C:\\Users\\admin\\Desktop\\a.txt" , "r") ; //文件路径，文件模式选取

   //2、读取数据：读不到返回null
   //定义一个数组（将文件内容存为数组来读取）
   char arr[1024] ;//一般长度直接设为1024
   char* str1 = fgets(arr , 1024 , file) ;//数组名称，数组长度（直接引用最长长度），文件名称

   printf("%s\n" , arr) ;//这两者都可以读
   printf("%s" , str1) ;//所以fgets用不用指针接收都是可以的

   //获取特殊值null
   char* str2 = fgets(arr , 1024 , file) ;
   printf("%s" , str2) ;
}
 *
 *
 *
 * 细节：（1）以换行符为准（在文件中按回车），而不是界面
 * （2）读不到返回null，我们可以用循环来读完全篇（while）
 *
 *#include<stdio.h>


int main(void){
   //1、以只读方式打开文件
   FILE* file = fopen("C:\\Users\\admin\\Desktop\\a.txt" , "r") ; //文件路径，文件模式选取

   //while循环
   //2、读取数据：读不到返回null
   //定义一个数组（将文件内容存为数组来读取）
   char arr[1024] ;//一般长度直接设为1024
   char* str ;//数组名称，数组长度（直接引用最长长度），文件名称
   while((str = fgets(arr , 1024 , file) ) != NULL)//null必须大写
   {
      printf("%s" , str) ;
   }
}
 *
*/