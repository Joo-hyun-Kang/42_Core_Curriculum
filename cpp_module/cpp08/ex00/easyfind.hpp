#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>
# include <deque>
# include <list>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator iter;

    iter = std::find(container.begin(), container.end(), value);

    if (iter == container.end())
    {
        throw std::runtime_error("can't find value");
    }

    return iter;
}

#endif
