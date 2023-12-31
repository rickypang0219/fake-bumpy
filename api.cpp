#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "array.h"
#include <string>

namespace py = pybind11;

PYBIND11_MODULE(myapi, m) {
    py::class_<Array>(m, "Array")
        .def(py::init<>())
        .def(py::init<const std::vector<float>&>())
        .def("size", &Array::size)
        .def("get", &Array::get)
        .def("set", &Array::set)
        .def("add", &Array::add)
        .def("__getitem__", [](const Array& arr, int index) {
            if (index >= 0 && index < arr.size()) {
                return arr.get(index);
            }
            throw py::index_error("Index out of range");
        })
        .def("__setitem__", [](Array& arr, int index, float value) {
            if (index >= 0 && index < arr.size()) {
                arr.set(index, value);
            }
            else {
                throw py::index_error("Index out of range");
            }
        })
        .def("__len__", &Array::size)
        .def("__add__", &Array::add)
        .def("__sub__", [](const Array& arr1, const Array& arr2) {
            if (arr1.size() != arr2.size()) {
                throw std::runtime_error("Array sizes do not match");
            }
            Array result(arr1);
            for (int i = 0; i < result.size(); ++i) {
                result.set(i, result.get(i) - arr2.get(i));
            }
            return result;
        })
        .def("__mul__", [](const Array& arr, int factor) {
            Array result(arr);
            for (int i = 0; i < result.size(); ++i) {
                result.set(i, result.get(i) * factor);
            }
            return result;
        })
        .def("__repr__", [](const Array& arr) {
            std::string repr = "[";
            for (int i = 0; i < arr.size(); ++i) {
                repr += std::to_string(arr.get(i));
                if (i < arr.size() - 1) {
                    repr += ", ";
                }
            }
            repr += "]";
            return repr;
        });
}
