
[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_aHz(unsigned long long value)
        -> attohertz
{
    return attohertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_aHz(long double value)
        -> frequency<double, std::atto>
{
    return frequency<double, std::atto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_fHz(unsigned long long value)
        -> femtohertz
{
    return femtohertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_fHz(long double value)
        -> frequency<double, std::femto>
{
    return frequency<double, std::femto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_pHz(unsigned long long value)
        -> picohertz
{
    return picohertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_pHz(long double value)
        -> frequency<double, std::pico>
{
    return frequency<double, std::pico>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_nHz(unsigned long long value)
        -> nanohertz
{
    return nanohertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_nHz(long double value)
        -> frequency<double, std::nano>
{
    return frequency<double, std::nano>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_uHz(unsigned long long value)
        -> microhertz
{
    return microhertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_uHz(long double value)
        -> frequency<double, std::micro>
{
    return frequency<double, std::micro>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_mHz(unsigned long long value)
        -> millihertz
{
    return millihertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_mHz(long double value)
        -> frequency<double, std::milli>
{
    return frequency<double, std::milli>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_cHz(unsigned long long value)
        -> centihertz
{
    return centihertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_cHz(long double value)
        -> frequency<double, std::centi>
{
    return frequency<double, std::centi>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_dHz(unsigned long long value)
        -> decihertz
{
    return decihertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_dHz(long double value)
        -> frequency<double, std::deci>
{
    return frequency<double, std::deci>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_Hz(unsigned long long value) -> hertz
{
    return hertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_Hz(long double value)
        -> frequency<double, std::ratio<1>>
{
    return frequency<double, std::ratio<1>>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_daHz(unsigned long long value)
        -> decahertz
{
    return decahertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_daHz(long double value)
        -> frequency<double, std::deca>
{
    return frequency<double, std::deca>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_hHz(unsigned long long value)
        -> hectohertz
{
    return hectohertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_hHz(long double value)
        -> frequency<double, std::hecto>
{
    return frequency<double, std::hecto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_kHz(unsigned long long value)
        -> kilohertz
{
    return kilohertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_kHz(long double value)
        -> frequency<double, std::kilo>
{
    return frequency<double, std::kilo>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_MHz(unsigned long long value)
        -> megahertz
{
    return megahertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_MHz(long double value)
        -> frequency<double, std::mega>
{
    return frequency<double, std::mega>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_GHz(unsigned long long value)
        -> gigahertz
{
    return gigahertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_GHz(long double value)
        -> frequency<double, std::giga>
{
    return frequency<double, std::giga>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_THz(unsigned long long value)
        -> terahertz
{
    return terahertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_THz(long double value)
        -> frequency<double, std::tera>
{
    return frequency<double, std::tera>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_PHz(unsigned long long value)
        -> petahertz
{
    return petahertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_PHz(long double value)
        -> frequency<double, std::peta>
{
    return frequency<double, std::peta>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_EHz(unsigned long long value)
        -> exahertz
{
    return exahertz(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::frequency_literals::operator""_EHz(long double value)
        -> frequency<double, std::exa>
{
    return frequency<double, std::exa>(value);
}
