TARGET=watchwatch

all: $(TARGET)
SOURCES = $(wildcard *.cpp)

CXX = clang++
CXXFLAGS = -Wall -Wextra

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)
