
# list the name of each file (without the .cpp file at the end)
EXE = IntInf_Test example PList IntegerSetArray_test IntArray_test hw6a_test integerSetHT_iterator_test

all: $(EXE)

run: all $(addsuffix -run,$(EXE))

clean:
	rm -f $(EXE) *~ logfile.txt $(ECE)

%: %.cpp
	$(CXX) -o $@ $< -Wall -std=c++11 -I ../include -L ../lib -lece309

%-run:
	@./$*

