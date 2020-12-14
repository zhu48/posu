
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

    template<
        typename Rep1,
        typename Period1,
        typename Rep2,
        typename Period2,
        typename TypeTag>
    [[nodiscard]] constexpr auto operator==(
        const base_unit<Rep1, Period1, TypeTag>& lhs,
        const base_unit<Rep2, Period2, TypeTag>& rhs) -> bool
    {
        return static_cast<const std::chrono::duration<Rep1, Period1>&>(lhs) ==
               static_cast<const std::chrono::duration<Rep2, Period2>&>(rhs);
    }

    template<
        typename Rep1,
        typename Period1,
        typename Rep2,
        typename Period2,
        typename TypeTag>
    [[nodiscard]] constexpr auto operator!=(
        const base_unit<Rep1, Period1, TypeTag>& lhs,
        const base_unit<Rep2, Period2, TypeTag>& rhs) -> bool
    {
        return static_cast<const std::chrono::duration<Rep1, Period1>&>(lhs) !=
               static_cast<const std::chrono::duration<Rep2, Period2>&>(rhs);
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

    inline namespace literals {

        inline namespace length_literals {

            constexpr auto operator""_am(unsigned long long value) -> attometers
            {
                return attometers(value);
            }

            constexpr auto operator""_am(long double value)
                -> length<double, std::atto>
            {
                return length<double, std::atto>(value);
            }

            constexpr auto operator""_fm(unsigned long long value)
                -> femtometers
            {
                return femtometers(value);
            }

            constexpr auto operator""_fm(long double value)
                -> length<double, std::femto>
            {
                return length<double, std::femto>(value);
            }

            constexpr auto operator""_pm(unsigned long long value) -> picometers
            {
                return picometers(value);
            }

            constexpr auto operator""_pm(long double value)
                -> length<double, std::pico>
            {
                return length<double, std::pico>(value);
            }

            constexpr auto operator""_nm(unsigned long long value) -> nanometers
            {
                return nanometers(value);
            }

            constexpr auto operator""_nm(long double value)
                -> length<double, std::nano>
            {
                return length<double, std::nano>(value);
            }

            constexpr auto operator""_um(unsigned long long value)
                -> micrometers
            {
                return micrometers(value);
            }

            constexpr auto operator""_um(long double value)
                -> length<double, std::micro>
            {
                return length<double, std::micro>(value);
            }

            constexpr auto operator""_mm(unsigned long long value)
                -> millimeters
            {
                return millimeters(value);
            }

            constexpr auto operator""_mm(long double value)
                -> length<double, std::milli>
            {
                return length<double, std::milli>(value);
            }

            constexpr auto operator""_cm(unsigned long long value)
                -> centimeters
            {
                return centimeters(value);
            }

            constexpr auto operator""_cm(long double value)
                -> length<double, std::centi>
            {
                return length<double, std::centi>(value);
            }

            constexpr auto operator""_dm(unsigned long long value) -> decimeters
            {
                return decimeters(value);
            }

            constexpr auto operator""_dm(long double value)
                -> length<double, std::deci>
            {
                return length<double, std::deci>(value);
            }

            constexpr auto operator""_m(unsigned long long value) -> meters
            {
                return meters(value);
            }

            constexpr auto operator""_m(long double value)
                -> length<double, std::ratio<1>>
            {
                return length<double, std::ratio<1>>(value);
            }

            constexpr auto operator""_dam(unsigned long long value)
                -> decameters
            {
                return decameters(value);
            }

            constexpr auto operator""_dam(long double value)
                -> length<double, std::deca>
            {
                return length<double, std::deca>(value);
            }

            constexpr auto operator""_hm(unsigned long long value)
                -> hectometers
            {
                return hectometers(value);
            }

            constexpr auto operator""_hm(long double value)
                -> length<double, std::hecto>
            {
                return length<double, std::hecto>(value);
            }

            constexpr auto operator""_km(unsigned long long value) -> kilometers
            {
                return kilometers(value);
            }

            constexpr auto operator""_km(long double value)
                -> length<double, std::kilo>
            {
                return length<double, std::kilo>(value);
            }

            constexpr auto operator""_Mm(unsigned long long value) -> megameters
            {
                return megameters(value);
            }

            constexpr auto operator""_Mm(long double value)
                -> length<double, std::mega>
            {
                return length<double, std::mega>(value);
            }

            constexpr auto operator""_Gm(unsigned long long value) -> gigameters
            {
                return gigameters(value);
            }

            constexpr auto operator""_Gm(long double value)
                -> length<double, std::giga>
            {
                return length<double, std::giga>(value);
            }

            constexpr auto operator""_Tm(unsigned long long value) -> terameters
            {
                return terameters(value);
            }

            constexpr auto operator""_Tm(long double value)
                -> length<double, std::tera>
            {
                return length<double, std::tera>(value);
            }

            constexpr auto operator""_Pm(unsigned long long value) -> petameters
            {
                return petameters(value);
            }

            constexpr auto operator""_Pm(long double value)
                -> length<double, std::peta>
            {
                return length<double, std::peta>(value);
            }

            constexpr auto operator""_Em(unsigned long long value) -> exameters
            {
                return exameters(value);
            }

            constexpr auto operator""_Em(long double value)
                -> length<double, std::exa>
            {
                return length<double, std::exa>(value);
            }

        } // namespace length_literals

    } // namespace literals

} // namespace posu::units