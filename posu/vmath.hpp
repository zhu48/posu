#ifndef POSU_VMATH_HPP
#define POSU_VMATH_HPP

#include <concepts>
#include <stdexcept>
#include <tuple>

/**
 * Vector arithmetic types.
 */
namespace posu::vmath {

    /**
     * Exception indicating the vector must be a pure diagonal, but is not.
     */
    class not_pure_diagonal : public std::runtime_error {
    public:
        /**
         * Construct the exception with the given message.
         *
         * @param what_arg The exception message.
         *
         * @{
         */
        not_pure_diagonal(const std::string& what_arg);
        not_pure_diagonal(const char* what_arg);
        //! @}
    };

    /**
     * A tuple-like aggregate of arithmetic types.
     *
     * This template behaves much like an `std::tuple` of arithmetic types, and supports arithmetic
     * operations on its members as a vector.
     *
     * @tparam T The tuple arithmetic type members.
     */
    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    class arith_tuple {
    public:
        //! The scaler type that all member types can convert to.
        using scaler_type = std::common_type_t<T...>;

        //! Value-initialize all members.
        constexpr arith_tuple() = default;

        /**
         * Construct a tuple where all members have the same given value.
         *
         * @param n The value to initialize all members with.
         */
        constexpr arith_tuple(scaler_type n) noexcept;

        /**
         * Construct a tuple with the given initial member values.
         *
         * @param n The values to initialize the tuple members with.
         */
        constexpr arith_tuple(T... n) noexcept requires(sizeof...(T) != 1);

        /**
         * Assign a scaler value to all tuple members.
         *
         * @param n The value to assign to all members.
         */
        constexpr auto operator=(scaler_type n) noexcept -> arith_tuple&;

        /**
         * Arithmetic operators.
         *
         * Perform vector addition, subtraction, multiplication, or division on the tuple. Operating
         * on a tuple and a scaler applies the same operation to each tuple member. Adding or
         * subtracting two tuples adds or subtracts element-wise.
         *
         * @param rhs The value to add, subtract, multiply, or divide.
         *
         * @return Returns the arithmetic operation result.
         *
         * @{
         */
        [[nodiscard]] constexpr auto operator+(scaler_type rhs) const noexcept -> arith_tuple;
        [[nodiscard]] constexpr auto operator+(const arith_tuple& rhs) const noexcept
            -> arith_tuple;

        [[nodiscard]] constexpr auto operator-(scaler_type rhs) const noexcept -> arith_tuple;
        [[nodiscard]] constexpr auto operator-(const arith_tuple& rhs) const noexcept
            -> arith_tuple;

        [[nodiscard]] constexpr auto operator*(scaler_type rhs) const noexcept -> arith_tuple;
        [[nodiscard]] constexpr auto operator/(scaler_type rhs) const noexcept -> arith_tuple;
        //! @}

        /**
         * Arithmetic assignment operators.
         *
         * Perform the same operations as the arithmetic operators, but assigns the operation result
         * value to this object.
         *
         * @param rhs The value to add, subtract, multiple, or divide.
         *
         * @return Returns self-reference.
         *
         * @{
         */
        constexpr auto operator+=(scaler_type rhs) noexcept -> arith_tuple&;
        constexpr auto operator+=(const arith_tuple& rhs) noexcept -> arith_tuple&;
        constexpr auto operator-=(scaler_type rhs) noexcept -> arith_tuple&;
        constexpr auto operator-=(const arith_tuple& rhs) noexcept -> arith_tuple&;
        constexpr auto operator*=(scaler_type rhs) noexcept -> arith_tuple&;
        constexpr auto operator/=(scaler_type rhs) noexcept -> arith_tuple&;
        //! @}

        /**
         * Convert to a scaler value if possible.
         *
         * Requires all tuple elements compare equal to each other.
         *
         * @return Returns the converted scaler value.
         *
         * @throw not_pure_diagonal Not all elements compare equal.
         */
        [[nodiscard]] explicit constexpr operator scaler_type() const noexcept(false);

        /**
         * Convert to an `std::tuple` of the member types.
         *
         * @return Returns the converted tuple.
         *
         * @{
         */
        [[nodiscard]] explicit constexpr operator std::tuple<T...>&() & noexcept;
        [[nodiscard]] explicit constexpr operator std::tuple<T...>&&() && noexcept;
        [[nodiscard]] explicit constexpr operator const std::tuple<T...>&() const& noexcept;
        [[nodiscard]] explicit constexpr operator const std::tuple<T...>&&() const&& noexcept;
        //! @}

    private:
        std::tuple<T...> m_data{}; //!< The underlying tuple of data.
    };

