
namespace posu::units {

    inline namespace literals {

        inline namespace chrono_literals {

            [[nodiscard]] constexpr auto operator""_as(unsigned long long value) -> attoseconds
            {
                return attoseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_as(long double value) -> time<double, std::atto>
            {
                return time<double, std::atto>(value);
            }

            [[nodiscard]] constexpr auto operator""_fs(unsigned long long value) -> femtoseconds
            {
                return femtoseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_fs(long double value)
                -> time<double, std::femto>
            {
                return time<double, std::femto>(value);
            }

            [[nodiscard]] constexpr auto operator""_ps(unsigned long long value) -> picoseconds
            {
                return picoseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_ps(long double value) -> time<double, std::pico>
            {
                return time<double, std::pico>(value);
            }

            [[nodiscard]] constexpr auto operator""_ns(unsigned long long value) -> nanoseconds
            {
                return nanoseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_ns(long double value) -> time<double, std::nano>
            {
                return time<double, std::nano>(value);
            }

            [[nodiscard]] constexpr auto operator""_us(unsigned long long value) -> microseconds
            {
                return microseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_us(long double value)
                -> time<double, std::micro>
            {
                return time<double, std::micro>(value);
            }

            [[nodiscard]] constexpr auto operator""_ms(unsigned long long value) -> milliseconds
            {
                return milliseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_ms(long double value)
                -> time<double, std::milli>
            {
                return time<double, std::milli>(value);
            }

            [[nodiscard]] constexpr auto operator""_cs(unsigned long long value) -> centiseconds
            {
                return centiseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_cs(long double value)
                -> time<double, std::centi>
            {
                return time<double, std::centi>(value);
            }

            [[nodiscard]] constexpr auto operator""_ds(unsigned long long value) -> deciseconds
            {
                return deciseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_ds(long double value) -> time<double, std::deci>
            {
                return time<double, std::deci>(value);
            }

            [[nodiscard]] constexpr auto operator""_s(unsigned long long value) -> seconds
            {
                return seconds(value);
            }

            [[nodiscard]] constexpr auto operator""_s(long double value)
                -> time<double, std::ratio<1>>
            {
                return time<double, std::ratio<1>>(value);
            }

            [[nodiscard]] constexpr auto operator""_das(unsigned long long value) -> decaseconds
            {
                return decaseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_das(long double value)
                -> time<double, std::deca>
            {
                return time<double, std::deca>(value);
            }

            [[nodiscard]] constexpr auto operator""_hs(unsigned long long value) -> hectoseconds
            {
                return hectoseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_hs(long double value)
                -> time<double, std::hecto>
            {
                return time<double, std::hecto>(value);
            }

            [[nodiscard]] constexpr auto operator""_ks(unsigned long long value) -> kiloseconds
            {
                return kiloseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_ks(long double value) -> time<double, std::kilo>
            {
                return time<double, std::kilo>(value);
            }

            [[nodiscard]] constexpr auto operator""_Ms(unsigned long long value) -> megaseconds
            {
                return megaseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_Ms(long double value) -> time<double, std::mega>
            {
                return time<double, std::mega>(value);
            }

            [[nodiscard]] constexpr auto operator""_Gs(unsigned long long value) -> gigaseconds
            {
                return gigaseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_Gs(long double value) -> time<double, std::giga>
            {
                return time<double, std::giga>(value);
            }

            [[nodiscard]] constexpr auto operator""_Ts(unsigned long long value) -> teraseconds
            {
                return teraseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_Ts(long double value) -> time<double, std::tera>
            {
                return time<double, std::tera>(value);
            }

            [[nodiscard]] constexpr auto operator""_Ps(unsigned long long value) -> petaseconds
            {
                return petaseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_Ps(long double value) -> time<double, std::peta>
            {
                return time<double, std::peta>(value);
            }

            [[nodiscard]] constexpr auto operator""_Es(unsigned long long value) -> exaseconds
            {
                return exaseconds(value);
            }

            [[nodiscard]] constexpr auto operator""_Es(long double value) -> time<double, std::exa>
            {
                return time<double, std::exa>(value);
            }

            [[nodiscard]] constexpr auto operator""_min(unsigned long long value) -> minutes
            {
                return minutes(value);
            }

            [[nodiscard]] constexpr auto operator""_min(long double value)
                -> time<double, std::chrono::minutes::period>
            {
                return time<double, std::chrono::minutes::period>(value);
            }

            [[nodiscard]] constexpr auto operator""_h(unsigned long long value) -> hours
            {
                return hours(value);
            }

            [[nodiscard]] constexpr auto operator""_h(long double value)
                -> time<double, std::chrono::hours::period>
            {
                return time<double, std::chrono::hours::period>(value);
            }

        } // namespace chrono_literals

        inline namespace length_literals {

            [[nodiscard]] constexpr auto operator""_am(unsigned long long value) -> attometers
            {
                return attometers(value);
            }

            [[nodiscard]] constexpr auto operator""_am(long double value)
                -> length<double, std::atto>
            {
                return length<double, std::atto>(value);
            }

            [[nodiscard]] constexpr auto operator""_fm(unsigned long long value) -> femtometers
            {
                return femtometers(value);
            }

            [[nodiscard]] constexpr auto operator""_fm(long double value)
                -> length<double, std::femto>
            {
                return length<double, std::femto>(value);
            }

            [[nodiscard]] constexpr auto operator""_pm(unsigned long long value) -> picometers
            {
                return picometers(value);
            }

            [[nodiscard]] constexpr auto operator""_pm(long double value)
                -> length<double, std::pico>
            {
                return length<double, std::pico>(value);
            }

            [[nodiscard]] constexpr auto operator""_nm(unsigned long long value) -> nanometers
            {
                return nanometers(value);
            }

            [[nodiscard]] constexpr auto operator""_nm(long double value)
                -> length<double, std::nano>
            {
                return length<double, std::nano>(value);
            }

            [[nodiscard]] constexpr auto operator""_um(unsigned long long value) -> micrometers
            {
                return micrometers(value);
            }

            [[nodiscard]] constexpr auto operator""_um(long double value)
                -> length<double, std::micro>
            {
                return length<double, std::micro>(value);
            }

            [[nodiscard]] constexpr auto operator""_mm(unsigned long long value) -> millimeters
            {
                return millimeters(value);
            }

            [[nodiscard]] constexpr auto operator""_mm(long double value)
                -> length<double, std::milli>
            {
                return length<double, std::milli>(value);
            }

            [[nodiscard]] constexpr auto operator""_cm(unsigned long long value) -> centimeters
            {
                return centimeters(value);
            }

            [[nodiscard]] constexpr auto operator""_cm(long double value)
                -> length<double, std::centi>
            {
                return length<double, std::centi>(value);
            }

            [[nodiscard]] constexpr auto operator""_dm(unsigned long long value) -> decimeters
            {
                return decimeters(value);
            }

            [[nodiscard]] constexpr auto operator""_dm(long double value)
                -> length<double, std::deci>
            {
                return length<double, std::deci>(value);
            }

            [[nodiscard]] constexpr auto operator""_m(unsigned long long value) -> meters
            {
                return meters(value);
            }

            [[nodiscard]] constexpr auto operator""_m(long double value)
                -> length<double, std::ratio<1>>
            {
                return length<double, std::ratio<1>>(value);
            }

            [[nodiscard]] constexpr auto operator""_dam(unsigned long long value) -> decameters
            {
                return decameters(value);
            }

            [[nodiscard]] constexpr auto operator""_dam(long double value)
                -> length<double, std::deca>
            {
                return length<double, std::deca>(value);
            }

            [[nodiscard]] constexpr auto operator""_hm(unsigned long long value) -> hectometers
            {
                return hectometers(value);
            }

            [[nodiscard]] constexpr auto operator""_hm(long double value)
                -> length<double, std::hecto>
            {
                return length<double, std::hecto>(value);
            }

            [[nodiscard]] constexpr auto operator""_km(unsigned long long value) -> kilometers
            {
                return kilometers(value);
            }

            [[nodiscard]] constexpr auto operator""_km(long double value)
                -> length<double, std::kilo>
            {
                return length<double, std::kilo>(value);
            }

            [[nodiscard]] constexpr auto operator""_Mm(unsigned long long value) -> megameters
            {
                return megameters(value);
            }

            [[nodiscard]] constexpr auto operator""_Mm(long double value)
                -> length<double, std::mega>
            {
                return length<double, std::mega>(value);
            }

            [[nodiscard]] constexpr auto operator""_Gm(unsigned long long value) -> gigameters
            {
                return gigameters(value);
            }

            [[nodiscard]] constexpr auto operator""_Gm(long double value)
                -> length<double, std::giga>
            {
                return length<double, std::giga>(value);
            }

            [[nodiscard]] constexpr auto operator""_Tm(unsigned long long value) -> terameters
            {
                return terameters(value);
            }

            [[nodiscard]] constexpr auto operator""_Tm(long double value)
                -> length<double, std::tera>
            {
                return length<double, std::tera>(value);
            }

            [[nodiscard]] constexpr auto operator""_Pm(unsigned long long value) -> petameters
            {
                return petameters(value);
            }

            [[nodiscard]] constexpr auto operator""_Pm(long double value)
                -> length<double, std::peta>
            {
                return length<double, std::peta>(value);
            }

            [[nodiscard]] constexpr auto operator""_Em(unsigned long long value) -> exameters
            {
                return exameters(value);
            }

            [[nodiscard]] constexpr auto operator""_Em(long double value)
                -> length<double, std::exa>
            {
                return length<double, std::exa>(value);
            }

        } // namespace length_literals

        inline namespace mass_literals {

            [[nodiscard]] constexpr auto operator""_ag(unsigned long long value) -> attograms
            {
                return attograms(value);
            }

            [[nodiscard]] constexpr auto operator""_ag(long double value) -> mass<double, std::atto>
            {
                return mass<double, std::atto>(value);
            }

            [[nodiscard]] constexpr auto operator""_fg(unsigned long long value) -> femtograms
            {
                return femtograms(value);
            }

            [[nodiscard]] constexpr auto operator""_fg(long double value)
                -> mass<double, std::femto>
            {
                return mass<double, std::femto>(value);
            }

            [[nodiscard]] constexpr auto operator""_pg(unsigned long long value) -> picograms
            {
                return picograms(value);
            }

            [[nodiscard]] constexpr auto operator""_pg(long double value) -> mass<double, std::pico>
            {
                return mass<double, std::pico>(value);
            }

            [[nodiscard]] constexpr auto operator""_ng(unsigned long long value) -> nanograms
            {
                return nanograms(value);
            }

            [[nodiscard]] constexpr auto operator""_ng(long double value) -> mass<double, std::nano>
            {
                return mass<double, std::nano>(value);
            }

            [[nodiscard]] constexpr auto operator""_ug(unsigned long long value) -> micrograms
            {
                return micrograms(value);
            }

            [[nodiscard]] constexpr auto operator""_ug(long double value)
                -> mass<double, std::micro>
            {
                return mass<double, std::micro>(value);
            }

            [[nodiscard]] constexpr auto operator""_mg(unsigned long long value) -> milligrams
            {
                return milligrams(value);
            }

            [[nodiscard]] constexpr auto operator""_mg(long double value)
                -> mass<double, std::milli>
            {
                return mass<double, std::milli>(value);
            }

            [[nodiscard]] constexpr auto operator""_cg(unsigned long long value) -> centigrams
            {
                return centigrams(value);
            }

            [[nodiscard]] constexpr auto operator""_cg(long double value)
                -> mass<double, std::centi>
            {
                return mass<double, std::centi>(value);
            }

            [[nodiscard]] constexpr auto operator""_dg(unsigned long long value) -> decigrams
            {
                return decigrams(value);
            }

            [[nodiscard]] constexpr auto operator""_dg(long double value) -> mass<double, std::deci>
            {
                return mass<double, std::deci>(value);
            }

            [[nodiscard]] constexpr auto operator""_g(unsigned long long value) -> grams
            {
                return grams(value);
            }

            [[nodiscard]] constexpr auto operator""_g(long double value)
                -> mass<double, std::ratio<1>>
            {
                return mass<double, std::ratio<1>>(value);
            }

            [[nodiscard]] constexpr auto operator""_dag(unsigned long long value) -> decagrams
            {
                return decagrams(value);
            }

            [[nodiscard]] constexpr auto operator""_dag(long double value)
                -> mass<double, std::deca>
            {
                return mass<double, std::deca>(value);
            }

            [[nodiscard]] constexpr auto operator""_hg(unsigned long long value) -> hectograms
            {
                return hectograms(value);
            }

            [[nodiscard]] constexpr auto operator""_hg(long double value)
                -> mass<double, std::hecto>
            {
                return mass<double, std::hecto>(value);
            }

            [[nodiscard]] constexpr auto operator""_kg(unsigned long long value) -> kilograms
            {
                return kilograms(value);
            }

            [[nodiscard]] constexpr auto operator""_kg(long double value) -> mass<double, std::kilo>
            {
                return mass<double, std::kilo>(value);
            }

            [[nodiscard]] constexpr auto operator""_Mg(unsigned long long value) -> megagrams
            {
                return megagrams(value);
            }

            [[nodiscard]] constexpr auto operator""_Mg(long double value) -> mass<double, std::mega>
            {
                return mass<double, std::mega>(value);
            }

            [[nodiscard]] constexpr auto operator""_Gg(unsigned long long value) -> gigagrams
            {
                return gigagrams(value);
            }

            [[nodiscard]] constexpr auto operator""_Gg(long double value) -> mass<double, std::giga>
            {
                return mass<double, std::giga>(value);
            }

            [[nodiscard]] constexpr auto operator""_Tg(unsigned long long value) -> teragrams
            {
                return teragrams(value);
            }

            [[nodiscard]] constexpr auto operator""_Tg(long double value) -> mass<double, std::tera>
            {
                return mass<double, std::tera>(value);
            }

            [[nodiscard]] constexpr auto operator""_Pg(unsigned long long value) -> petagrams
            {
                return petagrams(value);
            }

            [[nodiscard]] constexpr auto operator""_Pg(long double value) -> mass<double, std::peta>
            {
                return mass<double, std::peta>(value);
            }

            [[nodiscard]] constexpr auto operator""_Eg(unsigned long long value) -> exagrams
            {
                return exagrams(value);
            }

            [[nodiscard]] constexpr auto operator""_Eg(long double value) -> mass<double, std::exa>
            {
                return mass<double, std::exa>(value);
            }

        } // namespace mass_literals

        inline namespace electric_current_literals {

            [[nodiscard]] constexpr auto operator""_aA(unsigned long long value) -> attoamperes
            {
                return attoamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_aA(long double value)
                -> electric_current<double, std::atto>
            {
                return electric_current<double, std::atto>(value);
            }

            [[nodiscard]] constexpr auto operator""_fA(unsigned long long value) -> femtoamperes
            {
                return femtoamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_fA(long double value)
                -> electric_current<double, std::femto>
            {
                return electric_current<double, std::femto>(value);
            }

            [[nodiscard]] constexpr auto operator""_pA(unsigned long long value) -> picoamperes
            {
                return picoamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_pA(long double value)
                -> electric_current<double, std::pico>
            {
                return electric_current<double, std::pico>(value);
            }

            [[nodiscard]] constexpr auto operator""_nA(unsigned long long value) -> nanoamperes
            {
                return nanoamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_nA(long double value)
                -> electric_current<double, std::nano>
            {
                return electric_current<double, std::nano>(value);
            }

            [[nodiscard]] constexpr auto operator""_uA(unsigned long long value) -> microamperes
            {
                return microamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_uA(long double value)
                -> electric_current<double, std::micro>
            {
                return electric_current<double, std::micro>(value);
            }

            [[nodiscard]] constexpr auto operator""_mA(unsigned long long value) -> milliamperes
            {
                return milliamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_mA(long double value)
                -> electric_current<double, std::milli>
            {
                return electric_current<double, std::milli>(value);
            }

            [[nodiscard]] constexpr auto operator""_cA(unsigned long long value) -> centiamperes
            {
                return centiamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_cA(long double value)
                -> electric_current<double, std::centi>
            {
                return electric_current<double, std::centi>(value);
            }

            [[nodiscard]] constexpr auto operator""_dA(unsigned long long value) -> deciamperes
            {
                return deciamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_dA(long double value)
                -> electric_current<double, std::deci>
            {
                return electric_current<double, std::deci>(value);
            }

            [[nodiscard]] constexpr auto operator""_A(unsigned long long value) -> amperes
            {
                return amperes(value);
            }

            [[nodiscard]] constexpr auto operator""_A(long double value)
                -> electric_current<double, std::ratio<1>>
            {
                return electric_current<double, std::ratio<1>>(value);
            }

            [[nodiscard]] constexpr auto operator""_daA(unsigned long long value) -> decaamperes
            {
                return decaamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_daA(long double value)
                -> electric_current<double, std::deca>
            {
                return electric_current<double, std::deca>(value);
            }

            [[nodiscard]] constexpr auto operator""_hA(unsigned long long value) -> hectoamperes
            {
                return hectoamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_hA(long double value)
                -> electric_current<double, std::hecto>
            {
                return electric_current<double, std::hecto>(value);
            }

            [[nodiscard]] constexpr auto operator""_kA(unsigned long long value) -> kiloamperes
            {
                return kiloamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_kA(long double value)
                -> electric_current<double, std::kilo>
            {
                return electric_current<double, std::kilo>(value);
            }

            [[nodiscard]] constexpr auto operator""_MA(unsigned long long value) -> megaamperes
            {
                return megaamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_MA(long double value)
                -> electric_current<double, std::mega>
            {
                return electric_current<double, std::mega>(value);
            }

            [[nodiscard]] constexpr auto operator""_GA(unsigned long long value) -> gigaamperes
            {
                return gigaamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_GA(long double value)
                -> electric_current<double, std::giga>
            {
                return electric_current<double, std::giga>(value);
            }

            [[nodiscard]] constexpr auto operator""_TA(unsigned long long value) -> teraamperes
            {
                return teraamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_TA(long double value)
                -> electric_current<double, std::tera>
            {
                return electric_current<double, std::tera>(value);
            }

            [[nodiscard]] constexpr auto operator""_PA(unsigned long long value) -> petaamperes
            {
                return petaamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_PA(long double value)
                -> electric_current<double, std::peta>
            {
                return electric_current<double, std::peta>(value);
            }

            [[nodiscard]] constexpr auto operator""_EA(unsigned long long value) -> exaamperes
            {
                return exaamperes(value);
            }

            [[nodiscard]] constexpr auto operator""_EA(long double value)
                -> electric_current<double, std::exa>
            {
                return electric_current<double, std::exa>(value);
            }

        } // namespace electric_current_literals

        inline namespace thermodynamic_temperature_literals {

            [[nodiscard]] constexpr auto operator""_aK(unsigned long long value) -> attokelvins
            {
                return attokelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_aK(long double value)
                -> thermodynamic_temperature<double, std::atto>
            {
                return thermodynamic_temperature<double, std::atto>(value);
            }

            [[nodiscard]] constexpr auto operator""_fK(unsigned long long value) -> femtokelvins
            {
                return femtokelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_fK(long double value)
                -> thermodynamic_temperature<double, std::femto>
            {
                return thermodynamic_temperature<double, std::femto>(value);
            }

            [[nodiscard]] constexpr auto operator""_pK(unsigned long long value) -> picokelvins
            {
                return picokelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_pK(long double value)
                -> thermodynamic_temperature<double, std::pico>
            {
                return thermodynamic_temperature<double, std::pico>(value);
            }

            [[nodiscard]] constexpr auto operator""_nK(unsigned long long value) -> nanokelvins
            {
                return nanokelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_nK(long double value)
                -> thermodynamic_temperature<double, std::nano>
            {
                return thermodynamic_temperature<double, std::nano>(value);
            }

            [[nodiscard]] constexpr auto operator""_uK(unsigned long long value) -> microkelvins
            {
                return microkelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_uK(long double value)
                -> thermodynamic_temperature<double, std::micro>
            {
                return thermodynamic_temperature<double, std::micro>(value);
            }

            [[nodiscard]] constexpr auto operator""_mK(unsigned long long value) -> millikelvins
            {
                return millikelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_mK(long double value)
                -> thermodynamic_temperature<double, std::milli>
            {
                return thermodynamic_temperature<double, std::milli>(value);
            }

            [[nodiscard]] constexpr auto operator""_cK(unsigned long long value) -> centikelvins
            {
                return centikelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_cK(long double value)
                -> thermodynamic_temperature<double, std::centi>
            {
                return thermodynamic_temperature<double, std::centi>(value);
            }

            [[nodiscard]] constexpr auto operator""_dK(unsigned long long value) -> decikelvins
            {
                return decikelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_dK(long double value)
                -> thermodynamic_temperature<double, std::deci>
            {
                return thermodynamic_temperature<double, std::deci>(value);
            }

            [[nodiscard]] constexpr auto operator""_K(unsigned long long value) -> kelvins
            {
                return kelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_K(long double value)
                -> thermodynamic_temperature<double, std::ratio<1>>
            {
                return thermodynamic_temperature<double, std::ratio<1>>(value);
            }

            [[nodiscard]] constexpr auto operator""_daK(unsigned long long value) -> decakelvins
            {
                return decakelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_daK(long double value)
                -> thermodynamic_temperature<double, std::deca>
            {
                return thermodynamic_temperature<double, std::deca>(value);
            }

            [[nodiscard]] constexpr auto operator""_hK(unsigned long long value) -> hectokelvins
            {
                return hectokelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_hK(long double value)
                -> thermodynamic_temperature<double, std::hecto>
            {
                return thermodynamic_temperature<double, std::hecto>(value);
            }

            [[nodiscard]] constexpr auto operator""_kK(unsigned long long value) -> kilokelvins
            {
                return kilokelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_kK(long double value)
                -> thermodynamic_temperature<double, std::kilo>
            {
                return thermodynamic_temperature<double, std::kilo>(value);
            }

            [[nodiscard]] constexpr auto operator""_MK(unsigned long long value) -> megakelvins
            {
                return megakelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_MK(long double value)
                -> thermodynamic_temperature<double, std::mega>
            {
                return thermodynamic_temperature<double, std::mega>(value);
            }

            [[nodiscard]] constexpr auto operator""_GK(unsigned long long value) -> gigakelvins
            {
                return gigakelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_GK(long double value)
                -> thermodynamic_temperature<double, std::giga>
            {
                return thermodynamic_temperature<double, std::giga>(value);
            }

            [[nodiscard]] constexpr auto operator""_TK(unsigned long long value) -> terakelvins
            {
                return terakelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_TK(long double value)
                -> thermodynamic_temperature<double, std::tera>
            {
                return thermodynamic_temperature<double, std::tera>(value);
            }

            [[nodiscard]] constexpr auto operator""_PK(unsigned long long value) -> petakelvins
            {
                return petakelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_PK(long double value)
                -> thermodynamic_temperature<double, std::peta>
            {
                return thermodynamic_temperature<double, std::peta>(value);
            }

            [[nodiscard]] constexpr auto operator""_EK(unsigned long long value) -> exakelvins
            {
                return exakelvins(value);
            }

            [[nodiscard]] constexpr auto operator""_EK(long double value)
                -> thermodynamic_temperature<double, std::exa>
            {
                return thermodynamic_temperature<double, std::exa>(value);
            }

        } // namespace thermodynamic_temperature_literals

        inline namespace amount_of_substance_literals {

            [[nodiscard]] constexpr auto operator""_amol(unsigned long long value) -> attomoles
            {
                return attomoles(value);
            }

            [[nodiscard]] constexpr auto operator""_amol(long double value)
                -> amount_of_substance<double, std::atto>
            {
                return amount_of_substance<double, std::atto>(value);
            }

            [[nodiscard]] constexpr auto operator""_fmol(unsigned long long value) -> femtomoles
            {
                return femtomoles(value);
            }

            [[nodiscard]] constexpr auto operator""_fmol(long double value)
                -> amount_of_substance<double, std::femto>
            {
                return amount_of_substance<double, std::femto>(value);
            }

            [[nodiscard]] constexpr auto operator""_pmol(unsigned long long value) -> picomoles
            {
                return picomoles(value);
            }

            [[nodiscard]] constexpr auto operator""_pmol(long double value)
                -> amount_of_substance<double, std::pico>
            {
                return amount_of_substance<double, std::pico>(value);
            }

            [[nodiscard]] constexpr auto operator""_nmol(unsigned long long value) -> nanomoles
            {
                return nanomoles(value);
            }

            [[nodiscard]] constexpr auto operator""_nmol(long double value)
                -> amount_of_substance<double, std::nano>
            {
                return amount_of_substance<double, std::nano>(value);
            }

            [[nodiscard]] constexpr auto operator""_umol(unsigned long long value) -> micromoles
            {
                return micromoles(value);
            }

            [[nodiscard]] constexpr auto operator""_umol(long double value)
                -> amount_of_substance<double, std::micro>
            {
                return amount_of_substance<double, std::micro>(value);
            }

            [[nodiscard]] constexpr auto operator""_mmol(unsigned long long value) -> millimoles
            {
                return millimoles(value);
            }

            [[nodiscard]] constexpr auto operator""_mmol(long double value)
                -> amount_of_substance<double, std::milli>
            {
                return amount_of_substance<double, std::milli>(value);
            }

            [[nodiscard]] constexpr auto operator""_cmol(unsigned long long value) -> centimoles
            {
                return centimoles(value);
            }

            [[nodiscard]] constexpr auto operator""_cmol(long double value)
                -> amount_of_substance<double, std::centi>
            {
                return amount_of_substance<double, std::centi>(value);
            }

            [[nodiscard]] constexpr auto operator""_dmol(unsigned long long value) -> decimoles
            {
                return decimoles(value);
            }

            [[nodiscard]] constexpr auto operator""_dmol(long double value)
                -> amount_of_substance<double, std::deci>
            {
                return amount_of_substance<double, std::deci>(value);
            }

            [[nodiscard]] constexpr auto operator""_mol(unsigned long long value) -> moles
            {
                return moles(value);
            }

            [[nodiscard]] constexpr auto operator""_mol(long double value)
                -> amount_of_substance<double, std::ratio<1>>
            {
                return amount_of_substance<double, std::ratio<1>>(value);
            }

            [[nodiscard]] constexpr auto operator""_damol(unsigned long long value) -> decamoles
            {
                return decamoles(value);
            }

            [[nodiscard]] constexpr auto operator""_damol(long double value)
                -> amount_of_substance<double, std::deca>
            {
                return amount_of_substance<double, std::deca>(value);
            }

            [[nodiscard]] constexpr auto operator""_hmol(unsigned long long value) -> hectomoles
            {
                return hectomoles(value);
            }

            [[nodiscard]] constexpr auto operator""_hmol(long double value)
                -> amount_of_substance<double, std::hecto>
            {
                return amount_of_substance<double, std::hecto>(value);
            }

            [[nodiscard]] constexpr auto operator""_kmol(unsigned long long value) -> kilomoles
            {
                return kilomoles(value);
            }

            [[nodiscard]] constexpr auto operator""_kmol(long double value)
                -> amount_of_substance<double, std::kilo>
            {
                return amount_of_substance<double, std::kilo>(value);
            }

            [[nodiscard]] constexpr auto operator""_Mmol(unsigned long long value) -> megamoles
            {
                return megamoles(value);
            }

            [[nodiscard]] constexpr auto operator""_Mmol(long double value)
                -> amount_of_substance<double, std::mega>
            {
                return amount_of_substance<double, std::mega>(value);
            }

            [[nodiscard]] constexpr auto operator""_Gmol(unsigned long long value) -> gigamoles
            {
                return gigamoles(value);
            }

            [[nodiscard]] constexpr auto operator""_Gmol(long double value)
                -> amount_of_substance<double, std::giga>
            {
                return amount_of_substance<double, std::giga>(value);
            }

            [[nodiscard]] constexpr auto operator""_Tmol(unsigned long long value) -> teramoles
            {
                return teramoles(value);
            }

            [[nodiscard]] constexpr auto operator""_Tmol(long double value)
                -> amount_of_substance<double, std::tera>
            {
                return amount_of_substance<double, std::tera>(value);
            }

            [[nodiscard]] constexpr auto operator""_Pmol(unsigned long long value) -> petamoles
            {
                return petamoles(value);
            }

            [[nodiscard]] constexpr auto operator""_Pmol(long double value)
                -> amount_of_substance<double, std::peta>
            {
                return amount_of_substance<double, std::peta>(value);
            }

            [[nodiscard]] constexpr auto operator""_Emol(unsigned long long value) -> examoles
            {
                return examoles(value);
            }

            [[nodiscard]] constexpr auto operator""_Emol(long double value)
                -> amount_of_substance<double, std::exa>
            {
                return amount_of_substance<double, std::exa>(value);
            }

        } // namespace amount_of_substance_literals

        inline namespace luminous_intensity_literals {

            [[nodiscard]] constexpr auto operator""_acd(unsigned long long value) -> attocandelas
            {
                return attocandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_acd(long double value)
                -> luminous_intensity<double, std::atto>
            {
                return luminous_intensity<double, std::atto>(value);
            }

            [[nodiscard]] constexpr auto operator""_fcd(unsigned long long value) -> femtocandelas
            {
                return femtocandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_fcd(long double value)
                -> luminous_intensity<double, std::femto>
            {
                return luminous_intensity<double, std::femto>(value);
            }

            [[nodiscard]] constexpr auto operator""_pcd(unsigned long long value) -> picocandelas
            {
                return picocandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_pcd(long double value)
                -> luminous_intensity<double, std::pico>
            {
                return luminous_intensity<double, std::pico>(value);
            }

            [[nodiscard]] constexpr auto operator""_ncd(unsigned long long value) -> nanocandelas
            {
                return nanocandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_ncd(long double value)
                -> luminous_intensity<double, std::nano>
            {
                return luminous_intensity<double, std::nano>(value);
            }

            [[nodiscard]] constexpr auto operator""_ucd(unsigned long long value) -> microcandelas
            {
                return microcandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_ucd(long double value)
                -> luminous_intensity<double, std::micro>
            {
                return luminous_intensity<double, std::micro>(value);
            }

            [[nodiscard]] constexpr auto operator""_mcd(unsigned long long value) -> millicandelas
            {
                return millicandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_mcd(long double value)
                -> luminous_intensity<double, std::milli>
            {
                return luminous_intensity<double, std::milli>(value);
            }

            [[nodiscard]] constexpr auto operator""_ccd(unsigned long long value) -> centicandelas
            {
                return centicandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_ccd(long double value)
                -> luminous_intensity<double, std::centi>
            {
                return luminous_intensity<double, std::centi>(value);
            }

            [[nodiscard]] constexpr auto operator""_dcd(unsigned long long value) -> decicandelas
            {
                return decicandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_dcd(long double value)
                -> luminous_intensity<double, std::deci>
            {
                return luminous_intensity<double, std::deci>(value);
            }

            [[nodiscard]] constexpr auto operator""_cd(unsigned long long value) -> candelas
            {
                return candelas(value);
            }

            [[nodiscard]] constexpr auto operator""_cd(long double value)
                -> luminous_intensity<double, std::ratio<1>>
            {
                return luminous_intensity<double, std::ratio<1>>(value);
            }

            [[nodiscard]] constexpr auto operator""_dacd(unsigned long long value) -> decacandelas
            {
                return decacandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_dacd(long double value)
                -> luminous_intensity<double, std::deca>
            {
                return luminous_intensity<double, std::deca>(value);
            }

            [[nodiscard]] constexpr auto operator""_hcd(unsigned long long value) -> hectocandelas
            {
                return hectocandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_hcd(long double value)
                -> luminous_intensity<double, std::hecto>
            {
                return luminous_intensity<double, std::hecto>(value);
            }

            [[nodiscard]] constexpr auto operator""_kcd(unsigned long long value) -> kilocandelas
            {
                return kilocandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_kcd(long double value)
                -> luminous_intensity<double, std::kilo>
            {
                return luminous_intensity<double, std::kilo>(value);
            }

            [[nodiscard]] constexpr auto operator""_Mcd(unsigned long long value) -> megacandelas
            {
                return megacandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_Mcd(long double value)
                -> luminous_intensity<double, std::mega>
            {
                return luminous_intensity<double, std::mega>(value);
            }

            [[nodiscard]] constexpr auto operator""_Gcd(unsigned long long value) -> gigacandelas
            {
                return gigacandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_Gcd(long double value)
                -> luminous_intensity<double, std::giga>
            {
                return luminous_intensity<double, std::giga>(value);
            }

            [[nodiscard]] constexpr auto operator""_Tcd(unsigned long long value) -> teracandelas
            {
                return teracandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_Tcd(long double value)
                -> luminous_intensity<double, std::tera>
            {
                return luminous_intensity<double, std::tera>(value);
            }

            [[nodiscard]] constexpr auto operator""_Pcd(unsigned long long value) -> petacandelas
            {
                return petacandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_Pcd(long double value)
                -> luminous_intensity<double, std::peta>
            {
                return luminous_intensity<double, std::peta>(value);
            }

            [[nodiscard]] constexpr auto operator""_Ecd(unsigned long long value) -> exacandelas
            {
                return exacandelas(value);
            }

            [[nodiscard]] constexpr auto operator""_Ecd(long double value)
                -> luminous_intensity<double, std::exa>
            {
                return luminous_intensity<double, std::exa>(value);
            }

        } // namespace luminous_intensity_literals

    } // namespace literals

}
