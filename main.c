//C语言第八天（25/10/24）难度升级，进度放缓
#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int contains(int arr[], int len ,int num);
int main(void) {

    int arr[10] = {0};
    int len = sizeof(arr) / sizeof(int);
    srand(time(NULL));
    for (int i = 0; i < len;) {
        int num = rand() % 100 + 1;
//在把数字放入数组前进行判断是否重复，重复则不放入
        int flag = contains(arr, len, num);
        if (!flag)//表示flag不存在，也可以写作flag==0
        {
            arr[i] = num;//此时若不成立，则会跳过这一轮，数据默认值为0，范围小时仍然会重复
            i++;//因此把i++移动到下方，满足条件才++

        }
    }
    int sum = 0;
    for (int i; i < len; i++) {
        sum = sum + arr[i];
    }
    printf("%d\n", sum);
//求平均数
    int avg = sum / len;
    printf("%d\n", avg);
//统计有多少个数字比平均数小
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] < avg) {
            count++;
        }
    }
    printf("%d\n", count);
}//最容易错且不好修改的是这种差括号

    int contains(int arr[], int len ,int num)//进行一个比较判断
    {
        for (int i = 0; i < len; i++) {
            if (arr[i] == num) {
                return 1;
            }
        }
        return 0;//表示不存在
    }
/**
* 数组算法题合集
一、***求最值：找出数组中的最大值
//1、max的默认值是0索引开始，那么循环其实可以从1开始索引
//2、max的值不应该定为0，否则数组中若有负数则无法显现。所以max的初始默认值应该为数组中的一个值
#include <stdio.h>
#include<stdlib.h>

int main(void) {
    //定义一个数组
    int arr[] = {33,5,22, 44,55};//数组后面必须要加[],否则后续的对应符号会错误
//定义一个max
    int max = arr[0];//索取首地址的临时最大值
//遍历数组每一个元素
    int len = sizeof(arr) / sizeof(int);//想到计算长度这一步没问题
    for(int i = 0; i< len; i++)//遍历
    {
//根据条件判断，有更大的值出现就替换
        if(max < arr[i])//怎么表示所遍历到的这个数？？
//喔喔，i是索引，所以直接用i
        {
            max = arr[i];
        }
    }
    printf("最大值为：%d\n",max);
}

二、遍历数组并求和
1、生成十个1~100间的随机数，求出所有数据的和：
//生成十个随机数存入数组中，是否可以写函数然后在花括号内调用函数
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {


//定义数组：
    int arr[10] = {0};
//具体数据未知，但是知道长度，所以先写入长度10；然后默认值0，表示整数形式，其余值都是0。若填入1，则第一位为1，后面全是0。
//计算长度：
    int len = sizeof(arr) / sizeof(int);
    int sum = 0;
//生成十个1到100的随机数，然后放入数组中
    srand(time(NULL));
    for(int i = 0; i<len; i++)
    {
        int num = rand() %100 +1;//多次取随机数
        arr [i] =num;//数组赋值直接用数组中的一个单位来相等赋值
        printf("%d\n",arr[i]);
        sum = sum +arr[i];

    }
    printf("%d\n",sum);//尽量还是使用一个循环就行，不然sum永远是0
//把这十个数累加起来求和

}

2、生成十个1~100的随机数且不能重复
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int contains(int arr[], int len ,int num);
int main(void) {

    int arr[10] = {0};
    int len = sizeof(arr) / sizeof(int);
    srand(time(NULL));
    for (int i = 0; i < len;) {
        int num = rand() % 100 + 1;
//在把数字放入数组前进行判断是否重复，重复则不放入
        int flag = contains(arr, len, num);
        if (!flag)//表示flag不存在，也可以写作flag==0
        {
            arr[i] = num;//此时若不成立，则会跳过这一轮，数据默认值为0，范围小时仍然会重复
            i++;//因此把i++移动到下方，满足条件才++
        }
    }
    int sum = 0;
    for (int i; i < len; i++) {
        sum = sum + arr[i];
    }
    printf("%d\n", sum);
//求平均数
    int avg = sum / len;
    printf("%d\n", avg);
//统计有多少个数字比平均数小
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] < avg) {
            count++;
        }
    }
    printf("%d\n", count);
}//最容易错且不好修改的是这种差括号

    int contains(int arr[], int len ,int num)//进行一个比较判断
    {
        for (int i = 0; i < len; i++) {
            if (arr[i] == num) {
                return 1;
            }
        }
        return 0;//表示不存在
    }

三、反转数组：
1、键盘录入五个数据：遍历数组；翻转数组；再次遍历
void printfArr(int arr[], int len);
//定义数组
int arr[5]= {0};
//键盘录入
int len = sizeof(arr[]) / sizeof(arr[0]);
for(int i; i<len; i++)
{
printf("请输入第%d个数据：",i+1)；//加一避免第0个
scanf("%d\n",&arr[i]);
}
pritnfArr(arr , len);
//***遍历原数组数据（这个循环反复使用，因此引入函数）
//***翻转数组:i 和j如何同时变化呢
int i =0;
int j =len-1;//最末尾
while(i < j)
{
int temp = arr[i];//把i位先取出来
arr[i] = arr[j];
arr[j] = temp;//最后赋值给j
i++;
j--;
}
pintfArr(arr,len);

void printfArr(int arr[], int len)
{
for(int i; i<len; i++)
{
printf("%d\n",arr[i]);
}
}

四、***打乱数组中所有数的数据：
//1、定义一个数组：1到5
int arr[] = {1,2,3,4,5}；
int len =sizeof(arr) /sizeof(int);
//取随机的索引：1到5之间
//5 + 1
srand(time(NULL));
for(i = 0; i< len ; i++)
{
int index = rand() % len;//为啥不避免取索引重复的情况？（0到4）
//打乱的实质是交换数据
int temp = arr[i];
arr[i] = arr[index];
arr[index] = temp;
}

五、数组的常见算法：
1、基本查找/顺序查找:从0依次往后查找，找到后返回索引的值，没找到就返回－1
int order(int arr[] , int len , int num);
//定义数组：
int arr[] = {11,22,98,63,54};
int len = sizeof(arr) / sizeof(int);
int num = 63;
int index = order(arr,len,num);
printf("%d\n",index);
;
//创造一个查找函数：
int order(int arr[] , int len , int num)
{
for(i = 0; i<len; i++)
{
if(arr[i] == num)
{
return i;//返回的是索引值
}
return -1;
}
*/

