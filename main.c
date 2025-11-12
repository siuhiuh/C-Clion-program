//C语言第18天（25/11/12）
#include <stdio.h>
#include <string.h>

typedef struct //可省略cha，必须加typedef
{
    char name[100] ;
    int blood ;
}C;
int main(void) {
    C nanuo = {"纳诺" , 10000} ;
    C nanai = {"纳奈" , 1};
    //定义数组
    C arr[2] = {nanuo , nanai};//定义数组也不需要写struct
    //遍历
    for(int i = 0 ; i < 2 ; i++ )
    {
        C temp = arr[i] ;//这里前面写别名就代表了他的类型
        printf("名字是%s , 法力值为%d\n" , temp.name , temp.blood) ;
    }
}

/**
* 一、字符串实战：统计字符次数
 *统计大写、小写、数字的个数
 *
 *#include <stdio.h>
#include <string.h>

int main(void) {
//1、键盘录入字符串
printf("请输入一个字符串：") ;
    fflush(stdout) ;
    char str[100] ;
    scanf("%s" , str) ;
//2、计数器：count++
//遍历字符串
int bigcount = 0 ;
int smallcount = 0 ;
int numbercount = 0 ;
for(int i = 0 ; i< strlen(str) ; i++)//这里长度未知，直接用字符串函数
{
    char c = str[i] ;//请勿忘记用一个变量读取遍历
    if(c >= 'a' && c <= 'z')
    {
        smallcount++ ;
    }
    else if(c >= 'A' && c <= 'Z')
    {
        bigcount++ ;
    }
    else if(c >= '0' && c <= '9')//这里不可只用数字，此刻数字也是字符
    {
        numbercount++ ;
    }
}
printf("big%d\n" , bigcount) ;
printf("small%d\n" , smallcount) ;
printf("number%d\n" , numbercount) ;
}
*/

/**
* 二、结构体！：自定义的数据类型，一批数据组合的整体
 * 1、格式：
 * struct 结构体名字
 * {
 * 成员1 ；//里面可包含任何类型
 * 成员2 ；
 * }
 *
 * 2、小细节：
 * 可写在main函数里面（局部），也可以写在外面（全局位置）
 *
#include <stdio.h>
#include <string.h>

struct Mylover
{
    char name[100] ;
    int age ;
    char gender ;
    double height ;
};
int main(void) {
    //使用结构体
    //定义一个变量
    struct Mylover qiqi ;//记得要自己取一个名字
    strcpy(qiqi.name , "qiqi") ;//.是一个指向，指向结构体中的具体某一成员
    qiqi.age = 21 ;
    qiqi.gender ='F' ;//字符是不可以打印出中文的
    qiqi.height =1.63 ;

    printf("名字%s\n" , qiqi.name) ;
    printf("年龄%d\n" , qiqi.age) ;
    printf("性别%c\n" , qiqi.gender) ;
    printf("身高%lf\n" , qiqi.height) ;

}
*/

/**
* 一、结构体练习1：
 * 定义一个学生的结构体
 * 学生的基础信息
 * 三个学生放入数组，遍历数组
 *
 *
#include <stdio.h>
#include <string.h>

struct Student
{
    char name[100] ;
    int age ;
};
int main(void) {
    //定义三个学生并赋值
    struct Student stu1 = { "zhangsan" ,21} ;
    struct Student stu2 = { "lisi" ,22} ;
    struct Student stu3 = { "nanuo" ,25} ;
//2、三个学生放入数组
struct Student stuArr[3] = {stu1 , stu2 , stu3};//类型为结构体
//3、遍历获取
for(int i = 0 ; i < 3 ; i++) {
    //用一个变量来接收（不知道用啥）
    struct Student temp = stuArr[i];//跟数组内的类型一样，stu是结构体
    printf("学生的名字%s , 学生的年龄%d\n", temp.name, temp.age);
}
}
*/

/**
* 三、起别名，方便后续调用的方便性（甚至不用写struct）
 *
 * #include <stdio.h>
#include <string.h>

typedef struct //可省略cha，必须加typedef
{
    char name[100] ;
    int blood ;
}C;
int main(void) {
   C nanuo = {"纳诺" , 10000} ;
   C nanai = {"纳奈" , 1};
   //定义数组
   C arr[2] = {nanuo , nanai};//定义数组也不需要写struct
   //遍历
   for(int i = 0 ; i < 2 ; i++ )
   {
     C temp = arr[i] ;//这里前面写别名就代表了他的类型
     printf("名字是%s , 法力值为%d\n" , temp.name , temp.blood) ;
   }
}
*/
