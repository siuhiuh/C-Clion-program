//C语言学习第六天（25/10/22）
/**
* 一、练习:特殊数字
 * 1、找出1~100的每位相加起来为15的数
 * //套路：外循环，取出1~100的每个数
 * //内循环：把这个数的每一位取出来，每位数加起来为15
 * #include <stdio.h>

int main(void) {
    int res = 0;
    for (int i = 1; i <= 100; i++) {
        while (i != 0) {
            res = res + i % 10;
            i /= 10;
        }
        if (res == 15) {
            printf("%d", i);
        }

    }
}
 *
 *二、循环嵌套的跳出问题
 * 1、普通break跳出单一循环：
 *#include <stdio.h>

int main(void) {
    for(int i =1;i<=3;i++){
        for(int j =1;j<=5;j++){
            printf("内循环执行中%d\n",j);
            break;
        }
        printf("内循环执行结束\n");
        printf("-------------\n");
    }
    printf("外循环结束\n");
}
 *2、goto跳出任意循环/也可以进行循环（但这样阅读性差）
 *#include <stdio.h>

int main(void) {
    for(int i =1;i<=3;i++){
        for(int j =1;j<=5;j++){
            printf("内循环执行中%d\n",j);
            goto a;
        }
        printf("内循环执行结束\n");
        printf("-------------\n");
    }
    a: printf("外循环结束\n");//在想跳转的行前标号
}
*/

/**
* 三、函数：什么是函数
 * 1、反复书写的代码可用于程序打包，简化代码
 * 2、函数式程序中独立的功能，如已有的printf scanf
 *
 * 四、函数的定义：自己写一个函数
 * 1、函数名（名称）
 * 2、函数体（内容）
 * 3、基本格式：
 * viod 函数名（）{
 * 函数体();//有小括号才表示调用函数
 * }
 *4、练习：
 *#include <stdio.h>

void sum(){
    printf("Breath\n");
    printf("English pod\n");
    printf("learn C\n");
    printf("learn PCB\n");
}
int main(void) {
    printf("你会怎样度过你的一天？\n");
    sum();
}
 *
 * 
*/

/**
* 四、函数小练习：函数求和运算
 * #include <stdio.h>

void sum(){
    int a= 15;
    int b= 16;
    int sum=a+b;
    printf("%d\n",sum);//函数中要包含输出
}
int main(void) {
    sum();
}
 *
 *
*/

/**
* 五、带参数的函数：在小括号内进行
 * 1、如加法时相加的数字不确定，只定义不赋值，可以定义很多个值：
 * void 函数名（形参）
 * 函数体（实参）
 * #include <stdio.h>

void sum(int num1 ,int num2){
    int sum = num1 + num2;
    printf("%d\n",sum);//函数中要包含输出
}
int main(void) {
    sum(20 ,30);
}
 *2、打印的次数由传入参数而定：自己做的一下就做出来了！啊哈哈哈好激动！！
 *#include <stdio.h>

void turn(int num){
    for(int i =1;i<=num;i++)
    printf("Hello!\n");//函数中要包含输出
}
int main(void) {
    turn(5);
}
 *
*/

/**
* 六、带有返回值的函数
1、标准函数格式：
返回值类型 函数名（形参1 ， 形参2）
{
函数体；
return 返回值；//调用时直接是答案，而非打印这个步骤
}
2、练习：小明：基础题50分，大题40分；小张：基础题36分，大题45分；
#include <stdio.h>

int sum(int base , int big)//这个int不是定义sum的，这个只是返回值类型
{
    int sum = base + big;//sum需要额外定义
    return sum;
}
int main(void) {
    int  score1=sum(50,40);//另一种调用方式：printf("占位符"，函数名（实参）)
    int score2=sum(36,45);
    if(score1 > score2)
    {
        printf("小明总分更高");
    }
    else if(score1 <score2 )
    {
        printf("小张总分更高");
    }
    else
    {
        printf("两位同学一样高");
    }
}
3、函数的好处：代码的复用性，代码的可维护性（只用关注函数逻辑是否正确）

七、定义函数：
1、定义函数是为了干嘛（确认函数体）
2、需要什么才能完成这个。形参
3、用完后是否需要继续使用，返回值类型是否用void
4、给定两个长方形，看谁的面积更大:
#include <stdio.h>

int Area(int chang , int kuan)//这个int不是定义sum的，这个只是返回值类型
{
    double Area = chang*kuan;

    return Area;
}
int main(void) {
    double area1=Area(10.1 , 13.6 );
    double area2=Area(9.6 , 14.2);
    if(area1 > area2)
    {
        printf("hi");
    }
    else if(area1 < area2)
    {
        printf("hello");
    }
    else
    {
        printf("no");
    }
}
*/

/**
* 八、函数的注意事项：
 *1、函数不调用就不运行
 * 2、函数名不能重复
 * 3、函数和函数之间不能嵌套
 * 4、函数可写在main下方，但需要提前定义，在最上方写函数调用开头，并加上分号
 * 5、return后编写代码无效
 * 6、void是没有返回值的，return不仅可以返回结果，也可以结束函数
 *
*/

/**
* 九、C语言中的常见函数：
 * 1、math.h:
 * pow() 幂
 * sqrt（）平方根
 *2、例子：
 * #include <stdio.h>
#include <math.h>//引入头文件

int main(void) {
    double res1= pow(2 , 4);
    printf("%lf\n",res1);

    double res2= sqrt(3);
    printf("%lf\n",res2);

    double res3= ceil(14.6);//向上取整进1
    printf("%lf\n",res3);

    double res4= floor(14.6);//向下取整
    printf("%lf\n",res4);

    int res5= abs(-13);//取绝对值，abs指整数
    printf("%d\n",res5);

    double res6= fabs(-14.6);//对小数取绝对值（fabsf fabsl）
    printf("%lf\n",res6);
}
 *3、时间函数
 *#include <stdio.h>
#include <time.h>//引入头文件

int main(void) {
    //time()当前时间，从C语言到现在过了多少秒
   long long TIME= time(NULL);//形参表示当前时间是否需要在其他地方存储，不需要就NULL
    //具体类型查看可以长按ctrl+鼠标点击，最终发现是long long
    printf("%lld\n",TIME);//工具狗
}
*/