AM_CPPFLAGS = \
	-Wall -Wextra -Werror					\
	-DWNCK_I_KNOW_THIS_IS_UNSTABLE=1			\
	-DGETTEXT_PACKAGE=\"xfce4-hotcorner-plugin\" 		\
	-DG_LOG_DOMAIN=\"xfce4-hotcorner-plugin\"		\
	-DLOCALEDIR=\"$(localedir)\"				\
	$(PLATFORM_CPPFLAGS)

plugindir = $(libdir)/xfce4/panel/plugins
plugin_LTLIBRARIES = libhotcorner.la

libhotcorner_la_SOURCES =	\
	hotcorner.c						\
	util.c

libhotcorner_la_CFLAGS =					\
	$(GTK_LIBS)						\
	$(LIBXFCE4UTIL_CFLAGS)					\
	$(LIBXFCE4UI_CFLAGS)					\
	$(LIBXFCE4PANEL_CFLAGS)					\
	$(LIBWNCK_CFLAGS)					\
	$(PLATFORM_CFLAGS)

libhotcorner_la_LDFLAGS =					\
	-avoid-version 						\
	-module 						\
	-no-undefined						\
	-export-symbols-regex '^xfce_panel_module_(preinit|init|construct)' \
	$(PLATFORM_LDFLAGS)

libhotcorner_la_LIBADD =					\
	$(LIBXFCE4UTIL_LIBS)					\
	$(LIBXFCE4UI_LIBS)					\
	$(LIBXFCE4PANEL_LIBS)					\
	$(LIBWNCK_LIBS)						\
	$(LIBNOTIFY_LIBS)

desktopdir = $(datadir)/xfce4/panel/plugins
desktop_in_files = hotcorner.desktop.in
desktop_DATA = $(desktop_in_files:.desktop.in=.desktop)

@INTLTOOL_DESKTOP_RULE@

EXTRA_DIST =								\
	$(desktop_in_files)						\
	grammar.txt

CLEANFILES = $(desktop_DATA)

# vi:set ts=8 sw=8 noet ai nocindent syntax=automake:
