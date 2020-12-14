
namespace posu::units {

    inline namespace literals {

        inline namespace electric_current_literals {

            [[nodiscard]] constexpr auto operator""_aA(unsigned long long value) -> attoamperes
            {
                return attoamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_aA(long double value)
                -> electric_current<double, std::atto>
            {
                return electric_current<double, std::atto>(value);
            }

            [[nodiscard]] constexpr auto operator""_fA(unsigned long long value) -> femtoamperes
            {
                return femtoamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_fA(long double value)
                -> electric_current<double, std::femto>
            {
                return electric_current<double, std::femto>(value);
            }

            [[nodiscard]] constexpr auto operator""_pA(unsigned long long value) -> picoamperes
            {
                return picoamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_pA(long double value)
                -> electric_current<double, std::pico>
            {
                return electric_current<double, std::pico>(value);
            }

            [[nodiscard]] constexpr auto operator""_nA(unsigned long long value) -> nanoamperes
            {
                return nanoamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_nA(long double value)
                -> electric_current<double, std::nano>
            {
                return electric_current<double, std::nano>(value);
            }

            [[nodiscard]] constexpr auto operator""_uA(unsigned long long value) -> microamperes
            {
                return microamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_uA(long double value)
                -> electric_current<double, std::micro>
            {
                return electric_current<double, std::micro>(value);
            }

            [[nodiscard]] constexpr auto operator""_mA(unsigned long long value) -> milliamperes
            {
                return milliamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_mA(long double value)
                -> electric_current<double, std::milli>
            {
                return electric_current<double, std::milli>(value);
            }

            [[nodiscard]] constexpr auto operator""_cA(unsigned long long value) -> centiamperes
            {
                return centiamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_cA(long double value)
                -> electric_current<double, std::centi>
            {
                return electric_current<double, std::centi>(value);
            }

            [[nodiscard]] constexpr auto operator""_dA(unsigned long long value) -> deciamperes
            {
                return deciamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_dA(long double value)
                -> electric_current<double, std::deci>
            {
                return electric_current<double, std::deci>(value);
            }

            [[nodiscard]] constexpr auto operator""_A(unsigned long long value) -> amperes
            {
                return amperes(value);
            }

            [[nodiscard]] constexpr auto operator""_A(long double value)
                -> electric_current<double, std::ratio<1>>
            {
                return electric_current<double, std::ratio<1>>(value);
            }

            [[nodiscard]] constexpr auto operator""_daA(unsigned long long value) -> decaamperes
            {
                return decaamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_daA(long double value)
                -> electric_current<double, std::deca>
            {
                return electric_current<double, std::deca>(value);
            }

            [[nodiscard]] constexpr auto operator""_hA(unsigned long long value) -> hectoamperes
            {
                return hectoamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_hA(long double value)
                -> electric_current<double, std::hecto>
            {
                return electric_current<double, std::hecto>(value);
            }

            [[nodiscard]] constexpr auto operator""_kA(unsigned long long value) -> kiloamperes
            {
                return kiloamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_kA(long double value)
                -> electric_current<double, std::kilo>
            {
                return electric_current<double, std::kilo>(value);
            }

            [[nodiscard]] constexpr auto operator""_MA(unsigned long long value) -> megaamperes
            {
                return megaamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_MA(long double value)
                -> electric_current<double, std::mega>
            {
                return electric_current<double, std::mega>(value);
            }

            [[nodiscard]] constexpr auto operator""_GA(unsigned long long value) -> gigaamperes
            {
                return gigaamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_GA(long double value)
                -> electric_current<double, std::giga>
            {
                return electric_current<double, std::giga>(value);
            }

            [[nodiscard]] constexpr auto operator""_TA(unsigned long long value) -> teraamperes
            {
                return teraamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_TA(long double value)
                -> electric_current<double, std::tera>
            {
                return electric_current<double, std::tera>(value);
            }

            [[nodiscard]] constexpr auto operator""_PA(unsigned long long value) -> petaamperes
            {
                return petaamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_PA(long double value)
                -> electric_current<double, std::peta>
            {
                return electric_current<double, std::peta>(value);
            }

            [[nodiscard]] constexpr auto operator""_EA(unsigned long long value) -> exaamperes
            {
                return exaamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_EA(long double value)
                -> electric_current<double, std::exa>
            {
                return electric_current<double, std::exa>(value);
            }

        } // namespace electric_current_literals

    } // namespace literals

} // namespace posu::units
