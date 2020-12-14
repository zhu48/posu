
namespace posu::units {

    inline namespace literals {

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

} // namespace posu::units
