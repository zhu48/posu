
[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_aN(unsigned long long value)
        -> attonewtons
{
    return attonewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_aN(long double value)
        -> basic_newton<double, std::atto>
{
    return basic_newton<double, std::atto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_fN(unsigned long long value)
        -> femtonewtons
{
    return femtonewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_fN(long double value)
        -> basic_newton<double, std::femto>
{
    return basic_newton<double, std::femto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_pN(unsigned long long value)
        -> piconewtons
{
    return piconewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_pN(long double value)
        -> basic_newton<double, std::pico>
{
    return basic_newton<double, std::pico>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_nN(unsigned long long value)
        -> nanonewtons
{
    return nanonewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_nN(long double value)
        -> basic_newton<double, std::nano>
{
    return basic_newton<double, std::nano>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_uN(unsigned long long value)
        -> micronewtons
{
    return micronewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_uN(long double value)
        -> basic_newton<double, std::micro>
{
    return basic_newton<double, std::micro>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_mN(unsigned long long value)
        -> millinewtons
{
    return millinewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_mN(long double value)
        -> basic_newton<double, std::milli>
{
    return basic_newton<double, std::milli>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_cN(unsigned long long value)
        -> centinewtons
{
    return centinewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_cN(long double value)
        -> basic_newton<double, std::centi>
{
    return basic_newton<double, std::centi>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_dN(unsigned long long value)
        -> decinewtons
{
    return decinewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_dN(long double value)
        -> basic_newton<double, std::deci>
{
    return basic_newton<double, std::deci>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_N(unsigned long long value) -> newtons
{
    return newtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_N(long double value)
        -> basic_newton<double, std::ratio<1>>
{
    return basic_newton<double, std::ratio<1>>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_daN(unsigned long long value)
        -> decanewtons
{
    return decanewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_daN(long double value)
        -> basic_newton<double, std::deca>
{
    return basic_newton<double, std::deca>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_hN(unsigned long long value)
        -> hectonewtons
{
    return hectonewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_hN(long double value)
        -> basic_newton<double, std::hecto>
{
    return basic_newton<double, std::hecto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_kN(unsigned long long value)
        -> kilonewtons
{
    return kilonewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_kN(long double value)
        -> basic_newton<double, std::kilo>
{
    return basic_newton<double, std::kilo>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_MN(unsigned long long value)
        -> meganewtons
{
    return meganewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_MN(long double value)
        -> basic_newton<double, std::mega>
{
    return basic_newton<double, std::mega>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_GN(unsigned long long value)
        -> giganewtons
{
    return giganewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_GN(long double value)
        -> basic_newton<double, std::giga>
{
    return basic_newton<double, std::giga>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_TN(unsigned long long value)
        -> teranewtons
{
    return teranewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_TN(long double value)
        -> basic_newton<double, std::tera>
{
    return basic_newton<double, std::tera>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_PN(unsigned long long value)
        -> petanewtons
{
    return petanewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_PN(long double value)
        -> basic_newton<double, std::peta>
{
    return basic_newton<double, std::peta>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_EN(unsigned long long value) -> exanewtons
{
    return exanewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_EN(long double value)
        -> basic_newton<double, std::exa>
{
    return basic_newton<double, std::exa>(value);
}
