/// Range macro
///   apply for rawarray or containers iteration
///   used by:
///     std::sort related
#include <iterator>
using std::begin;
using std::end;
#define ALL(x) begin(x), end(x)
#define RNG_N(x, n) begin(x), begin(x) + n
/// Range macro end

/// Floating-numbers comparision macro
///   apply for judging whether two value(defined by float/double or primitive
///   floating numbers) are comparision with a specified precision(epsilon).
#include <cmath>
using std::fabs;
#define FP_EQ(a, b) ((fabs((a) - (b))) < (1e-8))
#define FP_GT(a, b) (((a) - (b)) > (1e-8))
#define FP_GT_EQ(a, b) (((a) - (b)) > (-1e-8))
#define FP_LT(a, b) (((a) - (b)) < (-1e-8))
#define FP_LT_EQ(a, b) (((a) - (b)) < (1e-8))

/// Floating-numbers equal macro end
