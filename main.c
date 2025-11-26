//C语言第25天（25/11/26）
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void){
   //1、打开文件:悬停后可发现该函数返回的是指针，所以要设一个指针来接收
   FILE* file = fopen("C:\\Users\\admin\\Desktop\\a.txt" , "r") ; //文件路径，文件模式选取

   //2、读取数据：读不到返回-1
   int c ;
   //printf("%c" , c) ;

   //循环逐字读取：只知道结束条件
   while((c = fgetc(file) ) != -1)
   {
      printf("%c", c) ;
   }

   //3、关闭文件
   fclose(file) ;

}

/**
* 一、文件：永久化存储
 * 1、读取输入流（被程序读取）
 * 2、写输出流（程序往外写）
 *
*/

/**
* 二、文件的路径：文件的位置
 * win+e 快捷打开文件夹
 * 1、绝对路径：以盘符开始： C：
 * 2、相对路径：相对于当前项目
 * 处于不同的文件夹，相对的项目也不同
 *
*/

/**
* 三、转义字符\：改变\后的符号特殊含义，比如双引号，这样便可打印
 * 如何表示路径
 * 字符串形式
 *
 * #include<stdio.h>

int main(void){
    printf("\"\n") ;
    printf("\\\n") ;

    char* file = "C:\\aaa\\a.txt" ;//写入两个斜杠
    printf("%s\n" , file) ;

}
*/

/**
* 四、读取数据（操作文件）：把本地文件数据，读到程序中来
 * 步骤：
 * 1、打开文件：fopen
 * 2、读数据的函数：
 * fgetc：一次读一个字符
 * fgets：一次读一行（字符串）
 * fread：一次读多个
 *3、关闭文件：fclose
 *
 * #include<stdio.h>


int main(void){
   //1、打开文件:悬停后可发现该函数返回的是指针，所以要设一个指针来接收
   FILE* file = fopen("C:\\Users\\admin\\Desktop\\a.txt" , "r") ; //文件路径，文件模式选取

   //2、读取数据：读不到返回-1
   int c ;
   //printf("%c" , c) ;

   //循环逐字读取：只知道结束条件
   while((c = fgetc(file) ) != -1)
   {
      printf("%c", c) ;
   }

   //3、关闭文件
   fclose(file) ;

}
*/