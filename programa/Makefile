SOURCES = main.cpp substancia.cpp ambiente.cpp PontoDeEbulicao.cpp

OBJECTS = $(SOURCES:.cpp=.o)

EXEC = programa

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXEC)

