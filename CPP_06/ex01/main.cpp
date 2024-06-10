#include "Serializer.hpp"

int main() {
    Data a;
	a.setStr("Hola mundo");

    // Convertir puntero a uintptr_t
	uintptr_t uIntPtr = Serializer::serialize( &a );
    std::cout << "uIntPtr Decimal value (Address of a): " << uIntPtr << std::endl;
    std::cout << "uIntPtr Hexadecimal value (Address of a): " << std::showbase << std::hex << uIntPtr << std::endl << std::endl;

    // Convertir uintptr_t de vuelta a puntero
	Data *ptrConvertedBack = Serializer::deserialize( uIntPtr );
    std::cout << "ptrConvertedBack string value: " << ptrConvertedBack->getStr() << std::endl;
    std::cout << "ptrConvertedBack Address: " << ptrConvertedBack << std::endl;

    return 0;
}
