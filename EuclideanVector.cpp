// EuclideanVector.cpp
//

#include "EuclideanVector.h"

namespace cs6771 {

	//default constructor given dimension of vector - delegates to the next constructor
	EuclideanVector::EuclideanVector(int i) : EuclideanVector(i, 0) {}
    EuclideanVector::EuclideanVector(double i) : EuclideanVector(static_cast<int>(i), 0) {} 
    EuclideanVector::EuclideanVector(unsigned int i) : EuclideanVector(static_cast<int>(i), 0) {}

	//default constructor given magnitude of each dimension
	EuclideanVector::EuclideanVector(unsigned int d, double m) {
		dimensions = d;
        for (unsigned int x = 0; x < d; x++){
            v.push_back(m);
        }
	}
    
    //delegating constuctors for different combinations of unsigned ints, ints, and doubles
    EuclideanVector::EuclideanVector(int d, int m) : EuclideanVector(static_cast<unsigned int>(d),static_cast<double>(m)) {}
    EuclideanVector::EuclideanVector(int d, double m) : EuclideanVector(static_cast<unsigned int>(d), m) {}
    EuclideanVector::EuclideanVector(int d, unsigned int m) : EuclideanVector(static_cast<unsigned int>(d),static_cast<double>(m)) {}
    EuclideanVector::EuclideanVector(unsigned int d, int m) : EuclideanVector(d ,static_cast<double>(m)) {}
    EuclideanVector::EuclideanVector(unsigned int d, unsigned int m) : EuclideanVector(d ,static_cast<double>(m)) {}
    EuclideanVector::EuclideanVector(double d, double m) : EuclideanVector(static_cast<unsigned int>(d), m) {}
    EuclideanVector::EuclideanVector(double d, int m) : EuclideanVector(static_cast<unsigned int>(d),static_cast<double>(m)) {}
    EuclideanVector::EuclideanVector(double d, unsigned int m) : EuclideanVector(static_cast<unsigned int>(d),static_cast<double>(m)) {}
     
     
    //constructor working with vector iterators - doubles 
    EuclideanVector::EuclideanVector(std::vector<double>::const_iterator start, std::vector<double>::const_iterator end) {
        int count = 0;
        for (std::vector<double>::const_iterator ptr = start; ptr != end; ptr++){
            v.push_back(*ptr);
            count++;
        }
        dimensions = count;
    }
    
    //constructor working with list iterators - doubles
    EuclideanVector::EuclideanVector(std::list<double>::const_iterator start, std::list<double>::const_iterator end) {
        int count = 0;
        for (std::list<double>::const_iterator ptr = start; ptr != end; ptr++){
            v.push_back(*ptr);
            count++;
        }
        dimensions = count;
    }
    
    //constructor working with vector iterators - ints
    EuclideanVector::EuclideanVector(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end) {
        int count = 0;
        for (std::vector<int>::const_iterator ptr = start; ptr != end; ptr++){
            v.push_back(*ptr);
            count++;
        }
        dimensions = count;
    }
    
    //constructor working with list iterators - ints
    EuclideanVector::EuclideanVector(std::list<int>::const_iterator start, std::list<int>::const_iterator end) {
        int count = 0;
        for (std::list<int>::const_iterator ptr = start; ptr != end; ptr++){
            v.push_back(*ptr);
            count++;
        }
        dimensions = count;
    }
    
    //constructor working with vector iterators - unsigned ints
    EuclideanVector::EuclideanVector(std::vector<unsigned int>::const_iterator start, std::vector<unsigned int>::const_iterator end) {
        int count = 0;
        for (std::vector<unsigned int>::const_iterator ptr = start; ptr != end; ptr++){
            v.push_back(*ptr);
            count++;
        }
        dimensions = count;
    }
    
    //constructor working with list iterators - unsigned ints
    EuclideanVector::EuclideanVector(std::list<unsigned int>::const_iterator start, std::list<unsigned int>::const_iterator end) {
        int count = 0;
        for (std::list<unsigned int>::const_iterator ptr = start; ptr != end; ptr++){
            v.push_back(*ptr);
            count++;
        }
        dimensions = count;
    }
    
	//copy constructor
	EuclideanVector::EuclideanVector(const EuclideanVector& ev) : dimensions(ev.dimensions)  {
        for (unsigned int x = 0; x < ev.getNumDimensions(); x++){
            v.push_back(ev[x]);
        }
	}

	//copy assignment operator overload
	EuclideanVector& EuclideanVector::operator=(const EuclideanVector &ev) {
        dimensions = ev.dimensions;
        for (unsigned int x = 0; x < ev.getNumDimensions(); x++){
            v.push_back(ev[x]);
        }
        return *this;   
	}

	//move constructor
	EuclideanVector::EuclideanVector(const EuclideanVector&& ev) : dimensions{std::move(ev.dimensions)} {
        for (unsigned int x = 0; x < ev.getNumDimensions(); x++){
            v.push_back(std::move(ev[x]));
        }
    }

