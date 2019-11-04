#include "IMonitorModule.hpp"
#include "TimeModule.hpp"
#include "NcursesDisplay.hpp"
#include "includes.hpp"
#include "CPUModule.hpp"

int main()
{
    TimeModule *timemod = new TimeModule;
    //CPUModule *proc = new CPUModule;
    NcursesDisplay window;
    window.addModule(timemod);
    window.addModule(new CPUModule);

    window.showModules();
}