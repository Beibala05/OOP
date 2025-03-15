#include "polynomal.h"

#include <cmath>
#include <iostream>

Polynomal::Polynomal()
{
	numbers.push_back(0.0);
}

Polynomal::Polynomal(std::vector<double> other_numbers)
{
	numbers = other_numbers;
}

Polynomal::Polynomal(const Polynomal& other)
{
	numbers = other.get_numbers();
}

Polynomal::Polynomal(Polynomal&& other) noexcept
{
	numbers = std::move(other.get_numbers());
}

Polynomal::Polynomal(std::initializer_list<double> list)
{
	for (double i : list)
	{
		numbers.push_back(i);
	}
}

Polynomal& Polynomal::operator=(const Polynomal& other)
{
	numbers = other.get_numbers();

	return *this;
}

Polynomal& Polynomal::operator=(Polynomal&& other)
{
	numbers = std::move(other.get_numbers());

	return *this;
}

Polynomal Polynomal::operator+(const Polynomal& other) const
{
	std::vector<double> result(std::max(this->size(), other.size()));

	for (int i = 0; i < result.size(); ++i)
	{
		if (i < this->size())
		{
			result[i] += this->get_numbers()[i];
		}

		if (i < other.size())
		{
			result[i] += other.get_numbers()[i];
		}
	}

	return Polynomal(result);
}

Polynomal Polynomal::operator-(const Polynomal& other) const
{
	std::vector<double> result(std::max(this->size(), other.size()));

	for (int i = 0; i < result.size(); ++i)
	{
		if (i < this->size())
		{
			result[i] += this->get_numbers()[i];
		}

		if (i < other.size())
		{
			result[i] -= other.get_numbers()[i];
		}
	}

	return Polynomal(result);
}

Polynomal Polynomal::operator*(const Polynomal& other) const
{
	std::vector<double> result(this->size() + other.size() - 1);

    for (size_t i = 0; i < this->size(); ++i) 
    {
        for (size_t j = 0; j < other.size(); ++j) 
        {
            result[i + j] += this->get_numbers()[i] * other.get_numbers()[j];
        }
    }

	return Polynomal(result);
}

Polynomal& Polynomal::operator+=(const Polynomal& other)
{
	*this = *this + other;
	return *this;
}

Polynomal& Polynomal::operator-=(const Polynomal& other)
{
	*this = *this - other;
	return *this;
}

Polynomal& Polynomal::operator*=(const Polynomal& other)
{
	*this = *this * other;
	return *this;
}

Polynomal Polynomal::operator+(double scalar) const
{
	std::vector<double> result;

	for (auto& element : numbers)
	{
		result.push_back(element);
	}

	result.at(result.size() - 1) += scalar;

	return Polynomal(result);
}

Polynomal Polynomal::operator-(double scalar) const
{
    return *this + (-scalar);
}

Polynomal Polynomal::operator*(double scalar) const
{
	std::vector<double> result;

	for (auto& element : numbers)
	{
		result.push_back(element * scalar);
	}

	return Polynomal(result);
}

Polynomal& Polynomal::operator+=(double scalar)
{
	*this = *this + scalar;
	return *this;
}

Polynomal& Polynomal::operator-=(double scalar)
{
	*this = *this - scalar;
	return *this;
}

Polynomal& Polynomal::operator*=(double scalar)
{
	*this = *this * scalar;
	return *this;
}

bool Polynomal::operator==(const Polynomal& other) const
{
	return this->get_numbers() == other.get_numbers();
}

bool Polynomal::operator!=(const Polynomal& other) const
{
    return !(*this == other);
}

double Polynomal::operator()(double x) const
{
	double result = 0.0;

	for (int i = 0; i < numbers.size(); ++i)
	{
		result += (pow(x, numbers.size() - i - 1) * numbers[i]);
	}

	return result;
}

std::vector<double> Polynomal::get_numbers() const
{
	return numbers;
}

size_t Polynomal::size() const
{
	return numbers.size();
}

Polynomal Polynomal::derivative() const 
{
	if (numbers.size() == 0 || numbers.size() == 1) return Polynomal();

    std::vector<double> result;

	for (int i = 0; i < numbers.size() - 1; ++i)
	{
		result.push_back(numbers[i] * (numbers.size() - i - 1));
	}

	return Polynomal(result);
}

Polynomal Polynomal::integral() const
{
	if (numbers.size() == 0 || numbers.size() == 1) return Polynomal();

	std::vector<double> result;

	int j = numbers.size();

	for (int i = 0; i < numbers.size(); ++i)
	{
		result.push_back(numbers[i] / j);
		j--;
	}

	result.push_back(0);
	
	return Polynomal(result);
}

std::ostream& operator<<(std::ostream& os, const Polynomal& numbers)
{
    for (int i = 0; i < numbers.size(); ++i)
    {
        os 
        << (numbers.get_numbers()[i] >= 0 ? " + " : " - ") 
        << std::abs(numbers.get_numbers()[i])
        << "x^" 
        << numbers.size() - i - 1;
    }

    return os;
}


int main()
{
    Polynomal d({6, 3, 2});

    d -= 1.0;

    std::cout << d << std::endl;

    std::cout << "derivative: " << d.derivative().integral() << std::endl;


    return 0;
}