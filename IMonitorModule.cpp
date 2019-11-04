#include <iostream>
#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule(void)
{
	
}
IMonitorModule::~IMonitorModule(void)
{
	
}
int IMonitorModule::getFlag(void) {
    return(flag_text);
}
int IMonitorModule::getData(void) {
    return(data_n);
}
std::string IMonitorModule::getName(void) {
    return(data_t);
}
void IMonitorModule::refreshData(void) {

}