//C语言第二天25/10/16(类型转换到逻辑运算符)
/**
 * 一、类型转换：分为两类（自动类型转换、强制类型转换）
1.自动类型转换：编译器隐式进行类型转换
（1）short转为int（短变为长）：
#include <stdio.h>

int main(void) {
    short a = 10;
    int b = a;//直接传递
    printf("%d" ,b);
    return 0;
}
（2）float直接转换/int直接转换：
#include <stdio.h>

int main(void) {
    float a = 5;
    int b = 5.65;//输出时只取整，并非四舍五入
    printf("%d" ,b);
    return 0;
}
（3）长bit转短bit：（int switch char）（溢出情况 ）
#include <stdio.h>

int main(void) {
    int i = 511;
    char s = i;//除去前面的多余的数位，保留字符自身长度，符号位为1，视为补码来计算原码
    printf("%d" ,s);
    return 0;
}
（4）在运算中自动类型转换:
①
#include <stdio.h>

int main(void) {
    float a = 2;
    int b = 3;
    double c = b/a;
    printf("%f" ,c);
    return 0;
}
②
#include <stdio.h>

int main(void) {
    int a = 10 , b = 3;
    double c = a/b;
    printf("%f" ,c);
    return 0;
}
③
#include <stdio.h>

int main(void) {
    double a = 10 , b = 3;
    double c = a/b;
    printf("%f" ,c);
    return 0;
}

（5）运算中的规则：
①不同类型因为长度不同，优先级也不同
②char和short一律转为int再运算
③float类型转为double
④当高优先级和低优先级同时参与计算时，统一转化为高优先级

2.强制类型转换：在括号中输入想转化的数据类型
（1）不同类型转换：
#include <stdio.h>

int main(void) {
    double a = 3.14;
    int b = (int) a;
    printf("%d" ,b);
    return 0;
}
（2）对计算结果：
#include <stdio.h>

int main(void) {
    double a = 3.14 , b = 2.76;
    int c = (int)(a+b);
    printf("%d" ,c);
    return 0;
}
（3）转换优先级:
#include <stdio.h>

int main(void) {
    int a =10, b = 3;
    double c = (double)a/b;
    printf("%f" ,c);
    return 0;
}

 */

/**
 * 二、运算符：
1.基本运算符：
加+
减－
乘*
除/
等号=
（1）等号运算规律：从右往左赋值
a = b = 20;
(2)取余运算：%
#include <stdio.h>

int main(void) {
    int a = 10 , b = 3;
    int c = a % b;
    printf("%d" ,c);
    return 0;
}
 */

/**
 * 三、运算符的优先级
 * 1.与自然语言相似
 * #include <stdio.h>

int main(void) {
    int a = 2;
    int b = 3;
    printf("%d",a+b*a);
    return 0;
}
 *2.加括号提升优先级
 *#include <stdio.h>

int main(void) {
    int a = 2;
    int b = 3;
    printf("%d",(a+b)*a);
    return 0;
}
 *3.多重运算（不用中括号，大括号）
 *#include <stdio.h>

int main(void) {
    int a = 2;
    int b = 3;
    printf("%d",((a+b)*a)*b);//应用：在C语言中形成算式
    return 0;
}
 *4.优先级总结：
 * （） > '++ -- + -(正负号)' > '* / %' > + - > =
 *
 * 5.特殊情况：
 * （1）
 * #include <stdio.h>

int main(void) {
    int a ;
    int b = (3+(a=2))*6;
    printf("%d",b);
    return 0;
}
 *（2）引入逗号运算符：
 *#include <stdio.h>

int main(void) {
    int a ;
    int b ;
    int c = (a=4 , b=a+2);//没括号则报错
    printf("%d",c);
    return 0;
}
 *
 */

