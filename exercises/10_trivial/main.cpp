#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16];
    int cached;
};
void init_cache(FibonacciCache &cache){
    cache.cache[0]=0;
    cache.cache[1]=1;
    cache.cached = 2;
}

// TODO: 实现正确的缓存优化斐波那契计算
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    if(i<=0) return 0;
    if(i<=1) return 1;
    if(i<cache.cached)
    {
        return cache.cache[i];
    }
    for(int j=cache.cached;j<=i&&j<16;++j)
    {
        cache.cache[j] = cache.cache[j-1] + cache.cache[j-2];
        cache.cached = j+1;
    }
    return cache.cache[i];
}

int main(int argc, char **argv) {   
    // TODO: 初始化缓存结构体，使计算正确
    // NOTICE: C/C++ 中，读取未初始化的变量（包括结构体变量）是未定义行为
    // READ: 初始化的各种写法 <https://zh.cppreference.com/w/cpp/language/initialization>
    FibonacciCache fib;
    init_cache(fib);
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
