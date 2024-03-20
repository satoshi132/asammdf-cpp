CXX = g++
CXXFLAGS = -std=c++17 -O2
TARGET = ./build/mdfreader
SRCDIR = ./src/Blocks
OBJDIR = ./build
SRCS = $(wildcard $(SRCDIR)/*.cpp) ./mdfreader.cpp
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(TARGET)
