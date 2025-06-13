#include<iostream>
#include<cstdio>
#include <vector>
using namespace std;
// 暴力解法
void solution(const vector<char>& a){
    int maxnum = 0;
    char result = a[0];
    int num = 0;
    for(int i=0;i<a.size();i++){
        num = 0;
        for(int j=0;j<a.size();j++){
            if(a[i] == a[j]) num++;
        }
        if(num>maxnum){
             maxnum = num;
             result = a[i];
        }
    }
    cout << "The most frequent character is: " << result << ",the most frequent is" << maxnum << endl;
}
// 以空间换时间
void solution2(const vector<char>& a){
    int temp[26] = {0};
    for(int i = 0; i < a.size(); i++){
        int index = a[i] - 'a';
        temp[index]++;
    }
    int maxIndex = 0;
    for(int i = 1;i<26;i++){
        if(temp[i]>temp[maxIndex])maxIndex = i;
    }
    cout << "The most frequent character is: " << maxIndex+'a' << ",the most frequent is" << temp[maxIndex] << endl;
}