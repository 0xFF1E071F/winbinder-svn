# Wedit Makefile for project winbinder_php50
SRCDIR=c:\@desenv\winbinder\csource\core
CFLAGS=-Ic:\util\lcc\include -IC:\@desenv\WinBinder\csource\core -IC:\@desenv\winbinder\csource\core\wb -IC:\@desenv\WinBinder\csource\php50\main -IC:\@desenv\WinBinder\csource\php50\zend -IC:\@desenv\WinBinder\csource\php50\tsrm -IC:\@desenv\WinBinder\csource\php50\regex -IC:\@desenv\WinBinder\csource\php50\win32 -IC:\@desenv\WinBinder\csource\php50\ext\standard  -A  -ansic
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
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
	wb_bitmap.obj \
	phpwb_winsys.obj \
	phpwb_window.obj \
	phpwb_wb_lib.obj \
	phpwb_sysdlg.obj \
	phpwb_lowlevel.obj \
	phpwb_generic.obj \
	phpwb_font.obj \
	phpwb_export.obj \
	phpwb_draw.obj \
	phpwb_control_treeview.obj \
	phpwb_control_toolbar.obj \
	phpwb_control_menu.obj \
	phpwb_control_listview.obj \
	phpwb_control.obj \
	phpwb_bitmap.obj \

LIBS=iehelper.lib php50ts.lib psapi.lib shell32.lib ole32.lib oleaut32.lib uuid.lib winmm.lib
EXE=c:\@desenv\winbinder\binaries\php50\ext\php_winbinder.dll

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -s -dll -nounderscores -o c:\@desenv\winbinder\binaries\php50\ext\php_winbinder.dll $(OBJS) $(LIBS)

# Build wb_winsys.c
WB_WINSYS_C=\

wb_winsys.obj: $(WB_WINSYS_C) $(SRCDIR)\wb\wb_winsys.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_winsys.c

# Build wb_window.c
WB_WINDOW_C=\

wb_window.obj: $(WB_WINDOW_C) $(SRCDIR)\wb\wb_window.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_window.c

# Build wb_sysdlg.c
WB_SYSDLG_C=\

wb_sysdlg.obj: $(WB_SYSDLG_C) $(SRCDIR)\wb\wb_sysdlg.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_sysdlg.c

# Build wb_lowlevel.c
WB_LOWLEVEL_C=\

wb_lowlevel.obj: $(WB_LOWLEVEL_C) $(SRCDIR)\wb\wb_lowlevel.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_lowlevel.c

# Build wb_generic.c
WB_GENERIC_C=\

wb_generic.obj: $(WB_GENERIC_C) $(SRCDIR)\wb\wb_generic.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_generic.c

# Build wb_font.c
WB_FONT_C=\

wb_font.obj: $(WB_FONT_C) $(SRCDIR)\wb\wb_font.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_font.c

# Build wb_draw.c
WB_DRAW_C=\

wb_draw.obj: $(WB_DRAW_C) $(SRCDIR)\wb\wb_draw.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_draw.c

# Build wb_control_treeview.c
WB_CONTROL_TREEVIEW_C=\

wb_control_treeview.obj: $(WB_CONTROL_TREEVIEW_C) $(SRCDIR)\wb\wb_control_treeview.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_control_treeview.c

# Build wb_control_toolbar.c
WB_CONTROL_TOOLBAR_C=\

wb_control_toolbar.obj: $(WB_CONTROL_TOOLBAR_C) $(SRCDIR)\wb\wb_control_toolbar.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_control_toolbar.c

# Build wb_control_tab.c
WB_CONTROL_TAB_C=\

wb_control_tab.obj: $(WB_CONTROL_TAB_C) $(SRCDIR)\wb\wb_control_tab.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_control_tab.c

# Build wb_control_menu.c
WB_CONTROL_MENU_C=\

wb_control_menu.obj: $(WB_CONTROL_MENU_C) $(SRCDIR)\wb\wb_control_menu.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_control_menu.c

# Build wb_control_listview.c
WB_CONTROL_LISTVIEW_C=\

wb_control_listview.obj: $(WB_CONTROL_LISTVIEW_C) $(SRCDIR)\wb\wb_control_listview.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_control_listview.c

# Build wb_control_hyperlink.c
WB_CONTROL_HYPERLINK_C=\

wb_control_hyperlink.obj: $(WB_CONTROL_HYPERLINK_C) $(SRCDIR)\wb\wb_control_hyperlink.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_control_hyperlink.c

# Build wb_control_html.c
WB_CONTROL_HTML_C=\

wb_control_html.obj: $(WB_CONTROL_HTML_C) $(SRCDIR)\wb\wb_control_html.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_control_html.c

# Build wb_control_calendar.c
WB_CONTROL_CALENDAR_C=\

wb_control_calendar.obj: $(WB_CONTROL_CALENDAR_C) $(SRCDIR)\wb\wb_control_calendar.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_control_calendar.c

# Build wb_control.c
WB_CONTROL_C=\

wb_control.obj: $(WB_CONTROL_C) $(SRCDIR)\wb\wb_control.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_control.c

# Build wb_bitmap.c
WB_BITMAP_C=\

wb_bitmap.obj: $(WB_BITMAP_C) $(SRCDIR)\wb\wb_bitmap.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\wb\wb_bitmap.c

# Build phpwb_winsys.c
PHPWB_WINSYS_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_ini.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ini.h\

phpwb_winsys.obj: $(PHPWB_WINSYS_C) $(SRCDIR)\phpwb_winsys.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_winsys.c

