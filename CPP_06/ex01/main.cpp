#include "Serializer.hpp"

int main() {
    Data a;
	a.setStr("Hola mundo");

    // Convertir puntero a uintptr_t
	uintptr_t uIntPtr = Serializer::serialize( &a );
    std::cout << "El valor del puntero convertido a uintptr_t en decimal: " << uIntPtr << std::endl;
    std::cout << "en hexadecimal: " << std::showbase << std::hex << uIntPtr << std::endl << std::endl;

    // Convertir uintptr_t de vuelta a puntero
	Data *ptrConvertedBack = Serializer::deserialize( uIntPtr );
    std::cout << "El valor apuntado por el puntero convertido de vuelta: " << ptrConvertedBack->getStr() << std::endl;
    std::cout << "La direccion del puntero convertido de vuelta: " << ptrConvertedBack << std::endl;

    return 0;
}
