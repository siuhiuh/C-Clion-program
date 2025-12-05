//C语言第27天（25/12/05）完结撒花！
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void) {
    //1、打开拷贝的文件（数据源）
    FILE *file1 = fopen("C:\\Users\\admin\\Desktop\\a.txt", "r"); //读取
    //2、打开文件夹（目的地）
    FILE *file2 = fopen("C:\\Users\\admin\\Desktop\\aaa\\a.txt", "w");//写入
    //3、利用循环读取数据源，读完后写入目的地
    char arr[1024];
    int n;
    //不确定到底多少个字符，因此用循环
    while ((n = fread(arr, 1, 1024, file1)) != 0) {
        //读取后写入
        fwrite(arr, 1, n, file2);//长度不再是数组长度
    }
    fclose(file1);
    fclose(file2);
}

/**
* 一、读取数据函数之，fread一次读多个
 *
 * #include<stdio.h>

int main(void) {
    //1、以只读方式打开文件
    FILE *file = fopen("C:\\Users\\admin\\Desktop\\a.txt", "r"); //文件路径，文件模式选取

    //2、读取数据：读不到返回null
    //定义一个数组（将文件内容存为数组来读取）
    char arr[1024];//一般长度直接设为1024
    int n = fread(arr, 1, 1024, file);//数组名称、数组内的类型长度，默认为char、总长度、文件名称
    printf("%d\n", n);//看看一次能读多少个字符
    printf("%s", arr);//将数组中全部的数据以字符串形式读出来
    //一个中文字符占3个(Windows的UTF-8格式下)，换行符也算一个字符
    //fread的细节：每次读取数据时会尽可能把数组装满，并返回当前读取到的有效字节

}


 #include<stdio.h>

int main(void) {
    //1、以只读方式打开文件
    FILE *file = fopen("C:\\Users\\admin\\Desktop\\a.txt", "r"); //文件路径，文件模式选取

    //2、while循环进行遍历打印数据
    //定义一个数组（将文件内容存为数组来读取）
    char arr[4];
    int n ;
    while((n = fread(arr, 1, 4, file)) != 0)
    {
     for(int i = 0 ; i < n ; i ++)
     {
         printf("%c" ,  arr[i]) ;//i表示索引，每一个arr里包含的是char类型数据
         //%c后面不允许加任何东西，否则未一次性读完的中文字符无法成形
     }
    }

}
*/

/**
* 二、写出数据：程序中的数据写到本地文件中永久存储
 * 1、fopen打开文件
 * 2、写出数据：fputc：一次写一个字符，返回写出字符
 * fputs：一次写一个字符串，忽略返回值,写成功返回非负数
 * fwrite：一次写多个，返回写出的个数
 *
 *include<stdio.h>

int main(void) {
    //1、以只读方式打开文件
    FILE *file = fopen("C:\\Users\\admin\\Desktop\\a.txt", "w"); //文件路径，文件模式选取
    //2、写出数据：
    int c = fputc(97 , file) ;//一个字符，对应的文件
    printf("%c\n" , c) ;

    int n = fputs("你好呀" , file) ; //char*指的是字符串
    printf("%d\n" , n) ;//EOF错误（end of file），表示文件夹装满了

    char arr[] = {'1','2','3','4'};
    int n1 = fwrite(arr , 1 , 4 , file) ;//数组名 字符类型长度 数组长度 写入的文件
    printf( "%d\n" , n1) ;//返回的是字符个数，因为用int来定义


    fclose(file) ;
}
*/

/**
* 三、关于读和写的小细节
 * r：只能读，不能写，如果是在w模式下，则会返回负数
 *
 * w：只写模式：
 * 细节1：文件不存在时，会把文件创建出来。但前提是文件夹都存在且无误
 * 细节2：文件已存在，输入内容后会把原内容清空
 * 细节3：创建和清空都是fopen这行代码就已经搞定了的
 *
 * a:续写模式
 * 细节1：文件不存在时，会把文件创建出来。但前提是文件夹都存在且无误
 * 细节2：文件已存在，输入内容后不会清空原内容
 * 细节3：创建和清空都是fopen这行代码就已经搞定了的
 *
*/

/**
* 四、利用代码拷贝文件：
 * 判断纯文本文件（r w a）：能用记事本打开，且打开后能读懂，不是乱码
 * 否则就是二进制（rb wb ab）
 *
 *
 * #include<stdio.h>

int main(void) {
    //1、打开拷贝的文件（数据源）
    FILE *file1 = fopen("C:\\Users\\admin\\Desktop\\a.txt", "r"); //读取
    //2、打开文件夹（目的地）
    FILE *file2 = fopen("C:\\Users\\admin\\Desktop\\aaa\\a.txt", "w");//写入
    //3、利用循环读取数据源，读完后写入目的地
    char arr[1024];
    int n;
    //不确定到底多少个字符，因此用循环
    while ((n = fread(arr, 1, 1024, file1)) != 0) {
        //读取后写入
        fwrite(arr, 1, n, file2);//长度不再是数组长度
    }
    fclose(file1);
    fclose(file2);
}
*/