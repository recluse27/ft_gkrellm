#ifndef NCURSESDISPLAY_HPP
# define NCURSESDISPLAY_HPP
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include <iostream>
#include <list>

class NcursesDisplay : public IMonitorDisplay 
{
	public:
		NcursesDisplay(void);
		~NcursesDisplay(void);
        void showModules(void);
        void displayModule(int pos, IMonitorModule *module);


	private:

};

#endif