//
//  Cholesky.hpp
//  NumCH
//
//  Created by Christian J Howard on 1/31/16.
//  Copyright © 2016 Christian Howard. All rights reserved.
//

#ifndef Cholesky_h
#define Cholesky_h


#include "Matrix.hpp"

namespace la {


//template<class T, MatType C>
template<class T, class C>
void cholesky( const Matrix<T,C> & m, LMat<T> & L ){
    if( !m.isSquare() ){
        printf("Error: Input matrix not square.\n");
        return;
    }
    
    if (m.size() != L.size() ) {
        L.resize(m.size());
    }
    const int numr = L.size().rows;
    
    double sum = T();
    for (int i = 0; i < numr; i++) {
        for (int j = 0; j <= i; j++) {
            sum = m(i,j);
            for (int k = 0; k < j; k++) {
                sum -= L(i,k)*L(j,k);
            }
            if( i == j ){
                if( sum < 0 ){
                    printf("Error: Non-Positive Definite Input Matrix\n");
                    return;
                }
                L(i,j) = sqrt(sum);
            }else{
                T tmp = L(j,j);
                if( tmp == T() ){
                    printf("Error: Divide by Zero\n");
                    return;
                }
                L(i,j) = sum / tmp;
            }
        }
    }
    
    
}


//template<class T, MatType C>
template<class T, class C>
LMat<T> cholesky( const Matrix<T,C> & m ){
    LMat<T> L(m.size());
    cholesky<T,C>( m, L);
    return L;
}


}




#endif /* Cholesky_h */
