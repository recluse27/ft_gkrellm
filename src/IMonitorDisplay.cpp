#include "../headers/IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay(void)
{
	
}

void IMonitorDisplay::addModule(IMonitorModule *module){
    modules.push_back(module);
}

IMonitorDisplay::~IMonitorDisplay(void)
{
	
}