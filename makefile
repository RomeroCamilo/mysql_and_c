CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11
LDFLAGS := $(shell mysql_config --libs)
CPPFLAGS := $(shell mysql_config --cflags)

SRC := main.cpp
TARGET := output

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)
