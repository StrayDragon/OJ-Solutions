#include <cmath>

bool is_prime(int n){
	if(n <= 1) return false;
	int bound = (int)std::sqrt(1.0 * n);
	for(int i = 2; i <= bound; ++i)
	  if(n % i == 0) return false;
	return true;
}

namespace old{
namespace fn{

[[deprecated("May overflow from the previous implementation")]]
bool is_prime(int n){
	if(n <= 1) return false;
	for(int i = 2; i*i <= n; ++i)
	  if(n % i == 0) return false;
	return true;
}

} // namespace fn
} // namespace old
