#include <functional>

enum Church {
	value = 0
};

typedef std::function<Church(Church)> ChurchFn_;
typedef std::function<ChurchFn_(ChurchFn_)> ChurchFn;

Church id(Church c) {
	return c;
}

ChurchFn zero(ChurchFn) {
	return [](ChurchFn c) { return id; }
}
/*
ChurchFn succ(ChurchFn) {
	return [](Church c1) {
		return [](Church c2) {
			
		}
	}
}*/

int main() {
	auto z = zero(id);

	return 0;
}
