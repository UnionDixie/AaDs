#pragma once

#include <iostream>
#include <functional>

namespace Math {


template<typename Scalar, typename Func = std::function<Scalar(Scalar)>>
Scalar findRoot(Func f, Scalar x0, int64_t nIter)
{
	Scalar x = x0;
	for (int64_t i = 0; i < nIter; i++) 
		x = f(x);

	return x;
}

template<typename Scalar, typename Func = std::function<Scalar(Scalar)>>
Scalar findRootDiv(Func f, Scalar a, Scalar b, Scalar dx)
{
	Scalar x = (a + b) / 2;
	while ((b-a) / 2 > dx)
	{
		if (f(a) == 0)
			return a;
		if (f(b) == 0)
			return b;
		if (f(x) == 0)
			return x;
		if (f(a) * f(x) > 0)
			a = x;
		else
			b = x;
		x = (a + b) / 2;
	}

	return x;
}


template<typename Scalar, typename Func = std::function<Scalar(Scalar)>>
Scalar findRootNewton(Func f, Scalar x0, int64_t nIter)
{
	const Scalar eps = 1e-6;
	auto diff = [=](Scalar x_i) {
		return (f(x_i + eps) - f(x_i)) / eps;
	};

	Scalar x = x0;
	for (int64_t i = 0; i < nIter; i++)
		x = x - f(x) / diff(x);

	return x;
}

void start()
{
	auto f = [] (double x) {
		return 0.5f * std::cos(x);
	};
	std::cout << findRoot<double>(f, 0, 100) << "\n";

	auto f1 = [](double x) {
		return 0.5f * std::cos(x) - x;
	};
	std::cout << findRootDiv<double>(f1, 0, 1, 1e-3) << "\n";

	std::cout << findRootNewton<double>(f1, 0, 3) << "\n";



}


}