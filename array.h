#pragma once
#include <vector>

// Array class
class Array{
public:
  Array();
  explicit Array(const std::vector<float> &values);

  int size() const ;
  double get(int index) const;
  void set(int index, float value);
  Array add(const Array& other) const;

private:
  std::vector<float> data;
};