/**
* 六、***二分查找/折半查找：前提；数据必须是有序的（从小到大或从大到小）
 * 核心逻辑：每次排除一半的查找范围
 * 寻找一个存在的数的索引
 * 1、min和max表示查找范围
 * 2、mid处于两者中间（C语言不讲究四舍五入）
 * 3、查找元素在mid（索引）左边，则去掉右边，max变为mid-1
 * 4、查找元素在mid（索引）右边，则去掉左边，min变为mid+1
 * 寻找一个不存在的值：一直推移直到出范围
 *#include <stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int len, int num);
int main(void) {
    //1、定义数组
    int arr[] = {7, 23, 79,81, 103, 127, 131, 147};
    int len = sizeof(arr) / sizeof(arr[0]);
    //2、要查询的数据
    int num = 131;
    //3、调用函数查找
    int index = binarySearch( arr, len, num);
    printf("%d\n",index);
}
//函数的创建：二分查找法
//找到了就是真实索引
//没找到输出-1
int binarySearch(int arr[], int len, int num)
{
    int min =0;
    int max = len - 1;
    while(min <= max)
    {
        int mid = (min + max) / 2;
        //把具体的数据值进行比较
        if(arr[mid] > num)
        {
            max = mid - 1;
        }//说明数字在mid左边，此时砍掉右半边，max变化
        else if(arr[mid] < num)
        {
            min = mid + 1;
        }
        else
        {
            return mid;//最终要的是mid（索引的值）
        }
    }
    return -1;//表示未找到
}
 *
*/

/**
* 七、二分查找的改进：太长时一直找中间值需要循环多次==插值查找
 *要求数据分布要均匀一些，恭喜做出来了，啊哈哈哈
 * #include <stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int len, int num);
int main(void) {
    //1、定义数组
    int arr[] = {1,2,3,4,5,6,7,8};
    int len = sizeof(arr) / sizeof(arr[0]);
    //2、要查询的数据
    int num = 8;//不规则的数据，有时候查找对有时候不对
    //3、调用函数查找
    int index = binarySearch( arr, len, num);
    printf("%d\n",index);
}
//函数的创建：二分查找法
//找到了就是真实索引
//没找到输出-1
int binarySearch(int arr[], int len, int num)//运用插值查找
{
    int min =0;
    int max = len - 1;
    int mid = min + (num - arr[min]) * (max - min)/ (arr[max] - arr[min]);//应先乘后除，因为乘是乘在分母上，否则答案不对
        //把具体的数据值进行比较
    if(mid < max+1)//还可以等于max
    {
    return mid;
    }
    return -1;//表示未找到
}
*/

/**
* 八、查找算法：
 * 1、分块查找（暂时了解思路即可）
 * 分块原则：
 * （1）前一块中的最大数据小于后一块中的所有数据（块内无序，块间有序）
 * （2）一般分为平方根个大块
 * 在块中进行依次寻找
 * 二分查找法先确定块，再依次遍历
 *2、不规律分块查找：
 * 此时分块更有讲究：每块数据不可有交集
 *
*/