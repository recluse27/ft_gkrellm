#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP
#include "IMonitorModule.hpp"
#include <list>

class IMonitorDisplay
{
	public:
		IMonitorDisplay(void);
		~IMonitorDisplay(void);
        void addModule(IMonitorModule *module);

	protected:
        std::list<IMonitorModule*> modules;

};

#endif