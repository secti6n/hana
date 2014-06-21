/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/adapted/std_integral_constant.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/detail/static_assert.hpp>
#include <boost/hana/functional.hpp>
#include <boost/hana/integral.hpp>
#include <boost/hana/list.hpp>
#include <boost/hana/type.hpp>
using namespace boost::hana;
using namespace literals;


int main() {
    //! [fusion]
    BOOST_HANA_CONSTEXPR_LAMBDA auto odd = [](auto x) {
        return x % 2_c != 0_c;
    };

    BOOST_HANA_STATIC_ASSERT(count(odd, list(1_c, 2_c, 3_c)) == 2_c);
    BOOST_HANA_STATIC_ASSERT(count(odd, list(1, 2, 3)) == 2);
    //! [fusion]

    //! [mpl]
    BOOST_HANA_CONSTEXPR_LAMBDA auto types = list_t<int, char, long, short, char, long, double, long>;
    BOOST_HANA_STATIC_ASSERT(count(lift<std::is_floating_point>, types) == 1_c);
    BOOST_HANA_STATIC_ASSERT(count(_ == type<char>, types) == 2_c);
    BOOST_HANA_STATIC_ASSERT(count(_ == type<void>, types) == 0_c);
    //! [mpl]
}
