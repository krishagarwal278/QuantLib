
/*
 Copyright (C) 2004 Neil Firth

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email quantlib-dev@lists.sf.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file mcamericanbasketengine.hpp
    \brief Least-square Monte Carlo engines
*/

#ifndef quantlib_american_basket_montecarlo_engine_h
#define quantlib_american_basket_montecarlo_engine_h

#include <ql/Instruments/basketoption.hpp>
#include <ql/MonteCarlo/path.hpp>

namespace QuantLib {

    //! least-square Monte Carlo engine
    /*! \warning This method is intrinsically weak for out-of-the-money
                 options.
        \bug This engine does not yet work for put options. More problems
             might surface.

        \ingroup basketengines
    */
    class MCAmericanBasketEngine : public BasketOption::engine {
      public:
        MCAmericanBasketEngine(Size requiredSamples,
                               Size timeSteps,
                               BigNatural seed = 0)
        : requiredSamples_(requiredSamples), timeSteps_(timeSteps),
          seed_(seed) {}
        void calculate() const;
      private:
        Size requiredSamples_;
        Size timeSteps_;
        BigNatural seed_;
    };


    // put all the asset prices into a vector.
    // s0 is not included in the vector
    std::vector<Real> getAssetSequence(Real s0, const Path& path);

    // put all the antithetic asset prices into a vector.
    // s0 is not included in the vector
    std::vector<Real> getAntiAssetSequence(Real s0, const Path& path);


}


#endif
