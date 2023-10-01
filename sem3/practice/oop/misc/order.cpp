#include <algorithm>
#include <cmath>

void abssort(float *x, unsigned n)
{
    std::sort(x, x + n,
              [](float a, float b) { return (std::abs(a) < std::abs(b)); });
}
