# Wedit Makefile for project winbinder_c
SRCDIR=c:\@desenv\winbinder\csource\c_binding
CFLAGS=-Ic:\util\lcc\include -IC:\@desenv\WinBinder\csource\core -IC:\@desenv\winbinder\csource\core\wb  -A  -ansic
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	welcome.obj \
	cwb_wb_lib.obj \
	wb_winsys.obj \
	wb_window.obj \
	wb_sysdlg.obj \
	wb_lowlevel.obj \
	wb_generic.obj \
	wb_font.obj \
	wb_draw.obj \
	wb_control_treeview.obj \
	wb_control_toolbar.obj \
	wb_control_tab.obj \
	wb_control_menu.obj \
	wb_control_listview.obj \
	wb_control_hyperlink.obj \
	wb_control_html.obj \
	wb_control_calendar.obj \
	wb_control.obj \
	wb_bitmap.obj

LIBS=iehelper.lib ole32.lib oleaut32.lib psapi.lib shell32.lib uuid.lib winmm.lib
EXE=c:\@desenv\winbinder\binaries\c\hello.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -s -subsystem windows -o c:\@desenv\winbinder\binaries\c\hello.exe $(OBJS) $(LIBS)

# Build welcome.c
WELCOME_C=\
	C:\@desenv\winbinder\csource\core\wb\wb.h\
	C:\@desenv\winbinder\csource\core\wb\wb_version.h\

welcome.obj: $(WELCOME_C) $(SRCDIR)\welcome.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\welcome.c

# Build cwb_wb_lib.c
CWB_WB_LIB_C=\
	C:\@desenv\winbinder\csource\core\wb\wb.h\
	C:\@desenv\winbinder\csource\core\wb\wb_version.h\

cwb_wb_lib.obj: $(CWB_WB_LIB_C) $(SRCDIR)\cwb_wb_lib.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\cwb_wb_lib.c

# Build wb_winsys.c
WB_WINSYS_C=\

wb_winsys.obj: $(WB_WINSYS_C) c:\@desenv\winbinder\csource\core\wb\wb_winsys.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_winsys.c

# Build wb_window.c
WB_WINDOW_C=\

wb_window.obj: $(WB_WINDOW_C) c:\@desenv\winbinder\csource\core\wb\wb_window.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_window.c

# Build wb_sysdlg.c
WB_SYSDLG_C=\

wb_sysdlg.obj: $(WB_SYSDLG_C) c:\@desenv\winbinder\csource\core\wb\wb_sysdlg.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_sysdlg.c

# Build wb_lowlevel.c
WB_LOWLEVEL_C=\

wb_lowlevel.obj: $(WB_LOWLEVEL_C) c:\@desenv\winbinder\csource\core\wb\wb_lowlevel.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_lowlevel.c

# Build wb_generic.c
WB_GENERIC_C=\

wb_generic.obj: $(WB_GENERIC_C) c:\@desenv\winbinder\csource\core\wb\wb_generic.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_generic.c

# Build wb_font.c
WB_FONT_C=\

wb_font.obj: $(WB_FONT_C) c:\@desenv\winbinder\csource\core\wb\wb_font.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_font.c

# Build wb_draw.c
WB_DRAW_C=\

wb_draw.obj: $(WB_DRAW_C) c:\@desenv\winbinder\csource\core\wb\wb_draw.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_draw.c

# Build wb_control_treeview.c
WB_CONTROL_TREEVIEW_C=\

wb_control_treeview.obj: $(WB_CONTROL_TREEVIEW_C) c:\@desenv\winbinder\csource\core\wb\wb_control_treeview.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_control_treeview.c

# Build wb_control_toolbar.c
WB_CONTROL_TOOLBAR_C=\

wb_control_toolbar.obj: $(WB_CONTROL_TOOLBAR_C) c:\@desenv\winbinder\csource\core\wb\wb_control_toolbar.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_control_toolbar.c

# Build wb_control_tab.c
WB_CONTROL_TAB_C=\

wb_control_tab.obj: $(WB_CONTROL_TAB_C) c:\@desenv\winbinder\csource\core\wb\wb_control_tab.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_control_tab.c

# Build wb_control_menu.c
WB_CONTROL_MENU_C=\

wb_control_menu.obj: $(WB_CONTROL_MENU_C) c:\@desenv\winbinder\csource\core\wb\wb_control_menu.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_control_menu.c

# Build wb_control_listview.c
WB_CONTROL_LISTVIEW_C=\

wb_control_listview.obj: $(WB_CONTROL_LISTVIEW_C) c:\@desenv\winbinder\csource\core\wb\wb_control_listview.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_control_listview.c

# Build wb_control_hyperlink.c
WB_CONTROL_HYPERLINK_C=\

wb_control_hyperlink.obj: $(WB_CONTROL_HYPERLINK_C) c:\@desenv\winbinder\csource\core\wb\wb_control_hyperlink.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_control_hyperlink.c

# Build wb_control_html.c
WB_CONTROL_HTML_C=\

wb_control_html.obj: $(WB_CONTROL_HTML_C) c:\@desenv\winbinder\csource\core\wb\wb_control_html.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_control_html.c

# Build wb_control_calendar.c
WB_CONTROL_CALENDAR_C=\

wb_control_calendar.obj: $(WB_CONTROL_CALENDAR_C) c:\@desenv\winbinder\csource\core\wb\wb_control_calendar.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_control_calendar.c

# Build wb_control.c
WB_CONTROL_C=\

wb_control.obj: $(WB_CONTROL_C) c:\@desenv\winbinder\csource\core\wb\wb_control.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_control.c

# Build wb_bitmap.c
WB_BITMAP_C=\

wb_bitmap.obj: $(WB_BITMAP_C) c:\@desenv\winbinder\csource\core\wb\wb_bitmap.c
	$(CC) -c $(CFLAGS) c:\@desenv\winbinder\csource\core\wb\wb_bitmap.c

link:
	$(LINKER)  -s -subsystem windows -o c:\@desenv\winbinder\binaries\c\hello.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) c:\@desenv\winbinder\binaries\c\hello.exe
