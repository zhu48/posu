
namespace posu {

    namespace detail {

        template<typename... Lists>
        using concatenate_impl_t = typename concatenate_impl<Lists...>::type;

        template<typename... LhsTypes, typename... RhsTypes>
        struct concatenate_impl<type_list<LhsTypes...>, type_list<RhsTypes...>> {
            using type = type_list<LhsTypes..., RhsTypes...>;
        };

        template<typename First, typename Second, typename... Rest>
        struct concatenate_impl<First, Second, Rest...>
            : concatenate_impl<concatenate_impl_t<First, Second>, Rest...> {
        };

        template<typename... Types, typename T>
        struct prepend_impl<type_list<Types...>, T>
            : concatenate_impl<type_list<T>, type_list<Types...>> {
        };

        template<typename... Types, typename T>
        struct prepend_impl<type_list<Types...>, type_list<T>>
            : concatenate_impl<type_list<T>, type_list<Types...>> {
        };

        template<typename... Types, typename T>
        struct append_impl<type_list<Types...>, T>
            : concatenate_impl<type_list<Types...>, type_list<T>> {
        };

        template<typename... Types, typename T>
        struct append_impl<type_list<Types...>, type_list<T>>
            : concatenate_impl<type_list<Types...>, type_list<T>> {
        };

        template<typename First, typename... Rest>
        struct pop_front_impl<type_list<First, Rest...>> {
            using type = type_list<Rest...>;
        };

        template<typename Type>
        struct pop_back_impl<type_list<Type>> {
            using type = type_list<>;
        };

        template<typename First, typename Second>
        struct pop_back_impl<type_list<First, Second>> {
            using type = type_list<First>;
        };

        template<typename First, typename... Rest>
        struct pop_back_impl<type_list<First, Rest...>>
            : prepend_impl<pop_back<type_list<Rest...>>, First> {
        };

        template<typename List, std::size_t... I>
        struct take_items<List, std::index_sequence<I...>> {
            using type = type_list<typename List::template at<I>...>;
        };

        template<typename List, typename T, std::size_t I>
        [[nodiscard]] constexpr auto find_impl_fn() noexcept -> std::size_t
        {
            if constexpr(I < std::tuple_size_v<List>) {
                if constexpr(std::same_as<std::tuple_element_t<I, List>, T>) {
                    return I;
                }
                else {
                    return find_impl_fn<List, T, I + 1>();
                }
            }

            return I;
        }

    } // namespace detail

    template<typename... Types>
    template<typename... Args>
    [[nodiscard]] constexpr auto type_list<Types...>::make_tuple(Args&&... args) noexcept(
        std::is_nothrow_constructible_v<tuple, Args...>) -> tuple
    {
        return std::make_tuple(std::forward<Args>(args)...);
    }

    template<typename... Types>
    template<typename... Args>
    [[nodiscard]] constexpr auto type_list<Types...>::make_variant(Args&&... args) noexcept(
        std::is_nothrow_constructible_v<variant, Args...>) -> variant
    {
        return variant(std::forward<Args>(args)...);
    }

    template<typename TypeList, typename... Args> // clang-format off
        requires is_type_list_v<TypeList>
    [[nodiscard]] constexpr auto // clang-format on
    make_tuple_from(TypeList /*unused*/, Args&&... args) noexcept(
        std::is_nothrow_constructible_v<tuple_from_t<TypeList>>) -> tuple_from_t<TypeList>
    {
        return TypeList::make_tuple(std::forward<Args>(args)...);
    }

    template<typename TypeList, typename... Args> // clang-format off
        requires is_type_list_v<TypeList>
    [[nodiscard]] constexpr auto // clang-format on
    make_variant_from(TypeList /*unused*/, Args&&... args) noexcept(
        std::is_nothrow_constructible_v<variant_from_t<TypeList>>) -> variant_from_t<TypeList>
    {
        return TypeList::make_variant(std::forward<Args>(args)...);
    }

} // namespace posu
