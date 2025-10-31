//C语言第13天（25/10/31）
#include <stdio.h>

int main(void) {

        // 用方式一定义
        int arr[2][3] = {
                [0] = {[0] = 1, [1] = 2, [2] = 3},
                [1] = {[0] = 11, [1] = 22, [2] = 33}
        };

        // 遍历数组
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }

        return 0;

}

/**
* 一、数组指针的细节
 * 1、arr参与计算的时候 会退化为第一个元素的首地址（指针的内存）
 * 2、但有特殊情况
 *#include <stdio.h>

int main(void) {
    //定义一个数组
    int arr[] = {1, 3 , 5, 7 , 9} ;
    //当arr计算长度时是一个整体
    int len = sizeof(arr) / sizeof(int) ;
    printf("%d\n" , len) ;
    //当arr单独出现时是一个整体
    printf("%zu\n" , sizeof(arr)) ;
    //&arr获取地址时，不会退化，即使是在运算中
    printf("%p\n" , arr) ;
    printf("%p\n" , &arr) ;//两者都是首地址
    printf("%p\n" , arr + 1) ; //一步跳跃对应的数据类型
    printf("%p\n" , &arr + 1) ;//一步跳跃整体
//学会用电脑calc计算十六进制跳跃了几步
}
*/

/**
* 二、用&arr遍历多维数组
 * 1、什么是二维数组：小数组放在大数组中
 * //方式1
 * arr[m][n] =
 * {
 * {1,2,3,4},
 * {5,6,7,8},
 * };
 * //方式2
 * int arr1[4] = {1,2,3,4};
 * int arr2[4] = {1,2,3,4};
 * int* arr[2] = {arr1 , arr2} ;
 *
 *
 *#include <stdio.h>

int main(void) {

        // 用方式一定义
        int arr[2][3] = {
                [0] = {[0] = 1, [1] = 2, [2] = 3},
                [1] = {[0] = 11, [1] = 22, [2] = 33}
        };

        // 遍历数组
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }

        return 0;

}
*/

/**
 * 三、长度不同时通过索引遍历
* #include <stdio.h>

int main(void) {
  //当长度不一样时，使用方法二
  int arr1[3] = {1 , 2, 3} ;
  int arr2[4] = {1 , 2, 3 , 4} ;
  int len1 = sizeof(arr1) / sizeof(int) ;
  int len2 = sizeof(arr2) / sizeof(int) ;
  //将len设为数组
  int len[2] = {len1 , len2 };//这里面包含的整数
  //二维数组定义
  int* arr[2] = {arr1 , arr2} ;//不再是整数，而是存的指针指向各个以为数组的首地址
  //循环索引遍历
  for(int i = 0 ; i < 2 ; i++)//记得确认i的范围
  {
      for(int j = 0 ; j < len[i] ; j++)
      {
          printf("%d " , arr[i][j]) ;
      }
      printf("\n") ;
  }
}
*/
