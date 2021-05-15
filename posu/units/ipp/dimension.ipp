
template<posu::units::base_dimension Lhs, posu::units::base_dimension Rhs>
struct posu::units::detail::dimension_multiply_impl<Lhs, Rhs> {
    using type = posu::type_ratio<posu::type_list<Lhs, Rhs>>;
};

template<posu::units::base_dimension Lhs, posu::units::derived_dimension Rhs>
struct posu::units::detail::dimension_multiply_impl<Lhs, Rhs> {
    using type = posu::ratio_multiply<posu::type_ratio<Lhs>, Rhs>;
};

template<posu::units::derived_dimension Lhs, posu::units::base_dimension Rhs>
struct posu::units::detail::dimension_multiply_impl<Lhs, Rhs> {
    using type = posu::ratio_multiply<Lhs, posu::type_ratio<Rhs>>;
};

template<posu::units::derived_dimension Lhs, posu::units::derived_dimension Rhs>
struct posu::units::detail::dimension_multiply_impl<Lhs, Rhs> {
    using type = posu::ratio_multiply<Lhs, Rhs>;
};
