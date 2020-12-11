#ifndef POSU_UNITS_HPP
#define POSU_UNITS_HPP

#include <chrono>

namespace posu::units {

    template<typename Rep, typename Period, typename Tag> // clang-format off
        requires( std::integral<Rep> || std::floating_point<Rep> )
    class base_unit : private std::chrono::duration<Rep, Period> {}; // clang-format on

    struct time_tag {
        constexpr time_tag() noexcept = default;
    };

    template<typename Rep, typename Period> // clang-format off
        requires( std::integral<Rep> || std::floating_point<Rep> )
    class base_unit<Rep, Period, time_tag> : // clang-format on
          public std::chrono::duration<Rep, Period> {
    };

    template<typename Rep, typename Period>
    using time = base_unit<Rep, Period, time_tag>;

    using attoseconds  = time<int, std::atto>;
    using femtoseconds = time<int, std::femto>;
    using picoseconds  = time<int, std::pico>;
    using nanoseconds  = time<std::chrono::nanoseconds::rep, std::nano>;
    using microseconds = time<std::chrono::microseconds::rep, std::micro>;
    using milliseconds = time<std::chrono::milliseconds::rep, std::milli>;
    using centiseconds = time<int, std::centi>;
    using deciseconds  = time<int, std::deci>;
    using seconds      = time<std::chrono::seconds::rep, std::ratio<1>>;
    using decaseconds  = time<int, std::deca>;
    using hectoseconds = time<int, std::hecto>;
    using kiloseconds  = time<int, std::kilo>;
    using megaseconds  = time<int, std::mega>;
    using gigaseconds  = time<int, std::giga>;
    using teraseconds  = time<int, std::tera>;
    using petaseconds  = time<int, std::peta>;
    using exaseconds   = time<int, std::exa>;
    using minutes =
        time<std::chrono::minutes::rep, std::chrono::minutes::period>;
    using hours  = time<std::chrono::hours::rep, std::chrono::hours::period>;
    using days   = time<std::chrono::days::rep, std::chrono::days::period>;
    using weeks  = time<std::chrono::weeks::rep, std::chrono::weeks::period>;
    using months = time<std::chrono::months::rep, std::chrono::months::period>;
    using years  = time<std::chrono::years::rep, std::chrono::years::period>;

    struct length_tag {
        constexpr length_tag() noexcept = default;
    };

    template<typename Rep, typename Period>
    using length = base_unit<Rep, Period, length_tag>;

    using attometers  = length<int, std::atto>;
    using femtometers = length<int, std::femto>;
    using picometers  = length<int, std::pico>;
    using nanometers  = length<int, std::nano>;
    using micrometers = length<int, std::micro>;
    using millimeters = length<int, std::milli>;
    using centimeters = length<int, std::centi>;
    using decimeters  = length<int, std::deci>;
    using meters      = length<int, std::ratio<1>>;
    using decameters  = length<int, std::deca>;
    using hectometers = length<int, std::hecto>;
    using kilometers  = length<int, std::kilo>;
    using megameters  = length<int, std::mega>;
    using gigameters  = length<int, std::giga>;
    using terameters  = length<int, std::tera>;
    using petameters  = length<int, std::peta>;
    using exameters   = length<int, std::exa>;

    struct mass_tag {
        constexpr mass_tag() noexcept = default;
    };

    template<typename Rep, typename Period>
    using mass = base_unit<Rep, Period, mass_tag>;

    using attograms  = mass<int, std::atto>;
    using femtograms = mass<int, std::femto>;
    using picograms  = mass<int, std::pico>;
    using nanograms  = mass<int, std::nano>;
    using micrograms = mass<int, std::micro>;
    using milligrams = mass<int, std::milli>;
    using centigrams = mass<int, std::centi>;
    using decigrams  = mass<int, std::deci>;
    using grams      = mass<int, std::ratio<1>>;
    using decagrams  = mass<int, std::deca>;
    using hectograms = mass<int, std::hecto>;
    using kilograms  = mass<int, std::kilo>;
    using megagrams  = mass<int, std::mega>;
    using gigagrams  = mass<int, std::giga>;
    using teragrams  = mass<int, std::tera>;
    using petagrams  = mass<int, std::peta>;
    using exagrams   = mass<int, std::exa>;

    struct electric_current_tag {
        constexpr electric_current_tag() noexcept = default;
    };

    template<typename Rep, typename Period>
    using electric_current = base_unit<Rep, Period, electric_current_tag>;

