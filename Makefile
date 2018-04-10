BINDIR=./deb/usr/bin/

COMPILE=SAY

SRCDIR=./src/srcs/

CC=gcc

FLAGS=-Wall -Werror -Wextra

INCS=-I./src/incs/

GTKLIBS=`pkg-config --libs --cflags gtk+-2.0`

_SRCS_SAY=main say read merge language join config config_check string

_SRCS_SAYCFG=saycfg language config config_check read string merge

_SRCS_SAYGUI=saygui merge string language config

_SRCS_SAYDATE=saydate

SRCS=${addprefix $(SRCDIR), ${addsuffix .c, $(_SRCS_$(COMPILE))}}

all:$(COMPILE)
	

SAY:
	$(CC) $(INCS) $(FLAGS) $(SRCS) -o $(BINDIR)say

SAYCFG:
	$(CC) $(INCS) $(FLAGS) $(SRCS) -o $(BINDIR)saycfg

SAYDATE:
	$(CC) $(INCS) $(FLAGS) $(SRCS) -o $(BINDIR)saydate

SAYGUI:
	$(CC) $(INCS) -w $(FLAGS) $(SRCS) $(GTKLIBS) -o $(BINDIR)saygui

build: clean
	sudo dpkg-deb --build ./deb
	mv -f ./deb.deb ./say.deb

install: build
	sudo dpkg -i ./say.deb

remove:
	sudo apt-get remove say

reinstall: remove install
	

clean:
	/bin/rm -f ./say.deb
