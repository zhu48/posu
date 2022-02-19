
[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_aHz(unsigned long long value)
        -> attohertz
{
    return attohertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_aHz(long double value)
        -> basic_hertz<double, atto>
{
    return basic_hertz<double, atto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_fHz(unsigned long long value)
        -> femtohertz
{
    return femtohertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_fHz(long double value)
        -> basic_hertz<double, femto>
{
    return basic_hertz<double, femto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_pHz(unsigned long long value)
        -> picohertz
{
    return picohertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_pHz(long double value)
        -> basic_hertz<double, pico>
{
    return basic_hertz<double, pico>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_nHz(unsigned long long value)
        -> nanohertz
{
    return nanohertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_nHz(long double value)
        -> basic_hertz<double, nano>
{
    return basic_hertz<double, nano>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_uHz(unsigned long long value)
        -> microhertz
{
    return microhertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_uHz(long double value)
        -> basic_hertz<double, micro>
{
    return basic_hertz<double, micro>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_mHz(unsigned long long value)
        -> millihertz
{
    return millihertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_mHz(long double value)
        -> basic_hertz<double, milli>
{
    return basic_hertz<double, milli>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_cHz(unsigned long long value)
        -> centihertz
{
    return centihertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_cHz(long double value)
        -> basic_hertz<double, centi>
{
    return basic_hertz<double, centi>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_dHz(unsigned long long value)
        -> decihertz
{
    return decihertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_dHz(long double value)
        -> basic_hertz<double, deci>
{
    return basic_hertz<double, deci>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_Hz(unsigned long long value) -> hertz
{
    return hertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_Hz(long double value)
        -> basic_hertz<double, ratio<1>>
{
    return basic_hertz<double, ratio<1>>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_daHz(unsigned long long value)
        -> decahertz
{
    return decahertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_daHz(long double value)
        -> basic_hertz<double, deca>
{
    return basic_hertz<double, deca>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_hHz(unsigned long long value)
        -> hectohertz
{
    return hectohertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_hHz(long double value)
        -> basic_hertz<double, hecto>
{
    return basic_hertz<double, hecto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_kHz(unsigned long long value)
        -> kilohertz
{
    return kilohertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_kHz(long double value)
        -> basic_hertz<double, kilo>
{
    return basic_hertz<double, kilo>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_MHz(unsigned long long value)
        -> megahertz
{
    return megahertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_MHz(long double value)
        -> basic_hertz<double, mega>
{
    return basic_hertz<double, mega>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_GHz(unsigned long long value)
        -> gigahertz
{
    return gigahertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_GHz(long double value)
        -> basic_hertz<double, giga>
{
    return basic_hertz<double, giga>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_THz(unsigned long long value)
        -> terahertz
{
    return terahertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_THz(long double value)
        -> basic_hertz<double, tera>
{
    return basic_hertz<double, tera>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_PHz(unsigned long long value)
        -> petahertz
{
    return petahertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_PHz(long double value)
        -> basic_hertz<double, peta>
{
    return basic_hertz<double, peta>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_EHz(unsigned long long value)
        -> exahertz
{
    return exahertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_EHz(long double value)
        -> basic_hertz<double, exa>
{
    return basic_hertz<double, exa>(value);
}
