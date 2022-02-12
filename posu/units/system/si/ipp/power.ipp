
[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_aW(unsigned long long value) -> attowatts
{
    return attowatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_aW(long double value)
        -> basic_watt<double, atto>
{
    return basic_watt<double, atto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_fW(unsigned long long value) -> femtowatts
{
    return femtowatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_fW(long double value)
        -> basic_watt<double, femto>
{
    return basic_watt<double, femto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_pW(unsigned long long value) -> picowatts
{
    return picowatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_pW(long double value)
        -> basic_watt<double, pico>
{
    return basic_watt<double, pico>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_nW(unsigned long long value) -> nanowatts
{
    return nanowatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_nW(long double value)
        -> basic_watt<double, nano>
{
    return basic_watt<double, nano>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_uW(unsigned long long value) -> microwatts
{
    return microwatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_uW(long double value)
        -> basic_watt<double, micro>
{
    return basic_watt<double, micro>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_mW(unsigned long long value) -> milliwatts
{
    return milliwatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_mW(long double value)
        -> basic_watt<double, milli>
{
    return basic_watt<double, milli>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_cW(unsigned long long value) -> centiwatts
{
    return centiwatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_cW(long double value)
        -> basic_watt<double, centi>
{
    return basic_watt<double, centi>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_dW(unsigned long long value) -> deciwatts
{
    return deciwatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_dW(long double value)
        -> basic_watt<double, deci>
{
    return basic_watt<double, deci>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_W(unsigned long long value) -> watts
{
    return watts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_W(long double value)
        -> basic_watt<double, ratio<1>>
{
    return basic_watt<double, ratio<1>>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_daW(unsigned long long value) -> decawatts
{
    return decawatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_daW(long double value)
        -> basic_watt<double, deca>
{
    return basic_watt<double, deca>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_hW(unsigned long long value) -> hectowatts
{
    return hectowatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_hW(long double value)
        -> basic_watt<double, hecto>
{
    return basic_watt<double, hecto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_kW(unsigned long long value) -> kilowatts
{
    return kilowatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_kW(long double value)
        -> basic_watt<double, kilo>
{
    return basic_watt<double, kilo>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_MW(unsigned long long value) -> megawatts
{
    return megawatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_MW(long double value)
        -> basic_watt<double, mega>
{
    return basic_watt<double, mega>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_GW(unsigned long long value) -> gigawatts
{
    return gigawatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_GW(long double value)
        -> basic_watt<double, giga>
{
    return basic_watt<double, giga>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_TW(unsigned long long value) -> terawatts
{
    return terawatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_TW(long double value)
        -> basic_watt<double, tera>
{
    return basic_watt<double, tera>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_PW(unsigned long long value) -> petawatts
{
    return petawatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_PW(long double value)
        -> basic_watt<double, peta>
{
    return basic_watt<double, peta>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_EW(unsigned long long value) -> exawatts
{
    return exawatts(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::power_literals::operator""_EW(long double value)
        -> basic_watt<double, exa>
{
    return basic_watt<double, exa>(value);
}
