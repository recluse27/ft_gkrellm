#include "../headers/CPUModule.hpp"
// #include "includes.hpp"
#include "../headers/header.hpp"

CPUModule::CPUModule(void)
{
	
}

CPUModule::~CPUModule(void)
{
	
}

void	CPUModule::refreshData(void)
{
    char		*buf;
	buf = new char(CPU_BUF_SIZE);
	std::string	ret;
    flag_text = 1;
    FILE* top = popen("ps -axro pcpu | awk '{sum+=$1} END {print sum}'", "r");
    if (top)
        fgets(buf, CPU_BUF_SIZE, top);
    pclose(top);
    // return buf;
	ret = std::string(buf);
    data_t = "CPU:";
    data_n = atoi(ret.c_str());
}