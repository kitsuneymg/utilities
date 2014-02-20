#include <iostream>
#include <string>
using namespace std;

template<typename CharT>
unsigned constexpr const_hash(const CharT *input) {
    return *input ?
        static_cast<unsigned int>(*input) + 33 * const_hash(input + 1) :
        5381;
}

unsigned constexpr operator"" _hash(const char *input, size_t) {
	return const_hash(input);
}

unsigned constexpr operator"" _hash(const wchar_t *input, size_t) {
	return const_hash(input);
}

/*
int main() {
	string s = "hello world";

	switch( const_hash(s.c_str()) ) {
	case "hello world"_hash: 
		cout<<"Woo!";
	}
	return 0;
}
*/
