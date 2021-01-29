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
     * @tparam Scale       The scaling ratio in relation to the related unit quantity.
     * @tparam Offset      The offset in relation to the related unit quantity.
     * @tparam UnitsString The unit string.
     */
    template<
        typename Units,
        typename Scale,
        arithmetic_constant Offset,
        const char* const   UnitsString>
        requires(is_type_ratio_v<Units>)
    struct derived_unit_tag : public base_unit_tag<UnitsString> {
        using type = derived_unit_tag<Units, Scale, Offset, UnitsString>; //!< Self-type.

        using derivation = Units;  //!< The unit derivation.
        using scale      = Scale;  //!< The to-unit-quantity scaling ratio.
        using offset     = Offset; //!< The to-unit-quantity scaling offset.
    };

    /**
     * @brief A derived unit tag type equivalent to a base unit tag type.
     *
     * @tparam T The type to compare against this concept.
     */
    template<typename T>
    concept base_unit_equivalent = meta_constant<T, std::string_view> &&
        one_constant<typename T::scale> && zero_constant<typename T::offset> &&
        one_constant<size<typename T::derivation::num>> && empty_v<typename T::derivation::den>;

    /**
     * @brief A quantity with units derived from a unit system's base units.
     *
     * @tparam Rep   The numeric representation type.
     * @tparam Ratio This quantity's ratio in relation to the related unit quantity.
     * @tparam Tag   The derived units-of-measure tag type.
     */
    template<arithmetic Rep, typename Ratio, typename Tag>
    class derived_unit;

    /**
     * @brief Partial specialization for generic derived-units quantities.
     *
     * @tparam Rep         The numeric representation type.
     * @tparam RatioNum    The to-unit-quantity quantity ratio numerator.
     * @tparam RatioDen    The to-unit-quantity quantity ratio denominator.
     * @tparam Units       The derivation of the related unit quantity's units of measure.
     * @tparam ScaleNum    The to-unit-quantity scaling factor numerator.
     * @tparam ScaleDen    The to-unit-quantity scaling factor denominator.
     * @tparam Offset      The offset in relation to the related unit quantity.
     * @tparam UnitsString The derived units-of-measure string.
     */
    template<
        arithmetic  Rep,
        std::size_t RatioNum,
        std::size_t RatioDen,
        typename Units,
        std::size_t         ScaleNum,
        std::size_t         ScaleDen,
        arithmetic_constant Offset,
        const char* const   UnitsString>
        requires(is_type_ratio_v<Units>)
    class derived_unit<
        Rep,
        std::ratio<RatioNum, RatioDen>,
        derived_unit_tag<Units, std::ratio<ScaleNum, ScaleDen>, Offset, UnitsString>>
        : public base_unit<
              Rep,
              std::ratio<RatioNum, RatioDen>,
              derived_unit_tag<Units, std::ratio<ScaleNum, ScaleDen>, Offset, UnitsString>> {
    private:
        using parent_type = base_unit<
            Rep,
            std::ratio<RatioNum, RatioDen>,
            derived_unit_tag<Units, std::ratio<ScaleNum, ScaleDen>, Offset, UnitsString>>;

    public:
        using scale  = std::ratio<ScaleNum, ScaleDen>; //!< The to-unit-quantity scaling ratio.
        using offset = Offset; //!< The offset in relation to the related unit quantity.

        using parent_type::parent_type; //!< Use parent constructors.
    };

    /**
     * @brief Partial specialization for a quantity exactly equivalent to a base unit.
     *
     * @tparam Rep         The numeric representation type.
     * @tparam RatioNum    The to-unit-quantity quantity ratio numerator.
     * @tparam RatioDen    The to-unit-quantity quantity ratio denominator.
     * @tparam BaseUnit    The equivalent base unit tag.
     * @tparam Offset      The zero in relation to the related unit quantity.
     * @tparam UnitsString The derived units-of-measure string.
     */
    template<
        arithmetic                      Rep,
        std::size_t                     RatioNum,
        std::size_t                     RatioDen,
        meta_constant<std::string_view> BaseUnit,
        zero_constant                   Offset,
        const char* const               UnitsString>
    class derived_unit<
        Rep,
        std::ratio<RatioNum, RatioDen>,
        derived_unit_tag<type_ratio<type_list<BaseUnit>>, std::ratio<1>, Offset, UnitsString>>
        : public base_unit<Rep, std::ratio<RatioNum, RatioDen>, BaseUnit> {
    private:
        using parent_type = base_unit<Rep, std::ratio<1>, BaseUnit>;

    public:
        using scale  = std::ratio<1>; //!< The to-unit-quantity scaling ratio.
        using offset = Offset;        //!< The offset in relation to the related unit quantity.

        using parent_type::parent_type; //!< Use parent constructors.
    };

    /**
     * @brief Check whether a type specializes the `derived_unit` template or not.
     *
     * @tparam T The type to check.
     *
     * @{
     */
    template<typename T>
    struct is_derived_quantity : std::false_type {
    };
    template<typename Rep, typename Ratio, typename Tag>
    struct is_derived_quantity<derived_unit<Rep, Ratio, Tag>> : std::true_type {
    };
    template<typename T>
    inline constexpr bool is_derived_quantity_v = is_derived_quantity<T>::value;
    template<typename T>
    concept derived_quantity = is_derived_quantity_v<T>;
    //! @}

} // namespace posu::units

#endif // #ifndef POSU_UNITS_DERIVED_UNIT_HPP
