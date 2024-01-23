#include "HexString.h"
#include <cassert>

bool TestSubtraction() {
    // Тесты для операции вычитания
    HexString hex1("A1");
    HexString hex2("B2");
    HexString hex3("10");

    HexString result1 = hex1 - hex3;
    HexString result2 = hex2 - hex1;


    return
        (result1.GetHexValue() == "91") &&
        (result2.GetHexValue() == "11");
}
