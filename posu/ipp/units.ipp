
namespace posu::units {

    template<typename Rep, typename Period, typename Tag> // clang-format off
        requires( std::integral<Rep> || std::floating_point<Rep> )
    template<typename Rep2>
        requires(
            std::convertible_to<Rep, const Rep2&> &&
            (
                std::chrono::treat_as_floating_point_v<Rep> ||
                !std::chrono::treat_as_floating_point_v<Rep2>
            )
        )
    constexpr base_unit<Rep, Period, Tag>::base_unit( const Rep2& r ) : // clang-format on
          parent_type(r)
    {
    }

    inline namespace literals {

        inline namespace chrono_literals {

            constexpr auto operator""_as(unsigned long long value)
                -> attoseconds
            {
                return attoseconds(value);
            }

            constexpr auto operator""_as(long double value)
                -> time<double, std::atto>
            {
                return time<double, std::atto>(value);
            }

            constexpr auto operator""_fs(unsigned long long value)
                -> femtoseconds
            {
                return femtoseconds(value);
            }

            constexpr auto operator""_fs(long double value)
                -> time<double, std::femto>
            {
                return time<double, std::femto>(value);
            }

            constexpr auto operator""_ps(unsigned long long value)
                -> picoseconds
            {
                return picoseconds(value);
            }

            constexpr auto operator""_ps(long double value)
                -> time<double, std::pico>
            {
                return time<double, std::pico>(value);
            }

            constexpr auto operator""_ns(unsigned long long value)
                -> nanoseconds
            {
                return nanoseconds(value);
            }

            constexpr auto operator""_ns(long double value)
                -> time<double, std::nano>
            {
                return time<double, std::nano>(value);
            }

            constexpr auto operator""_us(unsigned long long value)
                -> microseconds
            {
                return microseconds(value);
            }

            constexpr auto operator""_us(long double value)
                -> time<double, std::micro>
            {
                return time<double, std::micro>(value);
            }

            constexpr auto operator""_ms(unsigned long long value)
                -> milliseconds
            {
                return milliseconds(value);
            }

            constexpr auto operator""_ms(long double value)
                -> time<double, std::milli>
            {
                return time<double, std::milli>(value);
            }

            constexpr auto operator""_cs(unsigned long long value)
                -> centiseconds
            {
                return centiseconds(value);
            }

            constexpr auto operator""_cs(long double value)
                -> time<double, std::centi>
            {
                return time<double, std::centi>(value);
            }

            constexpr auto operator""_ds(unsigned long long value)
                -> deciseconds
            {
                return deciseconds(value);
            }

            constexpr auto operator""_ds(long double value)
                -> time<double, std::deci>
            {
                return time<double, std::deci>(value);
            }

            constexpr auto operator""_s(unsigned long long value) -> seconds
            {
                return seconds(value);
            }

            constexpr auto operator""_s(long double value)
                -> time<double, std::ratio<1>>
            {
                return time<double, std::ratio<1>>(value);
            }

            constexpr auto operator""_das(unsigned long long value)
                -> decaseconds
            {
                return decaseconds(value);
            }

            constexpr auto operator""_das(long double value)
                -> time<double, std::deca>
            {
                return time<double, std::deca>(value);
            }

            constexpr auto operator""_hs(unsigned long long value)
                -> hectoseconds
            {
                return hectoseconds(value);
            }

            constexpr auto operator""_hs(long double value)
                -> time<double, std::hecto>
            {
                return time<double, std::hecto>(value);
            }

            constexpr auto operator""_ks(unsigned long long value)
                -> kiloseconds
            {
                return kiloseconds(value);
            }

            constexpr auto operator""_ks(long double value)
                -> time<double, std::kilo>
            {
                return time<double, std::kilo>(value);
            }

            constexpr auto operator""_Ms(unsigned long long value)
                -> megaseconds
            {
                return megaseconds(value);
            }

            constexpr auto operator""_Ms(long double value)
                -> time<double, std::mega>
            {
                return time<double, std::mega>(value);
            }

            constexpr auto operator""_Gs(unsigned long long value)
                -> gigaseconds
            {
                return gigaseconds(value);
            }

            constexpr auto operator""_Gs(long double value)
                -> time<double, std::giga>
            {
                return time<double, std::giga>(value);
            }

            constexpr auto operator""_Ts(unsigned long long value)
                -> teraseconds
            {
                return teraseconds(value);
            }

            constexpr auto operator""_Ts(long double value)
                -> time<double, std::tera>
            {
                return time<double, std::tera>(value);
            }

            constexpr auto operator""_Ps(unsigned long long value)
                -> petaseconds
            {
                return petaseconds(value);
            }

            constexpr auto operator""_Ps(long double value)
                -> time<double, std::peta>
            {
                return time<double, std::peta>(value);
            }

            constexpr auto operator""_Es(unsigned long long value) -> exaseconds
            {
                return exaseconds(value);
            }

            constexpr auto operator""_Es(long double value)
                -> time<double, std::exa>
            {
                return time<double, std::exa>(value);
            }

            constexpr auto operator""_min(unsigned long long value) -> minutes
            {
                return minutes(value);
            }

            constexpr auto operator""_min(long double value)
                -> time<double, std::chrono::minutes::period>
            {
                return time<double, std::chrono::minutes::period>(value);
            }

            constexpr auto operator""_h(unsigned long long value) -> hours
            {
                return hours(value);
            }

            constexpr auto operator""_h(long double value)
                -> time<double, std::chrono::hours::period>
            {
                return time<double, std::chrono::hours::period>(value);
            }

        } // namespace chrono_literals

    } // namespace literals

} // namespace posu::units
