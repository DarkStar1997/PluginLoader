#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

extern "C" void display()
{
    printf("Inside %s of %s\n", __func__, __FILE__);
    std::vector<int> arr = {1, 4, 2, 3};
    printf("Max val = %d\n", *std::max_element(arr.begin(), arr.end()));
}
