#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP
#include "IMonitorModule.hpp"

class RAM_HPP : public IMonitorModule
{
	private:
	public:
		RAM();
		RAM(RAM const &src);
		~RAM();

		void getRAM();
};

#endif
