//C语言第17天（25/11/11）
#include <stdio.h>
#include <string.h>

int main(void) {

}

/**
* 一、字符串实战1：用户名登陆
 *#include <stdio.h>
#include <string.h>

int main(void) {
    //每个用户输入自己的用户名和密码，三次机会
    //1、定义正确的用户名和密码
    char* rightUserName = "lixiang" ;
    char* rightUserCode = "123456" ;
    //2、三次输入用户和密码的机会
    for(int i = 1 ; i <= 3 ; i++) {//应写<=而不是=<

        //定义可修改字符串数组
        char name[100];
        char code[100];
        printf("请输入用户名：");
        fflush(stdout) ;
        scanf("%s", name);//这里注意字符串不需要地址符，否则黄色警告
        printf("请输入密码：");
        fflush(stdout) ;
        scanf("%s", code);
        printf("您输入的用户为：%s\n", name);
        printf("您输入的密码为：%s\n", code);
        //对结果进行一个判断：这里运用的是字符串之间的比较函数strcmp
        if (!strcmp(rightUserName, name) && !strcmp(rightUserCode, code))//为1才执行，cmp相等时为0，所以要用非！
        {
            printf("登陆成功！\n");
            break; //直接跳出循环
        }
            //本次登录失败
            //这里用else if不好写，因为没有其他更明确的条件来表达这个情况
        else//直接分为成功和失败
        {
            if (i == 3) {
                printf("请用户%s联系平台的专业人员\n", name);
            } else {
                printf("还有%d次机会\n", 3 - i);
            }
        }
    }

    }

*/

