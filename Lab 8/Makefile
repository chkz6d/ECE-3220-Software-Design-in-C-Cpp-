EXECUTABLE := Source\

CODES := Source.cpp \
		
CXXFLAGS := -std=c++11 -pthread -ggdb -O0
		
.PHONY : clean

.PHONY : all

all : 
	make $(EXECUTABLE) 
	
clean :
	rm -f $(EXECUTABLE) big.txt

Source : Source.cpp
	$(CXX) $(CXXFLAGS) $< -o $@


