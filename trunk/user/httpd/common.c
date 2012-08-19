/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
/*
 * ASUS Home Gateway Reference Design
 * Web Page Configuration Support Routines
 *
 * Copyright 2001, ASUSTeK Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of ASUSTeK Inc.;
 * the contents of this file may not be disclosed to third parties, copied or
 * duplicated in any form, in whole or in part, without the prior written
 * permission of ASUSTeK Inc..
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <syslog.h>
#include <sys/klog.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <shutils.h>

#include "common.h"
#include "variables.c"

#define MAX_LINE_SIZE 512

/* API export for UPnP function */
int LookupServiceId(char *serviceId)
{
    int sid;

    sid = 0;

    while (svcLinks[sid].serviceId!=NULL)
    {
	if ( strcmp(serviceId, svcLinks[sid].serviceId) == 0)
	   break;
	sid ++;
    }

    if (svcLinks[sid].serviceId==NULL)
       return (-1);
    else return (sid);
}

char *GetServiceId(int sid)
{
    return (svcLinks[sid].serviceId);
}

struct variable *GetVariables(int sid)
{
    return (svcLinks[sid].variables);
}

