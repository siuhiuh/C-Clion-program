//C语言第四天（25/10/20）
/**
* 一、循环小案例：
1、正向反向输出：
(1)1到5进行输出：开始条件；结束条件；重复执行的事；每次循环后 i如何改变。
 #include <stdio.h>

int main(void) {
for(int i =1; i<=5 ; i++)
{
printf("%d\n",i);
}
}

(2)5到1反向输出：
 #include <stdio.h>

int main(void) {
for(int i =5 ; i>=1 ; i--)
{
printf("%d\n",i);
}
}

2.求和（累加，循环外定义一个初始变量）：
先获取每个数，设一个变量0
 #include <stdio.h>

int main(void) {
int sum = 0;//定义用来累加的变量
for(int i = 1; i<=5 ;i++)
{
sum += i;
}
printf("%d", sum);//只取结果的做法
}


二、深入：变量的生命周期（变量只在所属大括号内有效）
1、属于if的大括号中：
 #include <stdio.h>

int main(void) {
if(1)
{
int a= 10;
}
printf("%d",a);//出大括号后变量a的值消失
}


2、属于main的大括号：均存在

3、练习：
 #include <stdio.h>

int main(void) {
if(1)
{
int a= 10;
printf("%d",a);
}
int a= 15;
printf("%d",a);//大括号后a变为一个新的变量
}


4、一些疑惑解答（出括号变量从程序中消失）：
 #include <stdio.h>

int main(void) {
for(int i =1 ;i<=5 ; i++)
{
int sum =0;
sum +=i;
printf("%d",sum);
 }//每次都全新变量，因此累加变量设在最外面
}



三、符合条件的求和：0到100的偶数和
 #include <stdio.h>

int main(void) {
int  sum=0;
for(int i =0;i<=100; i++)//取出1到100的数
{
if(i%2 == 0)//判断是否为偶数（想到多少写多少），双等号才是判断等于，单等号是赋值
{
sum +=i;
}
}
printf("%d",sum);
}


四、统计满足条件的数字的个数：键盘录入两个数字表示范围，统计范围中既能被6整除，又能被8整除的数字有多少个：（scanf）
//忽略了用scanf录入的步骤
 #include <stdio.h>

int main(void) {
int num1;
int num2;
printf("请输入两个数字：\n");
scanf("%d %d",&num1,&num2)//别忘记取地址符&
//判断num1和2的大小（否则出错）
int min = num1 < num2 ? num1 : num2;
int max = num1 > num2 ? num1 : num2;
int count = 0；
for(i=min; i<=max ;i++)//改成min和max
{
if(i %6==0 && i %8==0 )//ok，同时满足就是这样写
{
count +=1;//或count++
}
}
printf("%d",count);
}

思维：写完后输入一些特殊的数据，修复bug.代码不可能一次性写完整

五、while循环：
1、基本结构：
初始化语句
while（条件判断语句）
{
循环体语句
条件控制语句
}

2、while的简单运用：
 #include <stdio.h>

int main(void) {
int i = 1;
while(i <= 4)
{
printf("超级嵌入式开发工程师就是我！");//循环语句
i++;//条件控制语句
}
}


六、for和while的对比：
1、唯一的小区别：for中的控制循环的变量i，在for结束后无法被调出（i在for中定义）
但while1中的循环变量，循环结束后仍可继续使用
2、真正的区别（适用范围）：（for）知道循环次数或范围。（while）只知道结束条件，不知道循环次数和范围
3、举例：
（1）求和1到100（明确的范围）：for
（2）读取文件中的内容（用的是循环，一次读取一个字）：while一直读到末尾

七、循环算法题练习：
1、***一个整数n，判断她是否时二的幂次方：
 #include <stdio.h>

int main(void) {
int n;
ptintf("请输入一个整数：")
scanf("%d",&n);
//循环用while：满足条件，循环才进行，则与结束条件反过来
//结束条件：（1）结果是1时结束，（整除余1），yes（2）结果无法被2整除，no
while(i>1 && i %2 ==0);//不知道除多少次，只知道结束条件，用while
{
n = n/2;
}
if(n == 1)
{
printf("yes");
}
else
{
printf("no");
}
}

2、折叠纸张，多少次能达到珠穆朗玛峰高度
 #include <stdio.h>

int main(void) {
//（1）定义纸的的厚度和珠穆朗玛峰高度
double a = 0.1;
int h = 8844430;
int count =0;
//(2)循环结束条件，累次乘以2，最终达到珠穆朗玛峰高度
while(a <=8844430)
{
a *=2;
count++;
}
printf("%d",count);
}

3、***将一个整数进行反转：思路，把每个数取出来，再拼接
 #include <stdio.h>

int main(void) {
int a= 123;
int res = 0;//反转结果
//从右依次取出每位数
while(a != 0)//只要这个数不为0
{
int c = a % 10;
a /=10;//除去一位
res =  res*10 + c;//组合起来
}
printf("%d",res);
}

4、***一个非负整数x，计算并返回x的算数平方根。保留只保留整数部分被舍去。
 #include <stdio.h>

int main(void) {
//重点思路：从1*1开始逐渐增大，直到平方大于x的值（有了这个思路就能自己写了）
int x = 8;
int i = 1；
while(i*i <= x )//一定要等于这个数字吗，不等于的话循环i++不会执行
{
i++;
}
printf("%d",i－1);
}

5、判断一个整数是否为回文数：从左从右读都是同一个数字121
 #include <stdio.h>

int main(void) {
int number = 12321;
int org = number;
int res = 0;
while(number !=0)
{
int c =number %10;
res = res*10 + c;
number /= 10;
}
if(res == org)
{
printf("yes");
}
else
{
printf("no");
}

}//此处有个很大的问题，1、首先是把else 和else if搞混了（else if要判断条件才可使用）
 //2、双等号才是等于，一开始只用了单等号，导致直接强行让两者相等了，只输出yes。No变灰。
*/