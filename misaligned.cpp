#include <iostream>
#include <assert.h>

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
        }
    }
    return i * j;
}

int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return major * 5 + minor + 1;
}

void testPairToNumber(MajorColor major, MinorColor minor, int expPairNumber) {
    int pairNumber = GetPairNumberFromColor(major, minor);
    assert(pairNumber == expPairNumber);
}

int main() {
    int result = printColorMap();
    assert(result == 25);
	testPairToNumber(WHITE, BROWN, 4);
    testPairToNumber(VIOLET, SLATE, 24);
    std::cout << "All is well (maybe!)\n";
    return 0;
}