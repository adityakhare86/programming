#include <bits/stdc++.h>
using namespace std;

template <class T>
void prnt(T x) { std::cerr << x << " "; }
template <class T, class V>
void prnt(std::pair<T, V> p)
{
    std::cerr << "[";
    prnt(p.first);
    prnt(p.second);
    std::cerr << "]";
}
template <class T>
void prnt(std::vector<T> v)
{
    std::cerr << "[";
    for (auto e : v)
        prnt(e);
    std::cerr << "]";
}
template <class T>
void prnt(std::set<T> v)
{
    std::cerr << "[";
    for (auto e : v)
        prnt(e);
    std::cerr << "]";
}
template <class T>
void prnt(std::unordered_set<T> v)
{
    std::cerr << "[";
    for (auto e : v)
        prnt(e);
    std::cerr << "]";
}
template <class T>
void prnt(std::unordered_multiset<T> v)
{
    std::cerr << "[";
    for (auto e : v)
        prnt(e);
    std::cerr << "]";
}
template <class T>
void prnt(std::multiset<T> v)
{
    std::cerr << "[";
    for (auto e : v)
        prnt(e);
    std::cerr << "]";
}
template <class T, class V>
void prnt(std::map<T, V> v)
{
    std::cerr << "{";
    for (auto e : v)
        prnt(e);
    std::cerr << "}";
}
template <class T, class V>
void prnt(std::unordered_map<T, V> v)
{
    std::cerr << "{";
    for (auto e : v)
        prnt(e);
    std::cerr << "}";
}
template <class T, class V>
void prnt(std::multimap<T, V> v)
{
    std::cerr << "{";
    for (auto e : v)
        prnt(e);
    std::cerr << "}";
}
template <class T, class V>
void prnt(std::unordered_multimap<T, V> v)
{
    std::cerr << "{";
    for (auto e : v)
        prnt(e);
    std::cerr << "}";
}

#ifndef ONLINE_JUDGE
void print_time(std::chrono::microseconds duration) { std::cerr << "Execution time: " << duration.count() << "us" << std::endl; }
#define dbg(x)               \
    std::cerr << #x << ": "; \
    prnt(x);                 \
    std::cerr << nl;
#else
void print_time(std::chrono::microseconds duration){};
template <class T>
void dbg(T x){};
#endif

#define var_name(x) std::cout << #x;
#define nl "\n"
#define vll vector<long long int>
#define fr(s, c, p) for (int i = s; i < c; i += p)
#define revfr(s, c, p) for (int i = s; i >= c; i -= p)
#define yes cout << "YES" << '\n';
#define no cout << "NO" << '\n';
using ll = long long int;

void code();

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t{};
    std::cin >> t;
    while (t--)
    {
        code();
    }
    // code();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
#ifndef ONLINE_JUDGE
    print_time(duration);
#endif

    return 0;
}

void code()
{
}