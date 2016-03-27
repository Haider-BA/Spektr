//
//  FastStorage.hpp
//  Spektr
//
//  Created by Christian J Howard on 3/25/16.
//
//  The MIT License (MIT)
//    Copyright © 2016 Christian Howard. All rights reserved.
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

#ifndef FastStorage_h
#define FastStorage_h

#include "MatHashes.hpp"
#include "Dims.hpp"

template< typename T, int Rows, int Cols  >
class FastStorage {
public:
    
    FastStorage(T dval = static_cast<T>(0));
    FastStorage(int dummyRows, int dummyCols, T dval = static_cast<T>(0));
    
    void transpose();
    bool isTransposed() const;
    
    T & operator()(int r, int c);
    const T & operator()(int r, int c) const;
    T & operator()(int k);
    const T & operator()(int k) const;
    
    Dims size() const;
    int total() const;
    
    
private:
    
    typedef Hasher<General> Hash;
    Dims dims;
    T data[Rows*Cols+1];
    int nt;
    bool isT;
};

#include "FastStorage_Impl.hpp"


#endif /* FastStorage_h */
