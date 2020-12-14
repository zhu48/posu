
namespace posu::units {

    inline namespace literals {

        inline namespace thermodynamic_temperature_literals {

            [[nodiscard]] constexpr auto operator""_aK(unsigned long long value) -> attokelvins
            {
                return attokelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_aK(long double value)
                -> thermodynamic_temperature<double, std::atto>
            {
                return thermodynamic_temperature<double, std::atto>(value);
            }

            [[nodiscard]] constexpr auto operator""_fK(unsigned long long value) -> femtokelvins
            {
                return femtokelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_fK(long double value)
                -> thermodynamic_temperature<double, std::femto>
            {
                return thermodynamic_temperature<double, std::femto>(value);
            }

            [[nodiscard]] constexpr auto operator""_pK(unsigned long long value) -> picokelvins
            {
                return picokelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_pK(long double value)
                -> thermodynamic_temperature<double, std::pico>
            {
                return thermodynamic_temperature<double, std::pico>(value);
            }

            [[nodiscard]] constexpr auto operator""_nK(unsigned long long value) -> nanokelvins
            {
                return nanokelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_nK(long double value)
                -> thermodynamic_temperature<double, std::nano>
            {
                return thermodynamic_temperature<double, std::nano>(value);
            }

            [[nodiscard]] constexpr auto operator""_uK(unsigned long long value) -> microkelvins
            {
                return microkelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_uK(long double value)
                -> thermodynamic_temperature<double, std::micro>
            {
                return thermodynamic_temperature<double, std::micro>(value);
            }

            [[nodiscard]] constexpr auto operator""_mK(unsigned long long value) -> millikelvins
            {
                return millikelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_mK(long double value)
                -> thermodynamic_temperature<double, std::milli>
            {
                return thermodynamic_temperature<double, std::milli>(value);
            }

            [[nodiscard]] constexpr auto operator""_cK(unsigned long long value) -> centikelvins
            {
                return centikelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_cK(long double value)
                -> thermodynamic_temperature<double, std::centi>
            {
                return thermodynamic_temperature<double, std::centi>(value);
            }

            [[nodiscard]] constexpr auto operator""_dK(unsigned long long value) -> decikelvins
            {
                return decikelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_dK(long double value)
                -> thermodynamic_temperature<double, std::deci>
            {
                return thermodynamic_temperature<double, std::deci>(value);
            }

            [[nodiscard]] constexpr auto operator""_K(unsigned long long value) -> kelvins
            {
                return kelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_K(long double value)
                -> thermodynamic_temperature<double, std::ratio<1>>
            {
                return thermodynamic_temperature<double, std::ratio<1>>(value);
            }

            [[nodiscard]] constexpr auto operator""_daK(unsigned long long value) -> decakelvins
            {
                return decakelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_daK(long double value)
                -> thermodynamic_temperature<double, std::deca>
            {
                return thermodynamic_temperature<double, std::deca>(value);
            }

            [[nodiscard]] constexpr auto operator""_hK(unsigned long long value) -> hectokelvins
            {
                return hectokelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_hK(long double value)
                -> thermodynamic_temperature<double, std::hecto>
            {
                return thermodynamic_temperature<double, std::hecto>(value);
            }

            [[nodiscard]] constexpr auto operator""_kK(unsigned long long value) -> kilokelvins
            {
                return kilokelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_kK(long double value)
                -> thermodynamic_temperature<double, std::kilo>
            {
                return thermodynamic_temperature<double, std::kilo>(value);
            }

            [[nodiscard]] constexpr auto operator""_MK(unsigned long long value) -> megakelvins
            {
                return megakelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_MK(long double value)
                -> thermodynamic_temperature<double, std::mega>
            {
                return thermodynamic_temperature<double, std::mega>(value);
            }

            [[nodiscard]] constexpr auto operator""_GK(unsigned long long value) -> gigakelvins
            {
                return gigakelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_GK(long double value)
                -> thermodynamic_temperature<double, std::giga>
            {
                return thermodynamic_temperature<double, std::giga>(value);
            }

            [[nodiscard]] constexpr auto operator""_TK(unsigned long long value) -> terakelvins
            {
                return terakelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_TK(long double value)
                -> thermodynamic_temperature<double, std::tera>
            {
                return thermodynamic_temperature<double, std::tera>(value);
            }

            [[nodiscard]] constexpr auto operator""_PK(unsigned long long value) -> petakelvins
            {
                return petakelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_PK(long double value)
                -> thermodynamic_temperature<double, std::peta>
            {
                return thermodynamic_temperature<double, std::peta>(value);
            }

            [[nodiscard]] constexpr auto operator""_EK(unsigned long long value) -> exakelvins
            {
                return exakelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_EK(long double value)
                -> thermodynamic_temperature<double, std::exa>
            {
                return thermodynamic_temperature<double, std::exa>(value);
            }

        } // namespace thermodynamic_temperature_literals

    } // namespace literals

} // namespace posu::units
