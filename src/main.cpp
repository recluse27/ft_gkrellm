/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:33:12 by vlazuka           #+#    #+#             */
/*   Updated: 2019/11/02 19:33:42 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.hpp"
#include "../headers/IMonitorModule.hpp"
#include "../headers/TimeModule.hpp"
#include "../headers/NcursesDisplay.hpp"
#include "../headers/CPUModule.hpp"


#include "printf.h"


std::string	get_hostname()
{
	#define BUFSIZE 256
    char buf[BUFSIZE];
    size_t buflen = BUFSIZE;

    if(gethostname(buf, buflen) == 0)
    {
    	std::string someString(buf);
        return (someString);
    }

    return "";
}



std::string	get_username()
{
	char *c;
	c = getlogin();

	std::string someString(c);

    return (someString);
}



int		get_os_info()
{
	struct utsname buf;
	if (uname(&buf))
		return 1;

	printf("System : %s\n", buf.sysname);
	printf("Node name: %s\n", buf.nodename);
	printf("Release : %s\n", buf.release);
	printf("Version : %s\n", buf.version);
	printf("Machine : %s\n", buf.machine);

	return 0;
}


std::string	get_datetime()
{
	time_t              tm;
	std::string         ret;
	struct tm			*s_tm;
	char                buff[60];

	time(&tm);
	s_tm = localtime(&tm);
	strftime(buff, 60, "%m/%e/%Y %I:%M:%S%p.", s_tm);

	ret = std::string(buff);

	return (ret);
}


std::string	network_getInfo()
{
	std::string					ret;
	std::stringstream			stream;
	FILE 						*filename;
	char						buff[1024];

	if(not (filename = popen("/usr/bin/top | /usr/bin/head -n9 | /usr/bin/grep 'Network'", "r")))
		return ( "Error!" );
	while(fgets(buff, sizeof(buff), filename))
		stream << buff;
	pclose( filename );
	ret = " " + stream.str();
	ret.insert(36, 1, '\n');
	ret.insert(37, 2, '\t');
	return (ret);
}




std::string	get_N_processes()
{
	char		*buf;
	buf = new char(CPU_BUF_SIZE);
	std::string	ret;
    FILE* top = popen("top -l 1 | grep \"Processes\" |  cut -d' ' -f2", "r");
    if (top)
        fgets(buf, CPU_BUF_SIZE, top);
    pclose(top);
    // return buf;
	ret = std::string(buf);

	return (ret);
}


void	get_model_and_cores()
{
    std::string         model;
    size_t              core_count;
    char                *buf;

    char    str[40];
    size_t  len = sizeof(str);
    

    sysctlbyname("machdep.cpu.brand_string", str, &len, NULL, 0);
    model = str;
    sysctlbyname("machdep.cpu.core_count", &core_count, &len, NULL, 0);
    buf = new char(CPU_BUF_SIZE);
    printf("%lu\n", core_count);
	printf("%s\n", model.c_str());	

}



std::string	get_cpu_usage()
{
	char		*buf;
	buf = new char(CPU_BUF_SIZE);
	std::string	ret;

    FILE* top = popen("top -l 1 | grep \"CPU usage:\" |  cut -d ' ' -f3", "r");
    if (top)
        fgets(buf, CPU_BUF_SIZE, top);
    pclose(top);
    // return buf;
	ret = std::string(buf);

	return (ret);
}



size_t	get_RAM_memory_all()
{
	char		*buf;
	buf = new char(RAM_BUF_SIZE);
    size_t size;
    size_t len;
    len = sizeof(size);

    sysctlbyname("hw.memsize", &size, &len, NULL, 0); // number of RAM
	// printf("%lu\n", size); // size of all RAM in bytes
    // printf("%lu\n", len);

    return (size);
}


size_t	get_RAM_memory_used()
{
	char		*buf;
	buf = new char(RAM_BUF_SIZE);
    FILE* top = popen("top -l 1 | grep \"PhysMem\" | cut -d'(' -f 1 | cut -d' ' -f 2", "r");
    size_t res;
    if (top)
        fgets(buf, RAM_BUF_SIZE, top);
    pclose(top);
    // return buf;
    // printf("%s\n", buf); // size of used memory in megabytes
    res = atoi(buf);
    return (res * 1024 * 1024);
}

// int		main(void)
// {
// 	//////////////// HOSTNAME + USERNAME ///////////////
// 	printf("%s\n", get_hostname().c_str());
// 	printf("%s\n", get_username().c_str());
// 	////////////////////////////////////////////////////

// 	//////////////// OS INFO ///////////////////////////
// 	get_os_info();
// 	////////////////////////////////////////////////////

// 	/////////////// Date/Time //////////////////////////
// 	printf("%s\n", get_datetime().c_str());
// 	////////////////////////////////////////////////////

// 	///////////////////////// CPU //////////////////////
// 	get_model_and_cores(); // model and number of cores
//     printf("%s\n", get_N_processes().c_str()); // number of processes
//     printf("%s\n", get_cpu_usage().c_str()); // cpu usage
// 	////////////////////////////////////////////////////

// 	//////////////////////// RAM ///////////////////////
// 	printf("%lu\n", get_RAM_memory_all());
// 	printf("%lu\n", get_RAM_memory_used());
// 	////////////////////////////////////////////////////

// 	/////////////////////// NETWORK ////////////////////
// 	printf("%s\n", network_getInfo().c_str());
//     ////////////////////////////////////////////////////

// 	return (0);
// }

// #include "../headers/IMonitorModule.hpp"
// #include "../headers/TimeModule.hpp"
// #include "../headers/NcursesDisplay.hpp"
// #include "../headers/header.hpp"
// #include "../headers/CPUModule.hpp"

int main(void)
{
    TimeModule *timemod = new TimeModule;
    //CPUModule *proc = new CPUModule;
    NcursesDisplay window;
    window.addModule(timemod);
    window.addModule(new CPUModule);

    window.showModules();
}
