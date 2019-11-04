#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP
#include "IMonitorModule.hpp"

class CPUModule : public IMonitorModule
{
	public:
		CPUModule(void);
		~CPUModule(void);
        void refreshData(void);

	private:

};

#endif