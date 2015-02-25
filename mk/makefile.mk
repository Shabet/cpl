#
# MS compiler: options : tested in Visual Studio 2013
#
# Makefile infra structure
#

CC = cl.exe
LINK = link.exe
CFLAGS = /EHsc

all: $(PROG)

.c.obj:
	$(CC) $(CFLAGS) /c $< 

$(PROG): $(OBJECTS)
	$(LINK) -out:$(PROG) $(OBJECTS)

clean:
	del *.obj core *.stackdump $(PROG)
