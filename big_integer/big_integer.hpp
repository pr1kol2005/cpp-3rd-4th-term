#pragma once

#include <algorithm>
#include <compare>
#include <cstdint>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

class BigInt {
 public:
  BigInt() = default;
  BigInt(int64_t num);
  BigInt(const std::string& str);
  BigInt(const BigInt& other);
  BigInt(BigInt&& other) = default;

  BigInt& operator=(const BigInt& rhs);

  ~BigInt() = default;

  BigInt operator+(const BigInt& rhs) const;
  BigInt operator-(const BigInt& rhs) const;
  BigInt operator*(const BigInt& rhs) const;
  BigInt operator/(const BigInt& rhs) const;
  BigInt operator%(const BigInt& rhs) const;

  BigInt& operator+=(const BigInt& rhs);
  BigInt& operator-=(const BigInt& rhs);
  BigInt& operator*=(const BigInt& rhs);
  BigInt& operator/=(const BigInt& rhs);
  BigInt& operator%=(const BigInt& rhs);

  bool operator==(const BigInt& rhs) const = default;
  std::strong_ordering operator<=>(const BigInt& rhs) const;

  BigInt& operator++();
  BigInt& operator--();
  BigInt operator++(int);
  BigInt operator--(int);

  BigInt operator-() const;

  friend std::ostream& operator<<(std::ostream& out, const BigInt& rhs);
  friend std::istream& operator>>(std::istream& in, BigInt& rhs);

 private:
  int64_t GetRowsSum(const BigInt& rhs, bool addition, std::size_t i);
  BigInt& AbsSubstraction(const BigInt& rhs);
  BigInt Abs() const;
  void ReverseBothDigits(const BigInt& rhs);
  void RemoveZeros();
  void Divide(const BigInt& rhs, bool is_module);

  bool is_positive_;
  std::vector<int8_t> digits_;
  static const int8_t kBase = 10;
  static const std::string kInt64MinStr;
};