    using attoamperes  = electric_current<int, std::atto>;
    using femtoamperes = electric_current<int, std::femto>;
    using picoamperes  = electric_current<int, std::pico>;
    using nanoamperes  = electric_current<int, std::nano>;
    using microamperes = electric_current<int, std::micro>;
    using milliamperes = electric_current<int, std::milli>;
    using centiamperes = electric_current<int, std::centi>;
    using deciamperes  = electric_current<int, std::deci>;
    using amperes      = electric_current<int, std::ratio<1>>;
    using decaamperes  = electric_current<int, std::deca>;
    using hectoamperes = electric_current<int, std::hecto>;
    using kiloamperes  = electric_current<int, std::kilo>;
    using megaamperes  = electric_current<int, std::mega>;
    using gigaamperes  = electric_current<int, std::giga>;
    using teraamperes  = electric_current<int, std::tera>;
    using petaamperes  = electric_current<int, std::peta>;
    using exaamperes   = electric_current<int, std::exa>;

    struct thermodynamic_temperature_tag {
        constexpr thermodynamic_temperature_tag() noexcept = default;
    };

    template<typename Rep, typename Period>
    using thermodynamic_temperature =
        base_unit<Rep, Period, thermodynamic_temperature_tag>;

    using attokelvins  = thermodynamic_temperature<int, std::atto>;
    using femtokelvins = thermodynamic_temperature<int, std::femto>;
    using picokelvins  = thermodynamic_temperature<int, std::pico>;
    using nanokelvins  = thermodynamic_temperature<int, std::nano>;
    using microkelvins = thermodynamic_temperature<int, std::micro>;
    using millikelvins = thermodynamic_temperature<int, std::milli>;
    using centikelvins = thermodynamic_temperature<int, std::centi>;
    using decikelvins  = thermodynamic_temperature<int, std::deci>;
    using kelvins      = thermodynamic_temperature<int, std::ratio<1>>;
    using decakelvins  = thermodynamic_temperature<int, std::deca>;
    using hectokelvins = thermodynamic_temperature<int, std::hecto>;
    using kilokelvins  = thermodynamic_temperature<int, std::kilo>;
    using megakelvins  = thermodynamic_temperature<int, std::mega>;
    using gigakelvins  = thermodynamic_temperature<int, std::giga>;
    using terakelvins  = thermodynamic_temperature<int, std::tera>;
    using petakelvins  = thermodynamic_temperature<int, std::peta>;
    using exakelvins   = thermodynamic_temperature<int, std::exa>;

    struct amount_of_substance_tag {
        constexpr amount_of_substance_tag() noexcept = default;
    };

    template<typename Rep, typename Period>
    using amount_of_substance = base_unit<Rep, Period, amount_of_substance_tag>;

    using attomoles  = amount_of_substance<int, std::atto>;
    using femtomoles = amount_of_substance<int, std::femto>;
    using picomoles  = amount_of_substance<int, std::pico>;
    using nanomoles  = amount_of_substance<int, std::nano>;
    using micromoles = amount_of_substance<int, std::micro>;
    using millimoles = amount_of_substance<int, std::milli>;
    using centimoles = amount_of_substance<int, std::centi>;
    using decimoles  = amount_of_substance<int, std::deci>;
    using moles      = amount_of_substance<int, std::ratio<1>>;
    using decamoles  = amount_of_substance<int, std::deca>;
    using hectomoles = amount_of_substance<int, std::hecto>;
    using kilomoles  = amount_of_substance<int, std::kilo>;
    using megamoles  = amount_of_substance<int, std::mega>;
    using gigamoles  = amount_of_substance<int, std::giga>;
    using teramoles  = amount_of_substance<int, std::tera>;
    using petamoles  = amount_of_substance<int, std::peta>;
    using examoles   = amount_of_substance<int, std::exa>;

    struct luminous_intensity_tag {
        constexpr luminous_intensity_tag() noexcept = default;
    };

    template<typename Rep, typename Period>
    using luminous_intensity = base_unit<Rep, Period, luminous_intensity_tag>;

    using attocandelas  = luminous_intensity<int, std::atto>;
    using femtocandelas = luminous_intensity<int, std::femto>;
    using picocandelas  = luminous_intensity<int, std::pico>;
    using nanocandelas  = luminous_intensity<int, std::nano>;
    using microcandelas = luminous_intensity<int, std::micro>;
    using millicandelas = luminous_intensity<int, std::milli>;
    using centicandelas = luminous_intensity<int, std::centi>;
    using decicandelas  = luminous_intensity<int, std::deci>;
    using candelas      = luminous_intensity<int, std::ratio<1>>;
    using decacandelas  = luminous_intensity<int, std::deca>;
    using hectocandelas = luminous_intensity<int, std::hecto>;
    using kilocandelas  = luminous_intensity<int, std::kilo>;
    using megacandelas  = luminous_intensity<int, std::mega>;
    using gigacandelas  = luminous_intensity<int, std::giga>;
    using teracandelas  = luminous_intensity<int, std::tera>;
    using petacandelas  = luminous_intensity<int, std::peta>;
    using exacandelas   = luminous_intensity<int, std::exa>;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_HPP
