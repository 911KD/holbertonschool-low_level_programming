# Green Efficiency Analysis

## Measurement Methodology

All measurements were taken on the same machine, a Windows laptop running Ubuntu through WSL 2, during the same session. Every program was compiled with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long` and executed from the terminal with no other heavy applications intentionally running.

Timing was done inside each program with `clock()` from `<time.h>`. A `clock_t` value is taken right before and right after the code being measured, and the difference is divided by `CLOCKS_PER_SEC` to get seconds. `clock()` measures processor time used by the program, not wall-clock time, so it focuses on the work done by the CPU.

For `baseline_loop` and `comparison_algorithms`, each program was run three times in a row, and the averages were computed from those three runs. For `instrumentation_lab`, I placed one timer around each phase (build, process, reduce) and one outer timer around all three. All `printf` calls were moved after the last measurement, so printing time is never included in any result.

## Observed Performance Differences

The baseline loop (100,000,000 iterations) took 0.386714, 0.421515 and 0.385609 seconds, for an average of about 0.397946 seconds. The values were close but not identical: the second run was about 9% slower than the third, which shows that even a deterministic program has small timing variations between runs.

The biggest difference appeared in `comparison_algorithms`. The naive version took 2.636223, 2.495385 and 2.490203 seconds, for an average of 2.540604 seconds. The single-pass version took 0.000077, 0.000074 and 0.000103 seconds, for an average of about 0.000085 seconds. Both work on the same 50,000 values, but the naive implementation was roughly 30,000 times slower. This matches the structure of the code: the naive version uses nested loops and performs about 1.25 billion checks, while the single-pass version performs only 50,000.

In `instrumentation_lab`, the total time was 0.001065 seconds. BUILD_DATA took 0.000514 seconds, PROCESS took 0.000377 seconds and REDUCE took 0.000169 seconds. Building the dataset was the most expensive phase, at about 48% of the total, while the reduction was the cheapest. The three phases add up to 0.001060 seconds, slightly less than TOTAL, which is expected because the outer timer also includes the small cost of the inner `clock()` calls.

## Relation Between Runtime and Energy Consumption

This project did not measure power in watts, so runtime is used as a proxy. When a program runs longer, the CPU stays busy longer, and a busy CPU generally consumes more energy than an idle one. Under this assumption, the naive algorithm kept the processor working for about 2.54 seconds to complete a task that the single-pass version finished in less than a tenth of a millisecond. For one run this difference is small, but if the same code ran thousands of times on a server, the extra CPU time, and the energy behind it, would add up quickly.

## Limitations of the Experiment

The main limitation is that runtime is not a direct measurement of energy. Real power usage also depends on CPU frequency, temperature and hardware, which were not measured.

Second, `clock()` has limited precision. The single-pass and instrumentation times were below a millisecond, so their relative variation between runs is much larger than for the naive version. The "30,000 times" figure and the phase percentages should be read as approximations.

Third, the experiment ran inside WSL on a laptop with other background processes, and only three runs were recorded for the first two programs and one for the instrumentation lab, which is a small sample. The 9% gap between baseline runs shows how much this environment can affect a single measurement.

## Practical Engineering Takeaway

The choice of algorithm had a far greater impact than any small code change could. Replacing a nested loop with a single pass reduced the runtime from about 2.5 seconds to under a tenth of a millisecond on my machine. Phase-level timing also showed that measuring is the only reliable way to know where time is spent: before running it, it was not obvious that building the data would cost more than processing it. Developers should measure first, then fix the algorithm. Efficient code keeps the CPU busy for less time, which is a simple and practical step toward more sustainable software.
