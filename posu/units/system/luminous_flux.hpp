#ifndef POSU_UNITS_SYSTEM_LUMINOUS_FLUX_HPP
#define POSU_UNITS_SYSTEM_LUMINOUS_FLUX_HPP

#include "posu/units/derived_unit.hpp"

#include "posu/units/system/luminous_intensity.hpp"
#include "posu/units/system/solid_angle.hpp"

namespace posu::units {

    struct luminous_flux {
        using type       = luminous_flux;
        using value_type = std::string_view;
        using dimensions =
            dimension_multiply<dimension_t<luminous_intensity>, dimension_t<solid_angle>>;

        static constexpr auto value = std::string_view{"luminous flux"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_kind<luminous_flux> = true;

    template<>
    struct kind_multiply_result<luminous_intensity, solid_angle> {
        using type = luminous_flux;
    };

    template<>
    struct kind_divide_result<luminous_flux, luminous_intensity> {
        using type = solid_angle;
    };

    template<>
    struct kind_divide_result<luminous_flux, solid_angle> {
        using type = luminous_intensity;
    };

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_LUMINOUS_FLUX_HPP
