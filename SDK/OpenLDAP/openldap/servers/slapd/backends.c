/* This work is part of OpenLDAP Software <http://www.openldap.org/>.
 *
 * Copyright 1998-2008 The OpenLDAP Foundation.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted only as authorized by the OpenLDAP
 * Public License.
 *
 * A copy of this license is available in the file LICENSE in the
 * top-level directory of the distribution or, alternatively, at
 * <http://www.OpenLDAP.org/license.html>.
 */
/* This file is automatically generated by configure; please do not edit. */

#include "portable.h"
#include "slap.h"

extern BI_init config_back_initialize;
extern BI_init ldif_back_initialize;

BackendInfo slap_binfo[] = {
	{ "config", config_back_initialize },
	{ "ldif", ldif_back_initialize },
	{ NULL, NULL },
};

/* end of generated file */
