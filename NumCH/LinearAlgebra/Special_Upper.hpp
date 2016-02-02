//
//  Special_Upper.hpp
//  NumCH
//
//  Created by Christian J Howard on 2/1/16.
//  Copyright © 2016 Christian Howard. All rights reserved.
//

#ifndef Special_Upper_h
#define Special_Upper_h

#include "Matrix.hpp"

namespace la {
    
    template<typename T>
    class UMat : public Matrix<T, UMat<T> >{
    public:
        
        UMat():Matrix<T,UMat<T>>(){}
        UMat(int numr, int numc, T dval = T() ):Matrix<T,UMat<T>>(numr,numc,dval){}
        UMat(Dims dims, T dval = T() ):Matrix<T,UMat<T>>(dims,dval){}
        ~UMat(){}
        
        /*template<class S>
        UMat<T> & operator=( const Matrix<T,S> & m ){
            return Matrix<T,UMat<T>>::operator=(m);
        }
        
        UMat<T> & operator=( const UMat & m ){
            return Matrix<T,UMat<T>>::operator=(m);
        }*/
        
        template <typename E>
        UMat( MatExpression<T,E> const& mat):Matrix<T,UMat<T>>(mat){}
        
    };
}

#endif /* Special_Upper_h */
