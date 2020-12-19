#include <utility>

namespace posu::units {

    namespace detail {

        template<typename Value>
        [[nodiscard]] constexpr auto as_parent(Value&& value) noexcept
        {
            using chrono_type = typename std::remove_cvref_t<Value>::parent_type;

            if constexpr(std::is_lvalue_reference_v<Value&&>) {
                if constexpr(std::is_const_v<std::remove_reference_t<Value>>) {
                    if constexpr(std::is_volatile_v<std::remove_reference_t<Value>>) {
                        return static_cast<const volatile chrono_type&>(std::forward<Value>(value));
                    }
                    else {
                        return static_cast<const chrono_type&>(std::forward<Value>(value));
                    }
                }
                else {
                    if constexpr(std::is_volatile_v<std::remove_reference_t<Value>>) {
                        return static_cast<volatile chrono_type&>(std::forward<Value>(value));
                    }
                    else {
                        return static_cast<chrono_type&>(std::forward<Value>(value));
                    }
                }
            }
            else {
                if constexpr(std::is_const_v<std::remove_reference_t<Value>>) {
                    if constexpr(std::is_volatile_v<std::remove_reference_t<Value>>) {
                        return static_cast<const volatile chrono_type&&>(
                            std::forward<Value>(value));
                    }
                    else {
                        return static_cast<const chrono_type&&>(std::forward<Value>(value));
                    }
                }
                else {
                    if constexpr(std::is_volatile_v<std::remove_reference_t<Value>>) {
                        return static_cast<volatile chrono_type&&>(std::forward<Value>(value));
                    }
                    else {
                        return static_cast<chrono_type&&>(std::forward<Value>(value));
                    }
                }
            }
        }

        template<typename TagType, typename Value>
        [[nodiscard]] constexpr auto as_quantity(Value&& value) noexcept
        {
            using chrono_type = std::remove_cvref_t<Value>;
            using quantity_type =
                base_unit<typename chrono_type::rep, typename chrono_type::period, TagType>;

            return quantity_type(std::forward<Value>(value));
        }

    } // namespace detail

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

    template<typename Rep1, typename Period1, typename Rep2, typename Period2, typename TypeTag>
    [[nodiscard]] constexpr auto operator==(
        const base_unit<Rep1, Period1, TypeTag>& lhs, const base_unit<Rep2, Period2, TypeTag>& rhs)
        -> bool
    {
        return static_cast<const std::chrono::duration<Rep1, Period1>&>(lhs) ==
               static_cast<const std::chrono::duration<Rep2, Period2>&>(rhs);
    }

} // namespace posu::units
