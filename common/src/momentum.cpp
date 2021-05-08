#include "momentum.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system;
using namespace prefix;

common::momentum::momentum ( long double val, long double mult ) : unit_t<3201>(val,mult){};
common::momentum::momentum(long double val): unit_t<3201>(val){};

common::momentum sakurajin::unit_system::unit_cast(const common::momentum& other, long double new_multiplier){
    auto v1 = sakurajin::unit_system::unit_cast(static_cast<unit_t<3201>>(other), new_multiplier);
    return common::momentum{v1.value,v1.multiplier};
}


common::momentum common::operator*(const base::mass& m, const common::speed& v){
    auto m1 = sakurajin::unit_system::unit_cast(m,1);
    auto v1 = sakurajin::unit_system::unit_cast(v,1);
    return common::momentum{v1.value*m1.value,1};
}

common::momentum common::operator*(const common::speed& v, const base::mass& m){
    return m*v;
}

base::mass common::operator/(const common::momentum& p, const common::speed& v){
    auto p1 = sakurajin::unit_system::unit_cast(p,1);
    auto v1 = sakurajin::unit_system::unit_cast(v,1);
    return base::mass{p1.value/v1.value,1};
}

common::speed common::operator/(const common::momentum& p, const base::mass& m){
    auto p1 = sakurajin::unit_system::unit_cast(p,1);
    auto m1 = sakurajin::unit_system::unit_cast(m,1);
    return common::speed{p1.value/m1.value,1};
}

common::momentum common::literals::operator "" _kgmps(long double len){
    return common::momentum{len,1};
}

common::momentum common::literals::operator "" _kgmps(unsigned long long int len){
    return common::momentum{static_cast<long double>(len), 1};
}

std::ostream& common::operator<<(std::ostream& os, const common::momentum& p){
    auto p1 = sakurajin::unit_system::unit_cast(p,1);
    return os << p1.value << " kilogram * meter per second";
}