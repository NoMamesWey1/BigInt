#include"BigInt.h"
#include<iostream>
#include<string>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

BigInt::BigInt(){
  digits.push_back(0);
}

BigInt::BigInt(int n)
{
    const int num = 10;
    digits.push_back(n % num);
    n /= num;
    while(n!=0){
        digits.push_back(n % num);
        n /= num;
    }
}

BigInt::BigInt(string num)
{
    for (int i = num.size()-1; i >= 0 ;i--){
      digits.push_back(num[i]-'0');
    }
    
}

bool BigInt::operator<(const BigInt& num) const
{
    if (digits.size() != num.digits.size()){
      if(digits.size() < num.digits.size()){
        return true;
      }
      else{
        return false;
      }
    }
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] != num.digits[i]){
          if(digits[i] < num.digits[i]){
            return true;
          }
          else{
            return false;
          }
        }
    }
}

bool BigInt::operator>(const BigInt& num) const
{
    if (digits.size() != num.digits.size()){
      if(digits.size() > num.digits.size()){
        return true;
      }
      else{
        return false;
      }
    }
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] != num.digits[i]){
          if(digits[i] > num.digits[i]){
            return true;
          }
          else{
            return false;
          }
        }
    }
}

bool BigInt::operator==(const BigInt& num) const
{
    bool ans = false;
    if (digits.size() == num.digits.size())
    {
        ans = true;
        for (int i = 0; i < digits.size(); i++)
            if (digits[i] != num.digits[i]){
                ans = false;
            }
    }
    return ans;
}

bool BigInt::operator==(const int num) const
{
    return (*this) == BigInt(num);
}

bool BigInt::operator<=(const BigInt& num) const
{
    return ((*this) == num || (*this) < num);
}

bool BigInt::operator<=(const int num) const
{
    return (*this) <= (BigInt(num));
}

BigInt BigInt::operator++(int num)
{
    *this = *this + 1;
    return *this;
}

BigInt BigInt::operator+(BigInt num) const
{
    BigInt temp(*this);
    while (temp.digits.size() != num.digits.size()){
      if(temp.digits.size() < num.digits.size()){
        temp.digits.push_back(0);
      }
      else{
        num.digits.push_back(0);
      }
    }
    int a = 0;
    for (int i = 0; i < num.digits.size(); i++) {
        if (temp.digits[i] == 0 && num.digits[i] == 0 && i == a != 0) {
            temp.digits[i] += a;
            a = 0;
        }
        temp.digits[i] += (num.digits[i] + a);
        a = 0;
        if (temp.digits[i] > 9) {
            a++;
            temp.digits[i] %= 10;
            if (i == num.digits.size() - 1)
                temp.digits.push_back(a);
        }
    }
    return temp;
}

BigInt BigInt::operator+(const int num) const
{
    return *this + BigInt(num);
}

BigInt BigInt::operator-(const BigInt num) const
{
    BigInt num1 = (*this);
    BigInt num2 = num;
    BigInt num3 = num1;

    while (num1.digits.size() > num2.digits.size())
        num2.digits.push_back(0);

    for (int i = 0; i < num1.digits.size(); i++) {
        if (num1.digits[i] < num2.digits[i]) {
            num1.digits[i] = num1.digits[i] + 10;
            num1.digits[i + 1] = num1.digits[i + 1] - 1;
        }
        num3.digits[i] = num1.digits[i] - num2.digits[i];
        if (num1.digits[i] == 0 && num2.digits[i] == 0 && i == num1.digits.size() - 1){
          num3.digits.erase(num3.digits.end() - 1);
        }
    }
    return num3;
}

BigInt BigInt::operator-(const int num) const
{
    return *this - BigInt(num);
}

ostream& operator<<(ostream&, BigInt num)
{
    const int len = 12;
    const int len2 = num.digits.size();
    if (len2 > len){
        for (int i = len2 - 1; i >= len2 - (len - 1); i--){
            const int digit = num.digits[i];
            cout << digit;
            if (i == len2 - 1){
             cout << "."; 
            }
        }
        cout << "e" << len2;
    }
    else
    {
        num.print();
    }
    return cout;
}

void BigInt::print()
{
    for(int i = digits.size()-1;i>=0;i--){
      cout<<int(digits[i]);
    }
}
