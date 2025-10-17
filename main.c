//C语言第三天（25/10/17）
/**
 * 一、if判断语句：
1.if语句基本结构（花括号内属于if）
int i =0；
if （i＞10）{执行的代码}//不要花括号就识别最近的那一行（无法识别多行）

2.引入不满足else

3.连续判断else if
#include <stdio.h>

int main(void) {
    int score = 85;
    if(score > 90){
        printf("perfect");
    } else if (score >= 70){
        printf("good");
    } else{
        printf("omg");
    }
}
4.if嵌套语句（注意花括号的范围一一对应）
int main(void) {
    int score = 29;
    if(score<60) {//大于60就不必进入这个条件语句了
        if (score > 30) {
            printf("Study C++");
        }else{
            printf("study Py");
        }
    }
}
 */

/**
* 二、分支语句-Switch：更适用于多个分支的语句
 * 1.基本格式：
 * switch（目标）{
 * case 匹配值：
 * 代码
 * break；
 * }
 *2.
 * #include <stdio.h>

int main(void) {
    char c = 'A';
    switch(c){
        case 'A':
            printf("yes");
            break;//每一段都要加break，否则会连续输出下面的值，不会停止
        case 'B':
            printf("no");
            break;
    }
    return 0;
}
 *3.switch的劣势：可以精确判断某个值，但不能进行范围判断
 *4.如果不满足的情况下：用defualt
 * #include <stdio.h>

int main(void) {
    char c = 'D';
    switch(c){
        case 'A':
            printf("yes");
            break;//每一段都要加break，否则会连续输出下面的值，不会停止
        case 'B':
            printf("no");
            break;
        default://后面不用加break了
            printf("0");
    }
    return 0;
}
 *5.在switch中嵌套if(实则有点多余)
 *#include <stdio.h>

int main(void) {
    char c = 'A';
    switch(c){
        case 'A':
            if(c == 'A'){
                printf("omg");
            }
            break;
        case 'B':
            printf("no");
            break;
        default:
            printf("0");
    }
    return 0;
}
 *
*/

/**
* 三、循环语句——for：批量执行代码
 * 1.格式：
 * for(表达式1；表达式2；表达式3){
 * 循环体
 * }
 * 2.相关解释：
 * ①表达式1只会执行一次（赋值）
 * ②表达式2每次循环前都会判断一次（if语句），若不再满足条件，则停止
 * ③表达式3在每次结束后进行一次
 * 3.例子：
 *#include <stdio.h>

int main(void) {
    for (int i = 0; i<4;i++){
        printf("omg\n");//每次都忘记打；
    }//结束循环后后面有代码的话也是可以继续执行的
    return 0;
}
 *4.调试在循环中的使用（小虫虫）：
 * 标红点击小虫虫可进行调试（恢复程序）
 *#include <stdio.h>

int main(void) {
    for (int i = 0; i<4;i++){
        printf("%d\n",i);
    }//结束循环后后面有代码的话也是可以继续执行的
    return 0;
}
 *5.提前结束语break：
 *#include <stdio.h>

int main(void) {
    for (int i = 0; i<10;i++){
        if(i == 5)break;
        printf("%d\n",i);
    }//结束循环后后面有代码的话也是可以继续执行的
    return 0;
}
 *6.加速循环continue：直接开启下一轮，具有就近原则，只加速离自己最近的for循环
 *#include <stdio.h>

int main(void) {
    for (int i = 0; i<8;i++){
        if(i == 5) continue;//结束等于五的这一轮
        printf("%d\n",i);
    }
}
 *7.多变量循环（内部优先循环完）
 * ①continue情况：
 *#include <stdio.h>

int main(void) {
    for (int i = 1; i<4;++i ){
        for (int j = 1; j<4; ++j ) {//for后面没有冒号
            if(i == j) continue;//相等的情况不打印
            printf("%d %d\n",i,j);
        }
    }
}
 *②break情况：
 *#include <stdio.h>

int main(void) {
    for (int i = 1; i<4;++i ){
        for (int j = 1; j<4; ++j ) {
            if(i == j) break;//break触发时直接退出内部循环，从外部循环从头开始
            printf("%d %d\n",i,j);
        }
    }
}
 *
 *
*/

/**
* 四、while循环语句：只需填写循环条件即可
 * 1.while不明确结束的时机（for用于知道要循环多少次）：
 *#include <stdio.h>

int main(void) {
   int i = 100;
   while(i>30){
       printf("%d ",i);
       i /= 2;
   }
}
 *2.while与if的嵌套
 *#include <stdio.h>

int main(void) {
   int i = 100;
   while(i>0){
       if(i <10)break;
       printf("%d ",i);
       i /= 2;
   }
}
 *3.do-while语句：先执行后判断的循环
 *#include <stdio.h>

int main(void) {
   do{
       printf("OK");
   }while(0);
}
 *4.练习：数字的幂：
 *#include <stdio.h>

int main(void) {
    int i =10, res=1;
    for(int j=0 ;j<4;j++){//for的各表达式要用冒号隔开
        res *= i;
    }
    printf("%d",res);
}
 *
 *
*/

/**
* 五、实战:100内寻找水仙花数(ok 自己写不出来。。)
 *①
 * #include <stdio.h>

int main(void) {
    for (int i=0; i<200 ; ++i){
        int a = i % 10 , b = i / 10 % 10 , c= i/100;//难点在于如何把每一位的数取出来
        if(a*a*a+ b*b*b + c*c*c == i){
            printf("%d是水仙花数\n",i);
        }
    }
}
 *
 *
*/

/**
* 六、实战：九九乘法表
 *#include <stdio.h>

int main(void) {
    for(int i=1 ; i<10 ; i++){
        for(int j=1 ; j<10 ; j++){
            if(i < j)break;//为了格式标准化，提前终止程序
            int res = i*j;
            printf(" %d ✖ %d = %2d",i,j,res);//只有一位数时强行占两位数
        }
        printf(" \n");
    }
}
 *
*/

/*
 * 七、斐波那契数列：（黄金分割）
 *#include <stdio.h>

int main(void) {
    int target = 5 , result;
    int a=1 , b=1 ,c;
    for(int i =2; i<target; ++i){
        c = a+b;
        a=b;
        b=c;
    }
    result = c;
    printf("%d",result);
}
 *
 */