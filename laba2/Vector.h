#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <fstream>

class Vector {
private:
    double* data;     
    unsigned size;     

public:
 
    Vector();                                   
    Vector(unsigned n, const double* arr = nullptr); 
    Vector(const Vector& other);                
    Vector(Vector&& other) noexcept;           
    ~Vector();                                  

    double& operator[](unsigned index);        
    const double& operator[](unsigned index) const; 
    Vector& operator=(const Vector& other);    
    Vector& operator=(Vector&& other) noexcept; 
    Vector operator+(const double* other) const; 

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    friend std::istream& operator>>(std::istream& is, Vector& vec);

    unsigned getSize() const;
};

#endif
#pragma once
