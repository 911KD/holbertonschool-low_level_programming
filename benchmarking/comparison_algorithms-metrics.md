# comparison_algorithms metrics

## Raw results

### Run 1
Naive algorithm result: 625025000
Naive algorithm time: 2.636223 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000077 seconds

### Run 2
Naive algorithm result: 625025000
Naive algorithm time: 2.495385 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000074 seconds

### Run 3
Naive algorithm result: 625025000
Naive algorithm time: 2.490203 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000103 seconds

## Averages

| Implementation | Average time (seconds) |
|---|---|
| Naive (A) | 2.540604 |
| Single-pass (B) | 0.000085 |

## Relative difference

Implementation A (naive) is ~30,000 times slower than implementation B (single-pass).

## Notes

- The naive version uses two nested loops (O(n²), about 1.25 billion checks), while the single-pass version uses one loop (O(n), 50,000 checks).
- The single-pass times are very small, so they vary more between runs (0.000074 to 0.000103 seconds), but the gap between the two implementations stays huge.
- Longer runtime keeps the CPU active longer, which means more energy is used.
