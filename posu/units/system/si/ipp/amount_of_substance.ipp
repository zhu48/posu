
[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_amol(
        unsigned long long value) -> attomoles
{
    return attomoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_amol(long double value)
        -> amount_of_substance<double, std::atto>
{
    return amount_of_substance<double, std::atto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_fmol(
        unsigned long long value) -> femtomoles
{
    return femtomoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_fmol(long double value)
        -> amount_of_substance<double, std::femto>
{
    return amount_of_substance<double, std::femto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_pmol(
        unsigned long long value) -> picomoles
{
    return picomoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_pmol(long double value)
        -> amount_of_substance<double, std::pico>
{
    return amount_of_substance<double, std::pico>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_nmol(
        unsigned long long value) -> nanomoles
{
    return nanomoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_nmol(long double value)
        -> amount_of_substance<double, std::nano>
{
    return amount_of_substance<double, std::nano>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_umol(
        unsigned long long value) -> micromoles
{
    return micromoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_umol(long double value)
        -> amount_of_substance<double, std::micro>
{
    return amount_of_substance<double, std::micro>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_mmol(
        unsigned long long value) -> millimoles
{
    return millimoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_mmol(long double value)
        -> amount_of_substance<double, std::milli>
{
    return amount_of_substance<double, std::milli>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_cmol(
        unsigned long long value) -> centimoles
{
    return centimoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_cmol(long double value)
        -> amount_of_substance<double, std::centi>
{
    return amount_of_substance<double, std::centi>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_dmol(
        unsigned long long value) -> decimoles
{
    return decimoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_dmol(long double value)
        -> amount_of_substance<double, std::deci>
{
    return amount_of_substance<double, std::deci>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_mol(
        unsigned long long value) -> moles
{
    return moles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_mol(long double value)
        -> amount_of_substance<double, std::ratio<1>>
{
    return amount_of_substance<double, std::ratio<1>>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_damol(
        unsigned long long value) -> decamoles
{
    return decamoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_damol(long double value)
        -> amount_of_substance<double, std::deca>
{
    return amount_of_substance<double, std::deca>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_hmol(
        unsigned long long value) -> hectomoles
{
    return hectomoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_hmol(long double value)
        -> amount_of_substance<double, std::hecto>
{
    return amount_of_substance<double, std::hecto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_kmol(
        unsigned long long value) -> kilomoles
{
    return kilomoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_kmol(long double value)
        -> amount_of_substance<double, std::kilo>
{
    return amount_of_substance<double, std::kilo>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_Mmol(
        unsigned long long value) -> megamoles
{
    return megamoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_Mmol(long double value)
        -> amount_of_substance<double, std::mega>
{
    return amount_of_substance<double, std::mega>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_Gmol(
        unsigned long long value) -> gigamoles
{
    return gigamoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_Gmol(long double value)
        -> amount_of_substance<double, std::giga>
{
    return amount_of_substance<double, std::giga>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_Tmol(
        unsigned long long value) -> teramoles
{
    return teramoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_Tmol(long double value)
        -> amount_of_substance<double, std::tera>
{
    return amount_of_substance<double, std::tera>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_Pmol(
        unsigned long long value) -> petamoles
{
    return petamoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_Pmol(long double value)
        -> amount_of_substance<double, std::peta>
{
    return amount_of_substance<double, std::peta>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_Emol(
        unsigned long long value) -> examoles
{
    return examoles(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::amount_of_substance_literals::operator""_Emol(long double value)
        -> amount_of_substance<double, std::exa>
{
    return amount_of_substance<double, std::exa>(value);
}
