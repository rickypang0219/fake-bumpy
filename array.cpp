#include "array.h"

Array::Array()
{
}

Array::Array(const std::vector<float>& values)
    : data(values)
{
}

int Array::size() const
{
    return static_cast<int>(data.size());
}

double Array::get(int index) const
{
    if (index >= 0 && index < size()) {
        return data[index];
    }
    throw std::out_of_range("Index out of range");
}

void Array::set(int index, float value)
{
    if (index >= 0 && index < size()) {
        data[index] = value;
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

Array Array::add(const Array& other) const
{
    if (size() != other.size()) {
        throw std::runtime_error("Arrays must have the same size for addition");
    }

    std::vector<float> result;
    result.reserve(size());

    for (int i = 0; i < size(); ++i) {
        result.push_back(data[i] + other.data[i]);
    }

    return Array(result);
}
