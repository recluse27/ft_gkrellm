#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP
#include <iostream>

class IMonitorModule
{
	public:
		IMonitorModule(void);
                ~IMonitorModule(void);
                int getData(void);
                int getFlag(void);
                std::string getName(void);
                virtual void refreshData(void);

	protected:
                int flag_text;
                int data_n;
                std::string data_t;
};

#endif