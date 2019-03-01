#include <iostream>
#include <fstream>
#include <cstring>

namespace util
{

bool isSQLite(const char *filename)
{
	std::ifstream ifStream(filename);
	if (!ifStream)
		return false;

	const char sqliteHeader[] = { "SQLite format 3" };

	char header[sizeof sqliteHeader];
	for (char &ch : header)
	{
		if (ifStream.eof() || !ifStream.get(ch))
			return false;
	}

	ifStream.close();
	//std::cout << header;
	return std::strcmp(header, sqliteHeader) == 0;
}

} // namespace util

int main()
{
	if (util::isSQLite(R"(C:\Users\liliam\Desktop\PYDB_top)"))
		std::cout << "Valid SQLite file!";

	std::cin.get();
}