# Build phpwb_window.c
PHPWB_WINDOW_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\

phpwb_window.obj: $(PHPWB_WINDOW_C) $(SRCDIR)\phpwb_window.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_window.c

# Build phpwb_wb_lib.c
PHPWB_WB_LIB_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\

phpwb_wb_lib.obj: $(PHPWB_WB_LIB_C) $(SRCDIR)\phpwb_wb_lib.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_wb_lib.c

# Build phpwb_sysdlg.c
PHPWB_SYSDLG_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\

phpwb_sysdlg.obj: $(PHPWB_SYSDLG_C) $(SRCDIR)\phpwb_sysdlg.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_sysdlg.c

# Build phpwb_lowlevel.c
PHPWB_LOWLEVEL_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\

phpwb_lowlevel.obj: $(PHPWB_LOWLEVEL_C) $(SRCDIR)\phpwb_lowlevel.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_lowlevel.c

# Build phpwb_generic.c
PHPWB_GENERIC_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\

phpwb_generic.obj: $(PHPWB_GENERIC_C) $(SRCDIR)\phpwb_generic.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_generic.c

# Build phpwb_font.c
PHPWB_FONT_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\

phpwb_font.obj: $(PHPWB_FONT_C) $(SRCDIR)\phpwb_font.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_font.c

# Build phpwb_export.c
PHPWB_EXPORT_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\ext\standard\info.h\

phpwb_export.obj: $(PHPWB_EXPORT_C) $(SRCDIR)\phpwb_export.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_export.c

# Build phpwb_draw.c
PHPWB_DRAW_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\

phpwb_draw.obj: $(PHPWB_DRAW_C) $(SRCDIR)\phpwb_draw.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_draw.c

# Build phpwb_control_treeview.c
PHPWB_CONTROL_TREEVIEW_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\

phpwb_control_treeview.obj: $(PHPWB_CONTROL_TREEVIEW_C) $(SRCDIR)\phpwb_control_treeview.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_control_treeview.c

# Build phpwb_control_toolbar.c
PHPWB_CONTROL_TOOLBAR_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\

phpwb_control_toolbar.obj: $(PHPWB_CONTROL_TOOLBAR_C) $(SRCDIR)\phpwb_control_toolbar.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_control_toolbar.c

# Build phpwb_control_menu.c
PHPWB_CONTROL_MENU_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\

phpwb_control_menu.obj: $(PHPWB_CONTROL_MENU_C) $(SRCDIR)\phpwb_control_menu.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_control_menu.c

# Build phpwb_control_listview.c
PHPWB_CONTROL_LISTVIEW_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\

phpwb_control_listview.obj: $(PHPWB_CONTROL_LISTVIEW_C) $(SRCDIR)\phpwb_control_listview.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_control_listview.c

# Build phpwb_control.c
PHPWB_CONTROL_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\

phpwb_control.obj: $(PHPWB_CONTROL_C) $(SRCDIR)\phpwb_control.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_control.c

# Build phpwb_bitmap.c
PHPWB_BITMAP_C=\
	$(SRCDIR)\phpwb.h\
	$(SRCDIR)\wb\wb.h\
	$(SRCDIR)\wb\wb_version.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\
	C:\@desenv\WinBinder\csource\php50\main\php_version.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_errors.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\main\..\TSRM\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\main\crtdbg.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_types.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ts_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_object_handlers.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_iterators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stream.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_qsort.h\
	C:\@desenv\WinBinder\csource\php50\main\php_compat.h\
	C:\@desenv\WinBinder\csource\php50\main\config.w32.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_list.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals_macros.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_ptr_stack.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_objects_API.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_modules.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_llist.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_mm.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_fast_cache.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_execute.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_compile.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_variables.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_operators.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_win32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\main\win95nt.h\
	C:\@desenv\WinBinder\csource\php50\main\php_regex.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_hash.h\
	C:\@desenv\WinBinder\csource\php50\main\php3_compat.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_alloc.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_stack.h\
	C:\@desenv\WinBinder\csource\php50\main\safe_mode.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\pwd.h\
	C:\@desenv\WinBinder\csource\php50\main\..\win32\param.h\
	C:\@desenv\WinBinder\csource\php50\main\spprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\snprintf.h\
	C:\@desenv\WinBinder\csource\php50\main\php_output.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_context.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_filter_api.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_transport.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_plain_wrapper.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_userspace.h\
	C:\@desenv\WinBinder\csource\php50\main\streams\php_stream_mmap.h\
	C:\@desenv\WinBinder\csource\php50\main\php_memory_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\php_streams.h\
	C:\@desenv\WinBinder\csource\php50\main\fopen_wrappers.h\
	C:\@desenv\WinBinder\csource\php50\main\php_globals.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_virtual_cwd.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\TSRM.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config_common.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\tsrm_config.w32.h\
	C:\@desenv\WinBinder\csource\php50\tsrm\readdir.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_constants.h\
	C:\@desenv\WinBinder\csource\php50\zend\zend_globals.h\
	C:\@desenv\WinBinder\csource\php50\main\php_reentrancy.h\
	C:\@desenv\WinBinder\csource\php50\main\php.h\

phpwb_bitmap.obj: $(PHPWB_BITMAP_C) $(SRCDIR)\phpwb_bitmap.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\phpwb_bitmap.c

link:
	$(LINKER)  -s -dll -nounderscores -o c:\@desenv\winbinder\binaries\php50\ext\php_winbinder.dll $(OBJS) $(LIBS)

clean:
	del $(OBJS) c:\@desenv\winbinder\binaries\php50\ext\php_winbinder.dll
