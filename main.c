//学习C语言第五天（25/10/21）
/**
* 一、***练习：有两个整数相除，要求不用乘法和除法来计算得到商和余数
//思路：计算机以加法和减法来运算
//如2*3=2+2+2
//11/3=11－3=8－3=5－3=2（此时商就是除以的次数，余数就是最终减到不能再减的结果：已知结束条件用while）
#include <stdio.h>

int main(void) {
    int a = 10;
    int b =3;
    //int res=a;
    int count=0;//count一定要赋予初始值，否则数字随机，虽然++，但是要从哪里++呢？
    while(a >b)
    {
        a = a - b;
        count++;
       // a -= b;
    }
    printf("商为：%d\n",count);
    printf("余数为：%d\n",a);
}
二、do while只用了解理论
1、循环执行流程：
初始化语句
do
{
循环体语句；
条件控制语句；
}while（条件判断语句）；//特征：循环体至少执行一次，先执行后判断
2、练习：打印1－5
#include <stdio.h>

int main(void) {
    int i=1;
    do
    {
        printf("%d\n",i);
        i++;
    }
    while(i<=5);//这里的while后面有分号
    //实际开发中这个循环几乎不用
}

三、循环语句高级之无限循环
1、for格式无限循环：
for( ; ; )
{
print("内容\n")
}
2、while和do while
while（1）（最常用）
3、练习：Ctrl+c中止循环
4、注：无限循环下写代码是没有意义的，循环不结束循环不到
5、无限循环不会单独使用而是和其他的一起运用（如判断语句）

四、跳转控制语句（循环的停止）
1、break：不可单独书写，而是放在switch或循环中表示结束，跳出
#include <stdio.h>

int main(void) {
    for(int i=1; i<=100; i++)
    {
        if(i%3==0 && i%5==0)
        {
            printf("%d",i);
            break;
        }
    }
}
2、continue：结束本次循环，继续下次循环
//一共买了五个包子，吃到第三个包子的时候发现里面有个虫子，不吃这个了，继续吃下一个
#include <stdio.h>

int main(void) {
    for(int i =1; i<=5; i++)
    {
        if(i == 3)//这里误加冒号的话会让后面的无效，还有赋值==（现在会出错但是会很快的检索出来，发现错误了）
        {
            continue;
        }
        printf("在吃第%d个包子\n",i);
    }
}

五、循环的嵌套：先确定内循环发生了什么
1、打印一个3行5列的矩形*)思路跟我想的一样
①
#include <stdio.h>

int main(void) {
    for(int j =1; j<=3; j++);
    {
        for(int i =1; i<=5; i++)
        {
            printf("*");
        }
        printf("\n");
    }
}
2、打印形状
//五行五列倒三角：
#include <stdio.h>

int main(void) {
    for(int j = 1; j<=5;j++)
    {
        for(int i =j; i<=5; i++)//修改内循环，因为它决定了要打几列
        {
            printf("*");
        }
        printf("\n");//打印出一行5列的
    }//打印五行五列的，现每行逐次递减
}

//正三角形（在矩形的基础上进行改写）
#include <stdio.h>

int main(void) {
    for(int j = 1; j<=5;j++)
    {
        for(int i =1; i<=j; i++)//修改内循环，因为它决定了要打几列
        {
            printf("*");
        }
        printf("\n");//打印出一行5列的
    }//打印五行五列的，现每行逐次递增
}

六、九九乘法表：三角形的表
//1、先打印9*9的九九乘法表(正三角形格式)
#include <stdio.h>

int main(void) {
    for(int i=1 ;i<=9;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            printf(" %d × %d=%d\t", j , i, i*j);//只用嵌套(j是横着的数据变化，i是竖着的数据变化)
//\t是制表符，长度可自动变的大空格
        }
        printf("\n");
    }
}

七、制表符\t:大空格，让整体的长度补全达到8或者8的倍数
1、abc\t (补5个)  abcdefgh\t（补8个）一个中文的长度是2
2、作用：让上下文对齐
#include <stdio.h>

int main(void) {
    printf("name\t\tage\n");//为了对齐可重复使用多个\t
    printf("zhangsan\t23\n");
}

八、***练习：统计质数100以内
//质数的概念：只能被1和本身整除
//取出数字

//抽茧剥丝1、判断一个整数是否为质数（任意一个整数，看除了他本身和1之外，还有没有其他可以整除它的数，进行计数判断。没有的话就是植树）
int n=17;
int count;
int countA=0;
for(int i =2; i<=n-1; i++)
{
if(n % i ==0)//若判断是否能被1或者本身整除，就无法排除能被其他数字整除
{
count++；
break；//太妙了！简化了程序，只要找到一个可整除它的数就停止计数
}
if(count==0)
{
printf("Yes");
}
else
{
printf("no");
}

//完整版，范围中统计质数和计数
#include <stdio.h>

int main(void) {
    int countA = 0;
    for(int i =2; i<=100; i++)
    {
        int count=0;//不要忘记赋值
        for (int j = 2; j <=i-1; j++)//修改变量名快捷键两次Ctrl+R
        {
            if (i % j == 0)//若判断是否能被1或者本身整除，就无法排除能被其他数字整除
            {
                count++;
                break;//太妙了！简化了程序，只要找到一个可整除它的数就停止计数
            }
        }
            if (count == 0)
            {
                countA ++;
            }

    }
    printf("%d", countA);
}


九、循环高级之幂级数列：1的1次方+2的2次方+到10的10次方
//拆解：1、一个数的几次方表示（循环累乘）
for(int i =1; i<=10; i++)
{
for(int j=1;j<=10;j++)
{
if(j>i)
{
break;
}
i *=i;
}

//2、次方的累加（运用循环）
#include <stdio.h>

int main(void) {
    long long sum = 0;//最终结果太大，太长
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (j > i)//也可用正三角形法：即j<=i,便可以更简洁的得到想要的程序
            {
                break;
            }
            sum = sum + i * i;
        }
        printf("%d", sum);

    }
}

十、自主练习：
1、0到1000内，符合要求的数字：每一位数字之和等于15：
#include <stdio.h>

int main(void) {
    int count=0;
    int sum=15;
    int res=0;
 for(int i =1; i<=100 ;i++)
 {
     while(i>0)
     {
         res =res + i%10;
         i /=10;
     }
     if(res==sum)
     {
         printf("%d",i);
     }

 }

}
*/