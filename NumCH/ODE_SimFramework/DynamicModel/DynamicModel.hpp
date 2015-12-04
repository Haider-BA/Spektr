//
//  DynamicModel.hpp
//  NumCH
//
//  Created by Christian J Howard on 11/2/15.
//  Copyright © 2015 Christian Howard. All rights reserved.
//

#ifndef DynamicModel_hpp
#define DynamicModel_hpp

#include <stdio.h>
#include "PreciseTime.h"
#include "RandomNumberGenerator.hpp"
typedef RandomNumberGenerator Rand;


class Simulator;

/*!
 * This is a class built to represent
 * a model that will be used within
 * the simulation
 *
 */
class DynamicModel {
    
public:
    
    
    
    virtual ~DynamicModel(){}
    
    
    
    
    
    /*!
     * This method is used to do any
     * other initialization for a model
     * that won't be done in the constructor,
     * such as if this model depends on any
     * other external models
     *
     * \params None
     * \returns None
     */
    virtual void initialize(){}
    
    
    
    virtual void setupPrintData(){}
    
    
    
    /*!
     * In the event this model
     * is based on differential
     * equations, this method returns
     * the number of dimensions
     * in the ODE equations
     *
     * \params None
     * \returns Number of Dimensions in System of ODEs
     */
    virtual int numDims(){ return 0; }
    
    
    
    
    /*!
     * This is a method that represents
     * the system of differential equations
     * and outputs the rate of change of the
     * variables in the equations
     *
     * \params dxdt A vector that will hold the rate of hange
     of the diffeq variables. This vector
     will be modified in this method and in
     turn make this input also the output
     * \returns None
     */
    virtual void operator()( double time , double* dqdt ) = 0;
    
    
    
    
    
    /*!
     * This method is for returning state
     * variable values based on a dimension index
     *
     * \params index Dimension index
     * \returns Reference Double value for the state variable
     associated with the input index
     */
    double & operator[](int index) const { return state[index]; }
    
    
    
    
    
    
    /*!
     * This method is for returning state
     * variable values based on a dimension index
     *
     * \params index Dimension index
     * \returns Reference Double value for the state variable
     associated with the input index
     */
    double & operator[](int index) { return state[index]; }
    
    
    
    
    
    
    /*!
     * This method is to set the rate at which this model will be updated
     *
     * \params updateRateInHz The update rate in Hz
     * \returns None
     */
    void assignUpdateRate( int updateRateInHz ){ incrementTime = Time(1, updateRateInHz); }
    
    
    
    
    /*!
     * This method returns the time step between each
     * update of this model
     *
     * \params None
     * \returns Returns the time step between each
     update of this model
     */
    double getDt() const { return incrementTime.convert<double>(); }
    Time   getFracDt() const { return incrementTime; }
    
    
    
    
protected:
    
    
    friend class Simulator;
    friend class RungeKutta4;
    friend class ExplicitTrapezoidal;
    
    
    //
    // Method used by simulation to assign the part of the state vector
    // that this model uses
    //
    void assignStateAddress( double* address ) { state = address; }
    
    
    // method to assign the random number generator
    void assignRandomGenerator( Rand & gen ){ generator = &gen; }
    
    
    void assignParentSimulator( Simulator* p ){ parent = p; }
    
    

    
    //
    // Time between updates
    //
    Time incrementTime;
    
    
    //
    // Pointer to state
    //
    double* state;
    
    
    Simulator* parent;
    
    
    // Random number generator
    Rand * generator;
    
};


#endif /* DynamicModel_hpp */