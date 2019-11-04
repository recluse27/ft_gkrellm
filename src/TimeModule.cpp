#include "../headers/TimeModule.hpp"
#include "../headers/IMonitorModule.hpp"
// #include <iostream>

TimeModule::TimeModule(void)
{
    flag_text = 0;
    return ;
}

TimeModule::~TimeModule(void)
{
    return ;
}

void	TimeModule::refreshData(void)
{
    time_t              tm;
    std::string         ret;
    struct tm			*s_tm;
    char                buff[60];

    time(&tm);
    s_tm = localtime(&tm);
    strftime(buff, 60, "%m/%e/%Y %I:%M:%S%p.", s_tm);

   data_t = std::string(buff);
}