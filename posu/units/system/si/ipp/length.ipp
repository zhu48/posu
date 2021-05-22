
[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_am(unsigned long long value)
        -> attometers
{
    return attometers(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_am(long double value)
        -> basic_meter<double, std::atto>
{
    return basic_meter<double, std::atto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_fm(unsigned long long value)
        -> femtometers
{
    return femtometers(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_fm(long double value)
        -> basic_meter<double, std::femto>
{
    return basic_meter<double, std::femto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_pm(unsigned long long value)
        -> picometers
{
    return picometers(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_pm(long double value)
        -> basic_meter<double, std::pico>
{
    return basic_meter<double, std::pico>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_nm(unsigned long long value)
        -> nanometers
{
    return nanometers(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_nm(long double value)
        -> basic_meter<double, std::nano>
{
    return basic_meter<double, std::nano>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_um(unsigned long long value)
        -> micrometers
{
    return micrometers(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_um(long double value)
        -> basic_meter<double, std::micro>
{
    return basic_meter<double, std::micro>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_mm(unsigned long long value)
        -> millimeters
{
    return millimeters(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_mm(long double value)
        -> basic_meter<double, std::milli>
{
    return basic_meter<double, std::milli>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_cm(unsigned long long value)
        -> centimeters
{
    return centimeters(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_cm(long double value)
        -> basic_meter<double, std::centi>
{
    return basic_meter<double, std::centi>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_dm(unsigned long long value)
        -> decimeters
{
    return decimeters(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_dm(long double value)
        -> basic_meter<double, std::deci>
{
    return basic_meter<double, std::deci>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_m(unsigned long long value) -> meters
{
    return meters(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_m(long double value)
        -> basic_meter<double, std::ratio<1>>
{
    return basic_meter<double, std::ratio<1>>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_dam(unsigned long long value)
        -> decameters
{
    return decameters(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_dam(long double value)
        -> basic_meter<double, std::deca>
{
    return basic_meter<double, std::deca>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_hm(unsigned long long value)
        -> hectometers
{
    return hectometers(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_hm(long double value)
        -> basic_meter<double, std::hecto>
{
    return basic_meter<double, std::hecto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_km(unsigned long long value)
        -> kilometers
{
    return kilometers(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_km(long double value)
        -> basic_meter<double, std::kilo>
{
    return basic_meter<double, std::kilo>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_Mm(unsigned long long value)
        -> megameters
{
    return megameters(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_Mm(long double value)
        -> basic_meter<double, std::mega>
{
    return basic_meter<double, std::mega>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_Gm(unsigned long long value)
        -> gigameters
{
    return gigameters(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_Gm(long double value)
        -> basic_meter<double, std::giga>
{
    return basic_meter<double, std::giga>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_Tm(unsigned long long value)
        -> terameters
{
    return terameters(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_Tm(long double value)
        -> basic_meter<double, std::tera>
{
    return basic_meter<double, std::tera>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_Pm(unsigned long long value)
        -> petameters
{
    return petameters(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_Pm(long double value)
        -> basic_meter<double, std::peta>
{
    return basic_meter<double, std::peta>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_Em(unsigned long long value) -> exameters
{
    return exameters(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::length_literals::operator""_Em(long double value)
        -> basic_meter<double, std::exa>
{
    return basic_meter<double, std::exa>(value);
}
