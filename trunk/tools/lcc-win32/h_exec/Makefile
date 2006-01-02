# Wedit Makefile for project h_exec
SRCDIR=c:\@desenv\winbinder\csource\h_exec
CFLAGS=-Ic:\util\lcc\include -IC:\@desenv\winbinder\csource\h_exec  -A  -ansic
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	h_exec.obj \
	h_exec.res \

LIBS=shell32.lib
EXE=c:\@desenv\winbinder\binaries\h_exec\h_exec.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -s -subsystem windows -o c:\@desenv\winbinder\binaries\h_exec\h_exec.exe $(OBJS) $(LIBS)

# Build h_exec.c
H_EXEC_C=\

h_exec.obj: $(H_EXEC_C) $(SRCDIR)\h_exec.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\h_exec.c

# Build h_exec.res
H_EXEC_RC=\

h_exec.res:	$(H_EXEC_RC) $(SRCDIR)\h_exec.rc
	$(LCCROOT)\bin\lrc.exe -I$(SRCDIR) -Ic:\util\lcc\include -IC:\@desenv\winbinder\csource\h_exec  $(SRCDIR)\h_exec.rc

link:
	$(LINKER)  -s -subsystem windows -o c:\@desenv\winbinder\binaries\h_exec\h_exec.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) c:\@desenv\winbinder\binaries\h_exec\h_exec.exe
