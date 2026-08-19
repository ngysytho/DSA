#include <iostream>
#include <bitset>
#include <bit>
#include <cstdint>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bitset<8> b(13);

cout << b;
// 00001101

cout << b[0];   // lấy bit 0
cout << b.count(); // số bit 1
b.set(2);       // bật bit 2
b.reset(2);     // tắt bit 2
b.flip(2);      // đảo bit 2


int x = 13; // 1101

cout << std::popcount((unsigned)x); // số bit 1 = 3
cout << std::countl_zero((unsigned)x);
cout << std::countr_zero((unsigned)x);

// std::popcount(x);        // đếm số bit 1
// std::countl_zero(x);     // đếm số 0 từ bên trái
// std::countr_zero(x);     // đếm số 0 từ bên phải
// std::bit_width(x);       // số bit cần để biểu diễn x
// std::has_single_bit(x);  // true nếu x là power of 2

// uint8_t
// uint16_t
// uint32_t
// uint64_t

// &   // AND
// |   // OR
// ^   // XOR
// ~   // NOT
// <<  // shift left
// >>  // shift right


// n & 1              // check chẵn/lẻ
// n & (1 << k)       // check bit k
// n | (1 << k)       // bật bit k
// n & ~(1 << k)      // tắt bit k
// n ^ (1 << k)       // đảo bit k
// (n >> k) & 1       // lấy bit k dưới dạng 0/1
}
