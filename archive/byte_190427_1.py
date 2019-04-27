'''
题目描述
母牛从3- 7岁初每年会生产1头小母牛，10岁后死亡(10岁仍然存活)。假设初始有1头刚出生的母牛，请问第n年有多少头母牛? (年从第一 年开始计数)
注:
第3年初会出生第一头牛，故第三年有两头母牛
第5年初第3年出身的牛会生产，故第五年有5头母牛。
岁数是虚岁

输入描述:
输入一个正整数表示n年

输出描述:
一个数字，表示第
n年有多少头牛

1
1

3
2

5
5
'''


def main():
    n = int(input())
    arr = [1] + [0 for i in range(9)]
    for i in range(n-1):
        tmp = sum(arr[1:6])
        for j in range(9, 0, -1):
            arr[j] = arr[j-1]
        arr[0] = tmp
    print(sum(arr))


if __name__ == "__main__":
    main()