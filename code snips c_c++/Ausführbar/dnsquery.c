/*<dnsquery>
    Copyright (C) <2017>  <Simperl Tobias>
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>		/* getaddrinfo, getnameinfo */
#include <stdio.h>		
#include <stdlib.h>		
#include <string.h>		
 
int main()
{
	struct addrinfo hints, *res, *res0;
	int error;
	char host[NI_MAXHOST];
  

	memset(&hints, 0, sizeof hints);
	hints.ai_family = PF_UNSPEC;     
	hints.ai_socktype = SOCK_DGRAM; 
 
	error = getaddrinfo("www.realraum.at", NULL, &hints, &res0);
	if (error) 
  {
		fprintf(stderr, "%s\n", gai_strerror(error));
		exit(1);
	}

	for (res = res0; res; res = res->ai_next) 
  {
		error = getnameinfo(res->ai_addr, res->ai_addrlen, host, sizeof host, NULL, 0, NI_NUMERICHOST);
 
		if (error) fprintf(stderr, "%s\n", gai_strerror(error)); 
    else printf("%s\n", host);
	}

	freeaddrinfo(res0);
 
	return 0;
}