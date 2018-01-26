#include "Utils.hpp"

QString randomQString() noexcept
{
    const size_t size = 5 + rand() % 20;
    QString res = "";

    for (size_t i = 0; i < size; ++i)
        res += 'a' + rand() % 26;

    return res;
}
