# 题目 A

## 题目描述
[在此填写题目描述]
![alt text](assets/README/image.png)
## 解题思路
![alt text](assets/README/image-1.png)
1. 简单的排列组合问题
2. 逆向思维
3. 先求满足6的，然后再拿总数去减
4. 取模的时候，需要加mod 然后整体取模，避免出现负数的情况
5.   cout<<(ksm(27LL,n)%MOD-ksm(7LL,n)%MOD+MOD)%MOD<<endl;