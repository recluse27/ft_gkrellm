#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP
#include "IMonitorModule.hpp"
#include <iostream>

class TimeModule : public IMonitorModule
{
	public:
		TimeModule(void);
        void refreshData(void);
		~TimeModule(void);

	private:

};

#endif