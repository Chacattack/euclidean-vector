#ifndef EUCLIDEANVECTOR_H
#define EUCLIDEANVECTOR_H

#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <cmath>

namespace cs6771 {
	class EuclideanVector {
	private:
		std::vector<double> v;
		int dimensions;
        
	public:
		EuclideanVector(int i); //default constructor given dimension of vector
        EuclideanVector(double i); //default constructor given dimension of vector as a double
        EuclideanVector(unsigned int i); //default constructor given dimension of vector as an unsigned int
        
		EuclideanVector(int d, double m); //default constructor given magnitude of each dimension
        EuclideanVector(int d, int m); //constructor for given 2 ints instead of int double
        EuclideanVector(int d, unsigned int m); //constructor for given 2 ints instead of int double
        EuclideanVector(unsigned int d, double m); //constructor for given 2 ints instead of int double
        EuclideanVector(unsigned int d, int m); //constructor for given 2 ints instead of int double
        EuclideanVector(unsigned int d, unsigned int m); //constructor for given 2 ints instead of int double
        EuclideanVector(double d, double m); //constructor for given 2 ints instead of int double
        EuclideanVector(double d, int m); //constructor for given 2 ints instead of int double
        EuclideanVector(double d, unsigned int m); //constructor for given 2 ints instead of int double
        
        
        //working with doubles
        EuclideanVector(std::vector<double>::const_iterator start, std::vector<double>::const_iterator end); //constructor for vector iterator
        EuclideanVector(std::list<double>::const_iterator start, std::list<double>::const_iterator end); //constructor for list iterator
        
        //working with ints
        EuclideanVector(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end); //constructor for vector iterator
        EuclideanVector(std::list<int>::const_iterator start, std::list<int>::const_iterator end); //constructor for list iterator
            
        //working with unsigned ints
        EuclideanVector(std::vector<unsigned int>::const_iterator start, std::vector<unsigned int>::const_iterator end); //constructor for vector iterator
        EuclideanVector(std::list<unsigned int>::const_iterator start, std::list<unsigned int>::const_iterator end); //constructor for list iterator
        
		
        
        EuclideanVector(const EuclideanVector& ev); //copy constructor
		EuclideanVector& operator=(const EuclideanVector &ev); //copy assignment operator overload

		EuclideanVector(const EuclideanVector&& ev); //move constructor
		EuclideanVector& operator=(const EuclideanVector&& ev); //move assignment operator overload
		//destructor
		friend std::ostream& operator<<(std::ostream& os, const EuclideanVector& ev); //prints out magnitude of vector
		unsigned int getNumDimensions() const; //returns number of dimensions in vector
		double get(unsigned int i) const; //returns value of magnitude of i
		const double getEuclideanNorm() const; //returns normal form of vector
		EuclideanVector& createUnitVector() const; //creates unit vector

		double& operator[](unsigned int index);
		double operator[](unsigned int index) const;
		friend bool operator==(const EuclideanVector& lhs, const EuclideanVector& rhs); //overwrites == operator
		friend bool operator!=(const EuclideanVector& lhs, const EuclideanVector& rhs); //overwrites != operator
		EuclideanVector& operator+=(const EuclideanVector& rhs); //overwrites += operator
		friend EuclideanVector operator+(const EuclideanVector& lhs, const EuclideanVector& rhs); //overwrites + operator
		EuclideanVector& operator-=(const EuclideanVector& rhs); //overwrites -= operator 
		friend EuclideanVector operator-(const EuclideanVector& lhs, const EuclideanVector& rhs); //overwrites - operator
		EuclideanVector& operator*=(const int i); //overwrites *= operator
		friend EuclideanVector operator*(const EuclideanVector& lhs, const int scalar); //overwrites * operator
		friend EuclideanVector operator*(const int scalar, const EuclideanVector& rhs); //overwrites * operator
		friend double operator*(const EuclideanVector& lhs, const EuclideanVector& rhs); //used for dot product
		EuclideanVector& operator/=(const int i); //overwrites /= operator
		friend EuclideanVector operator/(const EuclideanVector& lhs, const int i); //overwrites // operator
        
        operator std::vector<double> () const;
        operator std::list<double> () const;
        
	};
}

#endif