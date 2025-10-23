//C语言学习第七天（25/10/23）
/**
* 一、函数随机数：
1、随机数实用线性同余方程计算出来的
2、如何设置种子和调出随机数：
种子srand（）是最初始的值，后面的数在他的基础上变化随机数rand（）
//1、调入随机数库 standard library
//2、种子srand(初始值)
//3、随机数int num=rand（）
3、输出多个随机数：
#include <stdio.h>
#include<stdlib.h>

int main(void) {
    srand(1);//种子不变结果不变
    for(int i=1 ; i<=5 ; i++)
    {
        int num=rand();
        printf("%d\n",num);
    }
}


二、解决随机数的弊端：
1、种子不变随机数结果不变（容易被破解）
//让种子也固定不变，变化的种子==时间？！
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
    srand(time(NULL));//现在的时间，默认种子1
    for(int i=1 ; i<=5 ; i++)
    {
        int num=rand();
        printf("%d\n",num);
    }
}
2、去任意的范围内取随机数：
//范围变成包头不包尾，包左不包右1－101
//尾巴－开头 101－1=100
//修改代码，把随机数巧思变成一个固定范围。
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
    srand(time(NULL));
    for(int i=1 ; i<=5 ; i++)
    {
        int num=rand() %100 + 1;//取余变成0~99的范围，+1就变为1~100
//取余的具体数值是开头－尾巴的值
        printf("%d\n",num);
    }
}

三、猜数字小游戏1~100，键盘录入，猜中为止
#include<stdlib.h>

//随机数只出一次即可，否则可能永远猜不中
srand(time(NULL));
int res = rand % 100 + 1;
int x;
while(1)
{
scanf("请输入你猜的值：\n",&x);//忽略的点，需要循环猜多次
if(x>res);
{
printf("大了哟\n");
}
else if(x<res)
{
printf("小了哟\n");
}
else
{
printf("恭喜！\n");
break;//直到答对才退出
}
}

四、数组：同时存储多个同类型数据（注意数据类型自动转换的情况）
1、数组的定义：
//格式：数据类型（int） 数组名（arr） [长度]（储存几个数）
2、特点：连续的空间；固定的数目
3、定义数组存储练习：
//全班80位同学的年龄
int arr1 [80];
//全班50名同学的身高：
double arr2 [50];
*/

/**
* 五、数组的初始化：定义数组时，第一次给数组赋值
 * 数据类型 数组名 [长度] = {数组值，数组值}
 * int arr [3] = {1,2,3}
 * 1、没有设定长度：有多少值，就表示长度多长
 * 2、数组值个数<=长度:自动补齐默认值0（\0;字符串：NULL）；若大于长度，则报错
 *3、练习：
 * //定义数组存储灵能百分百三个主角的年龄，并初始化
 * int arr [3] = {13 ,12 ,27};
 *
*/

/**
* 六、数组元素的访问：
 * 1、索引：数组的编号，角标
 * 2、获取：变量 = 数组名[索引]：
 * int num = arr[5];
 * //练习：（1）索引0，2，4的元素，并求和（2）最后一个索引的元素改为10
 *#include <stdio.h>

int main(void) {
    int arr [5] = {1,2,3,4,5};
    int num1 = arr[0];
    int num2 = arr[2];
    int num3 = arr[4];
    int sum = num1 +num2 + num3;
    printf("%d\n",sum);

    printf("初始值为：%d\n",arr[4]);
    arr[4] = 10;
    printf("修改后的值为：%d\n",arr[4]);


}
 *
*/

/**
* 七、数组的遍历：依次获取数组中的每一个元素：
 * 1、练习：遍历数组并打印到控制台：
 *#include <stdio.h>

int main(void) {
    int arr [5] = {1,2,3,4,5};
//ctrl+d,复制这一行，ctrl+x剪切可复制
    printf("%d\n",arr[0]);
    printf("%d\n",arr[1]);
    printf("%d\n",arr[2]);
    printf("%d\n",arr[3]);
    printf("%d\n",arr[4]);
//利用循环去遍历数组
for(int i =0; i<5 ;i++)//一般写数组的长度，但此刻长度需要自己数
{
    printf("%d\n",arr[i]);
}



}
 *
 *
*/

/**
* 八、内存中的变量、数组
 *1、什么是内存：软件在运行时，临时存储的地方
 * 2、内存地址：内存分为不同的字节（小格子编号）
 * 3、内存地址规则：32位2进制最多存储2^32字节（4GB）
 * 64位转为十六进制更方便阅读
 * 4、C语言：int类型=4个字节，会给出变量的首地址（第一个小格子）：
 * //获取变量内存
 *#include <stdio.h>

int main(void) {
    int a =10;
    int b =20;
    int c =30;
    printf("%p\n",&a);
    printf("%p\n",&b);
    printf("%p\n",&c);

}
 *
*/

/**
* 九、数组与内存地址：首地址/
 * 首地址[索引]：此时的索引表示偏移量，int类型偏移一个单位，表示偏移四个字节
 * //获取数组内存
 *#include <stdio.h>

int main(void) {
   int arr[] = {1,2,3};
   printf("%p\n",&arr);
   printf("%p\n",&arr[0]);
   printf("%p\n",&arr[1]);//58往上进4。9 A B C
   printf("%p\n",&arr[2]);//16进制每一位最大到F然后进1

}
 *
*/

/**
* 十、
 * 1、***数组作为函数的参数：计算长度那一节
 * //要求要有通用性
 * //遍历时传递len
 *#include <stdio.h>

void printfArr(int arr[] , int len);//函数在下方，记得调用函数

int main(void) {
   int arr[] = {1,2,3, 4, 5, 6};
   //printf("%zu",sizeof(arr));
   int len = sizeof(arr) / sizeof(arr[0]);//或int，把这里的len传递给下方
   printfArr(arr,len);//传递，实参的调用，arr是首地址
}

void printfArr(int arr[] , int len)//忘记写函数名了。一个字节的长度8 这里的arr是首地址
// 函数中的arr的长度仅为64位二进制的长度8。因此要在上方计算len
{
    for(int i = 0; i < len;i++)
    {
        printf("%d\n",arr[i]);
    }
}
 *
 *
 * 2、数组的索引越界：最小索引：0；最大索引：长度（）-1
 *#include <stdio.h>

void printfArr(int arr[] , int len);

int main(void) {
   int arr[] = {1,2,3, 4, 5, 6};
   int len = sizeof(arr) / sizeof(arr[0]);
   printfArr(arr,len);
   printf("%d\n",arr[len-1]);//可直接求最大索引的数据
}

void printfArr(int arr[] , int len)
{
    for(int i = 0; i < len;i++)
    {
        printf("%d\n",arr[i]);
    }
}
*/