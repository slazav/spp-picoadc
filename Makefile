srcdir = spp-picoadc

all:
	make -C ${srcdir}


DESTDIR    ?=
prefix     ?= $(DESTDIR)/usr
bindir     ?= $(prefix)/bin

install: all
	install -D -m755 ${srcdir}/pico_adc -t ${bindir}
