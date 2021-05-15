#ifndef POSU_UNITS_DERIVED_UNIT_HPP
#define POSU_UNITS_DERIVED_UNIT_HPP

#include "posu/concepts.hpp"
#include "posu/type_ratio.hpp"
#include "posu/units/base_unit.hpp"

namespace posu::units {

    /**
     * @brief Quantity multiplication and division.
     *
     * These operations always return a `units::quantity_of_measure`. These operations use
     * `units::kind_multiply_result` and `units::kind_divide_result` to determine the quantity kind
     * of the result.
     *
     * @param lhs The left-hand-side operand.
     * @param rhs The right-hand-side operand.
     *
     * @return Returns the operation result.
     *
     * @{
     */
    [[nodiscard]] constexpr auto
    operator*(const quantity_of_measure auto& lhs, const quantity_of_measure auto& rhs) noexcept;
    [[nodiscard]] constexpr auto
    operator/(const quantity_of_measure auto& lhs, const quantity_of_measure auto& rhs) noexcept;
    //! @}

} // namespace posu::units

#include "posu/units/ipp/derived_unit.ipp"

#endif // #ifndef POSU_UNITS_DERIVED_UNIT_HPP
