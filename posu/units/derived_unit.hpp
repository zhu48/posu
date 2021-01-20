#ifndef POSU_UNITS_DERIVED_UNIT_HPP
#define POSU_UNITS_DERIVED_UNIT_HPP

#include "posu/type_list.hpp"
#include "posu/units/base_unit.hpp"

namespace posu::units {

    template<typename Numerator, typename Denominator>
        requires(is_type_list_v<Numerator>&& is_type_list_v<Denominator>)
    struct ratio {
    };

    template<typename T>
    struct is_ratio : std::false_type {
    };

    template<typename Numerator, typename Denominator>
    struct is_ratio<ratio<Numerator, Denominator>> : std::true_type {
    };

    template<typename T>
    inline constexpr bool is_ratio_v = is_ratio<T>::value;

    template<typename Rep, typename Period, typename Ratio>
        requires(is_ratio_v<Ratio>)
    using derived_unit = base_unit<Rep, Period, Ratio>;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_DERIVED_UNIT_HPP
