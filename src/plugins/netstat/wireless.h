#ifndef HAVE_NS_WIRELESS_H
#define HAVE_NS_WIRELESS_H

#include "netstat.h"

#define NS_WIRELESS_AUTH_OFF       0
#define NS_WIRELESS_AUTH_WEP       1
#define NS_WIRELESS_AUTH_WPA_PSK   2

typedef struct {
	char *essid;
	char *apaddr;
	int quality;
	int en_method;
	gboolean haskey;
} ap_info;

typedef struct {
	ap_info             *info;
	struct ap_info_node *next;
} APLIST;

void wireless_aplist_free(APLIST *aplist);
APLIST *wireless_scanning(int iwsockfd, const char *ifname);

#endif