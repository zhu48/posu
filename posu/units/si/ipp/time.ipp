
[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_as(unsigned long long value) -> attoseconds
{
    return attoseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_as(long double value)
        -> time<double, std::atto>
{
    return time<double, std::atto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_fs(unsigned long long value) -> femtoseconds
{
    return femtoseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_fs(long double value)
        -> time<double, std::femto>
{
    return time<double, std::femto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_ps(unsigned long long value) -> picoseconds
{
    return picoseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_ps(long double value)
        -> time<double, std::pico>
{
    return time<double, std::pico>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_ns(unsigned long long value) -> nanoseconds
{
    return nanoseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_ns(long double value)
        -> time<double, std::nano>
{
    return time<double, std::nano>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_us(unsigned long long value) -> microseconds
{
    return microseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_us(long double value)
        -> time<double, std::micro>
{
    return time<double, std::micro>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_ms(unsigned long long value) -> milliseconds
{
    return milliseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_ms(long double value)
        -> time<double, std::milli>
{
    return time<double, std::milli>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_cs(unsigned long long value) -> centiseconds
{
    return centiseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_cs(long double value)
        -> time<double, std::centi>
{
    return time<double, std::centi>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_ds(unsigned long long value) -> deciseconds
{
    return deciseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_ds(long double value)
        -> time<double, std::deci>
{
    return time<double, std::deci>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_s(unsigned long long value) -> seconds
{
    return seconds(value);
}

[[nodiscard]] constexpr auto posu::units::literals::chrono_literals::operator""_s(long double value)
    -> time<double, std::ratio<1>>
{
    return time<double, std::ratio<1>>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_das(unsigned long long value) -> decaseconds
{
    return decaseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_das(long double value)
        -> time<double, std::deca>
{
    return time<double, std::deca>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_hs(unsigned long long value) -> hectoseconds
{
    return hectoseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_hs(long double value)
        -> time<double, std::hecto>
{
    return time<double, std::hecto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_ks(unsigned long long value) -> kiloseconds
{
    return kiloseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_ks(long double value)
        -> time<double, std::kilo>
{
    return time<double, std::kilo>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_Ms(unsigned long long value) -> megaseconds
{
    return megaseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_Ms(long double value)
        -> time<double, std::mega>
{
    return time<double, std::mega>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_Gs(unsigned long long value) -> gigaseconds
{
    return gigaseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_Gs(long double value)
        -> time<double, std::giga>
{
    return time<double, std::giga>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_Ts(unsigned long long value) -> teraseconds
{
    return teraseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_Ts(long double value)
        -> time<double, std::tera>
{
    return time<double, std::tera>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_Ps(unsigned long long value) -> petaseconds
{
    return petaseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_Ps(long double value)
        -> time<double, std::peta>
{
    return time<double, std::peta>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_Es(unsigned long long value) -> exaseconds
{
    return exaseconds(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_Es(long double value)
        -> time<double, std::exa>
{
    return time<double, std::exa>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_min(unsigned long long value) -> minutes
{
    return minutes(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_min(long double value)
        -> time<double, std::chrono::minutes::period>
{
    return time<double, std::chrono::minutes::period>(value);
}

[[nodiscard]] constexpr auto
    posu::units::literals::chrono_literals::operator""_h(unsigned long long value) -> hours
{
    return hours(value);
}

[[nodiscard]] constexpr auto posu::units::literals::chrono_literals::operator""_h(long double value)
    -> time<double, std::chrono::hours::period>
{
    return time<double, std::chrono::hours::period>(value);
}