	//move assignment operator overload
	EuclideanVector& EuclideanVector::operator=(const EuclideanVector&& ev) {
        if (this != &ev){
            dimensions = std::move(ev.dimensions);
            for (unsigned int x = 0; x < ev.getNumDimensions(); x++){
                v[x] = std::move(ev[x]);
            }       
        }
        return *this;
	}
    
	//prints out magnitude of vector
	std::ostream& operator<<(std::ostream& os, const EuclideanVector& ev){
		os << "[";
        for (unsigned int x = 0; x < ev.getNumDimensions(); x++){
            os << ev.get(x);
            
            //adds space if not the last element
            if (x < ev.getNumDimensions() - 1){
                os << " ";
            }
        }
        os << "]";
        return os << std::noshowpoint;
	}

	//returns number of dimensions in vector
	unsigned int EuclideanVector::getNumDimensions() const{
        return dimensions;
	}

	//returns value of magnitude of i
	double EuclideanVector::get(unsigned int i) const{
        return v[i];
	}

	//returns normal form of vector
	const double EuclideanVector::getEuclideanNorm() const {
        double answer = 0;
        for (auto d: v){
            answer += d*d;
        }
        return std::sqrt(answer);
	}

	//creates unit vector
	EuclideanVector& EuclideanVector::createUnitVector() const {
        EuclideanVector *e = new EuclideanVector(*this);
        double div = this->getEuclideanNorm();
        for (int x = 0; x < this->dimensions; x++){
            e->v[x] = v[x]/div;
        }
        return *e;
	}
    
    //overwrite [] operator
    double& EuclideanVector::operator[](unsigned int index){
        return v[index];
    }
    
    //overwrites [] operator
    double EuclideanVector::operator[](unsigned int index) const{
        return v[index];
    }

	//overwrites == operator
	bool operator==(const EuclideanVector& lhs, const EuclideanVector& rhs) {
        //if not the same number of dimensions can't be the same
        if (lhs.getNumDimensions() != rhs.getNumDimensions()){
            return false;
        }
        
        //check that each element is the same, if one isn't then they aren't the same vector
        for (unsigned int x = 0; x < lhs.getNumDimensions(); x++){
            if (lhs[x] != rhs[x]){
                return false;
            }
        }      
        return true;
	}

	//overwrites != operator
	bool operator!=(const EuclideanVector& lhs, const EuclideanVector& rhs) {
        return !(lhs==rhs);
	}

	//overwrites += operator
	EuclideanVector& EuclideanVector::operator+=(const EuclideanVector& rhs) {
        for (unsigned int x = 0; x < this->getNumDimensions(); x++){
            v[x] += rhs[x];
        }    
        return *this;
	}

	//overwrites + operator
	EuclideanVector operator+(const EuclideanVector& lhs, const EuclideanVector& rhs) {
        EuclideanVector e = lhs;
        return e += rhs;
	}

	//overwrites -= operator 
	EuclideanVector& EuclideanVector::operator-=(const EuclideanVector& rhs) {
        for (unsigned int x = 0; x < this->getNumDimensions(); x++){
            v[x] -= rhs[x];
        }      
        return *this;
	}

	//overwrites - operator
	EuclideanVector operator-(const EuclideanVector& lhs, const EuclideanVector& rhs) {
        EuclideanVector e = lhs;
        return e -= rhs;
	}

	//overwrites *= operator
	EuclideanVector& EuclideanVector::operator*=(const int i) {
        for (unsigned int x = 0; x < this->getNumDimensions(); x++){
            v[x] *= i;
        }       
        return *this;
	}

	//overwrites * operator
	EuclideanVector operator*(const EuclideanVector& lhs, const int scalar){
        return operator*(scalar, lhs);
    }

	//overwrites * operator
	EuclideanVector operator*(const int scalar, const EuclideanVector& rhs) {
        EuclideanVector e = rhs;
        return e *= scalar;
	}

	//used for dot product
	double operator*(const EuclideanVector& lhs, const EuclideanVector& rhs) {
        double answer = 0;
        for (unsigned int i = 0; i < lhs.getNumDimensions(); i++){
            answer += (rhs[i] * lhs[i]);
        }
        return answer;
	}

	//overwrites /= operator
	EuclideanVector& EuclideanVector::operator/=(const int i) {
        for (unsigned int x = 0; x < this->getNumDimensions(); x++){
            v[x] /= i;
        }      
        return *this;
	}

	//overwrites / operator
	EuclideanVector operator/(const EuclideanVector& lhs, const int i) {
        EuclideanVector e = lhs;
        return e /= i;
	}
    
    //overwrites the typecasting operator to vector
    EuclideanVector::operator std::vector<double> () const{
        return (this->v);
    }
    
    //overwrites the typecasting operator to list
    EuclideanVector::operator std::list<double> () const{
        return (std::list<double>(v.begin(), v.end()));
    }
}