#ifndef BIGINT_H
#define BIGINT_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

class BigInt{
private:
    vector<char> digits;
public:
    BigInt();
	  BigInt(int n);
	  BigInt(string num);
	  BigInt operator+(BigInt num) const;
	  BigInt operator+(int num) const;
	  BigInt operator++(int num);
	  BigInt operator-(BigInt num) const;
	  BigInt operator-(int num) const;
	  bool operator==(const BigInt& num) const;
	  bool operator==(int num) const;
	  bool operator<(const BigInt& num) const;
    bool operator>(const BigInt& num) const;
	  bool operator<=(const BigInt& num) const;
	  bool operator<=(int num) const;
	  friend ostream& operator<<(ostream&, BigInt num);
	  void print();
};
#endif