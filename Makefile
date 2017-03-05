TARGET=watchwatch

SOURCES = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, ${SOURCES})
DEPS = $(patsubst %.cpp, %.d, ${SOURCES})

CXX = g++
CXXFLAGS = -Wall -Wextra -lSDL2
LDFLAGS = -lSDL2

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp %.d
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.d: %.cpp
	$(CXX) $< -M -o $@

clean:
	-rm -f $(TARGET) $(DEPS) $(OBJS)

-include $(SOURCES:.cpp=.d)
