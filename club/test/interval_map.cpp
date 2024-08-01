#include <map>
#include <iostream>
using namespace std;

template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
auto it = m_map.upper_bound(keyEnd);
if(it == m_map.begin()) {
	if(!(val == m_valBegin)) {
		m_map[keyBegin] = val;
		m_map[keyEnd] = m_valBegin;
	}
	return;
}

// guaranteed that 'it' is not begin and map is not empty.
it--;
bool addEnd = false;
V addVal;
if(!(it->second == val)) {
	addEnd = true;
	addVal = it->second;
}

// now if it is equal to keyEnd, we might delete that...
while(it != m_map.begin() && !(it->first < keyBegin)) {
	m_map.erase(it--);
}

if(it == m_map.begin() && !(it->first < keyBegin)) {
	m_map.erase(it);
	if(!(m_valBegin == val)) {
		m_map[keyBegin] = val;
	}
} else {
	if(!(it->second == val)) {
		m_map[keyBegin] = val;
	}
}

if(addEnd) {
	m_map[keyEnd] = addVal;
}


// 


// V last_val;
// if(it == m_map.begin()) {
// 	last_val = m_valBegin;
// } else {
// 	last_val = (--it)->second;
// }

// if(!(last_val == val)) {
// 	m_map[keyEnd] = last_val;
// }

// m_map[keyBegin] = val;

// while(it->first > keyBegin) {
// 	K key = it->first;
// 	m_map.erase(it--);
// }
// cout << it->first << " " << it->second << " before\n";
// V prev_val = (it == m_map.begin() ? m_valBegin : (--it)->second);
// cout << it->first << " " << it->second << " after\n";

// if(prev_val == val) {
// 	m_map.erase(keyBegin);
// }

for(auto el : m_map) {
	cout << el.first << " " << el.second << "\n";
}
cout << "\n";

	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.


int main() {
	int n;
	cin >> n;
	interval_map<int, char> m('A');
	while(n--) {
		int x, y;
		char c;
		cin >> x >> y >> c;
		m.assign(x, y, c);
	}

	for(int i = 0; i < 10; i++) {
		cout << m[i];
	}
	cout << "\n";

	// int q;
	// cin >> q;
	// while(q--) {
	// 	int x;
	// 	cin >> x;
	// 	cout << m[x] << "\n";
	// }

}