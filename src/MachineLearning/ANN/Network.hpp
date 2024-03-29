//
//  Network.hpp
//  NumCH
//
//  Created by Christian J Howard on 1/21/16.
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

#ifndef Network_hpp
#define Network_hpp

#include <stdio.h>
#include <vector>
#include "Node.hpp"

namespace ANN {
    
    class Network {
    public:
        
        // constructor/destructor stuff
        Network();
        Network( const std::vector<int> & layers );
        Network( const Network & net );
        ~Network();
        
        // set layer dimensions
        void setLayers( const std::vector<int> & layers );
        
        // operator
        std::vector<double> operator()(std::vector<double> & input );
        void operator()(std::vector<double> & input , std::vector<double> & output );
        Network & operator=( const Network & net );
        
        // back propogation
        void backprop( const std::vector<double> & dEdO,std::vector<double> & gradient );
        std::vector<double> backprop( const std::vector<double> & dEdO );
        
        
        
        
        // weight stuff
        size_t numWeights() const;
        const std::vector<double> & w() const;
        std::vector<double> & w();
        const double & weightAt(int index) const;
        double & weightAt(int index);
        const double & weightAt(int layer, int li, int ri) const;
        double & weightAt(int layer, int li, int ri);
        
        
        
        // node stuff
        size_t numNodes( int layer );
        size_t numNodes() const;
        void setActivationFunc( int layer, Activation (*f)(double z));
        Node & getNode(int layer, int n);
        Node & getNode(int n);
        
        size_t numInputs() const;
        size_t numOutputs() const;
        size_t numLayers() const;
        
        
        // set input/output mappings
        void setInputMap( void (*im)( std::vector<double> & in ) );
        void setOutputMap( void (*om)( std::vector<double> & out ) );
        
    protected:
        
        
    private:
        friend class Network;
        
        std::vector<double> weights;
        std::vector<int> layers;
        std::vector<int> layerSums;
        std::vector<Node> nodes;
        std::vector<double> input;
        std::vector<double> output;
        
        void (*inputMap)( std::vector<double> & in );
        void (*outputMap)( std::vector<double> & out );
        
        
        
        struct Connection {
            int layer;
            int li;
            int ri;
        };
        
        size_t obtainNumberWeights( const std::vector<int> & layers ) const;
        size_t hashfunc( const Connection & c ) const;
        void clear();
        void copy( const Network & net );
        
        
        
    };
    
}

#endif /* Network_hpp */
