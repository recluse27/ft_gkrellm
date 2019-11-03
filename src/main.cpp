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



#include "printf.h"


#include <iostream>
#include <string>
#include <unistd.h>
#include <limits.h>
#include <sys/utsname.h>
#include <time.h>

#include <ifaddrs.h>
#include <stdio.h>
#include <string.h>





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
	return ( ret );


}



int		main(void)
{
	//////////////// HOSTNAME + USERNAME ///////////////
	// printf("%s\n", get_hostname().c_str());
	// printf("%s\n", get_username().c_str());
	////////////////////////////////////////////////////

	//////////////// OS INFO ///////////////////////////
	// get_os_info();
	////////////////////////////////////////////////////

	/////////////// Date/Time //////////////////////////
	// printf("%s\n", get_datetime().c_str());
	////////////////////////////////////////////////////

	/////////////////////////// CPU ////////////////////



	/////////////////////// NETWORK ////////////////////
	printf("%s\n", network_getInfo().c_str());
    ////////////////////////////////////////////////////

	return (0);
}