    /**
     * Construct an arithmetic tuple where all members are equal.
     *
     * The constructed tuple has size `I`, and all members are of type `T` minus cv-qualifiers and
     * references.
     *
     * @tparam I The size of the arithmetic tuple to make.
     * @tparam T The type of the arithmetic tuple members.
     *
     * @param t The value to initialize all tuple members with.
     *
     * @return Returns the new tuple.
     */
    template<std::size_t I, typename T>
    [[nodiscard]] constexpr decltype(auto) make_arith_tuple(T&& t) noexcept;

    /**
     * Construct an arithmetic tuple from the given arguments.
     *
     * The constructed tuple has as many members as there are arguments, and the members are the
     * same type as the arguments, minus cv-qualifiers and references.
     *
     * @tparam T The types of the arithmetic tuple members.
     *
     * @param t The values to initialize tuple members with.
     *
     * @return Returns the new tuple.
     */
    template<typename... T>
    [[nodiscard]] constexpr auto make_arith_tuple(T&&... t) noexcept
        -> arith_tuple<std::remove_cvref_t<T>...>;

} // namespace posu::vmath

namespace std {

    /**
     * `std::tuple_size` specialization for `posu::vmath::arith_tuple`.
     *
     * @tparam T The arithmetic tuple's template arguments.
     */
    template<typename... T>
    struct tuple_size<posu::vmath::arith_tuple<T...>>
        : std::integral_constant<std::size_t, sizeof...(T)> {
    };

    /**
     * `std::get` specializations for `posu::vmath::arith_tuple`.
     *
     * @tparam I  The index of the tuple element to access.
     * @tparam Ty The unique type of the tuple element to access.
     *
     * @param value The tuple to access a member of.
     *
     * @return Returns the requested tuple element.
     *
     * @{
     */
    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto get(posu::vmath::arith_tuple<Types...>& value) noexcept
        -> tuple_element_t<I, tuple<Types...>>&;
    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto get(posu::vmath::arith_tuple<Types...>&& value) noexcept
        -> tuple_element_t<I, tuple<Types...>>&&;
    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto get(const posu::vmath::arith_tuple<Types...>& value) noexcept
        -> const tuple_element_t<I, tuple<Types...>>&;
    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto get(const posu::vmath::arith_tuple<Types...>&& value) noexcept
        -> const tuple_element_t<I, tuple<Types...>>&&;
    template<typename Ty, typename... Types>
    [[nodiscard]] constexpr auto get(posu::vmath::arith_tuple<Types...>& value) noexcept -> Ty&;
    template<typename Ty, typename... Types>
    [[nodiscard]] constexpr auto get(posu::vmath::arith_tuple<Types...>&& value) noexcept -> Ty&&;
    template<typename Ty, typename... Types>
    [[nodiscard]] constexpr auto get(const posu::vmath::arith_tuple<Types...>& value) noexcept
        -> const Ty&;
    template<typename Ty, typename... Types>
    [[nodiscard]] constexpr auto get(const posu::vmath::arith_tuple<Types...>&& value) noexcept
        -> const Ty&&;
    //! @}

} // namespace std

#include "posu/ipp/vmath.ipp"

#endif // #ifndef POSU_VMATH_HPP
