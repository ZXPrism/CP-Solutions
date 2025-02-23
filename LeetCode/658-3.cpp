// 1. use greedy to prove that we must select k consecutive numbers (a window with length k)
// 2. use binary search to minimize the max distance from x to any element in the window
// the max distance = max(abs(x - v[left]), abs(x - v[right])) = * max(x - v[left], v[right] - x) *
// => max(x - v[left], v[left + k - 1] - x)
// this function has a minimum value, but how to find that with binary search?

// problem: this function is not monotonic, there could be identical elements!
// so we have to make it unique before performing binary search? this would be inefficient!
