// huangshize 2016.03.29
// === math_function.cpp ===

#include "math_functions.h"

template <>
float jaffe_asum<float>(const int n, const float* x) {

	return 0;  // 未完成
}

template <>
double jaffe_asum<double>(const int n, const double* x) {
	return 0;  // 未完成
}

template <>
void jaffe_axpy<float>(const int n, const float alpha, const float* x, const float* y)
{

}

template <>
void jaffe_axpy<double>(const int n, const double alpha, const double* x, const double* y)
{

}

template <>
void jaffe_scale<float>(const int n, const float alpha, const float* x)
{

}

template <>
void jaffe_scale<double>(const int n, const double alpha, const double* x)
{

}
