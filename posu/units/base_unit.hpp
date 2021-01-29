#ifndef POSU_UNITS_BASE_UNIT_HPP
#define POSU_UNITS_BASE_UNIT_HPP

#include <chrono>
#include <string_view>

#include "posu/concepts.hpp"

namespace posu::units {

    /**
     * @brief A quanity with a unit-of-measure represented by a tag type.
     *
     * @tparam Rep    The numeric representation type.
     * @tparam Period The ratio with respect to the unit quantity type.
     * @tparam Tag    The tag type representing this quantity's units.
     */
    template<arithmetic Rep, typename Period, meta_constant<std::string_view> Tag>
    class base_unit;

    /**
     * @brief Check whether a type specializes the `base_unit` template or not.
     *
     * @tparam T The type to check.
     *
     * @{
     */
    template<typename T>
    struct is_base_quantity : std::false_type {
    };
    template<typename Rep, typename Ratio, typename Tag>
    struct is_base_quantity<base_unit<Rep, Ratio, Tag>> : std::true_type {
    };
    template<typename T>
    inline constexpr bool is_base_quantity_v = is_base_quantity<T>::value;
    template<typename T>
    concept base_quantity = is_base_quantity_v<T>;
    //! @}

    /**
     * @brief Check whether a quantity has the given units or not.
     *
     * @tparam T     The quantity type to check.
     * @tparam Units The units tag type to check for.
     *
     * @{
     */
    template<typename T, typename Units>
    concept quantity_of = base_quantity<T> && std::same_as<Units, typename T::units>;
    template<typename T, typename Units>
    struct is_quantity_of : std::bool_constant<quantity_of<T, Units>> {
    };
    template<typename T, typename Units>
    inline constexpr bool is_quantity_of_v = is_quantity_of<T, Units>::value;
    //! @}

    /**
     * @brief Base unit tag type template.
     *
     * @tparam UnitsString The unit string.
     */
    template<const char* const UnitsString>
    struct base_unit_tag {
        using type       = base_unit_tag<UnitsString>; //!< Self-type.
        using value_type = std::string_view;           //!< The unit string literal type.

        static constexpr auto value = std::string_view{UnitsString}; //!< The unit string literal.

        /**
         * @brief Obtain the wrapped unit string literal.
         *
         * @return Returns the wrapped unit string literal.
         */
        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }

        /**
         * @brief Conversion to wrapped unit string literal.
         *
         * @return Returns the wrapped unit string literal.
         */
        [[nodiscard]] constexpr operator value_type() const noexcept { return value; }
    };

    namespace detail {

        [[nodiscard]] constexpr auto to_duration(const base_quantity auto& quantity) noexcept;

    }

    template<arithmetic Rep, typename Period, meta_constant<std::string_view> Tag>
    class base_unit {
    public:
        using rep    = Rep;    //!< The numeric representation type.
        using period = Period; //!< The ratio with respect to the unit quantity type.
        using units  = Tag;    //!< The tag type representing this quantity's units.

        /**
         * @brief Construct a quantity with the given number of ticks.
         *
         * @tparam Rep2 The numeric tick type.
         *
         * @param r The number of ticks to initialize this quantity with.
         */
        template<typename Rep2>
            requires(
                std::convertible_to<Rep, const Rep2&> &&
                (std::chrono::treat_as_floating_point_v<Rep> ||
                 !std::chrono::treat_as_floating_point_v<Rep2>))
        constexpr explicit base_unit(const Rep2& r);

        /**
         * @brief Construct a quantity by converting from a different quantity with the same units.
         *
         * @tparam Rep2    The numeric representation type of the other quantity.
         * @tparam Period2 The to-unit-quantity ratio of the other quantity.
         *
         * @param d The quantity to convert from.
         */
        template<typename Rep2, typename Period2>
            requires(
                std::chrono::treat_as_floating_point_v<Rep> ||
                ((std::ratio_divide<Period2, Period>::den == 1) &&
                 !std::chrono::treat_as_floating_point_v<Rep2>))
        constexpr base_unit(const base_unit<Rep2, Period2, Tag>& d);

        /**
         * @brief Obtain the number of ticks this quantity has.
         *
         * @return Returns this quantity's numeric amount.
         */
        [[nodiscard]] constexpr auto count() const noexcept;

        /**
         * @brief Comparison operators.
         *
         * @tparam RRep    The numeric representation type of the quantity to compare against.
         * @tparam RPeriod The to-unit-quantity ratio of the quantity to compare against.
         *
         * @param rhs The quantity to compare against.
         *
         * @return Returns the comparison result.
         *
         * @{
         */
        template<typename RRep, typename RPeriod>
        [[nodiscard]] constexpr auto
        operator==(const base_unit<RRep, RPeriod, units>& rhs) const noexcept;
        template<typename RRep, typename RPeriod>
        [[nodiscard]] constexpr auto
        operator<=>(const base_unit<RRep, RPeriod, units>& rhs) const noexcept;
        //! @}

    private:
        using underlying_type = std::chrono::duration<Rep, Period>;

        friend constexpr auto detail::to_duration(const base_quantity auto& quantity) noexcept;

        underlying_type m_duration;
    };

} // namespace posu::units

#include "posu/units/ipp/base_unit.ipp"

#endif // #ifndef POSU_UNITS_BASE_UNIT_HPP
