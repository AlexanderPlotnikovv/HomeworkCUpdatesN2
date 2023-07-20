#include <iostream>
#include <variant>
#include <typeinfo>
#include <vector>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

void vectorprint(std::vector<int> vector)
{
	for (auto i : vector)
	{
		std::cout << i << " ";
	}
}

int main()
{
	int a = 9;
	std::string b = "the";
	std::vector <int> c = {1,2,3};
	std::variant <int, std::string, std::vector <int> > variant = get_variant();
	if (std::holds_alternative<int>(variant))
	{
		std::cout << 2 * a;
	}
	else if (std::holds_alternative<std::string>(variant))
	{
		std::cout << b;
	}
	else
	{
		vectorprint(c);
	}
	return 0;
}