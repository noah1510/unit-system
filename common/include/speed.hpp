#pragma once

#include "unit_t.hpp"
#include "length.hpp"
#include "time.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace common{
            class speed : public base::unit_t<201>{
            public:
                speed(long double val);
                speed(long double val, long double mult);
            };
            
            speed operator/(const base::length& s, const base::time& t);
            
            base::length operator*(const speed& v, const base::time& t);
            base::length operator*(const base::time& t, const speed& v);
            
            base::time operator/(const base::length& s, const speed& v);
            
            inline namespace literals{
                speed operator "" _kmph(long double val);
                speed operator "" _mps(long double val);
            }
            
        }
    }
}
 
