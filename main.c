//C语言第19天（25/11/13）
#include <stdio.h>
#include <string.h>

struct Message
        {
 char phone[12] ;//十一位多加一位
 char mail[100] ;
};

struct student
{
    char name[100] ;
    int age ;
    double height ;
    struct Message msg ;//取名字直接在这里取
};


int main(void) {
    //1、定义一个学生
    struct  student stu1 ;
    //2、赋值
    strcpy(stu1.name , "zhangsan") ;
    stu1.age = 19 ;
    stu1.height = 1.48 ;
    //重点，给嵌套结构体赋值(逐层解开)
    strcpy(stu1.msg.phone , "13112345678") ;
    strcpy(stu1.msg.mail , "13112345678@qq.com") ;
    printf("以下是该同学的一些信息：\n") ;
    printf("姓名为：%s\n" , stu1.name) ;
    printf("年龄为：%d\n", stu1.age) ;
    printf("身高为：%f\n" , stu1.height) ;
    printf("姓名为：%s\n" , stu1.msg.phone ) ;
    printf("姓名为：%s\n" , stu1.msg.mail) ;

    //简便方法：一次性赋值
    struct  student stu2 = {"zhangsan" , 43 , 1.49 , {"13212345679" , "123@qq.com"}};
    //嵌套的一块再加一个大括号，其中非字符串类型不用加引号
    printf("以下是该同学的一些信息：\n") ;
    printf("姓名为：%s\n" , stu2.name) ;
    printf("年龄为：%d\n", stu2.age) ;
    printf("身高为：%f\n" , stu2.height) ;
    printf("姓名为：%s\n" , stu2.msg.phone ) ;
    printf("姓名为：%s\n" , stu2.msg.mail) ;


}



/**
* 一、结构体作为函数的参数：函数中可传递结构体
 * 1、传递数据
 * 2、传递地址
 *
 * #include <stdio.h>
#include <string.h>

typedef struct
{
    char name[100] ;
    int age ;
}S;

void method1(S st) ;//函数title放在结构体下方，否则识别不到
void method2(S* p) ;

int main(void) {
    //1、定义一个学生
    S stu ;
    //2、给学生赋初始值
    strcpy(stu.name , "aaa") ;//给字符串赋值要用字符串函数
    stu.age = 0 ;//定义后直接调用就好了，不必引用结构体名称
    //3、打印出当前的学生信息
    printf("学生的姓名为：%s\n" , stu.name) ;
    printf("学生的年龄为：%d\n" , stu.age) ;
    //4、调用函数（尝试直接改变结构体内的值）
    method1(stu) ;//把名称给他就行
    //5、查看修改后的信息
    printf("修改后学生姓名：%s\n" , stu.name) ;
    printf("修改后学生年龄：%d\n" , stu.age) ;

    //将地址传递过去
    method2(&stu) ;//仍然不需要用S别名
    printf("修改后学生姓名：%s\n" , stu.name) ;
    printf("修改后学生年龄：%d\n" , stu.age) ;

}
//直接修改值会发现并未修改成功
//因为method1相当于定义了一个新变量，改变的是st的值，而不是stu
void method1(S st)//结构体名称+自定义名称
{
    printf("接收到的学生姓名为：%s\n" , st.name ) ;
    printf("接收到的学生年龄为：%d\n" , st.age ) ;
    //开始做修改(键盘)
    printf("请输入修改后的学生姓名：") ;
    fflush(stdout) ;
    scanf("%s" , st.name) ;//name本身是数组，当参与运算时，直接退化为指向首位的指针
    printf("请输入修改后的学生年龄：") ;
    fflush(stdout) ;
    scanf("%d" , &(st.age)) ;//这里的黄色警告不必担心
}
//定义一个指针
void method2(S* p)
{
    printf("接收到的学生姓名为：%s\n" , (*p).name ) ;//要将结构体的地址解引用
    printf("接收到的学生年龄为：%d\n" , (*p).age ) ;
    //开始做修改(键盘)
    printf("请输入修改后的学生姓名：") ;
    fflush(stdout) ;
    scanf("%s" , (*p).name) ;
    printf("请输入修改后的学生年龄：") ;
    fflush(stdout) ;
    scanf("%d" , &((*p).age)) ;

}
*/

/**
* 二、结构体嵌套
 * 成员包含结构体
 * 联系方式包括了手机号和电子邮箱
 *
 * include <stdio.h>
#include <string.h>

struct Message
        {
 char phone[12] ;//十一位多加一位
 char mail[100] ;
};

struct student
{
    char name[100] ;
    int age ;
    double height ;
    struct Message msg ;//取名字直接在这里取
};


int main(void) {
    //1、定义一个学生
    struct  student stu1 ;
    //2、赋值
    strcpy(stu1.name , "zhangsan") ;
    stu1.age = 19 ;
    stu1.height = 1.48 ;
    //重点，给嵌套结构体赋值(逐层解开)
    strcpy(stu1.msg.phone , "13112345678") ;
    strcpy(stu1.msg.mail , "13112345678@qq.com") ;
    printf("以下是该同学的一些信息：\n") ;
    printf("姓名为：%s\n" , stu1.name) ;
    printf("年龄为：%d\n", stu1.age) ;
    printf("身高为：%f\n" , stu1.height) ;
    printf("姓名为：%s\n" , stu1.msg.phone ) ;
    printf("姓名为：%s\n" , stu1.msg.mail) ;

    //简便方法：一次性赋值
    struct  student stu2 = {"zhangsan" , 43 , 1.49 , {"13212345679" , "123@qq.com"}};
    //嵌套的一块再加一个大括号，其中非字符串类型不用加引号
    printf("以下是该同学的一些信息：\n") ;
    printf("姓名为：%s\n" , stu2.name) ;
    printf("年龄为：%d\n", stu2.age) ;
    printf("身高为：%f\n" , stu2.height) ;
    printf("姓名为：%s\n" , stu2.msg.phone ) ;
    printf("姓名为：%s\n" , stu2.msg.mail) ;


}
*/