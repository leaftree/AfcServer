CC = gcc -g3

CCCOLOR   = "\033[33m"
LINKCOLOR = "\033[34;1m"
SRCCOLOR  = "\033[31m"
RMCOLOR   = "\033[1;31m"
BINCOLOR  = "\033[37;1m"
MAKECOLOR = "\033[32;1m"
ENDCOLOR  = "\033[0m"

QUIET_CC  = @printf '%b %b\n' $(CCCOLOR)CC$(ENDCOLOR) $(SRCCOLOR)$@$(ENDCOLOR) 1>&2;
QUIET_RM  = @printf '%b %b\n' $(LINKCOLOR)REMOVE$(ENDCOLOR) $(BINCOLOR)$@$(ENDCOLOR) 1>&2;
QUIET_EXE = @printf '%b %b\n' $(LINKCOLOR)EXEC$(ENDCOLOR) $(BINCOLOR)$@$(ENDCOLOR) 1>&2;

QUIET_PROC=$(QUIET_CC)$(CC)
QUIET_EXEC=$(QUIET_EXE)exec
QUIET_REMOVE=$(QUIET_RM)rm -f

CFLAGS += -DDBUG_ON

src  = DebugUtils.c \
			 xMalloc.c    \
			 String.c     \
			 Main.c       \

obj  = Main

all:$(obj)

$(obj):$(src)
	$(QUIET_PROC) $(CFLAGS) $(src) -o $(obj)

run:$(obj)
	$(QUIET_EXEC) $(PWD)/$(obj)

tags:$(src)
	ctags *.c *.h

.PHONY:clean
clean:
	$(QUIET_REMOVE) -f $(obj)
