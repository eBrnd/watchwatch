TARGET=watchwatch

SOURCES = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, ${SOURCES})
DEPS = $(patsubst %.cpp, %.d, ${SOURCES})

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -lSDL2 -g
LDFLAGS = -lSDL2 -g

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
