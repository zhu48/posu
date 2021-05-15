
template<posu::units::dimension Dimension>
struct posu::units::is_unknown_kind<posu::units::unknown<Dimension>> : public std::true_type {
};
