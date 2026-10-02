# Median benchmark: `std::sort` vs `std::nth_element`

Small C++ micro-benchmark comparing two ways to compute the median of `std::vector<int>`:
- **`std::sort`** (full sort, ~O(N log N))
- **`std::nth_element`** (selection/partition, avg ~O(N))

`nth_element` is typically faster when you only need the median, because it avoids fully sorting the data.

## Build
```bash
g++ -O3 -std=c++17 -march=native -DNDEBUG benchmark_nth_element.cpp -o bench

## Run
bash
./bench

## Notes
- Both algorithms modify the input vector. For fair results, benchmark on **separate copies** of the same generated data.
- Timing is measured using `std::chrono`.


