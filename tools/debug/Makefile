include ../../Makefile.header

LDFLAGS += -r
CFLAGS	+= -I../../include
CPP	+= -I../../include

.c.o:
	@$(CC) $(CFLAGS) \
	-c -o $*.o $<
.s.o:
	@$(AS) -o $*.o $<
.c.s:
	@$(CC) $(CFLAGS) \
	-S -o $*.s $<


all: debug.o

debug.o:
	@$(LD) $(LDFLAGS) -o debug.o 

clean:
	@rm -f core *.o *.a tmp_make
	@for i in *.c;do rm -f `basename $$i .c`.s;done

dep:
	@sed '/\#\#\# Dependencies/q' < Makefile > tmp_make
	@(for i in *.c;do $(CPP) -M $$i;done) >> tmp_make
	@cp tmp_make Makefile

