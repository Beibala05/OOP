#ifndef POLYNOMAL
#define POLYNOMAL

#include <vector>
#include <cstddef>
#include <ostream>

struct Polynomal
{
	Polynomal();
	Polynomal(const Polynomal& other);
	Polynomal(Polynomal&& other) 								    noexcept;
	Polynomal(std::vector<double> other_numbers);
	Polynomal(std::initializer_list<double> list);


	Polynomal& 			    operator =  (const Polynomal& other);
	Polynomal& 			    operator =  (Polynomal&& other);
	Polynomal& 			    operator += (const Polynomal& other);
	Polynomal& 			    operator -= (const Polynomal& other);
	Polynomal& 			    operator *= (const Polynomal& other);
	Polynomal 			    operator +  (const Polynomal& other)	    const;
	Polynomal 			    operator -  (const Polynomal& other)	    const;
	Polynomal 			    operator *  (const Polynomal& other)	    const;
	Polynomal& 			    operator += (double scalar);              
	Polynomal& 			    operator -= (double scalar);
	Polynomal& 			    operator *= (double scalar);
	Polynomal 			    operator +  (double scalar)					const;
	Polynomal 			    operator -  (double scalar)					const;
	Polynomal 			    operator *  (double scalar)					const;
	bool 				    operator == (const Polynomal& other)	    const;
	bool 				    operator != (const Polynomal& other)	    const;
	double 				    operator () (double x)						const;

	Polynomal 			    derivative() 								const;
	Polynomal 			    integral() 									const;

	size_t				 	size()									    const;
	std::vector<double> 	get_numbers() 							    const;
		

private:
	std::vector<double> 	numbers;
};

Polynomal operator+(double scalar, const Polynomal& obj) { return obj + scalar; }
Polynomal operator-(double scalar, const Polynomal& obj) { return obj - scalar; }

std::ostream& operator << (std::ostream& os, const Polynomal& numbers);

#endif // POLYNOMAL