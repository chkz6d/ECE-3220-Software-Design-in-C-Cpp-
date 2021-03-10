PP_FILES := ece3220-lab6-chkz6d.cpp \

EXECUTABLE := ece3220-lab6-chkz6d \

CXXFLAGS := -std=c++11 -ggdb -O0

.PHONY : all

all :
	make $(EXECUTABLE)

.PHONY : clean

clean :
	rm -f $(EXECUTABLE) sensorA.txt sensorB.txt loader.txt
	
$(EXECUTABLE) : $(PP_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@
