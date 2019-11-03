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
	// printf("%s \n", someString.c_str());

    return (someString);

}



int		main(void)
{
	//////////////// HOSTNAME + USERNAME ///////////////
	printf("%s\n", get_hostname().c_str());
	printf("%s\n", get_username().c_str());
	////////////////////////////////////////////////////
	

	return (0);
}
