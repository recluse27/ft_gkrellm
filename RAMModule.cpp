#include "RAMModule.hpp"
#include "includes.hpp"

RAM::RAM()
{
	return ;
}

RAM::RAM(RAM const &src)
{
	*this = src;
}

RAM::~RAM()
{
	return ;
}

void RAM::getRAM()
{
	std::system("top -l 1 | grep PhysMem");
	return ;
}
