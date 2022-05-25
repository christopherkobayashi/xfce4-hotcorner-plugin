/* Copyright (c) BrianHsu <brianhsu.hsu@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include<libnotify/notify.h>

#include <libwnck/libwnck.h>
#include "util.h"

gboolean is_upper_left(GdkRectangle monitorInfo, gint x, gint y)
{
	return (x == monitorInfo.x) && (y == monitorInfo.y);
}

gboolean is_upper_right(GdkRectangle monitorInfo, gint x, gint y)
{
	return (x == monitorInfo.x + monitorInfo.width - 1)
	    && (y == monitorInfo.y);
}

gboolean is_lower_right(GdkRectangle monitorInfo, gint x, gint y)
{
	return (x == monitorInfo.x + monitorInfo.width - 1)
	    && (y == monitorInfo.y + monitorInfo.height - 1);
}

gboolean is_lower_left(GdkRectangle monitorInfo, gint x, gint y)
{
	return (x == monitorInfo.x)
	    && (y == monitorInfo.y + monitorInfo.height - 1);
}

void toggle_desktop(int spot __attribute__((unused)),
		    HotCorner * hotCorner __attribute__((unused)))
{
	WnckScreen *wnck = wnck_screen_get_default();
	gboolean is_showing = wnck_screen_get_showing_desktop(wnck);

	wnck_screen_toggle_showing_desktop(wnck, !is_showing);
}

void turn_off_monitor(int spot __attribute__((unused)),
		      HotCorner * hotCorner __attribute__((unused)))
{
	NotifyNotification *notif;
	int ret = system("xset dpms force off");

	if (ret) {
		notify_init("hotcorner-notify");
		notif = notify_notification_new("HotCorner", "Could not turn off monitor", NULL);
		notify_notification_show(notif, NULL);
	}
}

void start_screensaver(int spot __attribute__((unused)),
		       HotCorner * hotCorner __attribute__((unused)))
{
	NotifyNotification *notif;
	int ret = system("xset s activate");

	if (ret) {
		notify_init("hotcorner-notify");
		notif = notify_notification_new("HotCorner", "Could not activate xscreensaver", NULL);
		notify_notification_show(notif, NULL);
	}
}

void start_dashboard(int spot __attribute__((unused)),
		     HotCorner * hotCorner __attribute__((unused)))
{
	NotifyNotification *notif;

	int ret = system("xfdashboard");

	if (ret) {
		notify_init("hotcorner-notify");
		notif = notify_notification_new("HotCorner", "Could not start xfdashboard", NULL);
		notify_notification_show(notif, NULL);
	}
}

void run_command(const gchar * command)
{
	NotifyNotification *notif;
	gchar *value = g_strstrip(g_strdup(command));
	int ret;

	if (strlen(value) > 0) {
		ret = system(value);
		if (ret) {
			notify_init("hotcorner-notify");
			notif = notify_notification_new("HotCorner", "Could not start command", NULL);
			notify_notification_show(notif, NULL);
		}
	}

	g_free(value);
}

