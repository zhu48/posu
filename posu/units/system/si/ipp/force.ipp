
[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_aN(unsigned long long value)
        -> attonewtons
{
    return attonewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_aN(long double value)
        -> basic_newton<double, atto>
{
    return basic_newton<double, atto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_fN(unsigned long long value)
        -> femtonewtons
{
    return femtonewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_fN(long double value)
        -> basic_newton<double, femto>
{
    return basic_newton<double, femto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_pN(unsigned long long value)
        -> piconewtons
{
    return piconewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_pN(long double value)
        -> basic_newton<double, pico>
{
    return basic_newton<double, pico>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_nN(unsigned long long value)
        -> nanonewtons
{
    return nanonewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_nN(long double value)
        -> basic_newton<double, nano>
{
    return basic_newton<double, nano>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_uN(unsigned long long value)
        -> micronewtons
{
    return micronewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_uN(long double value)
        -> basic_newton<double, micro>
{
    return basic_newton<double, micro>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_mN(unsigned long long value)
        -> millinewtons
{
    return millinewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_mN(long double value)
        -> basic_newton<double, milli>
{
    return basic_newton<double, milli>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_cN(unsigned long long value)
        -> centinewtons
{
    return centinewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_cN(long double value)
        -> basic_newton<double, centi>
{
    return basic_newton<double, centi>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_dN(unsigned long long value)
        -> decinewtons
{
    return decinewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_dN(long double value)
        -> basic_newton<double, deci>
{
    return basic_newton<double, deci>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_N(unsigned long long value) -> newtons
{
    return newtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_N(long double value)
        -> basic_newton<double, ratio<1>>
{
    return basic_newton<double, ratio<1>>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_daN(unsigned long long value)
        -> decanewtons
{
    return decanewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_daN(long double value)
        -> basic_newton<double, deca>
{
    return basic_newton<double, deca>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_hN(unsigned long long value)
        -> hectonewtons
{
    return hectonewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_hN(long double value)
        -> basic_newton<double, hecto>
{
    return basic_newton<double, hecto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_kN(unsigned long long value)
        -> kilonewtons
{
    return kilonewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_kN(long double value)
        -> basic_newton<double, kilo>
{
    return basic_newton<double, kilo>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_MN(unsigned long long value)
        -> meganewtons
{
    return meganewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_MN(long double value)
        -> basic_newton<double, mega>
{
    return basic_newton<double, mega>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_GN(unsigned long long value)
        -> giganewtons
{
    return giganewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_GN(long double value)
        -> basic_newton<double, giga>
{
    return basic_newton<double, giga>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_TN(unsigned long long value)
        -> teranewtons
{
    return teranewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_TN(long double value)
        -> basic_newton<double, tera>
{
    return basic_newton<double, tera>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_PN(unsigned long long value)
        -> petanewtons
{
    return petanewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_PN(long double value)
        -> basic_newton<double, peta>
{
    return basic_newton<double, peta>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_EN(unsigned long long value) -> exanewtons
{
    return exanewtons(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::force_literals::operator""_EN(long double value)
        -> basic_newton<double, exa>
{
    return basic_newton<double, exa>(value);
}
