#*******************************************************************************
#
# WINBINDER - A native Windows binding for PHP
#
# Copyright © 2004-2006 Hypervisual - see LICENSE.TXT for details
# Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)
#
# Makefile for WinBinder
#
#*******************************************************************************

#------------------------------------------------------------------- DEFINITIONS

OUTDIR = .
cc = cl
link = link

#----------------------------------------- SOURCE FILES, OBJECT FILES, LIBRARIES

SOURCES = \
	$(SRCDIR)\phpwb_window.c				\
	$(SRCDIR)\phpwb_control.c				\
	$(SRCDIR)\phpwb_control_listview.c		\
	$(SRCDIR)\phpwb_control_menu.c			\
	$(SRCDIR)\phpwb_control_toolbar.c		\
	$(SRCDIR)\phpwb_control_treeview.c		\
	$(SRCDIR)\phpwb_draw.c					\
	$(SRCDIR)\phpwb_export.c				\
	$(SRCDIR)\phpwb_font.c					\
	$(SRCDIR)\phpwb_generic.c				\
	$(SRCDIR)\phpwb_lowlevel.c				\
	$(SRCDIR)\phpwb_sysdlg.c				\
	$(SRCDIR)\phpwb_wb_lib.c				\
	$(SRCDIR)\phpwb_bitmap.c				\
	$(SRCDIR)\phpwb_winsys.c				\
	$(SRCDIR)\wb\wb_control_treeview.c		\
	$(SRCDIR)\wb\wb_control.c				\
	$(SRCDIR)\wb\wb_control_calendar.c		\
	$(SRCDIR)\wb\wb_control_html.c			\
	$(SRCDIR)\wb\wb_control_hyperlink.c		\
	$(SRCDIR)\wb\wb_control_listview.c		\
	$(SRCDIR)\wb\wb_control_menu.c			\
	$(SRCDIR)\wb\wb_control_tab.c			\
	$(SRCDIR)\wb\wb_control_toolbar.c		\
	$(SRCDIR)\wb\wb_bitmap.c				\
	$(SRCDIR)\wb\wb_draw.c					\
	$(SRCDIR)\wb\wb_font.c					\
	$(SRCDIR)\wb\wb_generic.c				\
	$(SRCDIR)\wb\wb_lowlevel.c				\
	$(SRCDIR)\wb\wb_sysdlg.c				\
	$(SRCDIR)\wb\wb_window.c				\
	$(SRCDIR)\wb\wb_winsys.c

OBJS = \
	$(OUTDIR)\phpwb_window.obj				\
	$(OUTDIR)\phpwb_control.obj				\
	$(OUTDIR)\phpwb_control_listview.obj	\
	$(OUTDIR)\phpwb_control_menu.obj		\
	$(OUTDIR)\phpwb_control_toolbar.obj		\
	$(OUTDIR)\phpwb_control_treeview.obj	\
	$(OUTDIR)\phpwb_draw.obj				\
	$(OUTDIR)\phpwb_export.obj				\
	$(OUTDIR)\phpwb_font.obj				\
	$(OUTDIR)\phpwb_generic.obj				\
	$(OUTDIR)\phpwb_lowlevel.obj			\
	$(OUTDIR)\phpwb_sysdlg.obj				\
	$(OUTDIR)\phpwb_wb_lib.obj				\
	$(OUTDIR)\phpwb_bitmap.obj				\
	$(OUTDIR)\phpwb_winsys.obj				\
	$(OUTDIR)\wb_control_treeview.obj		\
	$(OUTDIR)\wb_control.obj				\
	$(OUTDIR)\wb_control_calendar.obj		\
	$(OUTDIR)\wb_control_html.obj			\
	$(OUTDIR)\wb_control_hyperlink.obj		\
	$(OUTDIR)\wb_control_listview.obj		\
	$(OUTDIR)\wb_control_menu.obj			\
	$(OUTDIR)\wb_control_tab.obj			\
	$(OUTDIR)\wb_control_toolbar.obj		\
	$(OUTDIR)\wb_bitmap.obj					\
	$(OUTDIR)\wb_draw.obj					\
	$(OUTDIR)\wb_font.obj					\
	$(OUTDIR)\wb_generic.obj				\
	$(OUTDIR)\wb_lowlevel.obj				\
	$(OUTDIR)\wb_sysdlg.obj					\
	$(OUTDIR)\wb_window.obj					\
	$(OUTDIR)\wb_winsys.obj

LIBS = \
    user32.lib		\
    gdi32.lib		\
	comdlg32.lib	\
	comctl32.lib	\
	shell32.lib		\
	ole32.lib 		\
	oleaut32.lib 	\
	winmm.lib		\
    advapi32.lib	\
	$(PHPLIB)

#-------------------------------------------------------------------------- CODE

all: $(DLLDIR)\php_winbinder.dll

$(OBJS): $(SOURCES)
	$(cc) /nologo /MT /W3 /GX /O2 /YX /FD /c /QIfist \
	/D "NDEBUG" /D ZEND_DEBUG=0 /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D HAVE_WIN32STD=1 \
	/I "$(LIBDIR)" /I "$(LIBDIR)\main" /I "$(LIBDIR)\Zend" /I "$(LIBDIR)\TSRM" \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCES)


$(DLLDIR)\php_winbinder.dll: $(OBJS)
	$(link) /nologo /dll /machine:I386 -out:$(DLLDIR)\php_winbinder.dll \
	$(OBJS) $(LIBS)

clean:
	del /s /q $(OUTDIR)\*.obj $(OUTDIR)\*.pdb $(DLLDIR)\php_winbinder.dll $(OUTDIR)\php_winbinder.exp $(OUTDIR)\php_winbinder.lib

#------------------------------------------------------------------- END OF FILE
