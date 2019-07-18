#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <iterator>

#include <tuple>

struct S
{
    /* data */
    int n;
    std::string s;
    float d;

    /* compare operator */
    bool operator<(const S& rhs) const
    {
        // compare n to rhs.n,
        // then s to rhs.s,
        // then d to rhs.d
        return std::tie(n, s, d) < std::tie(rhs.n, rhs.s, rhs.d);
    }
};

int main()
{
    std::set<S> mySet;

#ifndef __cpp_structured_bindings
    // pre C++17:
    {
        S value {42, "Test", 3.14};
        std::set<S>::iterator iter;\
        bool inserted;

        // unpacks the return val of insert into iter and inserted
        std::tie(iter, inserted) = mySet.insert(value);

        if (inserted)
        {
            std::cout << "Value(" << iter->n << ", " << iter->s << ", ...) was inserted" << std::endl;
        }
    }
#else
    // with C++17
    {
        S value {100, "abc", 100.0};
        const auto [iter, inserted] = mySet.insert(value);

        if (inserted)
        {
            std::cout << "Value(" << iter->n << ", " << iter->s << ", ...) was inserted" << std::endl;
        }
    }
#endif
}
