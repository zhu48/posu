#ifndef POSU_UNITS_DERIVED_UNIT_HPP
#define POSU_UNITS_DERIVED_UNIT_HPP

#include "posu/concepts.hpp"
#include "posu/type_ratio.hpp"
#include "posu/units/base_unit.hpp"

namespace posu::units {

    /**
     * @brief Derived unit tag type template.
     *
     * @tparam Units       The unit derivation formula.
     * @tparam UnitsString The unit string.
     */
    template<meta_ratio Units, const char* const UnitsString>
    struct derived_unit_tag : public base_unit_tag<UnitsString> {
        using type       = derived_unit_tag<Units, UnitsString>; //!< Self-type.
        using derivation = Units;                                //!< The unit derivation.
    };

    template<derived_units T>
    struct derivation_traits<T> {
    public:
        using units      = T;
        using derivation = typename units::derivation;

        static constexpr auto units_string = units::value;
    };

    /**
     * @brief A quantity with units derived from a unit system's base units.
     *
     * @tparam Rep    The numeric representation type.
     * @tparam Period This quantity's ratio in relation to the related unit quantity.
     * @tparam Units  The derived units-of-measure tag type.
     */
    template<arithmetic Rep, detail::std_ratio Period, derived_units Units>
    using derived_unit = std::conditional_t<
        base_unit_equivalent<Units>,
        base_unit<Rep, Period, typename Units::derivation::num::front>,
        base_unit<Rep, Period, Units>>;

    /**
     * @brief Check whether a type specializes the `derived_unit` template or not.
     *
     * @tparam T The type to check.
     *
     * @{
     */
    template<typename T>
    concept derived_quantity = quantity<T> && derived_units<typename T::units>;
    template<typename T>
    struct is_derived_quantity : std::bool_constant<derived_quantity<T>> {
    };
    template<typename T>
    inline constexpr bool is_derived_quantity_v = is_derived_quantity<T>::value;
    //! @}

    template<quantity Lhs, quantity Rhs>
    [[nodiscard]] auto operator*(const Lhs& lhs, const Rhs& rhs) noexcept;
    template<quantity Lhs, quantity Rhs>
    [[nodiscard]] auto operator/(const Lhs& lhs, const Rhs& rhs) noexcept;

} // namespace posu::units

#include "posu/units/ipp/derived_unit.ipp"

#endif // #ifndef POSU_UNITS_DERIVED_UNIT_HPP