/**
* 四、自增自减运算符
 * 1.a = a+1 → ++a：(+在前)
 *#include <stdio.h>

int main(void) {
    int a = 1;
    ++a;
    printf("%d",a);
    return 0;
}
 *2.a++：
 *#include <stdio.h>

int main(void) {
    int a = 1;
    int b = a++;//b是a自增前的，a++也可以让a自增
    printf("%d %d" ,a,b);
    return 0;
}
 *3.一次性加大于1的数 a += x
 *#include <stdio.h>

int main(void) {
    int a = 1;
    int b = a += 6;
    printf("%d %d" ,a,b);
    return 0;
}
 *4.复合符号运算符：
 *#include <stdio.h>

int main(void) {
    int a = 6;
    int b = a %= 6;//其他运算符也可
    printf("%d %d" ,a,b);
    return 0;
}
 *5.自减运算符：--在前也可以在后
 * 同自增++
 * 6.该运算符优先级（难点，已解决）
 *#include <stdio.h>

int main(void) {
    int a = 6;
    printf("%d" ,a-- + --a);//6+（6-1-1）
    return 0;
}
 *
 *
*/

/**
* 五、位运算符：乘法运算符的快捷
 *1.左移<<(所有bit位左移)：
 *#include <stdio.h>

int main(void) {
    int a = 6;
    a = a<<3;//a<<=3
    printf("%d" ,a);//二进制相当于乘以2的几次方
    return 0;
}
 *2.右移>>:除以2的几次方
 *#include <stdio.h>

int main(void) {
    int a = 6;
    a = a>>2;//a<<=3
    printf("%d" ,a);
    return 0;
}
 *3.按位与&（and符号）：二进制计算，同时为1才为1（真）（8bit位为例）
 *#include <stdio.h>

int main(void) {
    int a = 1, b = 2;
    int c = a & b;
    printf("%d" ,c);
    return 0;
}
 *a:0000 0001
 *b:0000 0010
 *c:0000 0000
 *4.按位或|：只要有1就是1
 *#include <stdio.h>

int main(void) {
    int a = 1, b = 2;
    int c = a | b;
    printf("%d" ,c);
    return 0;
}
 *a:00000001
 *b:00000010
 *c:00000011
 *5.按位异或^：一样则为0
 * #include <stdio.h>

int main(void) {
    int a = 1, b = 2;
    int c = a ^ b;
    printf("%d" ,c);
    return 0;
}
 *a:00000001
 *b:00000010
 *c:00000011
 *6.按位非~：取反
 * #include <stdio.h>

int main(void) {
    char a = 0;
    printf("%d" ,a);//00000000 👉 11111111（负数是补码=10000001）
    return 0;
}
 *
 *
 */

/**
* 六、逻辑运算符：
 * 1.判断是否：_Bool(布尔类型)/int
 *#include <stdio.h>

int main(void) {
    int a = 10;
    _Bool  c= a > 0;
    printf("%d" ,c);
    return 0;
}
 *2.>= <= = < >
 *#include <stdio.h>

int main(void) {
    char a = 'D';
    printf("%d" ,a>='A');
    return 0;
}
 *3.逻辑与&&：同时满足
 *#include <stdio.h>

int main(void) {
    char a = 'a';
    printf("a是否是大写字母：%d" ,a>='A' && a<='Z');//逻辑与符号后也要写对应的变量
    return 0;
}
 *4.逻辑或||:满足其中一个
 *#include <stdio.h>

int main(void) {
    char a = 'a';
    printf("a是否不是大写字母：%d" ,a<'A' && a>'Z');
    return 0;
}
 *5.判断等于==：单个等号是赋值
 *#include <stdio.h>

int main(void) {
    char a = 'a';
    printf("a是否为a：%d" ,a=='a');
    return 0;
}
 *6.不等于！=：
 * ①
 *#include <stdio.h>

int main(void) {
    char a = 'a';
    printf("a是否不为a：%d" ,a=='a');
    return 0;
}
 * ②对整体结果取反
 *#include <stdio.h>

int main(void) {
    char a = 'a';
    printf("a是否不为a：%d" ,!(a=='b'));
    return 0;
}
 *7.三目运算符
 *#include <stdio.h>

int main(void) {
    int i = 10;
    char a = i>10 ? 'A' : 'B';//是则A，不是则B
    printf("%c" ,a);
    return 0;
}
 *
*/