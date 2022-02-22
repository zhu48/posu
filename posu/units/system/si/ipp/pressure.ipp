
[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_aPa(unsigned long long value)
        -> attopascals
{
    return attopascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_aPa(long double value)
        -> basic_pascal<double, atto>
{
    return basic_pascal<double, atto>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_fPa(unsigned long long value)
        -> femtopascals
{
    return femtopascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_fPa(long double value)
        -> basic_pascal<double, femto>
{
    return basic_pascal<double, femto>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_pPa(unsigned long long value)
        -> picopascals
{
    return picopascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_pPa(long double value)
        -> basic_pascal<double, pico>
{
    return basic_pascal<double, pico>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_nPa(unsigned long long value)
        -> nanopascals
{
    return nanopascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_nPa(long double value)
        -> basic_pascal<double, nano>
{
    return basic_pascal<double, nano>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_uPa(unsigned long long value)
        -> micropascals
{
    return micropascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_uPa(long double value)
        -> basic_pascal<double, micro>
{
    return basic_pascal<double, micro>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_mPa(unsigned long long value)
        -> millipascals
{
    return millipascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_mPa(long double value)
        -> basic_pascal<double, milli>
{
    return basic_pascal<double, milli>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_cPa(unsigned long long value)
        -> centipascals
{
    return centipascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_cPa(long double value)
        -> basic_pascal<double, centi>
{
    return basic_pascal<double, centi>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_dPa(unsigned long long value)
        -> decipascals
{
    return decipascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_dPa(long double value)
        -> basic_pascal<double, deci>
{
    return basic_pascal<double, deci>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_Pa(unsigned long long value) -> pascals
{
    return pascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_Pa(long double value)
        -> basic_pascal<double, ratio<1>>
{
    return basic_pascal<double, ratio<1>>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_daPa(unsigned long long value)
        -> decapascals
{
    return decapascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_daPa(long double value)
        -> basic_pascal<double, deca>
{
    return basic_pascal<double, deca>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_hPa(unsigned long long value)
        -> hectopascals
{
    return hectopascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_hPa(long double value)
        -> basic_pascal<double, hecto>
{
    return basic_pascal<double, hecto>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_kPa(unsigned long long value)
        -> kilopascals
{
    return kilopascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_kPa(long double value)
        -> basic_pascal<double, kilo>
{
    return basic_pascal<double, kilo>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_MPa(unsigned long long value)
        -> megapascals
{
    return megapascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_MPa(long double value)
        -> basic_pascal<double, mega>
{
    return basic_pascal<double, mega>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_GPa(unsigned long long value)
        -> gigapascals
{
    return gigapascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_GPa(long double value)
        -> basic_pascal<double, giga>
{
    return basic_pascal<double, giga>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_TPa(unsigned long long value)
        -> terapascals
{
    return terapascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_TPa(long double value)
        -> basic_pascal<double, tera>
{
    return basic_pascal<double, tera>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_PPa(unsigned long long value)
        -> petapascals
{
    return petapascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_PPa(long double value)
        -> basic_pascal<double, peta>
{
    return basic_pascal<double, peta>{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_EPa(unsigned long long value)
        -> exapascals
{
    return exapascals{value};
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::pressure_literals::operator""_EPa(long double value)
        -> basic_pascal<double, exa>
{
    return basic_pascal<double, exa>{value};
}
