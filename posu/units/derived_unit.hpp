#ifndef POSU_UNITS_DERIVED_UNIT_HPP
#define POSU_UNITS_DERIVED_UNIT_HPP

#include "posu/concepts.hpp"
#include "posu/type_ratio.hpp"
#include "posu/units/base_unit.hpp"

namespace posu::units {

    /**
     * @brief A quantity with units derived from a unit system's base units.
     *
     * @tparam Rep    The numeric representation type.
     * @tparam Ratio  This quantity's ratio in relation to the related unit quantity.
     * @tparam Units  The derivation of the related unit quantity's units of measure.
     * @tparam Scale  The scaling factor in relation to the related unit quantity.
     * @tparam Offset The offset in relation to the related unit quantity.
     */
    template<
        typename Rep,
        typename Ratio,
        typename Units          = type_ratio<>,
        typename Scale          = std::ratio<1>,
        numeric_constant Offset = std::integral_constant<int, 0>>
        requires(is_type_ratio_v<Units>)
    class derived_unit : public base_unit<Rep, Ratio, type_list<Units, Scale, Offset>> {
    private:
        using parent_type = base_unit<Rep, Ratio, type_list<Units, Scale, Offset>>;

    public:
        using scale  = Scale;
        using offset = Offset;

        using parent_type::parent_type;
    };

    /**
     * @brief Partial specialization for a quantity exactly equivalent to a base unit.
     *
     * @tparam Rep      The numeric representation type.
     * @tparam Ratio    This quantity's ratio in relation to the related unit quantity.
     * @tparam BaseUnit The equivalent base unit tag.
     * @tparam Offset   An offset exactly equal to zero.
     */
    template<typename Rep, typename Ratio, typename BaseUnit, numeric_constant Offset>
        requires(!is_type_ratio_v<BaseUnit> && (Offset{}() == 0))
    class derived_unit<Rep, Ratio, type_ratio<type_list<BaseUnit>>, std::ratio<1>, Offset>
        : public base_unit<Rep, Ratio, BaseUnit> {
    private:
        using parent_type = base_unit<Rep, Ratio, BaseUnit>;

    public:
        using scale  = std::ratio<1>;
        using offset = Offset;

        using parent_type::parent_type;
    };

} // namespace posu::units

#endif // #ifndef POSU_UNITS_DERIVED_UNIT_HPP
