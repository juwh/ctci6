#include <set>
#include <unordered_map>
#include <vector>

namespace ctcilib {
	template<typename T, typename E>
	class HashMapList {
		private:
			std::unordered_map<T, std::vector<E>> map;
		
		public:
			/* Insert item into list at key. */
			void put(T key, E item);
			
			/* Insert list of items at key. */
			void put(T key, std::vector<E> items);
			
			/* Get list of items at key. */
			std::vector<E> get(T key);
			
			/* Check if hashmaplist contains key. */
			bool contains_key(T key);
			
			/* Check if list at key contains value. */
			bool contains_key_value(T key, E value);
			
			/* Get the list of keys. */
			std::set<T> key_set();
			
			std::string to_string();
	};
}

using namespace ctcilib;

template<typename T, typename E>
void HashMapList<T, E>::put(T key, E item) {
	if (!contains_key(key)) {
		map.insert(key, std::vector<E>{});
	}
	map.at(key).push_back(item);
}

/* Insert list of items at key. */
template<typename T, typename E>
void HashMapList<T, E>::put(T key, std::vector<E> items) {
	map.insert({key, items});
}

/* Get list of items at key. */
template<typename T, typename E>
std::vector<E> HashMapList<T, E>::get(T key) {
	return map.at(key);
}

/* Check if hashmaplist contains key. */
template<typename T, typename E>
bool HashMapList<T, E>::contains_key(T key) {
	return map.contains(key);
}

/* Check if list at key contains value. */
template<typename T, typename E>
bool HashMapList<T, E>::contains_key_value(T key, E value) {
	if (!contains_key(key)) {
		return false;
	}
	std::vector<E> list = get(key);
	for (auto element : list) {
		if (element == value) {
			return true;
		}
	}
	return false;
}

/* Get the list of keys. */
template<typename T, typename E>
std::set<T> HashMapList<T, E>::key_set() {
	std::set<T> keys{};
	for (auto kv : map) {
		keys.insert(kv.first);
	}
	return keys;
}

template<typename T, typename E>
std::string HashMapList<T, E>::to_string() {
	std::string output{"{"};
	for (auto kv : map) {
		output += map.first + "=" + map.second + ",";
	}
	if (output.length > 1) {
		output.back() = "}";
	} else {
		output += "}"
	}
	return output;
}