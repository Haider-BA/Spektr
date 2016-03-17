//
//  Fraction.h
//  NumCH
//
//  Created by Christian J Howard on 10/31/15.
//
//  The MIT License (MIT)
//  Copyright © 2016 Christian Howard. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//
//

#ifndef Fraction_h
#define Fraction_h

#include <stdio.h>


class Fraction {
public:
    Fraction();
    Fraction(int num, int denom );
    
    Fraction operator*( const Fraction& ) const;
    Fraction operator+( const Fraction& ) const;
    Fraction operator/( const Fraction& ) const;
    Fraction operator-( const Fraction& ) const;
    Fraction operator-() const;
    void operator-(){ positive = !positive; }
    bool operator==( const Fraction & ) const;
    bool operator<( const Fraction & ) const;
    bool operator<=( const Fraction & ) const;
    bool operator>( const Fraction & ) const;
    bool operator>=( const Fraction & ) const;
    bool operator!=( const Fraction & ) const;
    
    
    template< class T>
    T convert() const;
    
    void print() const {
        if( positive ){
            printf("%u (%u/%u)\n",complete,numerator,denominator);
        }else{
            printf("-%u (%u/%u)\n",complete,numerator,denominator);
        }
    }
    
    
private:
    friend Fraction;
    
    int abs(int a){ if( a >= 0 ){ return a; }else{ return -a; } }
    bool sign( int a ){ return a>=0; }
    unsigned int gcd(unsigned int u, unsigned int v) const;
    unsigned int numerator;
    unsigned int denominator;
    unsigned int complete;
    bool positive;
    
};



#endif /* Fraction_h */