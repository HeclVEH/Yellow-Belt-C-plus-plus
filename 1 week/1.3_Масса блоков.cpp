#include <cstdint>
#include <iostream>
using namespace std;

int main() {
	unsigned int num_of_blocks;
	uint64_t density;	
	uint64_t summ = 0;
	cin >> num_of_blocks >> density;
	while (num_of_blocks != 0) {
		--num_of_blocks;
		uint64_t A, B, C;
		cin >> A >> B >> C;
		summ += (density * A * B * C);
	}
	cout << summ;
	return 0;
}

#include <cstdint>
#include <iostream>

using namespace std;

int main() {
	int N, R;
	cin >> N >> R;
	uint64_t answer = 0;
	for (int i = 0; i < N; ++i) {
		int W, H, D;
		cin >> W >> H >> D;
		// ≈сли не привести W к типу uint64_t перед умножением, 
		// произведение будет иметь тип int и случитс€ переполнение.
		// јльтернативное решение Ч хранить сами W, H, D в uint64_t
		answer += static_cast<uint64_t>(W) * H * D;
	}
	answer *= R;
	cout << answer << endl;
	return 0;
}