#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>


struct pair_hash {
	template<class T1, class T2>
	std::size_t operator()(const std::pair<T1, T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);

		// Mainly for demonstration purposes, i.e. works but is overly simple
		// In the real world, use sth. like boost.hash_combine
		return h1 ^ h2;
	}
};


int main() {
	std::unordered_map< std::pair<int, int>, int, pair_hash> bb;
	bb[{1, 1}] = 1;
	return 0;
}
