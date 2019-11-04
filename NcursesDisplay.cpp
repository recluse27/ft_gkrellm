#include "NcursesDisplay.hpp"
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "TimeModule.hpp"
#include "includes.hpp"
NcursesDisplay::NcursesDisplay(void)
{
}

NcursesDisplay::~NcursesDisplay(void)
{
	
}


void NcursesDisplay::displayModule(int pos, IMonitorModule *module) {
    int offset = 10;
    int val;
    const char * c = (*module).getName().c_str();  
    mvaddstr(pos,0,c);
    if ((*module).getFlag() == 1)
    {
        val = ((*module).getData());
        val = val > 100 ? 100 : val;
        for (int n = 0; n < val; n++)
            mvaddch(pos,n+offset,'/');
        for (int n = val; n < 100; n++)
            mvaddch(pos,n+offset,'.');
        refresh();
    }
}
std::list<IMonitorModule*>::iterator m;
void NcursesDisplay::showModules(void) {
	initscr();
    srand (time(NULL));
    while (true) {
        int pos = 0;
        for (m = modules.begin(); m != modules.end(); m++)
        {
            (*m)->refreshData();
            displayModule(pos, *m);
            pos++;
            usleep(1000000);
        }
        refresh();
    }
   // while (true) {
   //     displayModule(0, &timemod);
   //     timemod.refreshData();
   // }
    getch();
    endwin();

}