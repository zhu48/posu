
[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_as(unsigned long long value)
        -> attoseconds
{
    return attoseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_as(long double value)
        -> basic_second<double, atto>
{
    return basic_second<double, atto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_fs(unsigned long long value)
        -> femtoseconds
{
    return femtoseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_fs(long double value)
        -> basic_second<double, femto>
{
    return basic_second<double, femto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_ps(unsigned long long value)
        -> picoseconds
{
    return picoseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_ps(long double value)
        -> basic_second<double, pico>
{
    return basic_second<double, pico>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_ns(unsigned long long value)
        -> nanoseconds
{
    return nanoseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_ns(long double value)
        -> basic_second<double, nano>
{
    return basic_second<double, nano>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_us(unsigned long long value)
        -> microseconds
{
    return microseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_us(long double value)
        -> basic_second<double, micro>
{
    return basic_second<double, micro>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_ms(unsigned long long value)
        -> milliseconds
{
    return milliseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_ms(long double value)
        -> basic_second<double, milli>
{
    return basic_second<double, milli>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_cs(unsigned long long value)
        -> centiseconds
{
    return centiseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_cs(long double value)
        -> basic_second<double, centi>
{
    return basic_second<double, centi>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_ds(unsigned long long value)
        -> deciseconds
{
    return deciseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_ds(long double value)
        -> basic_second<double, deci>
{
    return basic_second<double, deci>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_s(unsigned long long value) -> seconds
{
    return seconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_s(long double value)
        -> basic_second<double, ratio<1>>
{
    return basic_second<double, ratio<1>>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_das(unsigned long long value)
        -> decaseconds
{
    return decaseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_das(long double value)
        -> basic_second<double, deca>
{
    return basic_second<double, deca>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_hs(unsigned long long value)
        -> hectoseconds
{
    return hectoseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_hs(long double value)
        -> basic_second<double, hecto>
{
    return basic_second<double, hecto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_ks(unsigned long long value)
        -> kiloseconds
{
    return kiloseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_ks(long double value)
        -> basic_second<double, kilo>
{
    return basic_second<double, kilo>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_Ms(unsigned long long value)
        -> megaseconds
{
    return megaseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_Ms(long double value)
        -> basic_second<double, mega>
{
    return basic_second<double, mega>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_Gs(unsigned long long value)
        -> gigaseconds
{
    return gigaseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_Gs(long double value)
        -> basic_second<double, giga>
{
    return basic_second<double, giga>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_Ts(unsigned long long value)
        -> teraseconds
{
    return teraseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_Ts(long double value)
        -> basic_second<double, tera>
{
    return basic_second<double, tera>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_Ps(unsigned long long value)
        -> petaseconds
{
    return petaseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_Ps(long double value)
        -> basic_second<double, peta>
{
    return basic_second<double, peta>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_Es(unsigned long long value)
        -> exaseconds
{
    return exaseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_Es(long double value)
        -> basic_second<double, exa>
{
    return basic_second<double, exa>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_min(unsigned long long value) -> minutes
{
    return minutes(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_min(long double value)
        -> basic_second<double, minutes::period>
{
    return basic_second<double, minutes::period>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_h(unsigned long long value) -> hours
{
    return hours(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::chrono_literals::operator""_h(long double value)
        -> basic_second<double, hours::period>
{
    return basic_second<double, hours::period>(value);
}
