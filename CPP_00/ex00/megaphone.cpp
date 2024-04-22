#include <iostream>
// #include <string>

int main(int argc, char **argv)
{
	std::string str;

	if (argc == 1)
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; argv[i]; i++) {
			for (int j = 0; argv[i][j]; j++) {
				str.push_back(toupper(argv[i][j]));
			}
		}
	}
	std::cout << str << std::endl;
	return 0;
}

/*
Problema de cin: En cuanto encuentra un caracter vacio (espacios, tabulaciones, etc)
lo asigna a la variable indicada y mantiene en un buffer el resto del input que
introduce el usuario. Dos alternativas:
	- gets() -> no respeta el tamaño asignado a la variable, sino que coge todo
	el input del usuario y utiliza memoria que no se le asigna previamente en caso de overflow
	- std::cin.getline(var, tamaño, cunado termina) -> si respeta tamaño indicado. Es la mejor
	opción.
*/
