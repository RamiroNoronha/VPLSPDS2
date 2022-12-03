IDIR = src/entidades
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=build
LDIR =../lib

_DEPS = Funcionario.hpp Pessoa.hpp Professor.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Funcionario.o Pessoa.o Professor.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

vpl_execution: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 