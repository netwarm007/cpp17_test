#include <iostream>
#include <string>

struct S
{
    int n;
    std::string s;
    float d;
};

#ifdef __cpp_if_constexpr
template <std::size_t I>
auto& get(S& s)
{
    if constexpr (I == 0)
        return s.n;
    else if constexpr (I == 1)
        return s.s;
    else if constexpr (I == 2)
        return s.d;
}
#else
template<std::size_t I> auto& get(S &s) { return s; }
template<> auto& get<0>(S &s) { return s.n; }
template<> auto& get<1>(S &s) { return s.s; }
template<> auto& get<2>(S &s) { return s.d; }
#endif

int main()
{
    S obj { 0, "hello", 10.0f };
    std::cout << get<0>(obj) << ", " << get<1>(obj) << std::endl;
}
